//
//  Created by zizheng fan on 2024/09/20.
//
#ifndef FZZSVGUTIL_H
#define FZZSVGUTIL_H

#include "basic/FZZObject.h"

class FZZSVGUtil : public FZZObject
{
public:
    FZZSVGUtil();
    FZZSVGUtil(fz_context * ctx);
    virtual ~FZZSVGUtil();
    
    
public:
    void ClearSVG();
    void CreateSVG(float page_width, float page_height, int text_format, int reuse_images);
    FZZBytes SVGEncode();
    
    
    
    float getWidth();
    float getHeight();
    
    void DrawFillPath(fz_path * path,int even_odd,fz_matrix ctm, const float *color, float alpha);
    void DrawStrokePath(fz_path * path,fz_stroke_state* stroke,fz_matrix ctm, const float *color, float alpha);
    
    void DrawFillText(fz_text *text, fz_matrix ctm,
                       const float *color, float alpha);
    void DrawStrokeText(fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
                         const float *color, float alpha);
    void DrawIgnoreText(fz_text *text, fz_matrix ctm);
    
    void DrawFillImage(fz_image *image,fz_matrix ctm, float alpha);
    void DrawFillImageMask(fz_image *image, fz_matrix ctm,
                           fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params);
    
    void DrawFillShade(fz_shade *shade, fz_matrix ctm, float alpha, fz_color_params color_params);
    
    
    void POPClip();
    void ClipPath(fz_path *path, int even_odd, fz_matrix ctm, fz_rect scissor);
    void ClipStrokePath(fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor);
    void ClipText(fz_text *text, fz_matrix ctm, fz_rect scissor);
    void ClipStrokeText(fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor);
    void ClipImageMask(fz_image *image, fz_matrix ctm, fz_rect scissor);
    
    void BeginMask(fz_rect bbox, int luminosity, fz_colorspace *colorspace, const float *color, fz_color_params color_params);
    void EndMask(fz_function *tr);
    //isolated: 布尔值（0或1），指定是否将图形组隔离。隔离意味着组内的效果不会影响到其他图形组。
    //knockout: 布尔值（0或1），指定是否启用组合图形的抠出效果。
    void BeginGroup(fz_rect bbox, fz_colorspace *cs, int isolated, int knockout, int blendmode, float alpha);
    void EndGroup();
    void BeginTile(fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm, int id);
    void EndTile();
    
    
public:
    
    
private:
    FZZSVGUtil(const FZZSVGUtil& obj);
    
private:
    bool DrawCheck();
private:
    fz_device * m_Dev;
    fz_buffer * m_SvgBuffer;
    fz_output * m_SvgOutPut;
    float m_PageWidth;
    float m_PageHeight;

};

#endif //FZZSVGUTIL_H
