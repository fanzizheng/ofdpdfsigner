//
// Created on 2024/6/24.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSCrypto_H
#define ofdpdfsigner_ArkTSCrypto_H

#include "ArkTSUtils.h"

napi_value GenerateRandom(napi_env env, napi_callback_info info);
napi_value GenerateDigest(napi_env env, napi_callback_info info);
napi_value GenerateSymKey(napi_env env, napi_callback_info info);
napi_value GenerateAsymKey(napi_env env, napi_callback_info info);
napi_value Encrypt(napi_env env, napi_callback_info info);
napi_value Decrypt(napi_env env, napi_callback_info info);
napi_value EncryptSM4CBC(napi_env env, napi_callback_info info);
napi_value DecryptSM4CBC(napi_env env, napi_callback_info info);
napi_value Sign(napi_env env, napi_callback_info info);
napi_value Verify(napi_env env, napi_callback_info info);
napi_value GenerateRootCert(napi_env env, napi_callback_info info);
napi_value GenerateCert(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSCrypto_H
