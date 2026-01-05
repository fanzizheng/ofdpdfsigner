//
//  Created by zizheng fan on 2024/07/18.
//
#include "basic/FZZConst.h"
#include "converter/utils/FZZWaterMark.h"
#include "basic/FZZString.h"
#include "converter/utils/FZZCommonUtil.h"

#include "fzfont/FZZFontConfig.h"
#include "fzfont/FZZTempFontCache.h"
#include "fzfont/FZZSystemFontCache.h"
#include "basic/FZZMatrix.h"

#include "mupdf/fitz/device.h"
#include "mupdf/fitz/geometry.h"
#define _USE_MATH_DEFINES
#include "math.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWaterMark**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWaterMark::FZZWaterMark()
{
    //DLOG("FZZWaterMark()");
    FZZConst::addClassCount("FZZWaterMark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWaterMark::~FZZWaterMark()
{
    //DLOG("~FZZWaterMark()");
    FZZConst::delClassCount("FZZWaterMark");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZWaterMark::getWaterMarkImage(bool isTile,bool isImage,double pageWidth,double pageHeight,double beginPosX,double beginPosY,
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
              double rotate,double scaled,/*out*/double & image_width,/*out*/double & image_height)
{
    FZZBytes outData;
    
    FZZImageUtil fzImageUtil;
    
    fz_context * ctx = fzImageUtil.getContext();
    if ( ctx == NULL ) {
        return outData;
    }
    fz_try(ctx) {
    FZZFontCache* fontCache_first = NULL;
    FZZFontCache* fontCache_second = NULL;
    FZZFontCache* fontCache_third = NULL;
    
    FZZPath linepath_first(ctx);
    FZZPath linepath_second(ctx);
    FZZPath linepath_third(ctx);
    
    double textWidth_first = 0;
    double textHeight_first = 0;
    double textWidth_second = 0;
    double textHeight_second = 0;
    double textWidth_third = 0;
    double textHeight_third = 0;
    double textWidthMax = 0;
    
    fz_rect pathrect = {0,0,0,0};
        
    do {
        if ( isImage ) {
            outData = drawImage(isTile, pageWidth, pageHeight, beginPosX, beginPosY,
                                imageData, imageDataLen,rotate,image_width,image_height);
            break;
        }
        
        image_width = 0;
        image_height = 0;
        if ( firstLineText.empty() ) {
            break;
        }

        if ( scaled <= 1 ) {
            scaled = 1;
        }
        
        firstLineText_fontSize = firstLineText_fontSize*scaled;
        secondLineText_fontSize = secondLineText_fontSize*scaled;
        thirdLineText_fontSize = thirdLineText_fontSize*scaled;


        horizontalSpacing = horizontalSpacing*scaled;

        verticalSpacing = verticalSpacing*scaled;
        lineSpacing0_1 = lineSpacing0_1*scaled;
        lineSpacing1_2 = lineSpacing1_2*scaled;

        if ( !(!isTile && beginPosX == -1 && beginPosY == -1) ) {
            beginPosX = beginPosX*scaled;
            beginPosY = beginPosY*scaled;
        }
        
        fontCache_first = FZZConst::g_FZSystemFontList.findFont(firstLineText_FontName);
        if ( fontCache_first == NULL ) {
            break;
        }
        getLinePath(firstLineText,fontCache_first,firstLineText_fontSize,isItalic_first,linepath_first);
        pathrect = linepath_first.getBounds();
        textWidth_first = pathrect.x1 - pathrect.x0;
        textHeight_first = pathrect.y1 - pathrect.y0;

        if ( !secondLineText.empty() ) {
            if ( secondLineText_FontName == firstLineText_FontName ) {
                //font_second = font_first;
                fontCache_second = fontCache_first;
            } else {
                fontCache_second = FZZConst::g_FZSystemFontList.findFont(secondLineText_FontName);
                if ( fontCache_second == NULL ) {
                    break;
                }
            }

            getLinePath(secondLineText,fontCache_second,secondLineText_fontSize,isItalic_second,linepath_second);
            pathrect = linepath_second.getBounds();
            textWidth_second = pathrect.x1 - pathrect.x0;
            textHeight_second = pathrect.y1 - pathrect.y0;
        }

        if ( !thirdLineText.empty() ) {
            if ( thirdLineText_FontName == firstLineText_FontName ) {
                //font_third = font_first;
                fontCache_third = fontCache_first;
            } else if ( thirdLineText_FontName == secondLineText_FontName ) {
                //font_third = font_second;
                fontCache_third = fontCache_second;
            } else {
                fontCache_third = FZZConst::g_FZSystemFontList.findFont(thirdLineText_FontName);
                if ( fontCache_third == NULL ) {
                    break;
                }
            }
           
            getLinePath(thirdLineText,fontCache_third,thirdLineText_fontSize,isItalic_third,linepath_third);
            pathrect = linepath_third.getBounds();
            textWidth_third = pathrect.x1 - pathrect.x0;
            textHeight_third = pathrect.y1 - pathrect.y0;
        }
        if (textWidth_first > textWidthMax) {
            textWidthMax = textWidth_first;
        }
        if (textWidth_second > textWidthMax) {
            textWidthMax = textWidth_second;
        }
        if (textWidth_third > textWidthMax) {
            textWidthMax = textWidth_third;
        }
        
        if ( !isTile && pageWidth == 0 && pageHeight == 0 ) {

            FZZPath pagePath1(ctx);
            FZZPath pagePath2(ctx);
            FZZPath pagePath3(ctx);
            FZZPath pagePath(ctx);
            
            getDrawPath(linepath_first,isTile, beginPosX, beginPosY,textAlign,textWidthMax,image_width,image_height,rotate,0.0f,textWidthMax+horizontalSpacing,
                        textHeight_first+lineSpacing0_1+
                        textHeight_second+lineSpacing1_2 +
                        textHeight_third+ verticalSpacing,pagePath1);
            
            
            
            if ( !secondLineText.empty() ) {

                getDrawPath(linepath_second,isTile, beginPosX, beginPosY,textAlign,textWidthMax,image_width,image_height,rotate,textHeight_first+lineSpacing0_1,textWidthMax+horizontalSpacing,
                            textHeight_first+lineSpacing0_1+
                            textHeight_second+lineSpacing1_2 +
                            textHeight_third+ verticalSpacing,pagePath2);
            }
            if ( !thirdLineText.empty() ) {

                getDrawPath(linepath_third,isTile, beginPosX, beginPosY,textAlign,textWidthMax,image_width,image_height,rotate,textHeight_first+lineSpacing0_1+
                            textHeight_second+lineSpacing1_2,textWidthMax+horizontalSpacing,
                            textHeight_first+lineSpacing0_1+
                            textHeight_second+lineSpacing1_2 +
                            textHeight_third+ verticalSpacing,pagePath3);
            }
           
            pagePath.addPath(pagePath1.getPath());
            pagePath.addPath(pagePath2.getPath());
            pagePath.addPath(pagePath3.getPath());
            
            fz_rect pathRect = pagePath.getBounds();

            double addValue = firstLineText_fontSize*0.4;

            FZZMatrix matrix;
            matrix.preTranslate(-pathRect.x0+addValue/2, -pathRect.y0+addValue/2);
            pagePath1.transform(matrix.getMatrix());
            pagePath2.transform(matrix.getMatrix());
            pagePath3.transform(matrix.getMatrix());
           
//            SkMatrix matrix;
//            matrix.postTranslate(-pathRect.left()+addValue/2, -pathRect.top()+addValue/2);
//            pagePath1.transform(matrix);
//            pagePath2.transform(matrix);
//            pagePath3.transform(matrix);
//
            image_width = pathRect.x1 - pathRect.x0 + addValue;
            image_height = pathRect.y1 - pathRect.y0 + addValue;

            fzImageUtil.CreateImage(image_width, image_height, 0, 0, 0, 0);
            drawText_WaterMark(fzImageUtil,pagePath1,firstLineText_fontSize,isBlob_first,firstLineText_color_R,
                                    firstLineText_color_G,firstLineText_color_B,firstLineText_alpha);

            if ( !secondLineText.empty() ) {
                drawText_WaterMark(fzImageUtil,pagePath2,secondLineText_fontSize,isBlob_second,secondLineText_color_R,
                                   secondLineText_color_G,secondLineText_color_B,secondLineText_alpha);

            }
            if ( !thirdLineText.empty() ) {
                drawText_WaterMark(fzImageUtil,pagePath3,thirdLineText_fontSize,isBlob_third,thirdLineText_color_R,
                                   thirdLineText_color_G,thirdLineText_color_B,thirdLineText_alpha);
            }

            
        } else {
            image_width = pageWidth*scaled;
            image_height = pageHeight*scaled;
            
            fzImageUtil.CreateImage(image_width, image_height, 0, 0, 0, 0);
            FZZPath pagePath(ctx);
            

            getDrawPath(linepath_first,isTile, beginPosX, beginPosY,textAlign,textWidthMax,image_width,image_height,rotate,0.0f,textWidthMax+horizontalSpacing,
                        textHeight_first+lineSpacing0_1+
                        textHeight_second+lineSpacing1_2 +
                        textHeight_third+ verticalSpacing,pagePath);

            drawText_WaterMark(fzImageUtil,pagePath,firstLineText_fontSize,isBlob_first,firstLineText_color_R,
                                    firstLineText_color_G,firstLineText_color_B,firstLineText_alpha);
            
                

            if ( !secondLineText.empty() ) {
                FZZPath pagePath2(ctx);
                
                   
                getDrawPath(linepath_second,isTile, beginPosX, beginPosY,textAlign,textWidthMax,image_width,image_height,rotate,textHeight_first+lineSpacing0_1,textWidthMax+horizontalSpacing,
                            textHeight_first+lineSpacing0_1+
                            textHeight_second+lineSpacing1_2 +
                            textHeight_third+ verticalSpacing,pagePath2);

                drawText_WaterMark(fzImageUtil,pagePath2,secondLineText_fontSize,isBlob_second,secondLineText_color_R,
                                   secondLineText_color_G,secondLineText_color_B,secondLineText_alpha);
                    

            }
            if ( !thirdLineText.empty() ) {
                FZZPath pagePath3(ctx);
                
                getDrawPath(linepath_third,isTile, beginPosX, beginPosY,textAlign,textWidthMax,image_width,image_height,rotate,textHeight_first+lineSpacing0_1+
                            textHeight_second+lineSpacing1_2,textWidthMax+horizontalSpacing,
                            textHeight_first+lineSpacing0_1+
                            textHeight_second+lineSpacing1_2 +
                            textHeight_third+ verticalSpacing,pagePath3);

                drawText_WaterMark(fzImageUtil,pagePath3,thirdLineText_fontSize,isBlob_third,thirdLineText_color_R,
                                   thirdLineText_color_G,thirdLineText_color_B,thirdLineText_alpha);
                    

            }
            
            
        }
        
        outData = fzImageUtil.PngEncode();
        image_width = FZZCommonUtil::pixelToMillimeters(image_width/scaled,72);
        image_height = FZZCommonUtil::pixelToMillimeters(image_height/scaled,72);
        
        
    } while(false);
    
    } fz_catch(ctx) {
        DLOG("gen svg error : %s",ctx->error.message);
    }
    
    return outData;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWaterMark::getLinePath(string LineText,FZZFontCache* fontCache,double LineText_fontSize,bool isItalic,FZZPath & linepath)
{
    if ( fontCache == NULL ) {
        return;
    }
    FZZString stcontent = LineText;
    int count = stcontent.length();
    double moveX = -LineText_fontSize;
    double tempfontsize_2 = LineText_fontSize/2;
    string itemchar = "";
    const FZZPath * fontPath = NULL;

    FZZMatrix matrix;
    
    for ( int i = 0; i < count; i++ ) {
        itemchar = stcontent[i];
        FzUnichar unichar = FZZConst::Utf8ToUtf32LE(itemchar);
        if ( unichar == 32 ) {
            moveX += tempfontsize_2;
            continue;
        } else if ( unichar > 127 ) {
            moveX += LineText_fontSize;
        } else {
            moveX += tempfontsize_2;
        }
        
        FzGlyphID charGlyphid = fontCache->unicharToGlyph(unichar);
        fontPath = fontCache->getPath(charGlyphid);
        if ( fontPath == NULL ) {
            continue;
        }
        
        matrix.reset();
        if ( isItalic ) {
            matrix.postSkew(-0.4, 0);
        }
        matrix.preScale(LineText_fontSize,LineText_fontSize);
        matrix.postTranslate(moveX, LineText_fontSize);
        
        linepath.addPath(((FZZPath *)fontPath)->getPath(), matrix.getMatrix());
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWaterMark::getDrawPath(FZZPath &  linepath,bool isTile,double beginPosX,double beginPosY,FZZWaterMark::TYPE_TEXTALIGN textAlign,double maxWidth,
                        double pagewidth, double pageheight,double rotate,double BeginY,double horizontalSpacing,double verticalSpacing,/*out*/FZZPath &  dstPath)
{
    FZZMatrix matrix;
    double moveX = 0,moveY = 0;
    
    fz_rect pathRect = linepath.getBounds();
    float pathRect_width = pathRect.x1 - pathRect.x0;
    
    switch (textAlign) {
        case TYPE_TEXTALIGN::TYPE_LEFT:
            moveX = 0;
            break;
        case TYPE_TEXTALIGN::TYPE_RIGHT:
            moveX = maxWidth - pathRect_width;
            break;
        case TYPE_TEXTALIGN::TYPE_CENTER:
            moveX = (maxWidth - pathRect_width)/2;
            break;
        default:
            moveX = 0;
            break;
    }
    
    moveY = BeginY;
    
    if ( isTile ) {
        
        double temppagewidth = sqrt(pagewidth*pagewidth + pageheight*pageheight);
        double temppageheight = temppagewidth;
        
        while (true) {
            
            matrix.reset();
            matrix.preTranslate(moveX, moveY);
            
          
            dstPath.addPath(linepath.getPath(),matrix.getMatrix());
            
            
            moveX += horizontalSpacing;
            if ( moveX > temppagewidth ) {
                moveY += verticalSpacing;
                switch (textAlign) {
                    case TYPE_TEXTALIGN::TYPE_LEFT:
                        moveX = 0;
                        break;
                    case TYPE_TEXTALIGN::TYPE_RIGHT:
                        moveX = maxWidth - pathRect_width;
                        break;
                    case TYPE_TEXTALIGN::TYPE_CENTER:
                        moveX = (maxWidth - pathRect_width)/2;
                        break;
                    default:
                        moveX = 0;
                        break;
                }
                if ( moveY > temppageheight ) {
                    break;
                }
            }
            
        }
        
        matrix.reset();
        
        matrix.postRotate((float)rotate,(float)temppagewidth/2,(float)temppageheight/2);
        matrix.postTranslate( -(temppagewidth - pagewidth)/2, -(temppageheight-pageheight)/2);
        matrix.postTranslate(beginPosX, beginPosY);
        
        
        dstPath.transform(matrix.getMatrix());
    } else {
        
        matrix.reset();
        matrix.preTranslate(moveX, moveY);
        dstPath.addPath(linepath.getPath(),matrix.getMatrix());
        
        pathRect = dstPath.getBounds();
        float pathRect_height = pathRect.y1 - pathRect.y0;
        matrix.reset();
        if ( beginPosX == -1 && beginPosY == -1 ) {
            matrix.postRotate(rotate);
            if ( rotate <= 0 ) {
                matrix.postTranslate((pagewidth - maxWidth)/2, (pageheight-pathRect_height)/2);
            } else {
                matrix.postTranslate((pagewidth - maxWidth)/2, (pageheight)/2-pathRect_height*2);
            }
        } else {
            matrix.postRotate(rotate);
            if (pagewidth > 0 && pageheight > 0) {
                matrix.postTranslate(beginPosX, beginPosY);
            } else {
                //dstPath.transform(matrix);
                //pathRect = dstPath.getBounds();
                //matrix.reset();
                //matrix.postTranslate(-pathRect.left(), -pathRect.top());
            }
            
            
            
        }
        dstPath.transform(matrix.getMatrix());
        
         
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWaterMark::drawText_WaterMark(FZZImageUtil & graphics,FZZPath &  pagePath,
                                   double LineText_fontSize,bool isBlob,double LineText_color_R,
                                   double LineText_color_G,double LineText_color_B,double LineText_alpha)
{
    FZZMatrix matrix;
    float color[] = { 0.0, 0.0, 0.0 };
    color[0] = (float)LineText_color_R/255.0;
    color[1] = (float)LineText_color_G/255.0;
    color[2] = (float)LineText_color_B/255.0;
    fz_context * ctx = graphics.getContext();
    
    if (isBlob) {
        fz_stroke_state* stroke = fz_new_stroke_state(ctx);
        if ( stroke != NULL ) {
            stroke->linewidth = LineText_fontSize * 0.15;
            stroke->miterlimit = stroke->linewidth*30;
            graphics.DrawStrokePath(pagePath.getPath(), stroke, matrix.getMatrix(), color, LineText_alpha/255.0);
            fz_drop_stroke_state(ctx,stroke);
        }
    }
    graphics.DrawFillPath(pagePath.getPath(), 0, matrix.getMatrix(), color, LineText_alpha/255.0);
}
//-----------------------------------------------------------------------------------------------------------------
fz_rect FZZWaterMark::FZCalculateRotatedBounds(int width,int height, float angle)
{
    FZZMatrix matrix;
    matrix.setRotate(angle,width / 2, height / 2);
    fz_rect fzbounds = fz_make_rect(0, 0, width, height);
    fzbounds = fz_transform_rect(fzbounds, matrix.getMatrix());
    fzbounds.x1 -= fzbounds.x0;
    fzbounds.y1 -= fzbounds.y0;
    fzbounds.x0 = 0;
    fzbounds.y0 = 0;
    
    return fzbounds;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZWaterMark::drawImage(bool isTile,double pageWidth,double pageHeight,double beginPosX,double beginPosY,
               const unsigned char * const imageData,size_t imageDataLen,double rotate,double & image_width,double & image_height)
{
    FZZBytes outData;
    
    FZZImageUtil fzImageUtil_src;
    if ( !fzImageUtil_src.LoadImage(imageData, imageDataLen) ) {
        return outData;
    }

    int widht = fzImageUtil_src.getWidth();
    int height = fzImageUtil_src.getHeight();
    fz_image * image = fzImageUtil_src.getImage();
    
//    FZZBytes srcdata = fzImageUtil_src.PngEncode();
//    FZZConst::writefile("/Volumes/WorkExt/work/cpp/ofdcreator_test/imageconverter/sign_WaterMark_src.png",srcdata.getData(),srcdata.getLen());
  
    
    
    FZZImageUtil fzImageUtil(fzImageUtil_src.getContext());
    
    if ( !isTile ) {
        FZZMatrix matrix;
        if ( pageWidth == 0 && pageHeight == 0 ) {
            fz_rect rect = FZCalculateRotatedBounds(widht,height,rotate);
            image_width = rect.x1 - rect.x0;
            image_height = rect.y1 - rect.y0;
            fzImageUtil.CreateImage(image_width+beginPosX, image_height+beginPosY, 255,255,255, 0);
            
            //在左上点旋转
            matrix.postRotate(rotate);
            if ( rotate <= 0 ) {
                
                matrix.postTranslate(0, -widht * sin(rotate * M_PI / 180.0));
            } else {
                matrix.postTranslate(height * sin(rotate * M_PI / 180.0),0);
            }
            matrix.postTranslate(beginPosX, beginPosY);
        } else {
            fzImageUtil.CreateImage(pageWidth, pageHeight, 255,255,255, 0);
            if ( beginPosX == -1 && beginPosY == -1 ) {
                fz_rect rect = FZCalculateRotatedBounds(widht,height,rotate);
                image_width = rect.x1 - rect.x0;
                image_height = rect.y1 - rect.y0;
                matrix.postRotate(rotate);
                if ( rotate <= 0 ) {
                    matrix.postTranslate(0, -widht * sin(rotate * M_PI / 180.0));
                } else {
                    matrix.postTranslate(height * sin(rotate * M_PI / 180.0),0);
                }
                matrix.postTranslate((pageWidth-image_width)/2,(pageHeight-image_height)/2);
            } else {
                matrix.postRotate(rotate);
                if ( rotate <= 0 ) {
                    matrix.postTranslate(0, -widht * sin(rotate * M_PI / 180.0));
                } else {
                    matrix.postTranslate(height * sin(rotate * M_PI / 180.0),0);
                }
                matrix.postTranslate(beginPosX, beginPosY);
            }
            image_width = pageWidth;
            image_height = pageHeight;
        }
        
        matrix.preScale(widht,height); //e,f不计算
        fzImageUtil.DrawFillImage(image, matrix.getMatrix(), 1);
    } else {
        //平铺局中
        if ( pageWidth == 0 || pageHeight == 0 ) {
            return outData;
        }
        fzImageUtil.CreateImage(pageWidth, pageHeight, 255,255,255, 0);
        
        if ( rotate == 0 ) {
            for (int y = 0; y < pageHeight; y += height) {
                for (int x = 0; x < pageWidth; x += widht) {
                    FZZMatrix ctm;
                    ctm.setTranslate(x+beginPosX, y+beginPosY);
                    ctm.preScale(widht,height);
                    fzImageUtil.DrawFillImage(image, ctm.getMatrix(), 1);
                }
            }
        } else {
            
            double temppageWidth = sqrt(pageWidth*pageWidth + pageHeight*pageHeight);
            double tempPageHeight = temppageWidth;
            
            fz_rect rect = FZCalculateRotatedBounds(temppageWidth,tempPageHeight,rotate);
            temppageWidth = rect.x1 - rect.x0;
            tempPageHeight = rect.y1 - rect.y0;
            
            
            FZZImageUtil fzImageUtil_temp(fzImageUtil_src.getContext());
            fzImageUtil_temp.CreateImage(temppageWidth, tempPageHeight, 255,255,255, 0);
            for (int y = 0; y < tempPageHeight; y += height) {
                for (int x = 0; x < temppageWidth; x += widht) {
                    FZZMatrix ctm;
                    ctm.setTranslate(x, y);
                    ctm.preScale(widht,height);
                    fzImageUtil_temp.DrawFillImage(image, ctm.getMatrix(), 1);
                }
            }
            
            
            FZZMatrix matrix;
            matrix.postRotate(rotate);
            if ( rotate <= 0 ) {
                matrix.postTranslate(0, -temppageWidth * sin(rotate * M_PI / 180.0));
            } else {
                matrix.postTranslate(tempPageHeight * sin(rotate * M_PI / 180.0),0);
            }
            
            float bian = sqrt(temppageWidth*temppageWidth + temppageWidth*temppageWidth);
            matrix .postTranslate((float)(-(bian-pageWidth)/2+beginPosX),(float)(-(bian-pageHeight)/2)+beginPosY);
            
            
            matrix.preScale(temppageWidth,tempPageHeight);
            
            fzImageUtil.DrawFillImage(fzImageUtil_temp.getImage(), matrix.getMatrix(), 1);
        }
        image_width = pageWidth;
        image_height = pageHeight;
    }
  
    outData = fzImageUtil.PngEncode();
    return outData;
}

//-----------------------------------------------------------------------------------------------------------------


