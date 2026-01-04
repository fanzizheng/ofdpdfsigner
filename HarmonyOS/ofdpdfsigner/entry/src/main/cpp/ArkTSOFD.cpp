//
// Created on 2024/6/26.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSOFD.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
#include "ArkTSSignCallBack.h"

//-----------------------------------------------------------------------------------------------------------
napi_value OFDOpen(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    size_t fileDataLen = 0;  
    void* fileData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[0], &valuetype, &fileDataLen, &fileData, nullptr, nullptr);
    if ( fileDataLen <= 0 || fileData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;
    }
    //-----------------------
    HANDLE handle = ofd_open((unsigned char *)fileData, fileDataLen);
    if (handle == NULL) {
        return NULL;
    } 
    int64_t ptrValue = reinterpret_cast<int64_t>(handle);
        
    //OH_LOG_INFO(LOG_APP,"c++ open ofd %{public}d",ptrValue);
    napi_value filehandle = NULL;
    napi_create_int64(env, ptrValue, &filehandle);
    return filehandle;
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDClose(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return ReturnBool(env, false);
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    if ( filehandle != NULL ) {
        ofd_close(filehandle);
    }
    
    return ReturnBool(env, true);
    
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDGetPageCount(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    
    int pageCount = ofd_getPageCount(filehandle);
    
    napi_value count = NULL;
    napi_create_int32(env, pageCount, &count);
    
    return count;
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDGetPageSize(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 2;  
    napi_value args[2];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    
    int32_t pageNumber;
    napi_get_value_int32(env, args[1], &pageNumber);
    
    double pageWidth = 0;
    double pageHeight = 0;
    ofd_getPageSize(filehandle,pageNumber,pageWidth,pageHeight);
    
    napi_value width;
    napi_create_double(env, pageWidth, &width);
    napi_value height;
    napi_create_double(env, pageHeight, &height);
    
    napi_value result_obj = NULL;
    status = napi_create_object(env, &result_obj);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, result_obj, "width", width);
    napi_set_named_property(env, result_obj, "height", height);
    
    return result_obj;
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDIsProtect(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    napi_value retLong = NULL;
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        napi_create_int32(env, -1, &retLong);
        return retLong;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    
    bool isTF = ofd_isProtect(filehandle);
        
    if ( isTF )
        napi_create_int32(env, 1, &retLong);
    else 
        napi_create_int32(env, 0, &retLong);
    
    return retLong;
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDIsEncrypt(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    napi_value retLong = NULL;
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        napi_create_int32(env, -1, &retLong);
        return retLong;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    
    bool isTF = ofd_isEncrypt(filehandle);
        
    if ( isTF )
        napi_create_int32(env, 1, &retLong);
    else 
        napi_create_int32(env, 0, &retLong);
    
    return retLong;
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDProtect(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    
    OH_LOG_INFO(LOG_APP,"OFDProtect => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {
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
    napi_ref signCallbackRef;
    napi_create_reference(env, args[1], 1, &signCallbackRef);
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
    napi_create_reference(env, args[2], 1, &userCertCallbackRef);
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
    
    bool isTF = ofd_protect(filehandle,SignCallBackFunc,getUserCertCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
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
napi_value OFDProtectionVerify(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"OFDPositionSign => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //-----------------------
    napi_ref recvCallbackRef;
    napi_create_reference(env, args[1], 1, &recvCallbackRef);
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
    
    bool isTF = ofd_protectionVerify(filehandle,VerifyCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
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
napi_value OFDEncryptDocument(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 7;
    napi_value args[7] = {nullptr};
    
    //OH_LOG_ERROR(LOG_APP,"OFDEncryptDocument => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 7) {
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        //OH_LOG_ERROR(LOG_APP,"OFDEncryptDocument => handle == 0");
        return NULL;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //----------------------------
    string strUserInfo = "";
    FZZBytes userInfo;
    NapiStringUtf8ToString(env, args[1],userInfo);
    if ( userInfo.getLen() > 0 ) {
        strUserInfo = (char *)userInfo.getData();
    }
    //----------------------------
    CALLBACKFUNC_PARAM param;
    param.env = env;
    //----------------------------
    napi_ref encSM4CBCCallbackRef;
    napi_create_reference(env, args[2], 1, &encSM4CBCCallbackRef);
    napi_value encSM4CBCCallback= nullptr;
        
    napi_get_reference_value(env, encSM4CBCCallbackRef, &encSM4CBCCallback);
    if ( encSM4CBCCallback == NULL ) {
        //OH_LOG_ERROR(LOG_APP,"OFDEncryptDocument => encSM4CBCCallback == NULL");
        return NULL;
    }
    
    param.EncryptSM4CBCCallBack_obj = encSM4CBCCallback;
    //----------------------------
    napi_ref decSM4CBCCallbackRef;
    napi_create_reference(env, args[3], 1, &decSM4CBCCallbackRef);
    napi_value decSM4CBCCallback= nullptr;
        
    napi_get_reference_value(env, decSM4CBCCallbackRef, &decSM4CBCCallback);
    if ( decSM4CBCCallback == NULL ) {
        //OH_LOG_ERROR(LOG_APP,"OFDEncryptDocument => decSM4CBCCallback == NULL");
        return NULL;
    }
    
    param.DecryptSM4CBCCallBack_obj = decSM4CBCCallback;
    //----------------------------
    napi_ref encSM2CallbackRef;
    napi_create_reference(env, args[4], 1, &encSM2CallbackRef);
    napi_value encSM2Callback= nullptr;
        
    napi_get_reference_value(env, encSM2CallbackRef, &encSM2Callback);
    if ( encSM2Callback == NULL ) {
        //OH_LOG_ERROR(LOG_APP,"OFDEncryptDocument => encSM2Callback == NULL");
        return NULL;
    }
    
    param.EncryptSM2CallBack_obj = encSM2Callback;
    //----------------------------
    napi_ref decSM2CallbackRef;
    napi_create_reference(env, args[5], 1, &decSM2CallbackRef);
    napi_value decSM2Callback= nullptr;
        
    napi_get_reference_value(env, decSM2CallbackRef, &decSM2Callback);
    if ( decSM2Callback == NULL ) {
        //OH_LOG_ERROR(LOG_APP,"OFDEncryptDocument => decSM2Callback == NULL");
        return NULL;
    }
    
    param.DecryptSM2CallBack_obj = decSM2Callback;
    //----------------------------
    napi_ref genRandomCallbackRef;
    napi_create_reference(env, args[6], 1, &genRandomCallbackRef);
    napi_value genRandomCallback= nullptr;
        
    napi_get_reference_value(env, genRandomCallbackRef, &genRandomCallback);
    if ( genRandomCallback == NULL ) {
        //OH_LOG_INFO(LOG_APP,"OFDEncryptDocument => genRandomCallback == NULL");
        return NULL;
    }
    
    param.GenerateRandomCallBack_obj = genRandomCallback;
    //----------------------------
        
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    int iRet = ofd_encryptDocument(filehandle,strUserInfo.c_str(),EncryptSM4CBCCallBackFunc,DecryptSM4CBCCallBackFunc,EncryptSM2CallBackFunc,DecryptSM2CallBackFunc,GenerateRandomCallBackFunc,(void *)(&param),&outData,&outDatalen);
    //OH_LOG_ERROR(LOG_APP, "XYOFDEncryptDocument_Handle => %{public}d",iRet);
    bool isTF = iRet == 0;
//    if (isTF) {
//        OH_LOG_ERROR(LOG_APP, "XYOFDEncryptDocument_Handle => true");
//    } else {
//        OH_LOG_ERROR(LOG_APP, "XYOFDEncryptDocument_Handle => false");
//    }

    napi_delete_reference(env, encSM4CBCCallbackRef);
    napi_delete_reference(env, decSM4CBCCallbackRef);
    napi_delete_reference(env, encSM2CallbackRef);
    napi_delete_reference(env, decSM2CallbackRef);
    napi_delete_reference(env, genRandomCallbackRef);
    
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
napi_value OFDDecryptDocument(napi_env env, napi_callback_info info)
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
    int64_t mode;
    napi_get_value_int64(env, args[1], &mode);
    //----------------------------
    string strPW = "";
    FZZBytes passWord;
    NapiStringUtf8ToString(env, args[2],passWord);
    if ( passWord.getLen() > 0 ) {
        strPW = (char *)passWord.getData();
    }
    //----------------------------
    string struserName = "";
    FZZBytes userName;
    NapiStringUtf8ToString(env, args[3],userName);
    if ( userName.getLen() > 0 ) {
        struserName = (char *)userName.getData();
    }
    //----------------------------
    string struserType = "";
    FZZBytes userType;
    NapiStringUtf8ToString(env, args[4],userType);
    if ( userType.getLen() > 0 ) {
        struserType = (char *)userType.getData();
    }
    //----------------------------
    CALLBACKFUNC_PARAM param;
    param.env = env;
    //----------------------------
    napi_ref encSM4CBCCallbackRef;
    napi_create_reference(env, args[5], 1, &encSM4CBCCallbackRef);
    napi_value encSM4CBCCallback= nullptr;
        
    napi_get_reference_value(env, encSM4CBCCallbackRef, &encSM4CBCCallback);
    if ( encSM4CBCCallback == NULL ) {
        return NULL;
    }
    
    param.EncryptSM4CBCCallBack_obj = encSM4CBCCallback;
    //----------------------------
    napi_ref decSM4CBCCallbackRef;
    napi_create_reference(env, args[6], 1, &decSM4CBCCallbackRef);
    napi_value decSM4CBCCallback= nullptr;
        
    napi_get_reference_value(env, decSM4CBCCallbackRef, &decSM4CBCCallback);
    if ( decSM4CBCCallback == NULL ) {
        return NULL;
    }
    
    param.DecryptSM4CBCCallBack_obj = decSM4CBCCallback;
    //----------------------------
    napi_ref encSM2CallbackRef;
    napi_create_reference(env, args[7], 1, &encSM2CallbackRef);
    napi_value encSM2Callback= nullptr;
        
    napi_get_reference_value(env, encSM2CallbackRef, &encSM2Callback);
    if ( encSM2Callback == NULL ) {
        return NULL;
    }
    
    param.EncryptSM2CallBack_obj = encSM2Callback;
    //----------------------------
    napi_ref decSM2CallbackRef;
    napi_create_reference(env, args[8], 1, &decSM2CallbackRef);
    napi_value decSM2Callback= nullptr;
        
    napi_get_reference_value(env, decSM2CallbackRef, &decSM2Callback);
    if ( decSM2Callback == NULL ) {
        return NULL;
    }
    
    param.DecryptSM2CallBack_obj = decSM2Callback;
    //----------------------------
    napi_ref genRandomCallbackRef;
    napi_create_reference(env, args[9], 1, &genRandomCallbackRef);
    napi_value genRandomCallback= nullptr;
        
    napi_get_reference_value(env, genRandomCallbackRef, &genRandomCallback);
    if ( genRandomCallback == NULL ) {
        return NULL;
    }
    
    param.GenerateRandomCallBack_obj = genRandomCallback;
    //----------------------------
        
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = ofd_decryptDocument(filehandle,mode,strPW.c_str(),struserName.c_str(),struserType.c_str(),EncryptSM4CBCCallBackFunc,DecryptSM4CBCCallBackFunc,EncryptSM2CallBackFunc,DecryptSM2CallBackFunc,GenerateRandomCallBackFunc,(void *)(&param),&outData,&outDatalen) == 0;
    
    napi_delete_reference(env, encSM4CBCCallbackRef);
    napi_delete_reference(env, decSM4CBCCallbackRef);
    napi_delete_reference(env, encSM2CallbackRef);
    napi_delete_reference(env, decSM2CallbackRef);
    napi_delete_reference(env, genRandomCallbackRef);
    
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


