//
//  Created by zizheng fan on 2024/09/18.
//
#include "basic/FZZConst.h"
#include "converter/tosvg/FZZPDF2SVG.h"
#include "converter/utils/FZZCommonUtil.h"
#include "FZZSVGDevice.h"
#include "fzfont/FZZTempFontCache.h"


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
/***********************************************FZZPDF2SVG**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2SVG::FZZPDF2SVG() : m_CTX(NULL),m_Doc(NULL),m_Stm(NULL),m_PDF(NULL),m_isNoStamp(false),m_PassWord("")
{
    //DLOG("FZZPDF2SVG()");
    FZZConst::addClassCount("FZZPDF2SVG");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2SVG::FZZPDF2SVG(FZZPDF * pdf) : FZZPDF2SVG()
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
FZZPDF2SVG::FZZPDF2SVG(const FZZPDF2SVG& obj): FZZPDF2SVG()
{
    //DLOG("FZZPDF2SVG(const FZZPDF2SVG& obj)");
    if ( this == &obj ) {
        return;
    }
//    this->m_PDF = obj.m_PDF;
//    this->m_CTX = obj.m_CTX;
//    this->m_Doc = obj.m_Doc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDF2SVG::~FZZPDF2SVG()
{
    //DLOG("~FZZPDF2SVG()");
    FZZConst::delClassCount("FZZPDF2SVG");
    
    
    
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
bool FZZPDF2SVG::isNeedPassWord()
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
bool FZZPDF2SVG::VerifyPassWord(string pwd)
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

int FZZPDF2SVG::pageSize()
{
    int page_count = 0;
    if ( m_Doc != NULL ) {
        page_count = pdf_count_pages(m_CTX,m_Doc);
    }
    return page_count;
}
//-----------------------------------------------------------------------------------------------------------------
//bool FZZPDF2SVG::makePage(int pageIndex)
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

FZZBytes FZZPDF2SVG::makePage(int pageIndex)
{
    FZZBytes Ret;
    pdf_page * pdfpage = NULL;
    fz_matrix page_ctm;
    fz_rect mediabox;
    fz_device * dev = NULL;
    fz_buffer * outbuf = NULL;
    fz_output * output = NULL;
    
    //DLOG("begin page ..................%d",pageIndex);
    
    
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
    
   
    
    outbuf = fz_new_buffer(m_CTX, 1024);
    if ( outbuf == NULL ) {
        goto err;
    }
    output = fz_new_output_with_buffer(m_CTX, outbuf);
    if ( output == NULL ) {
        goto err;
    }
  
//    if ( page_ctm.b != 0 || page_ctm.c != 0 ) {
//        dev = new_fzsvg_device(m_CTX,output,mediabox.y1, mediabox.x1, /*FZ_SVG_TEXT_AS_TEXT*/FZ_SVG_TEXT_AS_PATH, 1);
//    } else {
//        dev = new_fzsvg_device(m_CTX,output,mediabox.x1, mediabox.y1, /*FZ_SVG_TEXT_AS_TEXT*/FZ_SVG_TEXT_AS_PATH, 1);
//
//    }
    dev = new_fzsvg_device(m_CTX,output,mediabox.x1, mediabox.y1, /*FZ_SVG_TEXT_AS_TEXT*/FZ_SVG_TEXT_AS_PATH, 1);
    
    if ( dev == NULL ) {
        goto err;
    }
    fz_try(m_CTX) {
    
    //pdf_run_page_with_usage(m_CTX, pdfpage, dev, MUPDF_fz_identity,"View",NULL);
    
    //看 pdf_run_page_with_usage 这个函数实现，新建这个类
    //fz_run_page_contents 本身有内存泄露，目前可以确定定位到这个函数，待后续有大量时间时解决
    fz_run_page_contents(m_CTX, (fz_page *)pdfpage, dev, MUPDF_fz_identity, NULL);
    //pdf_run_page_annots(m_CTX, pdfpage, dev, MUPDF_fz_identity,NULL);
    pdf_page_annots(m_CTX, pdfpage, dev, MUPDF_fz_identity, "View",NULL);
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
    
    fz_close_device(m_CTX, dev);
    fz_close_output(m_CTX, output);
    if ( outbuf != NULL && outbuf->len > 0 ) {
        Ret.setData(outbuf->data, outbuf->len);
    }
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
    
    if ( output != NULL ) {
        fz_drop_output(m_CTX, output);
        output = NULL;
    }
    if ( outbuf != NULL ) {
        fz_drop_buffer(m_CTX, outbuf);
        outbuf = NULL;
    }
    
    //DLOG("end page ..................%d",pageIndex);
    return Ret;
}
 
