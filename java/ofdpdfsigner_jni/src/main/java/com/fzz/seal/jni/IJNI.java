package com.fzz.seal.jni;

import com.fzz.seal.callback.*;

public class IJNI {
    static {
        System.loadLibrary("ofdpdfsigner");
    }

    //-----------------------------------------------------------------------------------------------
    //Crypto
    //-----------------------------------------------------------------------------------------------
    public static native void generateRandom(int len,ReturnData retData);
    public static native void digest(int algType, byte[] sourceData,ReturnData retData);
    public static native void generateKey(int algType, int keyLength,ReturnData retData);
    public static native void generateKeyPair(int algType, int keyLength,ReturnData retData);
    public static native void decrypt(int keyType, byte[] deKey,int algType,byte[] encryptedData,byte[] sm4GCMData,ReturnData retData);
    public static native void encrypt(int keyType, byte[] enKey,int algType,byte[] sourceData,ReturnData retData);
    public static native void sign(int algType, byte[] prvKey, byte[] sourceData,ReturnData retData);
    public static native void verifySign(int algType, byte[] pubKey, byte[] sourceData, byte[] signData,ReturnData retData);
    public static native void generateRootCert(int keyType,byte[] DN, byte[] pubKey, int days, byte[] rootPriKey,ReturnData retData);
    public static native void generateCert(int keyType,int isSign,byte[] DN, byte[] pubKey, int days,byte[] rootDN,byte[] rootPriKey,ReturnData retData);
    public static native void decryptSM4CBC(byte[] deKey,byte[] iv,byte[] encryptedData,ReturnData retData);
    public static native void encryptSM4CBC(byte[] enKey,byte[] iv,byte[] sourceData,ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //印章
    //-----------------------------------------------------------------------------------------------
    public static native void createSeal(byte[] sealid,int type,byte[] sealname,int width, int height,byte[] createTime,byte[] startTime,byte[] endTime,byte[] imagetype,byte[] imageData, ISignCallBack signCallBack, ReturnData retData);
    public static native void getSealImageData(byte[] sealData, ReturnData retData);
    public static native void getSealUserCertData(byte[] sealData, ReturnData retData);
    public static native void verifySeal(byte[] sealData, IVerifyCallBack verifyCallBack, ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //字体管理
    //-----------------------------------------------------------------------------------------------
    public static native void GetAllSystemFontFileName(ISystemFontFileNameCallBack systemFontFileNameCallBack, ReturnData retData);
    public static native void saveFontFileNameCache(byte[] fontFileName, ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //系统管理
    //-----------------------------------------------------------------------------------------------
    public static native void SetWorkPath(byte[] path, ReturnData retData);
    public static native void SetTempPath(byte[] path, ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //打开关闭文件句柄
    //-----------------------------------------------------------------------------------------------
    public static native void openOFD(byte[] fileData, ReturnData retData);
    public static native void closeOFD(long handle);
    public static native void openPDF(byte[] fileData, ReturnData retData);
    public static native void closePDF(long handle);
    //-----------------------------------------------------------------------------------------------
    //OFD 印章 文件句柄
    //-----------------------------------------------------------------------------------------------
    public static native void OFDSignStamp_Pos_Handle(long fileHande,byte[] stampData, int pageIndex,double x,double y,
                                                      double stampwidth, double stampheight,boolean isContinueSign,
                                                      ISignCallBack signCallBack, ReturnData retData);
    public static native void OFDSignStamp_Riding_Handle(long fileHande,byte[] stampData, int RidingType,
                                                         double stampwidth, double stampheight,boolean isContinueSign,
                                                         ISignCallBack signCallBack, ReturnData retData);
    public static native void OFDSignStamp_KeyWord_Handle(long fileHandle,byte[] stampData, byte[] keyword,byte[] KeywordRule,
                                                          double stampwidth, double stampheight,boolean isContinueSign,
                                                          ISignCallBack signCallBack, ReturnData retData);

    public static native void OFDClearStamps(long fileHande,ReturnData retData);

    public static native void OFDVerifyDocment(byte[] docdata,IVerifyCallBack verifyCallBack, ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //OFD 转换 文件句柄
    //-----------------------------------------------------------------------------------------------
    public static native void getOFDPageCount_Handle(long fileHande,ReturnData retData);
    public static native void getOFDPageSize_Handle(long fileHande,int pageNumber,ReturnData retData);
    public static native void ofdPage2Image_Handle(long fileHandle,int imageType,int pageIndex,double scale,ReturnData retData);
    public static native void ofd2Image_Handle(long fileHandle,int imageType,double scale,ReturnData retData);
    public static native void ofd2ImageToZip_Handle(long fileHandle,int imageType,double scale,ReturnData retData);
    //isNoStamp -> 1: true 0: false
    public static native void ofd2PDF_Handle(long fileHande,int isNoStamp,int isEncrypt,byte[] passWord,ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //PDF 转换 文件句柄
    //-----------------------------------------------------------------------------------------------
    public static native void getPDFPageCount_Handle(long fileHande,ReturnData retData);
    public static native void getPDFPageSize_Handle(long fileHande,int pageNumber,ReturnData retData);
    public static native void pdfPage2Image_Handle(long fileHande,int imageType,int pageIndex,double scale,ReturnData retData);
    public static native void pdf2Image_Handle(long fileHande,int imageType,double scale,ReturnData retData);
    public static native void pdf2ImageToZip_Handle(long fileHande,int imageType,double scale,ReturnData retData);
    //isNoStamp -> 1: true 0: false
    public static native void pdf2OFD_Handle(long fileHande,int isNoStamp,ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //PDF 印章 文件句柄
    //-----------------------------------------------------------------------------------------------
    public static native void PDFSignStamp_Pos_Handle(long fileHande,byte[] imageData,double alpha, int pageIndex,double x,double y,
                                                      double stampwidth, double stampheight,
                                                      ISignCallBack signCallBack, ReturnData retData);
    public static native void PDFSignStamp_Riding_Handle(long fileHande,byte[] imageData,double alpha, int RidingType,
                                                         double stampwidth, double stampheight,
                                                         ISignCallBack signCallBack, ReturnData retData);
    public static native void PDFSignStamp_KeyWord_Handle(long fileHande,byte[] imageData,double alpha, byte[] keyword,byte[] KeywordRule,
                                                          double stampwidth, double stampheight,
                                                          ISignCallBack signCallBack, ReturnData retData);
    public static native void PDFClearStamps(long fileHande,ReturnData retData);

    public static native void PDFVerifyDocment(byte[] docdata,byte[] passWord,IVerifyCallBack verifyCallBack, ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //水印图片
    //-----------------------------------------------------------------------------------------------
    public static native void CreateWaterMark(boolean isTile,boolean isImage,  double pageWidth,
                                              double pageHeight,double X,double Y,byte[] imageData,
                                              int textAlign,double horizontalSpacing,double verticalSpacing,
                                              byte[] text_1,byte[] fontName_1,double fontSize_1,
                                              int isBlob_1,int isItalic_1,double colorR_1,
                                              double colorG_1,double colorB_1,double alpha_1,

                                              byte[] text_2,byte[] fontName_2,double fontSize_2,
                                              int isBlob_2,int isItalic_2,double colorR_2,
                                              double colorG_2,double colorB_2,double alpha_2,

                                              byte[] text_3,byte[] fontName_3,double fontSize_3,
                                              int isBlob_3,int isItalic_3,double colorR_3,
                                              double colorG_3,double colorB_3,double alpha_3,

                                              double lineSpacing0_1,double lineSpacing1_2,
                                              double rotate,double scaled,ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //PDF 密码
    //-----------------------------------------------------------------------------------------------
    public static native void PDFIsEncryptPassward(long fileHande,ReturnData retData);
    public static native void PDFSetPassword(long fileHande,byte[] passsword,ReturnData retData);
    public static native void PDFEncryptDecrypt(long fileHande,int isEncrypt,byte[] passsword,ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //OFD 完整性保护
    //-----------------------------------------------------------------------------------------------
    public static native void OFDIsProtect(long fileHande,ReturnData retData);
    public static native void OFDProtect_Handle(long fileHande,ISignCallBack signCallBack, ReturnData retData);
    public static native void OFDProtectionVerify_Handle(long fileHande,IVerifyCallBack verifyCallBack, ReturnData retData);
    //-----------------------------------------------------------------------------------------------
    //OFD 文档加密
    //-----------------------------------------------------------------------------------------------
    public static native void OFDIsEncrypt(long fileHande,ReturnData retData);
    public static native void OFDEncryptDocument_Handle(long fileHande, byte[] userInfo, IEncryptCallBack encryptCallBack, ReturnData retData);
    public static native void OFDDecryptDocument_Handle(long fileHande, int mode,byte[] passWord,byte[] userName,byte[] userType, IEncryptCallBack encryptCallBack, ReturnData retData);
}
