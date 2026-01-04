//
// Created on 2024/6/27.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSPDFConverter_H
#define ofdpdfsigner_ArkTSPDFConverter_H

#include "ArkTSUtils.h"

napi_value PDFToImage(napi_env env, napi_callback_info info);
napi_value PDFPageToImage(napi_env env, napi_callback_info info);
napi_value PDFToImageZip(napi_env env, napi_callback_info info);
napi_value PdfToOfd(napi_env env, napi_callback_info info);

#endif //ofdpdfsigner_ArkTSPDFConverter_H
