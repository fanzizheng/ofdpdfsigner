//
// Created on 2024/6/27.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSOFDConverter.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"

//-----------------------------------------------------------------------------------------------------------
napi_value OFDToImage(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
    
    // 获取参数  
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
    FZZBytes imageFormatData;
    NapiStringUtf8ToString(env, args[1],imageFormatData);
    if ( imageFormatData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string imageFormat = (char *)imageFormatData.getData();
    //----------------------------
    double scale;
    napi_get_value_double(env, args[2], &scale);
    //----------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    char * stroutDatalen = NULL;

    bool isTF = ofd_toImage(filehandle,imageFormat.c_str(),scale,&outData,&outDatalen,&stroutDatalen);
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        if ( stroutDatalen != NULL ) {
            FZZFreeHandle(stroutDatalen);
            stroutDatalen = NULL;
        }
        return NULL;
    }
    //----------------------------
    //OH_LOG_INFO(LOG_APP,"c++ ofd image lens %{public}s",stroutDatalen);
    vector<string> strlist;
    FZZConst::split(stroutDatalen, ",", strlist);
    
    napi_value array  = NULL; 
    status = napi_create_array_with_length(env, strlist.size(), &array);
    if (status != napi_ok ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        if ( stroutDatalen != NULL ) {
            FZZFreeHandle(stroutDatalen);
            stroutDatalen = NULL;
        }
        return NULL;
    }
    
    vector<string>::const_iterator itr;
    string tempstr = "";
    long pos = 0;
    size_t i = 0;
    for (itr = strlist.begin(); itr != strlist.end(); itr++) {
        tempstr = *itr;
        if ( !tempstr.empty() ) {
            long len = strtol(tempstr.c_str(),NULL,10);
            //OH_LOG_INFO(LOG_APP,"c++ ofd image len %{public}d,pos %{public}d,i : %{public}d",len,pos,i);
            napi_value imageData;
            DataToNapiUint8Array(env,outData+pos,len,&imageData);
            
            status = napi_set_element(env, array, i, imageData);  
            if (status == napi_ok) {    
                i++;
            }
            
            pos += len;
        }
        
    }

    //----------------------------
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    if ( stroutDatalen != NULL ) {
        FZZFreeHandle(stroutDatalen);
        stroutDatalen = NULL;
    }
    
    return array;
    
    
}
//-----------------------------------------------------------------------------------------------------------
napi_value OFDPageToImage(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 4;  
    napi_value args[4];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 4) {  
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
    FZZBytes imageFormatData;
    NapiStringUtf8ToString(env, args[1],imageFormatData);
    if ( imageFormatData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string imageFormat = (char *)imageFormatData.getData();
    //----------------------------
    
    int32_t pageNumber;
    napi_get_value_int32(env, args[2], &pageNumber);
    //----------------------------
    double scale;
    napi_get_value_double(env, args[3], &scale);
    //----------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = ofd_pageToImage(filehandle,imageFormat.c_str(),pageNumber,scale,&outData,&outDatalen);
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
napi_value OFDToImageZip(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
    
    // 获取参数  
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
    FZZBytes imageFormatData;
    NapiStringUtf8ToString(env, args[1],imageFormatData);
    if ( imageFormatData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string imageFormat = (char *)imageFormatData.getData();
    //----------------------------
    double scale;
    napi_get_value_double(env, args[2], &scale);
    //----------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = ofd_toImageZip(filehandle,imageFormat.c_str(),scale,&outData,&outDatalen);
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
napi_value OfdToPdf(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 4;  
    napi_value args[4];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 4) {  
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
    bool isIncludeStamp = false;
    napi_get_value_bool(env, args[1], &isIncludeStamp);
    //----------------------------
    bool isEncrypt = false;
    napi_get_value_bool(env, args[2], &isEncrypt);
    //----------------------------
    FZZBytes password;
    NapiStringUtf8ToString(env, args[3],password);
    if ( password.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    //----------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    
    bool isTF = ofdToPdf(filehandle,!isIncludeStamp,isEncrypt,(char *)password.getData(),&outData,&outDatalen);
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
