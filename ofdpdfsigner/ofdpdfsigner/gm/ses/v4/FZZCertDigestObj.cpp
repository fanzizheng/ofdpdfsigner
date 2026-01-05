//
//  Created by zizheng fan on 2022/11/11.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZCertDigestObj.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCertDigestObj******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestObj::FZZCertDigestObj() : m_type("")
{
    //DLOG("FZZCertDigestObj()");
    FZZConst::addClassCount("FZZCertDigestObj");
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestObj::FZZCertDigestObj(const unsigned char * data,size_t datalen):FZZCertDigestObj()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestObj::FZZCertDigestObj(const FZZBytes & data):FZZCertDigestObj()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestObj::FZZCertDigestObj(const FZZCertDigestObj& obj):FZZCertDigestObj()
{
    //DLOG("FZZCertDigestObj(const FZZCertDigestObj& obj)");
    if ( this == &obj ) {
        return;
    }
    m_type = obj.m_type;
    m_value = obj.m_value;
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestObj::~FZZCertDigestObj()
{
    //DLOG("~FZZCertDigestObj()");
    FZZConst::delClassCount("FZZCertDigestObj");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCertDigestObj::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    FZZBytes type,value;
    
    if ( !type.setMaxLen(m_type.length() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = type.getData();
    if (asn1_printable_string_to_der(m_type.c_str(),m_type.length(), &buffer,&bufferlen) != 1) {
        return ret;
    }
    type.setLen(bufferlen);
    
    if ( !value.setMaxLen(m_value.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = value.getData();
    if ( asn1_octet_string_to_der(m_value.getData(),m_value.getLen(),&buffer,&bufferlen) != 1) {
        return ret;
    }
    value.setLen(bufferlen);
    
    retData.addData(type);
    retData.addData(value);
    
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
bool FZZCertDigestObj::Deccode(const unsigned char * indata,size_t inlenght)
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
    

    if ((ret = asn1_printable_string_from_der((const char **)&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }

    FZZBytes buffer;
    buffer.setMaxLen(datalen+1);
    buffer.setData_NotMalloc(data, datalen);
    m_type = (char *)buffer.getData();
    
    
    m_value.clear();
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_value.setData(data, datalen);
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






