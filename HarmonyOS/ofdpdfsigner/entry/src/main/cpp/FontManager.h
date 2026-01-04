//
// Created on 2024/6/24.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_FontManager_H
#define ofdpdfsigner_FontManager_H

#include "ArkTSUtils.h"

napi_value SaveFontFileNameCache(napi_env env, napi_callback_info info);
napi_value GetAllSystemFontFileName(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_FontManager_H
