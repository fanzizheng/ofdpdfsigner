//
//  Created by zizheng fan on 2022/11/09.
//
#include "basic/FZZConst.h"
#include "gm/ses/v1/FZZSESeal_V1.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSESeal_V1******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V1::FZZSESeal_V1():m_SealInfo(NULL),m_SignInfo(NULL)
{
    //DLOG("FZZSESeal_V1()");
    FZZConst::addClassCount("FZZSESeal_V1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V1::FZZSESeal_V1(const unsigned char * data,size_t datalen) :FZZSESeal_V1()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V1::FZZSESeal_V1(const FZZBytes & data) :FZZSESeal_V1()
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
    //Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V1::FZZSESeal_V1(const FZZSESeal_V1& obj):FZZSESeal_V1()
{
    //DLOG("FZZSESeal_V1(const FZZSESeal_V1& obj)");
    if ( this == &obj ) {
        return;
    }

    m_SealInfo = obj.m_SealInfo == NULL ? NULL : new FZZSES_SealInfo_V1(*obj.m_SealInfo);
    m_SignInfo = obj.m_SignInfo == NULL ? NULL : new FZZSES_SignInfo_V1(*obj.m_SignInfo);
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESeal_V1::~FZZSESeal_V1()
{
    //DLOG("~FZZSESeal_V1()");
    FZZConst::delClassCount("FZZSESeal_V1");
    if ( m_SealInfo != NULL ) {
        delete m_SealInfo;
        m_SealInfo = NULL;
    }
    if ( m_SignInfo != NULL ) {
        delete m_SignInfo;
        m_SignInfo = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSESeal_V1::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,sealinfo,FZZCert,signatureAlgID,signedValue;
    
    if ( m_SealInfo == NULL || m_SignInfo == NULL ) {
        return ret;
    }
    
    retData.addData(m_SealInfo->Encode());
    retData.addData(m_SignInfo->Encode());
    
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
bool FZZSESeal_V1::Deccode(const unsigned char * indata,size_t inlenght)
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
    m_SealInfo = new FZZSES_SealInfo_V1(data,datalen);
    
    //---------test begin --------
//    FZZBytes cc = m_SealInfo->Encode();
//    DLOG("m_SealInfo %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    if ( m_SignInfo != NULL ) {
        delete m_SignInfo;
        m_SignInfo = NULL;
        
    }
    m_SignInfo = new FZZSES_SignInfo_V1(data,datalen);
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSESeal_V1::GenSignSource(FZZBytes &sealinfo,FZZBytes& certdata,FZZBytes alg)
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes signatureAlgID,cert;
    
    if ( !cert.setMaxLen(certdata.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = cert.getData();
    if ( asn1_octet_string_to_der(certdata.getData(),certdata.getLen(),&buffer,&bufferlen) != 1) {
        return ret;
    }
    cert.setLen(bufferlen);
    
    
    if ( !signatureAlgID.setMaxLen(alg.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = signatureAlgID.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)alg.getData(), alg.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    signatureAlgID.setLen(bufferlen);
    
    retData.addData(sealinfo);
    retData.addData(cert);
    retData.addData(signatureAlgID);
    
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
bool FZZSESeal_V1::Verify()
{
    FZZSES_SignInfo_V1 * signInfo = m_SignInfo;
    FZZBytes sealcert = signInfo->getCert();
    FZZCert cert;
    if ( !cert.loadCert(sealcert) ) {
        //DLOG("---------------- loadCert err---------------------");
        return false;
    }

    FZZBytes signdata = signInfo->getSignedValue();
    FZZBytes algdata = signInfo->getSignAlgID();
    
    FZZSES_SealInfo_V1* sealinfo = m_SealInfo;
    
    FZZBytes sealinfodatat = sealinfo->Encode();
    FZZBytes sourcedata = GenSignSource(sealinfodatat,sealcert,algdata);
    
    //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/sealsourcev1.dat",sourcedata.getData(),sourcedata.getLen());

    FZZGMCrypto gmCrypto;
    FZZKey pubkey = *cert.getPublicKey();
    bool tf = gmCrypto.verifySign(pubkey,sourcedata,signdata);
    
    return tf;
}
//-----------------------------------------------------------------------------------------------------------------





