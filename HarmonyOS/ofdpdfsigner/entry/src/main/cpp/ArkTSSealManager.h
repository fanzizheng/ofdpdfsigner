//
// Created on 2024/7/1.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSSealManager_H
#define ofdpdfsigner_ArkTSSealManager_H

#include "ArkTSUtils.h"

napi_value CreateSeal(napi_env env, napi_callback_info info);
napi_value VerifySeal(napi_env env, napi_callback_info info);
napi_value GetSealImageData(napi_env env, napi_callback_info info);
napi_value GetSealUserCertData(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSSealManager_H
