//
//  Created by zizheng fan on 2022/11/13.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZSES_Header.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_Header******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Header::FZZSES_Header() : m_version(0)
{
    //DLOG("FZZSES_Header()");
    FZZConst::addClassCount("FZZSES_Header");
    m_version = 4;
    m_id = "ES";
    m_vid = OFD_COMPANY"-stamp";
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Header::FZZSES_Header(const unsigned char * data,size_t datalen):FZZSES_Header()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Header::FZZSES_Header(const FZZBytes & data):FZZSES_Header()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Header::FZZSES_Header(const FZZSES_Header& obj):FZZSES_Header()
{
    //DLOG("FZZSES_Header(const FZZSES_Header& obj)");
    if ( this == &obj ) {
        return;
    }
    m_id = obj.m_id;
    m_version = obj.m_version;
    m_vid = obj.m_vid;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Header ::~FZZSES_Header()
{
    //DLOG("~FZZSES_Header()");
    FZZConst::delClassCount("FZZSES_Header");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_Header::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes id,vid,version,temp;
    
    if ( !id.setMaxLen(m_id.length() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = id.getData();
    if ( asn1_ia5_string_to_der(m_id.c_str(),m_id.length(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    id.setLen(bufferlen);
    

    temp = FZZConst::Uint32ToBytes(m_version);
    if ( !version.setMaxLen(temp.getLen()+20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = version.getData();
    if ( asn1_integer_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    version.setLen(bufferlen);
    
    
    bufferlen = 0;
    if ( !vid.setMaxLen(m_vid.length() + 20) ) {
        return ret;
    }
    buffer = vid.getData();
    bufferlen = 0;
    if ( asn1_ia5_string_to_der(m_vid.c_str(),m_vid.length(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    vid.setLen(bufferlen);
    
    retData.addData(id);
    retData.addData(version);
    retData.addData(vid);
    
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
bool FZZSES_Header::Deccode(const unsigned char * indata,size_t inlenght)
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
    m_id = buffer;
    free(buffer);
    buffer = NULL;
 
    if ((ret = asn1_integer_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_version = FZZConst::BytesToUint32(data, datalen);
    
    m_vid.clear();
    if ((ret = asn1_ia5_string_from_der((const char **)(&data), &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    buffer = (char *)malloc(datalen+1);
    memset(buffer,0x00,datalen+1);
    memcpy(buffer,data,datalen);
    m_vid = buffer;
    free(buffer);
    buffer = NULL;
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






