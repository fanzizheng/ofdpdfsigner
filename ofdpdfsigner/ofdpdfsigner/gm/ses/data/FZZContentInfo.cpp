//
//  Created by zizheng fan on 2022/11/04.
//
#include "basic/FZZConst.h"
#include "gm/ses/data/FZZContentInfo.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZContentInfo*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZContentInfo::FZZContentInfo() : m_SignedData(NULL)
{
    //DLOG("FZZContentInfo()");
    FZZConst::addClassCount("FZZContentInfo");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentInfo::FZZContentInfo(const unsigned char * data,size_t datalen) :FZZContentInfo()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentInfo::FZZContentInfo(const FZZBytes & data) :FZZContentInfo()
{
    
    const uint8_t * in = data.getData();
    size_t inlen = data.getLen();
    const uint8_t * outdata = NULL;
    size_t outdatalen = 0;
    
    int ret = 0;
    
    if ((ret = asn1_sequence_from_der(&outdata, &outdatalen, &in, &inlen)) != 1) {
        return ;
    }
    
    Deccode(outdata,outdatalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentInfo::FZZContentInfo(const FZZContentInfo& obj):FZZContentInfo()
{
    //DLOG("FZZContentInfo(const FZZContentInfo& obj)");
    if ( this == &obj ) {
        return;
    }
    
    m_contentType.setData(obj.m_contentType.getData(), obj.m_contentType.getLen());
    m_SignedData = obj.m_SignedData == NULL ? NULL : new FZZSignedData(*obj.m_SignedData);
    m_dataContent.setData(obj.m_dataContent.getData(), obj.m_dataContent.getLen());
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentInfo::~FZZContentInfo()
{
    //DLOG("~FZZContentInfo()");
    FZZConst::delClassCount("FZZContentInfo");
    if ( m_SignedData != NULL ) {
        delete m_SignedData;
        m_SignedData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZContentInfo::Encode()
{
    FZZBytes ret;
    FZZBytes retData,contentType,signedData,dataContent;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    
    if ( !contentType.setMaxLen(m_contentType.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = contentType.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)m_contentType.getData(), m_contentType.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    contentType.setLen(bufferlen);
    
    retData.addData(contentType);
    if ( m_SignedData != NULL ) {
        FZZBytes tempsignedData = m_SignedData->Encode();
        
        if ( !signedData.setMaxLen(tempsignedData.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = signedData.getData();
        if ( asn1_implicit_sequence_to_der(0,tempsignedData.getData(),tempsignedData.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        signedData.setLen(bufferlen);
        
        retData.addData(signedData);
    }
    
    if ( m_dataContent.getLen() > 0 ) {
        FZZBytes ostrdata;
        if ( !ostrdata.setMaxLen(m_dataContent.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = ostrdata.getData();
        if ( asn1_octet_string_to_der(m_dataContent.getData(),m_dataContent.getLen(),&buffer,&bufferlen) != 1) {
            return ret;
        }
        ostrdata.setLen(bufferlen);
        
        
        if ( !dataContent.setMaxLen(ostrdata.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = dataContent.getData();
        if ( asn1_implicit_sequence_to_der(0,ostrdata.getData(),ostrdata.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        dataContent.setLen(bufferlen);
        
        retData.addData(dataContent);
    }
    
    if ( !ret.setMaxLen(retData.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = ret.getData();
    if ( asn1_sequence_to_der(retData.getData(),retData.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    ret.setLen(bufferlen);
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
//    sequence
//    ->object identifier
//    ->Context[0]
bool FZZContentInfo::Deccode(const unsigned char * indata,size_t inlenght)
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
    
    in = data;
    inlen = datalen;
    
    uint32_t nodes[32];
    size_t nodes_count = 0;
    //v4_1_4
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in, &inlen)) != 1) {
        return isTF;
    }
    m_contentType.setData((unsigned char *)nodes,nodes_count*4);
    
    //Context[0]
    if ( m_SignedData != NULL ) {
        delete m_SignedData;
        m_SignedData = NULL;
        
    }
    
    if ( inlen > 0 && *in == 0xA0) {
   
        if ((ret = asn1_implicit_sequence_from_der(0,&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        if ( *data == 0x04 ) {
            in = data;
            inlen = datalen;
            if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
                return isTF;
            }
            m_dataContent.setData(data, datalen);
        } else {
            m_SignedData = new FZZSignedData(data,datalen);
        }
        
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------


