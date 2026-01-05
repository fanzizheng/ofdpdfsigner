//
//  Created by zizheng fan on 2023/01/11.
//
#include "basic/FZZConst.h"
#include "ofd/sign/signcontainer/FZZSESV4Container.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gm/ses/v4/FZZTBS_Sign_V4.h"
#include "gm/ses/parse/FZZSESVersion.h"
#include "gm/ses/v4/FZZSES_Signature_V4.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSESV4Container*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSESV4Container::FZZSESV4Container() : FZZExtendSignatureContainer(), m_PrivateKey(NULL),m_SignCert(NULL),m_Seal(NULL),m_isCallBack(false),m_signFunc(NULL),m_callBack_Param(NULL),m_getCertFunc(NULL)
{
    //DLOG("FZZSESV4Container()");
    FZZConst::addClassCount("FZZSESV4Container");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESV4Container::FZZSESV4Container(FZZKey * privateKey, FZZCert * signCert, FZZSESeal_V4* seal) : FZZSESV4Container()
{
    m_PrivateKey = privateKey;
    m_SignCert = signCert;
    m_Seal = seal;
    m_isCallBack = false;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESV4Container::FZZSESV4Container(FZZSESeal_V4* seal,CallBack_Sign signFunc,CallBack_getUserCert getCertFunc,const void * callBack_Param) : FZZSESV4Container()
{
    m_Seal = seal;
    m_isCallBack = true;
    m_signFunc = signFunc;
    m_callBack_Param = callBack_Param;
    m_getCertFunc = getCertFunc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESV4Container::~FZZSESV4Container()
{
    //DLOG("~FZZSESV4Container()");
    FZZConst::delClassCount("FZZSESV4Container");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSESV4Container::sign(FZZBytes & inData, string propertyInfo,FZZBytes & outSignData)
{
    if ( m_Seal == NULL) {
        return;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    gmCrypto.Digest("SM3", inData, hashData);
    if ( hashData.getLen() < 8 ) {
        return;
    }
    
    FZZTBS_Sign_V4 toSign;
    toSign.setVersion(FZZSESVersion::TYPE::v4);
    toSign.setEseal(m_Seal);
    time_t currtime;
    time(&currtime);
    toSign.setTimeInfo(currtime);
    toSign.setDataHash(hashData);
    toSign.setPropertyInfo(propertyInfo);
    
    FZZBytes signsrcdata = toSign.Encode();
    FZZBytes signdata;
    if ( m_isCallBack ) {
        if ( m_signFunc == NULL ) {
            return;
        }
        //fzz edit begin 2024.06.07
//        signdata = m_signFunc(m_callBack_Param,signsrcdata);
//        if ( signdata.getLen() <= 0 ) {
//            return;
//        }
        size_t bufferLen = MAXBUFLEN_SIGN;
        unsigned char * buffer = (unsigned char *)malloc(bufferLen);
        if ( buffer == NULL ) {
            return ;
        }
        m_signFunc(m_callBack_Param,signsrcdata.getData(),(int)signsrcdata.getLen(),&buffer,&bufferLen);
        if (bufferLen <= 0) {
            free(buffer);
            buffer = NULL;
            return ;
        }
        
        signdata.setData(buffer, bufferLen);
        free(buffer);
        buffer = NULL;
        //fzz edit end 2024.06.07
    } else {
        if ( m_PrivateKey == NULL ) {
            return;
        }
        signdata = gmCrypto.sign(*m_PrivateKey, signsrcdata);
    }
    
    FZZSES_Signature_V4 sesSignature;
    sesSignature.setToSign(&toSign);
    if ( m_isCallBack ) {
        if ( m_getCertFunc == NULL ) {
            return;
        }
        //fzz edit begin 2024.06.07
//        FZZBytes bCert = m_getCertFunc(m_callBack_Param);
//        if ( bCert.getLen() <= 0 ) {
//            return;
//        }
        size_t bufferLen = 0;
        unsigned char * buffer = NULL;
        m_getCertFunc(m_callBack_Param,&buffer,&bufferLen);
        if ( bufferLen <= 0 ) {
            return ;
        }
        buffer = (unsigned char *)malloc(bufferLen);
        if ( buffer == NULL ) {
            return ;
        }
        m_getCertFunc(m_callBack_Param,&buffer,&bufferLen);
        if (bufferLen <= 0) {
            free(buffer);
            buffer = NULL;
            return ;
        }
        FZZBytes bCert;
        bCert.setData(buffer, bufferLen);
        free(buffer);
        buffer = NULL;
        bufferLen = 0;
        //fzz edit end 2024.06.07
        sesSignature.setCert(bCert);
    } else {
        if ( m_SignCert == NULL ) {
            return;
        }
        sesSignature.setCert(m_SignCert->getCertData());
    }
    uint32_t oid_sm2sign_with_sm3[] = { 1,2,156,10197,1,501 };
    FZZBytes signalgdata((unsigned char *)oid_sm2sign_with_sm3, sizeof(oid_sm2sign_with_sm3));
    
    sesSignature.setSignatureAlgID(signalgdata);
    sesSignature.setSignature(signdata);
    
//    if (timeStampHook != null) {
//        byte[] timeStamp = timeStampHook.apply(sigVal);
//        if (timeStamp != null) {
//            signature.setTimeStamp(new DERBitString(timeStamp));
//        }
//    }
    
    
    FZZBytes esesigndata = sesSignature.Encode();
    if ( esesigndata.getLen() < 10 ) {
        return;
    }
    outSignData.setData(esesigndata.getData(), esesigndata.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigType::TYPE FZZSESV4Container::getOFDSignType()
{
    return FZZOFDSigType::TYPE::TYPE_Seal;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZSESV4Container::getSignAlgOID()
{
    return "1.2.156.10197.1.501";
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSESV4Container::getSeal()
{
    return m_Seal->Encode();
}
//-----------------------------------------------------------------------------------------------------------------

