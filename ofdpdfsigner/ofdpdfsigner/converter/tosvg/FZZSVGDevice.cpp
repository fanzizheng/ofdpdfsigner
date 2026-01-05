//
//  Created by zizheng fan on 2024/09/18.
//
#include "ofd/FZZOFDConst.h"
#include "FZZSVGDevice.h"
#include "converter/utils/FZZCommonUtil.h"
#include "converter/utils/FZZImageUtil.h"
#include "basic/FZZMatrix.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define LINEWIDTH_SCALE 0.27


//-----------------------------------------------------------------------------------------------------------------
//main func
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_close_device(fz_context *ctx, fz_device *dev)
{
    //last close
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_close_device(ctx, pdev->svgdev);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_drop_device(fz_context *ctx, fz_device *dev)
{
    //free
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_drop_device(ctx, pdev->svgdev);
    }
   
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_fill_path(fz_context *ctx, fz_device *dev, const fz_path *path, int even_odd, fz_matrix ctm,
    fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_fill_path(ctx, pdev->svgdev, path,  even_odd, ctm, colorspace, color, alpha, color_params);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_stroke_path(fz_context *ctx, fz_device *dev, const fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm,
    fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_stroke_path(ctx, pdev->svgdev, path, stroke, ctm,colorspace, color, alpha, color_params);
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_clip_path(fz_context *ctx, fz_device *dev, const fz_path *path, int even_odd, fz_matrix ctm, fz_rect scissor)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_clip_path(ctx, pdev->svgdev, path, even_odd, ctm, scissor);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_clip_stroke_path(fz_context *ctx, fz_device *dev, const fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{

    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_clip_stroke_path(ctx, pdev->svgdev, path, stroke, ctm, scissor);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_fill_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_fill_text(ctx, pdev->svgdev, text, ctm,colorspace, color, alpha, color_params);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_stroke_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_stroke_text(ctx, pdev->svgdev, text, stroke,ctm,colorspace, color, alpha, color_params);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_clip_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm, fz_rect scissor)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_clip_text(ctx, pdev->svgdev, text, ctm, scissor);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_clip_stroke_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_clip_stroke_text(ctx, pdev->svgdev, text, stroke,ctm, scissor);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_ignore_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    if ( pdev->svgdev != NULL ) {
        fz_ignore_text(ctx, pdev->svgdev, text, ctm);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_fill_image(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    if ( pdev->svgdev != NULL ) {
        
        if ( pdev->isstamp ) {
            FZZImageUtil imageUtil(ctx);
            imageUtil.renderMask(image, 244);
            fz_image * image_temp = imageUtil.getImage();
            if ( image_temp != NULL ) {
                fz_fill_image(ctx, pdev->svgdev, image_temp, ctm, 0.86, color_params);
            } else {
                fz_fill_image(ctx, pdev->svgdev, image, ctm, alpha, color_params);
            }
        } else {
            fz_fill_image(ctx, pdev->svgdev, image, ctm, alpha, color_params);
        }
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_fill_shade(fz_context *ctx, fz_device *dev, fz_shade *shade, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_fill_shade(ctx, pdev->svgdev, shade, ctm, alpha, color_params);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_fill_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_fill_image_mask(ctx, pdev->svgdev, image, ctm, colorspace, color, alpha, color_params);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_clip_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, fz_rect scissor)
{
    
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_clip_image_mask(ctx, pdev->svgdev, image, ctm, scissor);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_pop_clip(fz_context *ctx, fz_device *dev)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_pop_clip(ctx, pdev->svgdev);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_begin_mask(fz_context *ctx, fz_device *dev, fz_rect bbox, int luminosity, fz_colorspace *colorspace, const float *color, fz_color_params color_params)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_begin_mask(ctx, pdev->svgdev, bbox, luminosity, colorspace, color, color_params);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_end_mask(fz_context *ctx, fz_device *dev,fz_function *tr)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_end_mask_tr(ctx, pdev->svgdev,tr);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_begin_group(fz_context *ctx, fz_device *dev, fz_rect bbox, fz_colorspace *cs, int isolated, int knockout, int blendmode, float alpha)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_begin_group(ctx, pdev->svgdev,bbox, cs, isolated, knockout, blendmode, alpha);
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_end_group(fz_context *ctx, fz_device *dev)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_end_group(ctx, pdev->svgdev);
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static int fzsvg_dev_begin_tile(fz_context *ctx, fz_device *dev, fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm, int id)
{
    int ret = 0;
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return ret;
    }
    
    if ( pdev->svgdev != NULL ) {
        ret = fz_begin_tile_id(ctx, pdev->svgdev, area,  view,  xstep,  ystep,  ctm,  id);
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
static void fzsvg_dev_end_tile(fz_context *ctx, fz_device *dev)
{
    fzsvg_device *pdev = (fzsvg_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->svgdev != NULL ) {
        fz_end_tile(ctx, pdev->svgdev);
    }
}
//-----------------------------------------------------------------------------------------------------------------
fz_device * new_fzsvg_device(fz_context *ctx, fz_output *out, float page_width, float page_height, int text_format, int reuse_images)
{
    fzsvg_device *dev = fz_new_derived_device(ctx, fzsvg_device);
    if ( dev == NULL ) {
        return NULL;
    }
    
    dev->super.close_device = fzsvg_dev_close_device;
    dev->super.drop_device = fzsvg_dev_drop_device;
    
    dev->super.fill_path = fzsvg_dev_fill_path;
    dev->super.stroke_path = fzsvg_dev_stroke_path;
    dev->super.clip_path = fzsvg_dev_clip_path;
    dev->super.clip_stroke_path = fzsvg_dev_clip_stroke_path;

    dev->super.fill_text = fzsvg_dev_fill_text;
    dev->super.stroke_text = fzsvg_dev_stroke_text;
    dev->super.clip_text = fzsvg_dev_clip_text;
    dev->super.clip_stroke_text = fzsvg_dev_clip_stroke_text;
    dev->super.ignore_text = fzsvg_dev_ignore_text;

    dev->super.fill_shade = fzsvg_dev_fill_shade;
    dev->super.fill_image = fzsvg_dev_fill_image;
    dev->super.fill_image_mask = fzsvg_dev_fill_image_mask;
    dev->super.clip_image_mask = fzsvg_dev_clip_image_mask;

    dev->super.pop_clip = fzsvg_dev_pop_clip;

    dev->super.begin_mask = fzsvg_dev_begin_mask;
    dev->super.end_mask = fzsvg_dev_end_mask;
    dev->super.begin_group = fzsvg_dev_begin_group;
    dev->super.end_group = fzsvg_dev_end_group;

    dev->super.begin_tile = fzsvg_dev_begin_tile;
    dev->super.end_tile = fzsvg_dev_end_tile;

        
        //------test begin----------
        
//        dev->super.close_device = OFD_ofd_dev_close_device;
//        dev->super.drop_device = OFD_ofd_dev_drop_device;
//
//        dev->super.fill_path = NULL;
//        dev->super.stroke_path = NULL;
//        dev->super.clip_path = NULL;
//        dev->super.clip_stroke_path = NULL;
//
//        dev->super.fill_text = NULL;
//        dev->super.stroke_text = NULL;
//        dev->super.clip_text = NULL;
//        dev->super.clip_stroke_text = NULL;
//        dev->super.ignore_text = NULL;
//
//        dev->super.fill_shade = NULL;
//        dev->super.fill_image = NULL;
//        dev->super.fill_image_mask = NULL;
//        dev->super.clip_image_mask = NULL;
//
//        dev->super.pop_clip = NULL;
//
//        dev->super.begin_mask = NULL;
//        dev->super.end_mask = NULL;
//        dev->super.begin_group = NULL;
//        dev->super.end_group = NULL;
//
//        dev->super.begin_tile = NULL;
//        dev->super.end_tile = NULL;
//

        
        //------test end----------
    
    //dev->ishavestamp = false;
    dev->isstamp = false;
    
    dev->svgdev = fz_new_svg_device(ctx,out,page_width, page_height, text_format, reuse_images);
    if ( dev->svgdev == NULL ) {
        fz_drop_device(ctx, (fz_device*)dev);
        return NULL;
    }
    
    return (fz_device*)dev;
}
//-----------------------------------------------------------------------------------------------------------------
