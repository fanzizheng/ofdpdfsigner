//
//  Created by zizheng fan on 2023/03/06.
//
#include "basic/FZZConst.h"
#include "pdfsign/FZZPDFSigner.h"

#include "pdfsign/FZZPkcs7_GM.h"
#include "mupdf/fitz/display-list.h"
#include "mupdf/fitz/device.h"
#include "mupdf/pdf/annot.h"
#include "mupdf/pdf/page.h"
#include "mupdf/pdf/object.h"

#include "fzfont/FZZFontCache.h"
#include "converter/utils/FZZImageUtil.h"

#include "interface/FZZErrorCode.h"
#include "basic/FZZString.h"
/*11
 mac:

 #brew install openssl@1.1
 #cd mupdf
 
 update pdf/pdf-font-add.c file:
 update pdf_add_cjk_font function:
 => not update
 case FZ_ADOBE_GB:
         //fzz edit begin
         //basefont = serif ? "Song" : "Heiti";
         //encoding = wmode ? "UniGB-UTF16-V" : "UniGB-UTF16-H";
         //ordering = "GB1";
         //supplement = 5;
         
         basefont = serif ? "SimSun" : "SimHei";
       encoding = wmode ? "Adobe-GB1-UCS2" : "UniGB-UTF16-H";//"GBK-EUC-H";//wmode ? "Adobe-GB1-UCS2" : "UniGB-UTF16-H";
       ordering = "GB1";
       supplement = 5;//serif ? 4 : 1;
       
         //fzz edit ent

 update pdf/form.h file:
 =>
 //fzz add begin
 typedef void (*drawStampOverTextFunc)(fz_context *ctx,fz_page *page,fz_device *dev,fz_rect rect,fz_image *showgraphic);
 typedef void (*drawStampOverText_EndFunc)(fz_context *ctx,fz_page *page,fz_device *dev,fz_rect rect,fz_image *showgraphic);
 
 void pdf_sign_signature_ext(fz_context *ctx, pdf_annot *widget,
     pdf_pkcs7_signer *signer,
     int appearance_flags,
     fz_image *graphic,
     fz_image *showgraphic,
     const char *reason,
     const char *location,fz_page *page,drawStampOverTextFunc drawStampOverText,drawStampOverText_EndFunc drawStampOverText_End);
     
 fz_display_list *pdf_signature_appearance_signed_ext(fz_context *ctx, fz_rect rect, fz_text_language lang, fz_image *img, fz_image *showgraphic,const char *left_text, const char *right_text, int include_logo,fz_page *page,drawStampOverTextFunc drawStampOverText,drawStampOverText_EndFunc drawStampOverText_End);
 //fzz add end
 
 update pdf/pdf-signature.c file:
 =>
 //fzz add begin
 void pdf_sign_signature_ext(fz_context *ctx, pdf_annot *widget,
     pdf_pkcs7_signer *signer,
     int flags,
     fz_image *graphic,
     fz_image *showgraphic,
     const char *reason,
     const char *location,fz_page *page,drawStampOverTextFunc drawStampOverText,drawStampOverText_EndFunc drawStampOverText_End)
 {
     int logo = flags & PDF_SIGNATURE_SHOW_LOGO;
     fz_rect rect = pdf_annot_rect(ctx, widget);
     fz_text_language lang = pdf_annot_language(ctx, widget);
     int64_t now = time(NULL);
     char *name = NULL;
     char *info = NULL;
     fz_display_list *dlist = NULL;

     fz_var(dlist);
     fz_var(info);
     fz_var(name);

     
     fz_try(ctx)
     {
         if (!fz_is_empty_rect(rect))
         {
             info = pdf_format_signature_info(ctx, signer, flags, reason, location, now, &name);
             if (graphic)
                 dlist = pdf_signature_appearance_signed_ext(ctx, rect, lang, graphic,showgraphic, NULL, info, logo,page,drawStampOverText,drawStampOverText_End);
             else if (flags & PDF_SIGNATURE_SHOW_GRAPHIC_NAME)
                 dlist = pdf_signature_appearance_signed_ext(ctx, rect, lang, NULL,NULL, name, info, logo,page,drawStampOverText,drawStampOverText_End);
             else
                 dlist = pdf_signature_appearance_signed_ext(ctx, rect, lang, NULL, NULL,NULL, info, logo,page,drawStampOverText,drawStampOverText_End);
         }
        fz_rect mediabox;
         fz_matrix page_ctm;
         int is_horizontal = 0;
         pdf_page_transform(ctx, (pdf_page*)page, &mediabox, &page_ctm);
         if ( page_ctm.b != 0 || page_ctm.c != 0 ) {
             is_horizontal = 1;
         }
             pdf_sign_signature_with_appearance_ext(ctx, widget, signer, now, dlist,is_horizontal);
         }
     fz_always(ctx)
     {
         fz_free(ctx, info);
         fz_free(ctx, name);
         fz_drop_display_list(ctx, dlist);
     }
     fz_catch(ctx)
         fz_rethrow(ctx);
 }
 //fzz add end
 
 update pdf/pdf-appearance.c file:
 

 //fzz add begin
 fz_display_list *
 pdf_signature_appearance_signed_ext(fz_context *ctx, fz_rect rect, fz_text_language lang, fz_image *img, fz_image *showgraphic,const char *left_text, const char *right_text, int include_logo,fz_page *page,drawStampOverTextFunc drawStampOverText,drawStampOverText_EndFunc drawStampOverText_End)
 {
     fz_display_list *dlist = NULL;
     fz_device *dev = NULL;
     fz_text *text = NULL;
     fz_colorspace *cs = NULL;
     fz_path *path = NULL;
     fz_font *font = NULL;

     fz_var(path);
     fz_var(dlist);
     fz_var(dev);
     fz_var(text);
     fz_var(font);
     fz_try(ctx)
     {
         fz_rect prect;
         fz_rect logo_bounds;
         fz_matrix logo_tm;
         float color[] = { 0.0, 0.0, 0.0 };

         font = fz_new_base14_font(ctx, "Helvetica");

         dlist = fz_new_display_list(ctx, rect);
         dev = fz_new_list_device(ctx, dlist);
         cs = fz_device_rgb(ctx);

         if (include_logo)
         {
             path = fz_new_path(ctx);
             draw_logo(ctx, path);
             logo_bounds = fz_bound_path(ctx, path, NULL, fz_identity);
             logo_tm = center_rect_within_rect(logo_bounds, rect);
             fz_fill_path(ctx, dev, path, 0, logo_tm, cs, logo_color, 1.0f, fz_default_color_params);
         }

         prect = rect;
        
         if (right_text)
             prect.x1 = (prect.x0 + prect.x1) / 2.0f;

         if (img)
         {
             if ( drawStampOverText != NULL ) {
                 drawStampOverText(ctx,page,dev,rect,showgraphic);
             }
             fz_rect imgprect = rect;
             float img_aspect = (float) img->w / img->h;
             float rectw = imgprect.x1 - imgprect.x0;
             float recth = imgprect.y1 - imgprect.y0;
             float midx = (imgprect.x0+rectw/2.0);
             float midy = (imgprect.y0+recth/2.0);
             float rect_aspect = rectw / recth;
             float scale = img_aspect > rect_aspect ? rectw / img->w : recth / img->h;
             fz_matrix ctm = fz_pre_translate(fz_pre_scale(fz_translate(midx, midy), scale * img->w, scale * img->h), -0.5, -0.5);
             fz_fill_image(ctx, dev, img, ctm, 1.0, fz_default_color_params);
             if ( drawStampOverText_End != NULL ) {
                 drawStampOverText_End(ctx,page,dev,rect,showgraphic);
             }
             
         }

         if (left_text)
         {
             text = pdf_layout_fit_text(ctx, font, lang, left_text, prect);
             fz_fill_text(ctx, dev, text, fz_identity, cs, color, 1.0f, fz_default_color_params);
             fz_drop_text(ctx, text);
             text = NULL;
         }

         prect = rect;
         
         if (img || left_text)
             prect.x0 = (prect.x0 + prect.x1) / 2.0f;

         if (right_text)
         {
             text = pdf_layout_fit_text(ctx, font, lang, right_text, prect);
             fz_fill_text(ctx, dev, text, fz_identity, cs, color, 1.0f, fz_default_color_params);
         }
         
         
     }
     fz_always(ctx)
     {
         fz_drop_device(ctx, dev);
         fz_drop_path(ctx, path);
         fz_drop_text(ctx, text);
         fz_drop_font(ctx, font);
     }
     fz_catch(ctx)
     {
         fz_drop_display_list(ctx, dlist);
         fz_rethrow(ctx);
     }

     return dlist;
 }
 //fzz add end
 
 update pdf_update_appearance function:
 =>
 //fzz del begin
 //rect = pdf_annot_rect(ctx, annot);
 //dlist = pdf_signature_appearance_unsigned(ctx, rect, pdf_annot_language(ctx, annot));
 //fz_try(ctx)
 //    pdf_set_annot_appearance_from_display_list(ctx, annot, "N", NULL, fz_identity, dlist);
 //fz_always(ctx)
 //    fz_drop_display_list(ctx, dlist);
 //fz_catch(ctx)
 //    fz_rethrow(ctx);
 //fzz del end
 
 update pdf_signature_appearance_signed function:
 
 if (img)
         {
             float img_aspect = (float) img->w / img->h;
             float rectw = prect.x1 - prect.x0;
             float recth = prect.y1 - prect.y0;
             float midx = (prect.x0 + prect.x1) / 2.0;
             float midy = (prect.y0 + prect.y1) / 2.0;
             float rect_aspect = rectw / recth;
             float scale = img_aspect > rect_aspect ? rectw / img->w : recth / img->h;
             fz_matrix ctm = fz_pre_translate(fz_pre_scale(fz_translate(midx, midy), scale * img->w, scale * img->h), -0.5, -0.5);
             fz_fill_image(ctx, dev, img, ctm, 1.0, fz_default_color_params);
         }
 =>
 if (img)
         {
 //fzz edit begin
            fz_rect imgprect = rect;
             float img_aspect = (float) img->w / img->h;
             float rectw = imgprect.x1 - imgprect.x0;
             float recth = imgprect.y1 - imgprect.y0;
             float midx = (imgprect.x0+rectw/2.0);
             float midy = (imgprect.y0+recth/2.0);
             float rect_aspect = rectw / recth;
 //fzz edit end
            float scale = img_aspect > rect_aspect ? rectw / img->w : recth / img->h;
             fz_matrix ctm = fz_pre_translate(fz_pre_scale(fz_translate(midx, midy), scale * img->w, scale * img->h), -0.5, -0.5);
             fz_fill_image(ctx, dev, img, ctm, 1.0, fz_default_color_params);
         }
 
 add pdf_sign_signature_with_appearance_ext function:
 //fzz add begin
 void
 pdf_sign_signature_with_appearance_ext(fz_context *ctx, pdf_annot *widget, pdf_pkcs7_signer *signer, int64_t t, fz_display_list *disp_list,int is_horizontal)
 {
     pdf_document *doc = widget->page->doc;

     if (pdf_widget_is_readonly(ctx, widget))
         fz_throw(ctx, FZ_ERROR_GENERIC, "Signature is read only, it cannot be signed.");

     pdf_begin_operation(ctx, doc, "Sign signature");

     fz_try(ctx)
     {
         pdf_obj *wobj = ((pdf_annot *)widget)->obj;
         pdf_obj *form;
         int sf;

         pdf_dirty_annot(ctx, widget);
         enact_sig_locking(ctx, doc, wobj);

         //fzz edit begin
         //if (disp_list)
         //    pdf_set_annot_appearance_from_display_list(ctx, widget, "N", NULL, fz_identity, disp_list);
         if (disp_list) {
             fz_matrix ctm = fz_identity;
             if ( is_horizontal == 1 ) {
                 ctm = fz_rotate(90);
             }
             pdf_set_annot_appearance_from_display_list(ctx, widget, "N", NULL, ctm, disp_list);
         }
         //fzz edit end
         
         form = pdf_dict_getp(ctx, pdf_trailer(ctx, doc), "Root/AcroForm");
         if (!form)
         {
             pdf_obj *root = pdf_dict_get(ctx, pdf_trailer(ctx, doc), PDF_NAME(Root));
             form = pdf_dict_put_dict(ctx, root, PDF_NAME(AcroForm), 1);
         }

         sf = pdf_to_int(ctx, pdf_dict_get(ctx, form, PDF_NAME(SigFlags)));
         if ((sf & (PDF_SIGFLAGS_SIGSEXIST | PDF_SIGFLAGS_APPENDONLY)) != (PDF_SIGFLAGS_SIGSEXIST | PDF_SIGFLAGS_APPENDONLY))
             pdf_dict_put_drop(ctx, form, PDF_NAME(SigFlags), pdf_new_int(ctx, sf | PDF_SIGFLAGS_SIGSEXIST | PDF_SIGFLAGS_APPENDONLY));

         //fzz edit begin
         if ( signer != NULL ) {
             pdf_signature_set_value(ctx, doc, wobj, signer, t);
         }
         //fzz edit end
     }
     fz_always(ctx)
     {
         pdf_end_operation(ctx, doc);
     }
     fz_catch(ctx)
     {
         fz_rethrow(ctx);
     }
 }
 //fzz add begin
 
 update fitz/context.h file:
 
 static inline void
 fz_lock(fz_context *ctx, int lock)
 {
     //fzz del begin
     //fz_lock_debug_lock(ctx, lock);
     //fzz del end
     ctx->locks.lock(ctx->locks.user, lock);
 }
 static inline void
 fz_unlock(fz_context *ctx, int lock)
 {
     //fzz del begin
     //fz_lock_debug_unlock(ctx, lock);
     //fzz del end
     ctx->locks.unlock(ctx->locks.user, lock);
 }

 update Makerules file:
 
 else ifeq ($(OS),MACOS)
   HAVE_GLUT := yes
   SYS_GLUT_CFLAGS := -Wno-deprecated-declarations
   SYS_GLUT_LIBS := -framework GLUT -framework OpenGL
   CC = xcrun cc
   AR = xcrun ar
   LD = xcrun ld
   RANLIB = xcrun ranlib

   ifeq (, $(shell which pkg-config))
     $(warning "No pkg-config found, install it for proper integration of libcrypto")
   else
     HAVE_LIBCRYPTO := $(shell pkg-config --exists 'libcrypto >= 1.1.0' && echo yes)
     ifeq ($(HAVE_LIBCRYPTO),yes)
       LIBCRYPTO_CFLAGS := $(shell pkg-config --cflags libcrypto) -DHAVE_LIBCRYPTO
       LIBCRYPTO_LIBS := $(shell pkg-config --libs libcrypto)
     endif
   endif

 else ifeq ($(OS),Linux)
 
 =>
 
 else ifeq ($(OS),MACOS)
   HAVE_GLUT := yes
   SYS_GLUT_CFLAGS := -Wno-deprecated-declarations
   SYS_GLUT_LIBS := -framework GLUT -framework OpenGL
   CC = xcrun cc
   AR = xcrun ar
   LD = xcrun ld
   RANLIB = xcrun ranlib

  
    HAVE_LIBCRYPTO := yes
    LIBCRYPTO_CFLAGS := -I/usr/local/opt/openssl@1.1/include -DHAVE_LIBCRYPTO
    LIBCRYPTO_LIBS := -L/usr/local/opt/openssl@1.1/lib/ -lcrypto -lssl
     
   endif

 else ifeq ($(OS),Linux)
 
 export LDFLAGS="-L/usr/local/opt/openssl@1.1/lib"
 export CPPFLAGS="-I/usr/local/opt/openssl@1.1/include"
 #make HAVE_X11=no HAVE_GLUT=no HAVE_LIBCRYPTO=yes shared=no prefix=./build install
 #make HAVE_X11=no HAVE_GLUT=no HAVE_LIBCRYPTO=no shared=no prefix=./build install
 #openssl req -x509 -days 365 -newkey rsa:2048 -keyout cert.pem -out cert.pem
 #openssl pkcs12 -export -in cert.pem -out cert.pfx
 */

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
static void pdfStampimage_dev_close_device(fz_context *ctx, fz_device *dev)
{
    //last close
    pdfStampimage_device *pdev = (pdfStampimage_device*)dev;
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
static void pdfStampimage_dev_fill_image(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    if ( dev == NULL ) {
        return;
    }
    
    pdfStampimage_device *pdev = (pdfStampimage_device*)dev;
    
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
            pdev->stampImage = new FZZBytes(buf->data, buf->len);
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
                            maskImage.setData(buf_mask->data, buf_mask->len);
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
fz_device * new_pdfStampimage_device(fz_context *ctx)
{
    pdfStampimage_device *dev = fz_new_derived_device(ctx,pdfStampimage_device);
    if ( dev == NULL ) {
        return NULL;
    }
    
    dev->super.close_device = pdfStampimage_dev_close_device;
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
    dev->super.fill_image = pdfStampimage_dev_fill_image;
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
/*****************************************************FZZPDFSigner*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPDFSigner::FZZPDFSigner() : m_CTX(NULL),m_Doc(NULL),m_Stm(NULL),m_PDF(NULL),m_PassWord(""),m_CurrAddStampCount(0),m_CommandType(COMMAND_TYPE::TYPE_Verify)
{
    //DLOG("FZZPDFSigner()");
    FZZConst::addClassCount("FZZPDFSigner");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFSigner::FZZPDFSigner(FZZPDF * pdf): FZZPDFSigner()
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
        
        fz_install_load_system_font_funcs(m_CTX,PDFSigner_load_system_font,PDFSigner_load_system_cjk_font,PDFSigner_load_system_fallback_font);
    }
    fz_always(m_CTX)
    {

    }
    fz_catch(m_CTX)
    {

    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFSigner::~FZZPDFSigner()
{
    //DLOG("~FZZPDFSigner()");
    FZZConst::delClassCount("FZZPDFSigner");
    
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
    
    m_PDF = NULL;
    
    vector<FZZBytes*>::const_iterator stampimageiter;
    for (stampimageiter = m_SignInfo_StampImages.begin(); stampimageiter != m_SignInfo_StampImages.end(); stampimageiter++) {
        if ( *stampimageiter != NULL ) {
            delete *stampimageiter;
        }
    }
    m_SignInfo_StampImages.clear();
    
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDFSigner::isNeedPassWord()
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
bool FZZPDFSigner::VerifyPassWord(string pwd)
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
int FZZPDFSigner::pageSize()
{
    int page_count = 0;
    if ( m_Doc != NULL ) {
        page_count = pdf_count_pages(m_CTX,m_Doc);
    }
    return page_count;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::list_signature(fz_context *ctx, pdf_document *doc, pdf_obj *signature)
{
    pdf_pkcs7_distinguished_name *dn;
    pdf_pkcs7_verifier *verifier;

    if (!pdf_signature_is_signed(ctx, doc, signature))
    {
        //printf("%5d: Signature is not signed.\n", pdf_to_num(ctx, signature));
        return;
    }

    verifier = pkcs7_gm_create_verifier(ctx,NULL,NULL);

    dn = pdf_signature_get_signatory(ctx, verifier, doc, signature);
    if (dn)
    {
        char *s = pdf_signature_format_distinguished_name(ctx, dn);
        DLOG("%5d: Distinguished name: %s\n", pdf_to_num(ctx, signature), s);
        fz_free(ctx, s);
        pdf_signature_drop_distinguished_name(ctx, dn);
    }
    

    pdf_drop_verifier(ctx, verifier);

}
//-----------------------------------------------------------------------------------------------------------------
fz_display_list *
FZZPDFSigner::SignatureAppearanceUnsigned(fz_context *ctx, fz_rect rect, fz_text_language lang)
{
    fz_display_list *dlist = NULL;
    //fz_device *dev = NULL;
    

    
    fz_var(dlist);
    //fz_var(dev);
    
//    fz_try(ctx)
//    {
        

        dlist = fz_new_display_list(ctx, rect);
        //dev = fz_new_list_device(ctx, dlist);

        
//    }
//    fz_always(ctx)
//    {
//       // fz_drop_device(ctx, dev);
//
//    }
//    fz_catch(ctx)
//    {
//        fz_drop_display_list(ctx, dlist);
//        dlist = NULL;
//    }

    return dlist;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::ClearSignature(fz_context *ctx, pdf_annot *widget)
{
    int flags;
    fz_display_list *dlist = NULL;

    fz_var(dlist);
    fz_try(ctx)
    {
        fz_text_language lang = pdf_annot_language(ctx, (pdf_annot *)widget);
        fz_rect rect = pdf_annot_rect(ctx, widget);
        

        pdf_begin_operation(ctx, widget->page->doc, "Clear Signature");
        //if (pdf_widget_is_readonly(ctx, widget))
        //    fz_throw(ctx, FZ_ERROR_ARGUMENT, "Signature read only, it cannot be cleared.");

        pdf_xref_remove_unsaved_signature(ctx, ((pdf_annot *)widget)->page->doc, ((pdf_annot *)widget)->obj);

        pdf_dirty_annot(ctx, widget);

        flags = pdf_dict_get_int(ctx, ((pdf_annot *)widget)->obj, PDF_NAME(F));
        flags &= ~PDF_ANNOT_IS_LOCKED;
        if (flags)
            pdf_dict_put_int(ctx, ((pdf_annot *)widget)->obj, PDF_NAME(F), flags);
        else
            pdf_dict_del(ctx, ((pdf_annot *)widget)->obj, PDF_NAME(F));
        //pdf_dict_del(ctx, ((pdf_annot *)widget)->obj, PDF_NAME(F));

        pdf_dict_del(ctx, ((pdf_annot *)widget)->obj, PDF_NAME(V));

        //fzz del begin 2024.11.1
        dlist = SignatureAppearanceUnsigned(ctx, rect, lang);
        if ( dlist != NULL ) {
            pdf_set_annot_appearance_from_display_list(ctx, widget, "N", NULL, fz_identity, dlist);
        }
        
        
        //fzz del end 2024.11.1
        pdf_end_operation(ctx, widget->page->doc);
    }
    fz_always(ctx)
        fz_drop_display_list(ctx, dlist);
    fz_catch(ctx)
    {
        pdf_abandon_operation(ctx, widget->page->doc);
        fz_rethrow(ctx);
    }
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::clear_signature(fz_context *ctx, pdf_document *doc, pdf_obj *signature)
{
    int ret = 0;
    pdf_page *page = NULL;
    pdf_annot *widget;
    pdf_obj *parent;
    int pageno, pagenoend;

    fz_var(page);

    //printf("Clearing signature %d.\n", pdf_to_num(ctx, signature));

    fz_try(ctx)
    {
        parent = pdf_dict_get(ctx, signature, PDF_NAME(P));
        if (parent != NULL)
        {
            pageno = pdf_lookup_page_number(ctx, doc, parent);
            pagenoend = pageno+1;
        }
        else
        {
            pageno = 0;
            pagenoend = pdf_count_pages(ctx, doc);
        }
        for (; pageno < pagenoend; pageno++)
        {
            page = pdf_load_page(ctx, doc, pageno);
            for (widget = pdf_first_widget(ctx, page); widget; widget = pdf_next_widget(ctx, widget))
                if (pdf_widget_type(ctx, widget) == PDF_WIDGET_TYPE_SIGNATURE && !pdf_objcmp_resolve(ctx, pdf_annot_obj(ctx, widget), signature)) {
//                    if (pdf_widget_is_readonly(ctx, widget)) {
//                        DLOG("Signature read only, it cannot be cleared.");
//                    } else {
//                        pdf_clear_signature(ctx, widget);
//                    }
//                    pdf_clear_signature(ctx, widget);
                    ClearSignature(ctx, widget);
                }
            pdf_drop_page(ctx, page);
            page = NULL;
        }
    }
    fz_always(ctx)
    pdf_drop_page(ctx, page);
    fz_catch(ctx) {
        //fz_rethrow(ctx);
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::verify_signature(fz_context *ctx, pdf_document *doc, pdf_obj *signature,CallBack_Verify verifyFunc,const void * callBack_Param,string & signerdn,string & signtime)
{
    //char *name;
    pdf_signature_error err;
    pdf_pkcs7_verifier *verifier;
    int edits;
    pdf_pkcs7_distinguished_name *dn = NULL;

    

    if (!pdf_signature_is_signed(ctx, doc, signature))
    {
        //RidingStamp
        return 0;
    }
    
    //printf("Verifying signature %d:\n", pdf_to_num(ctx, signature));

    int ret = 0;
    verifier = pkcs7_gm_create_verifier(ctx,verifyFunc,callBack_Param);
    fz_var(dn);
    fz_try(ctx)
    {
        dn = pdf_signature_get_signatory(ctx, verifier, doc, signature);
        if (dn)
        {
            //name = pdf_signature_format_distinguished_name(ctx, dn);
            //signerdn = name;
            //signerdn = ((GM_VERIFIER*)verifier)->cert_dn;
            //DLOG("Distinguished name: %s", name);
            //fz_free(ctx, name);
        }
        else
        {
            signerdn = "";
            //printf("\tSignature information missing.\n");
        }

        err = pdf_check_certificate(ctx, verifier, doc, signature);
        if (err) {

            DLOG("Certificate error: %s", pdf_signature_error_description(err));
        }
        signerdn = ((GM_VERIFIER*)verifier)->cert_dn;
        

        err = pdf_check_digest(ctx, verifier, doc, signature);
        edits = pdf_signature_incremental_change_since_signing(ctx, doc, signature);
        if (err) {
            ret = -4;
            DLOG("Digest error: %s", pdf_signature_error_description(err));
        } else if (edits) {

            DLOG("The signature is valid but there have been edits since signing.");
        }
        signtime = FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(((GM_VERIFIER*)verifier)->signtime);
        
    }
    fz_always(ctx)
    {
        pdf_signature_drop_distinguished_name(ctx, dn);
        pdf_drop_verifier(ctx, verifier);
    }
    fz_catch(ctx) {
        ret = -3;
        DLOG("Verification error: %s", fz_caught_message(ctx));
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::process_field(fz_context *ctx, pdf_document *doc, pdf_obj *field,CallBack_Verify verifyFunc,const void * callBack_Param,string & signerdn,string & signtime)
{
    int ret = 0;
    //int objid = 0;
    //string tempstrid = "";
    int objid = pdf_to_num(ctx, field);
    if (pdf_dict_get_inheritable(ctx, field, PDF_NAME(FT)) == PDF_NAME(Sig)) {
        switch(m_CommandType) {
            case COMMAND_TYPE::TYPE_List:
                list_signature(ctx, doc, field);
                break;
            case COMMAND_TYPE::TYPE_Clear:
                //ret = clear_signature(ctx, doc, field);
                
                pdf_delete_object(ctx, doc, objid);
                break;
            case COMMAND_TYPE::TYPE_Verify: {
                //objid = pdf_to_num(ctx, field);
                //tempstrid = FZZConst::fmt(objid);
                //if ( tempstrid == sid ) {
                    ret = verify_signature(ctx, doc, field, verifyFunc,callBack_Param,signerdn,signtime);
                //}
                break;
            }
        }
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::process_field_hierarchy(fz_context *ctx, pdf_document *doc, pdf_obj *field,CallBack_Verify verifyFunc,const void * callBack_Param,const string &sid,bool & outIsContinue,string & signerdn,string & signtime)
{
    int ret = -2;
    pdf_obj *kids = pdf_dict_get(ctx, field, PDF_NAME(Kids));
    if (kids)
    {
        int i, n;
        n = pdf_array_len(ctx, kids);
        for (i = 0; i < n; ++i)
        {
            pdf_obj *kid = pdf_array_get(ctx, kids, i);
            
            ret = process_field_hierarchy(ctx, doc, kid, verifyFunc,callBack_Param,sid,outIsContinue,signerdn,signtime);
            if ( sid.empty() )  {
                if ( ret != 0 ) {
                    break;
                }
            } else {
                if ( outIsContinue == false ) {
                    break;
                }
            }
            
        }
    }
    else if (pdf_dict_get_inheritable(ctx, field, PDF_NAME(FT)) == PDF_NAME(Sig)) {
        if ( sid.empty() )  {
            ret = process_field(ctx, doc, field, verifyFunc,callBack_Param,signerdn,signtime);
            outIsContinue = true;
        } else {
            int objid = pdf_to_num(ctx, field);
            string tempstrid = FZZConst::fmt(objid);
            if ( tempstrid == sid ) {
                ret = process_field(ctx, doc, field, verifyFunc, callBack_Param,signerdn,signtime);
                outIsContinue = false;
            } else {
                outIsContinue = true;
            }
        }
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::process_acro_form(CallBack_Verify verifyFunc,const void * callBack_Param,const string &sid,string & signerdn,string & signtime)
{
    int ret = 0;
    pdf_obj *trailer = NULL;
    pdf_obj *root = NULL;
    pdf_obj *acroform = NULL;
    pdf_obj *fields = NULL;
    pdf_obj *tempfield = NULL;
    int fieldcount = 0;
    int i = 0;
    
    trailer = pdf_trailer(m_CTX, m_Doc);
    if ( trailer == NULL ) {
        ret = -1;
        goto err;
    }
    root = pdf_dict_get(m_CTX, trailer, PDF_NAME(Root));
    if ( root == NULL ) {
        ret = -1;
        goto err;
    }
    acroform = pdf_dict_get(m_CTX, root, PDF_NAME(AcroForm));
    if ( acroform == NULL ) {
        ret = -1;
        goto err;
    }
    fields = pdf_dict_get(m_CTX, acroform, PDF_NAME(Fields));
    if ( fields == NULL ) {
        ret = -1;
        goto err;
    }
    fieldcount = pdf_array_len(m_CTX, fields);
   
    bool isContinue;
  
    for (i = 0; i < fieldcount; ++i) {
        tempfield = pdf_array_get(m_CTX, fields, i);
        if ( tempfield == NULL ) {
            continue;
        }
        ret= process_field_hierarchy(m_CTX, m_Doc,tempfield,verifyFunc, callBack_Param,sid,isContinue,signerdn,signtime);
        if ( sid.empty() ) {
            if ( ret != 0 ) {
                break;
            }
        } else {
   
            if ( isContinue == false ) {
                break;
            }
 
        }
    }
    
err:
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::getSignatureInfos()
{
    m_CommandType = COMMAND_TYPE::TYPE_List;
    string outmsg = "";
    string sid = "";
    string signerdn = "";
    string signtime = "";
    process_acro_form(NULL,NULL,sid,signerdn,signtime);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::Clear_Signs()
{
    m_CommandType = COMMAND_TYPE::TYPE_Clear;
    string outmsg = "";
    string sid = "";
    string signerdn = "";
    string signtime = "";
    return process_acro_form(NULL,NULL,sid,signerdn,signtime);
}
//-----------------------------------------------------------------------------------------------------------------
//1: NULL sign
//0: ok
//-1: pdf file error;
//-2: not't sign obj
//-3: verify => false;
//-4: hash error;

int FZZPDFSigner::Verify(CallBack_Verify verifyFunc,const void * callBack_Param)
{
    m_CommandType = COMMAND_TYPE::TYPE_Verify;
    string outmsg = "";
    string sid = "";
    string signerdn = "";
    string signtime = "";
    return process_acro_form(verifyFunc,callBack_Param,sid,signerdn,signtime);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFSigner::Verify(string sid,CallBack_Verify verifyFunc,const void * callBack_Param,string & signerdn,string & signtime)
{
    m_CommandType = COMMAND_TYPE::TYPE_Verify;
    return process_acro_form(verifyFunc,callBack_Param,sid,signerdn,signtime);
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZPDFSigner::generatePDF()
{
    
    FZZBytes ret;
    if ( m_PDF == NULL ) {
        return ret;
    }
    //pdf_write_options opts = pdf_default_write_options;
    pdf_write_options opts = {
    0, /* do_incremental */
    0, /* do_pretty */
    0, /* do_ascii */
    0, /* do_compress */
    0, /* do_compress_images */
    0, /* do_compress_fonts */
    0, /* do_decompress */
    0, /* do_garbage */
    0, /* do_linear */
    0, /* do_clean */
    0, /* do_sanitize */
    0, /* do_appearance */
    0, /* do_encrypt */
    0, /* dont_regenerate_id */
    ~0, /* permissions */
    "", /* opwd_utf8[128] */
    "", /* upwd_utf8[128] */
    0 /* do_snapshot */
    };
    
    opts.do_incremental = 1;
    opts.do_compress = 1;
    opts.do_compress_images = 1;
    opts.do_compress_fonts = 1;
    //fzz crypt begin
    opts.do_encrypt = PDF_ENCRYPT_KEEP;
    //fzz crypt end
    
    //opts.do_appearance = 1;
 
    string fileuuid = FZZConst::createuuid();
    string filename = FZZConst::getTempPath() + "/" + fileuuid + ".pdf";
    
    //DLOG("sign file: %s",filename.c_str());

    
    //DLOG("writefile begin-----------");
    FZZBytes * srcData = m_PDF->getSourceData();
    if ( srcData != NULL ) {
        FZZConst::writefile(filename, srcData->getData(), srcData->getLen());
    }
    //DLOG("writefile end-----------");
    //DLOG("savefile begin-----------");
    fz_try(m_CTX)
    {

    
#ifdef _MSC_VER 

    string utf8_filename = FZZConst::GB2312toUtf8(filename);
    pdf_save_document(m_CTX, m_Doc, utf8_filename.c_str(), &opts);
#else
    pdf_save_document(m_CTX, m_Doc, filename.c_str(), &opts);
#endif
    //DLOG("savefile end-----------");
    //DLOG("read file end-----------");
    FZZConst::readfile(filename, ret);
    //DLOG("read file end-----------");
    
    //Not Supported pdf_write_document function
  
//    fz_buffer * buf = fz_new_buffer(m_CTX, 0);
//
//    if ( buf != NULL ) {
//        fz_output * output = fz_new_output_with_buffer(m_CTX, buf);
//        if ( output != NULL ) {
//
//            pdf_write_document(m_CTX, m_Doc, output, &opts);
//
//            ret.setData(buf->data, buf->len);
//
//            fz_close_output(m_CTX, output);
//            fz_drop_output(m_CTX, output);
//        }
//        fz_drop_buffer(m_CTX, buf);
//    }
    }
    fz_always(m_CTX)
    {
        
    }
    fz_catch(m_CTX)
    {
        DLOG("Sign PDF err:%s", fz_caught_message(m_CTX));
    }
    
    FZZConst::deleteFile(filename);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
//0 : ok
//-1: password error.
//-2 : load page error;
//-3 : create sign xef obj error;
//-4: create signer obj error;
//-5: unsaved_sigs error;
//-7 : max stamp number is 16;
int FZZPDFSigner::SignData(int pageIndex,float x,float y,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam)
{
    int ret = 0;
    pdf_page * pdfpage = NULL;
    pdf_annot *widget = NULL;
    char name[80];
    pdf_pkcs7_signer *signer = NULL;
    fz_rect annot_rect;
    fz_try(m_CTX)
    {
    m_CurrAddStampCount++;
    if ( m_CurrAddStampCount > PDF_MAX_STAMP_COUNT ) {
        ret = -7;
        goto err;
    }
    
    if ( m_CTX == NULL || m_Doc == NULL ) {
        ret = -2;
        goto err;
    }
    
//    if (pdf_needs_password(m_CTX, m_Doc)) {
//        if (!pdf_authenticate_password(m_CTX, m_Doc, m_PassWord.c_str())) {
//            ret = -1;
//            goto err;
//        }
//    }
    
    if ( pageIndex >= pageSize()  ) {
        ret = -2;
        goto err;
    }
    
    pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
    if ( pdfpage == NULL ) {
        ret = -2;
        goto err;
    }
    
    pdf_create_field_name(m_CTX, pdfpage->doc, "Signature", name, sizeof name);
    widget = pdf_create_signature_widget(m_CTX, pdfpage, name);
    if ( widget == NULL ) {
        ret = -3;
        goto err;
    }
    
    annot_rect.x0 = x;
    annot_rect.y0 = y;
    annot_rect.x1 = x+stampWidth;
    annot_rect.y1 = y+stampHeight;
    pdf_set_annot_rect(m_CTX, widget, annot_rect);
    
    signer = pkcs7_gm_create_signer(m_CTX, isCallBack,x509, prikey,signFunc,cbParam,NULL);
    if ( signer == NULL ) {
        ret = -4;
        goto err;
    }
    
    pdf_sign_signature(m_CTX, widget, signer,
                       PDF_SIGNATURE_APPEARANCE_DATA,
                            NULL,
                       NULL,
                       NULL);
    
    }
    fz_always(m_CTX)
    {
        
    }
    fz_catch(m_CTX)
    {

    }
 
err:
    if ( signer != NULL ) {
        pdf_drop_signer(m_CTX, signer);
        signer = NULL;
    }
    
    if ( widget != NULL ) {
        pdf_drop_widget(m_CTX,widget);
        widget = NULL;
    }
    
    if ( pdfpage != NULL ) {
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
    
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::ClearAlpha(const FZZBytes & imageData,FZZBytes & outData)
{

    FZZImageUtil imageUtil;
    if ( !imageUtil.LoadImage(imageData) ) {
        return;
    }
    imageUtil.setAlpha(255);
    outData = imageUtil.PngEncode();

}
//-----------------------------------------------------------------------------------------------------------------
//0 : ok
//-1: password error.
//-2 : load page error;
//-3 : create sign xef obj error;
//-4: create signer obj error;
//-5: unsaved_sigs error;
//-6: load image error;
//-7 : max stamp number is 16;

int FZZPDFSigner::SignStamp(int pageIndex,FZZBytes &srcstampimage,double alpha,float x,float y,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam)
{
    int ret = 0;
    pdf_page * pdfpage = NULL;
    pdf_annot *widget = NULL;
    char name[80];
    pdf_pkcs7_signer *signer = NULL;
    fz_image * image = NULL;
    fz_buffer *buffer = NULL;
    fz_image * showimage = NULL;
    fz_buffer * showbuffer = NULL;
    fz_rect annot_rect;
    FZZBytes tempstampimage;
    
    if ( m_CTX == NULL && pageIndex < 0) {
        ret = -2;
        goto err;
    }
fz_try(m_CTX)
{
    //DLOG("SignStamp..............begin");
    m_CurrAddStampCount++;
    if ( m_CurrAddStampCount > PDF_MAX_STAMP_COUNT ) {
        ret = -7;
        goto err;
    }
    
    if ( m_CTX == NULL || m_Doc == NULL ) {
        ret = -2;
        goto err;
    }
    
    
    //DLOG("SignStamp..............1");
//    if (pdf_needs_password(m_CTX, m_Doc)) {
//        if (!pdf_authenticate_password(m_CTX, m_Doc, m_PassWord.c_str())) {
//            ret = -1;
//            goto err;
//        }
//    }
    if ( pageIndex > 0 ) {
        pageIndex--;
    }
    
    if ( pageIndex >= pageSize()  ) {
        ret = -2;
        goto err;
    }
    //DLOG("SignStamp..............2");
    pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
    if ( pdfpage == NULL ) {
        ret = -2;
        goto err;
    }
    
    pdf_create_field_name(m_CTX, pdfpage->doc, "Signature", name, sizeof name);
    widget = pdf_create_signature_widget(m_CTX, pdfpage, name);
    if ( widget == NULL ) {
        ret = -3;
        goto err;
    }
    //DLOG("SignStamp..............3");
    annot_rect.x0 = x;
    annot_rect.y0 = y;
    annot_rect.x1 = x+stampWidth;
    annot_rect.y1 = y+stampHeight;
    pdf_set_annot_rect(m_CTX, widget, annot_rect);
    
    signer = pkcs7_gm_create_signer(m_CTX, isCallBack,x509, prikey,signFunc,cbParam,NULL);
    if ( signer == NULL ) {
        ret = -4;
        goto err;
    }
    //DLOG("SignStamp..............4");
    if ( srcstampimage.getLen() > 0 ) {
        //DLOG("SignStamp..............4.....1");
#ifdef PDF_STAMP_USE_CLIPS
        buffer = fz_new_buffer_from_copied_data(m_CTX, srcstampimage.getData(), srcstampimage.getLen());
        if ( buffer == NULL ) {
            ret = -6;
            goto err;
        }
        
        image = fz_new_image_from_buffer(m_CTX, buffer);
        if ( image == NULL ) {
            ret = -6;
            goto err;
        }
#else
        //DLOG("SignStamp..............4.....2");
        ClearAlpha(srcstampimage,tempstampimage);
        if ( tempstampimage.getLen() <= 0 ) {
            ret = -6;
            goto err;
        }

        //DLOG("SignStamp..............4.....3");
        buffer = fz_new_buffer_from_copied_data(m_CTX, tempstampimage.getData(), tempstampimage.getLen());
        if ( buffer == NULL ) {
            ret = -6;
            goto err;
        }
        //DLOG("SignStamp..............4.....4");
        image = fz_new_image_from_buffer(m_CTX, buffer);
        if ( image == NULL ) {
            ret = -6;
            goto err;
        }
        //DLOG("SignStamp..............4.....5");
        showbuffer = fz_new_buffer_from_copied_data(m_CTX, srcstampimage.getData(), srcstampimage.getLen());
        if ( showbuffer == NULL ) {
            ret = -6;
            goto err;
        }
        //DLOG("SignStamp..............4.....6");
        showimage = fz_new_image_from_buffer(m_CTX, showbuffer);
        if ( showimage == NULL ) {
            ret = -6;
            goto err;
        }
        
#endif
        //DLOG("SignStamp..............4.....7");
        pdf_sign_signature_ext(m_CTX, widget, signer,
                           PDF_SIGNATURE_APPEARANCE_STAMP,
                                image,
                               alpha,
                               showimage,
                           NULL,
                           NULL,(fz_page*)pdfpage,drawStampOverText,drawStampOverText_End);
    } else {
    
        //DLOG("SignStamp..............4.....30");
        pdf_sign_signature(m_CTX, widget, signer,
                           PDF_SIGNATURE_APPEARANCE_DATA,
                                NULL,
                           NULL,
                           NULL);
    }
    //DLOG("SignStamp..............5");
}
fz_always(m_CTX)
{
    
}
fz_catch(m_CTX)
{

}
err:
    if ( buffer != NULL ) {
        fz_drop_buffer(m_CTX, buffer);
        buffer = NULL;
    }
    if ( image != NULL ) {
        fz_drop_image(m_CTX, image);
        image = NULL;
    }
    
    if ( showbuffer != NULL ) {
        fz_drop_buffer(m_CTX, showbuffer);
        showbuffer = NULL;
    }
    if ( showimage != NULL ) {
        fz_drop_image(m_CTX, showimage);
        showimage = NULL;
    }
    
    if ( signer != NULL ) {
        pdf_drop_signer(m_CTX, signer);
        signer = NULL;
    }
    
    if ( widget != NULL ) {
        pdf_drop_widget(m_CTX,widget);
        widget = NULL;
    }
    
    if ( pdfpage != NULL ) {
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
    
    //DLOG("SignStamp..............end");
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
//0 : ok
//-1: password error.
//-2 : load page error;
//-3 : create sign xef obj error;
//-4: create signer obj error;
//-5: unsaved_sigs error;
//-6: load image error;
//-7 : max stamp number is 16;
//-8 : page cout < 2;
int FZZPDFSigner::SignRidingStamp(FZZPDFSigner::TYPE type,FZZBytes &stampimage,double alpha,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam)
{
    int ret = 0;
    pdf_page * pdfpage = NULL;
    pdf_annot *widget = NULL;
    char name[80];
    pdf_pkcs7_signer *signer = NULL;
    fz_image * image = NULL;
    fz_buffer *buffer = NULL;
    fz_image * showimage = NULL;
    fz_buffer * showbuffer = NULL;
    fz_rect annot_rect;
    int totalpages = 0;
    vector<FZZBytes *> outImages;
    vector<FZZBytes*>::const_iterator iter;
    fz_matrix page_ctm;
    fz_rect mediabox;
    fz_rect ofdPageMediabox;
    float pageWidth = 0;
    float pageHeight = 0;
    float stampWidth_temp = 0;
    float stampHeight_temp = 0;
    int i = 0;
    FZZBytes * itemImageData = 0;

    FZZImageUtil imageUtil;

    FZZBytes tempstampimage;
fz_try(m_CTX)
{

    m_CurrAddStampCount++;
    if ( m_CurrAddStampCount > PDF_MAX_STAMP_COUNT ) {
        ret = -7;
        goto err;
    }
    
    if ( m_CTX == NULL || m_Doc == NULL ) {
        ret = -2;
        goto err;
    }
    
//    if (pdf_needs_password(m_CTX, m_Doc)) {
//        if (!pdf_authenticate_password(m_CTX, m_Doc, m_PassWord.c_str())) {
//            ret = -1;
//            goto err;
//        }
//    }
    
    totalpages = pageSize();
    
    if ( totalpages < 2 ) {
        ret = -8;
        goto err;
    }
    
    if ( type == FZZPDFSigner::TYPE::TYPE_Right || type == FZZPDFSigner::TYPE::TYPE_Left ) {
        stampWidth_temp = stampWidth/totalpages+1;
        stampHeight_temp = stampHeight;
        imageUtil.SplitImage(stampimage,"PNG",totalpages,true,outImages,NULL,NULL);
    }   else {
        stampWidth_temp = stampWidth;
        stampHeight_temp = stampHeight/totalpages+1;
        imageUtil.SplitImage(stampimage,"PNG",totalpages,false,outImages,NULL,NULL);
    }
    
    signer = pkcs7_gm_create_signer(m_CTX, isCallBack,x509, prikey,signFunc,cbParam,&stampimage);
    if ( signer == NULL ) {
        ret = -4;
        goto err;
    }
 
    for (i = 0; i < totalpages; i++) {
        pdfpage = pdf_load_page(m_CTX, m_Doc, i);
        if ( pdfpage == NULL ) {
            ret = -2;
            goto err;
        }
        
        pdf_page_transform(m_CTX, pdfpage, &mediabox, &page_ctm);
        
        if ( page_ctm.b != 0 || page_ctm.c != 0 ) {
            ofdPageMediabox.x0 = mediabox.x0;
            ofdPageMediabox.y0 = mediabox.y0;
            ofdPageMediabox.x1 = mediabox.y1;
            ofdPageMediabox.y1 = mediabox.x1;
        } else {
            ofdPageMediabox.x0 = mediabox.x0;
            ofdPageMediabox.y0 = mediabox.y0;
            ofdPageMediabox.x1 = mediabox.x1;
            ofdPageMediabox.y1 = mediabox.y1;
        }
        
        pageWidth = ofdPageMediabox.x1 - ofdPageMediabox.x0;
        pageHeight = ofdPageMediabox.y1 - ofdPageMediabox.y0;
        
        pdf_create_field_name(m_CTX, pdfpage->doc, "Signature", name, sizeof name);
        widget = pdf_create_signature_widget(m_CTX, pdfpage, name);
        if ( widget == NULL ) {
            ret = -3;
            goto err;
        }
        
        switch (type) {
            case FZZPDFSigner::TYPE::TYPE_Right:
                
                annot_rect.x0 = pageWidth-stampWidth_temp;
                annot_rect.y0 = (pageHeight - stampHeight_temp)/2;
                annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                itemImageData = outImages[i];
                break;
            case FZZPDFSigner::TYPE::TYPE_Left:
                
                annot_rect.x0 = 0;
                annot_rect.y0 = (pageHeight - stampHeight_temp)/2;
                annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                itemImageData = outImages[totalpages-i-1];
                break;
            case FZZPDFSigner::TYPE::TYPE_Top:
                annot_rect.x0 = (pageWidth-stampWidth_temp)/2;
                annot_rect.y0 = 0;
                annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                itemImageData = outImages[totalpages-i-1];
                break;
            case FZZPDFSigner::TYPE::TYPE_Bottom:
                annot_rect.x0 = (pageWidth-stampWidth_temp)/2;
                annot_rect.y0 = pageHeight - stampHeight_temp;
                annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                itemImageData = outImages[i];
                break;
            default:
                break;
        }
        
        pdf_set_annot_rect(m_CTX, widget, annot_rect);
        
        if ( itemImageData->getLen() > 0 ) {
            
#ifdef PDF_STAMP_USE_CLIPS
            buffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
            if ( buffer == NULL ) {
                ret = -6;
                goto err;
            }
            
            image = fz_new_image_from_buffer(m_CTX, buffer);
            if ( image == NULL ) {
                ret = -6;
                goto err;
            }
#else
            ClearAlpha(*itemImageData,tempstampimage);
            if ( tempstampimage.getLen() <= 0 ) {
                ret = -6;
                goto err;
            }
            
            buffer = fz_new_buffer_from_copied_data(m_CTX, tempstampimage.getData(), tempstampimage.getLen());
            if ( buffer == NULL ) {
                ret = -6;
                goto err;
            }
            
            image = fz_new_image_from_buffer(m_CTX, buffer);
            if ( image == NULL ) {
                ret = -6;
                goto err;
            }
            
            showbuffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
            if ( showbuffer == NULL ) {
                ret = -6;
                goto err;
            }
            
            showimage = fz_new_image_from_buffer(m_CTX, showbuffer);
            if ( showimage == NULL ) {
                ret = -6;
                goto err;
            }
#endif
            if ( i == 0 ) {

                pdf_sign_signature_ext(m_CTX, widget, signer,
                                           PDF_SIGNATURE_APPEARANCE_STAMP,
                                                image,
                                       alpha,
                                       showimage,
                                           NULL,
                                           NULL,(fz_page*)pdfpage,drawStampOverText,drawStampOverText_End);
            } else {
                pdf_sign_signature_ext(m_CTX, widget, NULL,
                                           PDF_SIGNATURE_APPEARANCE_STAMP,
                                                image,
                                       alpha,
                                       showimage,
                                           NULL,
                                           NULL,(fz_page*)pdfpage,drawStampOverText,drawStampOverText_End);
            }
            
        } else {
            ret = -6;
            goto err;
        }
        
        if ( buffer != NULL ) {
            fz_drop_buffer(m_CTX, buffer);
            buffer = NULL;
        }
        if ( image != NULL ) {
            fz_drop_image(m_CTX, image);
            image = NULL;
        }
        
        if ( showbuffer != NULL ) {
            fz_drop_buffer(m_CTX, showbuffer);
            showbuffer = NULL;
        }
        if ( showimage != NULL ) {
            fz_drop_image(m_CTX, showimage);
            showimage = NULL;
        }
        
        if ( widget != NULL ) {
            pdf_drop_widget(m_CTX,widget);
            widget = NULL;
        }
        if ( pdfpage != NULL ) {
            pdf_drop_page(m_CTX, pdfpage);
            pdfpage = NULL;
        }
    } // for
}
fz_always(m_CTX)
{
    
}
fz_catch(m_CTX)
{

}
err:
    if ( buffer != NULL ) {
        fz_drop_buffer(m_CTX, buffer);
        buffer = NULL;
    }
    if ( image != NULL ) {
        fz_drop_image(m_CTX, image);
        image = NULL;
    }
    
    if ( showbuffer != NULL ) {
        fz_drop_buffer(m_CTX, showbuffer);
        showbuffer = NULL;
    }
    if ( showimage != NULL ) {
        fz_drop_image(m_CTX, showimage);
        showimage = NULL;
    }
    
    if ( signer != NULL ) {
        pdf_drop_signer(m_CTX, signer);
        signer = NULL;
    }
    
    if ( widget != NULL ) {
        pdf_drop_widget(m_CTX,widget);
        widget = NULL;
    }
    
    if ( pdfpage != NULL ) {
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
    
    for (iter = outImages.begin(); iter != outImages.end(); iter++) {
        if ( *iter != NULL ) {
            delete *iter;
        }
    }
    outImages.clear();
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
//0 : ok
//-1: password error.
//-2 : load page error;
//-3 : create sign xef obj error;
//-4: create signer obj error;
//-5: unsaved_sigs error;
//-6: load image error;
//-7 : max stamp number is 16;
//-8 : page cout < 2;
int FZZPDFSigner::SignCuttingRidingStamp(FZZPDFSigner::TYPE type,FZZBytes &stampimage,double alpha,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam)
{
    int ret = 0;
    pdf_page * pdfpage = NULL;
    pdf_annot *widget = NULL;
    char name[80];
    pdf_pkcs7_signer *signer = NULL;
    fz_image * image = NULL;
    fz_buffer *buffer = NULL;
    fz_image * showimage = NULL;
    fz_buffer * showbuffer = NULL;
    fz_rect annot_rect;
    int totalpages = 0;
    vector<FZZBytes *> outImages;
    vector<FZZBytes*>::const_iterator iter;
    fz_matrix page_ctm;
    fz_rect mediabox;
    fz_rect ofdPageMediabox;
    float pageWidth = 0;
    float pageHeight = 0;
    float stampWidth_temp = 0;
    float stampHeight_temp = 0;
    int i = 0;
    FZZBytes * itemImageData = 0;

    FZZImageUtil imageUtil;

    FZZBytes tempstampimage;
fz_try(m_CTX)
{
    m_CurrAddStampCount++;
    if ( m_CurrAddStampCount > PDF_MAX_STAMP_COUNT ) {
        ret = -7;
        goto err;
    }
    
    if ( m_CTX == NULL || m_Doc == NULL ) {
        ret = -2;
        goto err;
    }
    
//    if (pdf_needs_password(m_CTX, m_Doc)) {
//        if (!pdf_authenticate_password(m_CTX, m_Doc, m_PassWord.c_str())) {
//            ret = -1;
//            goto err;
//        }
//    }
    
    totalpages = pageSize();
    
    if ( totalpages < 2 ) {
        ret = -8;
        goto err;
    }
    
    if ( type == FZZPDFSigner::TYPE::TYPE_Right || type == FZZPDFSigner::TYPE::TYPE_Left ) {
        stampWidth_temp = stampWidth/2+1;
        stampHeight_temp = stampHeight;
        imageUtil.SplitImage(stampimage,"PNG",2,true,outImages,NULL,NULL);
    }   else {
        stampWidth_temp = stampWidth;
        stampHeight_temp = stampHeight/2+1;
        imageUtil.SplitImage(stampimage,"PNG",2,false,outImages,NULL,NULL);
    }
    
    signer = pkcs7_gm_create_signer(m_CTX, isCallBack,x509, prikey,signFunc,cbParam,&stampimage);
    if ( signer == NULL ) {
        ret = -4;
        goto err;
    }
 
    for (i = 0; i < totalpages; i++) {
        pdfpage = pdf_load_page(m_CTX, m_Doc, i);
        if ( pdfpage == NULL ) {
            ret = -2;
            goto err;
        }
        
        pdf_page_transform(m_CTX, pdfpage, &mediabox, &page_ctm);
        
        if ( page_ctm.b != 0 || page_ctm.c != 0 ) {
            ofdPageMediabox.x0 = mediabox.x0;
            ofdPageMediabox.y0 = mediabox.y0;
            ofdPageMediabox.x1 = mediabox.y1;
            ofdPageMediabox.y1 = mediabox.x1;
        } else {
            ofdPageMediabox.x0 = mediabox.x0;
            ofdPageMediabox.y0 = mediabox.y0;
            ofdPageMediabox.x1 = mediabox.x1;
            ofdPageMediabox.y1 = mediabox.y1;
        }
        
        pageWidth = ofdPageMediabox.x1 - ofdPageMediabox.x0;
        pageHeight = ofdPageMediabox.y1 - ofdPageMediabox.y0;
        
        
        
        
        
        
        if ( i == 0 ) {
            pdf_create_field_name(m_CTX, pdfpage->doc, "Signature", name, sizeof name);
            widget = pdf_create_signature_widget(m_CTX, pdfpage, name);
            if ( widget == NULL ) {
                ret = -3;
                goto err;
            }
            switch (type) {
                case FZZPDFSigner::TYPE::TYPE_Right:
                case FZZPDFSigner::TYPE::TYPE_Left:
                    annot_rect.x0 = pageWidth-stampWidth_temp;
                    annot_rect.y0 = (pageHeight - stampHeight_temp)/2;
                    annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                    annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                    itemImageData = outImages[0];
                    break;
                case FZZPDFSigner::TYPE::TYPE_Top:
                case FZZPDFSigner::TYPE::TYPE_Bottom:
                    annot_rect.x0 = (pageWidth-stampWidth_temp)/2;
                    annot_rect.y0 = pageHeight - stampHeight_temp;
                    annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                    annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                    itemImageData = outImages[0];
                    break;
                default:
                    break;
            }
                    
            pdf_set_annot_rect(m_CTX, widget, annot_rect);
            if ( itemImageData->getLen() > 0 ) {
#ifdef PDF_STAMP_USE_CLIPS
                buffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
                if ( buffer == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                image = fz_new_image_from_buffer(m_CTX, buffer);
                if ( image == NULL ) {
                    ret = -6;
                    goto err;
                }
#else
                ClearAlpha(*itemImageData,tempstampimage);
                if ( tempstampimage.getLen() <= 0 ) {
                    ret = -6;
                    goto err;
                }
                
                buffer = fz_new_buffer_from_copied_data(m_CTX, tempstampimage.getData(), tempstampimage.getLen());
                if ( buffer == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                image = fz_new_image_from_buffer(m_CTX, buffer);
                if ( image == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                showbuffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
                if ( showbuffer == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                showimage = fz_new_image_from_buffer(m_CTX, showbuffer);
                if ( showimage == NULL ) {
                    ret = -6;
                    goto err;
                }
#endif
//                pdf_sign_signature(m_CTX, widget, signer,
//                               PDF_SIGNATURE_APPEARANCE_STAMP,
//                                    image,
//                               NULL,
//                               NULL);
                pdf_sign_signature_ext(m_CTX, widget, signer,
                                           PDF_SIGNATURE_APPEARANCE_STAMP,
                                                image,
                                       alpha,
                                       showimage,
                                           NULL,
                                           NULL,(fz_page*)pdfpage,drawStampOverText,drawStampOverText_End);
                
            } else {
                ret = -6;
                goto err;
            }
        } else {
            pdf_create_field_name(m_CTX, pdfpage->doc, "Signature", name, sizeof name);
            widget = pdf_create_signature_widget(m_CTX, pdfpage, name);
            if ( widget == NULL ) {
                ret = -3;
                goto err;
            }
            switch (type) {
                case FZZPDFSigner::TYPE::TYPE_Right:
                case FZZPDFSigner::TYPE::TYPE_Left:
                    annot_rect.x0 = 0;
                    annot_rect.y0 = (pageHeight - stampHeight_temp)/2;
                    annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                    annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                    itemImageData = outImages[1];
                    break;
                case FZZPDFSigner::TYPE::TYPE_Top:
                case FZZPDFSigner::TYPE::TYPE_Bottom:
                    annot_rect.x0 = (pageWidth-stampWidth_temp)/2;
                    annot_rect.y0 = 0;
                    annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                    annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                    itemImageData = outImages[1];
                    break;
                default:
                    break;
            }
            pdf_set_annot_rect(m_CTX, widget, annot_rect);
            if ( itemImageData->getLen() > 0 ) {
#ifdef PDF_STAMP_USE_CLIPS
                buffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
                if ( buffer == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                image = fz_new_image_from_buffer(m_CTX, buffer);
                if ( image == NULL ) {
                    ret = -6;
                    goto err;
                }
#else
                ClearAlpha(*itemImageData,tempstampimage);
                if ( tempstampimage.getLen() <= 0 ) {
                    ret = -6;
                    goto err;
                }
                buffer = fz_new_buffer_from_copied_data(m_CTX, tempstampimage.getData(), tempstampimage.getLen());
                if ( buffer == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                image = fz_new_image_from_buffer(m_CTX, buffer);
                if ( image == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                showbuffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
                if ( showbuffer == NULL ) {
                    ret = -6;
                    goto err;
                }
                
                showimage = fz_new_image_from_buffer(m_CTX, showbuffer);
                if ( showimage == NULL ) {
                    ret = -6;
                    goto err;
                }
#endif
//                pdf_sign_signature(m_CTX, widget, NULL,
//                                       PDF_SIGNATURE_APPEARANCE_STAMP,
//                                            image,
//                                       NULL,
//                                       NULL);
                pdf_sign_signature_ext(m_CTX, widget, NULL,
                                           PDF_SIGNATURE_APPEARANCE_STAMP,
                                                image,
                                       alpha,
                                       showimage,
                                           NULL,
                                           NULL,(fz_page*)pdfpage,drawStampOverText,drawStampOverText_End);
            } else {
                ret = -6;
                goto err;
            }
            if ( i != totalpages - 1 ) {
                if ( buffer != NULL ) {
                    fz_drop_buffer(m_CTX, buffer);
                    buffer = NULL;
                }
                if ( image != NULL ) {
                    fz_drop_image(m_CTX, image);
                    image = NULL;
                }
                
                if ( showbuffer != NULL ) {
                    fz_drop_buffer(m_CTX, showbuffer);
                    showbuffer = NULL;
                }
                if ( showimage != NULL ) {
                    fz_drop_image(m_CTX, showimage);
                    showimage = NULL;
                }
                
                if ( widget != NULL ) {
                    pdf_drop_widget(m_CTX,widget);
                    widget = NULL;
                }
                
                pdf_create_field_name(m_CTX, pdfpage->doc, "Signature", name, sizeof name);
                widget = pdf_create_signature_widget(m_CTX, pdfpage, name);
                if ( widget == NULL ) {
                    ret = -3;
                    goto err;
                }
                switch (type) {
                    case FZZPDFSigner::TYPE::TYPE_Right:
                    case FZZPDFSigner::TYPE::TYPE_Left:
                        annot_rect.x0 = pageWidth-stampWidth_temp;
                        annot_rect.y0 = (pageHeight - stampHeight_temp)/2;
                        annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                        annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                        itemImageData = outImages[0];
                        break;
                    case FZZPDFSigner::TYPE::TYPE_Top:
                    case FZZPDFSigner::TYPE::TYPE_Bottom:
                        annot_rect.x0 = (pageWidth-stampWidth_temp)/2;
                        annot_rect.y0 = pageHeight - stampHeight_temp;
                        annot_rect.x1 = annot_rect.x0+stampWidth_temp;
                        annot_rect.y1 = annot_rect.y0+stampHeight_temp;
                        itemImageData = outImages[0];
                        break;
                    default:
                        break;
                }
                pdf_set_annot_rect(m_CTX, widget, annot_rect);
                if ( itemImageData->getLen() > 0 ) {
#ifdef PDF_STAMP_USE_CLIPS
                    buffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
                    if ( buffer == NULL ) {
                        ret = -6;
                        goto err;
                    }
                    
                    image = fz_new_image_from_buffer(m_CTX, buffer);
                    if ( image == NULL ) {
                        ret = -6;
                        goto err;
                    }
#else
                    ClearAlpha(*itemImageData,tempstampimage);
                    if ( tempstampimage.getLen() <= 0 ) {
                        ret = -6;
                        goto err;
                    }
                    buffer = fz_new_buffer_from_copied_data(m_CTX, tempstampimage.getData(), tempstampimage.getLen());
                    if ( buffer == NULL ) {
                        ret = -6;
                        goto err;
                    }
                    
                    image = fz_new_image_from_buffer(m_CTX, buffer);
                    if ( image == NULL ) {
                        ret = -6;
                        goto err;
                    }
                    
                    showbuffer = fz_new_buffer_from_copied_data(m_CTX, itemImageData->getData(), itemImageData->getLen());
                    if ( showbuffer == NULL ) {
                        ret = -6;
                        goto err;
                    }
                    
                    showimage = fz_new_image_from_buffer(m_CTX, showbuffer);
                    if ( showimage == NULL ) {
                        ret = -6;
                        goto err;
                    }
#endif
//                    pdf_sign_signature(m_CTX, widget, NULL,
//                                           PDF_SIGNATURE_APPEARANCE_STAMP,
//                                                image,
//                                           NULL,
//                                           NULL);
                    pdf_sign_signature_ext(m_CTX, widget, NULL,
                                               PDF_SIGNATURE_APPEARANCE_STAMP,
                                                    image,
                                           alpha,
                                           showimage,
                                               NULL,
                                               NULL,(fz_page*)pdfpage,drawStampOverText,drawStampOverText_End);
                } else {
                    ret = -6;
                    goto err;
                }
            }
            
        }
        
        if ( buffer != NULL ) {
            fz_drop_buffer(m_CTX, buffer);
            buffer = NULL;
        }
        if ( image != NULL ) {
            fz_drop_image(m_CTX, image);
            image = NULL;
        }
        
        if ( showbuffer != NULL ) {
            fz_drop_buffer(m_CTX, showbuffer);
            showbuffer = NULL;
        }
        if ( showimage != NULL ) {
            fz_drop_image(m_CTX, showimage);
            showimage = NULL;
        }
        
        if ( widget != NULL ) {
            pdf_drop_widget(m_CTX,widget);
            widget = NULL;
        }
        if ( pdfpage != NULL ) {
            pdf_drop_page(m_CTX, pdfpage);
            pdfpage = NULL;
        }
    } // for
}
fz_always(m_CTX)
{
    
}
fz_catch(m_CTX)
{

}
err:
    if ( buffer != NULL ) {
        fz_drop_buffer(m_CTX, buffer);
        buffer = NULL;
    }
    if ( image != NULL ) {
        fz_drop_image(m_CTX, image);
        image = NULL;
    }
    
    if ( showbuffer != NULL ) {
        fz_drop_buffer(m_CTX, showbuffer);
        showbuffer = NULL;
    }
    if ( showimage != NULL ) {
        fz_drop_image(m_CTX, showimage);
        showimage = NULL;
    }
    
    if ( signer != NULL ) {
        pdf_drop_signer(m_CTX, signer);
        signer = NULL;
    }
    
    if ( widget != NULL ) {
        pdf_drop_widget(m_CTX,widget);
        widget = NULL;
    }
    
    if ( pdfpage != NULL ) {
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
    
    for (iter = outImages.begin(); iter != outImages.end(); iter++) {
        if ( *iter != NULL ) {
            delete *iter;
        }
    }
    outImages.clear();
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::getSignInfos(vector<string> & pageIndexs,vector<string> & sids,vector<FZZBytes *> & stampimages)
{
    m_SignInfo_PageIndexs.clear();
    m_SignInfo_Sids.clear();
    
    vector<FZZBytes*>::const_iterator stampimageiter;
    for (stampimageiter = m_SignInfo_StampImages.begin(); stampimageiter != m_SignInfo_StampImages.end(); stampimageiter++) {
        if ( *stampimageiter != NULL ) {
            delete *stampimageiter;
        }
    }
    m_SignInfo_StampImages.clear();
    
    int pagecount = pageSize();
    for (int i = 0; i < pagecount; i++) {
        getSignInfos(i);
    }
    

    for (stampimageiter = m_SignInfo_StampImages.begin(); stampimageiter != m_SignInfo_StampImages.end(); stampimageiter++) {
        if ( *stampimageiter != NULL ) {
            stampimages.push_back(*stampimageiter);
        }
    }
    
    vector<string>::const_iterator striter;
    for (striter = m_SignInfo_PageIndexs.begin(); striter != m_SignInfo_PageIndexs.end(); striter++) {
        pageIndexs.push_back(*striter);
    }
    
    for (striter = m_SignInfo_Sids.begin(); striter != m_SignInfo_Sids.end(); striter++) {
        sids.push_back(*striter);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::getSignInfos(int pageIndex)

{
    
    pdf_page * pdfpage = NULL;
    fz_device * dev = NULL;

    dev = new_pdfStampimage_device(m_CTX);
    if ( dev == NULL ) {
        goto err;
    }
    
 
    
    pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
    if ( pdfpage == NULL ) {
        goto err;
    }
    
    pdf_page_annots(pageIndex,m_CTX, pdfpage, dev, MUPDF_fz_identity, "View",NULL);
    pdf_page_widgets(pageIndex,m_CTX, pdfpage, dev, MUPDF_fz_identity, "View", NULL);
    
err:
    if ( dev != NULL ) {
        fz_close_device(m_CTX, dev);
        fz_drop_device(m_CTX, dev);
        dev = NULL;
    }
    
    if ( pdfpage != NULL ) {
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//pdf_run_page_annots_with_usage is ok
void FZZPDFSigner::pdf_page_annots(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    pdf_document *doc = page->doc;
    int nocache;

    nocache = !!(dev->hints & FZ_NO_CACHE);
    if (nocache)
        pdf_mark_xref(ctx, doc);

    fz_try(ctx)
    {
        pdf_page_annots_with_usage_imp(pageIndex,ctx, doc, page, dev, ctm, usage, cookie);
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
//pdf_run_page_annots_with_usage_imp is ok
void FZZPDFSigner::pdf_page_annots_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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

        pdf_annot_with_usage(pageIndex,ctx, doc, page, annot, dev, ctm, usage, cookie);
    }
}
//-----------------------------------------------------------------------------------------------------------------
//pdf_run_page_widgets_with_usage is ok
void FZZPDFSigner::pdf_page_widgets(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
{
    pdf_document *doc = page->doc;
    int nocache;

    nocache = !!(dev->hints & FZ_NO_CACHE);
    if (nocache)
        pdf_mark_xref(ctx, doc);

    fz_try(ctx)
    {
        pdf_page_widgets_with_usage_imp(pageIndex,ctx, doc, page, dev, ctm, usage, cookie);
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
//pdf_run_page_widgets_with_usage_imp is ok
void FZZPDFSigner::pdf_page_widgets_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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

        pdf_annot_with_usage(pageIndex,ctx, doc, page, widget, dev, ctm, usage, cookie);
    }
}
//-----------------------------------------------------------------------------------------------------------------
//pdf_run_annot_with_usage is ok
void FZZPDFSigner::pdf_annot_with_usage(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie)
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
    //DLOG("annto time : %s",buffer);
    
    
    
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

    pdf_pkcs7_verifier *verifier = NULL;
    pdf_pkcs7_distinguished_name *dn = NULL;
    fz_var(dn);
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

//        const char* pcreator = strAuthor.c_str();
//        const char* pTime = buffer;
//        const char* pstrannottype_TYPE_Highlight = "Highlight";
//        const char* pstrannottype_TYPE_Stamp = "Stamp";
        //AnnotType::toString(AnnotType::TYPE::TYPE_Path).c_str()
//        const char* pstrannottype_TYPE_Path = "Path";
//        //AnnotType::toString(AnnotType::TYPE::TYPE_Link).c_str()
//        const char* pstrannottype_TYPE_Link = "Link";
//        const char* pstrremark = strContents.c_str();
        string strPageIndex = FZZConst::fmt(pageIndex + 1);
//        const char* pPageindex = strPageIndex.c_str();
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

        pdfStampimage_device * pdev = (pdfStampimage_device*)dev;
        switch (annotType) {
            
            case PDF_ANNOT_SQUIGGLY:
                
                break;
            case PDF_ANNOT_STRIKE_OUT:
                
                break;
            case PDF_ANNOT_UNDERLINE:
                
                break;
            case PDF_ANNOT_HIGHLIGHT:
                
                break;
            case PDF_ANNOT_TEXT:
            case PDF_ANNOT_FREE_TEXT:
            case PDF_ANNOT_STAMP:
                
                break;
            case PDF_ANNOT_WIDGET:
                if (  pdev->stampImage != NULL ) {
                    //is RidingStamp
                    if (pdf_signature_is_signed(ctx, doc, annot->obj)) {
                    
                        verifier = pkcs7_gm_create_verifier(ctx,NULL,NULL);
                        
                        dn = pdf_signature_get_signatory(ctx, verifier, doc, annot->obj);
                        GM_VERIFIER* gmverifyer = (GM_VERIFIER*)verifier;
                        if ( gmverifyer->imagedata != NULL && gmverifyer->imagedata->getLen() > 10 ) {
                            pdev->stampImage->setData(gmverifyer->imagedata->getData(), gmverifyer->imagedata->getLen());
                        }
                        
                        FZZBytes* tempimage = new FZZBytes(pdev->stampImage->getData(),pdev->stampImage->getLen());
                        if ( tempimage != NULL ) {

                            m_SignInfo_PageIndexs.push_back(strPageIndex);
                            m_SignInfo_Sids.push_back(strsignid);
                            m_SignInfo_StampImages.push_back(tempimage);
                        }
                        
                        //stampsFunc(pPageindex,"",strsignid.c_str(),pdev->stampImage->getData(),pdev->stampImage->getLen());
                    }
                }
             
                break;
            case PDF_ANNOT_INK:
                
                break;
            case PDF_ANNOT_SQUARE:
                
                break;
            case PDF_ANNOT_CIRCLE:
                
                break;
            case PDF_ANNOT_LINE:
                
                break;
            case PDF_ANNOT_FILE_ATTACHMENT:
                
                break;
            default:
                
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
        if ( dn != NULL ) {
            pdf_signature_drop_distinguished_name(ctx, dn);
        }
        if ( verifier != NULL ) {
            pdf_drop_verifier(ctx, verifier);
        }
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
void FZZPDFSigner::fillPath(fz_device *dev,fz_text *text,fz_matrix ctm,fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //char tempstr[6] = {0};
    //char * ptempstr = tempstr;
fz_try(m_CTX)
{
    for (fz_text_span * span = text->head; span; span = span->next) {

        if ( span == NULL ) {
            continue;
        }
        fz_matrix tm, trm;
        //int gid;

        if ( span->len <= 0 ) continue;

        tm = span->trm;

        //fz_font_flags_t * fontFlags = fz_font_flags(span->font);
        
        //fontSetting->setBold(fontFlags->is_bold);
        //fontSetting->setItalic(fontFlags->is_italic);
        for (int i = 0; i < span->len; i++) {
            //if (span->items[i].ucs < 0)
            //    continue;
            //fz_runetochar(ptempstr, span->items[i].ucs);

            //fz_text* temptext = fz_new_text(ctx);
            tm.e = span->items[i].x;
            tm.f = span->items[i].y;
            trm = fz_concat(tm, ctm);
            fz_path* fontPath = fz_outline_glyph(m_CTX,span->font,span->items[i].gid,trm);
            if ( fontPath != NULL ) {

                
                
                
                //fz_fill_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, cs, color, 0.75f, fz_default_color_params);
                //fz_fill_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, cs, color, alpha, fz_default_color_params);
             
                fz_fill_path(m_CTX, dev, fontPath, 0, MUPDF_fz_identity, colorspace, color, alpha, color_params);
                
                
                
                fz_drop_path(m_CTX, fontPath);

           }
     
        }

    }
}
fz_always(m_CTX)
{
    
}
fz_catch(m_CTX)
{

}
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::drawStampOverText(fz_context *ctx,fz_page *page,fz_device *dev,fz_rect rect,fz_image *showgraphic)
{
#ifdef PDF_STAMP_DRAWTEXT
#ifdef PDF_STAMP_USE_CLIPS
    fz_path *path = fz_new_path(ctx);

    fz_moveto(ctx, path, rect.x0, rect.y0);
    fz_lineto(ctx, path, rect.x1, rect.y0);
    fz_lineto(ctx, path, rect.x1, rect.y1);
    fz_lineto(ctx, path, rect.x0, rect.y1);
    fz_closepath(ctx, path);
    
//    fz_moveto(ctx, path, rect.x0+10, rect.y0);
//    fz_lineto(ctx, path, rect.x1-10, rect.y0);
//    fz_lineto(ctx, path, rect.x1-10, rect.y1);
//    fz_lineto(ctx, path, rect.x0+10, rect.y1);
//    fz_closepath(ctx, path);
    
    //fz_clip_path(ctx,dev,path,false,MUPDF_fz_identity,rect);

    //--------------
    fz_matrix ctm = MUPDF_fz_identity;
    fz_device * stampdevice = new_stamp_device(ctx,dev,rect,false,showgraphic,path);
    //((stamp_device*)stampdevice)->isGenFont = true;
    //pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
    //((stamp_device*)stampdevice)->isGenFont = false;

    pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
    fz_close_device(ctx, stampdevice);
    fz_drop_device(ctx, stampdevice);

    fz_clip_path(ctx,dev,path,true,MUPDF_fz_identity,rect);
    //-------------------
    
  
    
    fz_drop_path(ctx, path);
#endif
#endif
    
    //DLOG("drawStampOverText ");
//    fz_matrix ctm = MUPDF_fz_identity;
//
//    fz_device * stampdevice = new_stamp_device(ctx,dev,rect);
//    //((stamp_device*)stampdevice)->isGenFont = true;
//    //pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
//    //((stamp_device*)stampdevice)->isGenFont = false;
//    pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
//    fz_close_device(ctx, stampdevice);
//    fz_drop_device(ctx, stampdevice);
    
    
    
//    pdf_run_page(ctx, (pdf_page*)page, dev, ctm, NULL);
    
    
    
//    fz_device *drawdev = NULL;
//    fz_image * image = NULL;
//    fz_matrix ctm = MUPDF_fz_identity;
//    //ctm = fz_post_scale(ctm,3,3);
//
//    //rect = pdf_bound_annot(ctx, annot);
//    rect = fz_transform_rect(rect, ctm);
//    fz_irect bbox = fz_round_rect(rect);
//
//    fz_pixmap *pix = fz_new_pixmap_with_bbox(ctx, fz_device_rgb(ctx), bbox, NULL, 1.0);
//    if (1.0)
//        fz_clear_pixmap(ctx, pix);
//    else
//        fz_clear_pixmap_with_value(ctx, pix, 0xFF);
//
//    fz_try(ctx)
//    {
//        drawdev = fz_new_draw_device(ctx, ctm, pix);
//        pdf_run_page(ctx, (pdf_page*)page, drawdev, MUPDF_fz_identity, NULL);
//        fz_close_device(ctx, drawdev);
//        image = fz_new_image_from_pixmap(ctx, pix, NULL);
//
//        fz_rect imgprect = rect;
//        float img_aspect = (float) image->w / image->h;
//        float rectw = imgprect.x1 - imgprect.x0;
//        float recth = imgprect.y1 - imgprect.y0;
//        float midx = (imgprect.x0+rectw/2.0);
//        float midy = (imgprect.y0+recth/2.0);
//        float rect_aspect = rectw / recth;
//        float scale = img_aspect > rect_aspect ? rectw / image->w : recth / image->h;
//        fz_matrix ctm1 = fz_pre_translate(fz_pre_scale(fz_translate(midx, midy), scale * image->w, scale * image->h), -0.5, -0.5);
//
//        fz_fill_image(ctx, dev, image, ctm1, 1.0, fz_default_color_params);
//    }
//    fz_always(ctx)
//    {
//        fz_drop_device(ctx, drawdev);
//    }
//    fz_catch(ctx)
//    {
//        fz_drop_pixmap(ctx, pix);
//        fz_drop_image(ctx, image);
//        fz_rethrow(ctx);
//    }
//
//
    
    
    
//    FZZBytes ret;
//    if ( pix != NULL ) {
//
//        fz_buffer *buf = fz_new_buffer(ctx, INCREMENT_BUFLEN_PNG);
//        if ( buf != NULL ) {
//            fz_output * out = fz_new_output_with_buffer(ctx, buf);
//            if ( out != NULL ) {
//                fz_write_pixmap_as_png(ctx, out, pix);
//
//                ret.setData(buf->data, buf->len);
//
//                fz_close_output(ctx, out);
//                fz_drop_output(ctx, out);
//            }
//            fz_drop_buffer(ctx, buf);
//        }
//        fz_drop_pixmap(ctx, pix);
//    }
//
//    FZZConst::writefile("/Users/fzz/work/cpp/ofd/tmp/signpdf/out.png", ret.getData(), ret.getLen());
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::drawStampOverText_End(fz_context *ctx,fz_page *page,fz_device *dev,fz_rect rect,fz_image *showgraphic)
{
    //
#ifdef PDF_STAMP_DRAWTEXT
#ifdef PDF_STAMP_USE_CLIPS
    fz_pop_clip(ctx,dev);
#else
    fz_matrix ctm = MUPDF_fz_identity;
    fz_device * stampdevice = new_stamp_device(ctx,dev,rect,true,showgraphic,NULL);
    pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
    fz_close_device(ctx, stampdevice);
    fz_drop_device(ctx, stampdevice);
#endif
#endif
    /*
    fz_matrix ctm = MUPDF_fz_identity;
    fz_device * stampdevice = new_stamp_device(ctx,dev,rect);
    //((stamp_device*)stampdevice)->isGenFont = true;
    //pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
    //((stamp_device*)stampdevice)->isGenFont = false;
    
    pdf_run_page(ctx, (pdf_page*)page, stampdevice, ctm, NULL);
    fz_close_device(ctx, stampdevice);
    fz_drop_device(ctx, stampdevice);
     */
    
    
}
//-----------------------------------------------------------------------------------------------------------------
fz_font * FZZPDFSigner::PDFSigner_load_system_font(fz_context *ctx, const char *name, int bold, int italic, int needs_exact_metrics)
{
    //DLOG("PDFSigner_load_system_font : %s",name);
    string strfontname = name;
    
//    if ( strfontname.find("STSongStd-Light") != string::npos  ) {
//        strfontname = "STSong-Light";
//    }
    fz_font * fzFont = NULL;

    FZZFontCache* fontCache = FZZConst::g_FZSystemFontList.findFont(strfontname);
    if ( fontCache != NULL ) {
        //fzFont = (fz_font *)fontCache->getFZFont();
        const FZZBytes* fontdata = fontCache->getFontData();
        if ( fontdata != NULL && fontdata->getLen() > 0 ) {
            fzFont = fz_new_font_from_memory(ctx, NULL, fontdata->getData(), (int)fontdata->getLen(), 0, 0);
        }
    }

    return fzFont;
}
//-----------------------------------------------------------------------------------------------------------------
fz_font * FZZPDFSigner::PDFSigner_load_system_cjk_font(fz_context *ctx, const char *name, int ordering, int serif)
{
    DLOG("PDFSigner_load_system_cjk_font : %s",name);
    string strfontname = name;
    
//    if ( strfontname.find("STSongStd-Light") != string::npos  ) {
//        strfontname = "STSong-Light";
//    }
    fz_font * fzFont = NULL;

    FZZFontCache* fontCache = FZZConst::g_FZSystemFontList.findFont(strfontname);
    if ( fontCache != NULL ) {
        //fzFont = (fz_font *)fontCache->getFZFont();
        const FZZBytes* fontdata = fontCache->getFontData();
        if ( fontdata != NULL && fontdata->getLen() > 0 ) {
            fzFont = fz_new_font_from_memory(ctx, NULL, fontdata->getData(), (int)fontdata->getLen(), 0, 0);
        }
    }

    return fzFont;
}
//-----------------------------------------------------------------------------------------------------------------
fz_font * FZZPDFSigner::PDFSigner_load_system_fallback_font(fz_context *ctx, int script, int language, int serif, int bold, int italic)
{
    DLOG("PDFSigner_load_system_fallback_font");
    return NULL;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::getPageWidthHeight(int pageIndex,/*out*/double &pageWidth,/*out*/double &pageHeight)
{
    pageWidth = 0;
    pageHeight = 0;
    pdf_page * pdfpage = NULL;
    pdfpage = pdf_load_page(m_CTX, m_Doc, pageIndex);
    if ( pdfpage == NULL ) {
        return;
    }
    
    fz_matrix page_ctm;
    fz_rect mediabox;
    pdf_page_transform(m_CTX, pdfpage, &mediabox, &page_ctm);
    
    float page_x0 = 0;
    float page_x1 = 0;
    float page_y0 = 0;
    float page_y1 = 0;
    
    if ( page_ctm.b != 0 || page_ctm.c != 0 ) {
        page_x0 = mediabox.x0;
        page_y0 = mediabox.y0;
        page_x1 = mediabox.y1;
        page_y1 = mediabox.x1;
    } else {
        page_x0 = mediabox.x0;
        page_y0 = mediabox.y0;
        page_x1 = mediabox.x1;
        page_y1 = mediabox.y1;
    }
    
    pageWidth = page_x1 - page_x0;
    pageHeight = page_y1 - page_y0;
    
    if ( pdfpage != NULL ) {
        pdf_drop_page(m_CTX, pdfpage);
        pdfpage = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFSigner::getStampImage(fz_context *ctx, pdf_document *doc, pdf_obj *field,FZZBytes & stampImage)
{
    pdf_pkcs7_verifier *verifier = NULL;
    pdf_pkcs7_distinguished_name *dn = NULL;
    
    verifier = pkcs7_gm_create_verifier(ctx,NULL,NULL);
    if ( verifier != NULL ) {
        dn = pdf_signature_get_signatory(ctx, verifier, doc, field);
        if (dn)
        {
            pdf_signature_drop_distinguished_name(ctx, dn);
        }
        GM_VERIFIER* gmverifyer = (GM_VERIFIER*)verifier;
        if ( gmverifyer->imagedata != NULL && gmverifyer->imagedata->getLen() > 10 ) {
            stampImage.setData(gmverifyer->imagedata->getData(), gmverifyer->imagedata->getLen());
        }
        pdf_drop_verifier(ctx, verifier);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
