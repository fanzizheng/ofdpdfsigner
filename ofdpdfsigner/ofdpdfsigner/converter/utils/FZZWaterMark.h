//
//  Created by zizheng fan on 2024/07/18.
//
#ifndef FZWATERMARK_H
#define FZWATERMARK_H

#include "converter/utils/FZZImageUtil.h"
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"
#include "basic/FZZPath.h"
class FZZWaterMark
{
public:
    typedef enum {
        TYPE_LEFT = 1,
        TYPE_RIGHT = 2,
        TYPE_CENTER = 3
    } TYPE_TEXTALIGN;
public:
    FZZWaterMark();
    virtual ~FZZWaterMark();
    
public:
    //isTile 是否平铺,
    //true 平铺： pageWidth,pageHeight 必须大于零;beginPosX,beginPosY 是最左侧单元起始位置,但因为平铺是文档对角线长度做正方形平铺，因此beginPosX,beginPosY值偏小时看不到效果
    //false 不平铺：pageWidth,pageHeight 为零时，按实际大小产生图片；pageWidth,pageHeight 大于零时,beginPosX,beginPosY 单元起始位置,这个位置是旋转后的左上点，-1和-1为居中
    //isImage ：图片时，仅仅使用 bool isTile,bool isImage,double pageWidth,double pageHeight,double beginPosX,double beginPosY ,double rotate这几个参数
    //scaled : 图片方式时忽略此参数 放大缩小，对于1.0时，文档的放大将导致水印的失真，放大几倍取决于文档在放大几倍时失真的可接受范围，一般 2.0可以支持文档的400%的放大。这个值越大，将导致性能损失和文档的大小几何倍增加
    //         在盖章时，显示的大小请依旧使用 文档页面的大小。
    //horizontalSpacing 横向间距
    //image_width,image_height 为毫米
    FZZBytes getWaterMarkImage(bool isTile,bool isImage,double pageWidth,double pageHeight,double beginPosX,double beginPosY,
                            const unsigned char * const imageData,size_t imageDataLen,
                  FZZWaterMark::TYPE_TEXTALIGN textAlign,double horizontalSpacing,double verticalSpacing,
                  string firstLineText,string firstLineText_FontName,double firstLineText_fontSize,bool isBlob_first,bool isItalic_first,double firstLineText_color_R,
                  double firstLineText_color_G,double firstLineText_color_B,double firstLineText_alpha,
                  double lineSpacing0_1,
                  string secondLineText,string secondLineText_FontName,double secondLineText_fontSize,bool isBlob_second,bool isItalic_second,double secondLineText_color_R,
                  double secondLineText_color_G,double secondLineText_color_B,double secondLineText_alpha,
                  double lineSpacing1_2,
                  string thirdLineText,string thirdLineText_FontName,double thirdLineText_fontSize,bool isBlob_third,bool isItalic_third,double thirdLineText_color_R,
                  double thirdLineText_color_G,double thirdLineText_color_B,double thirdLineText_alpha,
                  double rotate,double scaled,/*out*/double & image_width,/*out*/double & image_height);
    
    
protected:
    
    void getLinePath(string LineText,FZZFontCache* fontCache,double LineText_fontSize,bool isItalic,FZZPath & linepath);
    
    void getDrawPath(FZZPath &  linepath,bool isTile,double beginPosX,double beginPosY,FZZWaterMark::TYPE_TEXTALIGN textAlign,double maxWidth,
                            double pagewidth, double pageheight,double rotate,double BeginY,double horizontalSpacing,double verticalSpacing,/*out*/FZZPath &  dstPath);
    
    void drawText_WaterMark(FZZImageUtil & graphics,FZZPath &  pagePath,
                            double LineText_fontSize,bool isBlob,double LineText_color_R,
                            double LineText_color_G,double LineText_color_B,double LineText_alpha);
    
    FZZBytes drawImage(bool isTile,double pageWidth,double pageHeight,double beginPosX,double beginPosY,
                   const unsigned char * const imageData,size_t imageDataLen,double rotate,/*out*/double & image_width,/*out*/double & image_height);
    
protected:
    fz_rect FZCalculateRotatedBounds(int width,int height, float angle);
private:
   
    
};

#endif //WATERMARK_H
