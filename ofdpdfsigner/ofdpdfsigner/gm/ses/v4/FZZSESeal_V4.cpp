//
//  Created by zizheng fan on 2022/11/15.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZSESeal_V4.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
#include "gm/crypto/FZZGMCrypto.h"

#include "gm/crypto/FZZCert.h"
#include "interface/FZZErrorCode.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCreateSESeal_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCreateSESeal_V4::CreateSeal(FZZBytes & cert_sealUser,FZZBytes & cert_seal,FZZKey & PriKey_cert_seal,
                                  string sealname,time_t createDate,time_t startDate,int addDay,
                                  string imageType,FZZBytes &imageData,int imageWidth,int imageHeight,
                                  string sealID)
{
    //-------------------------------
    
    FZZCertInfoList certinfolist;
    certinfolist.add(cert_sealUser);
    
    FZZSES_CertList sealUserCertList(&certinfolist);
    
    
    FZZSES_ESPropertyInfo_V4 propertyInfo;
    //fzz note 2024-04-10
    //type 修改
    propertyInfo.setType(3);
    propertyInfo.setName(sealname);
    propertyInfo.setCertListType(FZZSES_ESPropertyInfo_V4::CertListType);
 
    propertyInfo.setCreateDate(createDate);
    propertyInfo.setValidStart(startDate);
    time_t endDate;
    x509_validity_add_days(&endDate,startDate,addDay);
    
    
    
    propertyInfo.setValidEnd(endDate);
    propertyInfo.setCertList(&sealUserCertList);
    //----------------------------
    FZZSES_ESPictrueInfo_V4 pictrueInfo;
    pictrueInfo.setType(imageType);
    pictrueInfo.setData(imageData);
    pictrueInfo.setWidth(imageWidth);
    pictrueInfo.setHeight(imageHeight);
    //----------------------------
    FZZSES_Header sesHeader;
    FZZSES_SealInfo_V4 sesSealInfo_V4;
    sesSealInfo_V4.setHeader(&sesHeader);
    sesSealInfo_V4.setEsID(sealID);
    sesSealInfo_V4.setPropertInfo(&propertyInfo);
    sesSealInfo_V4.setPicture(&pictrueInfo);
    
    //----------------------------
    FZZBytes signsrcdata = sesSealInfo_V4.Encode();
    
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsource.dat",signsrcdata.getData(),signsrcdata.getLen());
    
    FZZGMCrypto gmCrypto;
    FZZBytes sign = gmCrypto.sign(PriKey_cert_seal,signsrcdata);
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsign.dat",sign.getData(),sign.getLen());
    //----------------------------
    
    FZZSESeal_V4 seal;
    seal.setSealInfo(&sesSealInfo_V4);
    seal.setCert(cert_seal);
    
    uint32_t oid_sm2sign_with_sm3[] = { 1,2,156,10197,1,501 };
    FZZBytes signalgdata((unsigned char *)oid_sm2sign_with_sm3, sizeof(oid_sm2sign_with_sm3));
    seal.setSignAlgID(signalgdata);
    seal.setSignedValue(sign);

    FZZBytes sealData = seal.Encode();
    
    return sealData;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCreateSESeal_V4::CreateSeal(CallBack_getUserCert getCertFunc,CallBack_getSealCert getSealCertFunc,CallBack_Sign signFunc,
                                  const void * callBack_Param,
                 string sealname,time_t createDate,time_t startDate,int addDay,
                 string imageType,FZZBytes &imageData,int imageWidth,int imageHeight,
                 string sealID)
{
    //-------------------------------
    FZZBytes sealData;
    if ( signFunc == NULL || getCertFunc == NULL || getSealCertFunc == NULL ) {
        return sealData;
    }
    //fzz edit begin 2024.06.07
//    FZZBytes cert_sealUser = getCertFunc(callBack_Param);
//    if ( cert_sealUser.getLen() <= 0 ) {
//        return sealData;
//    }
//    FZZBytes cert_seal = getSealCertFunc(callBack_Param);
//    if ( cert_seal.getLen() <= 0 ) {
//        return sealData;
//    }
    size_t bufferLen = 0;
    unsigned char * buffer = NULL;
    getCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return sealData;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return sealData;
    }
    getCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return sealData;
    }
    FZZBytes cert_sealUser;
    cert_sealUser.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    
    getSealCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return sealData;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return sealData;
    }
    getSealCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return sealData;
    }
    FZZBytes cert_seal;
    cert_seal.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    
    //fzz edit end 2024.06.07
    //DLOG("user cert:%s",FZZConst::HexEncode(cert_sealUser.getData(), cert_sealUser.getLen()).c_str());
    //DLOG("seal cert:%s",FZZConst::HexEncode(cert_seal.getData(), cert_seal.getLen()).c_str());
    FZZCertInfoList certinfolist;
    certinfolist.add(cert_sealUser);
    
    FZZSES_CertList sealUserCertList(&certinfolist);
    
    
    FZZSES_ESPropertyInfo_V4 propertyInfo;
    propertyInfo.setType(3);
    propertyInfo.setName(sealname);
    propertyInfo.setCertListType(FZZSES_ESPropertyInfo_V4::CertListType);
 
    //startDate = createDate;
    
    propertyInfo.setCreateDate(createDate);
    propertyInfo.setValidStart(startDate);
    
    
    time_t endDate;
    x509_validity_add_days(&endDate,startDate,addDay);
    //DLOG("%ld,%ld,%ld",createDate,startDate,endDate);
    propertyInfo.setValidEnd(endDate);
    propertyInfo.setCertList(&sealUserCertList);
    //----------------------------
    FZZSES_ESPictrueInfo_V4 pictrueInfo;
    pictrueInfo.setType(imageType);
    pictrueInfo.setData(imageData);
    pictrueInfo.setWidth(imageWidth);
    pictrueInfo.setHeight(imageHeight);
    //----------------------------
    FZZSES_Header sesHeader;
    FZZSES_SealInfo_V4 sesSealInfo_V4;
    sesSealInfo_V4.setHeader(&sesHeader);
    sesSealInfo_V4.setEsID(sealID);
    sesSealInfo_V4.setPropertInfo(&propertyInfo);
    sesSealInfo_V4.setPicture(&pictrueInfo);
    
    //----------------------------
    FZZBytes signsrcdata = sesSealInfo_V4.Encode();
    
    if ( signsrcdata.getLen() <= 0 ) {
        return sealData;
    }
    
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsource.dat",signsrcdata.getData(),signsrcdata.getLen());
    
    //FZZGMCrypto gmCrypto;
    //FZZBytes sign = gmCrypto.sign(PriKey_cert_seal,signsrcdata);
    //fzz edit begin 2024.06.07
