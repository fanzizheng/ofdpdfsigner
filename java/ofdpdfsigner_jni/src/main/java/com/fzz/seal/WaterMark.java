package com.fzz.seal;


import com.fzz.seal.entity.TextParams;
import com.fzz.seal.entity.WaterMarkImage;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;


public class WaterMark {

    public static WaterMarkImage createWaterMark(double rotation, double scale, boolean isImage,
                                                 byte[] image, TextParams textParams)
    {
        WaterMarkImage ret = null;
        if ( !isImage && (textParams == null || textParams.getText() == null
                || textParams.getColor() == null || textParams.getFont() == null
                || textParams.getFontSize() == null || textParams.getIsFontBold() == null
                || textParams.getText().length <= 0
                || textParams.getText().length != textParams.getColor().length
                || textParams.getText().length != textParams.getFont().length
                || textParams.getText().length != textParams.getFontSize().length
                || textParams.getText().length != textParams.getIsFontBold().length)) {
            return ret;
        }

        if ( isImage && ( image == null || image.length < 10 ) ) {
            return ret;
        }

        ReturnData returnData = new ReturnData();


        String text_1 = "";
        String fontName_1 = "";
        double fontSize_1 = 0;
        int isBlob_1 = 0;
        int isItalic_1 = 0;
        double colorR_1 = 0;
        double colorG_1 = 0;
        double colorB_1 = 0;
        double alpha_1 = 0;


        String text_2 = "";
        String fontName_2 = "";
        double fontSize_2 = 0;
        int isBlob_2 = 0;
        int isItalic_2 = 0;
        double colorR_2 = 0;
        double colorG_2 = 0;
        double colorB_2 = 0;
        double alpha_2 = 0;

        String text_3 = "";
        String fontName_3 = "";
        double fontSize_3 = 0;
        int isBlob_3 = 0;
        int isItalic_3 = 0;
        double colorR_3 = 0;
        double colorG_3 = 0;
        double colorB_3 = 0;
        double alpha_3 = 0;

        double lineSpacing0_1 = 8;
        double lineSpacing1_2 = 8;

        int textAlign = 1;
        if ( !isImage ) {
            if (textParams.getText().length >= 1) {
                text_1 = textParams.getText()[0];
                fontName_1 = textParams.getFont()[0];
                fontSize_1 = textParams.getFontSize()[0];
                isBlob_1 = textParams.getIsFontBold()[0] ? 1 : 0;
                isItalic_1 = 0;
                colorR_1 = textParams.getColor()[0].getRed();
                colorG_1 = textParams.getColor()[0].getGreen();
                colorB_1 = textParams.getColor()[0].getBlue();
                alpha_1 = textParams.getColor()[0].getAlpha();
            }

            if (textParams.getText().length >= 2) {
                text_2 = textParams.getText()[1];
                fontName_2 = textParams.getFont()[1];
                fontSize_2 = textParams.getFontSize()[1];
                isBlob_2 = textParams.getIsFontBold()[1] ? 1 : 0;
                isItalic_2 = 0;
                colorR_2 = textParams.getColor()[1].getRed();
                colorG_2 = textParams.getColor()[1].getGreen();
                colorB_2 = textParams.getColor()[1].getBlue();
                alpha_2 = textParams.getColor()[1].getAlpha();
            }

            if (textParams.getText().length >= 3) {
                text_3 = textParams.getText()[2];
                fontName_3 = textParams.getFont()[2];
                fontSize_3 = textParams.getFontSize()[2];
                isBlob_3 = textParams.getIsFontBold()[2] ? 1 : 0;
                isItalic_3 =  0;
                colorR_3 = textParams.getColor()[2].getRed();
                colorG_3 = textParams.getColor()[2].getGreen();
                colorB_3 = textParams.getColor()[2].getBlue();
                alpha_3 = textParams.getColor()[2].getAlpha();
            }

            double[] lineSpacing = textParams.getLineSpacing();
            if ( lineSpacing != null ) {
                if ( lineSpacing.length >= 1 ) {
                    lineSpacing0_1 = lineSpacing[0];
                }
                if ( lineSpacing.length >= 2 ) {
                    lineSpacing1_2 = lineSpacing[1];
                }
            }

            String strtextAlign = textParams.getTextAlign().toLowerCase();

            if ( strtextAlign.equals("left") ) {
                textAlign = 1;
            } else if ( strtextAlign.equals("right") ) {
                textAlign = 2;
            } else if ( strtextAlign.equals("center") ) {
                textAlign = 3;
            }

        } else {
            //image
        }


        IJNI.CreateWaterMark( false, isImage,0,
                0, 0, 0,image,
                textAlign, 0, 0,

                text_1.getBytes(StandardCharsets.UTF_8), fontName_1.getBytes(StandardCharsets.UTF_8), fontSize_1,
                isBlob_1, isItalic_1, colorR_1,
                colorG_1, colorB_1, alpha_1,

                text_2.getBytes(StandardCharsets.UTF_8), fontName_2.getBytes(StandardCharsets.UTF_8), fontSize_2,
                isBlob_2, isItalic_2, colorR_2,
                colorG_2, colorB_2, alpha_2,

                text_3.getBytes(StandardCharsets.UTF_8), fontName_3.getBytes(StandardCharsets.UTF_8), fontSize_3,
                isBlob_3, isItalic_3, colorR_3,
                colorG_3, colorB_3, alpha_3,

                lineSpacing0_1, lineSpacing1_2,
                rotation, scale, returnData);

        if (returnData.getErrorCode() == 0 && returnData.getResultData() != null) {


            byte[] temp = returnData.getResultData();
            byte[] imageDate = new byte[temp.length];
            System.arraycopy(temp, 0, imageDate, 0, temp.length);
            String strWidth = new String(returnData.getResultData1());
            String strHeight = new String(returnData.getResultData2());

            ret = new WaterMarkImage();
            ret.setWidth(Double.valueOf(strWidth).doubleValue());
            ret.setHeight(Double.valueOf(strHeight).doubleValue());
            ret.setImage(imageDate);
        }

        return ret;
    }


