//
//  Created by zizheng fan on 2024/11/10.1
//
#if defined(_MSC_VER)
#include "pch.h"
#endif
#include "basic/FZZConst.h"
#include "interface/FZZCInterface.h"
#include "converter/image/FZZPDFToImage.h"

#include "ofd/sign/FZZNumberFormatAtomicSignID.h"
#include "ofd/sign/FZZStandFormatAtomicSignID.h"
#include "ofd/sign/signcontainer/FZZSESV4Container.h"
#include "ofd/sign/stamppos/FZZNormalStampPos.h"

#include "ofd/sign/signcontainer/FZZGBT35275DSContainer.h"
#include "ofd/sign/signcontainer/FZZGBT35275PKCS9DSContainer.h"
#include "ofd/sign/stamppos/FZZRidingStampPos.h"
#include "ofd/sign/stamppos/FZZCuttingRideStampPos.h"

#include "pdfsign/FZZPDFSigner.h"
#include "converter/utils/FZZCommonUtil.h"

#include "interface/FZZKeyWordRule.h"

#include "gm/crypto/FZZGMCrypto.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZKeyPair.h"
#include "gm/crypto/FZZCert.h"
#include "gm/crypto/FZZCertGenerator.h"
#include "gm/ses/v4/FZZSESeal_V4.h"
#include "gm/ses/v4/FZZSES_Header.h"
#include "gm/ses/v4/FZZSES_ESPropertyInfo_V4.h"
#include <gmssl/x509.h>
#include "gm/ses/v4/FZZSES_CertList.h"
#include "gm/ses/v4/FZZSES_ESPictrueInfo_V4.h"
#include <gmssl/x509_alg.h>
#include "pdfsign/FZZPDFCreator.h"
#include <gmssl/rand.h>
#include <gmssl/x509_ext.h>
#include "interface/FZZErrorCode.h"
#include "ofd/FZZOFD.h"
#include "ofd/FZZOFDSigner.h"
#include "ofd/FZZOFDSignCleaner.h"
#include "ofd/FZZOFDValidator.h"

#include "ofd/keyword/FZZOFDFindKeyWord.h"
#include "converter/image/FZZOFDToImage.h"
#include "converter/topdf/FZZOFDToPDF.h"
#include "converter/toofd/FZZPDF2OFD.h"
#include "converter/utils/FZZWaterMark.h"
#include "converter/tosvg/FZZPDF2SVG.h"
#include "converter/tosvg/FZZOFDToSvg.h"
#include "ofd/FZZOFDProtectSign.h"
#include "ofd/FZZOFDEncrypt.h"

#include "pdfsign/FZZPDF.h"

#include "rapidjson/document.h"

#if defined(_MSC_VER)

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#endif

