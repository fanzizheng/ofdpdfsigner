//
//  Created by zizheng fan on 2022/11/16.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZSES_ESPictrueInfo_V4.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_ESPictrueInfo_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPictrueInfo_V4::FZZSES_ESPictrueInfo_V4() : m_type(""),m_width(0),m_height(0)
{
    //DLOG("FZZSES_ESPictrueInfo_V4()");
    FZZConst::addClassCount("FZZSES_ESPictrueInfo_V4");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPictrueInfo_V4::FZZSES_ESPictrueInfo_V4(const unsigned char * data,size_t datalen) :FZZSES_ESPictrueInfo_V4()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPictrueInfo_V4::FZZSES_ESPictrueInfo_V4(const FZZBytes & data) :FZZSES_ESPictrueInfo_V4()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPictrueInfo_V4::FZZSES_ESPictrueInfo_V4(const FZZSES_ESPictrueInfo_V4& obj):FZZSES_ESPictrueInfo_V4()
{
    //DLOG("FZZSES_ESPictrueInfo_V4(const FZZSES_ESPictrueInfo_V4& obj)");
    if ( this == &obj ) {
        return;
    }
    m_type = obj.m_type;
    m_data = obj.m_data;
    m_width = obj.m_width;
    m_height = obj.m_height;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_ESPictrueInfo_V4::~FZZSES_ESPictrueInfo_V4()
{
    //DLOG("~FZZSES_ESPictrueInfo_V4()");
    FZZConst::delClassCount("FZZSES_ESPictrueInfo_V4");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_ESPictrueInfo_V4::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,type,image,width,height;
    if ( !type.setMaxLen(m_type.length() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = type.getData();
    if ( asn1_ia5_string_to_der(m_type.c_str(),m_type.length(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    type.setLen(bufferlen);
    
    if ( !image.setMaxLen(m_data.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = image.getData();
    if ( asn1_octet_string_to_der(m_data.getData(),m_data.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    image.setLen(bufferlen);
    
    
    temp = FZZConst::Uint32ToBytes(m_width);
    if ( !width.setMaxLen(temp.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = width.getData();
    if ( asn1_integer_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    width.setLen(bufferlen);
    
    temp = FZZConst::Uint32ToBytes(m_height);
    if ( !height.setMaxLen(temp.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = height.getData();
    if ( asn1_integer_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    height.setLen(bufferlen);
    
    retData.addData(type);
    retData.addData(image);
    retData.addData(width);
    retData.addData(height);
    
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
bool FZZSES_ESPictrueInfo_V4::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
   
    if ((ret = asn1_ia5_string_from_der((const char **)(&data), &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    char * buffer = (char *)malloc(datalen+1);
    memset(buffer,0x00,datalen+1);
    memcpy(buffer,data,datalen);
    m_type = buffer;
    free(buffer);
    buffer = NULL;
    
    m_data.clear();
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_data.setData(data, datalen);
    
 
    if ((ret = asn1_integer_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    m_width = FZZConst::BytesToUint32(data, (int)datalen);
    
    if ((ret = asn1_integer_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_height = FZZConst::BytesToUint32(data, (int)datalen);
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------






