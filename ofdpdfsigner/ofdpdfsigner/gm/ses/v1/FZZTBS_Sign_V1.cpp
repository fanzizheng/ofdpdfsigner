//
//  Created by zizheng fan on 2022/11/07.
//
#include "basic/FZZConst.h"
#include "gm/ses/v1/FZZTBS_Sign_V1.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZTBS_Sign_V1******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V1::FZZTBS_Sign_V1():m_version(4),m_SESeal_V1(NULL),m_propertyInfo("")
{
    //DLOG("FZZTBS_Sign_V1()");
    FZZConst::addClassCount("FZZTBS_Sign_V1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V1::FZZTBS_Sign_V1(const unsigned char * data,size_t datalen) :FZZTBS_Sign_V1()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V1::FZZTBS_Sign_V1(const FZZTBS_Sign_V1& obj) :FZZTBS_Sign_V1()
{
    //DLOG("FZZTBS_Sign_V4(const FZZTBS_Sign_V4& obj)");
    if ( this == &obj ) {
        return;
    }
    m_version = obj.m_version;
    m_SESeal_V1 = obj.m_SESeal_V1 == NULL ? NULL : new FZZSESeal_V1(*obj.m_SESeal_V1);
    m_timeStamp = obj.m_timeStamp;
    m_dataHash = obj.m_dataHash;
    m_propertyInfo = obj.m_propertyInfo;
    m_Cert = obj.m_Cert;
    m_signatureAlgID = obj.m_signatureAlgID;
}
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V1::~FZZTBS_Sign_V1()
{
    //DLOG("~FZZTBS_Sign_V4()");
    FZZConst::delClassCount("FZZTBS_Sign_V1");
    if ( m_SESeal_V1 != NULL ) {
        delete m_SESeal_V1;
        m_SESeal_V1 = NULL;
        
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZTBS_Sign_V1::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,version,seseal,timeStamp,FZZCert,dataHash,propertyInfo,signatureAlgID;
    
    if ( m_SESeal_V1 == NULL ) {
        return ret;
    }
    
    temp = FZZConst::Uint32ToBytes(m_version);
    if ( !version.setMaxLen(temp.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = version.getData();
    if ( asn1_integer_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    version.setLen(bufferlen);
    
  
    
    if ( m_timeStamp.getLen() > 0 ) {
        if ( !timeStamp.setMaxLen(m_timeStamp.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = timeStamp.getData();
        if (asn1_bit_string_to_der(m_timeStamp.getData(), m_timeStamp.getLen()*8, &buffer,&bufferlen) != 1) {
            return ret;
        }
        timeStamp.setLen(bufferlen);
        
    }

    if ( !dataHash.setMaxLen(m_dataHash.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = dataHash.getData();
    if (asn1_bit_string_to_der(m_dataHash.getData(), m_dataHash.getLen()*8, &buffer,&bufferlen) != 1) {
        return ret;
    }
    dataHash.setLen(bufferlen);
    
    if ( !propertyInfo.setMaxLen(m_propertyInfo.length() + 20) ) {
        return ret;
    }
    buffer = propertyInfo.getData();
    bufferlen = 0;
    if ( asn1_ia5_string_to_der(m_propertyInfo.c_str(),m_propertyInfo.length(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    propertyInfo.setLen(bufferlen);
    
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
    
    
    retData.addData(version);
    retData.addData(m_SESeal_V1->Encode());
    retData.addData(timeStamp);
    retData.addData(dataHash);
    retData.addData(propertyInfo);
    retData.addData(FZZCert);
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
bool FZZTBS_Sign_V1::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
    if ((ret = asn1_integer_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_version = FZZConst::BytesToUint32(data, datalen);

    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    if ( m_SESeal_V1 != NULL ) {
        delete m_SESeal_V1;
        m_SESeal_V1 = NULL;
        
    }
    m_SESeal_V1 = new FZZSESeal_V1(data,datalen);
    //---------test begin --------
    //FZZBytes cc = m_SESeal_V4->Encode();
    //DLOG("m_SESeal_V4 %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    m_timeStamp.clear();
    if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_timeStamp.setData(data, datalen/8);
    
    m_dataHash.clear();
    datalen = 0;
    if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
//    if ( datalen >= 256 ) {
//        datalen = datalen / 8;
//    }
    m_dataHash.setData(data, datalen/8);
    
    if ((ret = asn1_ia5_string_from_der((const char **)(&data), &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    FZZBytes buffer;
    buffer.setMaxLen(datalen+1);
    buffer.setData_NotMalloc(data, datalen);
    m_propertyInfo = (char *)buffer.getData();
    
    m_Cert.clear();
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_Cert.setData(data, datalen);
    
    uint32_t nodes[32];
    size_t nodes_count = 0;
    //v4_1_4
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in, &inlen)) != 1) {
        return isTF;
    }
    m_signatureAlgID.setData((unsigned char *)nodes,nodes_count*4);
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------







