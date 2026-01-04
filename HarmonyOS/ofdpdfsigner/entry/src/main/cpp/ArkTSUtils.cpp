//
// Created on 2024/6/24.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSUtils.h"
//-----------------------------------------------------------------------------------------------------------------
void NapiStringUtf8ToString(napi_env env,napi_value value,FZZBytes & outData)
{
    napi_status status;  
    size_t len = 0;  
    // 将JavaScript字符串转换为C字符串  
    status = napi_get_value_string_utf8(env, value, NULL, 0, &len);  
    if (status != napi_ok) {
        return ;  
    }
    if ( len <= 0 ) {
        return ;  
    }
    outData.setMaxLen(len+3);
    status = napi_get_value_string_utf8(env, value, (char *)outData.getData(), outData.getLen(), &len);  
    if (status != napi_ok) {
        return ;  
    }  
}
//-----------------------------------------------------------------------------------------------------------------
void NapiStringUtf8ToCString(napi_env env,napi_value value,string & outStr)
{
    napi_status status;  
    size_t len = 0; 
    FZZBytes outData;
    // 将JavaScript字符串转换为C字符串  
    status = napi_get_value_string_utf8(env, value, NULL, 0, &len);  
    if (status != napi_ok) {
        return ;  
    }
    if ( len <= 0 ) {
        return ;  
    }
    outData.setMaxLen(len+3);
    status = napi_get_value_string_utf8(env, value, (char *)outData.getData(), outData.getLen(), &len);  
    if (status != napi_ok) {
        return ;  
    }  
    outStr = (char *)outData.getData();
}
//-----------------------------------------------------------------------------------------------------------------
void NapiObjectPropertyToString(napi_env env,napi_value object,char * propertyName,string & outStr)
{
    napi_status status;
    napi_value strValue;
    status = napi_get_named_property(env, object, propertyName, &strValue);
    if (status != napi_ok) {
        return ;  
    }
    NapiStringUtf8ToCString(env,strValue,outStr);
}
//-----------------------------------------------------------------------------------------------------------------
void NapiObjectPropertyToData(napi_env env,napi_value object,char * propertyName,FZZBytes & outData)
{
    napi_status status;
    napi_value uint8s;
    status = napi_get_named_property(env, object, propertyName, &uint8s);
    if (status != napi_ok) {
        return ;  
    }
    size_t sourceDataLen = 0;  
    void* sourceData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, uint8s, &valuetype, &sourceDataLen, &sourceData, nullptr, nullptr);
    if ( sourceDataLen <= 0 || sourceData == NULL ) {
        return;
    }
    outData.setData( (unsigned char *) sourceData, sourceDataLen);
}
//-----------------------------------------------------------------------------------------------------------------
void NapiObjectPropertyToObject(napi_env env,napi_value object,char * propertyName,napi_value* result)
{
    napi_status status;
    status = napi_get_named_property(env, object, propertyName, result);
    if (status != napi_ok) {
        return ;  
    }
}
//-----------------------------------------------------------------------------------------------------------------
void StringToNapiString(napi_env env,char * data,napi_value* result)
{
    napi_create_string_utf8(env, data, strlen(data), result);
}
//-----------------------------------------------------------------------------------------------------------------
void DataToNapiUint8Array(napi_env env,unsigned char * data,size_t datalen,napi_value* result)
{
    if ( data == NULL || datalen == 0 ) {
        return;
    }
    napi_value arrayBuffer;
    void* result_buffer = NULL;
    napi_create_arraybuffer(env, datalen,  &result_buffer, &arrayBuffer);
    if ( result_buffer == NULL ) {
        return;
    }
    memcpy(result_buffer, data, datalen);
    
    napi_create_typedarray(env, napi_uint8_array, datalen, arrayBuffer, 0, result);
}
//-----------------------------------------------------------------------------------------------------------------
napi_value ReturnBool(napi_env env,bool value)
{
    napi_value result = NULL;  
    napi_status status = napi_get_boolean(env, value, &result);  
    if (status != napi_ok) {  
        napi_throw_error(env, NULL, "Could not create result");  
        return NULL;  
    }  
    return result;
}
//-----------------------------------------------------------------------------------------------------------------