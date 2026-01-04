//
// Created on 2024/7/4.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSPDFStamp.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
#include "ArkTSSignCallBack.h"

//-----------------------------------------------------------------------------------------------------------
napi_value PDFPositionSign(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 11;
    napi_value args[11] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 11) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //----------------------------
    size_t imageDataLen = 0;  
    void* imageData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[1], &valuetype, &imageDataLen, &imageData, nullptr, nullptr);
    if ( imageDataLen <= 0 || imageData == NULL ) {
        napi_throw_error(env, NULL, "imageData is NULL");  
        return NULL;  
    }
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => %{public}d",imageDataLen);
    //-----------------------
    double sealAlpha;
    napi_get_value_double(env, args[2], &sealAlpha);
    //-----------------------
    int32_t pageNumber;
    napi_get_value_int32(env, args[3], &pageNumber);
    //-----------------------
    double stampX;
    napi_get_value_double(env, args[4], &stampX);
    //-----------------------
    double stampY;
    napi_get_value_double(env, args[5], &stampY);
    //-----------------------
    double width;
    napi_get_value_double(env, args[6], &width);
    //-----------------------
    double height;
    napi_get_value_double(env, args[7], &height);
    //-----------------------
    bool isLocked = false;
    napi_get_value_bool(env, args[8], &isLocked);
    //----------------------------
    napi_ref signCallbackRef;
    napi_create_reference(env, args[9], 1, &signCallbackRef);
    napi_value signCallback= nullptr;

    napi_get_reference_value(env, signCallbackRef, &signCallback);
    if ( signCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert signCallbackRef");
        return NULL;
    }

    CALLBACKFUNC_PARAM param;
    param.virifyCallBack_obj = NULL;
    param.sealCertCallBack_obj = NULL;
    param.userCertCallBack_obj = NULL;
    param.signCallBack_obj = NULL;
    param.getFontCallBack_obj = NULL;
    param.env = env;

    param.signCallBack_obj = signCallback;
    //----------------------------
    napi_ref userCertCallbackRef;
    napi_create_reference(env, args[10], 1, &userCertCallbackRef);
    napi_value userCallback= nullptr;

    napi_get_reference_value(env, userCertCallbackRef, &userCallback);
    if ( userCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert userCallback");
        return NULL;
    }


    param.userCertCallBack_obj = userCallback;
    //----------------------------
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = pdf_positionSign(filehandle,(unsigned char *)imageData, imageDataLen,sealAlpha,pageNumber,stampX,stampY,width,height,SignCallBackFunc,getUserCertCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
    napi_delete_reference(env, signCallbackRef);
    napi_delete_reference(env, userCertCallbackRef);
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    //----------------------------
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFRidingSign(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 9;
    napi_value args[9] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 9) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //----------------------------
    size_t imageDataLen = 0;  
    void* imageData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[1], &valuetype, &imageDataLen, &imageData, nullptr, nullptr);
    if ( imageDataLen <= 0 || imageData == NULL ) {
        napi_throw_error(env, NULL, "imageData is NULL");  
        return NULL;  
    }
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => %{public}d",imageDataLen);
    //-----------------------
    double sealAlpha;
    napi_get_value_double(env, args[2], &sealAlpha);
    //-----------------------
    FZZBytes tempData;
    NapiStringUtf8ToString(env, args[3],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    int ridingType = strtol((char *)tempData.getData(),NULL,10);
    //-----------------------
    double width;
    napi_get_value_double(env, args[4], &width);
    //-----------------------
    double height;
    napi_get_value_double(env, args[5], &height);
    //-----------------------
    bool isLocked = false;
    napi_get_value_bool(env, args[6], &isLocked);
    //----------------------------
    napi_ref signCallbackRef;
    napi_create_reference(env, args[7], 1, &signCallbackRef);
    napi_value signCallback= nullptr;

    napi_get_reference_value(env, signCallbackRef, &signCallback);
    if ( signCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert signCallbackRef");
        return NULL;
    }

    CALLBACKFUNC_PARAM param;
    param.virifyCallBack_obj = NULL;
    param.sealCertCallBack_obj = NULL;
    param.userCertCallBack_obj = NULL;
    param.signCallBack_obj = NULL;
    param.getFontCallBack_obj = NULL;
    param.env = env;

    param.signCallBack_obj = signCallback;
    //----------------------------
    napi_ref userCertCallbackRef;
    napi_create_reference(env, args[8], 1, &userCertCallbackRef);
    napi_value userCallback= nullptr;

    napi_get_reference_value(env, userCertCallbackRef, &userCallback);
    if ( userCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert userCallback");
        return NULL;
    }


    param.userCertCallBack_obj = userCallback;
    //----------------------------
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = pdf_ridingSign(filehandle,(unsigned char *)imageData, imageDataLen,sealAlpha,ridingType,width,height,SignCallBackFunc,getUserCertCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
    napi_delete_reference(env, signCallbackRef);
    napi_delete_reference(env, userCertCallbackRef);
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    //----------------------------
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFKeywordSign(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 10;
    napi_value args[10] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 10) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //----------------------------
    size_t imageDataLen = 0;  
    void* imageData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[1], &valuetype, &imageDataLen, &imageData, nullptr, nullptr);
    if ( imageDataLen <= 0 || imageData == NULL ) {
        napi_throw_error(env, NULL, "imageData is NULL");  
        return NULL;  
    }
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => %{public}d",imageDataLen);
    //-----------------------
    double sealAlpha;
    napi_get_value_double(env, args[2], &sealAlpha);
    //-----------------------
    
    FZZBytes tempData;
    NapiStringUtf8ToString(env, args[3],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string keyWord = (char *)tempData.getData();
    //-----------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[4],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string keyWordRules = (char *)tempData.getData();
    //-----------------------
    double width;
    napi_get_value_double(env, args[5], &width);
    //-----------------------
    double height;
    napi_get_value_double(env, args[6], &height);
    //-----------------------
    bool isLocked = false;
    napi_get_value_bool(env, args[7], &isLocked);
    //----------------------------
    napi_ref signCallbackRef;
    napi_create_reference(env, args[8], 1, &signCallbackRef);
    napi_value signCallback= nullptr;

    napi_get_reference_value(env, signCallbackRef, &signCallback);
    if ( signCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert signCallbackRef");
        return NULL;
    }

    CALLBACKFUNC_PARAM param;
    param.virifyCallBack_obj = NULL;
    param.sealCertCallBack_obj = NULL;
    param.userCertCallBack_obj = NULL;
    param.signCallBack_obj = NULL;
    param.getFontCallBack_obj = NULL;
    param.env = env;

    param.signCallBack_obj = signCallback;
    //----------------------------
    napi_ref userCertCallbackRef;
    napi_create_reference(env, args[9], 1, &userCertCallbackRef);
    napi_value userCallback= nullptr;

    napi_get_reference_value(env, userCertCallbackRef, &userCallback);
    if ( userCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert userCallback");
        return NULL;
    }


    param.userCertCallBack_obj = userCallback;
    //----------------------------
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = pdf_keywordSign(filehandle,(unsigned char *)imageData, imageDataLen,sealAlpha,keyWord.c_str(),keyWordRules.c_str(),width,height,SignCallBackFunc,getUserCertCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
    napi_delete_reference(env, signCallbackRef);
    napi_delete_reference(env, userCertCallbackRef);
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    //----------------------------
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFVerify(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------
    size_t fileDataLen = 0;  
    void* fileData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[0], &valuetype, &fileDataLen, &fileData, nullptr, nullptr);
    if ( fileDataLen <= 0 || fileData == NULL ) {
        napi_throw_error(env, NULL, "imageData is NULL");  
        return NULL;  
    }
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => %{public}d",imageDataLen);
    //-----------------------
    string strPW = "";
    FZZBytes password;
    NapiStringUtf8ToString(env, args[1],password);
    if ( password.getLen() > 0 ) {
        strPW = (char *)password.getData();
    }
    //----------------------------
    
    napi_ref recvCallbackRef;
    napi_create_reference(env, args[2], 1, &recvCallbackRef);
    napi_value recvCallback= nullptr;
        
    napi_get_reference_value(env, recvCallbackRef, &recvCallback);
    if ( recvCallback == NULL ) {
        return NULL;
    }
    
    CALLBACKFUNC_PARAM param;
    param.env = env;
    param.virifyCallBack_obj = recvCallback;
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = verifyDocment((unsigned char *)fileData, fileDataLen,2,(char *)(strPW.c_str()),VerifyCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
    napi_delete_reference(env, recvCallbackRef);
    //------------------------------------------------
    
    if ( !isTF || outDatalen <= 0 ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    napi_value result_str = NULL;
    StringToNapiString(env,(char *)outData,&result_str);
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    return result_str;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFClearSigns(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"PDFClearSigns => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //-------------
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //-------------
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = pdf_clearSigns(filehandle,&outData,&outDatalen) == 0;
    
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    //----------------------------
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------