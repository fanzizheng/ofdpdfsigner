#ifndef OFDPDFSIGNERPROXY_H
#define OFDPDFSIGNERPROXY_H

#include "util.h"

#include <QLibrary>

typedef void (*AttachmentFileFunc)(const char* const filename,
                                   const char * const time,
                                   const unsigned char* const filedata,
                                   int filedatalen);
typedef void (*AnnotsFunc)(int pagenum,
                           const char * const creator,
                           const char* const time,
                           const char* const type,
                           const char* const remark);
typedef void (*StampsFunc)(const char* const pagenum,
                           const char * const time,
                           const char * const sid,
                           const unsigned char* imagedata,
                           int imagedatalen);
typedef void (*FindWordFunc)(int pageIndex,const char* const word,float x,float y,float w,float h);
//-----------------------------------------

typedef void * HANDLE;

typedef void (*CallBack_SystemFontFileNameFunc)(const void * param,const char* const fullFileName);

typedef void (*TYPE_FreeHandle)(HANDLE handle);
typedef bool (*TYPE_setWorkPath)(const char* const workpath);
typedef bool (*TYPE_saveFontFileNameCache)(const char* const fontFileName);
typedef bool (*TYPE_getAllSystemFontFileName)(CallBack_SystemFontFileNameFunc systemFontFileNameFunc,const void * callBack_Param);
typedef bool (*TYPE_getImageWidthHeight)(const unsigned char * const imageData,size_t imageLenght,/*out*/size_t* imageWidth,/*out*/size_t* imageHeight);
typedef bool (*TYPE_splitImage)(const unsigned char * const imageData,int imageLenght,const char * imageType,bool isHorizontal,size_t count,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen,size_t* imageWidth,size_t* imageHeight);

