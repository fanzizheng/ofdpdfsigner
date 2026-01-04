//
// Created on 2024/7/4.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSOFDStamp_H
#define ofdpdfsigner_ArkTSOFDStamp_H

#include "ArkTSUtils.h"

napi_value OFDPositionSign(napi_env env, napi_callback_info info);
napi_value OFDRidingSign(napi_env env, napi_callback_info info);
napi_value OFDKeywordSign(napi_env env, napi_callback_info info);
napi_value OFDVerify(napi_env env, napi_callback_info info);
napi_value OFDClearSigns(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSOFDStamp_H
