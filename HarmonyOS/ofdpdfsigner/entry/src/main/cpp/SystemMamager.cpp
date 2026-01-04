//
// Created on 2024/6/21.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "SystemMamager.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"

//-----------------------------------------------------------------------------------------------------------------
napi_value SetTempPath(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    FZZBytes buffer;
  
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    NapiStringUtf8ToString(env, args[0],buffer);
    
    if ( buffer.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    bool isTF = setTempPath((char *)buffer.getData());
    //napi_throw_error(env, NULL, (char *)buffer.getData());
    return ReturnBool(env,isTF);
}
//-----------------------------------------------------------------------------------------------------------------
napi_value SetWorkPath(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];  
    FZZBytes buffer;
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    NapiStringUtf8ToString(env, args[0],buffer);
    if ( buffer.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    bool isTF = setWorkPath((char *)buffer.getData());
    
    return ReturnBool(env,isTF);
}
//-----------------------------------------------------------------------------------------------------------------