//-----------------------------------------------------------------------------------------------------------------
void FZZPDF2SVG::pdf_page_widgets(fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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
void FZZPDF2SVG::pdf_page_widgets_with_usage_imp(fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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
void FZZPDF2SVG::pdf_page_annots(fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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
void FZZPDF2SVG::pdf_page_annots_with_usage_imp(fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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
void FZZPDF2SVG::pdf_annot_with_usage(fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    fz_matrix page_ctm;
    fz_rect mediabox;
    pdf_processor *proc = NULL;
    fz_default_colorspaces *default_cs = NULL;
    int flags;
    int resources_pushed = 0;
    int struct_parent_num;
    pdf_obj *struct_parent;

    fz_var(proc);
    fz_var(default_cs);
    fz_var(resources_pushed);

    //fzz add begin 2004.09.18
    enum pdf_annot_type annotType = pdf_annot_type(ctx, annot);
    switch (annotType) {
        case PDF_ANNOT_WIDGET:
            if ( pdf_widget_type(ctx, annot) == PDF_WIDGET_TYPE_SIGNATURE ) {
                if ( m_isNoStamp ) {
                    //fzz add begin 2004.09.18
                    ((fzsvg_device *)dev)->isstamp = false;
                    //fzz add end 2004.09.18
                    return;
                }
                
                ((fzsvg_device *)dev)->isstamp = true;
            }
            

            break;
        default:
            break;
    }
    //fzz add end 2004.09.18
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
            //fzz add begin 2004.09.18
            ((fzsvg_device *)dev)->isstamp = false;
            //fzz add end 2004.09.18
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
            int rotate = pdf_dict_get_inheritable_int(ctx, page->obj, PDF_NAME(Rotate));
            fz_rect rect = pdf_dict_get_rect(ctx, annot->obj, PDF_NAME(Rect));
            fz_point tp = fz_transform_point_xy(rect.x0, rect.y1, page_ctm);
            page_ctm = fz_concat(page_ctm, fz_translate(-tp.x, -tp.y));
            page_ctm = fz_concat(page_ctm, fz_rotate(-rotate));
            page_ctm = fz_concat(page_ctm, fz_translate(tp.x, tp.y));
        }

        ctm = fz_concat(page_ctm, ctm);

        struct_parent = pdf_dict_getl(ctx, page->obj, PDF_NAME(StructParent));
        struct_parent_num = pdf_to_int_default(ctx, struct_parent, -1);

        proc = pdf_new_run_processor(ctx, page->doc, dev, ctm, struct_parent_num, usage, NULL, default_cs, cookie);
        pdf_processor_push_resources(ctx, proc, pdf_page_resources(ctx, annot->page));
        resources_pushed = 1;
        pdf_process_annot(ctx, proc, annot, cookie);
        pdf_close_processor(ctx, proc);
    }
    fz_always(ctx)
    {
        if (resources_pushed)
            pdf_processor_pop_resources(ctx, proc);
        pdf_drop_processor(ctx, proc);
        fz_drop_default_colorspaces(ctx, default_cs);
        pdf_annot_pop_local_xref(ctx, annot);
    }
    fz_catch(ctx) {
        //fz_rethrow(ctx);
    }
    //fzz add begin 2004.09.18
    ((fzsvg_device *)dev)->isstamp = false;
    //fzz add end 2004.09.18
}
//-----------------------------------------------------------------------------------------------------------------


