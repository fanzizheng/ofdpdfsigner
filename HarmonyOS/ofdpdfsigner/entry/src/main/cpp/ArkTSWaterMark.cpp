//
// Created on 2024/7/4.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSWaterMark.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
//-----------------------------------------------------------------------------------------------------------
napi_value CreateWaterMark(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 5;  
    napi_value args[5];
    
    string text_1 = "";
    string fontName_1 = "";
    double fontSize_1 = 0;
    bool isBlob_1 = false;
    bool isItalic_1 = false;
    double colorR_1 = 0;
    double colorG_1 = 0;
    double colorB_1 = 0;
    double alpha_1 = 0;


    string text_2 = "";
    string fontName_2 = "";
    double fontSize_2 = 0;
    bool isBlob_2 = false;
    bool isItalic_2 = false;
    double colorR_2 = 0;
    double colorG_2 = 0;
    double colorB_2 = 0;
    double alpha_2 = 0;

    string text_3 = "";
    string fontName_3 = "";
    double fontSize_3 = 0;
    bool isBlob_3 = false;
    bool isItalic_3 = false;
    double colorR_3 = 0;
    double colorG_3 = 0;
    double colorB_3 = 0;
    double alpha_3 = 0;

    double lineSpacing0_1 = 8;
    double lineSpacing1_2 = 8;

    int32_t textAlign_int = 1;
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 5) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    //-----------------------
    double rotation;
    napi_get_value_double(env, args[0], &rotation);
    //-----------------------
    double scale;
    napi_get_value_double(env, args[1], &scale);
    //-----------------------
    bool isImage = false;
    napi_get_value_bool(env, args[2], &isImage);
    //-----------------------
    size_t imageDataLen = 0;  
    void* imageData = NULL;  
    if ( isImage ) {
        //----------------------------
        napi_typedarray_type valuetype = napi_uint8_array;
        napi_get_typedarray_info(env, args[3], &valuetype, &imageDataLen, &imageData, nullptr, nullptr);
        if ( imageDataLen <= 0 || imageData == NULL ) {
            napi_throw_error(env, NULL, "imageData is NULL");  
            return NULL;  
        }
        //OH_LOG_INFO(LOG_APP,"OFDPositionSign => %{public}d",imageDataLen);
        //-----------------------
    } else {
        napi_value texts;
        uint32_t textsLen = 0;
        if (napi_get_named_property(env, args[4], "text", &texts) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.text is NULL");  
            return NULL;  
        }
        if ( napi_get_array_length(env, texts, &textsLen) != napi_ok ) {
            napi_throw_error(env, NULL, "textParams.text is NULL");
            return NULL;
        }
        
        napi_value colors;
        uint32_t colorsLen = 0;
        if (napi_get_named_property(env, args[4], "color", &colors) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.color is NULL");  
            return NULL;  
        }
        if ( napi_get_array_length(env, colors, &colorsLen) != napi_ok ) {
            napi_throw_error(env, NULL, "textParams.color is NULL");
            return NULL;
        }
        
        napi_value fonts;
        uint32_t fontsLen = 0;
        if (napi_get_named_property(env, args[4], "font", &fonts) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.font is NULL");  
            return NULL;  
        }
        if ( napi_get_array_length(env, fonts, &fontsLen) != napi_ok ) {
            napi_throw_error(env, NULL, "textParams.font is NULL");
            return NULL;
        }
        
        napi_value fontSizes;
        uint32_t fontSizesLen = 0;
        if (napi_get_named_property(env, args[4], "fontSize", &fontSizes) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.fontSize is NULL");  
            return NULL;  
        }
        if ( napi_get_array_length(env, fontSizes, &fontSizesLen) != napi_ok ) {
            napi_throw_error(env, NULL, "textParams.fontSize is NULL");
            return NULL;
        }
        
        napi_value isFontBolds;
        uint32_t isFontBoldsLen = 0;
        if (napi_get_named_property(env, args[4], "isFontBold", &isFontBolds) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.isFontBold is NULL");  
            return NULL;  
        }
        if ( napi_get_array_length(env, isFontBolds, &isFontBoldsLen) != napi_ok ) {
            napi_throw_error(env, NULL, "textParams.isFontBold is NULL");
            return NULL;
        }
        
        napi_value lineSpacings;
        uint32_t lineSpacingsLen = 0;
        if (napi_get_named_property(env, args[4], "lineSpacing", &lineSpacings) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.lineSpacing is NULL");  
            return NULL;  
        }
        if ( napi_get_array_length(env, lineSpacings, &lineSpacingsLen) != napi_ok ) {
            napi_throw_error(env, NULL, "textParams.lineSpacing is NULL");
            return NULL;
        }
        
        napi_value textAlign;
        if (napi_get_named_property(env, args[4], "textAlign", &textAlign) != napi_ok) {
            napi_throw_error(env, NULL, "textParams.textAlign is NULL");  
            return NULL;  
        }
        
        if ( textsLen <= 0 || textsLen > 3 || textsLen != colorsLen || textsLen != fontsLen 
            || textsLen != fontSizesLen || textsLen != isFontBoldsLen ) {
            napi_throw_error(env, NULL, "textParams.text len 1..3");  
            return NULL;  
        }
        
        napi_value tempValue;
        
        if ( textsLen >= 1 ) {
            
            if ( napi_get_element(env, texts, 0, &tempValue) == napi_ok ) {
                NapiStringUtf8ToCString(env,tempValue,text_1);
            }
            if ( napi_get_element(env, fonts, 0, &tempValue) == napi_ok ) {
                NapiStringUtf8ToCString(env,tempValue,fontName_1);
            }
            if ( napi_get_element(env, fontSizes, 0, &tempValue) == napi_ok ) {
                napi_get_value_double(env, tempValue, &fontSize_1);
            }
            if ( napi_get_element(env, isFontBolds, 0, &tempValue) == napi_ok ) {
                napi_get_value_bool(env, tempValue, &isBlob_1);
            }
            isItalic_1 = false;
            if ( napi_get_element(env, colors, 0, &tempValue) == napi_ok ) {
                napi_value r;
                if (napi_get_named_property(env, tempValue, "r", &r) == napi_ok) {
                    napi_get_value_double(env, r, &colorR_1);
                }
                napi_value g;
                if (napi_get_named_property(env, tempValue, "g", &g) == napi_ok) {
                    napi_get_value_double(env, g, &colorG_1);
                }
                napi_value b;
                if (napi_get_named_property(env, tempValue, "b", &b) == napi_ok) {
                    napi_get_value_double(env, b, &colorB_1);
                }
                napi_value a;
                if (napi_get_named_property(env, tempValue, "a", &a) == napi_ok) {
                    napi_get_value_double(env, a, &alpha_1);
                }
            }
        }
        if ( textsLen >= 2 ) {
            
            if ( napi_get_element(env, texts, 1, &tempValue) == napi_ok ) {
                NapiStringUtf8ToCString(env,tempValue,text_2);
            }
            if ( napi_get_element(env, fonts, 1, &tempValue) == napi_ok ) {
                NapiStringUtf8ToCString(env,tempValue,fontName_2);
            }
            if ( napi_get_element(env, fontSizes, 1, &tempValue) == napi_ok ) {
                napi_get_value_double(env, tempValue, &fontSize_2);
            }
            if ( napi_get_element(env, isFontBolds, 1, &tempValue) == napi_ok ) {
                napi_get_value_bool(env, tempValue, &isBlob_2);
            }
            isItalic_2 = false;
            if ( napi_get_element(env, colors, 1, &tempValue) == napi_ok ) {
                napi_value r;
                if (napi_get_named_property(env, tempValue, "r", &r) == napi_ok) {
                    napi_get_value_double(env, r, &colorR_2);
                }
                napi_value g;
                if (napi_get_named_property(env, tempValue, "g", &g) == napi_ok) {
                    napi_get_value_double(env, g, &colorG_2);
                }
                napi_value b;
                if (napi_get_named_property(env, tempValue, "b", &b) == napi_ok) {
                    napi_get_value_double(env, b, &colorB_2);
                }
                napi_value a;
                if (napi_get_named_property(env, tempValue, "a", &a) == napi_ok) {
                    napi_get_value_double(env, a, &alpha_2);
                }
            }
        }//
        if ( textsLen >= 3 ) {
            
            if ( napi_get_element(env, texts, 2, &tempValue) == napi_ok ) {
                NapiStringUtf8ToCString(env,tempValue,text_3);
            }
            if ( napi_get_element(env, fonts, 2, &tempValue) == napi_ok ) {
                NapiStringUtf8ToCString(env,tempValue,fontName_3);
            }
            if ( napi_get_element(env, fontSizes, 2, &tempValue) == napi_ok ) {
                napi_get_value_double(env, tempValue, &fontSize_3);
            }
            if ( napi_get_element(env, isFontBolds, 2, &tempValue) == napi_ok ) {
                napi_get_value_bool(env, tempValue, &isBlob_3);
            }
            isItalic_3 = false;
            if ( napi_get_element(env, colors, 2, &tempValue) == napi_ok ) {
                napi_value r;
                if (napi_get_named_property(env, tempValue, "r", &r) == napi_ok) {
                    napi_get_value_double(env, r, &colorR_3);
                }
                napi_value g;
                if (napi_get_named_property(env, tempValue, "g", &g) == napi_ok) {
                    napi_get_value_double(env, g, &colorG_3);
                }
                napi_value b;
                if (napi_get_named_property(env, tempValue, "b", &b) == napi_ok) {
                    napi_get_value_double(env, b, &colorB_3);
                }
                napi_value a;
                if (napi_get_named_property(env, tempValue, "a", &a) == napi_ok) {
                    napi_get_value_double(env, a, &alpha_3);
                }
            }
        }//
        
        if ( lineSpacingsLen >= 1 ) {
            
            if ( napi_get_element(env, lineSpacings, 0, &tempValue) == napi_ok ) {
                napi_get_value_double(env, tempValue, &lineSpacing0_1);
            }
        } 
        if ( lineSpacingsLen >= 2 ) {
            if ( napi_get_element(env, lineSpacings, 1, &tempValue) == napi_ok ) {
                napi_get_value_double(env, tempValue, &lineSpacing1_2);
            }
        }
        string strtextAlign = "";
        NapiStringUtf8ToCString(env,textAlign,strtextAlign);
        if (strtextAlign == "left")  {
            textAlign_int = 1;
        } else if  (strtextAlign == "right")  {
            textAlign_int = 2;
        } else if  (strtextAlign == "center")  {
            textAlign_int = 3;
        }
    }//isimage
    //-----------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    double imageWidth = 0;
    double imageHeight = 0;
    int iret = createWaterMarkImage(false,isImage,0,0,0,0,(unsigned char *)imageData,imageDataLen,textAlign_int,0,0,
                                              text_1.c_str(),fontName_1.c_str(),fontSize_1,isBlob_1,isItalic_1,colorR_1,
                                              colorG_1,colorB_1,alpha_1,
                                              lineSpacing0_1,
                                              text_2.c_str(),fontName_2.c_str(),fontSize_2,isBlob_2,isItalic_2,colorR_2,
                                                colorG_2,colorB_2,alpha_2,
                                               lineSpacing1_2,
                                              text_3.c_str(),fontName_3.c_str(),fontSize_3,isBlob_3,isItalic_3,colorR_3,
                                                                                              colorG_3,colorB_3,alpha_3,
                                               rotation, scale,&outData,&outDatalen,&imageWidth,&imageHeight);
    
    napi_value result_image = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_image);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    napi_value result_width;
    napi_create_double(env, imageWidth, &result_width);
    napi_value result_height;
    napi_create_double(env, imageHeight, &result_height);
    
    napi_value result_obj = NULL;
    status = napi_create_object(env, &result_obj);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, result_obj, "image", result_image);
    napi_set_named_property(env, result_obj, "width", result_width);
    napi_set_named_property(env, result_obj, "height", result_height);
    
    return result_obj;
}
//-----------------------------------------------------------------------------------------------------------