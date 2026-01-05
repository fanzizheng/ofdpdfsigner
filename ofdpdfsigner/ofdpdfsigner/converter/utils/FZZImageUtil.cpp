//
//  Created by zizheng fan on 2024/07/16.
//
#include "basic/FZZConst.h"
#include "converter/utils/FZZImageUtil.h"
#include "basic/FZZMatrix.h"
#include "mupdf/fitz/pixmap.h"
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif
//-----------------------------------------------------------------------------------------------------------------
static int cmp_shade_stop(const void *a, const void *b)
{
    const struct shade_stop *astop = (const struct shade_stop *)a;
    const struct shade_stop *bstop = (const struct shade_stop *)b;
    float diff = astop->offset - bstop->offset;
    if (diff < 0)
        return -1;
    if (diff > 0)
        return 1;
    return astop->index - bstop->index;
}
//-----------------------------------------------------------------------------------------------------------------
static inline float lerp(float a, float b, float x)
{
    return a + (b - a) * x;
}
//-----------------------------------------------------------------------------------------------------------------
static void sample_gradient_stops(fz_context *ctx, fz_shade *shade, struct shade_stop *stops, int count)
{
    float offset, d;
    int i, k;

    k = 0;
    for (i = 0; i < 256; i++)
    {
        offset = i / 255.0f;
        while (k + 1 < count && offset > stops[k+1].offset)
            k++;

        d = (offset - stops[k].offset) / (stops[k+1].offset - stops[k].offset);

        shade->function[i][0] = lerp(stops[k].r, stops[k+1].r, d);
        shade->function[i][1] = lerp(stops[k].g, stops[k+1].g, d);
        shade->function[i][2] = lerp(stops[k].b, stops[k+1].b, d);
        shade->function[i][3] = lerp(stops[k].a, stops[k+1].a, d);
    }
}
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZImageUtil**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZImageUtil::FZZImageUtil() : FZZObject(),m_PixMap(NULL),m_Dev(NULL),m_Image(NULL),m_ImageBuffer(NULL)//,isFreeCTX(true)
{
    FZZConst::addClassCount("FZZImageUtil");
    //m_CTX = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
}
//-----------------------------------------------------------------------------------------------------------------
FZZImageUtil::FZZImageUtil(fz_context * ctx) : FZZObject(ctx), m_PixMap(NULL),m_Dev(NULL),m_Image(NULL),m_ImageBuffer(NULL)//,isFreeCTX(false)
{
    FZZConst::addClassCount("FZZImageUtil");
    //m_CTX = ctx;
}
//-----------------------------------------------------------------------------------------------------------------
FZZImageUtil::FZZImageUtil(const FZZImageUtil& obj): FZZImageUtil()
{

    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZImageUtil::~FZZImageUtil()
{
    FZZConst::delClassCount("FZZImageUtil");
    
    ClearImage();
    
//    if ( isFreeCTX ) {
//        if ( m_CTX != NULL ) {
//            fz_flush_warnings(m_CTX);
//            fz_drop_context(m_CTX);
//            m_CTX = NULL;
//        }
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::ClearImage()
{
    if ( m_CTX == NULL ) {
        return;
    }
    
    if ( m_PixMap != NULL ) {
        fz_drop_pixmap(m_CTX, m_PixMap);
        m_PixMap = NULL;
    }
    
    if ( m_Dev != NULL ) {
        fz_close_device(m_CTX, m_Dev);
        fz_drop_device(m_CTX, m_Dev);
        m_Dev = NULL;
    }
    
    if ( m_Image != NULL ) {
        fz_drop_image(m_CTX, m_Image);
        m_Image = NULL;
    }
    
    if ( m_ImageBuffer != NULL ) {
        fz_drop_buffer(m_CTX, m_ImageBuffer);
        m_ImageBuffer = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZImageUtil::DrawCheck()
{
    return m_CTX == NULL || m_PixMap == NULL || m_Dev == NULL ? false : true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::CreateImage(int width,int height,unsigned char R,unsigned char G,unsigned char B, unsigned char alpha)
{
    if ( m_CTX == NULL ) {
        return;
    }
    
    ClearImage();
    //fz_try(m_CTX) {
        m_PixMap = fz_new_pixmap(m_CTX, fz_device_rgb(m_CTX), width, height,NULL,alpha == 255 ? 0 : 1 );
        if ( m_PixMap == NULL ) {
            return;
        }

        clear_pixmap_with_value(m_CTX,m_PixMap,R,G,B,alpha);
        
        m_Dev = fz_new_draw_device(m_CTX, MUPDF_fz_identity, m_PixMap);
        if ( m_Dev == NULL ) {
            return;
        }
//    } fz_catch(m_CTX) {
//    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZImageUtil::LoadImage(fz_image *image)
{
    if ( m_CTX == NULL ) {
        return false;
    }
    
    ClearImage();
    
    m_PixMap = fz_get_pixmap_from_image(m_CTX, image, NULL, NULL, NULL, NULL);
    if ( m_PixMap == NULL ) {
        return false;
    }
    
    m_Dev = fz_new_draw_device(m_CTX, MUPDF_fz_identity, m_PixMap);
    if ( m_Dev == NULL ) {
        return false;
    }
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZImageUtil::LoadImage(const unsigned char * const data, size_t datalen)
{
    if ( datalen < 10 || data == NULL) {
        return false;
    }
    if ( m_CTX == NULL ) {
        return false;
    }
    
    ClearImage();
    
    m_ImageBuffer = fz_new_buffer_from_copied_data(m_CTX, data, datalen);
    if ( m_ImageBuffer == NULL ) {
        return false;
    }
    m_Image = fz_new_image_from_buffer(m_CTX, m_ImageBuffer);
    
    if ( m_Image == NULL ) {
        return false;
    }
    
    m_PixMap = fz_get_pixmap_from_image(m_CTX, m_Image, NULL, NULL, NULL, NULL);
    if ( m_PixMap == NULL ) {
        return false;
    }
    
    m_Dev = fz_new_draw_device(m_CTX, MUPDF_fz_identity, m_PixMap);
    if ( m_Dev == NULL ) {
        return false;
    }
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZImageUtil::LoadImage(const FZZBytes & imageData)
{
    return LoadImage(imageData.getData(),imageData.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZImageUtil::LoadImage(string imageFileName)
{

#ifdef _MSC_VER
    if ( _access(imageFileName.c_str(),0) == -1) {
        return false;
    }
#else
    if ( access(imageFileName.c_str(),0) == -1) {
        return false;
    }
#endif
    FZZBytes imageData;
    if (!FZZConst::readfile(imageFileName,imageData)) {
        DLOG("read image file error,filename = %s",imageFileName.c_str());
        return false;
    }
    return LoadImage(imageData.getData(),imageData.getLen());

}
//-----------------------------------------------------------------------------------------------------------------
fz_image * FZZImageUtil::getImage()
{
    if ( m_Image != NULL ) {
        return m_Image;
    }
    if ( m_PixMap != NULL ) {
        if ( m_CTX == NULL ) {
            return NULL;
        }
        
        m_Image = fz_new_image_from_pixmap(m_CTX, m_PixMap, NULL);
        return m_Image;
    }
    return NULL;
}
//-----------------------------------------------------------------------------------------------------------------
fz_pixmap * FZZImageUtil::getPixmap()
{
    return m_PixMap;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::clear_pixmap_with_value(fz_context *ctx, fz_pixmap *pix, unsigned char R,unsigned char G,unsigned char B, unsigned char alpha)
{
    unsigned char *s;
    int w, h, n;
    ptrdiff_t stride, len;
    //int alpha = pix->alpha;

    w = pix->w;
    h = pix->h;
    if (w < 0 || h < 0)
        return;

    n = pix->n;
    
    stride = pix->stride;
    len = (ptrdiff_t)w * n;

    s = pix->samples;
    
    int x, y;
    stride -= len;
    for (y = 0; y < pix->h; y++)
    {
        for (x = 0; x < pix->w; x++)
        {
            
            *s++ = R;
            *s++ = G;
            *s++ = B;
            if ( n == 4 ) {
                *s++ = alpha;
            }
            
        }
        s += stride;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZImageUtil::PngEncode()
{
    FZZBytes retBytes;
    if ( !DrawCheck() ) {
        return retBytes;
    }
    //fz_try(m_CTX) {
//        fz_buffer *buf = fz_new_buffer_from_pixmap_as_png(m_CTX,m_PixMap,fz_default_color_params);
//        if ( buf != NULL ) {
//            retBytes.setData(buf->data, buf->len);
//            fz_drop_buffer(m_CTX, buf);
//        }
        fz_buffer *buf = fz_new_buffer(m_CTX, INCREMENT_BUFLEN_PNG);
        if ( buf != NULL ) {
            fz_output * out = fz_new_output_with_buffer(m_CTX, buf);
            if ( out != NULL ) {
                fz_write_pixmap_as_png(m_CTX, out, m_PixMap);

                retBytes.setData(buf->data, buf->len);

                fz_close_output(m_CTX, out);
                fz_drop_output(m_CTX, out);
            }
            fz_drop_buffer(m_CTX, buf);
        }
//    } fz_catch(m_CTX) {
//    }
    
    return retBytes;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::deleteAlpha(fz_pixmap *srcpix,fz_pixmap *destpix)
{
    unsigned char * s;
    unsigned char * dest_s;
    int w, h, n;
    ptrdiff_t stride, len;
    ptrdiff_t dest_stride;
    //int alpha = pix->alpha;

    w = srcpix->w;
    h = srcpix->h;
    if (w < 0 || h < 0)
        return;

    n = srcpix->n;
    
    stride = srcpix->stride;
    dest_stride = destpix->stride;
    len = (ptrdiff_t)w * n;

    s = srcpix->samples;
    dest_s = destpix->samples;
    
    int x, y;
    stride -= len;
    dest_stride -= (ptrdiff_t)w * 3;
    for (y = 0; y < srcpix->h; y++)
    {
        for (x = 0; x < srcpix->w; x++)
        {
            
            *dest_s++ = *s++;
            *dest_s++ = *s++;
            *dest_s++ = *s++;
            s++;//alpha
            
        }
        s += stride;
        dest_s += dest_stride;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZImageUtil::JPGEncode()
{
    FZZBytes retBytes;
    if ( !DrawCheck() ) {
        return retBytes;
    }
    
    //fz_try(m_CTX) {
        fz_buffer *buf = fz_new_buffer(m_CTX, INCREMENT_BUFLEN_PNG);

        if ( buf != NULL ) {
        
            fz_output * out = fz_new_output_with_buffer(m_CTX, buf);
            if ( out != NULL ) {
               
                if ( m_PixMap->n == 4 ) {
                    
                    fz_pixmap * tempPixMap = fz_new_pixmap(m_CTX, fz_device_rgb(m_CTX), m_PixMap->w, m_PixMap->h,NULL,0);

                    deleteAlpha(m_PixMap,tempPixMap);

                    fz_write_pixmap_as_jpeg(m_CTX, out, tempPixMap,100,1);

                    fz_drop_pixmap(m_CTX, tempPixMap);
                    
                } else {
                   
                    fz_write_pixmap_as_jpeg(m_CTX, out, m_PixMap,100,1);
                    
                }
               
                retBytes.setData(buf->data, buf->len);
              
                fz_close_output(m_CTX, out);
                fz_drop_output(m_CTX, out);
            }
            fz_drop_buffer(m_CTX, buf);
        }
//    } fz_catch(m_CTX) {
//    }
  
    return retBytes;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZImageUtil::getWidth()
{
    if ( !DrawCheck() ) {
        return 0;
    }
    return fz_pixmap_width(m_CTX,m_PixMap);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZImageUtil::getHeight()
{
    if ( !DrawCheck() ) {
        return 0;
    }
    return fz_pixmap_height(m_CTX,m_PixMap);//m_PixMap->h;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::DrawFillPath(fz_path * path,int even_odd,fz_matrix ctm, const float *color, float alpha)
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
void FZZImageUtil::DrawStrokePath(fz_path * path,fz_stroke_state* stroke,fz_matrix ctm, const float *color, float alpha)
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
void FZZImageUtil::DrawFillImage(fz_image *image,fz_matrix ctm, float alpha)
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
void FZZImageUtil::DrawFillShade(fz_shade *shade, fz_matrix ctm, float alpha, fz_color_params color_params)
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
void FZZImageUtil::POPClip()
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
void FZZImageUtil::ClipPath(fz_path *path, int even_odd, fz_matrix ctm, fz_rect scissor)
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
void FZZImageUtil::ClipStrokePath(fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
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
void FZZImageUtil::ClipText(fz_text *text, fz_matrix ctm, fz_rect scissor)
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
void FZZImageUtil::ClipStrokeText(fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
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
void FZZImageUtil::ClipImageMask(fz_image *image, fz_matrix ctm, fz_rect scissor)
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


void FZZImageUtil::DrawFillText(fz_text *text, fz_matrix ctm,
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
void FZZImageUtil::DrawStrokeText(fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
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
void FZZImageUtil::DrawIgnoreText(fz_text *text, fz_matrix ctm)
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
void FZZImageUtil::DrawFillImageMask(fz_image *image, fz_matrix ctm,
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
void FZZImageUtil::BeginMask(fz_rect bbox, int luminosity, fz_colorspace *colorspace, const float *color, fz_color_params color_params)
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
void FZZImageUtil::EndMask(fz_function *tr)
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
void FZZImageUtil::BeginGroup(fz_rect bbox, fz_colorspace *cs, int isolated, int knockout, int blendmode, float alpha)
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
void FZZImageUtil::EndGroup()
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
void FZZImageUtil::BeginTile(fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm, int id)
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
void FZZImageUtil::EndTile()
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
fz_shade * FZZImageUtil::newShade(int type,int extend0,int extend1,float x0,float y0,float r0,float x1,float y1,float r1,shade_stop * stops,int stopCount)
{
    fz_shade * shade = NULL;
    if ( m_CTX == NULL ) {
        return shade;
    }
    shade = fz_malloc_struct(m_CTX, fz_shade);
    if ( shade == NULL ) {
        return shade;
    }
    FZ_INIT_STORABLE(shade, 1, fz_drop_shade_imp);
    
    shade->colorspace = fz_keep_colorspace(m_CTX, fz_device_rgb(m_CTX));
    shade->bbox = fz_infinite_rect;
    shade->matrix = fz_identity;
    shade->use_background = 0;
    shade->use_function = 1;
    shade->type = type;
    shade->u.l_or_r.extend[0] = extend0;
    shade->u.l_or_r.extend[1] = extend1;

    shade->u.l_or_r.coords[0][0] = x0;
    shade->u.l_or_r.coords[0][1] = y0;
    shade->u.l_or_r.coords[0][2] = r0;
    shade->u.l_or_r.coords[1][0] = x1;
    shade->u.l_or_r.coords[1][1] = y1;
    shade->u.l_or_r.coords[1][2] = r1;
    
    qsort(stops, stopCount, sizeof(shade_stop), cmp_shade_stop);
    sample_gradient_stops(m_CTX,shade,stops, stopCount);
    return shade;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::deleteShade(fz_shade * shade)
{
    if ( m_CTX == NULL ) {
        return;
    }
    if ( shade != NULL ) {
        fz_drop_shade(m_CTX, shade);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::renderMask(fz_image *image,int Gray)
{
    fz_pixmap * imagePixMap = NULL;
    do {
        if ( image == NULL ) {
            break;
        }
        
        imagePixMap = fz_get_pixmap_from_image(m_CTX, image, NULL, NULL, NULL, NULL);
        if ( imagePixMap == NULL ) {
            break;
        }
        
        int image_w = imagePixMap->w;
        int image_h = imagePixMap->h;
        if (image_w < 0 || image_h < 0) {
            break;
        }
        CreateImage(image_w,image_h,255,255,255,0);
        if ( m_PixMap == NULL ) {
            break;
        }
        
        int image_n = imagePixMap->n;
        ptrdiff_t image_stride = imagePixMap->stride;
        ptrdiff_t image_len = (ptrdiff_t)image_w * image_n;
        image_stride -= image_len;
        
        unsigned char *image_s = imagePixMap->samples;
        
        int newImage_n = m_PixMap->n;
        ptrdiff_t newImage_stride = m_PixMap->stride;
        ptrdiff_t mewImage_len = (ptrdiff_t)m_PixMap->w * newImage_n;
        newImage_stride -= mewImage_len;
        
        unsigned char * newImage_s = m_PixMap->samples;
        
        unsigned char R = 0;
        unsigned char G = 0;
        unsigned char B = 0;
        unsigned char A = 0;
        
        int x, y;
        
        for (y = 0; y < imagePixMap->h; y++)
        {
            for (x = 0; x < imagePixMap->w; x++)
            {
                R = *image_s++;
                G = *image_s++;
                B = *image_s++;
                if ( image_n == 4 ) {
                    A = *image_s++;
                }
                
                if ((R + G + B) / 3 >= Gray) {
                    *newImage_s++ = R;
                    *newImage_s++ = G;
                    *newImage_s++ = B;
                    if ( newImage_n == 4 ) {
                        *newImage_s++ = 0;
                    }
                } else {
                    *newImage_s++ = R;
                    *newImage_s++ = G;
                    *newImage_s++ = B;
                    if ( newImage_n == 4 ) {
                        if ( image_n == 4 ) {
                            *newImage_s++ = A;
                        } else {
                            *newImage_s++ = 255;
                        }
                    }
                }
            }
            image_s += image_stride;
            newImage_s += newImage_stride;
        }
    
    
    
    } while(false);
    
    if ( imagePixMap != NULL ) {
        fz_drop_pixmap(m_CTX, imagePixMap);
        imagePixMap = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::renderMask(const FZZBytes & imageData,int Gray)
{
    if ( imageData.getLen() <= 3) {
        return;
    }
    fz_buffer * imageBuffer = NULL;
    fz_image * image = NULL;
    fz_pixmap * imagePixMap = NULL;
    do {
        imageBuffer = fz_new_buffer_from_copied_data(m_CTX, imageData.getData(), imageData.getLen());
        if ( imageBuffer == NULL ) {
            break;
        }
        image = fz_new_image_from_buffer(m_CTX, imageBuffer);
        
        if ( image == NULL ) {
            break;
        }
        
        imagePixMap = fz_get_pixmap_from_image(m_CTX, image, NULL, NULL, NULL, NULL);
        if ( imagePixMap == NULL ) {
            break;
        }
        
        int image_w = imagePixMap->w;
        int image_h = imagePixMap->h;
        if (image_w < 0 || image_h < 0) {
            break;
        }
        CreateImage(image_w,image_h,255,255,255,0);
        if ( m_PixMap == NULL ) {
            break;
        }
        
        int image_n = imagePixMap->n;
        ptrdiff_t image_stride = imagePixMap->stride;
        ptrdiff_t image_len = (ptrdiff_t)image_w * image_n;
        image_stride -= image_len;
        
        unsigned char *image_s = imagePixMap->samples;
        
        int newImage_n = m_PixMap->n;
        ptrdiff_t newImage_stride = m_PixMap->stride;
        ptrdiff_t mewImage_len = (ptrdiff_t)m_PixMap->w * newImage_n;
        newImage_stride -= mewImage_len;
        
        unsigned char * newImage_s = m_PixMap->samples;
        
        unsigned char R = 0;
        unsigned char G = 0;
        unsigned char B = 0;
        unsigned char A = 0;
        
        int x, y;
        
        for (y = 0; y < imagePixMap->h; y++)
        {
            for (x = 0; x < imagePixMap->w; x++)
            {
                R = *image_s++;
                G = *image_s++;
                B = *image_s++;
                if ( image_n == 4 ) {
                    A = *image_s++;
                }
                
                if ((R + G + B) / 3 >= Gray) {
                    *newImage_s++ = R;
                    *newImage_s++ = G;
                    *newImage_s++ = B;
                    if ( newImage_n == 4 ) {
                        *newImage_s++ = 0;
                    }
                } else {
                    *newImage_s++ = R;
                    *newImage_s++ = G;
                    *newImage_s++ = B;
                    if ( newImage_n == 4 ) {
                        if ( image_n == 4 ) {
                            *newImage_s++ = A;
                        } else {
                            *newImage_s++ = 255;
                        }
                    }
                }
            }
            image_s += image_stride;
            newImage_s += newImage_stride;
        }
    
    
    
    } while(false);
    
    if ( imagePixMap != NULL ) {
        fz_drop_pixmap(m_CTX, imagePixMap);
        imagePixMap = NULL;
    }
    
    if ( image != NULL ) {
        fz_drop_image(m_CTX, image);
        image = NULL;
    }
    
    if ( imageBuffer != NULL ) {
        fz_drop_buffer(m_CTX, imageBuffer);
        imageBuffer = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::renderMask(const FZZBytes & imageData,const FZZBytes & maskImageData)
{
    if ( imageData.getLen() <= 3 || maskImageData.getLen() <= 3) {
        return;
    }
    
    fz_buffer * imageBuffer = NULL;
    fz_image * image = NULL;
    fz_pixmap * imagePixMap = NULL;
    fz_buffer * maskImageBuffer = NULL;
    fz_image * maskImage = NULL;
    fz_pixmap * maskImagePixMap = NULL;
    do {
        imageBuffer = fz_new_buffer_from_copied_data(m_CTX, imageData.getData(), imageData.getLen());
        if ( imageBuffer == NULL ) {
            break;
        }
        image = fz_new_image_from_buffer(m_CTX, imageBuffer);
        
        if ( image == NULL ) {
            break;
        }
        
        imagePixMap = fz_get_pixmap_from_image(m_CTX, image, NULL, NULL, NULL, NULL);
        if ( imagePixMap == NULL ) {
            break;
        }
        
        maskImageBuffer = fz_new_buffer_from_copied_data(m_CTX, maskImageData.getData(), maskImageData.getLen());
        if ( maskImageBuffer == NULL ) {
            break;
        }
        maskImage = fz_new_image_from_buffer(m_CTX, maskImageBuffer);
        if ( maskImage == NULL ) {
            break;
        }
        
        maskImagePixMap = fz_get_pixmap_from_image(m_CTX, maskImage, NULL, NULL, NULL, NULL);
        if ( maskImagePixMap == NULL ) {
            break;
        }
        
        
        int image_w = imagePixMap->w;
        int image_h = imagePixMap->h;
        int maskimage_w = maskImagePixMap->w;
        int maskimage_h = maskImagePixMap->h;
        if (image_w < 0 || image_h < 0 || maskimage_w != image_w || maskimage_h != image_h) {
            break;
        }
        CreateImage(image_w,image_h,255,255,255,0);
        if ( m_PixMap == NULL ) {
            break;
        }
        //----------------
        int image_n = imagePixMap->n;
        ptrdiff_t image_stride = imagePixMap->stride;
        ptrdiff_t image_len = (ptrdiff_t)image_w * image_n;
        image_stride -= image_len;
        unsigned char * image_s = imagePixMap->samples;
        //---------------------
        int maskimage_n = maskImagePixMap->n;
        ptrdiff_t maskimage_stride = maskImagePixMap->stride;
        ptrdiff_t maskimage_len = (ptrdiff_t)maskimage_w * maskimage_n;
        maskimage_stride -= maskimage_len;
        unsigned char * maskimage_s = maskImagePixMap->samples;
        //---------------------
        int newImage_n = m_PixMap->n;
        ptrdiff_t newImage_stride = m_PixMap->stride;
        ptrdiff_t mewImage_len = (ptrdiff_t)m_PixMap->w * newImage_n;
        newImage_stride -= mewImage_len;
        
        unsigned char * newImage_s = m_PixMap->samples;
        //------------------------
        unsigned char R = 0;
        unsigned char G = 0;
        unsigned char B = 0;
        unsigned char A = 0;
        
        int x, y;
        for (y = 0; y < imagePixMap->h; y++)
        {
            for (x = 0; x < imagePixMap->w; x++)
            {
                if ( maskimage_n == 1 ) {
                    R = G = B = *maskimage_s++;
                } else {
                    R = *maskimage_s++;
                    G = *maskimage_s++;
                    B = *maskimage_s++;
                    if ( maskimage_n == 4 ) {
                        A = *maskimage_s++;
                    }
                }
                if ((R + G + B) / 3 > 244) {
                    *newImage_s++ = *image_s++;
                    *newImage_s++ = *image_s++;
                    *newImage_s++ = *image_s++;
                    if ( newImage_n == 4 ) {
                        if ( image_n == 4 ) {
                            *newImage_s++ = *image_s++;
                        } else {
                            *newImage_s++ = 255;
                        }
                    } else {
                        if ( image_n == 4 ) {
                            image_s++;
                        }
                    }
                    
                } else {
                    *newImage_s++ = *image_s++;
                    *newImage_s++ = *image_s++;
                    *newImage_s++ = *image_s++;
                    if ( newImage_n == 4 ) {
                        *newImage_s++ = 0;
                    }
                    if ( image_n == 4 ) {
                        image_s++;
                    }
                }
                
                
                
            }
            image_s += image_stride;
            newImage_s += newImage_stride;
            maskimage_s += maskimage_stride;
        }
    
    
    
    } while(false);
    
    if ( maskImagePixMap != NULL ) {
        fz_drop_pixmap(m_CTX, maskImagePixMap);
        maskImagePixMap = NULL;
    }
    
    if ( maskImage != NULL ) {
        fz_drop_image(m_CTX, maskImage);
        maskImage = NULL;
    }
    
    if ( maskImageBuffer != NULL ) {
        fz_drop_buffer(m_CTX, maskImageBuffer);
        maskImageBuffer = NULL;
    }
    
    if ( imagePixMap != NULL ) {
        fz_drop_pixmap(m_CTX, imagePixMap);
        imagePixMap = NULL;
    }
    
    if ( image != NULL ) {
        fz_drop_image(m_CTX, image);
        image = NULL;
    }
    
    if ( imageBuffer != NULL ) {
        fz_drop_buffer(m_CTX, imageBuffer);
        imageBuffer = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::setAlpha(unsigned char alpha)
{
    fz_pixmap *pix = m_PixMap;
    unsigned char *s;
    int w, h, n;
    ptrdiff_t stride, len;
    //int alpha = pix->alpha;
    
    if ( pix == NULL || pix->n != 4 ) {
        return;
    }

    w = pix->w;
    h = pix->h;
    if (w < 0 || h < 0)
        return;

    n = pix->n;
    
    stride = pix->stride;
    len = (ptrdiff_t)w * n;

    s = pix->samples;
    
    int x, y;
    stride -= len;
    for (y = 0; y < pix->h; y++)
    {
        for (x = 0; x < pix->w; x++)
        {
            if ( *s == *(s+1) && *s == *(s+2) && *s == 0 ) {
                *s++ = 255;
                *s++ = 255;
                *s++ = 255;
            } else {
                s = s + 3;
            }
            *s++ = alpha;
        }
        s += stride;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::SplitImage(const FZZBytes & imageData,string outimageType,int n,bool ishorizontal,vector<FZZBytes *> &outImages,size_t* outSrcImageWidth,size_t* outSrcImageHeight)
{
    fz_context * ctx = this->getContext();
    FZZImageUtil ImageUtil(ctx);
    ImageUtil.LoadImage(imageData);
    int width = ImageUtil.getWidth();
    int height = ImageUtil.getHeight();
    if ( outSrcImageWidth != NULL ) {
        *outSrcImageWidth = width;
    }
    if ( outSrcImageHeight != NULL ) {
        *outSrcImageHeight = height;
    }
    
    FZZBytes * tempImageData = NULL;
    if ( ishorizontal ) {
        int sw = width / n;
        int yu = width - sw * n;
        int yusetp = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {//last
                tempImageData = new FZZBytes();
                if ( tempImageData != NULL ) {
                    GenSubImage(ImageUtil,outimageType,i * sw + yusetp, 0, width - (i * sw + yusetp), height,*tempImageData);
                    outImages.push_back(tempImageData);
                }
                
            } else {//
                if (yu != 0) {
                    tempImageData = new FZZBytes();
                    if ( tempImageData != NULL ) {
                        GenSubImage(ImageUtil,outimageType,i * sw + yusetp, 0, sw + 1, height,*tempImageData);
                        outImages.push_back(tempImageData);
                    }
                    
                    yu--;
                    yusetp++;
                } else {
                    tempImageData = new FZZBytes();
                    if ( tempImageData != NULL ) {
                        GenSubImage(ImageUtil,outimageType,i * sw + yusetp, 0, sw, height,*tempImageData);
                        outImages.push_back(tempImageData);
                    }
                }
            }

        }
    } else {
        int hh = height / n;
        int yu = height - hh * n;
        int yusetp = 0;
        for (int i = 0; i < n; i++) {
          
            if (i == n - 1) {//last
                tempImageData = new FZZBytes();
                if ( tempImageData != NULL ) {
                    GenSubImage(ImageUtil,outimageType,0,i * hh + yusetp, width, height - (i * hh + yusetp),*tempImageData);
                    outImages.push_back(tempImageData);
                }
            } else {//
                if (yu != 0) {
                    tempImageData = new FZZBytes();
                    if ( tempImageData != NULL ) {
                        GenSubImage(ImageUtil,outimageType,0,i * hh + yusetp, width, hh+1,*tempImageData);
                        outImages.push_back(tempImageData);
                    }
                    yu--;
                    yusetp++;
                } else {
                    tempImageData = new FZZBytes();
                    if ( tempImageData != NULL ) {
                        GenSubImage(ImageUtil,outimageType,0,i * hh + yusetp, width, hh,*tempImageData);
                        outImages.push_back(tempImageData);
                    }
                    
                }
            }


        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZImageUtil::GenSubImage(FZZImageUtil & srcImage,string outimageType,int posX,int posY,int sizeX,int sizeY,FZZBytes & outimage)
{
    fz_context * ctx = this->getContext();
    FZZImageUtil subImage(ctx);
    subImage.CreateImage(sizeX,sizeY,0xFF,0xFF,0xFF,0x00);

    FZZMatrix matrix;
    matrix.postScale(srcImage.getWidth(), srcImage.getHeight());
    matrix.postTranslate(-posX, -posY);
    subImage.DrawFillImage(srcImage.getImage(), matrix.getMatrix(), 1);

//    FZZImageUtil subImage(ctx);
//    subImage.CreateImage(300,300,0xFF,0xFF,0xFF,0x00);
//
//    if ( subImage.getPixmap() == NULL || srcImage.getPixmap() == NULL) {
//        return;
//    }
//
//    fz_irect cliprect = {posX, posY, (posX+sizeX), (posY+sizeY)};
//
//    fz_default_colorspaces *defcs = fz_new_default_colorspaces(ctx);
//
//    fz_copy_pixmap_rect(ctx, subImage.getPixmap(), srcImage.getPixmap(), cliprect,  defcs);
//
//    if ( defcs != NULL ) {
//        fz_drop_default_colorspaces(ctx, defcs);
//    }
    
    if ( outimageType == "PNG" ) {
        outimage = subImage.PngEncode();
    } else if (outimageType == "JPG") {
        outimage = subImage.JPGEncode();
    } else {
        outimage = subImage.PngEncode();
    }

}
//-----------------------------------------------------------------------------------------------------------------
