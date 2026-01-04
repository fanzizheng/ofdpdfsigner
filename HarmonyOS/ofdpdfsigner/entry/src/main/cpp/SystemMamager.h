//
// Created on 2024/6/21.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_SystemMamager_H
#define ofdpdfsigner_SystemMamager_H

#include "ArkTSUtils.h"


napi_value SetTempPath(napi_env env, napi_callback_info info);
napi_value SetWorkPath(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_SystemMamager_H
