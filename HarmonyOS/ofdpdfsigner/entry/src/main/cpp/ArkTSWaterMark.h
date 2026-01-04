//
// Created on 2024/7/4.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSWaterMark_H
#define ofdpdfsigner_ArkTSWaterMark_H

#include "ArkTSUtils.h"

napi_value CreateWaterMark(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSWaterMark_H
