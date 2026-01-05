//
//  Created by zizheng fan on 2023/12/15.
//
//  该接口为java jni 接口
//  函数说明参见 java 版 sdk 接口说明文档
//
#ifndef FZZJNIINTERFACE_H
#define FZZJNIINTERFACE_H

#include <jni.h>

#define JNI_TYPE_SM2 0
#define JNI_TYPE_SM3 1
#define JNI_TYPE_SM4 2
#define JNI_TYPE_SM3_SM2 10

struct JNICALLBACKFUNC_PARAM {
    JNIEnv * env;
    jobject CallBack_obj;
};

#ifdef __cplusplus
extern "C" {
#endif
  
//-----------------------------------------------------------------------------------------------------------------
/***********************************************Crypto**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateRandom
  (JNIEnv *, jobject, jint, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_digest
  (JNIEnv *, jobject, jint, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateKey
  (JNIEnv *, jobject, jint, jint, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateKeyPair
  (JNIEnv *, jobject, jint, jint, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_encrypt
  (JNIEnv *, jobject, jint, jbyteArray, jint, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_decrypt
  (JNIEnv *, jobject, jint, jbyteArray, jint, jbyteArray, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_sign
  (JNIEnv *, jobject, jint, jbyteArray, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_verifySign
  (JNIEnv *, jobject, jint, jbyteArray, jbyteArray, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateRootCert
  (JNIEnv *, jobject, jint, jbyteArray, jbyteArray,jint, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateCert
  (JNIEnv *, jobject, jint, jint, jbyteArray, jbyteArray,jint, jbyteArray, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_encryptSM4CBC
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_decryptSM4CBC
  (JNIEnv *, jobject,  jbyteArray, jbyteArray, jbyteArray, jobject);

//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFConverter*********************************************************/
//-----------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDConverter*********************************************************/
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
/****************************************************Seal*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_createSeal
(JNIEnv *, jobject, jbyteArray,jint,jbyteArray,jint ,jint ,jbyteArray ,jbyteArray  ,jbyteArray ,jbyteArray,jbyteArray,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getSealImageData
(JNIEnv *, jobject, jbyteArray,jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getSealUserCertData
(JNIEnv *, jobject, jbyteArray,jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_verifySeal
(JNIEnv *, jobject, jbyteArray,jobject, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDStamp*********************************************************/
//-----------------------------------------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDVerifyDocment
(JNIEnv *, jobject, jbyteArray,jobject, jobject);

//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFStamp*********************************************************/
//-----------------------------------------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFVerifyDocment
(JNIEnv *, jobject, jbyteArray,jbyteArray,jobject, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************FONT*********************************************************/
//-----------------------------------------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_GetAllSystemFontFileName
(JNIEnv *, jobject, jobject, jobject);

JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_saveFontFileNameCache
(JNIEnv *, jobject, jbyteArray, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Util*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_SetWorkPath
(JNIEnv *, jobject, jbyteArray, jobject);
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_SetTempPath
(JNIEnv *, jobject, jbyteArray, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************打开关闭文件句柄*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_openOFD
(JNIEnv *, jobject, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_closeOFD
(JNIEnv *, jobject, jlong);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_openPDF
(JNIEnv *, jobject, jbyteArray, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_closePDF
(JNIEnv *, jobject, jlong);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDStamp handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDSignStamp_1Pos_1Handle
(JNIEnv *, jobject, jlong,jbyteArray,jint,jdouble,jdouble,jdouble,jdouble,jboolean,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDSignStamp_1Riding_1Handle
(JNIEnv *, jobject,jlong, jbyteArray,jint,jdouble,jdouble,jboolean,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDSignStamp_1KeyWord_1Handle
(JNIEnv *, jobject, jlong,jbyteArray,jbyteArray,jbyteArray,jdouble,jdouble,jboolean,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDClearStamps
(JNIEnv *, jobject, jlong, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDConverter handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getOFDPageCount_1Handle
  (JNIEnv *, jobject, jlong, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getOFDPageSize_1Handle
(JNIEnv *, jobject , jlong , jint , jobject );
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofdPage2Image_1Handle
  (JNIEnv *, jobject, jlong,jint,jint,jdouble, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofd2Image_1Handle
  (JNIEnv *, jobject, jlong,jint,jdouble, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofd2ImageToZip_1Handle
  (JNIEnv *, jobject, jlong,jint,jdouble, jobject);
//--
//1: true 0: false
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofd2PDF_1Handle
  (JNIEnv *, jobject, jlong,jint,jint,jbyteArray, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFConverter handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getPDFPageCount_1Handle
  (JNIEnv *, jobject, jlong, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getPDFPageSize_1Handle
  (JNIEnv *, jobject, jlong, jint , jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdfPage2Image_1Handle
  (JNIEnv *, jobject, jlong,jint,jint,jdouble, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdf2Image_1Handle
  (JNIEnv *, jobject, jlong,jint,jdouble, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdf2ImageToZip_1Handle
  (JNIEnv *, jobject, jlong,jint,jdouble, jobject);
//--
//1: true 0: false
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdf2OFD_1Handle
  (JNIEnv *, jobject, jlong,jint, jobject);

//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFStamp handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSignStamp_1Pos_1Handle
(JNIEnv *, jobject, jlong,jbyteArray,jdouble,jint,jdouble,jdouble,jdouble,jdouble,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSignStamp_1Riding_1Handle
(JNIEnv *, jobject, jlong,jbyteArray,jdouble,jint,jdouble,jdouble,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSignStamp_1KeyWord_1Handle
(JNIEnv *, jobject, jlong,jbyteArray,jdouble,jbyteArray,jbyteArray,jdouble,jdouble,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFClearStamps
(JNIEnv *, jobject, jlong, jobject);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Watermark image*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_CreateWaterMark
(JNIEnv * , jobject , jboolean ,jboolean,jdouble ,jdouble ,jdouble ,jdouble ,jbyteArray,jint ,jdouble ,jdouble ,
 jbyteArray ,jbyteArray ,jdouble ,jboolean ,jboolean ,jdouble ,
 jdouble ,jdouble ,jdouble ,

 jbyteArray ,jbyteArray ,jdouble ,jboolean ,jboolean ,jdouble ,
 jdouble ,jdouble ,jdouble ,

 jbyteArray ,jbyteArray ,jdouble ,jboolean ,jboolean ,jdouble ,
 jdouble ,jdouble ,jdouble ,
 jdouble ,jdouble ,jdouble ,jdouble , jobject retdata);
//----------------------------------------------------------------------------------------------------
/****************************************PDFEncrypt****************************/
//----------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFIsEncryptPassward
 (JNIEnv * , jobject,jlong,jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSetPassword
 (JNIEnv * , jobject,jlong,jbyteArray,jobject retdata);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFEncryptDecrypt
 (JNIEnv * , jobject,jlong,jint,jbyteArray,jobject retdata);
//----------------------------------------------------------------------------------------------------
/****************************************OFDProtect****************************/
//----------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDIsProtect
 (JNIEnv * , jobject,jlong,jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDProtect_1Handle
(JNIEnv *, jobject, jlong ,jobject, jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDProtectionVerify_1Handle
(JNIEnv *, jobject, jlong ,jobject, jobject);
//----------------------------------------------------------------------------------------------------
/****************************************OFDEncrypt****************************/
//----------------------------------------------------------------------------------------------------
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDIsEncrypt
 (JNIEnv * , jobject,jlong,jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDEncryptDocument_1Handle
 (JNIEnv * , jobject,jlong,jbyteArray,jobject,jobject);
//--
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDDecryptDocument_1Handle
 (JNIEnv * , jobject,jlong,jint,jbyteArray,jbyteArray,jbyteArray,jobject,jobject);
//----------------------------------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif

#endif //FZZJNIINTERFACE_H

