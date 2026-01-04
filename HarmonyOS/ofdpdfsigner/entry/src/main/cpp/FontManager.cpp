//
// Created on 2024/6/24.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "FontManager.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
//-----------------------------------------------------------------------------------------------------------
napi_value SaveFontFileNameCache(napi_env env, napi_callback_info info) 
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
    bool isTF = saveFontFileNameCache((char *)buffer.getData());
    //napi_throw_error(env, NULL, (char *)buffer.getData());
    return ReturnBool(env,isTF);
}
//-----------------------------------------------------------------------------------------------------------
void SystemFontFileName_CallBackFunc(const void * param,const char* const fullFileName)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    
    if ( callbackParam->env == NULL || callbackParam->getFontCallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_argv[1];
    napi_value Callback_ret;
    napi_create_string_utf8(callbackParam->env, fullFileName, strlen(fullFileName), &Callback_argv[0]);
    napi_call_function(callbackParam->env, nullptr, callbackParam->getFontCallBack_obj, 1, Callback_argv, &Callback_ret);
}
//-----------------------------------------------------------------------------------------------------------
napi_value GetAllSystemFontFileName(napi_env env, napi_callback_info info) 
{
    napi_status status;  
    napi_value ret; 
    napi_get_boolean(env, false, &ret);
    
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    napi_ref recvCallbackRef;
    napi_create_reference(env, args[0], 1, &recvCallbackRef);
    napi_value recvCallback= nullptr;
        
    napi_get_reference_value(env, recvCallbackRef, &recvCallback);
    if ( recvCallback == NULL ) {
        return ReturnBool(env,false);
    }
    
    CALLBACKFUNC_PARAM param;
    param.env = env;
    param.getFontCallBack_obj = recvCallback;
    bool isTF = getAllSystemFontFileName(SystemFontFileName_CallBackFunc,(void *)(&param));
    
    napi_delete_reference(env, recvCallbackRef);
 
    return ReturnBool(env,isTF);
}
//-----------------------------------------------------------------------------------------------------------