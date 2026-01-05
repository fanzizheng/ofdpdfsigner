//
//  Created by zizheng fan on 2024/08/05.
//
#include "basic/FZZConst.h"
#include "converter/toofd/FZZPDF2OFD.h"
#include "converter/utils/FZZCommonUtil.h"
#include "FZZOFDDevice.h"
#include "fzfont/FZZTempFontCache.h"
#include "font/FZZGenFont.h"

//#include "pdf-annot-imp.h"
//pdf_annot Declared on pdf-annot-imp.h
struct pdf_annot
{
    int refs;

    pdf_page *page;
    pdf_obj *obj;

    int is_hot;
    int is_active;

    int needs_new_ap; /* If set, then a resynthesis of this annotation has been requested. */
    int has_new_ap; /* If set, then the appearance stream has changed since last queried. */
    int ignore_trigger_events;

    pdf_annot *next;
};

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPDF2OFD**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2OFD::FZZPDF2OFD() : m_CTX(NULL),m_Doc(NULL),m_Stm(NULL),m_PDF(NULL),m_isNoStamp(false),m_OFDDoc(NULL),m_isGenFont(false),m_PassWord("")
{
    //DLOG("FZZPDF2OFD()");
    FZZConst::addClassCount("FZZPDF2OFD");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2OFD::FZZPDF2OFD(FZZPDF * pdf) : FZZPDF2OFD()
{
    m_PDF = pdf;
    if ( m_PDF == NULL ) {
        return;
    }
    
    FZZBytes * tempSrcData = m_PDF->getSourceData();
    if ( tempSrcData == NULL ) {
        return;
    }
    
    m_CTX = fz_new_context(NULL, NULL, FZ_STORE_DEFAULT);
    if ( m_CTX == NULL ) return;


    fz_try(m_CTX)
    {
        fz_register_document_handlers(m_CTX);
        fz_set_aa_level(m_CTX, 8);

        m_Stm = fz_open_memory(m_CTX, tempSrcData->getData(), tempSrcData->getLen());
        if ( m_Stm == NULL ) return;
        m_Doc = pdf_open_document_with_stream(m_CTX, m_Stm);
        if ( m_Doc == NULL ) return;
    }
    fz_always(m_CTX)
    {

    }
    fz_catch(m_CTX)
    {

    }
    m_OFDDoc = new FZZOFD();
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2OFD::FZZPDF2OFD(const FZZPDF2OFD& obj): FZZPDF2OFD()
{
    //DLOG("FZZPDF2OFD(const FZZPDF2OFD& obj)");
    if ( this == &obj ) {
        return;
    }
//    this->m_PDF = obj.m_PDF;
//    this->m_CTX = obj.m_CTX;
//    this->m_Doc = obj.m_Doc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2OFD::~FZZPDF2OFD()
{
    //DLOG("~FZZPDF2OFD()");
    FZZConst::delClassCount("FZZPDF2OFD");
    
    map<string,FZZGenFont*>::iterator it;
    for (it = m_genFont.begin(); it != m_genFont.end(); it++) {
        if ( it->second != NULL ) {
            delete (it->second);
        }
    }
    m_genFont.clear();
    
    map<string,FZZBytes*>::iterator pdffontit;
    for (pdffontit = m_PDFFontData.begin(); pdffontit != m_PDFFontData.end(); pdffontit++) {
        if ( pdffontit->second != NULL ) {
            delete (pdffontit->second);
        }
    }
    m_PDFFontData.clear();
    
    if ( m_Doc != NULL ) {
        pdf_drop_document(m_CTX,m_Doc);
        m_Doc = NULL;
    }

    if ( m_Stm != NULL ) {
        fz_drop_stream(m_CTX, m_Stm);
        m_Stm = NULL;
    }

    if ( m_CTX != NULL ) {
        fz_flush_warnings(m_CTX);
        fz_drop_context(m_CTX);
        m_CTX = NULL;
    }
    
    if ( m_OFDDoc != NULL ) {
        delete m_OFDDoc;
        m_OFDDoc = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDF2OFD::isNeedPassWord()
{
    bool ret = false;
    if ( m_CTX == NULL && m_Doc == NULL ) {
        return ret;
    }
    if (pdf_needs_password(m_CTX, m_Doc)) {
        ret = true;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDF2OFD::VerifyPassWord(string pwd)
{
    bool ret = false;
    m_PassWord = pwd;
    
    if ( m_CTX == NULL && m_Doc == NULL ) {
        return ret;
    }
    
    if (pdf_needs_password(m_CTX, m_Doc)) {
        if (!pdf_authenticate_password(m_CTX, m_Doc, m_PassWord.c_str())) {
            ret = false;
        } else {
            ret = true;
        }
    } else {
        ret = true;
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDF2OFD::getPDFPageCount()
{
    int page_count = 0;
    if ( m_Doc != NULL ) {
        page_count = pdf_count_pages(m_CTX,m_Doc);
    }
    return page_count;
}
//-----------------------------------------------------------------------------------------------------------------
//bool FZZPDF2OFD::makePage(int pageIndex)
//{
//    try
//    {
//        pdf_page * pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
//        if ( pdfpage != NULL ) {
//            fz_drop_page(m_CTX, (fz_page *) pdfpage);
//        }
//    }
//    catch(...)
//    {
//        fz_rethrow(m_CTX);
//    }
//    return true;
//}

bool FZZPDF2OFD::makePage(int pageIndex)
{
    bool isRet = false;
    pdf_page * pdfpage = NULL;
    fz_matrix page_ctm;
    fz_rect mediabox;
    fz_rect ofdPageMediabox;
    fz_device * dev = NULL;
    fzofd_device *pdev = NULL;
    

    FZZOFDPageXML * page = NULL;
    FZZOFDPageArea * ct_pageArea = NULL;
    FZZOFDLayer*  layer = NULL;
    
    
    //DLOG("begin page ..................%d",pageIndex);
    
    if ( m_OFDDoc == NULL ) {
        goto err;
    }
//    fz_try(m_CTX)
//    {
        pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
        if ( pdfpage == NULL ) {
            goto err;
        }
//    }
//    fz_catch(m_CTX)
//    {
//        fz_rethrow(m_CTX);
//    }
    pdf_page_transform(m_CTX, pdfpage, &mediabox, &page_ctm);
    
    mediabox = fz_transform_rect(mediabox, page_ctm);
    
   
    ofdPageMediabox.x0 = lround(FZZCommonUtil::pixelToMillimeters(mediabox.x0, 72));
    ofdPageMediabox.y0 = lround(FZZCommonUtil::pixelToMillimeters(mediabox.y0, 72));
    ofdPageMediabox.x1 = lround(FZZCommonUtil::pixelToMillimeters(mediabox.x1, 72));
    ofdPageMediabox.y1 = lround(FZZCommonUtil::pixelToMillimeters(mediabox.y1, 72));
    
    
    
    
    if ( !m_isGenFont ) {
        
        
        page = m_OFDDoc->addPage();
        if ( page == NULL ) {
            goto err;
        }
        ct_pageArea = page->setPageArea();
        if ( ct_pageArea == NULL ) {
            goto err;
        }
        
        FZZOFDPhysicalBox * physicalBox = ct_pageArea->setPhysicalBox();
        if ( physicalBox == NULL ) {
            goto err;
        }
        physicalBox->setValue(0, 0, ofdPageMediabox.x1, ofdPageMediabox.y1);
        FZZOFDApplicationBox * applicationBox = ct_pageArea->setApplicationBox();
        if ( applicationBox == NULL ) {
            goto err;
        }
        applicationBox->setValue(0, 0, ofdPageMediabox.x1, ofdPageMediabox.y1);
        FZZOFDContent * ofdContent = page->setContent();
        if ( ofdContent == NULL ) {
            goto err;
        }
        layer = ofdContent->addLayer();
        if ( layer == NULL ) {
            goto err;
        }
         
       
    }
    
  //fzz edit begin 2024.09.18
//    if ( page_ctm.b != 0 || page_ctm.c != 0 ) {
//        dev = new_fzofd_device(m_CTX,m_OFDDoc,layer,mediabox.y1, mediabox.x1, MUPDF_fz_identity,m_isNoStamp,&m_genFont,&m_ucs_gid_map,m_isGenFont);
//    } else {
//        dev = new_fzofd_device(m_CTX,m_OFDDoc,layer,mediabox.x1, mediabox.y1, MUPDF_fz_identity,m_isNoStamp,&m_genFont,&m_ucs_gid_map,m_isGenFont);
//
//    }
    dev = new_fzofd_device(m_CTX,m_OFDDoc,layer,mediabox.x1, mediabox.y1, MUPDF_fz_identity,m_isNoStamp,&m_genFont,&m_ucs_gid_map,m_isGenFont);
    //fzz edit end 2024.09.18
    if ( dev == NULL ) {
        goto err;
    }
    pdev = (fzofd_device*)dev;
    if ( !m_isGenFont ) {
        if ( page == NULL ) {
            pdev->currPageIndex = 0;
        } else {
            pdev->currPageIndex = page->getPageIndex();
        }
    } else {
        pdev->currPageIndex = 0;
    }
    
    pdev->pagetype = 0;
    fz_try(m_CTX) {
    //看 pdf_run_page_with_usage 这个函数实现，新建这个类
    //fz_run_page_contents 本身有内存泄露，目前可以确定定位到这个函数，待后续有大量时间时解决
    fz_run_page_contents(m_CTX, (fz_page *)pdfpage, dev, MUPDF_fz_identity, NULL);
    
    pdev->pagetype = 1;
    pdf_page_annots(m_CTX, pdfpage, dev, MUPDF_fz_identity, "View",NULL);
    pdev->pagetype = 1;
    pdf_page_widgets(m_CTX, pdfpage, dev, MUPDF_fz_identity, "View", NULL);
    
    } fz_catch(m_CTX) {
        DLOG("gen svg error : %s",m_CTX->error.message);
    }
//    }
//    fz_always(m_CTX)
//    {
//        if ( dev != NULL ) {
//            fz_close_device(m_CTX, dev);
//            fz_drop_device(m_CTX, dev);
//            dev = NULL;
//        }
//
//        if ( pdfpage != NULL ) {
//            fz_drop_page(m_CTX, (fz_page *) pdfpage);
//            pdfpage = NULL;
//        }
//    }
//    fz_catch(m_CTX)
//    {
//        fz_rethrow(m_CTX);
//    }
err:
    if ( dev != NULL ) {
        fz_close_device(m_CTX, dev);
        fz_drop_device(m_CTX, dev);
        dev = NULL;
    }
    
    if ( pdfpage != NULL ) {
        //fz_drop_page(m_CTX, (fz_page *) pdfpage);
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
    
    //DLOG("end page ..................%d",pageIndex);
    return isRet;
}
 
//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::generateOFDFont()
{
    map<string,FZZGenFont*>::iterator it;
    for (it = m_genFont.begin(); it != m_genFont.end(); it++) {
        if ( it->second != NULL ) {
            FZZGenFont* genFont = it->second;
            FZZBytes * newFontData = new FZZBytes();
            if ( newFontData != NULL ) {
                if ( genFont->genNewFont(*newFontData) ) {
                    auto isExitPari = m_PDFFontData.insert(pair<string,FZZBytes*>(it->first ,newFontData));
                    if ( !isExitPari.second ) {
                        delete newFontData;
                        continue;
                    }
                    
                    //sk_sp<SkData> data = SkData::MakeWithoutCopy(newFontData->getData(),newFontData->getLen());
                    //SkFont font(SkTypeface::MakeFromData(data),1);
                     
                    FZZTempFontCache fontCache;
                    if ( !fontCache.load(*newFontData) ) {
                        continue;
                    }
                    
                    const unordered_map<FzUnichar,FzGlyphID> * tempmap = fontCache.getWords();
                    if ( tempmap != NULL ) {
                        m_ucs_gid_map[it->first] = *tempmap;
//                        map<SkUnichar,SkGlyphID>::const_iterator tempmap_it;
//                        for (tempmap_it = tempmap->begin(); tempmap_it != tempmap->end(); tempmap_it++) {
//                            m_ucs_gid_map[it->first].insert(pair<int,int>(tempmap_it->first,tempmap_it->second));
//                        }
                    }
                    
                    
//                    string aa = "/Users/fzz/work/cpp/ofd/tmp/imageconverter/";
//                    static int bb = 0;
//                    bb++;
//                    aa = aa + FZZConst::fmt(bb);
//                    aa += ".ttf";
//                    FZZConst::writefile(aa, newFontData->getData(), newFontData->getLen());
                } else {
                    delete newFontData;
                    newFontData = NULL;
                } //if ( genFont->genNewFont(*newFontData) )
        
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZPDF2OFD::generateOFD()
{
    FZZBytes ret ;
    
    if ( m_OFDDoc != NULL ) {
        
        map<string,FZZBytes*>::iterator it;
        for (it = m_PDFFontData.begin(); it != m_PDFFontData.end(); it++) {
            if ( it->second != NULL ) {
                m_OFDDoc->updateFontFile(it->first, *(it->second));
            }
        }
        
        m_OFDDoc->UpdateMaxUnitID();
        m_OFDDoc->FlushAll();
        m_OFDDoc->Close(ret);
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::pdf_page_widgets(fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    pdf_document *doc = page->doc;
    int nocache;

    nocache = !!(dev->hints & FZ_NO_CACHE);
    if (nocache)
        pdf_mark_xref(ctx, doc);

    fz_try(ctx)
    {
        pdf_page_widgets_with_usage_imp(ctx, doc, page, dev, ctm, usage, cookie);
    }
    fz_always(ctx)
    {
        if (nocache)
            pdf_clear_xref_to_mark(ctx, doc);
    }
    fz_catch(ctx)
    {
        //fz_rethrow(ctx);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::pdf_page_widgets_with_usage_imp(fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    pdf_annot *widget;

    if (cookie && cookie->progress_max != (size_t)-1)
    {
        int count = 1;
        for (widget = page->widgets; widget; widget = widget->next)
            count++;
        cookie->progress_max += count;
    }

    for (widget = page->widgets; widget; widget = widget->next)
    {
        /* Check the cookie for aborting */
        if (cookie)
        {
            if (cookie->abort)
                break;
            cookie->progress++;
        }

        pdf_annot_with_usage(ctx, doc, page, widget, dev, ctm, usage, cookie);
    }
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::pdf_page_annots(fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    pdf_document *doc = page->doc;
    int nocache;

    nocache = !!(dev->hints & FZ_NO_CACHE);
    if (nocache)
        pdf_mark_xref(ctx, doc);

    fz_try(ctx)
    {
        pdf_page_annots_with_usage_imp(ctx, doc, page, dev, ctm, usage, cookie);
    }
    fz_always(ctx)
    {
        if (nocache)
            pdf_clear_xref_to_mark(ctx, doc);
    }
    fz_catch(ctx)
    {
        //fz_rethrow(ctx);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::pdf_page_annots_with_usage_imp(fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    pdf_annot *annot;

    if (cookie && cookie->progress_max != (size_t)-1)
    {
        int count = 1;
        for (annot = page->annots; annot; annot = annot->next)
            count++;
        cookie->progress_max += count;
    }

    for (annot = page->annots; annot; annot = annot->next)
    {
        /* Check the cookie for aborting */
        if (cookie)
        {
            if (cookie->abort)
                break;
            cookie->progress++;
        }

        pdf_annot_with_usage(ctx, doc, page, annot, dev, ctm, usage, cookie);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::pdf_annot_with_usage(fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    fz_matrix page_ctm;
    fz_rect mediabox;
    pdf_processor *proc = NULL;
    fz_default_colorspaces *default_cs = NULL;
    int flags;

    //fzz add begin 2024-04-18
    int resources_pushed = 0;
    //fzz add end 2024-04-18
    //fzz add begin 2024-04-12
    int struct_parent_num;
    pdf_obj *struct_parent;
    //fzz add end 2024-04-12
    
    fz_var(proc);
    fz_var(default_cs);
    //fzz add begin 2024-04-18
    fz_var(resources_pushed);
    //fzz add end 2024-04-18
    
    //fzz add begin
    if (dev == NULL) return;
    fzofd_device *pdev = (fzofd_device*)dev;
    pdev->annotType = pdf_annot_type(ctx, annot);
    
    if ( pdev->annotType == PDF_ANNOT_WIDGET ) {
        if ( pdf_widget_type(ctx, annot) != PDF_WIDGET_TYPE_SIGNATURE ) {
            pdev->annotType = PDF_ANNOT_STAMP;
        }
    }
    
    switch (pdev->annotType) {
        case PDF_ANNOT_FILE_ATTACHMENT:
            if ( pdf_annot_has_filespec(ctx,annot) != 0 && m_isGenFont == false) {
                pdf_obj * fileObj = pdf_annot_filespec(ctx, annot);
                
                if ( fileObj != NULL ) {
                    if ( pdf_is_embedded_file(ctx,fileObj) != 0 ) {
                        pdf_embedded_file_params embeddedFileParams;
                        pdf_get_embedded_file_params(ctx,fileObj,&embeddedFileParams);
                        fz_buffer * fileBuffer = pdf_load_embedded_file_contents(ctx, fileObj);
                        if ( fileBuffer != NULL ) {
                            
                            if ( pdev->ofdDoc != NULL ) {
                                FZZBytes fileData(fileBuffer->data, fileBuffer->len);
                                string filename = embeddedFileParams.filename;
                                size_t pos = filename.find_last_of(".");
                                string name = filename;
                                string format = "";
                                if ( pos != string::npos ) {
                                    name = filename.substr(0,pos);
                                    format = filename.substr(pos+1);
                                }
                                
                                
                                string AttachmentID = "";
                                pdev->ofdDoc->addFileAttachment(&fileData, name, format,&AttachmentID);
                                if ( pdev->Annot_Event_cmd != NULL ) {
                                    *(pdev->Annot_Event_cmd) = "DO:GotoA->NewWindow:true;AttachID:"+AttachmentID+";";
                                }
                            }
                            
                            fz_drop_buffer(ctx, fileBuffer);
                        }
                    }
                }
            }
            break;
        default:
            break;
    }
    //Display only the annot to be displayed
    flags = pdf_dict_get_int(ctx, annot->obj, PDF_NAME(F));

    if ((flags & (PDF_ANNOT_IS_INVISIBLE | PDF_ANNOT_IS_HIDDEN)) || (flags & PDF_ANNOT_IS_NO_VIEW) ){
        //DLOG("annto type : %s , INVISIBLE or HIDDEN or NO_VIEW",pdf_string_from_annot_type(ctx,pdev->annotType));
        return;
    }
    
    
    
    //fzz add end
    
    //DLOG("annto type : %s ",pdf_string_from_annot_type(ctx,pdev->annotType));

    if (cookie && page->super.incomplete)
        cookie->incomplete = 1;

    pdf_annot_push_local_xref(ctx, annot);

    /* Widgets only get displayed if they have both a T and a TF flag,
     * apparently */
    if (pdf_name_eq(ctx, pdf_dict_get(ctx, annot->obj, PDF_NAME(Subtype)), PDF_NAME(Widget)))
    {
        pdf_obj *ft = pdf_dict_get_inheritable(ctx, annot->obj, PDF_NAME(FT));
        pdf_obj *t = pdf_dict_get_inheritable(ctx, annot->obj, PDF_NAME(T));

        if (ft == NULL || t == NULL)
        {
            pdf_annot_pop_local_xref(ctx, annot);
            return;
        }
    }

    fz_try(ctx)
    {
        default_cs = pdf_load_default_colorspaces(ctx, doc, page);
        if (default_cs)
            fz_set_default_colorspaces(ctx, dev, default_cs);

        pdf_page_transform(ctx, page, &mediabox, &page_ctm);

        flags = pdf_dict_get_int(ctx, annot->obj, PDF_NAME(F));
        if (flags & PDF_ANNOT_IS_NO_ROTATE)
        {
            int rotate = pdf_to_int(ctx, pdf_dict_get_inheritable(ctx, page->obj, PDF_NAME(Rotate)));
            fz_rect rect = pdf_dict_get_rect(ctx, annot->obj, PDF_NAME(Rect));
            fz_point tp = fz_transform_point_xy(rect.x0, rect.y1, page_ctm);
            page_ctm = fz_concat(page_ctm, fz_translate(-tp.x, -tp.y));
            page_ctm = fz_concat(page_ctm, fz_rotate(-rotate));
            page_ctm = fz_concat(page_ctm, fz_translate(tp.x, tp.y));
        }

        ctm = fz_concat(page_ctm, ctm);
        //fzz add begin
        //DLOG("annto type : %s begin ",pdf_string_from_annot_type(ctx,pdev->annotType));
        
        
        //---------------------------------------------
        string strAuthor = "Unknown user";
        if ( pdf_annot_has_author(ctx,annot) != 0 ) {
            strAuthor = pdf_annot_author(ctx,annot);
            if ( strAuthor.empty() ) {
                strAuthor = "Unknown user";
            }
        }
        //---------------------------------------------
        string strContents = "";
        //fz_try(ctx) {
            const char * pstrContents = pdf_annot_contents(ctx,annot);
            strContents = pstrContents == NULL ? "" : pstrContents;
            
//            pstrContents = pdf_annot_icon_name(ctx,annot);
//            string striconname = pstrContents == NULL ? "" : pstrContents;
//            DLOG("annto icon name : %s",striconname.c_str());
            //DLOG("annto icon name : %s",strContents.c_str());
            //test begin
//            if ( strContents != "This is a squared (and round-cornered) custom stamp" ) {
//                return;
//            }
            //test end
        //}
        //fz_always(ctx) {
        //    ;
       // }
        //fz_catch(ctx) {
        //    fz_rethrow(ctx);
        //}
        //---------------------------------------------
        
        bool isReadOnly = false;
        if (flags & PDF_ANNOT_IS_READ_ONLY) {
            isReadOnly = true;
        }
        bool isNoZoom = false;
        if (flags & PDF_ANNOT_IS_NO_ZOOM) {
            isNoZoom = true;
        }
        bool isNoRotate = false;
        if (flags & PDF_ANNOT_IS_NO_ROTATE) {
            isNoRotate = true;
        }
        
//        if (flags & PDF_ANNOT_IS_LOCKED) {
//            DLOG("PDF_ANNOT_IS_LOCKED : true");
//        } else {
//            DLOG("PDF_ANNOT_IS_LOCKED : false");
//        }
//
//        if (flags & PDF_ANNOT_IS_TOGGLE_NO_VIEW) {
//            DLOG("PDF_ANNOT_IS_TOGGLE_NO_VIEW : true");
//        } else {
//            DLOG("PDF_ANNOT_IS_TOGGLE_NO_VIEW : false");
//        }
//
//        if (flags & PDF_ANNOT_IS_TOGGLE_NO_VIEW) {
//            DLOG("PDF_ANNOT_IS_LOCKED_CONTENTS : true");
//        } else {
//            DLOG("PDF_ANNOT_IS_LOCKED_CONTENTS : false");
//        }
        
        
            
            
//            int64_t intDate = pdf_annot_creation_date(ctx,annot);
//            
//            int64_t milli = intDate+ (int64_t)8*60*60*1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//            auto mTime = std::chrono::milliseconds(milli);
//            auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
//            auto tt = std::chrono::system_clock::to_time_t(tp);
//            std::tm* t = std::gmtime(&tt);
//            char buffer[40] = { 0 };
//            sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
//            DLOG("annto time : %s",buffer);
        
        
        
        
        if ( pdev->OFD_genAnnot != NULL ) {
            pdev->OFD_genAnnot(ctx,pdev,strAuthor,strContents,isReadOnly,isNoZoom,isNoRotate);
        }
        //fzz add end
        
        
        //fzz edit begin 2024-04-12
        //proc = pdf_new_run_processor(ctx, dev, ctm, usage, NULL, default_cs, cookie);
        
        struct_parent = pdf_dict_getl(ctx, page->obj, PDF_NAME(StructParent));
        struct_parent_num = pdf_to_int_default(ctx, struct_parent, -1);
        proc = pdf_new_run_processor(ctx, page->doc, dev, ctm, struct_parent_num, usage, NULL, default_cs, cookie);
        //fzz edit end 2024-04-12
        if ( proc != NULL ) {
            //fzz add begin 2024-04-18
            pdf_processor_push_resources(ctx, proc, pdf_page_resources(ctx, annot->page));
            resources_pushed = 1;
            //fzz add end 2024-04-18
            pdf_process_annot(ctx, proc, annot, cookie);
            pdf_close_processor(ctx, proc);
        }
        //fzz add begin
        if ( pdev->OFD_annotationrender != NULL ) {
            pdev->OFD_annotationrender(pdev);
        }
        //DLOG("annto type : %s end ",pdf_string_from_annot_type(ctx,pdev->annotType));
        //fzz add end
        
    }
    fz_always(ctx)
    {
        //fzz add begin 2024-04-18
        if (resources_pushed)
            pdf_processor_pop_resources(ctx, proc);
        //fzz add end 2024-04-18
        if ( proc != NULL ) {
            pdf_drop_processor(ctx, proc);
        }
        fz_drop_default_colorspaces(ctx, default_cs);
        pdf_annot_pop_local_xref(ctx, annot);
    }
    fz_catch(ctx) {
        //fz_rethrow(ctx);
    }
}

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2OFD::test()
{
//
//    FZZConst::readfile("/Users/fzz/work/cpp/ofd/tmp/Doc2.pdf", m_PdfData);
//
//    m_CTX = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
//    if ( m_CTX == NULL ) return;
//
//    fz_set_aa_level(m_CTX, 8);
//
//    m_PdfData.setData(m_PdfData.getData(), m_PdfData.getLen());
//    m_Stm = fz_open_memory(m_CTX, m_PdfData.getData(), m_PdfData.getLen());
//    if ( m_Stm == NULL ) return;
//    m_Doc = pdf_open_document_with_stream(m_CTX, m_Stm);
//
//    //---------------------------------------------------------------
//
//    fz_page *page = fz_load_page(m_CTX, (fz_document *)m_Doc, 0);
//
//    fz_rect rect;
//    fz_irect bbox;
//
//    fz_device *dev = NULL;
//
//    rect = fz_bound_page(m_CTX, page);
//
//    rect = fz_transform_rect(rect, MUPDF_fz_identity);
//    bbox = fz_round_rect(rect);
//
//    //fz_run_page_contents(m_CTX, page, dev, MUPDF_fz_identity, NULL);
//    //    fz_run_page_annots(m_CTX, page, dev, MUPDF_fz_identity, NULL);
//    //    fz_run_page_widgets(m_CTX, page, dev, MUPDF_fz_identity, NULL);
//    fz_matrix page_ctm;
//
//    fz_rect mediabox;
//    pdf_page_transform(m_CTX, (pdf_page *)page, &mediabox, &page_ctm);
//
//    //pdf_obj *group = pdf_page_group(m_CTX, (pdf_page *)page);
//    //pdf_obj *cs = pdf_dict_get(m_CTX, group, PDF_NAME(CS));
//
//    //pdf_lexbuf_init(ctx, &buf, PDF_LEXBUF_SMALL);
//
//    fz_close_device(m_CTX, dev);
//    fz_drop_device(m_CTX, dev);
//
//    fz_drop_page(m_CTX, page);
//    //----------------------------------------------------------------
//
//
//    if ( m_Stm != NULL ) {
//        fz_drop_stream(m_CTX, m_Stm);
//        m_Stm = NULL;
//    }
//    if ( m_Doc != NULL ) {
//        pdf_drop_document(m_CTX,m_Doc);
//        m_Doc = NULL;
//    }
//
//    if ( m_CTX != NULL ) {
//        fz_flush_warnings(m_CTX);
//        fz_drop_context(m_CTX);
//        m_CTX = NULL;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
