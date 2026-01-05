//
//  Created by zizheng fan on 2022/12/01.
//
#include "basic/FZZConst.h"
#include "converter/image/FZZPDFToImage.h"
//#include "converter/utils/PdfiumProxy.h"

#include "converter/utils/FZZImageUtil.h"

//fzz test begin 2024-05-14
//#include "pdfsign/FZZPkcs7_GM.h"
//fzz test end 2024-05-14
#include "pdfsign/FZZPDFSigner.h"

#include "mupdf/fitz/util.h"


//#include "pdf-annot-imp.h"
//pdf_annot in pdf-annot-imp.h
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
static void pdftoimage_dev_close_device(fz_context *ctx, fz_device *dev)
{
    //last close
    pdftoimage_device *pdev = (pdftoimage_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    if ( pdev->stampImage != NULL ) {
        delete pdev->stampImage;
        pdev->stampImage = NULL;
    }
    
//    vector<FZZBytes *>::const_iterator iter;
//    for (iter = pdev->stampImageList.begin(); iter != pdev->stampImageList.end(); iter++) {
//        FZZBytes* temp = *iter;
//        if ( temp != NULL ) {
//            delete temp;
//            temp = NULL;
//        }
//    }
//    pdev->stampImageList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
static void pdftoimage_dev_fill_image(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    if ( dev == NULL ) {
        return;
    }
    
    pdftoimage_device *pdev = (pdftoimage_device*)dev;
    
    fz_pixmap * pix = fz_get_unscaled_pixmap_from_image(ctx,image);
    if ( pix == NULL ) {
        return;
    }
    
    fz_buffer *buf = fz_new_buffer(ctx, INCREMENT_BUFLEN_PNG);
    if ( buf != NULL ) {
        fz_output * out = fz_new_output_with_buffer(ctx, buf);
        if ( out != NULL ) {
            fz_write_pixmap_as_png(ctx, out, pix);
      
            if ( pdev->stampImage != NULL ) {
                delete pdev->stampImage;
                pdev->stampImage = NULL;
            }
            pdev->stampImage = new FZZBytes(buf->data, (int)(buf->len));
            if ( pdev->stampImage != NULL && image->mask != NULL ) {
                if (image->mask->imagemask)  {
                    DLOG("ofd_dev_fill_image is call -> image->mask != NULL , type : mask");
                } else {
                    //DLOG("ofd_dev_fill_image is call -> image->mask != NULL , type : smask");
                    FZZBytes maskImage;
                    fz_pixmap * pix_mask = fz_get_unscaled_pixmap_from_image(ctx,image->mask);
                    if ( pix_mask == NULL ) {
                        return;
                    }
                    fz_buffer *buf_mask = fz_new_buffer(ctx, INCREMENT_BUFLEN_PNG);
                    if ( buf_mask != NULL ) {
                        fz_output * out_mask = fz_new_output_with_buffer(ctx, buf_mask);
                        if ( out_mask != NULL ) {
                            fz_write_pixmap_as_png(ctx, out_mask, pix_mask);
                            maskImage.setData(buf_mask->data, (int)(buf_mask->len));
                        }
                        
                        fz_close_output(ctx, out_mask);
                        fz_drop_output(ctx, out_mask);
                    }
                    fz_drop_buffer(ctx, buf_mask);
                    fz_drop_pixmap(ctx, pix_mask);

                    FZZImageUtil imageUtil;

                    FZZBytes tempsrc(pdev->stampImage->getData(),pdev->stampImage->getLen());
                    imageUtil.renderMask(tempsrc, maskImage);

                    FZZBytes tempimageData = imageUtil.PngEncode();

                    pdev->stampImage->setData(tempimageData.getData(), tempimageData.getLen());
                
                }
            }
            
            //imageData
            //pdev->stampImageList.push_back(imageData);
            
            fz_close_output(ctx, out);
            fz_drop_output(ctx, out);
        }
        fz_drop_buffer(ctx, buf);
    }
        
    fz_drop_pixmap(ctx, pix);
 
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
fz_device * new_pdftoimage_device(fz_context *ctx)
{
    pdftoimage_device *dev = fz_new_derived_device(ctx, pdftoimage_device);
    if ( dev == NULL ) {
        return NULL;
    }
    
    dev->super.close_device = pdftoimage_dev_close_device;
    dev->super.drop_device = NULL;
    
    dev->super.fill_path = NULL;
    dev->super.stroke_path = NULL;
    dev->super.clip_path = NULL;
    dev->super.clip_stroke_path = NULL;

    dev->super.fill_text = NULL;
    dev->super.stroke_text = NULL;
    dev->super.clip_text = NULL;
    dev->super.clip_stroke_text = NULL;
    dev->super.ignore_text = NULL;

    dev->super.fill_shade = NULL;
    dev->super.fill_image = pdftoimage_dev_fill_image;
    dev->super.fill_image_mask = NULL;
    dev->super.clip_image_mask = NULL;

    dev->super.pop_clip = NULL;

    dev->super.begin_mask = NULL;
    dev->super.end_mask = NULL;
    dev->super.begin_group = NULL;
    dev->super.end_group = NULL;

    dev->super.begin_tile = NULL;
    dev->super.end_tile = NULL;
    
    dev->stampImage = NULL;
    
    return (fz_device*)dev;
}
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPDFToImage**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPDFToImage::FZZPDFToImage() : m_PDF(NULL),m_CTX(NULL),m_Doc(NULL),m_Stm(NULL),m_PassWord("")
{
    //DLOG("FZZPDFToImage()");
    FZZConst::addClassCount("FZZPDFToImage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFToImage::FZZPDFToImage(FZZPDF * pdf): FZZPDFToImage()
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
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFToImage::FZZPDFToImage(const FZZPDFToImage& obj): FZZPDFToImage()
{
    //DLOG("FZZPDFToImage(const FZZPDFToImage& obj)");
    if ( this == &obj ) {
        return;
    }
//    this->m_PDF = obj.m_PDF;
//    this->m_CTX = obj.m_CTX;
//    this->m_Doc = obj.m_Doc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFToImage::~FZZPDFToImage()
{
    //DLOG("~FZZPDFToImage()");
    FZZConst::delClassCount("FZZPDFToImage");
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
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDFToImage::isNeedPassWord()
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
bool FZZPDFToImage::VerifyPassWord(string pwd)
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
int FZZPDFToImage::pageSize()
{
    int page_count = 0;
    if ( m_Doc != NULL ) {
        page_count = pdf_count_pages(m_CTX,m_Doc);
    }
    return page_count;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZPDFToImage::makePage(int pageIndex,string imageType)
{
    return makePage(pageIndex,imageType,(float)1);
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZPDFToImage::makePage(int pageIndex,string imageType,float scaleValue)
{
    FZZBytes ret;
    if ( m_CTX == NULL ) {
        return ret;
    }
    fz_try(m_CTX) {
        if ( m_Doc != NULL && pageIndex >= 0 ) {
            
            //fz_context * ctx = fz_clone_context(m_CTX);
            
            fz_matrix ctm = MUPDF_fz_identity;
            
            ctm = fz_post_scale(ctm,scaleValue,scaleValue);
            
            fz_pixmap * pix = fz_new_pixmap_from_page_number(m_CTX,(fz_document *)m_Doc,pageIndex,ctm,fz_device_rgb(m_CTX),false);
            if ( pix != NULL ) {
            
                fz_buffer *buf = fz_new_buffer(m_CTX, INCREMENT_BUFLEN_PNG);
                if ( buf != NULL ) {
                    fz_output * out = fz_new_output_with_buffer(m_CTX, buf);
                    if ( out != NULL ) {
                        transform(imageType.begin(), imageType.end(), imageType.begin(), ::toupper);
                        if ( imageType != "PNG" ) {
                            if ( pix->n == 4 ) {
                                
                                fz_pixmap * tempPixMap = fz_new_pixmap(m_CTX, fz_device_rgb(m_CTX), pix->w, pix->h,NULL,0);

                                FZZImageUtil imageUtil(m_CTX);
                                imageUtil.deleteAlpha(pix,tempPixMap);

                                fz_write_pixmap_as_jpeg(m_CTX, out, tempPixMap,100,1);

                                fz_drop_pixmap(m_CTX, tempPixMap);
                                
                            } else {
                               
                                fz_write_pixmap_as_jpeg(m_CTX, out, pix,100,1);
                                
                            }
                        } else {
                            fz_write_pixmap_as_png(m_CTX, out, pix);
                        }
                        
                        ret.setData(buf->data, buf->len);
                        
                        fz_close_output(m_CTX, out);
                        fz_drop_output(m_CTX, out);
                    }
                    fz_drop_buffer(m_CTX, buf);
                }
                fz_drop_pixmap(m_CTX, pix);
            }
        }
        
    } fz_catch(m_CTX) {
        DLOG("gen svg error : %s",m_CTX->error.message);
    }

//    if ( ret.getLen() > 0 ) {
//        transform(imageType.begin(), imageType.end(), imageType.begin(), ::toupper);
//        if ( imageType != "PNG" ) {
//
//            FZZImageUtil imageUtil;
//            DLOG("makePage 1..1");
//            if ( imageUtil.LoadImage(ret) ) {
//                if (imageType == "JPG") {
//                    DLOG("makePage 1..1..1");
//                    ret = imageUtil.JPGEncode();
//                    DLOG("makePage 1..1..2 end");
//                }
//
//            }
//            DLOG("makePage 1..1 end");
//        }
//    }
  
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//bool FZZPDFToImage::PdfWritePng(FZZBytes & pngData, void *buffer,
//                 int width, int height, int stride)
//{
//    // BGRA > RGBA
//    auto buf = reinterpret_cast<uint8_t *>(buffer);
//    for (int r = 0; r < height; ++r) {
//        for (int c = 0; c < width; ++c) {
//            auto pixel = buf + (r*stride) + (c*4);
//            auto b = pixel[0];
//            pixel[0] = pixel[2];  // b = r
//            pixel[2] = b;         // r = b
//        }
//    }
//
//    ImageUtil imageUtil;
//    imageUtil.ImageDataToPNG(buf, width, height, stride, pngData);
//    return true;
//
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFToImage::getOtherInfo(int pageIndex,AttachmentFileFunc attachmentFileFunc,
                              AnnotsFunc annotsFunc,
                              StampsFunc stampsFunc)
{
    pdf_page * pdfpage = NULL;
    fz_device * dev = NULL;

    
    dev = new_pdftoimage_device(m_CTX);
    if ( dev == NULL ) {
        goto err;
    }
    
 
    
    pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
    if ( pdfpage == NULL ) {
        goto err;
    }
    
    
    pdf_page_annots(pageIndex,m_CTX, pdfpage, dev, MUPDF_fz_identity, "View",NULL,attachmentFileFunc,annotsFunc,stampsFunc);
    pdf_page_widgets(pageIndex,m_CTX, pdfpage, dev, MUPDF_fz_identity, "View", NULL,attachmentFileFunc,annotsFunc,stampsFunc);
    
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
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFToImage::pdf_page_annots(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                 AnnotsFunc annotsFunc,
                                 StampsFunc stampsFunc)
{
    pdf_document *doc = page->doc;
    int nocache;

    nocache = !!(dev->hints & FZ_NO_CACHE);
    if (nocache)
        pdf_mark_xref(ctx, doc);

    fz_try(ctx)
    {
        pdf_page_annots_with_usage_imp(pageIndex,ctx, doc, page, dev, ctm, usage, cookie,attachmentFileFunc,annotsFunc,stampsFunc);
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
void FZZPDFToImage::pdf_page_annots_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                                AnnotsFunc annotsFunc,
                                                StampsFunc stampsFunc)
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

        pdf_annot_with_usage(pageIndex,ctx, doc, page, annot, dev, ctm, usage, cookie,attachmentFileFunc,annotsFunc,stampsFunc);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFToImage::pdf_page_widgets(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                  AnnotsFunc annotsFunc,
                                  StampsFunc stampsFunc)
{
    pdf_document *doc = page->doc;
    int nocache;

    nocache = !!(dev->hints & FZ_NO_CACHE);
    if (nocache)
        pdf_mark_xref(ctx, doc);

    fz_try(ctx)
    {
        pdf_page_widgets_with_usage_imp(pageIndex,ctx, doc, page, dev, ctm, usage, cookie,attachmentFileFunc,annotsFunc,stampsFunc);
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
void FZZPDFToImage::pdf_page_widgets_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                                 AnnotsFunc annotsFunc,
                                                 StampsFunc stampsFunc)
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

        pdf_annot_with_usage(pageIndex,ctx, doc, page, widget, dev, ctm, usage, cookie,attachmentFileFunc,annotsFunc,stampsFunc);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFToImage::pdf_annot_with_usage(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                      AnnotsFunc annotsFunc,
                                      StampsFunc stampsFunc)
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
  
    enum pdf_annot_type annotType = pdf_annot_type(ctx, annot);
    
    int signid = pdf_to_num(ctx, annot->obj);
    string strsignid = FZZConst::fmt(signid);
    
    
    int64_t intDate = pdf_annot_modification_date(ctx,annot);
    int64_t milli = intDate*1000+ (int64_t)8*60*60*1000;
    auto mTime = std::chrono::milliseconds(milli);
    auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
    auto tt = std::chrono::system_clock::to_time_t(tp);
    std::tm* t = std::gmtime(&tt);
    char buffer[40] = { 0 };
    sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    DLOG("annto time : %s",buffer);
    
    
    switch (annotType) {
        case PDF_ANNOT_FILE_ATTACHMENT:
            if ( pdf_annot_has_filespec(ctx,annot) != 0 ) {
                pdf_obj * fileObj = pdf_annot_filespec(ctx, annot);
                
                if ( fileObj != NULL ) {
                    if ( pdf_is_embedded_file(ctx,fileObj) != 0 ) {
                        pdf_embedded_file_params embeddedFileParams;
                        pdf_get_embedded_file_params(ctx,fileObj,&embeddedFileParams);
                        fz_buffer * fileBuffer = pdf_load_embedded_file_contents(ctx, fileObj);
                        if ( fileBuffer != NULL ) {
                            
                            if ( attachmentFileFunc != NULL ) {
                                FZZBytes fileData(fileBuffer->data, (int)(fileBuffer->len));
                                string filename = embeddedFileParams.filename;
                                size_t pos = filename.find_last_of(".");
                                string name = filename;
                                string format = "";
                                if ( pos != string::npos ) {
                                    name = filename.substr(0,pos);
                                    format = filename.substr(pos+1);
                                }
                                
//                                int64_t intDate = pdf_annot_modification_date(ctx,annot);
//                                int64_t milli = intDate*1000+ (int64_t)8*60*60*1000;
//                                auto mTime = std::chrono::milliseconds(milli);
//                                auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
//                                auto tt = std::chrono::system_clock::to_time_t(tp);
//                                std::tm* t = std::gmtime(&tt);
//                                char buffer[40] = { 0 };
//                                sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
//                                DLOG("annto time : %s",buffer);
                                const char* pFileName = filename.c_str();
                                const char* pTime = buffer;
//#ifdef _MSC_VER
//                                string gbstr = pFileName;
//                                string utf8str = FZZConst::GB2312toUtf8(gbstr);
//                                pFileName = utf8str.c_str();
//
//                                gbstr = pTime;
//                                string utf8strTime = FZZConst::GB2312toUtf8(gbstr);
//                                pTime = utf8strTime.c_str();
//
//#endif
                                attachmentFileFunc(pFileName, pTime,fileData.getData(),(int)fileData.getLen());
                                
                                //string AttachmentID = "";
                                //pdev->ofdDoc->addFileAttachment(fileData, name, format,&AttachmentID);
                                //pdev->Annot_Event_cmd = "DO:GotoA->NewWindow:true;AttachID:"+AttachmentID+";";
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
    //只要显示的annot
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

    //pdf_pkcs7_verifier *verifier = NULL;
    //pdf_pkcs7_distinguished_name *dn = NULL;
    //fz_var(dn);
    fz_try(ctx)
    {
        default_cs = pdf_load_default_colorspaces(ctx, doc, page);
//        if (default_cs)
//            fz_set_default_colorspaces(ctx, dev, default_cs);

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
//            int64_t milli = intDate+ (int64_t)8*60*60*1000;
//            auto mTime = std::chrono::milliseconds(milli);
//            auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
//            auto tt = std::chrono::system_clock::to_time_t(tp);
//            std::tm* t = std::gmtime(&tt);
//            char buffer[40] = { 0 };
//            sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
//            DLOG("annto time : %s",buffer);
        
//        int64_t intDate = pdf_annot_modification_date(ctx,annot);
//        int64_t milli = intDate*1000+ (int64_t)8*60*60*1000;
//        auto mTime = std::chrono::milliseconds(milli);
//        auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
//        auto tt = std::chrono::system_clock::to_time_t(tp);
//        std::tm* t = std::gmtime(&tt);
//        char buffer[40] = { 0 };
//        sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
//        DLOG("annto time : %s",buffer);
        
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

        const char* pcreator = strAuthor.c_str();
        const char* pTime = buffer;
        const char* pstrannottype_TYPE_Highlight = "Highlight";
        const char* pstrannottype_TYPE_Stamp = "Stamp";
        //AnnotType::toString(AnnotType::TYPE::TYPE_Path).c_str()
        const char* pstrannottype_TYPE_Path = "Path";
        //AnnotType::toString(AnnotType::TYPE::TYPE_Link).c_str()
        const char* pstrannottype_TYPE_Link = "Link";
        const char* pstrremark = strContents.c_str();
        string strPageIndex = FZZConst::fmt(pageIndex + 1);
        const char* pPageindex = strPageIndex.c_str();
//#ifdef _MSC_VER
//        string gbstr = pcreator;
//        string utf8str = FZZConst::GB2312toUtf8(gbstr);
//        pcreator = utf8str.c_str();
//
//        gbstr = pTime;
//        string utf8strTime = FZZConst::GB2312toUtf8(gbstr);
//        pTime = utf8strTime.c_str();
//
//        gbstr = pstrannottype_TYPE_Highlight;
//        string utf8strannottype_TYPE_Highlight = FZZConst::GB2312toUtf8(gbstr);
//        pstrannottype_TYPE_Highlight = utf8strannottype_TYPE_Highlight.c_str();
//
//        gbstr = pstrannottype_TYPE_Stamp;
//        string utf8strannottype_TYPE_Stamp = FZZConst::GB2312toUtf8(gbstr);
//        pstrannottype_TYPE_Stamp = utf8strannottype_TYPE_Stamp.c_str();
//
//        gbstr = pstrannottype_TYPE_Path;
//        string utf8strannottype_TYPE_Path = FZZConst::GB2312toUtf8(gbstr);
//        pstrannottype_TYPE_Path = utf8strannottype_TYPE_Path.c_str();
//
//        gbstr = pstrannottype_TYPE_Link;
//        string utf8strannottype_TYPE_Link = FZZConst::GB2312toUtf8(gbstr);
//        pstrannottype_TYPE_Link = utf8strannottype_TYPE_Link.c_str();
//
//        gbstr = pstrremark;
//        string utf8strremark = FZZConst::GB2312toUtf8(gbstr);
//        pstrremark = utf8strremark.c_str();
//
//        gbstr = pPageindex;
//        string utf8strpageindex = FZZConst::GB2312toUtf8(gbstr);
//        pPageindex = utf8strpageindex.c_str();
//
//#endif

        pdftoimage_device * pdev = (pdftoimage_device*)dev;
        switch (annotType) {
            
            case PDF_ANNOT_SQUIGGLY:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Highlight, pstrremark);
                }
                break;
            case PDF_ANNOT_STRIKE_OUT:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Highlight, pstrremark);
                }
                break;
            case PDF_ANNOT_UNDERLINE:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Highlight, pstrremark);
                }
                break;
            case PDF_ANNOT_HIGHLIGHT:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Highlight, pstrremark);
                }
                break;
            case PDF_ANNOT_TEXT:
            case PDF_ANNOT_FREE_TEXT:
            case PDF_ANNOT_STAMP:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Stamp, pstrremark);
                }
                break;
            case PDF_ANNOT_WIDGET:
                if ( stampsFunc != NULL && pdev->stampImage != NULL ) {
                    //is RidingStamp
                    if (pdf_signature_is_signed(ctx, doc, annot->obj)) {
                        //fzz test begin 2024-05-14
                        /*
                        verifier = pkcs7_gm_create_verifier(ctx,NULL,NULL);
                        
                        dn = pdf_signature_get_signatory(ctx, verifier, doc, annot->obj);
                        GM_VERIFIER* gmverifyer = (GM_VERIFIER*)verifier;
                        if ( gmverifyer->imagedata != NULL && gmverifyer->imagedata->getLen() > 10 ) {
                            pdev->stampImage->setData(gmverifyer->imagedata->getData(), gmverifyer->imagedata->getLen());
                        }

                        stampsFunc(pPageindex,"",strsignid.c_str(),pdev->stampImage->getData(),(int)pdev->stampImage->getLen());
                         */
                        //fzz test end 2024-05-14
                        FZZBytes imageData;
                        FZZPDFSigner::getStampImage(ctx,doc, annot->obj,imageData);
                        if ( imageData.getLen() > 10 ) {
                            pdev->stampImage->setData(imageData.getData(), imageData.getLen());
                        }
                        stampsFunc(pPageindex,"",strsignid.c_str(),imageData.getData(), (int)imageData.getLen());
                    }
                }
             
                break;
            case PDF_ANNOT_INK:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Path, pstrremark);
                }
                break;
            case PDF_ANNOT_SQUARE:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Path, pstrremark);
                }
                break;
            case PDF_ANNOT_CIRCLE:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Path, pstrremark);
                }
                break;
            case PDF_ANNOT_LINE:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Path, pstrremark);
                }
                break;
            case PDF_ANNOT_FILE_ATTACHMENT:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Link, pstrremark);
                }
                break;
            default:
                if ( annotsFunc != NULL ) {
                    annotsFunc(pageIndex, pcreator, pTime, pstrannottype_TYPE_Path, pstrremark);
                }
                break;
        }
        
        
        
        
