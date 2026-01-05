//
//  Created by zizheng fan on 2022/11/06.
//
#include "basic/FZZConst.h"
#include "gm/ses/v1/FZZSES_SealInfo_V1.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_SealInfo_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SealInfo_V1::FZZSES_SealInfo_V1() : m_esID(""),m_picture(NULL),m_header(NULL),m_property(NULL),m_extDatas(NULL)
{
    //DLOG("FZZSES_SealInfo_V1()");
    FZZConst::addClassCount("FZZSES_SealInfo_V1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SealInfo_V1::FZZSES_SealInfo_V1(const unsigned char * data,size_t datalen):FZZSES_SealInfo_V1()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SealInfo_V1::FZZSES_SealInfo_V1(const FZZBytes & data):FZZSES_SealInfo_V1()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SealInfo_V1::FZZSES_SealInfo_V1(const FZZSES_SealInfo_V1& obj):FZZSES_SealInfo_V1()
{
    //DLOG("FZZSES_SealInfo_V1(const FZZSES_SealInfo_V1& obj)");
    if ( this == &obj ) {
        return;
    }
    m_picture = obj.m_picture == NULL ? NULL : new FZZSES_ESPictrueInfo_V4(*obj.m_picture);
    m_header = obj.m_header == NULL ? NULL : new FZZSES_Header(*obj.m_header);
    m_property = obj.m_property == NULL ? NULL : new FZZSES_ESPropertyInfo_V1(*obj.m_property);
    m_extDatas = obj.m_extDatas == NULL ? NULL : new FZZExtensionDatas(*obj.m_extDatas);
    m_esID = obj.m_esID;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_SealInfo_V1 ::~FZZSES_SealInfo_V1()
{
    //DLOG("~FZZSES_SealInfo_V1()");
    FZZConst::delClassCount("FZZSES_SealInfo_V1");
    
    if ( m_header != NULL ) {
        delete m_header;
        m_header = NULL;
        
    }
    
    if ( m_picture != NULL ) {
        delete m_picture;
        m_picture = NULL;
        
    }
    
    if ( m_property != NULL ) {
        delete m_property;
        m_property = NULL;
        
    }
    
    if ( m_extDatas != NULL ) {
        delete m_extDatas;
        m_extDatas = NULL;
        
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_SealInfo_V1::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,head,esid,property,picture,extDatas;
    
    if ( m_header == NULL || m_property == NULL || m_picture == NULL ) {
        return ret;
    }
    
    if ( !esid.setMaxLen(m_esID.length() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = esid.getData();
    if ( asn1_ia5_string_to_der(m_esID.c_str(),m_esID.length(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    esid.setLen(bufferlen);
    
    retData.addData(m_header->Encode());
    retData.addData(esid);
    retData.addData(m_property->Encode());
    retData.addData(m_picture->Encode());
    
    if ( m_extDatas != NULL ) {
//        temp = m_extDatas->Encode();
//        if ( !extDatas.setMaxLen(temp.getLen() + 20) ) {
//            return ret;
//        }
//        bufferlen = 0;
//        buffer = extDatas.getData();
//        if ( asn1_sequence_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
//            return ret;
//        }
//        extDatas.setLen(bufferlen);
        retData.addData(m_extDatas->Encode());
    }
    
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
bool FZZSES_SealInfo_V1::Deccode(const unsigned char * indata,size_t inlenght)
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
    if ( m_header != NULL ) {
        delete m_header;
        m_header = NULL;
        
    }
    m_header = new FZZSES_Header(data,datalen);
    
    //---------test begin --------
    //FZZBytes cc = m_header->Encode();
    //DLOG("m_header %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    

    if ((ret = asn1_ia5_string_from_der((const char **)(&data), &datalen, &in, &inlen)) != 1) {
        return isTF;
    }

    FZZBytes buffer;
    buffer.setMaxLen(datalen+1);
    buffer.setData_NotMalloc(data, datalen);
    m_esID = (char *)buffer.getData();
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    if ( m_property != NULL ) {
        delete m_property;
        m_property = NULL;
        
    }
    m_property = new FZZSES_ESPropertyInfo_V1(data,datalen);
    
    //---------test begin --------
    //FZZBytes aa = m_property->Encode();
    //DLOG("property : %s",FZZConst::HexEncode(aa.getData(), aa.getLen()).c_str());
    //---------test end ----------
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    if ( m_picture != NULL ) {
        delete m_picture;
        m_picture = NULL;
        
    }
    m_picture = new FZZSES_ESPictrueInfo_V4(data,datalen);
    //---------test begin --------
    //FZZBytes bb = m_picture->Encode();
    //DLOG("picture : %s",FZZConst::HexEncode(bb.getData(), bb.getLen()).c_str());
    //---------test end ----------
    
    if ( inlen > 0 ) {
        if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        if ( m_extDatas != NULL ) {
            delete m_extDatas;
            m_extDatas = NULL;
            
        }
        m_extDatas = new FZZExtensionDatas(data,datalen);
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






