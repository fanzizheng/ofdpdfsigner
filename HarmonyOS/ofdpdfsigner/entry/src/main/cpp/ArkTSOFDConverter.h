//
// Created on 2024/6/27.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSOFDConverter_H
#define ofdpdfsigner_ArkTSOFDConverter_H

#include "ArkTSUtils.h"

napi_value OFDToImage(napi_env env, napi_callback_info info);
napi_value OFDPageToImage(napi_env env, napi_callback_info info);
napi_value OFDToImageZip(napi_env env, napi_callback_info info);
napi_value OfdToPdf(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSOFDConverter_H
