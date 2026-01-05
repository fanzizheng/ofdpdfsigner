//
//  Created by zizheng fan on 2022/11/07.
//
#include "basic/FZZConst.h"
#include "gm/ses/v1/FZZSES_SignInfo_V1.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSESeal_V1******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SignInfo_V1::FZZSES_SignInfo_V1()
{
    //DLOG("FZZSES_SignInfo_V1()");
    FZZConst::addClassCount("FZZSES_SignInfo_V1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SignInfo_V1::FZZSES_SignInfo_V1(const unsigned char * data,size_t datalen) :FZZSES_SignInfo_V1()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SignInfo_V1::FZZSES_SignInfo_V1(const FZZBytes & data) :FZZSES_SignInfo_V1()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SignInfo_V1::FZZSES_SignInfo_V1(const FZZSES_SignInfo_V1& obj):FZZSES_SignInfo_V1()
{
    //DLOG("FZZSES_SignInfo_V1(const FZZSES_SignInfo_V1& obj)");
    if ( this == &obj ) {
        return;
    }

    
    m_Cert = obj.m_Cert;
    m_signatureAlgID = obj.m_signatureAlgID;
    m_signedValue = obj.m_signedValue;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SignInfo_V1::~FZZSES_SignInfo_V1()
{
    //DLOG("~FZZSES_SignInfo_V1()")
    FZZConst::delClassCount("FZZSES_SignInfo_V1");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_SignInfo_V1::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,FZZCert,signatureAlgID,signedValue;
    
    
    
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
bool FZZSES_SignInfo_V1::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
//    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
//        return isTF;
//    }
    
    
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