    public static byte[] createWaterMark(boolean isTile,boolean isImage,double pageWidth,
                                        double pageHeight,double X,double Y,byte[] imageData,
                                        int textAlign,double horizontalSpacing,double verticalSpacing,
                                        String[] text,String[] fontName,double[] fontSize,
                                        boolean[] isBlob,boolean[] isItalic,double[] colorR,
                                        double[] colorG,double[] colorB,double[] alpha,
                                        double lineSpacing0_1,double lineSpacing1_2,
                                        double rotate,double scaled)
    {
        byte[] ret = null;

        ReturnData returnData = new ReturnData();

        if ( text.length <= 0 ) {
            return ret;
        }

        if (  text.length != fontName.length
                || text.length != fontSize.length || text.length != isBlob.length
                || text.length != isItalic.length || text.length != colorR.length
                || text.length != colorG.length || text.length != colorB.length
                || text.length != alpha.length ) {
            return ret;
        }

        String text_1 = "";
        String fontName_1 = "";
        double fontSize_1 = 0;
        int isBlob_1 = 0;
        int isItalic_1 = 0;
        double colorR_1 = 0;
        double colorG_1 = 0;
        double colorB_1 = 0;
        double alpha_1 = 0;


        String text_2 = "";
        String fontName_2 = "";
        double fontSize_2 = 0;
        int isBlob_2 = 0;
        int isItalic_2= 0;
        double colorR_2 = 0;
        double colorG_2 = 0;
        double colorB_2 = 0;
        double alpha_2 = 0;

        String text_3 = "";
        String fontName_3 = "";
        double fontSize_3 = 0;
        int isBlob_3 = 0;
        int isItalic_3 = 0;
        double colorR_3 = 0;
        double colorG_3 = 0;
        double colorB_3 = 0;
        double alpha_3 = 0;

        if ( text.length >= 1 ) {
            text_1 = text[0];
            fontName_1 = fontName[0];
            fontSize_1 = fontSize[0];
            isBlob_1 = isBlob[0] ? 1 : 0;
            isItalic_1 = isItalic[0] ? 1 : 0;
            colorR_1 = colorR[0];
            colorG_1 = colorG[0];
            colorB_1 = colorB[0];
            alpha_1 = alpha[0];
        }

        if ( text.length >= 2 ) {
            text_2 = text[1];
            fontName_2 = fontName[1];
            fontSize_2 = fontSize[1];
            isBlob_2 = isBlob[1] ? 1 : 0;
            isItalic_2 = isItalic[1] ? 1 : 0;
            colorR_2 = colorR[1];
            colorG_2 = colorG[1];
            colorB_2 = colorB[1];
            alpha_2 = alpha[1];
        }

        if ( text.length >= 3 ) {
            text_3 = text[2];
            fontName_3 = fontName[2];
            fontSize_3 = fontSize[2];
            isBlob_3 = isBlob[2] ? 1 : 0;
            isItalic_3 = isItalic[2] ? 1 : 0;
            colorR_3 = colorR[2];
            colorG_3 = colorG[2];
            colorB_3 = colorB[2];
            alpha_3 = alpha[2];
        }

        IJNI.CreateWaterMark( isTile, isImage,pageWidth,
         pageHeight, X, Y,imageData,
         textAlign, horizontalSpacing, verticalSpacing,

         text_1.getBytes(StandardCharsets.UTF_8), fontName_1.getBytes(StandardCharsets.UTF_8), fontSize_1,
         isBlob_1, isItalic_1, colorR_1,
         colorG_1, colorB_1, alpha_1,

         text_2.getBytes(StandardCharsets.UTF_8), fontName_2.getBytes(StandardCharsets.UTF_8), fontSize_2,
         isBlob_2, isItalic_2, colorR_2,
         colorG_2, colorB_2, alpha_2,

         text_3.getBytes(StandardCharsets.UTF_8), fontName_3.getBytes(StandardCharsets.UTF_8), fontSize_3,
         isBlob_3, isItalic_3, colorR_3,
         colorG_3, colorB_3, alpha_3,

         lineSpacing0_1, lineSpacing1_2,
         rotate, scaled,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }


}
