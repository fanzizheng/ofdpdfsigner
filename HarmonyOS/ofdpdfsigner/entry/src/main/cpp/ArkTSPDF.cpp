//
// Created on 2024/6/26.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSPDF.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
#include "hilog/log.h"

//-----------------------------------------------------------------------------------------------------------
napi_value PDFOpen(napi_env env, napi_callback_info info)
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
    HANDLE handle = pdf_open((unsigned char *)fileData, fileDataLen);
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
napi_value PDFClose(napi_env env, napi_callback_info info)
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
        pdf_close(filehandle);
    }
    
    return ReturnBool(env, true);
    
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFGetPageCount(napi_env env, napi_callback_info info)
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
    
    int pageCount = pdf_getPageCount(filehandle);
    
    napi_value count = NULL;
    napi_create_int32(env, pageCount, &count);
    
    return count;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFGetPageSize(napi_env env, napi_callback_info info)
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
    pdf_getPageSize(filehandle,pageNumber,pageWidth,pageHeight);
    
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
napi_value PDFIsNeedPassWord(napi_env env, napi_callback_info info)
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
    
    bool isTF = pdf_isNeedPassWord(filehandle);
        
    if ( isTF )
        napi_create_int32(env, 1, &retLong);
    else 
        napi_create_int32(env, 0, &retLong);
    
    return retLong;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFSetPassWord(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 2;  
    napi_value args[2];
    napi_value retLong = NULL;
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");
        return NULL;  
    }
    //------------
    int64_t handle;
    napi_get_value_int64(env, args[0], &handle);
    
    if ( handle == 0 ) {
        napi_create_int32(env, -1, &retLong);
        return retLong;
    }
    
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    //-------------
    string strPW = "";
    FZZBytes password;
    NapiStringUtf8ToString(env, args[1],password);
    if ( password.getLen() > 0 ) {
        strPW = (char *)password.getData();
    }
    //----------------------------
    pdf_setPassWord(filehandle,(char *)strPW.c_str());

    napi_create_int32(env, 0, &retLong);
    
    return retLong;
}
//-----------------------------------------------------------------------------------------------------------
napi_value PDFDocumnetEncryptDecrypt(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    
    //OH_LOG_INFO(LOG_APP,"PDFClearSigns => begin");
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {
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
    bool isEncrypt = false;
    napi_get_value_bool(env, args[1], &isEncrypt);
    //----------------------------
    string strPW = "";
    FZZBytes password;
    NapiStringUtf8ToString(env, args[2],password);
    if ( password.getLen() > 0 ) {
        strPW = (char *)password.getData();
    }
    //----------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = pdf_documnetEncryptDecrypt(filehandle,isEncrypt,(char *)strPW.c_str(),&outData,&outDatalen) == 0;
    
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