//    FZZBytes sign = signFunc(callBack_Param,signsrcdata);
//    if ( sign.getLen() <= 0 ) {
//        return sealData;
//    }
    bufferLen = MAXBUFLEN_SIGN;
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return sealData;
    }
    signFunc(callBack_Param,signsrcdata.getData(),(int)signsrcdata.getLen(),&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return sealData;
    }
    FZZBytes sign;
    sign.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    //fzz edit end 2024.06.07
    //DLOG("sign:%s",FZZConst::HexEncode(sign.getData(), sign.getLen()).c_str());
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsign.dat",sign.getData(),sign.getLen());
    //----------------------------
    
    FZZSESeal_V4 seal;
    seal.setSealInfo(&sesSealInfo_V4);
    seal.setCert(cert_seal);
    
    uint32_t oid_sm2sign_with_sm3[] = { 1,2,156,10197,1,501 };
    FZZBytes signalgdata((unsigned char *)oid_sm2sign_with_sm3, sizeof(oid_sm2sign_with_sm3));
    seal.setSignAlgID(signalgdata);
    seal.setSignedValue(sign);

    sealData = seal.Encode();
    
    //DLOG("seal:%s",FZZConst::HexEncode(sealData.getData(), sealData.getLen()).c_str());
    
    return sealData;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCreateSESeal_V4::CreateSeal(CallBack_getUserCert getCertFunc,CallBack_getSealCert getSealCertFunc,CallBack_Sign signFunc,
                 const void * callBack_Param,
                                  int type,string sealname,time_t createDate,time_t startDate,time_t endDate,
                 string imageType,FZZBytes &imageData,int imageWidth,int imageHeight,
                 string sealID)
{
    //-------------------------------
    FZZBytes sealData;
    if ( signFunc == NULL || getCertFunc == NULL || getSealCertFunc == NULL ) {
        return sealData;
    }
    //fzz edit begin 2024.06.07
//    FZZBytes cert_sealUser = getCertFunc(callBack_Param);
//    if ( cert_sealUser.getLen() <= 0 ) {
//        return sealData;
//    }
//    FZZBytes cert_seal = getSealCertFunc(callBack_Param);
//    if ( cert_seal.getLen() <= 0 ) {
//        return sealData;
//    }
    size_t bufferLen = 0;
    unsigned char * buffer = NULL;
    getCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return sealData;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return sealData;
    }
    getCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return sealData;
    }
    FZZBytes cert_sealUser;
    cert_sealUser.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    
    getSealCertFunc(callBack_Param,&buffer,&bufferLen);
    if ( bufferLen <= 0 ) {
        return sealData;
    }
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return sealData;
    }
    getSealCertFunc(callBack_Param,&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return sealData;
    }
    FZZBytes cert_seal;
    cert_seal.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    bufferLen = 0;
    //fzz edit end 2024.06.07
    
    //DLOG("user cert:%s",FZZConst::HexEncode(cert_sealUser.getData(), cert_sealUser.getLen()).c_str());
    //DLOG("seal cert:%s",FZZConst::HexEncode(cert_seal.getData(), cert_seal.getLen()).c_str());
    FZZCertInfoList certinfolist;
    certinfolist.add(cert_sealUser);
    
    FZZSES_CertList sealUserCertList(&certinfolist);
    
    
    FZZSES_ESPropertyInfo_V4 propertyInfo;
    propertyInfo.setType(type);
    propertyInfo.setName(sealname);
    propertyInfo.setCertListType(FZZSES_ESPropertyInfo_V4::CertListType);
 
    //startDate = createDate;
    
    propertyInfo.setCreateDate(createDate);
    propertyInfo.setValidStart(startDate);
    
    
    //time_t endDate;
    //x509_validity_add_days(&endDate,startDate,addDay);
    //DLOG("%ld,%ld,%ld",createDate,startDate,endDate);
    propertyInfo.setValidEnd(endDate);
    propertyInfo.setCertList(&sealUserCertList);
    //----------------------------
    FZZSES_ESPictrueInfo_V4 pictrueInfo;
    pictrueInfo.setType(imageType);
    pictrueInfo.setData(imageData);
    pictrueInfo.setWidth(imageWidth);
    pictrueInfo.setHeight(imageHeight);
    //----------------------------
    FZZSES_Header sesHeader;
    FZZSES_SealInfo_V4 sesSealInfo_V4;
    sesSealInfo_V4.setHeader(&sesHeader);
    sesSealInfo_V4.setEsID(sealID);
    sesSealInfo_V4.setPropertInfo(&propertyInfo);
    sesSealInfo_V4.setPicture(&pictrueInfo);
    
    //----------------------------
    FZZBytes signsrcdata = sesSealInfo_V4.Encode();
    
    if ( signsrcdata.getLen() <= 0 ) {
        return sealData;
    }
    
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsource.dat",signsrcdata.getData(),signsrcdata.getLen());
    
    //FZZGMCrypto gmCrypto;
    //FZZBytes sign = gmCrypto.sign(PriKey_cert_seal,signsrcdata);
    //fzz edit begin 2024.06.07
