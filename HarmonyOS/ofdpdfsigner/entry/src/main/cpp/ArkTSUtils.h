//
// Created on 2024/6/24.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSUtils_H
#define ofdpdfsigner_ArkTSUtils_H

#include "napi/native_api.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "hilog/log.h"

struct CALLBACKFUNC_PARAM {
    napi_env env;
    napi_value signCallBack_obj;
    napi_value userCertCallBack_obj;
    napi_value sealCertCallBack_obj;
    napi_value virifyCallBack_obj;
    napi_value getFontCallBack_obj;
    
    napi_value EncryptSM4CBCCallBack_obj;
    napi_value DecryptSM4CBCCallBack_obj;
    napi_value EncryptSM2CallBack_obj;
    napi_value DecryptSM2CallBack_obj;
    napi_value GenerateRandomCallBack_obj;
};

void NapiStringUtf8ToString(napi_env env,napi_value value,FZZBytes & outData);
void NapiStringUtf8ToCString(napi_env env,napi_value value,string & outStr);
void NapiObjectPropertyToString(napi_env env,napi_value object,char * propertyName,string & outStr);
void NapiObjectPropertyToData(napi_env env,napi_value object,char * propertyName,FZZBytes & outData);
void NapiObjectPropertyToObject(napi_env env,napi_value object,char * propertyName,napi_value* result);

void StringToNapiString(napi_env env,char * data,napi_value* result);
void DataToNapiUint8Array(napi_env env,unsigned char * data,size_t datalen,napi_value* result);

napi_value ReturnBool(napi_env env,bool value);

#endif //ofdpdfsigner_ArkTSUtils_H
