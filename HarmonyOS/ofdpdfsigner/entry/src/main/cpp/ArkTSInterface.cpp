//
// Created on 2024/6/13.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSInterface.h"
#include "napi/native_api.h"
#include <cstdio>
#include "SystemMamager.h"
#include "FontManager.h"
#include "ArkTSCrypto.h"
#include "ArkTSPDF.h"
#include "ArkTSOFD.h"
#include "ArkTSOFDConverter.h"
#include "ArkTSPDFConverter.h"
#include "ArkTSSealManager.h"
#include "ArkTSWaterMark.h"
#include "ArkTSPDFStamp.h"
#include "ArkTSOFDStamp.h"

//-----------------------------------------------------------------------------------------------------------
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "getAllSystemFontFileName", nullptr, GetAllSystemFontFileName, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "saveFontFileNameCache", nullptr, SaveFontFileNameCache, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "setTempPath", nullptr, SetTempPath, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "setWorkPath", nullptr, SetWorkPath, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "generateRandom", nullptr, GenerateRandom, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "generateDigest", nullptr, GenerateDigest, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "generateSymKey", nullptr, GenerateSymKey, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "generateAsymKey", nullptr, GenerateAsymKey, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "encrypt", nullptr, Encrypt, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "decrypt", nullptr, Decrypt, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "encryptSM4CBC", nullptr, EncryptSM4CBC, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "decryptSM4CBC", nullptr, DecryptSM4CBC, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "sign", nullptr, Sign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "verify", nullptr, Verify, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "generateRootCert", nullptr, GenerateRootCert, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "generateCert", nullptr, GenerateCert, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_open", nullptr, PDFOpen, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_close", nullptr, PDFClose, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_open", nullptr, OFDOpen, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_close", nullptr, OFDClose, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_getPageCount", nullptr, PDFGetPageCount, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_getPageSize", nullptr, PDFGetPageSize, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_getPageCount", nullptr, OFDGetPageCount, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_getPageSize", nullptr, OFDGetPageSize, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_toImage", nullptr, PDFToImage, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_toImage", nullptr, OFDToImage, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_pageToImage", nullptr, PDFPageToImage, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_pageToImage", nullptr, OFDPageToImage, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_toImageZip", nullptr, PDFToImageZip, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_toImageZip", nullptr, OFDToImageZip, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdfToOfd", nullptr, PdfToOfd, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofdToPdf", nullptr, OfdToPdf, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "createSeal", nullptr, CreateSeal, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "verifySeal", nullptr, VerifySeal, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "getSealImageData", nullptr, GetSealImageData, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "getSealUserCertData", nullptr, GetSealUserCertData, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_positionSign", nullptr, OFDPositionSign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_ridingSign", nullptr, OFDRidingSign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_keywordSign", nullptr, OFDKeywordSign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_verify", nullptr, OFDVerify, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_clearSigns", nullptr, OFDClearSigns, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_positionSign", nullptr, PDFPositionSign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_ridingSign", nullptr, PDFRidingSign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_keywordSign", nullptr, PDFKeywordSign, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_verify", nullptr, PDFVerify, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_clearSigns", nullptr, PDFClearSigns, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_isNeedPassWord", nullptr, PDFIsNeedPassWord, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_setPassWord", nullptr, PDFSetPassWord, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "pdf_documnetEncryptDecrypt", nullptr, PDFDocumnetEncryptDecrypt, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "ofd_isProtect", nullptr, OFDIsProtect, nullptr, nullptr, nullptr, napi_default, nullptr },  
        { "ofd_isEncrypt", nullptr, OFDIsEncrypt, nullptr, nullptr, nullptr, napi_default, nullptr }, 
        { "ofd_protect", nullptr, OFDProtect, nullptr, nullptr, nullptr, napi_default, nullptr }, 
        { "ofd_protectionVerify", nullptr, OFDProtectionVerify, nullptr, nullptr, nullptr, napi_default, nullptr }, 
        { "ofd_encryptDocument", nullptr, OFDEncryptDocument, nullptr, nullptr, nullptr, napi_default, nullptr }, 
        { "ofd_decryptDocument", nullptr, OFDDecryptDocument, nullptr, nullptr, nullptr, napi_default, nullptr }, 
        { "createWaterMark", nullptr, CreateWaterMark, nullptr, nullptr, nullptr, napi_default, nullptr }
    
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version =1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "ofdpdfsigner",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
//-----------------------------------------------------------------------------------------------------------