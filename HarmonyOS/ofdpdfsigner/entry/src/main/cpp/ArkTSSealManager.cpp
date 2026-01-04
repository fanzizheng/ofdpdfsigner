//
// Created on 2024/7/1.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSSealManager.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
#include "ArkTSSignCallBack.h"

//-----------------------------------------------------------------------------------------------------------
//code : string,
//type : string,
//name : string,
//format : string,
//image : Uint8Array,
//width : number,
//height : number,
//createTime : string,
//startTime : string,
//endTime : string, 
//signCallBack: (sourceData: Uint8Array) => Uint8Array,
//getUserCertCallback: () => Uint8Array,
//getSealCertCallback: () => Uint8Array
napi_value CreateSeal(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 13;
    napi_value args[13] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"CreateSeal => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 13) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------
    FZZBytes tempData;
    NapiStringUtf8ToString(env, args[0],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string code = (char *)tempData.getData();
    
    //----------------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[1],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string type = (char *)tempData.getData();
    //----------------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[2],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string name = (char *)tempData.getData();
    //----------------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[3],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string format = (char *)tempData.getData();
    //----------------------------
    size_t imageDataLen = 0;  
    void* imageData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[4], &valuetype, &imageDataLen, &imageData, nullptr, nullptr);
    if ( imageDataLen <= 0 || imageData == NULL ) {
        napi_throw_error(env, NULL, "imageData is NULL");  
        return NULL;  
    }
    //OH_LOG_INFO(LOG_APP,"CreateSeal => %{public}d",imageDataLen);
    //-----------------------
    int32_t width;
    napi_get_value_int32(env, args[5], &width);
    //----------------------------
    int32_t height;
    napi_get_value_int32(env, args[6], &height);
    //----------------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[7],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string createTime = (char *)tempData.getData();
    //----------------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[8],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string startTime = (char *)tempData.getData();
    //----------------------------
    tempData.clear();
    NapiStringUtf8ToString(env, args[9],tempData);
    if ( tempData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }

    string endTime = (char *)tempData.getData();
    //----------------------------
    napi_ref signCallbackRef;
    napi_create_reference(env, args[10], 1, &signCallbackRef);
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
    napi_create_reference(env, args[11], 1, &userCertCallbackRef);
    napi_value userCallback= nullptr;

    napi_get_reference_value(env, userCertCallbackRef, &userCallback);
    if ( userCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert userCallback");
        return NULL;
    }


    param.userCertCallBack_obj = userCallback;
    //----------------------------
    napi_ref sealCertCallbackRef;
    napi_create_reference(env, args[12], 1, &sealCertCallbackRef);
    napi_value sealCallback= nullptr;

    napi_get_reference_value(env, sealCertCallbackRef, &sealCallback);
    if ( sealCallback == NULL ) {
        napi_throw_error(env, NULL, "Could not convert sealCallback");
        return NULL;
    }


    param.sealCertCallBack_obj = sealCallback;

    //----------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    //OH_LOG_INFO(LOG_APP,"CreateSeal begin %{public}s, %{public}ld",type.c_str(),strtol(type.c_str(),NULL,10));
    bool isTF = createSeal(code.c_str(),strtol(type.c_str(),NULL,10),name.c_str(),width, height,createTime.c_str(),startTime.c_str(),endTime.c_str(),format.c_str(),(unsigned char *)imageData, imageDataLen,SignCallBackFunc,getUserCertCallBackFunc,getSealCertCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    //OH_LOG_INFO(LOG_APP,"CreateSeal end");
    napi_delete_reference(env, signCallbackRef);
    napi_delete_reference(env, userCertCallbackRef);
    napi_delete_reference(env, sealCertCallbackRef);
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
napi_value VerifySeal(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_value retNumber = NULL;
    int retInt = 0xFFFFFF;
    napi_create_int32(env, retInt, &retNumber);
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return retNumber;  
    }
    
    size_t sealDataLen = 0;  
    void* sealData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[0], &valuetype, &sealDataLen, &sealData, nullptr, nullptr);
    if ( sealDataLen <= 0 || sealData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return retNumber;  
    }
    //-----------------------
    
    napi_ref recvCallbackRef;
    napi_create_reference(env, args[1], 1, &recvCallbackRef);
    napi_value recvCallback= nullptr;
        
    napi_get_reference_value(env, recvCallbackRef, &recvCallback);
    if ( recvCallback == NULL ) {
        return retNumber;
    }
    
    CALLBACKFUNC_PARAM param;
    param.env = env;
    param.virifyCallBack_obj = recvCallback;
    retInt = verifySeal((unsigned char *)sealData,sealDataLen,VerifyCallBackFunc,(void *)(&param));
    
    napi_delete_reference(env, recvCallbackRef);
    //------------------------------------------------
    
    napi_create_int32(env, retInt, &retNumber);
    
    return retNumber;
}
//-----------------------------------------------------------------------------------------------------------
napi_value GetSealImageData(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    size_t sealDataLen = 0;  
    void* sealData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[0], &valuetype, &sealDataLen, &sealData, nullptr, nullptr);
    if ( sealDataLen <= 0 || sealData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;  
    }
    //-----------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = getSealImageData((unsigned char *)sealData, sealDataLen,&outData,&outDatalen) == 0;
    
    
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
napi_value GetSealUserCertData(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    size_t sealDataLen = 0;  
    void* sealData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[0], &valuetype, &sealDataLen, &sealData, nullptr, nullptr);
    if ( sealDataLen <= 0 || sealData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;  
    }
    //-----------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = getSealUserCertData((unsigned char *)sealData, sealDataLen,&outData,&outDatalen) == 0;
    
    
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