typedef HANDLE (*TYPE_ofd_open)(const unsigned char * const ofdData,int ofdDatalen);
typedef void (*TYPE_ofd_close)(HANDLE fileHandle);
typedef int (*TYPE_ofd_getPageCount)(HANDLE fileHandle);
typedef bool (*TYPE_ofd_pageToImage)(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef bool (*TYPE_ofd_toImage)(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen);
typedef bool (*TYPE_ofdToPdf)(HANDLE handle,bool isNoStamp,bool isEncrypt,const char * password,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef void (*TYPE_ofd_getOtherInfo)(HANDLE obj,AttachmentFileFunc attachmentFileFunc,AnnotsFunc annotsFunc,StampsFunc stampsFunc);
typedef bool (*TYPE_ofd_findWord)(HANDLE handle,int pageIndex,const char* const word,FindWordFunc findWordFunc);

typedef HANDLE (*TYPE_pdf_open)(const unsigned char * const fileData,int fileDatalen);
typedef void (*TYPE_pdf_close)(HANDLE fileHandle);
typedef int (*TYPE_pdf_getPageCount)(HANDLE fileHandle);
typedef bool (*TYPE_pdf_pageToImage)(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef bool (*TYPE_pdf_toImage)(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen);
typedef bool (*TYPE_pdfToOfd)(HANDLE handle,bool isNoStamp,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef void (*TYPE_pdf_getOtherInfo)(HANDLE obj,AttachmentFileFunc attachmentFileFunc,AnnotsFunc annotsFunc,StampsFunc stampsFunc);
typedef bool (*TYPE_pdf_findWord)(HANDLE handle,int pageIndex,const char* const word,FindWordFunc findWordFunc);

typedef int (*TYPE_getSealImageData)(const unsigned char * const sealData,int sealDatalen,/*out*/unsigned char ** outImageData,/*out*/size_t * outImageDatalen);

typedef int (*TYPE_testCreateSeal)(const unsigned char * const imageData,int imageDatalen,
                                  /*out*/unsigned char ** outSealData,/*out*/int * outSealDatalen,
                                  /*out*/unsigned char ** outSealUserCert,/*out*/int * outSealUserCertlen,
                                  /*out*/unsigned char ** outSealUserCertPriKey,/*out*/int * outSealUserCertPriKeylen
                                  );
typedef int  (*TYPE_testOFDVerify)(const unsigned char * const ofdData,int ofdDatalen,
                                 const char* const sid,
                                 /*out*/char ** outSignTime,/*out*/int * outSignTimelen,
                                 /*out*/char ** outSignDn,/*out*/int * outSignDnlen);

typedef int (*TYPE_testPDFVerify)(const unsigned char * const pdfData,int pdfDatalen,
                                 const char* const sid,
                                 /*out*/char ** outSignTime,/*out*/int * outSignTimelen,
                                 /*out*/char ** outSignDn,/*out*/int * outSignDnlen);

typedef int  (*TYPE_testOFDPositionSign)(const unsigned char * const stampData,int stampDatalen,
                                       const unsigned char * const certData,int certDatalen,
                                       const unsigned char * const privateKeyData,int privateKeyDatalen,
                                       const unsigned char * const ofdData,int ofdDatalen,
                                       int pageIndex,double x,double y, double stampwidth,
                                       double stampheight,bool isContinueSign,
                                       /*out*/unsigned char ** outData,/*out*/int * outDatalen);

typedef int  (*TYPE_testPDFPositionSign)(const unsigned char * const stampData,int stampDatalen,
                                       const unsigned char * const certData,int certDatalen,
                                       const unsigned char * const privateKeyData,int privateKeyDatalen,
                                       const unsigned char * const pdfData,int pdfDatalen,
                                       int pageIndex,double x,double y, double stampwidth,
                                       double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen);

typedef int (*TYPE_testOFDRidingSign)(const unsigned char * const stampData,int stampDatalen,
                                     const unsigned char * const certData,int certDatalen,
                                     const unsigned char * const privateKeyData,int privateKeyDatalen,
                                     const unsigned char * const ofdData,int ofdDatalen,
                                     int RidingType, double stampwidth,
                                     double stampheight,bool isContinueSign,
                                     /*out*/unsigned char ** outData,/*out*/int * outDatalen);

typedef int (*TYPE_testPDFRidingSign)(const unsigned char * const stampData,int stampDatalen,
                                     const unsigned char * const certData,int certDatalen,
                                     const unsigned char * const privateKeyData,int privateKeyDatalen,
                                     const unsigned char * const pdfData,int pdfDatalen,
                                     int RidingType, double stampwidth,
                                     double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen);

typedef int (*TYPE_testOFDKeywordSign)(const unsigned char * const stampData,int stampDatalen,
                                      const unsigned char * const certData,int certDatalen,
                                      const unsigned char * const privateKeyData,int privateKeyDatalen,
                                      const unsigned char * const ofdData,int ofdDatalen,
                                      const char * const keyword,const char * const KeywordRule, double stampwidth,
                                      double stampheight,bool isContinueSign,
                                      /*out*/unsigned char ** outData,/*out*/int * outDatalen);

typedef int (*TYPE_testPDFKeywordSign)(const unsigned char * const stampData,int stampDatalen,
                                      const unsigned char * const certData,int certDatalen,
                                      const unsigned char * const privateKeyData,int privateKeyDatalen,
                                      const unsigned char * const pdfData,int pdfDatalen,
                                      const char * const keyword,const char * const KeywordRule, double stampwidth,
                                      double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen);


typedef bool (*TYPE_testVerifySeal)(const unsigned char * const imageData,int imageDatalen);

class OFDPDFSignerProxy
{
public:
    OFDPDFSignerProxy();
    ~OFDPDFSignerProxy();
    bool init(const char * const dllname);

public:
    void FreeHandle(HANDLE handle);
    bool setWorkPath(const char* const workpath);
    bool saveFontFileNameCache(const char* const fontFileName);
    bool getAllSystemFontFileName(CallBack_SystemFontFileNameFunc systemFontFileNameFunc,const void * callBack_Param);
    bool getImageWidthHeight(const unsigned char * const imageData,size_t imageLenght,/*out*/size_t* imageWidth,/*out*/size_t* imageHeight);
    bool splitImage(const unsigned char * const imageData,int imageLenght,const char * imageType,bool isHorizontal,size_t count,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen,size_t* imageWidth,size_t* imageHeight);

    HANDLE ofd_open(const unsigned char * const ofdData,int ofdDatalen);
    void ofd_close(HANDLE fileHandle);
    int ofd_getPageCount(HANDLE fileHandle);
    bool ofd_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
    bool ofd_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen);
    bool ofdToPdf(HANDLE handle,bool isNoStamp,bool isEncrypt,const char * password,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
    void ofd_getOtherInfo(HANDLE obj,AttachmentFileFunc attachmentFileFunc,AnnotsFunc annotsFunc,StampsFunc stampsFunc);
    bool ofd_findWord(HANDLE handle,int pageIndex,const char* const word,FindWordFunc findWordFunc);

    HANDLE pdf_open(const unsigned char * const fileData,int fileDatalen);
    void pdf_close(HANDLE fileHandle);
    int pdf_getPageCount(HANDLE fileHandle);
    bool pdf_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
    bool pdf_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen);
    bool pdfToOfd(HANDLE handle,bool isNoStamp,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
    void pdf_getOtherInfo(HANDLE obj,AttachmentFileFunc attachmentFileFunc,AnnotsFunc annotsFunc,StampsFunc stampsFunc);
    bool pdf_findWord(HANDLE handle,int pageIndex,const char* const word,FindWordFunc findWordFunc);

    int getSealImageData(const unsigned char * const sealData,int sealDatalen,/*out*/unsigned char ** outImageData,/*out*/size_t * outImageDatalen);

    int testCreateSeal(const unsigned char * const imageData,int imageDatalen,
                                       /*out*/unsigned char ** outSealData,/*out*/int * outSealDatalen,
                                       /*out*/unsigned char ** outSealUserCert,/*out*/int * outSealUserCertlen,
                                       /*out*/unsigned char ** outSealUserCertPriKey,/*out*/int * outSealUserCertPriKeylen
                                       );
    int  testOFDVerify(const unsigned char * const ofdData,int ofdDatalen,
                                     const char* const sid,
                                     /*out*/char ** outSignTime,/*out*/int * outSignTimelen,
                                     /*out*/char ** outSignDn,/*out*/int * outSignDnlen);

    int testPDFVerify(const unsigned char * const pdfData,int pdfDatalen,
                                     const char* const sid,
                                     /*out*/char ** outSignTime,/*out*/int * outSignTimelen,
                                     /*out*/char ** outSignDn,/*out*/int * outSignDnlen);

    int  testOFDPositionSign(const unsigned char * const stampData,int stampDatalen,
                                           const unsigned char * const certData,int certDatalen,
                                           const unsigned char * const privateKeyData,int privateKeyDatalen,
                                           const unsigned char * const ofdData,int ofdDatalen,
                                           int pageIndex,double x,double y, double stampwidth,
                                           double stampheight,bool isContinueSign,
                                           /*out*/unsigned char ** outData,/*out*/int * outDatalen);

    int  testPDFPositionSign(const unsigned char * const stampData,int stampDatalen,
                                           const unsigned char * const certData,int certDatalen,
                                           const unsigned char * const privateKeyData,int privateKeyDatalen,
                                           const unsigned char * const pdfData,int pdfDatalen,
                                           int pageIndex,double x,double y, double stampwidth,
                                           double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen);

    int testOFDRidingSign(const unsigned char * const stampData,int stampDatalen,
                                         const unsigned char * const certData,int certDatalen,
                                         const unsigned char * const privateKeyData,int privateKeyDatalen,
                                         const unsigned char * const ofdData,int ofdDatalen,
                                         int RidingType, double stampwidth,
                                         double stampheight,bool isContinueSign,
                                         /*out*/unsigned char ** outData,/*out*/int * outDatalen);

    int testPDFRidingSign(const unsigned char * const stampData,int stampDatalen,
                                         const unsigned char * const certData,int certDatalen,
                                         const unsigned char * const privateKeyData,int privateKeyDatalen,
                                         const unsigned char * const pdfData,int pdfDatalen,
                                         int RidingType, double stampwidth,
                                         double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen);

    int testOFDKeywordSign(const unsigned char * const stampData,int stampDatalen,
                                          const unsigned char * const certData,int certDatalen,
                                          const unsigned char * const privateKeyData,int privateKeyDatalen,
                                          const unsigned char * const ofdData,int ofdDatalen,
                                          const char * const keyword,const char * const KeywordRule, double stampwidth,
                                          double stampheight,bool isContinueSign,
                                          /*out*/unsigned char ** outData,/*out*/int * outDatalen);

    int testPDFKeywordSign(const unsigned char * const stampData,int stampDatalen,
                                          const unsigned char * const certData,int certDatalen,
                                          const unsigned char * const privateKeyData,int privateKeyDatalen,
                                          const unsigned char * const pdfData,int pdfDatalen,
                                          const char * const keyword,const char * const KeywordRule, double stampwidth,
                                          double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen);


    bool testVerifySeal(const unsigned char * const imageData,int imageDatalen);
    //--------------------------------------


    int addWaterMark_Text(int docType,const unsigned char * const docData,int docDatalen,float horizontalSpacing,float verticalSpacing,
                          char* firstLineText,char* firstLineText_FontName,float firstLineText_fontSize,float firstLineText_color_R,
                          float firstLineText_color_G,float firstLineText_color_B,float firstLineText_alpha,
                          float lineSpacing0_1,
                          char * secondLineText,char * secondLineText_FontName,float secondLineText_fontSize,float secondLineText_color_R,
                          float secondLineText_color_G,float secondLineText_color_B,float secondLineText_alpha,
                          float lineSpacing1_2,
                          char * thirdLineText,char * thirdLineText_FontName,float thirdLineText_fontSize,float thirdLineText_color_R,
                          float thirdLineText_color_G,float thirdLineText_color_B,float thirdLineText_alpha,
                          float rotate,/*out*/unsigned char ** outData,/*out*/int * outDatalen){return 0;}





private:
    QLibrary m_DLLlib;

    TYPE_FreeHandle m_FreeHandle;
    TYPE_setWorkPath  m_setWorkPath;
    TYPE_saveFontFileNameCache m_saveFontFileNameCache;
    TYPE_getAllSystemFontFileName m_getAllSystemFontFileName;
    TYPE_getImageWidthHeight m_getImageWidthHeight;
    TYPE_splitImage m_splitImage;

    TYPE_ofd_open m_ofd_open;
    TYPE_ofd_close m_ofd_close;
    TYPE_ofd_getPageCount m_ofd_getPageCount;
    TYPE_ofd_pageToImage m_ofd_pageToImage;
    TYPE_ofd_toImage m_ofd_toImage;
    TYPE_ofdToPdf m_ofdToPdf;
    TYPE_ofd_getOtherInfo m_ofd_getOtherInfo;
    TYPE_ofd_findWord m_ofd_findWord;

    TYPE_pdf_open m_pdf_open;
    TYPE_pdf_close m_pdf_close;
    TYPE_pdf_getPageCount m_pdf_getPageCount;
    TYPE_pdf_pageToImage m_pdf_pageToImage;
    TYPE_pdf_toImage m_pdf_toImage;
    TYPE_pdfToOfd m_pdfToOfd;
    TYPE_pdf_getOtherInfo m_pdf_getOtherInfo;
    TYPE_pdf_findWord m_pdf_findWord;

    TYPE_getSealImageData m_getSealImageData;

    TYPE_testCreateSeal m_testCreateSeal;
    TYPE_testOFDVerify m_testOFDVerify;
    TYPE_testPDFVerify m_testPDFVerify;
    TYPE_testOFDPositionSign m_testOFDPositionSign;
    TYPE_testPDFPositionSign m_testPDFPositionSign;
    TYPE_testOFDRidingSign m_testOFDRidingSign;
    TYPE_testPDFRidingSign m_testPDFRidingSign;
    TYPE_testOFDKeywordSign m_testOFDKeywordSign;
    TYPE_testPDFKeywordSign m_testPDFKeywordSign;
    TYPE_testVerifySeal m_testVerifySeal;


};

#endif // OFDPDFSIGNERPROXY_H
