//
//  Created by zizheng fan on 2022/11/13.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZSES_ESPropertyInfo_V4.h"
#include "gmssl/asn1.h"


const uint32_t FZZSES_ESPropertyInfo_V4::CertListType = 1;
const uint32_t FZZSES_ESPropertyInfo_V4::CertDigestListType = 2;
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_ESPropertyInfo_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V4::FZZSES_ESPropertyInfo_V4() : m_type(0),m_certListType(0),m_SES_CertList(NULL),m_createDate(0),m_validStart(0),m_validEnd(0)
{
    //DLOG("FZZSES_ESPropertyInfo_V4()");
    FZZConst::addClassCount("FZZSES_ESPropertyInfo_V4");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V4::FZZSES_ESPropertyInfo_V4(const unsigned char * data,size_t datalen):FZZSES_ESPropertyInfo_V4()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V4::FZZSES_ESPropertyInfo_V4(const FZZBytes & data):FZZSES_ESPropertyInfo_V4()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V4::FZZSES_ESPropertyInfo_V4(const FZZSES_ESPropertyInfo_V4& obj):FZZSES_ESPropertyInfo_V4()
{
    //DLOG("FZZSES_SealInfo_V4(const FZZSES_SealInfo_V4& obj)");
    if ( this == &obj ) {
        return;
    }
    m_SES_CertList = obj.m_SES_CertList == NULL ? NULL : new FZZSES_CertList(*obj.m_SES_CertList);
    m_type = obj.m_type;
    m_name = obj.m_name;
    m_certListType = obj.m_certListType;
    m_createDate = obj.m_createDate;
    m_validStart = obj.m_validStart;
    m_validEnd = obj.m_validEnd;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V4 ::~FZZSES_ESPropertyInfo_V4()
{
    //DLOG("~FZZSES_ESPropertyInfo_V4()");
    FZZConst::delClassCount("FZZSES_ESPropertyInfo_V4");
    if ( m_SES_CertList != NULL ) {
        delete m_SES_CertList;
        m_SES_CertList = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_ESPropertyInfo_V4::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    //size_t templen =0;
    
    FZZBytes temp,type,name,certType,certlist,createDate,validStart,validEnd;
    
    temp = FZZConst::Uint32ToBytes(m_type);
    if ( !type.setMaxLen(temp.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = type.getData();
    if ( asn1_integer_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    type.setLen(bufferlen);
    
    if ( !name.setMaxLen(m_name.length() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = name.getData();
    if ( asn1_utf8_string_to_der(m_name.c_str(),m_name.length(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    name.setLen(bufferlen);
    

    temp = FZZConst::Uint32ToBytes(m_certListType);
    if ( !certType.setMaxLen(temp.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = certType.getData();
    if ( asn1_integer_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    certType.setLen(bufferlen);
    
    if ( m_SES_CertList == NULL ) {
        return ret;
    }
//    temp = m_SES_CertList->Encode();
//    if ( !certlist.setMaxLen(temp.getLen() + 20) ) {
//        return ret;
//    }
//    bufferlen = 0;
//    buffer = certlist.getData();
//    if ( asn1_sequence_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
//        return ret;
//    }
//    certlist.setLen(bufferlen);
    
    //DLOG("cert seq => %s",FZZConst::HexEncode(certlist.getData(), certlist.getLen()).c_str());
    
    
    if ( !createDate.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = createDate.getData();
    if ( asn1_generalized_time_to_der(m_createDate,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    createDate.setLen(bufferlen);
    
    if ( !validStart.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = validStart.getData();
    if ( asn1_generalized_time_to_der(m_validStart,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    validStart.setLen(bufferlen);
    
    if ( !validEnd.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = validEnd.getData();
    if ( asn1_generalized_time_to_der(m_validEnd,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    validEnd.setLen(bufferlen);
    
    
    retData.addData(type);
    retData.addData(name);
    retData.addData(certType);
    retData.addData(m_SES_CertList->Encode());
    retData.addData(createDate);
    retData.addData(validStart);
    retData.addData(validEnd);
    
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
bool FZZSES_ESPropertyInfo_V4::Deccode(const unsigned char * indata,size_t inlenght)
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
    m_type = FZZConst::BytesToUint32(data, datalen);
    
    
    if ((ret = asn1_utf8_string_from_der((const char **)&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    FZZBytes buffer;
    buffer.setMaxLen(datalen+1);
    buffer.setData_NotMalloc(data, datalen);
    m_name = (char *)buffer.getData();
    

    if ((ret = asn1_integer_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_certListType = FZZConst::BytesToUint32(data, datalen);
    
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    if ( m_SES_CertList != NULL ) {
        delete m_SES_CertList;
        m_SES_CertList = NULL;
        
    }
    m_SES_CertList = new FZZSES_CertList(m_certListType,data,datalen);
    
    //---------test begin --------
//    FZZBytes bb = m_SES_CertList->Encode();
//    DLOG("m_SES_CertList : %s",FZZConst::HexEncode(bb.getData(), bb.getLen()).c_str());
    //---------test end ----------
    
    if ((ret = asn1_generalized_time_from_der(&m_createDate, &in, &inlen)) != 1) {
        return isTF;
    }
    
    if ((ret = asn1_generalized_time_from_der(&m_validStart, &in, &inlen)) != 1) {
        return isTF;
    }
    
    if ((ret = asn1_generalized_time_from_der(&m_validEnd, &in, &inlen)) != 1) {
        return isTF;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