//-----------------------------------------------------------------------------------------------------------------
/***********************************************utils function**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
void ClearKeyWordList(vector<FZZKeyWordInfo*> * list)
{
    vector<FZZKeyWordInfo*>::const_iterator it;
    for( it = list->begin(); it != list->end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    list->clear();
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API void DEVAPI FZZFreeHandle(HANDLE handle)
{
    if ( handle != NULL ) {
        free(handle);
        handle = NULL;
    }
}

//-----------------------------------------------------------------------------------------------------------------
/*********************************************** function**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Util*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI setWorkPath(const char* const filePath)
{
    const char* pWorkpath = filePath;
#ifdef _MSC_VER
    string utf8str = filePath;
    string gbstr = FZZConst::Utf8toGB2312(utf8str);
    pWorkpath = gbstr.c_str();

#endif

    FZZConst::setCurrPath(pWorkpath);
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI setTempPath(const char* const filePath)
{
    const char* pWorkpath = filePath;
#ifdef _MSC_VER
    string utf8str = filePath;
    string gbstr = FZZConst::Utf8toGB2312(utf8str);
    pWorkpath = gbstr.c_str();

#endif

    FZZConst::setTempPath(pWorkpath);
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI getImageWidthHeight(const unsigned char * const imageData,size_t imageLenght,/*out*/size_t* imageWidth,/*out*/size_t* imageHeight)
{
    *imageWidth = 0;
    *imageHeight = 0;
    FZZImageUtil imageUtil;
    if ( !imageUtil.LoadImage(imageData, imageLenght) ) {
        return false;
    }
    
    *imageWidth = imageUtil.getWidth();
    *imageHeight = imageUtil.getHeight();
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI splitImage(const unsigned char * const imageData,int imageLenght,const char * imageType,bool isHorizontal,size_t count,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen,size_t* imageWidth,size_t* imageHeight)
{
    bool isTF = true;
    vector<FZZBytes *> outImages;
    FZZImageUtil imageUtil;
    int pos = 0;
    //int x = 0;
    int i = 0;
    vector<FZZBytes*>::const_iterator iter;
    FZZBytes * tempImage;
    int totallen = 0;
    string outlen = "";
    size_t itemlen = 0;
    
    FZZBytes image(imageData,imageLenght);
    
    imageUtil.SplitImage(image,imageType,(int)count,isHorizontal,outImages,imageWidth,imageHeight);
    
    i = 0;
    for (iter = outImages.begin(); iter != outImages.end(); iter++) {
        tempImage = *iter;
        itemlen = tempImage->getLen();
        totallen += itemlen;
        if ( i == outImages.size() -1 ) {
            outlen += FZZConst::fmt(itemlen);
        } else {
            outlen += FZZConst::fmt(itemlen)+",";
        }
        i++;
    }
 
    
    *intoutDatalen = totallen;
    *outData = (unsigned char *)malloc(totallen);
    *outDatalen = (char *)malloc(outlen.length()+1);
    if ( *outData == NULL || *outDatalen == NULL ) {
        if ( *outData != NULL ) {
            FZZFreeHandle(*outData);
            *outData = NULL;
        }
        if ( *outDatalen != NULL ) {
            FZZFreeHandle(*outDatalen);
            *outDatalen = NULL;
        }
        isTF = false;
        goto err;
    }
    
    pos = 0;
    for (iter = outImages.begin(); iter != outImages.end(); iter++) {
        tempImage = *iter;
        if ( tempImage != NULL ) {
            itemlen = tempImage->getLen();
            memcpy((*outData)+pos,tempImage->getData(),itemlen);
            pos += itemlen;
        }
    }
   
    memset(*outDatalen,0x00,outlen.length()+1);
    memcpy(*outDatalen,outlen.c_str(),outlen.length());
    
err:
    for (iter = outImages.begin(); iter != outImages.end(); iter++) {
        if ( *iter != NULL ) {
            delete *iter;
        }
    }
    outImages.clear();
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************字体*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI saveFontFileNameCache(const char* const fontFileName)
{
    if ( fontFileName == NULL || strlen(fontFileName) <= 0 ) {
        return false;
    }
    const char* pfontFileName = fontFileName;
#ifdef _MSC_VER
    string utf8str = fontFileName;
    string gbstr = FZZConst::Utf8toGB2312(utf8str);
    pfontFileName = gbstr.c_str();

#endif
    //DLOG("AddFontCache => %s", pfontFileName);

    string fontName = FZZConst::g_FZFontConfig.getFontName_FullPath(pfontFileName);
    FZZConst::g_FZSystemFontList.addFontFile(fontName, pfontFileName);

    return true;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI getAllSystemFontFileName(CallBack_SystemFontFileNameFunc systemFontFileNameFunc,const void * callBack_Param)
{
    if ( systemFontFileNameFunc == NULL ) {
        return false;
    }
    vector<string> fullpaths;

    FZZConst::g_FZFontConfig.getSysFontFullPath(fullpaths);

   // DLOG("GetAllSystemFontFileName count %d", fullpaths.size());
    vector<string>::const_iterator it;
    for( it = fullpaths.begin(); it != fullpaths.end(); it++ ) {
        const char* ptempstr = (*it).c_str();
        //DLOG("GetAllSystemFontFileName =》 %s", ptempstr);
//#ifdef _MSC_VER
//        string gbstr = ptempstr;
//        string utf8str = FZZConst::GB2312toUtf8(gbstr);
//        ptempstr = utf8str.c_str();
//
//#endif
        systemFontFileNameFunc(callBack_Param,ptempstr);
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************crypto*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI generateRootCert(int keyType,unsigned char * keyData,int keyDatalen,unsigned char * dnData,int dnlen,int days,unsigned char * rootKeyData,int rootKeyDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    if ( keyType != FZZCRYPTOTYPEE_SM2  ) {
        return isTF;
    }
    
    if ( keyData == NULL || keyDatalen <= 0 || rootKeyData == NULL || rootKeyDatalen <= 0 || dnData == NULL || dnlen <= 0) {
        return isTF;
    }
    
    FZZKey pubKey(FZZKey::KEYTYPE_SM2_PUB_KEY,"",keyData,keyDatalen);
    FZZKey rootPriKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",rootKeyData,rootKeyDatalen);
    
    FZZBytes b_DN;
    b_DN.setMaxLen(dnlen+3);
    b_DN.setData_NotMalloc(dnData, dnlen);
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_SN = gmCrypto.generateRandom(16);
    
    FZZCertGenerator certGenerator;
    //FZZBytes serial;
    //serial.setData((unsigned char *)FZZConst::HexEncode(b_SN.getData(), b_SN.getLen()).c_str(),16);
    certGenerator.setSerialNumber(b_SN);
    certGenerator.setIssuer((char *)b_DN.getData());
    certGenerator.setSubject((char *)b_DN.getData());
    time_t NotBefore;
    time(&NotBefore);
    certGenerator.setNotBefore(NotBefore);
    certGenerator.addDays(days);
    certGenerator.setCertPublicKey(pubKey);
    certGenerator.setSignPrivateKey(rootPriKey);
    
    FZZBytes certData = certGenerator.genCert();
    if ( certData.getLen() > 0 ) {
        *outData = (unsigned char *)malloc(certData.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = certData.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,certData.getData(),*outDatalen);
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//isSign : 1: signcert; 0:enccert;
DLL_API bool DEVAPI generateCert(int keyType,int isSign,unsigned char * keyData,int keyDatalen,unsigned char * dnData,int dnlen,unsigned char * dnRootData,int dnRootlen,int days,unsigned char * rootKeyData,int rootKeyDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    if ( keyType != FZZCRYPTOTYPEE_SM2  ) {
        return isTF;
    }
    
    if ( keyData == NULL || keyDatalen <= 0 || rootKeyData == NULL || rootKeyDatalen <= 0 || dnData == NULL || dnlen <= 0 || dnRootData == NULL || dnRootlen <= 0) {
        return isTF;
    }
    
    FZZKey pubKey(FZZKey::KEYTYPE_SM2_PUB_KEY,"",keyData,keyDatalen);
    FZZKey rootPriKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",rootKeyData,rootKeyDatalen);
    
    FZZBytes b_DN;
    b_DN.setMaxLen(dnlen+3);
    b_DN.setData_NotMalloc(dnData, dnlen);
  
    
    FZZBytes b_rootDN;
    b_rootDN.setMaxLen(dnRootlen+3);
    b_rootDN.setData_NotMalloc(dnRootData, dnRootlen);

    
    FZZGMCrypto gmCrypto;
    FZZBytes b_SN = gmCrypto.generateRandom(16);
    
    
    FZZCertGenerator certGenerator;
    //FZZKeyPair stampUserkeyPair = gmCrypto.generateKeyPair();
    //serial.setData((unsigned char *)FZZConst::HexEncode(b_SN.getData(), b_SN.getLen()).c_str(),16);
    certGenerator.setSerialNumber(b_SN);
    certGenerator.setIssuer((char *)b_rootDN.getData());
    certGenerator.setSubject((char *)b_DN.getData());
    time_t NotBefore;
    time(&NotBefore);
    certGenerator.setNotBefore(NotBefore);
    certGenerator.addDays(days);
    certGenerator.setCertPublicKey(pubKey);
    certGenerator.setSignPrivateKey(rootPriKey);
    
    if ( isSign ) {
        certGenerator.setKeyUsage(X509_KU_DIGITAL_SIGNATURE|X509_KU_NON_REPUDIATION|X509_KU_KEY_CERT_SIGN|X509_KU_CRL_SIGN|X509_KU_KEY_AGREEMENT);
    } else {
        certGenerator.setKeyUsage(X509_KU_KEY_ENCIPHERMENT|X509_KU_DATA_ENCIPHERMENT|X509_KU_KEY_AGREEMENT|X509_KU_ENCIPHER_ONLY);
    }
    
    
    FZZBytes certData = certGenerator.genCert();
    if ( certData.getLen() > 0 ) {
        *outData = (unsigned char *)malloc(certData.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = certData.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,certData.getData(),*outDatalen);
        isTF = true;
    }
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI generateRandom(int length,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
//    *outData = (unsigned char *)malloc(length);
//    if ( *outData == NULL ) {
//        return isTF;
//    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes random = gmCrypto.generateRandom(length);
    if ( random.getLen() == length ) {
        
        *outData = (unsigned char *)malloc(random.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = random.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,random.getData(),*outDatalen);
        isTF = true;
    }
    
    
//    isTF = rand_bytes(*outData,length) == 1 ? true : false ;
//
//    if ( isTF ) {
//        *outDatalen = length;
//    } else {
//        FZZFreeHandle(*outData);
//    }
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI generateDigest(unsigned char * sourceData,int sourceDataLength,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZGMCrypto gmCrypto;
    string digestalg = "SM3";
    FZZBytes digestAct;
    FZZBytes inDatas;
    inDatas.setData(sourceData,sourceDataLength);
    gmCrypto.Digest(digestalg.c_str(), inDatas, digestAct);
    
    if ( digestAct.getLen() > 8 ) {
        
        *outData = (unsigned char *)malloc(digestAct.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = digestAct.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,digestAct.getData(),*outDatalen);
        isTF = true;
    }

    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI generateSymKey(/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZGMCrypto gmCrypto;
    FZZKey key = gmCrypto.generateKey();
    if ( key.getKeyDataLen() == 16 ) {
        *outData = (unsigned char *)malloc(key.getKeyDataLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = key.getKeyDataLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,key.getKeyData(),*outDatalen);
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI generateAsymKey(/*out*/unsigned char ** outPublicKeyData,/*out*/size_t * outPublicKeyDatalen,/*out*/unsigned char ** outPrivateKeyData,/*out*/size_t * outPrivateKeyDatalen)
{
    bool isTF = false;
    *outPublicKeyDatalen = 0;
    *outPrivateKeyDatalen = 0;
    
    FZZGMCrypto gmCrypto;
    FZZKeyPair keyPair = gmCrypto.generateKeyPair();
    
    if ( keyPair.getPublicKey().getKeyDataLen() > 0 && keyPair.getPrivateKey().getKeyDataLen() > 0) {
        
        *outPublicKeyData = (unsigned char *)malloc(keyPair.getPublicKey().getKeyDataLen());
        if ( *outPublicKeyData == NULL ) {
            return isTF;
        }
        *outPublicKeyDatalen = keyPair.getPublicKey().getKeyDataLen();
        memset(*outPublicKeyData,0x00,*outPublicKeyDatalen);
        memcpy(*outPublicKeyData,keyPair.getPublicKey().getKeyData(),*outPublicKeyDatalen);
        
        *outPrivateKeyData = (unsigned char *)malloc(keyPair.getPrivateKey().getKeyDataLen());
        if ( *outPrivateKeyData == NULL ) {
            return isTF;
        }
        *outPrivateKeyDatalen = keyPair.getPrivateKey().getKeyDataLen();
        memset(*outPrivateKeyData,0x00,*outPrivateKeyDatalen);
        memcpy(*outPrivateKeyData,keyPair.getPrivateKey().getKeyData(),*outPrivateKeyDatalen);
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI encipher(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** encData,/*out*/size_t * encDatalen,/*out*/unsigned char ** sm4GCMData,/*out*/size_t * sm4GCMDatalen)
{
    bool isTF = false;
    *encDatalen = 0;
    *sm4GCMDatalen = 0;
    
    FZZKey key;
    switch( keyType ) {
        case FZZKEYTYPE_SM4:
            key.setKeyType(FZZKey::KEYTYPE_SM4);
            key.setKeyData(keyData, keyDatalen);
            break;
        case FZZKEYTYPE_SM2_PUB:
            key.setKeyType(FZZKey::KEYTYPE_SM2_PUB_KEY);
            key.setKeyData(keyData, keyDatalen);
            break;
        default:
            return isTF;
    }
    string strCryptoType = "";
    switch( algType ) {
        case FZZCRYPTOTYPEE_SM2:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM2;
            break;
        case FZZCRYPTOTYPEE_SM4_CBC:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM4_CBC;
            break;
        case FZZCRYPTOTYPEE_SM4_GCM:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM4_GCM;
            break;
        case FZZCRYPTOTYPEE_SM4_CTR:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM4_CTR;
            break;
        default:
            return isTF;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_SourceData;
    FZZBytes b_sm4GCMData;
    
    b_SourceData.setData(sourceData,sourceDatalen);
    FZZBytes b_encData = gmCrypto.Encrypt(key,strCryptoType,b_SourceData,b_sm4GCMData);
    if ( b_encData.getLen() > 0 ) {
        *encData = (unsigned char *)malloc(b_encData.getLen());
        if ( *encData == NULL ) {
            return isTF;
        }
        *encDatalen = b_encData.getLen();
        memset(*encData,0x00,*encDatalen);
        memcpy(*encData,b_encData.getData(),*encDatalen);
        
        if ( b_sm4GCMData.getLen() > 0 ) {
            *sm4GCMData = (unsigned char *)malloc(b_sm4GCMData.getLen());
            if ( *sm4GCMData == NULL ) {
                return isTF;
            }
            *sm4GCMDatalen = b_sm4GCMData.getLen();
            memset(*sm4GCMData,0x00,*sm4GCMDatalen);
            memcpy(*sm4GCMData,b_sm4GCMData.getData(),*sm4GCMDatalen);
        }
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI decipher(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * encData,int encDatalen,unsigned char * sm4GCMData,int sm4GCMDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;

    
    FZZKey key;
    switch( keyType ) {
        case FZZKEYTYPE_SM4:
            key.setKeyType(FZZKey::KEYTYPE_SM4);
            key.setKeyData(keyData, keyDatalen);
            break;
        case FZZKEYTYPE_SM2_PRI:
            key.setKeyType(FZZKey::KEYTYPE_SM2_PRI_KEY);
            key.setKeyData(keyData, keyDatalen);
            break;
        default:
            return isTF;
    }
    string strCryptoType = "";
    switch( algType ) {
        case FZZCRYPTOTYPEE_SM2:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM2;
            break;
        case FZZCRYPTOTYPEE_SM4_CBC:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM4_CBC;
            break;
        case FZZCRYPTOTYPEE_SM4_GCM:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM4_GCM;
            break;
        case FZZCRYPTOTYPEE_SM4_CTR:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM4_CTR;
            break;
        default:
            return isTF;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_encData;
    FZZBytes b_sm4GCMData;
    
    b_encData.setData(encData,encDatalen);
    b_sm4GCMData.setData(sm4GCMData, sm4GCMDatalen);
    FZZBytes b_sourceData = gmCrypto.Decrypt(key,strCryptoType,b_encData,b_sm4GCMData);
    if ( b_sourceData.getLen() > 0 ) {
        *outData = (unsigned char *)malloc(b_sourceData.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = b_sourceData.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,b_sourceData.getData(),*outDatalen);
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI sign(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZKey key;
    switch( keyType ) {
        case FZZKEYTYPE_SM2_PRI:
            key.setKeyType(FZZKey::KEYTYPE_SM2_PRI_KEY);
            key.setKeyData(keyData, keyDatalen);
            break;
        default:
            return isTF;
    }
    string strCryptoType = "";
    switch( algType ) {
        case FZZCRYPTOTYPEE_SM2:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM2;
            break;
        default:
            return isTF;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_SourceData;
    
    b_SourceData.setData(sourceData,sourceDatalen);
    FZZBytes b_signData = gmCrypto.sign(key, b_SourceData);
    if ( b_signData.getLen() > 0 ) {
        *outData = (unsigned char *)malloc(b_signData.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = b_signData.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,b_signData.getData(),*outDatalen);
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI verify(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * sourceData,int sourceDatalen,unsigned char * signData,int signDatalen)
{
    bool isTF = false;
    FZZKey key;
    switch( keyType ) {
        case FZZKEYTYPE_SM2_PUB:
            key.setKeyType(FZZKey::KEYTYPE_SM2_PUB_KEY);
            key.setKeyData(keyData, keyDatalen);
            break;
        default:
            return isTF;
    }
    string strCryptoType = "";
    switch( algType ) {
        case FZZCRYPTOTYPEE_SM2:
            strCryptoType = FZZGMCrypto::CRYPTOTYPE_SM2;
            break;
        default:
            return isTF;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_SourceData;
    FZZBytes b_SignData;
    
    b_SourceData.setData(sourceData,sourceDatalen);
    b_SignData.setData(signData, signDatalen);
    isTF = gmCrypto.verifySign(key, b_SourceData, b_SignData);
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI encryptSM4CBC(unsigned char * keyData,int keyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** encData,/*out*/size_t * encDatalen)
{
    bool isTF = false;
    *encDatalen = 0;
    
    if ( keyData == NULL || keyDatalen <= 0 || ivData == NULL || ivDatalen <= 0 || sourceData == NULL || sourceDatalen <= 0) {
        return isTF;
    }
    
    FZZKey key;
    key.setKeyType(FZZKey::KEYTYPE_SM4);
    key.setKeyData(keyData, keyDatalen);
            
    FZZBytes kivData;
    kivData.setData(ivData,ivDatalen);
    
    FZZBytes bxmldata;
    bxmldata.setData(sourceData,sourceDatalen);
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_encData = gmCrypto.Encrypt_SM4_CBC(key, &kivData, bxmldata);
    
    if ( b_encData.getLen() > 0 ) {
        *encData = (unsigned char *)malloc(b_encData.getLen());
        if ( *encData == NULL ) {
            return isTF;
        }
        *encDatalen = b_encData.getLen();
        memset(*encData,0x00,*encDatalen);
        memcpy(*encData,b_encData.getData(),*encDatalen);
        
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI decryptSM4CBC(unsigned char * keyData,int keyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;

    if ( keyData == NULL || keyDatalen <= 0 || ivData == NULL || ivDatalen <= 0 || encData == NULL || encDatalen <= 0) {
        return isTF;
    }
    
    FZZKey key;
    key.setKeyType(FZZKey::KEYTYPE_SM4);
    key.setKeyData(keyData, keyDatalen);
            
    FZZBytes kivData;
    kivData.setData(ivData,ivDatalen);
    
    FZZBytes EWKData;
    EWKData.setData(encData,encDatalen);
    
    FZZGMCrypto gmCrypto;
    FZZBytes b_sourceData = gmCrypto.Decrypt_SM4_CBC(key, &kivData, EWKData);
    
    if ( b_sourceData.getLen() > 0 ) {
        *outData = (unsigned char *)malloc(b_sourceData.getLen());
        if ( *outData == NULL ) {
            return isTF;
        }
        *outDatalen = b_sourceData.getLen();
        memset(*outData,0x00,*outDatalen);
        memcpy(*outData,b_sourceData.getData(),*outDatalen);
        isTF = true;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Seal*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI createSeal(const char * const code,int type,const char * const name,int width,int height,
                                const char * const createTime,const char * const startTime,const char * const endTime,const char * const format,
                                const unsigned char * const imageData,int imageDatalen,CallBack_Sign signFunc,CallBack_getUserCert getUserCertFunc,CallBack_getSealCert getSealCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outSealData,/*out*/size_t * outSealDatalen)
{
    int ret = -1;
    time_t createDate,startDate,endDate;

    if ( endTime != NULL && strlen(endTime) > 0 ) {
        endDate = FZZConst::StringToTime(endTime);
    } else {
        return ret;
    }

    if ( createTime != NULL && strlen(createTime) > 0 ) {
        createDate = FZZConst::StringToTime(createTime);
    } else {
        return ret;
    }

    if ( startTime != NULL && strlen(startTime) > 0 ) {
        startDate = FZZConst::StringToTime(startTime);
    } else {
        return ret;
    }


    FZZBytes picdata(imageData,imageDatalen);

    FZZCreateSESeal_V4 createSeal;
    FZZBytes sealData = createSeal.CreateSeal(getUserCertFunc,getSealCertFunc,signFunc,callBack_Param,
                                           type,name,createDate,startDate,endDate,
                                           format,picdata,width,height,code);

    if ( sealData.getLen() > 0 ) {
        *outSealData = (unsigned char *)malloc(sealData.getLen());
        if ( *outSealData == NULL ) {
            return -3;
        }
        *outSealDatalen = sealData.getLen();
        memset(*outSealData,0x00,*outSealDatalen);
        memcpy(*outSealData,sealData.getData(),*outSealDatalen);
        //DLOG("seal:%s",FZZConst::HexEncode(sealData.getData(), sealData.getLen()).c_str());
        ret = 0;
    }


    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI getSealImageData(const unsigned char * const sealData,int sealDatalen,
                              /*out*/unsigned char ** outImageData,/*out*/size_t * outImageDatalen
                              )
{
    FZZBytes sealdata(sealData,sealDatalen);
    FZZSESeal_V4 seal(sealdata);
    FZZSES_SealInfo_V4* sealinfo = seal.getSealInfo();
    if ( sealinfo == NULL ) {
        return -1;
    }
    FZZSES_ESPictrueInfo_V4* picinfo = sealinfo->getPicture();
    if ( picinfo == NULL ) {
        return -1;
    }
    FZZBytes bimg = picinfo->getData();
    
    if ( bimg.getLen() > 0 ) {
        *outImageData = (unsigned char *)malloc(bimg.getLen());
        if ( *outImageData == NULL ) {
            return -402;
        }
        //memset(*outImageData,0x00,bimg.length());
        memcpy(*outImageData,bimg.getData(),bimg.getLen());
        *outImageDatalen = bimg.getLen();
    } else {
        *outImageDatalen = 0;
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI getSealUserCertData(const unsigned char * const sealData,int sealDatalen,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen
                              )
{
    FZZBytes sealdata(sealData,sealDatalen);
    FZZSESeal_V4 seal(sealdata);
    FZZBytes bimg = seal.getUserCert();
    if ( bimg.getLen() > 0 ) {
        *outData = (unsigned char *)malloc(bimg.getLen());
        if ( *outData == NULL ) {
            return -402;
        }
        //memset(*outImageData,0x00,bimg.length());
        memcpy(*outData,bimg.getData(),bimg.getLen());
        *outDatalen = bimg.getLen();
    } else {
        *outDatalen = 0;
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI verifySeal(const unsigned char * const sealData,int sealDatalen,CallBack_Verify verifyFunc,const void * callBack_Param)
{
    int ret = ERR_FAIL;
    
    FZZBytes sealdata(sealData,sealDatalen);
    FZZSESeal_V4 seal(sealdata);
    ret = seal.Verify(verifyFunc,callBack_Param);

    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Watermark*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI createWaterMarkImage(bool isTile,bool isImage,double pageWidth,double pageHeight,double beginPosX,double beginPosY,const unsigned char * const imageData,size_t imageDataLen,int textAlign,double horizontalSpacing,double verticalSpacing,
                                          const char * const firstLineText,const char * const firstLineText_FontName,double firstLineText_fontSize,bool isBlob_first,bool isItalic_first,double firstLineText_color_R,
                                          double firstLineText_color_G,double firstLineText_color_B,double firstLineText_alpha,
                                          double lineSpacing0_1,
                                          const char * const secondLineText,const char * const secondLineText_FontName,double secondLineText_fontSize,bool isBlob_second,bool isItalic_second,double secondLineText_color_R,
                                          double secondLineText_color_G,double secondLineText_color_B,double secondLineText_alpha,
                                          double lineSpacing1_2,
                                          const char * const thirdLineText,const char * const thirdLineText_FontName,double thirdLineText_fontSize,bool isBlob_third,bool isItalic_third,double thirdLineText_color_R,
                                          double thirdLineText_color_G,double thirdLineText_color_B,double thirdLineText_alpha,
                                          double rotate,double scaled,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen,/*out*/double * imageWidth,/*out*/double * imageHeight)
{
    
    *outDatalen = 0;
    
    const char * pfirstLineText = firstLineText;
    const char * pfirstLineText_FontName = firstLineText_FontName;
    const char * psecondLineText = secondLineText;
    const char * psecondLineText_FontName = secondLineText_FontName;
    const char * pthirdLineText = thirdLineText;
    const char * pthirdLineText_FontName = thirdLineText_FontName;
#ifdef _MSC_VER
    string utf8str = firstLineText;
    string gbfirstLineText = FZZConst::Utf8toGB2312(utf8str);
    pfirstLineText = gbfirstLineText.c_str();

    utf8str = firstLineText_FontName;
    string gbfirstLineText_FontName = FZZConst::Utf8toGB2312(utf8str);
    pfirstLineText_FontName = gbfirstLineText_FontName.c_str();
    
    utf8str = secondLineText;
    string gbsecondLineText = FZZConst::Utf8toGB2312(utf8str);
    psecondLineText = gbsecondLineText.c_str();
    
    utf8str = secondLineText_FontName;
    string gbsecondLineText_FontName = FZZConst::Utf8toGB2312(utf8str);
    psecondLineText_FontName = gbsecondLineText_FontName.c_str();
    
    utf8str = thirdLineText;
    string gbthirdLineText = FZZConst::Utf8toGB2312(utf8str);
    pthirdLineText = gbthirdLineText.c_str();
    
    utf8str = thirdLineText_FontName;
    string gbthirdLineText_FontName = FZZConst::Utf8toGB2312(utf8str);
    pthirdLineText_FontName = gbthirdLineText_FontName.c_str();
#endif
    
    DLOG("CreateWaterMarkImage => isTile:%s,isImage:%s,pageWidth:%lf,pageHeight:%lf,beginPosX:%lf,beginPosY:%lf,imageData:%s,size_t:%ld,textAlign:%d,horizontalSpacing:%lf,verticalSpacing:%lf,firstLineText:%s,firstLineText_FontName:%s,firstLineText_fontSize:%lf,isBlob_first:%s,isItalic_first:%sfirstLineText_color_R:%lf,firstLineText_color_G:%lf, firstLineText_color_B:%lf, firstLineText_alpha:%lf,lineSpacing0_1:%lf,secondLineText:%s,secondLineText_FontName:%s, secondLineText_fontSize:%lf,isBlob_second:%s,isItalic_second:%s, secondLineText_color_R:%lf,secondLineText_color_G:%lf, secondLineText_color_B:%lf, secondLineText_alpha:%lf,lineSpacing1_2:%lf,thirdLineText:%s,thirdLineText_FontName:%s, thirdLineText_fontSize:%lf, isBlob_third:%s, isItalic_third:%s, thirdLineText_color_R:%lf,thirdLineText_color_G:%lf, thirdLineText_color_B:%lf, thirdLineText_alpha:%lf,rotate:%lf, scaled:%lf",
         isTile?"true":"false",isImage?"true":"false",pageWidth,pageHeight,beginPosX,beginPosY,imageData == NULL?"NULL":"Not NULL",imageDataLen,textAlign,horizontalSpacing,verticalSpacing,firstLineText,firstLineText_FontName,firstLineText_fontSize,isBlob_first?"true":"false",isItalic_first?"true":"false",firstLineText_color_R,
         firstLineText_color_G,firstLineText_color_B,firstLineText_alpha,
         lineSpacing0_1,
         secondLineText,secondLineText_FontName,secondLineText_fontSize,isBlob_second?"true":"false", isItalic_second?"true":"false",secondLineText_color_R,
         secondLineText_color_G,secondLineText_color_B,secondLineText_alpha,
         lineSpacing1_2,
         thirdLineText,thirdLineText_FontName,thirdLineText_fontSize,isBlob_third?"true":"false", isItalic_third?"true":"false",thirdLineText_color_R,
         thirdLineText_color_G,thirdLineText_color_B,thirdLineText_alpha,
         rotate,scaled);
                      
    
    FZZWaterMark waterMark;
    
    
    FZZWaterMark::TYPE_TEXTALIGN wm_textAlign = FZZWaterMark::TYPE_TEXTALIGN::TYPE_LEFT;
    
    switch (textAlign) {
        case 1:
            wm_textAlign = FZZWaterMark::TYPE_TEXTALIGN::TYPE_LEFT;
            break;
        case 2:
            wm_textAlign = FZZWaterMark::TYPE_TEXTALIGN::TYPE_RIGHT;
            break;
        case 3:
            wm_textAlign = FZZWaterMark::TYPE_TEXTALIGN::TYPE_CENTER;
            break;
    }

    FZZBytes picdata = waterMark.getWaterMarkImage(isTile,isImage,pageWidth,pageHeight,beginPosX,beginPosY,imageData,imageDataLen,wm_textAlign,horizontalSpacing,verticalSpacing,
                                                pfirstLineText,pfirstLineText_FontName,firstLineText_fontSize,isBlob_first,isItalic_first,firstLineText_color_R,
                                                firstLineText_color_G,firstLineText_color_B,firstLineText_alpha,
                                                lineSpacing0_1,
                                                psecondLineText,psecondLineText_FontName, secondLineText_fontSize, isBlob_second, isItalic_second, secondLineText_color_R,
                                                 secondLineText_color_G, secondLineText_color_B, secondLineText_alpha,
                                                 lineSpacing1_2,
                                                pthirdLineText,pthirdLineText_FontName, thirdLineText_fontSize, isBlob_third, isItalic_third, thirdLineText_color_R,
                                                 thirdLineText_color_G, thirdLineText_color_B, thirdLineText_alpha,
                                                 rotate, scaled,*imageWidth,*imageHeight);
    
    if ( picdata.getLen() <= 10 ) {
        return ERR_WATERMARK_CREATEIMAGE;
    }
        
    *outData = (unsigned char *)malloc(picdata.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,picdata.getData(),picdata.getLen());
    *outDatalen = picdata.getLen();
    
    return ERR_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************  OFD  *********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API HANDLE DEVAPI ofd_open(const unsigned char * const ofdData,int ofdDatalen)
{
    HANDLE ret = NULL;
    FZZOFD * reader = new FZZOFD();
    if ( reader->Read(ofdData,ofdDatalen) ) {
        ret = reader;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API void DEVAPI ofd_close(HANDLE fileHandle)
{
    if ( fileHandle != NULL ) {
        delete (FZZOFD*)fileHandle;
        fileHandle = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_getFileData(HANDLE fileHandle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    FZZBytes * ofdData = reader->getFileData();
    
    if ( ofdData == NULL || ofdData->getLen() <= 10 ) {
        return ERR_OFD_LOAD;
    }
    
    *outData = (unsigned char *)malloc(ofdData->getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,ofdData->getData(),ofdData->getLen());
    *outDatalen = ofdData->getLen();
    
    return ERR_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_getPageCount(HANDLE fileHandle)
{
    int retPageCount = 0;
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return retPageCount;
    }
    retPageCount = reader->getPageCount();
    return retPageCount;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_getPageSize(HANDLE fileHandle,int pageNumber,/*out*/double &pageWidth,/*out*/double &pageHeight)
{
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    reader->getPageWidthHeight(pageNumber, pageWidth, pageHeight);
    return ERR_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI ofd_isProtect(HANDLE fileHandle)
{
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return false;
    }
    
    return reader->isProtect();
}
//----------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_protect(HANDLE fileHandle,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    int ret = ERR_FAIL;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    FZZOFDProtectSign OFDProtectSign(reader);
    
    if ( !OFDProtectSign.exeProtect(SignFunc,getUserCertFunc,callBack_Param) ) {
        return ERR_OFD_PROTECT;
    }
    
    FZZBytes OFDProtectData;
    OFDProtectSign.generateOFD(OFDProtectData);
 
    if ( OFDProtectData.getLen() <= 10 ) {
        return ERR_OFD_PROTECT;
    }
    
    *outData = (unsigned char *)malloc(OFDProtectData.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,OFDProtectData.getData(),OFDProtectData.getLen());
    *outDatalen = OFDProtectData.getLen();
    
    reader->clear();
    reader->Read(OFDProtectData.getData(),OFDProtectData.getLen());
    
    ret = 0;
    return ret;
}
//----------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_protectionVerify(HANDLE fileHandle,CallBack_Verify verifyFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    
    int ret = ERR_FAIL;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    FZZOFDProtectSign OFDProtectSign(reader);
    vector<string> notHaveFileName;
    string outstr = "{";
   
    if ( !OFDProtectSign.isIntegrity(verifyFunc,callBack_Param,notHaveFileName) ) {
        outstr += "\"verify\":false";
        if ( notHaveFileName.size() > 0 ) {
            outstr += ",nothavefile:[";
            
            vector<string>::const_iterator itr;
            for ( itr = notHaveFileName.begin(); itr != notHaveFileName.end(); itr++ ) {
                outstr += *itr;
                outstr += ",";
            }
            
            outstr = outstr.substr(0,outstr.length()-1);
            
            outstr += "]";
        } else {
            outstr += ",nothavefile:[]";
        }
        ret = ERR_OFD_PROTECT_VERIFY;
    } else {
        outstr += "\"verify\":true,nothavefile:[]";
        ret = ERR_SUCCESS;
    }
    outstr += "}";
    if ( outstr.length() > 0 ) {
        *outData = (unsigned char *)malloc(outstr.length()+1);
        if ( *outData == NULL ) {
            return ERR_ALLOC_MEMORY;
        }
        memset(*outData,0x00,outstr.length()+1);
        memcpy(*outData,outstr.c_str(),outstr.length());
        *outDatalen = outstr.length();
    } else {
        *outDatalen = 0;
    }
    
    return ret;
}
//----------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI ofd_isEncrypt(HANDLE fileHandle)
{
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return false;
    }
    
    return reader->isEncrypt();
}
//----------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_encryptDocument(HANDLE fileHandle,const char * userInfo,CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,CallBack_EncryptSM2 encSM2,CallBack_DecryptSM2 decSM2,CallBack_GenerateRandom genRandom,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    int ret = ERR_FAIL;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    FZZOFDEncrypt encrypt(reader);
    
    encrypt.setCryptCallBack(encSm4CBC,decSm4CBC,encSM2,decSM2,genRandom,(void *)callBack_Param);
    //-----------------
    string strUserInfo = userInfo;
    strUserInfo = "{\"userInfo\":" + strUserInfo + "}";
    
    rapidjson::Document dom;
    if (dom.Parse(strUserInfo.c_str()).HasParseError()) {
        return ERR_OFD_ENCRYPT_USERINFO;
    }
    
    if (!(dom.HasMember("userInfo") && dom["userInfo"].IsArray())) {
        return ERR_OFD_ENCRYPT_USERINFO;
    }
    
    int mode = 0;
    string passWordCert = "";
    string userName = "";
    string userType = "";
    const rapidjson::Value& UserInfo_Array = dom["userInfo"];
    for (int i = 0; i < UserInfo_Array.Size(); ++i) {
        const rapidjson::Value& UserInfo_Array_Item = UserInfo_Array[i];
        
        if (UserInfo_Array_Item.HasMember("mode") && UserInfo_Array_Item["mode"].IsInt()) {
            mode = UserInfo_Array_Item["mode"].GetInt();
        }
        
        if (UserInfo_Array_Item.HasMember("passWordCert") && UserInfo_Array_Item["passWordCert"].IsString()) {
            passWordCert = UserInfo_Array_Item["passWordCert"].GetString();
        }
        
        if (UserInfo_Array_Item.HasMember("userName") && UserInfo_Array_Item["userName"].IsString()) {
            userName = UserInfo_Array_Item["userName"].GetString();
        }
        
        if (UserInfo_Array_Item.HasMember("userType") && UserInfo_Array_Item["userType"].IsString()) {
            userType = UserInfo_Array_Item["userType"].GetString();
        }
        if ( mode == 1 ) {
            encrypt.addUserPassWordMode(passWordCert,userName,userType);
        } else if ( mode == 2 ) {
            encrypt.addUserCertMode(passWordCert,userName,userType);
        }
    }
    
    //---------------------
    
    FZZBytes outOFDData;
    if ( !encrypt.Encrypt(outOFDData) ) {
        return ERR_OFD_ENCRYPT;
    }
    
    if ( outOFDData.getLen() <= 10 ) {
        return ERR_OFD_ENCRYPT;
    }
    
    *outData = (unsigned char *)malloc(outOFDData.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,outOFDData.getData(),outOFDData.getLen());
    *outDatalen = outOFDData.getLen();
    
    reader->clear();
    reader->Read(outOFDData.getData(),outOFDData.getLen());
    
    ret = 0;
    return ret;
}
//----------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_decryptDocument(HANDLE fileHandle,int mode,const char * password,const char * username,const char * usertype,CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,CallBack_EncryptSM2 encSM2,CallBack_DecryptSM2 decSM2,CallBack_GenerateRandom genRandom,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    int ret = ERR_FAIL;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)fileHandle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    FZZOFDEncrypt decrypt(reader);
    
    decrypt.setCryptCallBack(encSm4CBC,decSm4CBC,encSM2,decSM2,genRandom,(void *)callBack_Param);
    
    FZZBytes outOFDData;
    
    if ( !decrypt.Decrypt(mode,mode == 2 ? "" : password,username,usertype,outOFDData) ) {
        return ERR_OFD_DECRYPT;
    }
    
    if ( outOFDData.getLen() <= 10 ) {
        return ERR_OFD_DECRYPT;
    }
    
    *outData = (unsigned char *)malloc(outOFDData.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,outOFDData.getData(),outOFDData.getLen());
    *outDatalen = outOFDData.getLen();
    
    reader->clear();
    reader->Read(outOFDData.getData(),outOFDData.getLen());
    
    ret = 0;
    return ret;
}
//----------------------------------------------------------------------------------------------------
/****************************************OFDStamp****************************/
//----------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_positionSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,int pageIndex,double x,double y,double stampwidth, double stampheight,bool isContinueSign,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    int ret = ERR_FAIL;
    if ( pageIndex <= -2 || pageIndex == 0 ) {
        return ERR_OFD_SIGNSTAMP;
    }
    
    *outDatalen = 0;
    FZZBytes sealData(stampData, stampDatalen);
    FZZSESeal_V4 seseal(sealData);
    
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    FZZOFDSigner signer(reader);
    if ( !signer.isCanSign() ) {
        return ERR_OFD_NOT_SIGN;
    }
    
    
    if ( pageIndex == -1 ) {
        int pageCount = reader->getPageCount();
        for ( int i = 1; i <= pageCount; i++ ) {
            
            FZZSESV4Container signContainer(&seseal,SignFunc,getUserCertFunc,callBack_Param);
            if ( i == pageCount ) {
                if ( isContinueSign ) {
                    signer.setSignMode(FZZSignMode::TYPE::TYPE_ContinueSign);
                } else {
                    signer.setSignMode(FZZSignMode::TYPE::TYPE_WholeProtected);
                }
            } else {
                signer.setSignMode(FZZSignMode::TYPE::TYPE_ContinueSign);
            }
            
            signer.setSignContainer(&signContainer);
            signer.clearApPos();
            
            FZZNormalStampPos nsp(i, x, y, stampwidth, stampheight);
            signer.addApPos(&nsp);
            if ( !signer.exeSign() ) {
                return ERR_OFD_SIGNSTAMP;
            }
            
        }
    } else {

        FZZSESV4Container signContainer(&seseal,SignFunc,getUserCertFunc,callBack_Param);
        if ( isContinueSign ) {
            signer.setSignMode(FZZSignMode::TYPE::TYPE_ContinueSign);
        } else {
            signer.setSignMode(FZZSignMode::TYPE::TYPE_WholeProtected);
        }
        
        signer.setSignContainer(&signContainer);
        
        FZZNormalStampPos nsp(pageIndex, x, y, stampwidth, stampheight);
        signer.addApPos(&nsp);
        if ( !signer.exeSign() ) {
            return ERR_OFD_SIGNSTAMP;
        }
        
    }
    
    FZZBytes signOFDdata;
    signer.generateSignOFD(signOFDdata);
 
    if ( signOFDdata.getLen() <= 10 ) {
        return ERR_OFD_SIGNSTAMP;
    }
    
    *outData = (unsigned char *)malloc(signOFDdata.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,signOFDdata.getData(),signOFDdata.getLen());
    *outDatalen = signOFDdata.getLen();
    
    reader->clear();
    reader->Read(signOFDdata.getData(),signOFDdata.getLen());
    
    ret = 0;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_ridingSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,
                                      int RidingType, double stampwidth,
                                      double stampheight,bool isContinueSign,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                                        /*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;
    FZZBytes sealData(stampData, stampDatalen);
    FZZSESeal_V4 seseal(sealData);
    //FZZKey prvKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",privateKeyData,privateKeyDatalen);
//    FZZCert certsealuser;
//    if ( !certsealuser.loadCert(certData,certDatalen) ) {
//        return -1;
//    }
    
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    
    
    FZZOFDSigner signer(reader);
    if ( !signer.isCanSign() ) {
        return ERR_OFD_NOT_SIGN;
    }
    
    //FZZSESV4Container signContainer(&prvKey,&certsealuser,&seseal);
    FZZSESV4Container signContainer(&seseal,SignFunc,getUserCertFunc,callBack_Param);
    if ( isContinueSign ) {
        signer.setSignMode(FZZSignMode::TYPE::TYPE_ContinueSign);
    } else {
        signer.setSignMode(FZZSignMode::TYPE::TYPE_WholeProtected);
    }
    
    
    signer.setSignContainer(&signContainer);
    
    FZZStampAppearance* stampAppearance = NULL;
    switch(RidingType) {
        case 0:
            stampAppearance = new FZZRidingStampPos(FZZRidingStampPos::TYPE::TYPE_Left, 0, stampwidth, stampheight);
            break;
        case 1:
            stampAppearance = new FZZRidingStampPos(FZZRidingStampPos::TYPE::TYPE_Right, 0, stampwidth, stampheight);
            
            break;
        case 2:
            stampAppearance = new FZZRidingStampPos(FZZRidingStampPos::TYPE::TYPE_Top, 0, stampwidth, stampheight);
            
            break;
        case 3:
            stampAppearance = new FZZRidingStampPos(FZZRidingStampPos::TYPE::TYPE_Bottom, 0, stampwidth, stampheight);
            break;
        case 4:
            stampAppearance = new FZZCuttingRideStampPos(FZZRidingStampPos::TYPE::TYPE_Right, 0, stampwidth, stampheight,0);
            
            break;
        case 5:
            stampAppearance = new FZZCuttingRideStampPos(FZZRidingStampPos::TYPE::TYPE_Top, 0, stampwidth, stampheight,0);
            
            break;
    }
    
    signer.addApPos(stampAppearance);
    if ( !signer.exeSign() ) {
        if ( stampAppearance != NULL ) {
            if ( RidingType >= 4 ) {
                delete (FZZCuttingRideStampPos*)stampAppearance;
            } else {
                delete (FZZRidingStampPos*)stampAppearance;
            }
        }
        return ERR_OFD_SIGNSTAMP;
    }
    
    if ( stampAppearance != NULL ) {
        if ( RidingType >= 4 ) {
            delete (FZZCuttingRideStampPos*)stampAppearance;
        } else {
            delete (FZZRidingStampPos*)stampAppearance;
        }
    }
    
    FZZBytes signOFDdata;
    signer.generateSignOFD(signOFDdata);
 
    if ( signOFDdata.getLen() <= 10 ) {
        return ERR_OFD_SIGNSTAMP;
    }
    
    *outData = (unsigned char *)malloc(signOFDdata.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,signOFDdata.getData(),signOFDdata.getLen());
    *outDatalen = signOFDdata.getLen();
    
    reader->clear();
    reader->Read(signOFDdata.getData(),signOFDdata.getLen());
    
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_keywordSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,
                                      const char * const keyword,const char * const pKeywordRule, double stampwidth,
                                      double stampheight,bool isContinueSign,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                                     /*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    //DLOG("OFDSignStamp_KeyWord begin");
    *outDatalen = 0;
    FZZBytes sealData(stampData, stampDatalen);
    
    //DLOG("OFDSignStamp_KeyWord read seal begin");
    FZZSESeal_V4 seseal(sealData);
    //DLOG("OFDSignStamp_KeyWord read seal end");
//    FZZKey prvKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",privateKeyData,privateKeyDatalen);
//    FZZCert certsealuser;
//    if ( !certsealuser.loadCert(certData,certDatalen) ) {
//        return -1;
//    }
    //DLOG("OFDSignStamp_KeyWord read ofd begin");
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return ERR_OFD_LOAD;
    }
    //DLOG("OFDSignStamp_KeyWord read ofd end");

    FZZOFDFindKeyWord fkw(reader);

    int pagecount = fkw.pageSize();
    vector<FZZKeyWordInfo*> tempkwilist;
    vector<FZZKeyWordInfo*> * kwilist = NULL;
    vector<FZZKeyWordInfo*>::const_iterator it;
    string strkeyword = keyword;
    //DLOG("key work : %s", strkeyword.c_str());
#ifdef _MSC_VER
    //strkeyword = FZZConst::Utf8toGB2312(strkeyword);
    //DLOG("key work => : %s", strkeyword.c_str());
#endif
    //DLOG("OFDSignStamp_KeyWord find word begin");
    for ( int i = 0; i < pagecount; i++ ) {
        //DLOG("OFDSignStamp_KeyWord find word item(%d) begin",i);
        kwilist = fkw.find(i, strkeyword);
        if ( kwilist == NULL || kwilist->size() <= 0 ) {
            continue;
        }
        //DLOG("OFDSignStamp_KeyWord find word item(%d) end",i);
        int index = 0;
        for( it = kwilist->begin(); it != kwilist->end(); it++ ) {
            FZZKeyWordInfo * temp = *it;
            if ( temp == NULL ) {
                continue;
            }
            string tempstr = temp->getKeyWord();
            FZZKeyWordInfo * tempInfo = new FZZKeyWordInfo(temp->getPageIndex(),tempstr,temp->getX(),temp->getY(),temp->getW(),temp->getH());
            tempInfo->setIndex(index++);
            tempkwilist.push_back(tempInfo);
        }
        //DLOG("OFDSignStamp_KeyWord find word item(%d) add end",i);
        
    }
    //DLOG("OFDSignStamp_KeyWord find word end");
    if (  tempkwilist.size() <= 0 ) {
        DLOG("tempkwilist is 0");
        ClearKeyWordList(&tempkwilist);
        return ERR_OFD_KEYWORDRULE;
    }
    //DLOG("OFDSignStamp_KeyWord read word rule begin");
    FZZKeyWordRule keyWordRule;
    kwilist = keyWordRule.getRule(1,&tempkwilist, pKeywordRule,stampwidth,stampheight);
    if ( kwilist == NULL || kwilist->size() <= 0 ) {
        DLOG("kwilist is 0");
        ClearKeyWordList(&tempkwilist);
        return ERR_OFD_KEYWORDRULE;
    }
    //DLOG("OFDSignStamp_KeyWord read word rule end");
    //-----------
    ClearKeyWordList(&tempkwilist);
    //DLOG("OFDSignStamp_KeyWord read sign stamp begin");
    FZZOFDSigner signer(reader);
    if ( !signer.isCanSign() ) {
        return ERR_OFD_NOT_SIGN;
    }
    
  
    for( it = kwilist->begin(); it != kwilist->end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp == NULL ) {
            continue;
        }
        
    
        //FZZSESV4Container signContainer(&prvKey,&certsealuser,&seseal);
        FZZSESV4Container signContainer(&seseal,SignFunc,getUserCertFunc,callBack_Param);
        if ( it + 1 == kwilist->end() ) {
            if ( isContinueSign ) {
                signer.setSignMode(FZZSignMode::TYPE::TYPE_ContinueSign);
            } else {
                signer.setSignMode(FZZSignMode::TYPE::TYPE_WholeProtected);
            }
        } else {
            signer.setSignMode(FZZSignMode::TYPE::TYPE_ContinueSign);
        }
        
        
        signer.setSignContainer(&signContainer);
        signer.clearApPos();
        
        FZZNormalStampPos nsp(temp->getPageIndex()+1, temp->getX(),temp->getY(), stampwidth, stampheight);
        signer.addApPos(&nsp);
        if ( !signer.exeSign() ) {
            return ERR_OFD_SIGNSTAMP;
        }
    }
    //DLOG("OFDSignStamp_KeyWord read sign stamp end");
    
    //DLOG("OFDSignStamp_KeyWord read generate sgin ofd begin");
    FZZBytes signOFDdata;
    signer.generateSignOFD(signOFDdata);
    //DLOG("OFDSignStamp_KeyWord read generate sgin ofd end");
 
    if ( signOFDdata.getLen() <= 10 ) {
        return ERR_OFD_SIGNSTAMP;
    }
    
    *outData = (unsigned char *)malloc(signOFDdata.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,signOFDdata.getData(),signOFDdata.getLen());
    *outDatalen = signOFDdata.getLen();
    //DLOG("OFDSignStamp_KeyWord end");
    reader->clear();
    reader->Read(signOFDdata.getData(),signOFDdata.getLen());
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************OFD Converter ****************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI ofd_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return isTF;
    }
    
    if ( pageIndex < 0 ) {
        return isTF;
    }
    
    string strImageType = imageType;
    transform(strImageType.begin(), strImageType.end(), strImageType.begin(), ::toupper);
    
    bool isSVG = strImageType == "SVG";
    if ( isSVG ) {
        FZZOFDToSvg ofdToImage(reader,FZZCommonUtil::dpiToPpm(72));
        if ( pageIndex >= ofdToImage.pageSize() ) {
            return isTF;
        }
        FZZBytes imageData = ofdToImage.makePage(pageIndex);
        *outData = (unsigned char *)malloc(imageData.getLen());
        
        if ( *outData == NULL ) {
         
            return isTF;
        }
        memcpy(*outData,imageData.getData(),imageData.getLen());
        *outDatalen = imageData.getLen();

        isTF = true;
    } else {

        FZZOFDToImage ofdToImage(reader,FZZCommonUtil::dpiToPpm(72)*scale);

        if ( pageIndex >= ofdToImage.pageSize() ) {
            return isTF;
        }
        FZZBytes imageData = ofdToImage.makePage(pageIndex,imageType);
        *outData = (unsigned char *)malloc(imageData.getLen());
        
        if ( *outData == NULL ) {
         
            return isTF;
        }
        memcpy(*outData,imageData.getData(),imageData.getLen());
        *outDatalen = imageData.getLen();

        isTF = true;
    }
    
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI ofd_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen)
{
    bool isTF = false;
    *intoutDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return isTF;
    }
    //DLOG("----------------DLLMain::OFD2Image to image begin---------------------");
    
    string strImageType = imageType;
    transform(strImageType.begin(), strImageType.end(), strImageType.begin(), ::toupper);
    
    bool isSVG = strImageType == "SVG";
    if ( isSVG ) {
        FZZOFDToSvg ofdToImage(reader,FZZCommonUtil::dpiToPpm(72));
        FZZBytes outBytes;
        string outlen = "";
        int pagecount = ofdToImage.pageSize();
        
        if ( pagecount > 0 ) {
        
            FZZBytes* outdatalist = new FZZBytes[pagecount];
            if ( outdatalist == NULL ) {
                return isTF;
            }
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                outdatalist[i] = ofdToImage.makePage(i);
                itemlen = outdatalist[i].getLen();
                if ( i == pagecount -1 ) {
                    outlen += FZZConst::fmt(itemlen);
                } else {
                    outlen += FZZConst::fmt(itemlen)+",";
                }
                totallen += itemlen;
            }
            //DLOG("----------------DLLMain::OFD2Image to image end---------------------");
            *intoutDatalen = totallen;
            *outData = (unsigned char *)malloc(totallen);
            *outDatalen = (char *)malloc(outlen.length()+1);
            if ( *outData == NULL || *outDatalen == NULL ) {
                if ( outdatalist != NULL ) {
                    delete [] outdatalist;
                    outdatalist = NULL;
                }
                if ( *outData != NULL ) {
                    FZZFreeHandle(*outData);
                    *outData = NULL;
                }
                if ( *outDatalen != NULL ) {
                    FZZFreeHandle(*outDatalen);
                    *outDatalen = NULL;
                }
                
                return isTF;
            }
            
            int pos = 0;
            for ( int x = 0; x < pagecount; x++ ) {
                itemlen = outdatalist[x].getLen();
                memcpy((*outData)+pos,outdatalist[x].getData(),itemlen);
                pos += itemlen;
            }
            //memcpy(*outData,outBytes.getData(),outBytes.getLen());
            if ( outdatalist != NULL ) {
                delete [] outdatalist;
                outdatalist = NULL;
            }
            
            memset(*outDatalen,0x00,outlen.length()+1);
            memcpy(*outDatalen,outlen.c_str(),outlen.length());
          
            isTF = true;
        }
    } else {

        FZZOFDToImage ofdToImage(reader,FZZCommonUtil::dpiToPpm(72)*scale);

        FZZBytes outBytes;
        string outlen = "";
        int pagecount = ofdToImage.pageSize();
        
        if ( pagecount > 0 ) {
        
            FZZBytes* outdatalist = new FZZBytes[pagecount];
            if ( outdatalist == NULL ) {
                return isTF;
            }
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                outdatalist[i] = ofdToImage.makePage(i,imageType);
                itemlen = outdatalist[i].getLen();
                if ( i == pagecount -1 ) {
                    outlen += FZZConst::fmt(itemlen);
                } else {
                    outlen += FZZConst::fmt(itemlen)+",";
                }
                totallen += itemlen;
            }
            //DLOG("----------------DLLMain::OFD2Image to image end---------------------");
            *intoutDatalen = totallen;
            *outData = (unsigned char *)malloc(totallen);
            *outDatalen = (char *)malloc(outlen.length()+1);
            if ( *outData == NULL || *outDatalen == NULL ) {
                if ( outdatalist != NULL ) {
                    delete [] outdatalist;
                    outdatalist = NULL;
                }
                if ( *outData != NULL ) {
                    FZZFreeHandle(*outData);
                    *outData = NULL;
                }
                if ( *outDatalen != NULL ) {
                    FZZFreeHandle(*outDatalen);
                    *outDatalen = NULL;
                }
                
                return isTF;
            }
            
            int pos = 0;
            for ( int x = 0; x < pagecount; x++ ) {
                itemlen = outdatalist[x].getLen();
                memcpy((*outData)+pos,outdatalist[x].getData(),itemlen);
                pos += itemlen;
            }
            //memcpy(*outData,outBytes.getData(),outBytes.getLen());
            if ( outdatalist != NULL ) {
                delete [] outdatalist;
                outdatalist = NULL;
            }
            
            memset(*outDatalen,0x00,outlen.length()+1);
            memcpy(*outDatalen,outlen.c_str(),outlen.length());
          
            isTF = true;
        }
    }
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI ofd_toImageZip(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return isTF;
    }
    //DLOG("----------------DLLMain::OFD2Image zip begin---------------------");
    string strImageType = imageType;
    transform(strImageType.begin(), strImageType.end(), strImageType.begin(), ::toupper);
    
    bool isSVG = strImageType == "SVG";
    if ( isSVG ) {
        FZZOFDToSvg ofdToImage(reader,FZZCommonUtil::dpiToPpm(72));
        
        FZZBytes outBytes;
      
        int pagecount = ofdToImage.pageSize();
        if ( pagecount > 0 ) {
        
    //        FZZBytes* outdatalist = new FZZBytes[pagecount];
    //        if ( outdatalist == NULL ) {
    //            return isTF;
    //        }
            vector<FZZBytes*> outdatalist;
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                FZZBytes* imageData = new FZZBytes(ofdToImage.makePage(i));
                outdatalist.push_back(imageData);
                itemlen = imageData->getLen();
                totallen += itemlen+8;//0000.jpg len
            }
            //DLOG("----------------DLLMain::OFD2Image end---------------------");
            //DLOG("----------------DLLMain::OFD2Image zip begin---------------------");
            FZZZipTracks zipTracks;
#ifdef MINIZIPNG
            zipTracks.CreateZip_mem();

            for (int x = 0; x < pagecount; x++) {
                //itemlen = outdatalist[x]->getLen();
                //DLOG("OFD2ImageToZip zip add %d",outdatalist[x]->getLen());
                zipTracks.AddFileToZip((FZZConst::fmt(x) + "." + imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }

            FZZBytes zipoutData = zipTracks.CloseZip_mem();
            *outData = (unsigned char*)malloc(zipoutData.getLen());
            if (*outData != NULL) {
                memcpy(*outData, zipoutData.getData(), zipoutData.getLen());
                *outDatalen = zipoutData.getLen();

                isTF = true;
            }

            vector<FZZBytes*>::const_iterator it;
            for (it = outdatalist.begin(); it != outdatalist.end(); it++) {
                if (*it != NULL) {
                    delete* it;
                }
            }
            outdatalist.clear();
#else
            unsigned long maxsize = zipTracks.getZipFileMaxSize(totallen);
            *outData = (unsigned char *)malloc(maxsize);
           
            if ( *outData == NULL  ) {
    //            if ( outdatalist != NULL ) {
    //                delete [] outdatalist;
    //                outdatalist = NULL;
    //            }
                vector<FZZBytes*>::const_iterator it;
                for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                    if ( *it != NULL ) {
                        delete *it;
                    }
                }
                outdatalist.clear();
                
                if ( *outData != NULL ) {
                    FreeHandle(*outData);
                    *outData = NULL;
                }
                return isTF;
            }
            
            memset(*outData, 0x00, maxsize);
            zipTracks.CreateZip_mem(*outData, maxsize);
            
            for ( int x = 0; x < pagecount; x++ ) {
                //itemlen = outdatalist[x]->getLen();
                zipTracks.AddFileToZip((FZZConst::fmt(x)+"."+imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }
            
            
            *outDatalen = zipTracks.CloseZip_mem();
            
    //        if ( outdatalist != NULL ) {
    //            delete [] outdatalist;
    //            outdatalist = NULL;
    //        }
            vector<FZZBytes*>::const_iterator it;
            for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                if ( *it != NULL ) {
                    delete *it;
                }
            }
            outdatalist.clear();
            
            isTF = true;
#endif
        }
    } else {
        FZZOFDToImage ofdToImage(reader,FZZCommonUtil::dpiToPpm(72)*scale);

        FZZBytes outBytes;
      
        int pagecount = ofdToImage.pageSize();
        if ( pagecount > 0 ) {
        
    //        FZZBytes* outdatalist = new FZZBytes[pagecount];
    //        if ( outdatalist == NULL ) {
    //            return isTF;
    //        }
            vector<FZZBytes*> outdatalist;
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                FZZBytes* imageData = new FZZBytes(ofdToImage.makePage(i,imageType));
                outdatalist.push_back(imageData);
                itemlen = imageData->getLen();
                totallen += itemlen+8;//0000.jpg len
            }
            //DLOG("----------------DLLMain::OFD2Image end---------------------");
            //DLOG("----------------DLLMain::OFD2Image zip begin---------------------");
            FZZZipTracks zipTracks;
#ifdef MINIZIPNG
            zipTracks.CreateZip_mem();

            for (int x = 0; x < pagecount; x++) {
                //itemlen = outdatalist[x]->getLen();
                //DLOG("OFD2ImageToZip zip add %d",outdatalist[x]->getLen());
                zipTracks.AddFileToZip((FZZConst::fmt(x) + "." + imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }

            FZZBytes zipoutData = zipTracks.CloseZip_mem();
            *outData = (unsigned char*)malloc(zipoutData.getLen());
            if (*outData != NULL) {
                memcpy(*outData, zipoutData.getData(), zipoutData.getLen());
                *outDatalen = zipoutData.getLen();

                isTF = true;
            }

            vector<FZZBytes*>::const_iterator it;
            for (it = outdatalist.begin(); it != outdatalist.end(); it++) {
                if (*it != NULL) {
                    delete* it;
                }
            }
            outdatalist.clear();
#else
            unsigned long maxsize = zipTracks.getZipFileMaxSize(totallen);
            *outData = (unsigned char *)malloc(maxsize);
           
            if ( *outData == NULL  ) {
    //            if ( outdatalist != NULL ) {
    //                delete [] outdatalist;
    //                outdatalist = NULL;
    //            }
                vector<FZZBytes*>::const_iterator it;
                for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                    if ( *it != NULL ) {
                        delete *it;
                    }
                }
                outdatalist.clear();
                
                if ( *outData != NULL ) {
                    FreeHandle(*outData);
                    *outData = NULL;
                }
                return isTF;
            }
            
            memset(*outData, 0x00, maxsize);
            zipTracks.CreateZip_mem(*outData, maxsize);
            
            for ( int x = 0; x < pagecount; x++ ) {
                //itemlen = outdatalist[x]->getLen();
                zipTracks.AddFileToZip((FZZConst::fmt(x)+"."+imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }
            
            
            *outDatalen = zipTracks.CloseZip_mem();
            
    //        if ( outdatalist != NULL ) {
    //            delete [] outdatalist;
    //            outdatalist = NULL;
    //        }
            vector<FZZBytes*>::const_iterator it;
            for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                if ( *it != NULL ) {
                    delete *it;
                }
            }
            outdatalist.clear();
            
            isTF = true;
#endif
        }
    }
    
    //DLOG("----------------DLLMain::OFD2Image zip end---------------------");
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI ofdToPdf(HANDLE handle,bool isNoStamp,bool isEncrypt,const char * password,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return isTF;
    }
    

    FZZOFDToPDF ofd2pdf(reader);

    ofd2pdf.SetNoStamp(isNoStamp);
    ofd2pdf.setPassWord(password);
    ofd2pdf.setEncrypt(isEncrypt);
    int pagecount = ofd2pdf.getOFDPageCount();
   
    ofd2pdf.setGenFontFlag(true);
    for ( int i = 0; i < pagecount; i++  ) {
        ofd2pdf.makePage(i);
    }
    ofd2pdf.generatePDFFont();
   
    ofd2pdf.setGenFontFlag(false);
    for ( int i = 0; i < pagecount; i++  ) {
        ofd2pdf.makePage(i);
    }

    FZZBytes pdfdata = ofd2pdf.generatePDF();
    
    *outData = (unsigned char *)malloc(pdfdata.getLen());
    
    if ( *outData == NULL ) {
     
        return isTF;
    }
    memcpy(*outData,pdfdata.getData(),pdfdata.getLen());
    *outDatalen = pdfdata.getLen();

    isTF = true;
    
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI verifyDocment(const unsigned char * const docdata,int doclen,int doctype,char * passWord,CallBack_Verify verifyFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    int ret = 0;
    
    string outstr = "[";
    if ( doctype == 1 ) {
        //ofd
//        OFDReader reader;
//        if ( !reader.init(docdata,doclen) ) {
//            return ERR_OFD_LOAD;
//        }
//
//        //如果 要符合国办标准，用isCanSign检测是否可以盖章，如果可以盖章，所以印章都不验证，直接为false
////                OFDSigner signer(&reader);
////                if ( !signer.isCanSign() ) {
////                    return ERR_OFD_NOT_SIGN;
////                }
//
//        OFDValidator ofdValidator(&reader);
        FZZOFD reader;
        if ( !reader.Read(docdata,doclen) ) {
            return ERR_OFD_LOAD;
        }
        
        
      
        
        //如果 要符合国办标准，用isCanSign检测是否可以盖章，如果可以盖章，所以印章都不验证，直接为false
//                FZZOFDSigner signer(&reader);
//                if ( !signer.isCanSign() ) {
//                    return ERR_OFD_NOT_SIGN;
//                }
        
        FZZOFDValidator ofdValidator(&reader);
        
        vector<string> pageIndexs;
        vector<string> sids;
        vector<string> signTimes;
        vector<FZZBytes *> stampimages;
        
        ofdValidator.getSignInfos(pageIndexs, sids, signTimes, stampimages);
        
        vector<string>::const_iterator siditer;
        for (siditer = sids.begin(); siditer != sids.end(); siditer++) {
            string sid = *siditer;
            
            if ( !sid.empty() ) {
                outstr += "{";
                string outsigntime;
                string outsigner;
                
                
                if ( ofdValidator.Verify(sid,verifyFunc,callBack_Param, outsigntime, outsigner) == 0 ) {
                    outstr += "\"verify\":true,";
                } else {
                    outstr += "\"verify\":false,";
                }
                outstr += "\"certCN\":\"" + outsigner + "\",";
                outstr += "\"signDate\":\""+ outsigntime +"\",";
                outstr += "\"pageIndex\":\"" + *(pageIndexs.begin()+(siditer - sids.begin())) + "\",";
                outstr += "\"signAlg\":\"SM3-SM2\"";
                if ( siditer - sids.begin() == sids.size() -1 ) {
                    outstr += "}";
                } else {
                    outstr += "},";
                }
            }
            
            
        }
        
        pageIndexs.clear();
        sids.clear();
        signTimes.clear();
        vector<FZZBytes*>::const_iterator stampimageiter;
        for (stampimageiter = stampimages.begin(); stampimageiter != stampimages.end(); stampimageiter++) {
            if ( *stampimageiter != NULL ) {
                delete *stampimageiter;
            }
        }
        stampimages.clear();
        
    } else if ( doctype == 2 ) {
        //pdf
        FZZPDF pdf;
        if ( !pdf.OpenPDF(docdata,doclen) ) {
            return ERR_PDF_LOAD;
        }
        FZZPDFSigner pdfSigner(&pdf);
        
        if ( pdfSigner.isNeedPassWord() ) {
            if ( passWord != NULL && strlen(passWord) > 0 ) {
                if ( !pdfSigner.VerifyPassWord(passWord) ) {
                    return ERR_PDF_VERIFY_PW;
                }
            } else {
                return ERR_PDF_NOT_SET_PW;
            }
            
        }
        
        
        
        vector<string> pageIndexs;
        vector<string> sids;
        vector<FZZBytes *> stampimages;
        
        pdfSigner.getSignInfos(pageIndexs, sids, stampimages);
        vector<string>::const_iterator siditer;
        for (siditer = sids.begin(); siditer != sids.end(); siditer++) {
            string sid = *siditer;
            if ( !sid.empty() ) {
                outstr += "{";
                string outsigner = "";
                string outsigntime = "";
                if ( pdfSigner.Verify(sid,verifyFunc,callBack_Param,outsigner,outsigntime) == 0 ) {
                    outstr += "\"verify\":true,";
                } else {
                    outstr += "\"verify\":false,";
                }
                outstr += "\"certCN\":\"" + outsigner + "\",";
                outstr += "\"signDate\":\""+ outsigntime +"\",";
                outstr += "\"pageIndex\":\"" + *(pageIndexs.begin()+(siditer - sids.begin())) + "\",";
                outstr += "\"signAlg\":\"SM3-SM2\"";
                if ( siditer - sids.begin() == sids.size() -1 ) {
                    outstr += "}";
                } else {
                    outstr += "},";
                }
            }
        }
        
        pageIndexs.clear();
        sids.clear();
        
        stampimages.clear();
    } else {
        ret = ERR_DOC_TYPE;
    }
    
    outstr += "]";
    
    if ( outstr.length() > 0 ) {
        *outData = (unsigned char *)malloc(outstr.length()+1);
        if ( *outData == NULL ) {
            return ERR_ALLOC_MEMORY;
        }
        memset(*outData,0x00,outstr.length()+1);
        memcpy(*outData,outstr.c_str(),outstr.length());
        *outDatalen = outstr.length();
    } else {
        *outDatalen = 0;
    }
    ret = 0;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI ofd_clearSigns(HANDLE handle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;
    FZZOFD * reader = (FZZOFD *)handle;
    if ( reader == NULL ) {
        return ERR_PDF_LOAD;
    }
    
    FZZBytes signpdata;
    FZZOFDSignCleaner signCleaner(reader);
    signCleaner.clean(signpdata);
    
    if ( signpdata.getLen() <= 10 ) {
        return ERR_PDF_GEN;
    }
        
    *outData = (unsigned char *)malloc(signpdata.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    
    reader->clear();
    reader->Read(signpdata.getData(),signpdata.getLen());
    
    memcpy(*outData,signpdata.getData(),signpdata.getLen());
    *outDatalen = signpdata.getLen();
    
    return 0;
}
//----------------------------------------------------------------------------------------------------
/****************************************************  PDF  *********************************************************/
//----------------------------------------------------------------------------------------------------
DLL_API HANDLE DEVAPI pdf_open(const unsigned char * const fileData,int fileDatalen)
{
    HANDLE ret = NULL;
    FZZPDF * reader = new FZZPDF();
    if ( reader->OpenPDF(fileData,fileDatalen) ) {
        ret = reader;
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------
DLL_API void DEVAPI pdf_close(HANDLE fileHandle)
{
    if ( fileHandle != NULL ) {
        delete (FZZPDF*)fileHandle;
        fileHandle = NULL;
    }
}
//----------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_getFileData(HANDLE fileHandle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    FZZPDF * pdf = (FZZPDF *)fileHandle;
    if ( pdf == NULL ) {
        return ERR_PDF_LOAD;
    }
    
    FZZBytes * pdfData = pdf->getSourceData();
    
    if ( pdfData == NULL || pdfData->getLen() <= 10 ) {
        return ERR_OFD_LOAD;
    }
    
    *outData = (unsigned char *)malloc(pdfData->getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    memcpy(*outData,pdfData->getData(),pdfData->getLen());
    *outDatalen = pdfData->getLen();
    
    return ERR_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_getPageCount(HANDLE fileHandle)
{
    int retPageCount = 0;
    FZZPDF * pdf = (FZZPDF *)fileHandle;
    if ( pdf == NULL ) {
        return retPageCount;
    }
    
    FZZPDFToImage pdfToImage(pdf);
    retPageCount = pdfToImage.pageSize();
    
    return retPageCount;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_getPageSize(HANDLE fileHandle,int pageNumber,/*out*/double &pageWidth,/*out*/double &pageHeight)
{
    FZZPDF * pdf = (FZZPDF *)fileHandle;
    if ( pdf == NULL ) {
        return ERR_PDF_LOAD;
    }
    if ( pageNumber <= 0 ) {
        pageNumber = 1;
    }
    FZZPDFSigner pdfSigner(pdf);
    pdfSigner.getPageWidthHeight(pageNumber - 1,pageWidth,pageHeight);
    return ERR_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI pdf_isNeedPassWord(HANDLE fileHandle)
{
    FZZPDF * pdf = (FZZPDF *)fileHandle;
    if ( pdf == NULL ) {
        return false;
    }
    
    FZZPDFSigner pdfSigner(pdf);
    return pdfSigner.isNeedPassWord();
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API void DEVAPI pdf_setPassWord(HANDLE fileHandle,char * password)
{
    FZZPDF * pdf = (FZZPDF *)fileHandle;
    if ( pdf == NULL || password == NULL || strlen(password) == 0 ) {
        return;
    }
    //DLOG("PDFSetPassword => pw[%s]",password);
    pdf->setPassWord(password);
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_documnetEncryptDecrypt(HANDLE fileHandle,bool isEncrypt,char * passWord,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;
    FZZPDF * pdf = (FZZPDF *)fileHandle;
    if ( pdf == NULL ) {
        return ERR_PDF_LOAD;
    }
    //DLOG("PDFEncryptDecrypt_Handle => pw[%s]",passWord);
    FZZPDFCreator pdfCreator(pdf);
    if ( pdfCreator.isNeedPassWord() ) {
        string pw = pdf->getPassword();
        if ( pw.empty() ) {
            return ERR_PDF_NOT_SET_PW;
        }
        if ( !pdfCreator.VerifyPassWord(pw) ) {
            return ERR_PDF_VERIFY_PW;
        }
    }
    
    int ret = ERR_SUCCESS;
    FZZBytes signpdata;
    if ( (ret = pdfCreator.CopyPDF(isEncrypt,passWord == NULL ? "" : passWord,signpdata)) != ERR_SUCCESS ) {
        return ret;
    }
    
    if ( signpdata.getLen() > 10 ) {
        *outData = (unsigned char *)malloc(signpdata.getLen());
        if ( *outData == NULL ) {
            //DLOG("SignStamp_Pos_PDF....-102");
            return ERR_ALLOC_MEMORY;
        }
        pdf->OpenPDF(signpdata);
        memcpy(*outData,signpdata.getData(),signpdata.getLen());
        *outDatalen = signpdata.getLen();
    } else {
        *outDatalen = 0;
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFStamp*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_positionSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,double alpha,int pageIndex,double x,double y,double stampwidth, double stampheight,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;

    //DLOG("SignStamp_Pos_PDF....begin");
    if ( getUserCertFunc == NULL || SignFunc == NULL ) {
        return ERR_CALLBACK_NULL;
    }
    //fzz edit begin 2024.06.07
//    FZZBytes certData = getUserCertFunc(callBack_Param);
//    if ( certData.getLen() <= 0 ) {
//        return ERR_CERT_LOAD;
//    }
    size_t bufferLen = 0;
    unsigned char * buffer = NULL;
    getUserCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return ERR_CERT_LOAD;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return ERR_CERT_LOAD;
    }
    getUserCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return ERR_CERT_LOAD;
    }
    FZZBytes certData;
    certData.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    //fzz edit end 2024.06.07
    FZZBytes picdata(stampData, stampDatalen);
//    FZZKey prvKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",privateKeyData,privateKeyDatalen);
    
    
    FZZCert certsealuser;
    if ( !certsealuser.loadCert(certData.getData(),certData.getLen()) ) {
        //DLOG("SignStamp_Pos_PDF....-100");
        return ERR_CERT_LOAD;
    }
    
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return ERR_PDF_LOAD;
    }
    
    float width = FZZCommonUtil::millimetersToPixel(stampwidth, 72);
    float height = FZZCommonUtil::millimetersToPixel(stampheight, 72);
    
    FZZBytes signpdata;
    int ret = ERR_SUCCESS;
    if ( pageIndex == -1 ) {
        FZZPDFSigner * pdfSigner = new FZZPDFSigner(pdf);
        if ( pdfSigner == NULL ) {
            return ERR_PDF_LOAD;
        }
        
        if ( pdfSigner->isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfSigner->VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
        
        int pageCount = pdfSigner->pageSize();
        int stampcount = 0;
        FZZBytes temppdfdata;
        
        for( int i = 1; i <= pageCount; i++ ) {
            stampcount++;
            
            if ( pdfSigner->SignStamp(i,picdata,alpha,x,y,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param)  != 0 ) {
                break;
            }
            if ( stampcount == 6 ) {
                if ( pdfSigner != NULL ) {
                    temppdfdata = pdfSigner->generatePDF();
                    delete pdfSigner;
                }
                //pdf.clear();
                pdf->OpenPDF(temppdfdata);
                pdfSigner = new FZZPDFSigner(pdf);
                if ( pdfSigner->isNeedPassWord() ) {
                    string pw = pdf->getPassword();
                    if ( pw.empty() ) {
                        return ERR_PDF_NOT_SET_PW;
                    }
                    if ( !pdfSigner->VerifyPassWord(pw) ) {
                        return ERR_PDF_VERIFY_PW;
                    }
                }
                stampcount = 0;
            }
            
        }
        
        if ( pdfSigner != NULL ) {
            signpdata = pdfSigner->generatePDF();
            delete pdfSigner ;
            
        }
    } else {
    
        FZZPDFSigner pdfSigner(pdf);
        //DLOG("PDFSignStamp_Pos=>SignStamp....begin");
        if ( pdfSigner.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfSigner.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
        ret = pdfSigner.SignStamp(pageIndex,picdata,alpha,x,y,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
        if ( ret != 0 ) {
            //DLOG("SignStamp_Pos_PDF....err : %d",ret);
            return ret;
        }
        //DLOG("PDFSignStamp_Pos=>SignStamp....end");
        signpdata = pdfSigner.generatePDF();
        if ( signpdata.getLen() <= 10 ) {
            //DLOG("SignStamp_Pos_PDF....-101");
            return ERR_PDF_GEN;
        }
    }
    
    if ( signpdata.getLen() > 10 ) {
        
        
        
        *outData = (unsigned char *)malloc(signpdata.getLen());
        if ( *outData == NULL ) {
            //DLOG("SignStamp_Pos_PDF....-102");
            return ERR_ALLOC_MEMORY;
        }
        pdf->OpenPDF(signpdata);
        memcpy(*outData,signpdata.getData(),signpdata.getLen());
        *outDatalen = signpdata.getLen();
    } else {
        *outDatalen = 0;
    }
    
    //DLOG("SignStamp_Pos_PDF....end");
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_ridingSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,double alpha,
                                      int RidingType, double stampwidth,
                                      double stampheight,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;
    if ( getUserCertFunc == NULL || SignFunc == NULL ) {
        //DLOG("PDFSignStamp_Riding.....1");
        return ERR_CALLBACK_NULL;
    }
    
    
    //fzz edit begin 2024.06.07
//    FZZBytes certData = getUserCertFunc(callBack_Param);
//    if ( certData.getLen() <= 0 ) {
//        return ERR_CERT_LOAD;
//    }
    size_t bufferLen = 0;
    unsigned char * buffer = NULL;
    getUserCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return ERR_CERT_LOAD;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return ERR_CERT_LOAD;
    }
    getUserCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return ERR_CERT_LOAD;
    }
    FZZBytes certData;
    certData.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    //fzz edit end 2024.06.07
    //DLOG("PDFSignStamp_Riding.....begin");
    FZZBytes picdata(stampData, stampDatalen);
    //FZZKey prvKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",privateKeyData,privateKeyDatalen);
    FZZCert certsealuser;
    if ( !certsealuser.loadCert(certData.getData(),certData.getLen()) ) {
        //DLOG("PDFSignStamp_Riding.....3");
        return ERR_CERT_LOAD;
    }
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        //DLOG("PDFSignStamp_Riding.....4");
        return ERR_PDF_LOAD;
    }
    FZZPDFSigner pdfSigner(pdf);
    
    if ( pdfSigner.isNeedPassWord() ) {
        string pw = pdf->getPassword();
        if ( pw.empty() ) {
            return ERR_PDF_NOT_SET_PW;
        }
        if ( !pdfSigner.VerifyPassWord(pw) ) {
            return ERR_PDF_VERIFY_PW;
        }
    }
    
    float width = FZZCommonUtil::millimetersToPixel(stampwidth, 72);
    float height = FZZCommonUtil::millimetersToPixel(stampheight, 72);
    int ret = 0;
   
    switch(RidingType) {
        case 0:
            ret = pdfSigner.SignRidingStamp(FZZPDFSigner::TYPE::TYPE_Left,picdata,alpha,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
            break;
        case 1:
           
            ret = pdfSigner.SignRidingStamp(FZZPDFSigner::TYPE::TYPE_Right,picdata,alpha,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
            break;
        case 2:

            ret = pdfSigner.SignRidingStamp(FZZPDFSigner::TYPE::TYPE_Top,picdata,alpha,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
            break;
        case 3:
    
            ret = pdfSigner.SignRidingStamp(FZZPDFSigner::TYPE::TYPE_Bottom,picdata,alpha,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
            break;
        case 4:
    
            ret = pdfSigner.SignCuttingRidingStamp(FZZPDFSigner::TYPE::TYPE_Right,picdata,alpha,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
            break;
        case 5:
      
            ret = pdfSigner.SignCuttingRidingStamp(FZZPDFSigner::TYPE::TYPE_Top,picdata,alpha,width,height,true,&certsealuser,NULL,SignFunc,callBack_Param);
            break;
    }
    
    if ( ret != 0 ) {
        //DLOG("PDFSignStamp_Riding.....5,%d",ret);
        return ret;
    }
    FZZBytes signpdata = pdfSigner.generatePDF();
    if ( signpdata.getLen() <= 10 ) {
        //DLOG("PDFSignStamp_Riding.....6,%d",ret);
        return ERR_PDF_GEN;
    }
        
    
    
    *outData = (unsigned char *)malloc(signpdata.getLen());
    if ( *outData == NULL ) {
        //DLOG("PDFSignStamp_Riding.....7,%d",ret);
        return ERR_ALLOC_MEMORY;
    }
    pdf->OpenPDF(signpdata);
    memcpy(*outData,signpdata.getData(),signpdata.getLen());
    *outDatalen = signpdata.getLen();
    
    //DLOG("PDFSignStamp_Riding.....end");
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_keywordSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,double alpha,
                                      const char * const keyword,const char * const pKeywordRule, double stampwidth,
                                      double stampheight,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;
    if ( getUserCertFunc == NULL || SignFunc == NULL ) {
        return ERR_CALLBACK_NULL;
    }
    
    //fzz edit begin 2024.06.07
//    FZZBytes certData = getUserCertFunc(callBack_Param);
//    if ( certData.getLen() <= 0 ) {
//        return ERR_CERT_LOAD;
//    }
    size_t bufferLen = 0;
    unsigned char * buffer = NULL;
    getUserCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return ERR_CERT_LOAD;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return ERR_CERT_LOAD;
    }
    getUserCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return ERR_CERT_LOAD;
    }
    FZZBytes certData;
    certData.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    //fzz edit end 2024.06.07
    FZZBytes picdata(stampData, stampDatalen);
    //FZZKey prvKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",privateKeyData,privateKeyDatalen);
    FZZCert certsealuser;
    if ( !certsealuser.loadCert(certData.getData(),certData.getLen()) ) {
        return ERR_CERT_LOAD;
    }
    
    float xs[500] = {0};
    float ys[500] = {0};
    float ws[500] = {0};
    float hs[500] = {0};
    int count = 0;
    
    float width = FZZCommonUtil::millimetersToPixel(stampwidth, 72);
    float height = FZZCommonUtil::millimetersToPixel(stampheight, 72);
    
    string strKeyWord = keyword;
    
    vector<FZZKeyWordInfo*> tempKeyWordList;
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return ERR_PDF_LOAD;
    }
    
    FZZPDFToImage pdfToImage(pdf);
    if ( pdfToImage.isNeedPassWord() ) {
        string pw = pdf->getPassword();
        if ( pw.empty() ) {
            return ERR_PDF_NOT_SET_PW;
        }
        if ( !pdfToImage.VerifyPassWord(pw) ) {
            return ERR_PDF_VERIFY_PW;
        }
    }
    
    int pageCount = pdfToImage.pageSize();
    for (int x = 0; x < pageCount; x++) {
        count = 0;
        pdfToImage.findWord(x,strKeyWord.c_str(),xs,ys,ws,hs,&count,500);
        int index = 0;
        for( int i = 0; i < count; i++ ) {
            FZZKeyWordInfo * tempInfo = new FZZKeyWordInfo(x,strKeyWord,xs[i],ys[i],ws[i],hs[i]);
            tempInfo->setIndex(index++);
            tempKeyWordList.push_back(tempInfo);
        }
    }
    //DLOG("KeyRule:%s",pKeywordRule);
    FZZKeyWordRule keyWordRule;
    vector<FZZKeyWordInfo*> * kwilist = keyWordRule.getRule(2,&tempKeyWordList, pKeywordRule,width,height);
    if ( kwilist == NULL || kwilist->size() <= 0 ) {
        ClearKeyWordList(&tempKeyWordList);
        //DLOG("kwilist is null");
        return -8;
    }
    
//    FZZPDF pdf;
//    if ( !pdf.OpenPDF(pdfData,pdfDatalen) ) {
//        return ERR_PDF_LOAD;
//    }
    
    FZZPDFSigner * pdfSigner = new FZZPDFSigner(pdf);
    
    if ( pdfSigner->isNeedPassWord() ) {
        string pw = pdf->getPassword();
        if ( pw.empty() ) {
            return ERR_PDF_NOT_SET_PW;
        }
        if ( !pdfSigner->VerifyPassWord(pw) ) {
            return ERR_PDF_VERIFY_PW;
        }
    }
    
    int stampcount = 0;
    FZZBytes temppdfdata;
    vector<FZZKeyWordInfo*>::const_iterator it;
    for( it = kwilist->begin(); it != kwilist->end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp == NULL ) {
            continue;
        }
        stampcount++;
        
        if ( pdfSigner->SignStamp(temp->getPageIndex()+1,picdata,alpha,temp->getX(),temp->getY(),width,height,true,&certsealuser,NULL,SignFunc,callBack_Param)  != 0 ) {
            break;
        }
        if ( stampcount == 6 ) {
            if ( pdfSigner != NULL ) {
                temppdfdata = pdfSigner->generatePDF();
                delete pdfSigner;
            }
            //pdf.clear();
            pdf->OpenPDF(temppdfdata);
            pdfSigner = new FZZPDFSigner(pdf);
            if ( pdfSigner->isNeedPassWord() ) {
                string pw = pdf->getPassword();
                if ( pw.empty() ) {
                    return ERR_PDF_NOT_SET_PW;
                }
                if ( !pdfSigner->VerifyPassWord(pw) ) {
                    return ERR_PDF_VERIFY_PW;
                }
            }
            stampcount = 0;
        }
        
    }
    
    ClearKeyWordList(&tempKeyWordList);
    if ( pdfSigner != NULL ) {
        FZZBytes signpdata = pdfSigner->generatePDF();
        delete pdfSigner ;
        if ( signpdata.getLen() <= 10 ) {
            return ERR_PDF_GEN;
        }
            
        
        
        *outData = (unsigned char *)malloc(signpdata.getLen());
        if ( *outData == NULL ) {
            return ERR_ALLOC_MEMORY;
        }
        pdf->OpenPDF(signpdata);
        memcpy(*outData,signpdata.getData(),signpdata.getLen());
        *outDatalen = signpdata.getLen();
    } else {
        *outDatalen = 0;
    }
    
    
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API int DEVAPI pdf_clearSigns(HANDLE handle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    *outDatalen = 0;
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return ERR_PDF_LOAD;
    }
    
    FZZPDFSigner pdfSigner(pdf);
    if ( pdfSigner.isNeedPassWord() ) {
        string pw = pdf->getPassword();
        if ( pw.empty() ) {
            return ERR_PDF_NOT_SET_PW;
        }
        if ( !pdfSigner.VerifyPassWord(pw) ) {
            return ERR_PDF_VERIFY_PW;
        }
    }
    
    if ( pdfSigner.Clear_Signs() != 0 ) {
        return ERR_PDF_DEL_STAMP;
    }
    
    FZZBytes signpdata = pdfSigner.generatePDF();
    
    if ( signpdata.getLen() <= 10 ) {
        return ERR_PDF_GEN;
    }
        
    *outData = (unsigned char *)malloc(signpdata.getLen());
    if ( *outData == NULL ) {
        return ERR_ALLOC_MEMORY;
    }
    pdf->OpenPDF(signpdata);
    memcpy(*outData,signpdata.getData(),signpdata.getLen());
    *outDatalen = signpdata.getLen();
    
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDF Converter*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI pdf_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    if ( pageIndex < 0 ) {
        return isTF;
    }
    
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return isTF;
    }
    string strImageType = imageType;
    transform(strImageType.begin(), strImageType.end(), strImageType.begin(), ::toupper);
    
    bool isSVG = strImageType == "SVG";
    if ( isSVG ) {
        FZZPDF2SVG pdfToSvg(pdf);
                   
        if ( pdfToSvg.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfToSvg.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
        
        if ( pageIndex >= pdfToSvg.pageSize() ) {

            return isTF;
        }
        FZZBytes imageData = pdfToSvg.makePage(pageIndex);
        *outData = (unsigned char *)malloc(imageData.getLen());
        
        if ( *outData == NULL ) {
         
            return isTF;
        }
        memcpy(*outData,imageData.getData(),imageData.getLen());
        *outDatalen = imageData.getLen();

        isTF = true;
        
    } else {
            
        FZZPDFToImage pdfToImage(pdf);
        
        if ( pdfToImage.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfToImage.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
           
        if ( pageIndex >= pdfToImage.pageSize() ) {

            return isTF;
        }
        FZZBytes imageData = pdfToImage.makePage(pageIndex,imageType,scale);
        *outData = (unsigned char *)malloc(imageData.getLen());
        
        if ( *outData == NULL ) {
         
            return isTF;
        }
        memcpy(*outData,imageData.getData(),imageData.getLen());
        *outDatalen = imageData.getLen();

        isTF = true;
    }
    
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI pdf_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen)
{
    bool isTF = false;
    *intoutDatalen = 0;
    
    //double scaledValue = scale;
    
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return isTF;
    }
    
    string strImageType = imageType;
    transform(strImageType.begin(), strImageType.end(), strImageType.begin(), ::toupper);
    
    bool isSVG = strImageType == "SVG";
    if ( isSVG ) {
        FZZPDF2SVG pdfToSvg(pdf);
           
        if ( pdfToSvg.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfToSvg.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
            
        FZZBytes outBytes;
        string outlen = "";
        int pagecount = pdfToSvg.pageSize();
        
        if ( pagecount > 0 ) {
            
            FZZBytes* outdatalist = new FZZBytes[pagecount];
            if ( outdatalist == NULL ) {
                return isTF;
            }
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                outdatalist[i] = pdfToSvg.makePage(i);
                itemlen = outdatalist[i].getLen();
                if ( i == pagecount -1 ) {
                    outlen += FZZConst::fmt(itemlen);
                } else {
                    outlen += FZZConst::fmt(itemlen)+",";
                }
                totallen += itemlen;
            }
            //DLOG("----------------DLLMain::OFD2Image to image end---------------------");
            *intoutDatalen = totallen;
            *outData = (unsigned char *)malloc(totallen);
            *outDatalen = (char *)malloc(outlen.length()+1);
            if ( *outData == NULL || *outDatalen == NULL ) {
                if ( outdatalist != NULL ) {
                    delete [] outdatalist;
                    outdatalist = NULL;
                }
                if ( *outData != NULL ) {
                    FZZFreeHandle(*outData);
                    *outData = NULL;
                }
                if ( *outDatalen != NULL ) {
                    FZZFreeHandle(*outDatalen);
                    *outDatalen = NULL;
                }
                
                return isTF;
            }
            
            int pos = 0;
            for ( int x = 0; x < pagecount; x++ ) {
                itemlen = outdatalist[x].getLen();
                memcpy((*outData)+pos,outdatalist[x].getData(),itemlen);
                pos += itemlen;
            }
            //memcpy(*outData,outBytes.getData(),outBytes.getLen());
            if ( outdatalist != NULL ) {
                delete [] outdatalist;
                outdatalist = NULL;
            }
            
            memset(*outDatalen,0x00,outlen.length()+1);
            memcpy(*outDatalen,outlen.c_str(),outlen.length());
          
            isTF = true;
            
            
        }
    } else {
        FZZPDFToImage pdfToImage(pdf);
           
        if ( pdfToImage.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfToImage.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
            
        FZZBytes outBytes;
        string outlen = "";
        int pagecount = pdfToImage.pageSize();
        
        if ( pagecount > 0 ) {
            
            FZZBytes* outdatalist = new FZZBytes[pagecount];
            if ( outdatalist == NULL ) {
                return isTF;
            }
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                outdatalist[i] = pdfToImage.makePage(i,imageType,scale);
                itemlen = outdatalist[i].getLen();
                if ( i == pagecount -1 ) {
                    outlen += FZZConst::fmt(itemlen);
                } else {
                    outlen += FZZConst::fmt(itemlen)+",";
                }
                totallen += itemlen;
            }
            //DLOG("----------------DLLMain::OFD2Image to image end---------------------");
            *intoutDatalen = totallen;
            *outData = (unsigned char *)malloc(totallen);
            *outDatalen = (char *)malloc(outlen.length()+1);
            if ( *outData == NULL || *outDatalen == NULL ) {
                if ( outdatalist != NULL ) {
                    delete [] outdatalist;
                    outdatalist = NULL;
                }
                if ( *outData != NULL ) {
                    FZZFreeHandle(*outData);
                    *outData = NULL;
                }
                if ( *outDatalen != NULL ) {
                    FZZFreeHandle(*outDatalen);
                    *outDatalen = NULL;
                }
                
                return isTF;
            }
            
            int pos = 0;
            for ( int x = 0; x < pagecount; x++ ) {
                itemlen = outdatalist[x].getLen();
                memcpy((*outData)+pos,outdatalist[x].getData(),itemlen);
                pos += itemlen;
            }
            //memcpy(*outData,outBytes.getData(),outBytes.getLen());
            if ( outdatalist != NULL ) {
                delete [] outdatalist;
                outdatalist = NULL;
            }
            
            memset(*outDatalen,0x00,outlen.length()+1);
            memcpy(*outDatalen,outlen.c_str(),outlen.length());
          
            isTF = true;
            
            
        }
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI pdf_toImageZip(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return isTF;
    }
    
    string strImageType = imageType;
    transform(strImageType.begin(), strImageType.end(), strImageType.begin(), ::toupper);
    bool isSVG = strImageType == "SVG";
    if ( isSVG ) {
        FZZPDF2SVG pdfToSvg(pdf);
                   
        if ( pdfToSvg.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfToSvg.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
        
        FZZBytes outBytes;
        int pagecount = pdfToSvg.pageSize();
        
        if ( pagecount > 0 ) {
            vector<FZZBytes*> outdatalist;
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                FZZBytes* imageData = new FZZBytes(pdfToSvg.makePage(i));
                outdatalist.push_back(imageData);
                itemlen = imageData->getLen();
                totallen += itemlen+8;//0000.jpg len
            }
            //DLOG("----------------DLLMain::OFD2Image to image end---------------------");
            //DLOG("----------------DLLMain::OFD2Image zip begin---------------------");
            FZZZipTracks zipTracks;
#ifdef MINIZIPNG
            zipTracks.CreateZip_mem();
            for (int x = 0; x < pagecount; x++) {
                //itemlen = outdatalist[x]->getLen();
                zipTracks.AddFileToZip((FZZConst::fmt(x) + "." + imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }
            FZZBytes zipoutData = zipTracks.CloseZip_mem();
            *outData = (unsigned char*)malloc(zipoutData.getLen());
            if (*outData != NULL) {
                memcpy(*outData, zipoutData.getData(), zipoutData.getLen());

                *outDatalen = zipoutData.getLen();
                isTF = true;
            }

            vector<FZZBytes*>::const_iterator it;
            for (it = outdatalist.begin(); it != outdatalist.end(); it++) {
                if (*it != NULL) {
                    delete* it;
                }
            }
            outdatalist.clear();
#else

            unsigned long maxsize = zipTracks.getZipFileMaxSize(totallen);
            *outData = (unsigned char *)malloc(maxsize);
           
            if ( *outData == NULL  ) {
        //            if ( outdatalist != NULL ) {
        //                delete [] outdatalist;
        //                outdatalist = NULL;
        //            }
                vector<FZZBytes*>::const_iterator it;
                for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                    if ( *it != NULL ) {
                        delete *it;
                    }
                }
                outdatalist.clear();
                
                if ( *outData != NULL ) {
                    FreeHandle(*outData);
                    *outData = NULL;
                }
                return isTF;
            }
            
            memset(*outData, 0x00, maxsize);
            zipTracks.CreateZip_mem(*outData, maxsize);
            
            for ( int x = 0; x < pagecount; x++ ) {
                //itemlen = outdatalist[x]->getLen();
                zipTracks.AddFileToZip((FZZConst::fmt(x)+"."+imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }
            
            
            *outDatalen = zipTracks.CloseZip_mem();
            
        //        if ( outdatalist != NULL ) {
        //            delete [] outdatalist;
        //            outdatalist = NULL;
        //        }
            vector<FZZBytes*>::const_iterator it;
            for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                if ( *it != NULL ) {
                    delete *it;
                }
            }
            outdatalist.clear();
            
            isTF = true;
#endif
        }
    } else {
    
        FZZPDFToImage pdfToImage(pdf);
        
        if ( pdfToImage.isNeedPassWord() ) {
            string pw = pdf->getPassword();
            if ( pw.empty() ) {
                return ERR_PDF_NOT_SET_PW;
            }
            if ( !pdfToImage.VerifyPassWord(pw) ) {
                return ERR_PDF_VERIFY_PW;
            }
        }
        
        FZZBytes outBytes;
        int pagecount = pdfToImage.pageSize();
        
        if ( pagecount > 0 ) {
            vector<FZZBytes*> outdatalist;
            int totallen = 0;
            size_t itemlen = 0;
            for (int i = 0; i < pagecount; i++) {
                FZZBytes* imageData = new FZZBytes(pdfToImage.makePage(i,imageType,scale));
                outdatalist.push_back(imageData);
                itemlen = imageData->getLen();
                totallen += itemlen+8;//0000.jpg len
            }
            //DLOG("----------------DLLMain::OFD2Image to image end---------------------");
            //DLOG("----------------DLLMain::OFD2Image zip begin---------------------");
            FZZZipTracks zipTracks;
#ifdef MINIZIPNG
            zipTracks.CreateZip_mem();
            for (int x = 0; x < pagecount; x++) {
                //itemlen = outdatalist[x]->getLen();
                zipTracks.AddFileToZip((FZZConst::fmt(x) + "." + imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }
            FZZBytes zipoutData = zipTracks.CloseZip_mem();
            *outData = (unsigned char*)malloc(zipoutData.getLen());
            if (*outData != NULL) {
                memcpy(*outData, zipoutData.getData(), zipoutData.getLen());

                *outDatalen = zipoutData.getLen();
                isTF = true;
            }

            vector<FZZBytes*>::const_iterator it;
            for (it = outdatalist.begin(); it != outdatalist.end(); it++) {
                if (*it != NULL) {
                    delete* it;
                }
            }
            outdatalist.clear();
#else

            unsigned long maxsize = zipTracks.getZipFileMaxSize(totallen);
            *outData = (unsigned char *)malloc(maxsize);
           
            if ( *outData == NULL  ) {
        //            if ( outdatalist != NULL ) {
        //                delete [] outdatalist;
        //                outdatalist = NULL;
        //            }
                vector<FZZBytes*>::const_iterator it;
                for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                    if ( *it != NULL ) {
                        delete *it;
                    }
                }
                outdatalist.clear();
                
                if ( *outData != NULL ) {
                    FreeHandle(*outData);
                    *outData = NULL;
                }
                return isTF;
            }
            
            memset(*outData, 0x00, maxsize);
            zipTracks.CreateZip_mem(*outData, maxsize);
            
            for ( int x = 0; x < pagecount; x++ ) {
                //itemlen = outdatalist[x]->getLen();
                zipTracks.AddFileToZip((FZZConst::fmt(x)+"."+imageType).c_str(), outdatalist[x]->getData(), outdatalist[x]->getLen());
            }
            
            
            *outDatalen = zipTracks.CloseZip_mem();
            
        //        if ( outdatalist != NULL ) {
        //            delete [] outdatalist;
        //            outdatalist = NULL;
        //        }
            vector<FZZBytes*>::const_iterator it;
            for( it = outdatalist.begin(); it != outdatalist.end(); it++ ) {
                if ( *it != NULL ) {
                    delete *it;
                }
            }
            outdatalist.clear();
            
            isTF = true;
#endif
        }
    }
    //DLOG("----------------DLLMain::OFD2Image zip end---------------------");
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
DLL_API bool DEVAPI pdfToOfd(HANDLE handle,bool isNoStamp,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    bool isTF = false;
    *outDatalen = 0;
    
    FZZPDF * pdf = (FZZPDF *)handle;
    if ( pdf == NULL ) {
        return isTF;
    }

    FZZPDF2OFD pdf2ofd(pdf);
    
    if ( pdf2ofd.isNeedPassWord() ) {
        string pw = pdf->getPassword();
        if ( pw.empty() ) {
            return ERR_PDF_NOT_SET_PW;
        }
        if ( !pdf2ofd.VerifyPassWord(pw) ) {
            return ERR_PDF_VERIFY_PW;
        }
    }

    pdf2ofd.SetNoStamp(isNoStamp);
    
    int pagecount = pdf2ofd.getPDFPageCount();
    
    pdf2ofd.setGenFontFlag(true);
    for ( int i = 0; i < pagecount; i++  ) {
        pdf2ofd.makePage(i);
    }
    pdf2ofd.generateOFDFont();
    
    pdf2ofd.setGenFontFlag(false);
    for ( int i = 0; i < pagecount; i++  ) {
        pdf2ofd.makePage(i);
    }

    FZZBytes pdfdata = pdf2ofd.generateOFD();
    
    *outData = (unsigned char *)malloc(pdfdata.getLen());
    if ( *outData == NULL ) {
     
        return isTF;
    }
    memcpy(*outData,pdfdata.getData(),pdfdata.getLen());
    *outDatalen = pdfdata.getLen();
    isTF = true;
    
    //DLOG("PDF2OFD => font size : %d",FZZConst::g_TrueTypeFont.getFontCount());
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