//    FZZBytes sign = signFunc(callBack_Param,signsrcdata);
//    if ( sign.getLen() <= 0 ) {
//        return sealData;
//    }
    bufferLen = MAXBUFLEN_SIGN;
    buffer = (unsigned char *)malloc(bufferLen);
    if ( buffer == NULL ) {
        return sealData;
    }
    signFunc(callBack_Param,signsrcdata.getData(),(int)signsrcdata.getLen(),&buffer,&bufferLen);
    if (bufferLen <= 0) {
        free(buffer);
        buffer = NULL;
        return sealData;
    }
    FZZBytes sign;
    sign.setData(buffer, bufferLen);
    free(buffer);
    buffer = NULL;
    //fzz edit end 2024.06.07
    //DLOG("sign:%s",FZZConst::HexEncode(sign.getData(), sign.getLen()).c_str());
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsign.dat",sign.getData(),sign.getLen());
    //----------------------------
    
    FZZSESeal_V4 seal;
    seal.setSealInfo(&sesSealInfo_V4);
    seal.setCert(cert_seal);
    
    uint32_t oid_sm2sign_with_sm3[] = { 1,2,156,10197,1,501 };
    FZZBytes signalgdata((unsigned char *)oid_sm2sign_with_sm3, sizeof(oid_sm2sign_with_sm3));
    seal.setSignAlgID(signalgdata);
    seal.setSignedValue(sign);

    sealData = seal.Encode();
    
    //DLOG("seal:%s",FZZConst::HexEncode(sealData.getData(), sealData.getLen()).c_str());
    
    return sealData;
}
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSESeal_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V4::FZZSESeal_V4():m_SealInfo(NULL)
{
    //DLOG("FZZSESeal_V4()");
    FZZConst::addClassCount("FZZSESeal_V4");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V4::FZZSESeal_V4(const unsigned char * data,size_t datalen) :FZZSESeal_V4()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V4::FZZSESeal_V4(const FZZBytes & data) :FZZSESeal_V4()
{
    
    const uint8_t * in = data.getData();
    size_t inlen = data.getLen();
    const uint8_t * outdata = NULL;
    size_t outdatalen = 0;
    
    int ret = 0;
    
    if ((ret = asn1_sequence_from_der(&outdata, &outdatalen, &in, &inlen)) != 1) {
        return ;
    }
    
    Deccode(outdata,outdatalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V4::FZZSESeal_V4(const FZZSESeal_V4& obj):FZZSESeal_V4()
{
    //DLOG("FZZSESeal_V4(const FZZSESeal_V4& obj)");
    if ( this == &obj ) {
        return;
    }

    m_SealInfo = obj.m_SealInfo == NULL ? NULL : new FZZSES_SealInfo_V4(*obj.m_SealInfo);
    m_Cert = obj.m_Cert;
    m_signatureAlgID = obj.m_signatureAlgID;
    m_signedValue = obj.m_signedValue;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V4::~FZZSESeal_V4()
{
    //DLOG("~FZZSESeal_V4()");
    FZZConst::delClassCount("FZZSESeal_V4");
    if ( m_SealInfo != NULL ) {
        delete m_SealInfo;
        m_SealInfo = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSESeal_V4::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,sealinfo,FZZCert,signatureAlgID,signedValue;
    
    if ( m_SealInfo == NULL ) {
        return ret;
    }
    
//    temp = m_SealInfo->Encode();
//    if ( !sealinfo.setMaxLen(temp.getLen() + 20) ) {
//        return ret;
//    }
//    bufferlen = 0;
//    buffer = sealinfo.getData();
//    if ( asn1_sequence_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
//        return ret;
//    }
//    sealinfo.setLen(bufferlen);
    
    
    if ( !FZZCert.setMaxLen(m_Cert.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = FZZCert.getData();
    if ( asn1_octet_string_to_der(m_Cert.getData(),m_Cert.getLen(),&buffer,&bufferlen) != 1) {
        return ret;
    }
    FZZCert.setLen(bufferlen);
    
    if ( !signatureAlgID.setMaxLen(m_signatureAlgID.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = signatureAlgID.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)m_signatureAlgID.getData(), m_signatureAlgID.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    signatureAlgID.setLen(bufferlen);
    
    
    if ( !signedValue.setMaxLen(m_signedValue.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = signedValue.getData();
    if (asn1_bit_string_to_der(m_signedValue.getData(), m_signedValue.getLen()*8, &buffer,&bufferlen) != 1) {
        return ret;
    }
    signedValue.setLen(bufferlen);
    
    retData.addData(m_SealInfo->Encode());
    retData.addData(FZZCert);
    retData.addData(signatureAlgID);
    retData.addData(signedValue);
    
    if ( !ret.setMaxLen(retData.getLen() + 20) ) {
        ret.clear();
        return ret;
    }
    bufferlen = 0;
    buffer = ret.getData();
    if ( asn1_sequence_to_der(retData.getData(),retData.getLen(),&buffer,&bufferlen) != 1 ) {
        ret.clear();
        return ret;
    }
    ret.setLen(bufferlen);
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZSESeal_V4::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    if ( m_SealInfo != NULL ) {
        delete m_SealInfo;
        m_SealInfo = NULL;
        
    }
    m_SealInfo = new FZZSES_SealInfo_V4(data,datalen);
    
    //---------test begin --------
//    FZZBytes cc = m_SealInfo->Encode();
//    DLOG("m_SealInfo %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    
    m_Cert.clear();
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_Cert.setData(data, datalen);
    
    m_signatureAlgID.clear();
    uint32_t nodes[32];
    size_t nodes_count = 0;
    //v4_1_4
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in, &inlen)) != 1) {
        return isTF;
    }
    m_signatureAlgID.setData((unsigned char *)nodes,nodes_count*4);
    
    
    m_signedValue.clear();
    if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_signedValue.setData(data, datalen/8);
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZSESeal_V4::Verify()
{
    FZZSES_SealInfo_V4* sesSealInfo = m_SealInfo;
    FZZBytes sealcert = m_Cert;
    FZZCert cert;
    if ( !cert.loadCert(sealcert) ) {
        //DLOG("---------------- loadCert err---------------------");
        return false;
    }

    FZZBytes signdata = m_signedValue;

    FZZBytes sourcedata = sesSealInfo->Encode();

    FZZGMCrypto gmCrypto;
    FZZKey pubkey = *cert.getPublicKey();
    bool tf = gmCrypto.verifySign(pubkey,sourcedata,signdata);
    return tf;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZSESeal_V4::Verify(CallBack_Verify verifyFunc,const void * callBack_Param)
{
    FZZSES_SealInfo_V4* sesSealInfo = m_SealInfo;
    if ( m_SealInfo == NULL ) {
        return ERR_VERIFY;
    }
    FZZBytes sealcert = m_Cert;
    FZZCert cert;
    if ( !cert.loadCert(sealcert) ) {
        //DLOG("---------------- loadCert err---------------------");
        return ERR_CERT_LOAD;
    }

    FZZBytes signdata = m_signedValue;

    FZZBytes sourcedata = sesSealInfo->Encode();

//    FZZGMCrypto gmCrypto;
    FZZKey pubkey = *cert.getPublicKey();
//    bool tf = gmCrypto.verifySign(pubkey,sourcedata,signdata);
    FZZBytes keyData;
    keyData.setData(pubkey.getKeyData(), pubkey.getKeyDataLen());
    //fzz edit begin 2024.06.07
    //bool tf = verifyFunc(callBack_Param,0,keyData,sourcedata,signdata);
    bool tf = verifyFunc(callBack_Param,0,keyData.getData(),(int)keyData.getLen(),sourcedata.getData(),(int)sourcedata.getLen(),signdata.getData(),(int)signdata.getLen());
    //fzz edit end 2024.06.07
    bool btime = false;
    FZZSES_ESPropertyInfo_V4* propertInfo = sesSealInfo->getPropertInfo();
    if ( propertInfo != NULL ) {
        time_t currtime;
        time(&currtime);
        
        time_t starttime = propertInfo->getValidStart();
        time_t endtime = propertInfo->getValidEnd();
        if ( starttime <= currtime && currtime < endtime ) {
            
            btime = true;
        }
        //DLOG("%ld,%ld,%ld",starttime,endtime,currtime);
    }
    //DLOG("%s",tf?"true":"false");
    return tf ? (btime ? 0 : ERR_NOT_VALIDITY) : ERR_VERIFY;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSESeal_V4::getUserCert()
{
    FZZBytes ret;
    FZZSES_SealInfo_V4* sesSealInfo = m_SealInfo;
    if ( m_SealInfo != NULL ) {
        FZZSES_ESPropertyInfo_V4* propertInfo = sesSealInfo->getPropertInfo();
        if ( propertInfo != NULL ) {
            FZZSES_CertList* sesCertList = propertInfo->getCertList();
            if ( sesCertList != NULL ) {
                FZZCertInfoList * certInfoList = sesCertList->getCerts();
                if ( certInfoList != NULL ) {
                    if ( certInfoList->size() > 0 ) {
                        FZZBytes* certData = certInfoList->get(0);
                        if ( certData != NULL && certData->getLen() > 0 ) {
                            ret.setData(certData->getData(), certData->getLen());
                        }
                    }
                }
            }
        }//if ( propertInfo != NULL ) {
    } //if ( m_SealInfo != NULL ) {
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
