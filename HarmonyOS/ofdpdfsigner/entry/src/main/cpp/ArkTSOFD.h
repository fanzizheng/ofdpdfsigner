//
// Created on 2024/6/26.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSOFD_H
#define ofdpdfsigner_ArkTSOFD_H

#include "ArkTSUtils.h"

napi_value OFDOpen(napi_env env, napi_callback_info info);
napi_value OFDClose(napi_env env, napi_callback_info info);
napi_value OFDGetPageCount(napi_env env, napi_callback_info info);
napi_value OFDGetPageSize(napi_env env, napi_callback_info info);
napi_value OFDIsProtect(napi_env env, napi_callback_info info);
napi_value OFDIsEncrypt(napi_env env, napi_callback_info info);
napi_value OFDProtect(napi_env env, napi_callback_info info);
napi_value OFDProtectionVerify(napi_env env, napi_callback_info info);
napi_value OFDEncryptDocument(napi_env env, napi_callback_info info);
napi_value OFDDecryptDocument(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSOFD_H
