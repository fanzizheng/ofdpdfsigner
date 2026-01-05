//
//  Created by zizheng fan on 2024/09/20.
//
#include "basic/FZZConst.h"
#include "converter/utils/FZZSVGUtil.h"
#include "basic/FZZMatrix.h"
#include "mupdf/fitz/output-svg.h"
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZSVGUtil**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSVGUtil::FZZSVGUtil() : FZZObject(),m_Dev(NULL),m_SvgOutPut(NULL),m_SvgBuffer(NULL),m_PageWidth(0),m_PageHeight(0)
{
    FZZConst::addClassCount("FZZSVGUtil");
    //m_CTX = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSVGUtil::FZZSVGUtil(fz_context * ctx) : FZZObject(ctx), m_Dev(NULL),m_SvgOutPut(NULL),m_SvgBuffer(NULL),m_PageWidth(0),m_PageHeight(0)
{
    FZZConst::addClassCount("FZZSVGUtil");
    //m_CTX = ctx;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSVGUtil::FZZSVGUtil(const FZZSVGUtil& obj): FZZSVGUtil()
{

    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZSVGUtil::~FZZSVGUtil()
{
    FZZConst::delClassCount("FZZSVGUtil");
    
    ClearSVG();
    
//    if ( isFreeCTX ) {
//        if ( m_CTX != NULL ) {
//            fz_flush_warnings(m_CTX);
//            fz_drop_context(m_CTX);
//            m_CTX = NULL;
//        }
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::ClearSVG()
{
    if ( m_CTX == NULL ) {
        return;
    }
    
    if ( m_Dev != NULL ) {
        fz_close_device(m_CTX, m_Dev);
        fz_drop_device(m_CTX, m_Dev);
        m_Dev = NULL;
    }
    
    if ( m_SvgOutPut != NULL ) {
        fz_close_output(m_CTX, m_SvgOutPut);
        fz_drop_output(m_CTX, m_SvgOutPut);
        m_SvgOutPut = NULL;
    }
    
    if ( m_SvgBuffer != NULL ) {
        fz_drop_buffer(m_CTX, m_SvgBuffer);
        m_SvgBuffer = NULL;
    }
    
    m_PageWidth = 0;
    m_PageHeight = 0;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZSVGUtil::DrawCheck()
{
    return m_CTX == NULL || m_SvgOutPut == NULL || m_Dev == NULL ? false : true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::CreateSVG(float page_width, float page_height, int text_format, int reuse_images)
{
    if ( m_CTX == NULL ) {
        return;
    }
    
    ClearSVG();
    
    m_SvgBuffer = fz_new_buffer(m_CTX, 1024);
    if ( m_SvgBuffer == NULL ) {
        return;
    }
    m_SvgOutPut = fz_new_output_with_buffer(m_CTX, m_SvgBuffer);
    if ( m_SvgOutPut == NULL ) {
        return;
    }
    
    m_Dev = fz_new_svg_device(m_CTX,m_SvgOutPut,page_width, page_height, text_format, reuse_images);
    if ( m_Dev == NULL ) {
        
        return;
    }
    
    m_PageWidth = page_width;
    m_PageHeight = page_height;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSVGUtil::SVGEncode()
{
    FZZBytes retBytes;
    if ( !DrawCheck() ) {
        return retBytes;
    }
    if ( m_Dev != NULL ) {
        fz_close_device(m_CTX, m_Dev);
    }
    if ( m_SvgOutPut != NULL ) {
        fz_close_output(m_CTX, m_SvgOutPut);
    }
    if ( m_SvgBuffer != NULL && m_SvgBuffer->len > 0 ) {
        retBytes.setData(m_SvgBuffer->data, m_SvgBuffer->len);
    }
    ClearSVG();
    return retBytes;
}
//-----------------------------------------------------------------------------------------------------------------
float FZZSVGUtil::getWidth()
{
    return m_PageWidth;
}
//-----------------------------------------------------------------------------------------------------------------
float FZZSVGUtil::getHeight()
{
    return m_PageHeight;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawFillPath(fz_path * path,int even_odd,fz_matrix ctm, const float *color, float alpha)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( path == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_fill_path(m_CTX, m_Dev, path, even_odd, ctm, fz_device_rgb(m_CTX), color, alpha, fz_default_color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawFillPath error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawStrokePath(fz_path * path,fz_stroke_state* stroke,fz_matrix ctm, const float *color, float alpha)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( path == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_stroke_path(m_CTX, m_Dev, path, stroke, ctm, fz_device_rgb(m_CTX), color, alpha, fz_default_color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawStrokePath error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawFillImage(fz_image *image,fz_matrix ctm, float alpha)
{
    //DLOG("DrawFillImage");
    if ( !DrawCheck() ) {
        return;
    }
    if ( image == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_fill_image( m_CTX, m_Dev, image,  ctm, alpha,fz_default_color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawFillImage error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawFillShade(fz_shade *shade, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( shade == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_fill_shade( m_CTX, m_Dev, shade,  ctm, alpha,color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawFillShade error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::POPClip()
{
    //DLOG("POPClip");
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_pop_clip( m_CTX, m_Dev);
//    } fz_catch(m_CTX) {
//        DLOG("POPClip error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::ClipPath(fz_path *path, int even_odd, fz_matrix ctm, fz_rect scissor)
{
    //DLOG("ClipPath");
    if ( !DrawCheck() ) {
        return;
    }
    if ( path == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_clip_path( m_CTX, m_Dev, path, even_odd, ctm, scissor);
//    } fz_catch(m_CTX) {
//        DLOG("ClipPath error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::ClipStrokePath(fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
    //DLOG("ClipStrokePath");
    if ( !DrawCheck() ) {
        return;
    }
    if ( path == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_clip_stroke_path( m_CTX, m_Dev, path, stroke, ctm, scissor);
//    } fz_catch(m_CTX) {
//        DLOG("ClipStrokePath error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::ClipText(fz_text *text, fz_matrix ctm, fz_rect scissor)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( text == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_clip_text( m_CTX, m_Dev, text, ctm, scissor);
//    } fz_catch(m_CTX) {
//        DLOG("ClipText error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::ClipStrokeText(fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( text == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_clip_stroke_text( m_CTX, m_Dev, text, stroke, ctm, scissor);
//    } fz_catch(m_CTX) {
//        DLOG("ClipStrokeText error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::ClipImageMask(fz_image *image, fz_matrix ctm, fz_rect scissor)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( image == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_clip_image_mask( m_CTX, m_Dev, image, ctm, scissor);
//    } fz_catch(m_CTX) {
//        DLOG("ClipImageMask error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------


void FZZSVGUtil::DrawFillText(fz_text *text, fz_matrix ctm,
                   const float *color, float alpha)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( text == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_fill_text( m_CTX, m_Dev, text, ctm, fz_device_rgb(m_CTX), color, alpha, fz_default_color_params);
        //m_Dev->fill_text(m_CTX, m_Dev, text, ctm, fz_device_rgb(m_CTX), color, alpha, fz_default_color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawFillText error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawStrokeText(fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
                     const float *color, float alpha)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( text == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
      
        fz_stroke_text( m_CTX, m_Dev, text, stroke, ctm, fz_device_rgb(m_CTX), color, alpha, fz_default_color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawStrokeText error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawIgnoreText(fz_text *text, fz_matrix ctm)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( text == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_ignore_text( m_CTX, m_Dev, text, ctm);
//    } fz_catch(m_CTX) {
//        DLOG("DrawIgnoreText error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::DrawFillImageMask(fz_image *image, fz_matrix ctm,
                       fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    if ( !DrawCheck() ) {
        return;
    }
    if ( image == NULL ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_fill_image_mask( m_CTX, m_Dev, image, ctm,
                           colorspace, color, alpha, color_params);
//    } fz_catch(m_CTX) {
//        DLOG("DrawFillImageMask error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::BeginMask(fz_rect bbox, int luminosity, fz_colorspace *colorspace, const float *color, fz_color_params color_params)
{
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_begin_mask( m_CTX, m_Dev, bbox, luminosity, colorspace, color, color_params);
//    } fz_catch(m_CTX) {
//        DLOG("BeginMask error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::EndMask(fz_function *tr)
{
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_end_mask_tr( m_CTX, m_Dev, tr);
//    } fz_catch(m_CTX) {
//        DLOG("EndMask error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::BeginGroup(fz_rect bbox, fz_colorspace *cs, int isolated, int knockout, int blendmode, float alpha)
{
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_begin_group( m_CTX, m_Dev, bbox, cs, isolated, knockout, blendmode, alpha);
//    } fz_catch(m_CTX) {
//        DLOG("BeginGroup error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::EndGroup()
{
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_end_group( m_CTX, m_Dev);
//    } fz_catch(m_CTX) {
//        DLOG("EndGroup error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::BeginTile(fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm, int id)
{
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_begin_tile_id( m_CTX, m_Dev, area, view, xstep, ystep, ctm, id);
        
//    } fz_catch(m_CTX) {
//        DLOG("BeginTile error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSVGUtil::EndTile()
{
    if ( !DrawCheck() ) {
        return;
    }
    //fz_try(m_CTX) {
        fz_end_tile( m_CTX, m_Dev);
//    } fz_catch(m_CTX) {
//        DLOG("EndTile error : %s",m_CTX->error.message);
//    }
}
//-----------------------------------------------------------------------------------------------------------------


