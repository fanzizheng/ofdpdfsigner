//
//  Created by zizheng fan on 2022/11/17.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZTBS_Sign_V4.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZTBS_Sign_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V4::FZZTBS_Sign_V4():m_SESeal_V4(NULL),m_version(4),m_timeInfo(0),m_extDatas(NULL),m_propertyInfo("")
{
    //DLOG("FZZTBS_Sign_V4()");
    FZZConst::addClassCount("FZZTBS_Sign_V4");
}
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V4::FZZTBS_Sign_V4(const unsigned char * data,size_t datalen) :FZZTBS_Sign_V4()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V4::FZZTBS_Sign_V4(const FZZTBS_Sign_V4& obj) :FZZTBS_Sign_V4()
{
    //DLOG("FZZTBS_Sign_V4(const FZZTBS_Sign_V4& obj)");
    if ( this == &obj ) {
        return;
    }
    m_version = obj.m_version;
    m_SESeal_V4 = obj.m_SESeal_V4 == NULL ? NULL : new FZZSESeal_V4(*obj.m_SESeal_V4);
    m_timeInfo = obj.m_timeInfo;
    m_dataHash = obj.m_dataHash;
    m_propertyInfo = obj.m_propertyInfo;
    m_extDatas = obj.m_extDatas == NULL ? NULL : new FZZExtensionDatas(*obj.m_extDatas);
}
//-----------------------------------------------------------------------------------------------------------------
FZZTBS_Sign_V4::~FZZTBS_Sign_V4()
{
    //DLOG("~FZZTBS_Sign_V4()");
    FZZConst::delClassCount("FZZTBS_Sign_V4");
    if ( m_SESeal_V4 != NULL ) {
        delete m_SESeal_V4;
        m_SESeal_V4 = NULL;
        
    }
    
    if ( m_extDatas != NULL ) {
        delete m_extDatas;
        m_extDatas = NULL;
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZTBS_Sign_V4::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,version,seseal,timeInfo,dataHash,propertyInfo,extDatas;
    
    if ( m_SESeal_V4 == NULL ) {
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
    
//    temp = m_SESeal_V4->Encode();
//    if ( !seseal.setMaxLen(temp.getLen() + 20) ) {
//        return ret;
//    }
//    bufferlen = 0;
//    buffer = seseal.getData();
//    if ( asn1_sequence_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1 ) {
//        return ret;
//    }
//    seseal.setLen(bufferlen);
    
    if ( !timeInfo.setMaxLen(60 + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = timeInfo.getData();
    if ( asn1_generalized_time_to_der(m_timeInfo,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    timeInfo.setLen(bufferlen);
    
    
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
    
    
    retData.addData(version);
    retData.addData(m_SESeal_V4->Encode());
    retData.addData(timeInfo);
    retData.addData(dataHash);
    retData.addData(propertyInfo);
    
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
bool FZZTBS_Sign_V4::Deccode(const unsigned char * indata,size_t inlenght)
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
    if ( m_SESeal_V4 != NULL ) {
        delete m_SESeal_V4;
        m_SESeal_V4 = NULL;
        
    }
    m_SESeal_V4 = new FZZSESeal_V4(data,datalen);
    //---------test begin --------
    //FZZBytes cc = m_SESeal_V4->Encode();
    //DLOG("m_SESeal_V4 %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    
    
    if ((ret = asn1_generalized_time_from_der(&m_timeInfo, &in, &inlen)) != 1) {
        return isTF;
    }
    
    
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







