//
// Created on 2024/7/1.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSSignCallBack.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"


//-----------------------------------------------------------------------------------------------------------
void SignCallBackFunc(const void * param,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    //OH_LOG_INFO(LOG_APP,"SignCallBackFunc => begin");
    if ( callbackParam->env == NULL || callbackParam->signCallBack_obj == NULL ) {
        return;
    }
    
    //OH_LOG_INFO(LOG_APP,"SignCallBackFunc => sourceData len %{public}d",sourceDatalen);
    
    napi_value Callback_argv[1];
    napi_value Callback_ret;
    DataToNapiUint8Array(callbackParam->env,sourceData,sourceDatalen,&Callback_argv[0]);
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->signCallBack_obj, 1, Callback_argv, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    //OH_LOG_INFO(LOG_APP,"SignCallBackFunc => signdata len %{public}d",retDataLen);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //OH_LOG_INFO(LOG_APP,"SignCallBackFunc => end");
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
void getUserCertCallBackFunc(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    //OH_LOG_INFO(LOG_APP,"getUserCertCallBackFunc => begin");
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
        
    if ( callbackParam->env == NULL || callbackParam->userCertCallBack_obj == NULL ) {
        return;
    }
    //OH_LOG_INFO(LOG_APP,"getUserCertCallBackFunc => 1");
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->userCertCallBack_obj, 0, NULL, &Callback_ret);
    //OH_LOG_INFO(LOG_APP,"getUserCertCallBackFunc => 2");
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        //OH_LOG_INFO(LOG_APP,"getUserCertCallBackFunc => 2...1");
        return;
    }
    //OH_LOG_INFO(LOG_APP,"getUserCertCallBackFunc => 3");
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
    //OH_LOG_INFO(LOG_APP,"getUserCertCallBackFunc => end");
}
//-----------------------------------------------------------------------------------------------------------
void getSealCertCallBackFunc(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
            
    if ( callbackParam->env == NULL || callbackParam->sealCertCallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->sealCertCallBack_obj, 0, NULL, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
bool VerifyCallBackFunc(const void * param,int algType,unsigned char * keyData,int keyDatalen,unsigned char * sourceData,int sourceDatalen,unsigned char * signData,int signDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
        
    if ( callbackParam->env == NULL || callbackParam->virifyCallBack_obj == NULL ) {
        return false;
    }
    
    napi_value Callback_argv[4];
    napi_create_string_utf8(callbackParam->env, "SM3_SM2", strlen("SM3_SM2"), &Callback_argv[0]);
    napi_value pubkey;
    DataToNapiUint8Array(callbackParam->env,keyData,keyDatalen,&pubkey);
    DataToNapiUint8Array(callbackParam->env,sourceData,sourceDatalen,&Callback_argv[2]);
    DataToNapiUint8Array(callbackParam->env,signData,signDatalen,&Callback_argv[3]);
    
    napi_value keyType;
    StringToNapiString(callbackParam->env,"SM2_Public",&keyType);
    
    
    napi_status status = napi_create_object(callbackParam->env, &Callback_argv[1]);
    if (status != napi_ok ) {
        return false;  
    }
    napi_set_named_property(callbackParam->env, Callback_argv[1], "keyType", keyType);
    napi_set_named_property(callbackParam->env, Callback_argv[1], "key", pubkey);
    //------------------------------------
    napi_value Callback_ret;
    napi_call_function(callbackParam->env, nullptr, callbackParam->virifyCallBack_obj, 4, Callback_argv, &Callback_ret);
    //------------------------------------
    bool retboolean = false;
    napi_get_value_bool(callbackParam->env, Callback_ret, &retboolean);
    return retboolean;
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
//(key：Key,iv：Uint8Array,sourceData：Uint8Array) => Uint8Array
void EncryptSM4CBCCallBackFunc(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    //OH_LOG_ERROR(LOG_APP, "EncryptSM4CBCCallBackFunc => begin");            
    if ( callbackParam->env == NULL || callbackParam->EncryptSM4CBCCallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_argv[3];
    //-------------------------------
    napi_value pubkey;
    DataToNapiUint8Array(callbackParam->env,keyData,KeyDatalen,&pubkey);
    napi_value keyType;
    StringToNapiString(callbackParam->env,"SM4",&keyType);
    napi_status status = napi_create_object(callbackParam->env, &Callback_argv[0]);
    if (status != napi_ok ) {
        return;  
    }
    napi_set_named_property(callbackParam->env, Callback_argv[0], "keyType", keyType);
    napi_set_named_property(callbackParam->env, Callback_argv[0], "key", pubkey);
    //-------------------------------
    DataToNapiUint8Array(callbackParam->env,ivData,ivDatalen,&Callback_argv[1]);
    DataToNapiUint8Array(callbackParam->env,sourceData,sourceDatalen,&Callback_argv[2]);
    //-------------------------------
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->EncryptSM4CBCCallBack_obj, 3, Callback_argv, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
//(key:Key,iv:Uint8Array, encryptData:Uint8Array) => Uint8Array
void DecryptSM4CBCCallBackFunc(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    //OH_LOG_ERROR(LOG_APP, "DecryptSM4CBCCallBackFunc => begin");   
    if ( callbackParam->env == NULL || callbackParam->DecryptSM4CBCCallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_argv[3];
    //-------------------------------
    napi_value pubkey;
    DataToNapiUint8Array(callbackParam->env,keyData,KeyDatalen,&pubkey);
    napi_value keyType;
    StringToNapiString(callbackParam->env,"SM4",&keyType);
    napi_status status = napi_create_object(callbackParam->env, &Callback_argv[0]);
    if (status != napi_ok ) {
        return;  
    }
    napi_set_named_property(callbackParam->env, Callback_argv[0], "keyType", keyType);
    napi_set_named_property(callbackParam->env, Callback_argv[0], "key", pubkey);
    //-------------------------------
    DataToNapiUint8Array(callbackParam->env,ivData,ivDatalen,&Callback_argv[1]);
    DataToNapiUint8Array(callbackParam->env,encData,encDatalen,&Callback_argv[2]);
    //-------------------------------
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->DecryptSM4CBCCallBack_obj, 3, Callback_argv, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
//(publicKey:Key,sourceData:Uint8Array) => Uint8Array
void EncryptSM2CallBackFunc(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    //OH_LOG_ERROR(LOG_APP, "EncryptSM2CallBackFunc => begin");   
    if ( callbackParam->env == NULL || callbackParam->EncryptSM2CallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_argv[2];
    //-------------------------------
    napi_value pubkey;
    DataToNapiUint8Array(callbackParam->env,keyData,KeyDatalen,&pubkey);
    napi_value keyType;
    StringToNapiString(callbackParam->env,"SM2_Public",&keyType);
    napi_status status = napi_create_object(callbackParam->env, &Callback_argv[0]);
    if (status != napi_ok ) {
        return;  
    }
    napi_set_named_property(callbackParam->env, Callback_argv[0], "keyType", keyType);
    napi_set_named_property(callbackParam->env, Callback_argv[0], "key", pubkey);
    //-------------------------------
    DataToNapiUint8Array(callbackParam->env,sourceData,sourceDatalen,&Callback_argv[1]);
    //-------------------------------
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->EncryptSM2CallBack_obj, 2, Callback_argv, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
//(encryptData:Uint8Array) => Uint8Array
void DecryptSM2CallBackFunc(const void * param,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    //OH_LOG_ERROR(LOG_APP, "DecryptSM2CallBackFunc => begin");      
    if ( callbackParam->env == NULL || callbackParam->DecryptSM2CallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_argv[1];
    DataToNapiUint8Array(callbackParam->env,encData,encDatalen,&Callback_argv[0]);
    
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->DecryptSM2CallBack_obj, 1, Callback_argv, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------
//(len : number) => Uint8Array
void GenerateRandomCallBackFunc(const void * param,size_t len,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    CALLBACKFUNC_PARAM * callbackParam = (CALLBACKFUNC_PARAM *)param;
    //OH_LOG_ERROR(LOG_APP, "GenerateRandomCallBackFunc => begin");
    if ( callbackParam->env == NULL || callbackParam->GenerateRandomCallBack_obj == NULL ) {
        return;
    }
    
    napi_value Callback_argv[1];
    napi_create_int64(callbackParam->env, len, &Callback_argv[0]);
    
    napi_value Callback_ret;
    //------------------------------------
    napi_call_function(callbackParam->env, nullptr, callbackParam->GenerateRandomCallBack_obj, 1, Callback_argv, &Callback_ret);
    //------------------------------------
    size_t retDataLen = 0;  
    void* retData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(callbackParam->env, Callback_ret, &valuetype, &retDataLen, &retData, nullptr, nullptr);
    if ( retDataLen <= 0 || retData == NULL ) {
        return;
    }
    
    if ( outData == NULL || *outData == NULL ) {
        *outDatalen = retDataLen;
    } else {
        if ( *outDatalen >= retDataLen ) {
            *outDatalen = retDataLen;
            memcpy(*outData,(unsigned char *)retData, retDataLen);
        } else {
            *outDatalen = retDataLen;
        }
    }
    //------------------------------------
}
//-----------------------------------------------------------------------------------------------------------