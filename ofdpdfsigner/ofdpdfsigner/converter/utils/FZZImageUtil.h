//
//  Created by zizheng fan on 2024/07/16.
//
#ifndef FZZIMAGEUTIL_H
#define FZZIMAGEUTIL_H

#include "basic/FZZObject.h"

struct shade_stop
{
    float offset;
    float r, g, b, a;
    int index;
};



class FZZImageUtil : public FZZObject
{
public:
    FZZImageUtil();
    FZZImageUtil(fz_context * ctx);
    virtual ~FZZImageUtil();
    
    
public:
    void ClearImage();
    void CreateImage(int width,int height,unsigned char R,unsigned char G,unsigned char B, unsigned char alpha);
    bool LoadImage(const unsigned char * const data, size_t datalen);
    bool LoadImage(const FZZBytes & imageData);
    bool LoadImage(string imageFileName);
    bool LoadImage(fz_image *image);
    FZZBytes PngEncode();
    FZZBytes JPGEncode();
    
    fz_image * getImage();
    fz_pixmap * getPixmap();
    
    int getWidth();
    int getHeight();
    
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
    
    //Gray 要变成透明的颜色
    void renderMask(fz_image *image,int Gray);
    void renderMask(const FZZBytes & imageData,int Gray);
    void renderMask(const FZZBytes & imageData,const FZZBytes & maskImageData);
    
    
    void setAlpha(unsigned char alpha);
    
    //free outImages
    void SplitImage(const FZZBytes & imageData,string outimageType,int n,bool ishorizontal,vector<FZZBytes *> &outImages,size_t* outSrcImageWidth,size_t* outSrcImageHeight);
    
    void deleteAlpha(fz_pixmap *srcpix,fz_pixmap *destpix);
public:
    //free
    //目前仅支持 FZ_LINEAR 和 FZ_RADIAL
    //type : FZ_LINEAR（线性渐变色） or FZ_RADIAL（径向渐变）; extend 是否延展；FZ_LINEAR 时 r0和r1为 0；FZ_RADIAL：r0 起始半径，r1结束半径;
    //FZ_LINEAR 和 FZ_RADIAL： extend0 和 extend1 相等
    //径向渐变用于指定径向渐变（radial gradient）。径向渐变是一种颜色渐变的效果，从一个点开始向外辐射，颜色随着距离的增加而逐渐改变。
    fz_shade * newShade(int type,int extend0,int extend1,float x0,float y0,float r0,float x1,float y1,float r1,shade_stop * stops,int stopCount);
    void deleteShade(fz_shade * shade);
    
private:
    FZZImageUtil(const FZZImageUtil& obj);
    void clear_pixmap_with_value(fz_context *ctx, fz_pixmap *pix, unsigned char R,unsigned char G,unsigned char B, unsigned char alpha);
    
    void GenSubImage(FZZImageUtil & srcImage,string outimageType,int posX,int posY,int sizeX,int sizeY,FZZBytes & outimage);
private:
    bool DrawCheck();
private:

    fz_pixmap * m_PixMap;
    fz_device * m_Dev;
    fz_image * m_Image;
    fz_buffer * m_ImageBuffer;

};

#endif //FZZIMAGEUTIL_H
