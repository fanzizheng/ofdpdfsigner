//
//  Created by zizheng fan on 2022/11/10.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZExtData.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"

#define ASN1_TRUE 0xff
#define ASN1_FALSE 0x00
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZExtData******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZExtData::FZZExtData() : m_critical(ASN1_FALSE)
{
    //DLOG("FZZExtData()");
    FZZConst::addClassCount("FZZExtData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZExtData::FZZExtData(const unsigned char * data,size_t datalen):FZZExtData()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZExtData::FZZExtData(const FZZBytes & data):FZZExtData()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZExtData::FZZExtData(const FZZExtData& obj):FZZExtData()
{
    //DLOG("FZZExtData(const FZZExtData& obj)");
    if ( this == &obj ) {
        return;
    }
    m_extnID = obj.m_extnID;
    m_critical = obj.m_critical;
    m_extnValue = obj.m_extnValue;
}
//-----------------------------------------------------------------------------------------------------------------
FZZExtData ::~FZZExtData()
{
    //DLOG("~FZZExtData()");
    FZZConst::delClassCount("FZZExtData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZExtData::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    FZZBytes temp,extnid,critical,extnValue;
    
    if ( !extnid.setMaxLen(m_extnID.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = extnid.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)m_extnID.getData(), m_extnID.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    extnid.setLen(bufferlen);
    
    if ( !critical.setMaxLen(4 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = critical.getData();
    if (asn1_boolean_to_der(m_critical, &buffer,&bufferlen) != 1) {
        return ret;
    }
    critical.setLen(bufferlen);
    
    
    if ( !extnValue.setMaxLen(m_extnValue.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = extnValue.getData();
    if ( asn1_octet_string_to_der(m_extnValue.getData(),m_extnValue.getLen(),&buffer,&bufferlen) != 1) {
        return ret;
    }
    extnValue.setLen(bufferlen);
    
    retData.addData(extnid);
    retData.addData(critical);
    retData.addData(extnValue);
    
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
bool FZZExtData::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
    uint32_t nodes[32];
    size_t nodes_count = 0;
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in, &inlen)) != 1) {
        return isTF;
    }
    m_extnID.setData((unsigned char *)nodes,nodes_count*4);
    
    
    if ((ret = asn1_boolean_from_der(&m_critical, &in, &inlen)) != 1) {
        return isTF;
    }
    
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_extnValue.setData(data,datalen);
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






