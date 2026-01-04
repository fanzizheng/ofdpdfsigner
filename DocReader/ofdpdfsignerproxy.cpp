#include "ofdpdfsignerproxy.h"
#include <QDebug>
//----------------------------------------------------------------------------------------------------------
OFDPDFSignerProxy::OFDPDFSignerProxy() : m_FreeHandle(NULL),m_setWorkPath(NULL),m_saveFontFileNameCache(NULL),
    m_getAllSystemFontFileName(NULL),m_getImageWidthHeight(NULL),m_splitImage(NULL),
    m_ofd_open(NULL),m_ofd_close(NULL),m_ofd_getPageCount(NULL),m_ofd_pageToImage(NULL),
    m_ofd_toImage(NULL),m_ofdToPdf(NULL),m_ofd_getOtherInfo(NULL),m_ofd_findWord(NULL),
    m_pdf_open(NULL),m_pdf_close(NULL),m_pdf_getPageCount(NULL),m_pdf_pageToImage(NULL),m_pdf_toImage(NULL),
    m_pdfToOfd(NULL),m_pdf_getOtherInfo(NULL),m_pdf_findWord(NULL),m_getSealImageData(NULL),m_testCreateSeal(NULL),
    m_testOFDVerify(NULL),m_testPDFVerify(NULL),m_testOFDPositionSign(NULL),m_testPDFPositionSign(NULL),
    m_testOFDRidingSign(NULL),m_testPDFRidingSign(NULL),m_testOFDKeywordSign(NULL),
    m_testPDFKeywordSign(NULL),m_testVerifySeal(NULL)
{

}
//----------------------------------------------------------------------------------------------------------
OFDPDFSignerProxy::~OFDPDFSignerProxy()
{
    m_FreeHandle = NULL;
    m_setWorkPath = NULL;
    m_saveFontFileNameCache = NULL;
    m_getAllSystemFontFileName = NULL;
    m_getImageWidthHeight = NULL;
    m_splitImage = NULL;

    m_ofd_open = NULL;
    m_ofd_close = NULL;
    m_ofd_getPageCount = NULL;
    m_ofd_pageToImage = NULL;
    m_ofd_toImage = NULL;
    m_ofdToPdf = NULL;
    m_ofd_getOtherInfo = NULL;
    m_ofd_findWord = NULL;

    m_pdf_open = NULL;
    m_pdf_close = NULL;
    m_pdf_getPageCount = NULL;
    m_pdf_pageToImage = NULL;
    m_pdf_toImage = NULL;
    m_pdfToOfd = NULL;
    m_pdf_getOtherInfo = NULL;
    m_pdf_findWord = NULL;

    m_getSealImageData = NULL;

    m_testCreateSeal = NULL;
    m_testOFDVerify = NULL;
    m_testPDFVerify = NULL;
    m_testOFDPositionSign = NULL;
    m_testPDFPositionSign = NULL;
    m_testOFDRidingSign = NULL;
    m_testPDFRidingSign = NULL;
    m_testOFDKeywordSign = NULL;
    m_testPDFKeywordSign = NULL;
    m_testVerifySeal = NULL;

    m_DLLlib.unload();
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::init(const char * const dllname)
{
    bool isTF = false;

    m_DLLlib.setFileName(dllname);
    if ( !m_DLLlib.load() ) {
        qDebug() << "not load dll : " << dllname << " error:" <<m_DLLlib.errorString() << Qt::endl;
        return isTF;
    }

    if ( m_FreeHandle == NULL ) {
        m_FreeHandle = (TYPE_FreeHandle)m_DLLlib.resolve("FZZFreeHandle");
    }
    if ( m_FreeHandle == NULL ) {
        return isTF;
    }

    if ( m_setWorkPath == NULL ) {
        m_setWorkPath = (TYPE_setWorkPath)m_DLLlib.resolve("setWorkPath");
    }
    if ( m_setWorkPath == NULL ) {
        return isTF;
    }

    if ( m_saveFontFileNameCache == NULL ) {
        m_saveFontFileNameCache = (TYPE_saveFontFileNameCache)m_DLLlib.resolve("saveFontFileNameCache");
    }
    if ( m_saveFontFileNameCache == NULL ) {
        return isTF;
    }

    if ( m_getAllSystemFontFileName == NULL ) {
        m_getAllSystemFontFileName = (TYPE_getAllSystemFontFileName)m_DLLlib.resolve("getAllSystemFontFileName");
    }
    if ( m_getAllSystemFontFileName == NULL ) {
        return isTF;
    }


    if ( m_getImageWidthHeight == NULL ) {
        m_getImageWidthHeight = (TYPE_getImageWidthHeight)m_DLLlib.resolve("getImageWidthHeight");
    }
    if ( m_getImageWidthHeight == NULL ) {
        return isTF;
    }

    if ( m_splitImage == NULL ) {
        m_splitImage = (TYPE_splitImage)m_DLLlib.resolve("splitImage");
    }
    if ( m_splitImage == NULL ) {
        return isTF;
    }

    if ( m_ofd_open == NULL ) {
        m_ofd_open = (TYPE_ofd_open)m_DLLlib.resolve("ofd_open");
    }
    if ( m_ofd_open == NULL ) {
        return isTF;
    }

    if ( m_ofd_close == NULL ) {
        m_ofd_close = (TYPE_ofd_close)m_DLLlib.resolve("ofd_close");
    }
    if ( m_ofd_close == NULL ) {
        return isTF;
    }

    if ( m_ofd_getPageCount == NULL ) {
        m_ofd_getPageCount = (TYPE_ofd_getPageCount)m_DLLlib.resolve("ofd_getPageCount");
    }
    if ( m_ofd_getPageCount == NULL ) {
        return isTF;
    }

    if ( m_ofd_pageToImage == NULL ) {
        m_ofd_pageToImage = (TYPE_ofd_pageToImage)m_DLLlib.resolve("ofd_pageToImage");
    }
    if ( m_ofd_pageToImage == NULL ) {
        return isTF;
    }


    if ( m_ofd_toImage == NULL ) {
        m_ofd_toImage = (TYPE_ofd_toImage)m_DLLlib.resolve("ofd_toImage");
    }
    if ( m_ofd_toImage == NULL ) {
        return isTF;
    }

    if ( m_ofdToPdf == NULL ) {
        m_ofdToPdf = (TYPE_ofdToPdf)m_DLLlib.resolve("ofdToPdf");
    }
    if ( m_ofdToPdf == NULL ) {
        return isTF;
    }


    if ( m_ofd_getOtherInfo == NULL ) {
        m_ofd_getOtherInfo = (TYPE_ofd_getOtherInfo)m_DLLlib.resolve("ofd_getOtherInfo");
    }
    if ( m_ofd_getOtherInfo == NULL ) {
        return isTF;
    }

    if ( m_ofd_findWord == NULL ) {
        m_ofd_findWord = (TYPE_ofd_findWord)m_DLLlib.resolve("ofd_findWord");
    }
    if ( m_ofd_findWord == NULL ) {
        return isTF;
    }
//---------------------------------------
    if ( m_pdf_open == NULL ) {
        m_pdf_open = (TYPE_pdf_open)m_DLLlib.resolve("pdf_open");
    }
    if ( m_pdf_open == NULL ) {
        return isTF;
    }

    if ( m_pdf_close == NULL ) {
        m_pdf_close = (TYPE_pdf_close)m_DLLlib.resolve("pdf_close");
    }
    if ( m_pdf_close == NULL ) {
        return isTF;
    }

    if ( m_pdf_getPageCount == NULL ) {
        m_pdf_getPageCount = (TYPE_pdf_getPageCount)m_DLLlib.resolve("pdf_getPageCount");
    }
    if ( m_pdf_getPageCount == NULL ) {
        return isTF;
    }

    if ( m_pdf_pageToImage == NULL ) {
        m_pdf_pageToImage = (TYPE_pdf_pageToImage)m_DLLlib.resolve("pdf_pageToImage");
    }
    if ( m_pdf_pageToImage == NULL ) {
        return isTF;
    }

    if ( m_pdf_toImage == NULL ) {
        m_pdf_toImage = (TYPE_pdf_toImage)m_DLLlib.resolve("pdf_toImage");
    }
    if ( m_pdf_toImage == NULL ) {
        return isTF;
    }

    if ( m_pdfToOfd == NULL ) {
        m_pdfToOfd = (TYPE_pdfToOfd)m_DLLlib.resolve("pdfToOfd");
    }
    if ( m_pdfToOfd == NULL ) {
        return isTF;
    }

    if ( m_pdf_getOtherInfo == NULL ) {
        m_pdf_getOtherInfo = (TYPE_pdf_getOtherInfo)m_DLLlib.resolve("pdf_getOtherInfo");
    }
    if ( m_pdf_getOtherInfo == NULL ) {
        return isTF;
    }

    if ( m_pdf_findWord == NULL ) {
        m_pdf_findWord = (TYPE_pdf_findWord)m_DLLlib.resolve("pdf_findWord");
    }
    if ( m_pdf_findWord == NULL ) {
        return isTF;
    }

    //--------------------------------------------
    if ( m_getSealImageData == NULL ) {
        m_getSealImageData = (TYPE_getSealImageData)m_DLLlib.resolve("getSealImageData");
    }
    if ( m_getSealImageData == NULL ) {
        return isTF;
    }

    if ( m_testCreateSeal == NULL ) {
        m_testCreateSeal = (TYPE_testCreateSeal)m_DLLlib.resolve("testCreateSeal");
    }
    if ( m_testCreateSeal == NULL ) {
        return isTF;
    }

    if ( m_testOFDVerify == NULL ) {
        m_testOFDVerify = (TYPE_testOFDVerify)m_DLLlib.resolve("testOFDVerify");
    }
    if ( m_testOFDVerify == NULL ) {
        return isTF;
    }

    if ( m_testPDFVerify == NULL ) {
        m_testPDFVerify = (TYPE_testPDFVerify)m_DLLlib.resolve("testPDFVerify");
    }
    if ( m_testPDFVerify == NULL ) {
        return isTF;
    }

    if ( m_testOFDPositionSign == NULL ) {
        m_testOFDPositionSign = (TYPE_testOFDPositionSign)m_DLLlib.resolve("testOFDPositionSign");
    }
    if ( m_testOFDPositionSign == NULL ) {
        return isTF;
    }

    if ( m_testPDFPositionSign == NULL ) {
        m_testPDFPositionSign = (TYPE_testPDFPositionSign)m_DLLlib.resolve("testPDFPositionSign");
    }
    if ( m_testPDFPositionSign == NULL ) {
        return isTF;
    }

    if ( m_testOFDRidingSign == NULL ) {
        m_testOFDRidingSign = (TYPE_testOFDRidingSign)m_DLLlib.resolve("testOFDRidingSign");
    }
    if ( m_testOFDRidingSign == NULL ) {
        return isTF;
    }

    if ( m_testPDFRidingSign == NULL ) {
        m_testPDFRidingSign = (TYPE_testPDFRidingSign)m_DLLlib.resolve("testPDFRidingSign");
    }
    if ( m_testPDFRidingSign == NULL ) {
        return isTF;
    }

    if ( m_testOFDKeywordSign == NULL ) {
        m_testOFDKeywordSign = (TYPE_testOFDKeywordSign)m_DLLlib.resolve("testOFDKeywordSign");
    }
    if ( m_testOFDKeywordSign == NULL ) {
        return isTF;
    }

    if ( m_testPDFKeywordSign == NULL ) {
        m_testPDFKeywordSign = (TYPE_testPDFKeywordSign)m_DLLlib.resolve("testPDFKeywordSign");
    }
    if ( m_testPDFKeywordSign == NULL ) {
        return isTF;
    }

    if ( m_testVerifySeal == NULL ) {
        m_testVerifySeal = (TYPE_testVerifySeal)m_DLLlib.resolve("testVerifySeal");
    }
    if ( m_testVerifySeal == NULL ) {
        return isTF;
    }




    isTF = true;
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
void OFDPDFSignerProxy::FreeHandle(HANDLE handle)
{
    if ( m_FreeHandle != NULL ) {
        m_FreeHandle(handle);
    }
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::setWorkPath(const char* const workpath)
{
    bool isTF = false;
    if ( m_setWorkPath != NULL ) {
        isTF = m_setWorkPath(workpath);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::saveFontFileNameCache(const char* const fontFileName)
{
    bool isTF = false;
    if ( m_saveFontFileNameCache != NULL ) {
        isTF = m_saveFontFileNameCache(fontFileName);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::getAllSystemFontFileName(CallBack_SystemFontFileNameFunc systemFontFileNameFunc,const void * callBack_Param)
{
    bool isTF = false;
    if ( m_getAllSystemFontFileName != NULL ) {
        isTF = m_getAllSystemFontFileName(systemFontFileNameFunc,callBack_Param);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::getImageWidthHeight(const unsigned char * const imageData,size_t imageLenght,/*out*/size_t* imageWidth,/*out*/size_t* imageHeight)
{
    bool isTF = false;
    if ( m_getImageWidthHeight != NULL ) {
        isTF = m_getImageWidthHeight(imageData,imageLenght,imageWidth,imageHeight);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::splitImage(const unsigned char * const imageData,int imageLenght,const char * imageType,bool isHorizontal,size_t count,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen,size_t* imageWidth,size_t* imageHeight)
{
    bool isTF = false;
    if ( m_splitImage != NULL ) {
        isTF = m_splitImage(imageData,imageLenght,imageType,isHorizontal,count,outData,intoutDatalen,outDatalen,imageWidth,imageHeight);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
HANDLE OFDPDFSignerProxy::ofd_open(const unsigned char * const fileData,int fileDatalen)
{
    HANDLE handle = NULL;
    if ( m_ofd_open != NULL ) {
        handle = m_ofd_open(fileData,fileDatalen);
    }
    return handle;
}
//----------------------------------------------------------------------------------------------------------
void OFDPDFSignerProxy::ofd_close(HANDLE fileHandle)
{
    if ( m_ofd_close != NULL ) {
        m_ofd_close(fileHandle);
    }
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::ofd_getPageCount(HANDLE fileHandle)
{
    int ret = 0;
    if ( m_ofd_getPageCount != NULL ) {
        ret = m_ofd_getPageCount(fileHandle);
    }
    return ret;
}
//---------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::ofd_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    if ( m_ofd_pageToImage != NULL ) {
        isTF = m_ofd_pageToImage(handle,imageType, pageIndex, scale,outData,outDatalen);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::ofd_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen)
{
    bool isTF = false;
    if ( m_ofd_toImage != NULL ) {
        isTF = m_ofd_toImage(handle,imageType, scale, outData,intoutDatalen,outDatalen);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::ofdToPdf(HANDLE handle,bool isNoStamp,bool isEncrypt,const char * password,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    if ( m_ofdToPdf != NULL ) {
        isTF = m_ofdToPdf(handle,isNoStamp,isEncrypt,password,outData,outDatalen);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
void OFDPDFSignerProxy::ofd_getOtherInfo(HANDLE obj,AttachmentFileFunc attachmentFileFunc,AnnotsFunc annotsFunc,StampsFunc stampsFunc)
{
    if ( m_ofd_getOtherInfo != NULL ) {
        m_ofd_getOtherInfo(obj, attachmentFileFunc, annotsFunc, stampsFunc);
    }
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::ofd_findWord(HANDLE handle,int pageIndex,const char* const word,FindWordFunc findWordFunc)
{
    bool isTF = false;
    if ( m_ofd_findWord != NULL ) {
        isTF = m_ofd_findWord(handle,pageIndex,word,findWordFunc);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
void OFDPDFSignerProxy::pdf_close(HANDLE fileHandle)
{
    if ( m_pdf_close != NULL ) {
        m_pdf_close(fileHandle);
    }
}
//----------------------------------------------------------------------------------------------------------
HANDLE OFDPDFSignerProxy::pdf_open(const unsigned char * const fileData,int fileDatalen)
{
    HANDLE handle = NULL;
    if ( m_pdf_open != NULL ) {
        handle = m_pdf_open(fileData,fileDatalen);
    }
    return handle;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::pdf_getPageCount(HANDLE fileHandle)
{
    int ret = 0;
    if ( m_pdf_getPageCount != NULL ) {
        ret = m_pdf_getPageCount(fileHandle);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::pdf_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    if ( m_pdf_pageToImage != NULL ) {
        isTF = m_pdf_pageToImage(handle,imageType, pageIndex, scale,outData,outDatalen);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::pdf_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen)
{
    bool isTF = false;
    if ( m_pdf_toImage != NULL ) {
        isTF = m_pdf_toImage(handle,imageType, scale,outData,intoutDatalen,outDatalen);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::pdfToOfd(HANDLE handle,bool isNoStamp,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    if ( m_pdfToOfd != NULL ) {
        isTF = m_pdfToOfd(handle,isNoStamp,outData,outDatalen);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
void OFDPDFSignerProxy::pdf_getOtherInfo(HANDLE obj,AttachmentFileFunc attachmentFileFunc,AnnotsFunc annotsFunc,StampsFunc stampsFunc)
{
    if ( m_pdf_getOtherInfo != NULL ) {
        m_pdf_getOtherInfo(obj, attachmentFileFunc, annotsFunc, stampsFunc);
    }
}
//----------------------------------------------------------------------------------------------------------
bool OFDPDFSignerProxy::pdf_findWord(HANDLE handle,int pageIndex,const char* const word,FindWordFunc findWordFunc)
{
    bool isTF = false;
    if ( m_pdf_findWord != NULL ) {
        isTF = m_pdf_findWord(handle,pageIndex,word,findWordFunc);
    }
    return isTF;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::getSealImageData(const unsigned char * const sealData,int sealDatalen,/*out*/unsigned char ** outImageData,/*out*/size_t * outImageDatalen)
{
    int ret = false;
    if ( m_getSealImageData != NULL ) {
        ret = m_getSealImageData(sealData, sealDatalen,outImageData,outImageDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::testCreateSeal(const unsigned char * const imageData,int imageDatalen,
                   /*out*/unsigned char ** outSealData,/*out*/int * outSealDatalen,
                   /*out*/unsigned char ** outSealUserCert,/*out*/int * outSealUserCertlen,
                   /*out*/unsigned char ** outSealUserCertPriKey,/*out*/int * outSealUserCertPriKeylen
                   )
{
    int ret = false;
    if ( m_testCreateSeal != NULL ) {
        ret = m_testCreateSeal(imageData,imageDatalen,
                               outSealData,outSealDatalen,
                               outSealUserCert,outSealUserCertlen,
                               outSealUserCertPriKey,outSealUserCertPriKeylen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int  OFDPDFSignerProxy::testOFDVerify(const unsigned char * const ofdData,int ofdDatalen,
                  const char* const sid,
                  /*out*/char ** outSignTime,/*out*/int * outSignTimelen,
                  /*out*/char ** outSignDn,/*out*/int * outSignDnlen)
{
    int ret = false;
    if ( m_testOFDVerify != NULL ) {
        ret = m_testOFDVerify(ofdData,ofdDatalen,
                              sid,
                              outSignTime,outSignTimelen,
                              outSignDn,outSignDnlen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------

int OFDPDFSignerProxy::testPDFVerify(const unsigned char * const pdfData,int pdfDatalen,
                  const char* const sid,
                  /*out*/char ** outSignTime,/*out*/int * outSignTimelen,
                  /*out*/char ** outSignDn,/*out*/int * outSignDnlen)
{
    int ret = false;
    if ( m_testPDFVerify != NULL ) {
        ret = m_testPDFVerify(pdfData,pdfDatalen,
                              sid,
                              outSignTime,outSignTimelen,
                              outSignDn,outSignDnlen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int  OFDPDFSignerProxy::testOFDPositionSign(const unsigned char * const stampData,int stampDatalen,
                        const unsigned char * const certData,int certDatalen,
                        const unsigned char * const privateKeyData,int privateKeyDatalen,
                        const unsigned char * const ofdData,int ofdDatalen,
                        int pageIndex,double x,double y, double stampwidth,
                        double stampheight,bool isContinueSign,
                        /*out*/unsigned char ** outData,/*out*/int * outDatalen)
{
    int ret = false;
    if ( m_testOFDPositionSign != NULL ) {
        ret = m_testOFDPositionSign(stampData,stampDatalen,
                                    certData, certDatalen,
                                     privateKeyData, privateKeyDatalen,
                                    ofdData, ofdDatalen,
                                     pageIndex, x, y,  stampwidth,
                                     stampheight, isContinueSign,
                                     outData,outDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int  OFDPDFSignerProxy::testPDFPositionSign(const unsigned char * const stampData,int stampDatalen,
                        const unsigned char * const certData,int certDatalen,
                        const unsigned char * const privateKeyData,int privateKeyDatalen,
                        const unsigned char * const pdfData,int pdfDatalen,
                        int pageIndex,double x,double y, double stampwidth,
                        double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen)
{
    int ret = false;
    if ( m_testPDFPositionSign != NULL ) {
        ret = m_testPDFPositionSign(stampData,stampDatalen,
                                    certData, certDatalen,
                                    privateKeyData, privateKeyDatalen,
                                    pdfData, pdfDatalen,
                                    pageIndex, x, y,  stampwidth,
                                    stampheight,
                                    outData,outDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::testOFDRidingSign(const unsigned char * const stampData,int stampDatalen,
                      const unsigned char * const certData,int certDatalen,
                      const unsigned char * const privateKeyData,int privateKeyDatalen,
                      const unsigned char * const ofdData,int ofdDatalen,
                      int RidingType, double stampwidth,
                      double stampheight,bool isContinueSign,
                      /*out*/unsigned char ** outData,/*out*/int * outDatalen)
{
    int ret = false;
    if ( m_testOFDRidingSign != NULL ) {
        ret = m_testOFDRidingSign(stampData,stampDatalen,
                                  certData, certDatalen,
                                   privateKeyData, privateKeyDatalen,
                                   ofdData, ofdDatalen,
                                   RidingType,  stampwidth,
                                   stampheight, isContinueSign,
                                  outData,outDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::testPDFRidingSign(const unsigned char * const stampData,int stampDatalen,
                      const unsigned char * const certData,int certDatalen,
                      const unsigned char * const privateKeyData,int privateKeyDatalen,
                      const unsigned char * const pdfData,int pdfDatalen,
                      int RidingType, double stampwidth,
                      double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen)
{
    int ret = false;
    if ( m_testPDFRidingSign != NULL ) {
        ret = m_testPDFRidingSign(stampData, stampDatalen,
                                  certData, certDatalen,
                                   privateKeyData, privateKeyDatalen,
                                  pdfData, pdfDatalen,
                                   RidingType,  stampwidth,
                                   stampheight,outData, outDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::testOFDKeywordSign(const unsigned char * const stampData,int stampDatalen,
                       const unsigned char * const certData,int certDatalen,
                       const unsigned char * const privateKeyData,int privateKeyDatalen,
                       const unsigned char * const ofdData,int ofdDatalen,
                       const char * const keyword,const char * const KeywordRule, double stampwidth,
                       double stampheight,bool isContinueSign,
                       /*out*/unsigned char ** outData,/*out*/int * outDatalen)
{
    int ret = false;
    if ( m_testOFDKeywordSign != NULL ) {
        ret = m_testOFDKeywordSign(stampData, stampDatalen,
                                    certData, certDatalen,
                                    privateKeyData, privateKeyDatalen,
                                    ofdData, ofdDatalen,
                                    keyword, KeywordRule,  stampwidth,
                                    stampheight, isContinueSign,
                                    outData, outDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int OFDPDFSignerProxy::testPDFKeywordSign(const unsigned char * const stampData,int stampDatalen,
                       const unsigned char * const certData,int certDatalen,
                       const unsigned char * const privateKeyData,int privateKeyDatalen,
                       const unsigned char * const pdfData,int pdfDatalen,
                       const char * const keyword,const char * const KeywordRule, double stampwidth,
                       double stampheight,/*out*/unsigned char ** outData,/*out*/int * outDatalen)
{
    int ret = false;
    if ( m_testPDFKeywordSign != NULL ) {
        ret = m_testPDFKeywordSign(stampData, stampDatalen,
                                   certData, certDatalen,
                                    privateKeyData, privateKeyDatalen,
                                   pdfData, pdfDatalen,
                                   keyword,KeywordRule,  stampwidth,
                                    stampheight,outData,outDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------

bool OFDPDFSignerProxy::testVerifySeal(const unsigned char * const imageData,int imageDatalen)
{
    int ret = false;
    if ( m_testVerifySeal != NULL ) {
        ret = m_testVerifySeal(imageData,imageDatalen);
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
