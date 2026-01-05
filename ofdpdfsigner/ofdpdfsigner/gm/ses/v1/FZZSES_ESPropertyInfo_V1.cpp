//
//  Created by zizheng fan on 2022/11/05.
//
#include "basic/FZZConst.h"
#include "gm/ses/v1/FZZSES_ESPropertyInfo_V1.h"
#include "gmssl/asn1.h"

const uint32_t FZZSES_ESPropertyInfo_V1::CertListType = 1;
const uint32_t FZZSES_ESPropertyInfo_V1::CertDigestListType = 2;
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_ESPropertyInfo_V1******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V1::FZZSES_ESPropertyInfo_V1() : m_type(0),m_SES_CertList(NULL),m_createDate(0),m_validStart(0),m_validEnd(0)
{
    //DLOG("FZZSES_ESPropertyInfo_V1()");
    FZZConst::addClassCount("FZZSES_ESPropertyInfo_V1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V1::FZZSES_ESPropertyInfo_V1(const unsigned char * data,size_t datalen):FZZSES_ESPropertyInfo_V1()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V1::FZZSES_ESPropertyInfo_V1(const FZZBytes & data):FZZSES_ESPropertyInfo_V1()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V1::FZZSES_ESPropertyInfo_V1(const FZZSES_ESPropertyInfo_V1& obj):FZZSES_ESPropertyInfo_V1()
{
    //DLOG("FZZSES_ESPropertyInfo_V1(const FZZSES_ESPropertyInfo_V1& obj)");
    if ( this == &obj ) {
        return;
    }
    m_SES_CertList = obj.m_SES_CertList == NULL ? NULL : new FZZSES_CertList(*obj.m_SES_CertList);
    m_type = obj.m_type;
    m_name = obj.m_name;
    m_createDate = obj.m_createDate;
    m_validStart = obj.m_validStart;
    m_validEnd = obj.m_validEnd;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPropertyInfo_V1 ::~FZZSES_ESPropertyInfo_V1()
{
    //DLOG("~FZZSES_ESPropertyInfo_V1()");
    FZZConst::delClassCount("FZZSES_ESPropertyInfo_V1");
    if ( m_SES_CertList != NULL ) {
        delete m_SES_CertList;
        m_SES_CertList = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_ESPropertyInfo_V1::Encode()
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
    

    
    //Didn't make it clear, temporarily replaced by xx 30 03 16 01 31
    if ( m_SES_CertList == NULL ) {
        unsigned char certdata[5] = {0x30,0x03,0x16,0x01,0x31};
        certlist.setData(certdata, 5);
    } else {
        FZZBytes tempdata = m_SES_CertList->Encode();
        certlist.setData(tempdata.getData(),tempdata.getLen());
    }
    
    
    
    if ( !createDate.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = createDate.getData();
    if ( asn1_utc_time_to_der(m_createDate,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    createDate.setLen(bufferlen);
    
    if ( !validStart.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = validStart.getData();
    if ( asn1_utc_time_to_der(m_validStart,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    validStart.setLen(bufferlen);
    
    if ( !validEnd.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = validEnd.getData();
    if ( asn1_utc_time_to_der(m_validEnd,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    validEnd.setLen(bufferlen);
    
    
    retData.addData(type);
    retData.addData(name);
    //retData.addData(m_SES_CertList->Encode());
    retData.addData(certlist);
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
bool FZZSES_ESPropertyInfo_V1::Deccode(const unsigned char * indata,size_t inlenght)
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
    
    
    if ( m_SES_CertList != NULL ) {
        delete m_SES_CertList;
        m_SES_CertList = NULL;
        
    }
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) == 1) {
        m_SES_CertList = new FZZSES_CertList(FZZSES_ESPropertyInfo_V1::CertListType,data,datalen);
    } else {
        //is null
        
    }

    //---------test begin --------
//    FZZBytes bb = m_SES_CertList->Encode();
//    DLOG("m_SES_CertList : %s",FZZConst::HexEncode(bb.getData(), bb.getLen()).c_str());
    //---------test end ----------
    
    if ((ret = asn1_utc_time_from_der(&m_createDate, &in, &inlen)) != 1) {
        return isTF;
    }
    
    if ((ret = asn1_utc_time_from_der(&m_validStart, &in, &inlen)) != 1) {
        return isTF;
    }
    
    if ((ret = asn1_utc_time_from_der(&m_validEnd, &in, &inlen)) != 1) {
        return isTF;
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






