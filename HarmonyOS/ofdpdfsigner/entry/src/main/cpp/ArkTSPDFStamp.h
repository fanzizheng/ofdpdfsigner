//
// Created on 2024/7/4.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSPDFStamp_H
#define ofdpdfsigner_ArkTSPDFStamp_H

#include "ArkTSUtils.h"

napi_value PDFPositionSign(napi_env env, napi_callback_info info);
napi_value PDFRidingSign(napi_env env, napi_callback_info info);
napi_value PDFKeywordSign(napi_env env, napi_callback_info info);
napi_value PDFVerify(napi_env env, napi_callback_info info);
napi_value PDFClearSigns(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSPDFStamp_H