//        if ( pdev->genAnnot != NULL ) {
//            pdev->genAnnot(ctx,pdev,strAuthor,strContents,isReadOnly,isNoZoom,isNoRotate);
//        }
        //fzz add end
        
        
        
        
        
        if ( pdev->stampImage != NULL ) {
            delete pdev->stampImage;
            pdev->stampImage = NULL;
        }
        
        //fzz add begin
        //if ( pdev->annotationrender != NULL ) {
        //    pdev->annotationrender(pdev);
        //}
        //DLOG("annto type : %s end ",pdf_string_from_annot_type(ctx,pdev->annotType));
        //fzz add end
        
    }
    fz_always(ctx)
    {
//        if ( dn != NULL ) {
//            pdf_signature_drop_distinguished_name(ctx, dn);
//        }
//        if ( verifier != NULL ) {
//            pdf_drop_verifier(ctx, verifier);
//        }
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
void FZZPDFToImage::findWord(int pageIndex,const char* const word,FindWordFunc findWordFunc)
{
    if ( m_CTX == NULL ) {
        return;
    }
    
    if ( m_Doc == NULL ) {
        return;
    }
    
    if ( findWordFunc == NULL ) {
        return;
    }
    
    if ( pageIndex < 0 ) {
        pageIndex = 0;
    }
    
    int pagecount = pageSize();
    if ( pageIndex >=  pagecount ) {
        pageIndex = pagecount-1;
    }
    
    fz_quad quads[500] = {0};
    
    
    int count = fz_search_page_number(m_CTX, (fz_document *)m_Doc, pageIndex, word, NULL,quads, 500);
    
    float x = 0;
    float y = 0;
    float w = 0;
    float h = 0;

    for( int i = 0; i < count; i++ ) {
        if ( quads[i].ll.x == 0 && quads[i].ll.y == 0 && quads[i].lr.x == 0 && quads[i].lr.y == 0 &&
            quads[i].ul.x == 0 && quads[i].ul.y == 0 && quads[i].ur.x == 0 && quads[i].ur.y == 0 ) {
            break;
        }
        
        if ( quads[i].ll.x <= quads[i].lr.x ) {
            x = quads[i].ll.x;
            w = quads[i].lr.x - x;
        } else {
            x = quads[i].lr.x;
            w = quads[i].ll.x - x;
        }
        
        if ( quads[i].ur.y <= quads[i].lr.y ) {
            y = quads[i].ur.y;
            h = quads[i].lr.y - y;
        } else {
            y = quads[i].lr.y;
            w = quads[i].ur.y - y;
        }

        const char* ptempstr = word;
//#ifdef _MSC_VER
//        string gbstr = ptempstr;
//        string utf8str = FZZConst::GB2312toUtf8(gbstr);
//        ptempstr = utf8str.c_str();
//
//#endif

        findWordFunc(pageIndex, ptempstr,x,y,w,h);
        
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFToImage::findWord(int pageIndex,const char* const word,float *xs,float * ys,float *ws,float * hs,int* number,int max)
{
    if ( m_CTX == NULL ) {
        return;
    }
    
    if ( m_Doc == NULL ) {
        return;
    }
    
    if ( xs == NULL || ys == NULL || ws == NULL || hs == NULL || max <= 0 ) {
        return;
    }
    
    if ( pageIndex < 0 ) {
        pageIndex = 0;
    }
    
    int pagecount = pageSize();
    if ( pageIndex >=  pagecount ) {
        pageIndex = pagecount-1;
    }
    
    fz_quad quads[500] = {0};
    
    
    int count = fz_search_page_number(m_CTX, (fz_document *)m_Doc, pageIndex, word, NULL,quads, 500);
//    page = fz_load_page(ctx, doc, number);
//    fz_try(ctx)
//        count = fz_search_page(m_CTX, page, word, &hit, &hit,quads, 500);
//    fz_always(ctx)
//        fz_drop_page(ctx, page);
//    fz_catch(ctx)
//        fz_rethrow(ctx);
    
    float x = 0;
    float y = 0;
    float w = 0;
    float h = 0;
    count = max <= count ? max : count;
    for( int i = 0; i < count; i++ ) {
        if ( quads[i].ll.x == 0 && quads[i].ll.y == 0 && quads[i].lr.x == 0 && quads[i].lr.y == 0 &&
            quads[i].ul.x == 0 && quads[i].ul.y == 0 && quads[i].ur.x == 0 && quads[i].ur.y == 0 ) {
            break;
        }
        
        if ( quads[i].ll.x <= quads[i].lr.x ) {
            x = quads[i].ll.x;
            w = quads[i].lr.x - x;
        } else {
            x = quads[i].lr.x;
            w = quads[i].ll.x - x;
        }
        
        if ( quads[i].ur.y <= quads[i].lr.y ) {
            y = quads[i].ur.y;
            h = quads[i].lr.y - y;
        } else {
            y = quads[i].lr.y;
            w = quads[i].ur.y - y;
        }
        xs[i] = x;
        ys[i] = y;
        ws[i] = w;
        hs[i] = h;
        *number = i+1;
        
    }
    
}
//-----------------------------------------------------------------------------------------------------------------

