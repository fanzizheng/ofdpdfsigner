//
// Created on 2024/6/26.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSPDF_H
#define ofdpdfsigner_ArkTSPDF_H

#include "ArkTSUtils.h"

napi_value PDFOpen(napi_env env, napi_callback_info info);
napi_value PDFClose(napi_env env, napi_callback_info info);
napi_value PDFGetPageCount(napi_env env, napi_callback_info info);
napi_value PDFGetPageSize(napi_env env, napi_callback_info info);
napi_value PDFIsNeedPassWord(napi_env env, napi_callback_info info);
napi_value PDFSetPassWord(napi_env env, napi_callback_info info);
napi_value PDFDocumnetEncryptDecrypt(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSPDF_H
