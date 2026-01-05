//
//  Created by zizheng fan on 2022/11/01.
//
#include "basic/FZZConst.h"
#include "gm/ses/data/FZZUnAuthenticatedAttributes.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZUnAuthenticatedAttributes*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZUnAuthenticatedAttributes::FZZUnAuthenticatedAttributes()
{
    //DLOG("FZZUnAuthenticatedAttributes()");
    FZZConst::addClassCount("FZZUnAuthenticatedAttributes");

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZUnAuthenticatedAttributes::FZZUnAuthenticatedAttributes(const unsigned char * data,size_t datalen) :FZZUnAuthenticatedAttributes()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZUnAuthenticatedAttributes::FZZUnAuthenticatedAttributes(const FZZBytes & data) :FZZUnAuthenticatedAttributes()
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
FZZUnAuthenticatedAttributes::FZZUnAuthenticatedAttributes(const FZZUnAuthenticatedAttributes& obj):FZZUnAuthenticatedAttributes()
{
    //DLOG("FZZContentInfo(const FZZContentInfo& obj)");
    if ( this == &obj ) {
        return;
    }
    //m_messageDigest = obj.m_messageDigest;
    m_messageDigest.setData(obj.m_messageDigest.getData(), obj.m_messageDigest.getLen());
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZUnAuthenticatedAttributes::~FZZUnAuthenticatedAttributes()
{
    //DLOG("~FZZUnAuthenticatedAttributes()");
    FZZConst::delClassCount("FZZUnAuthenticatedAttributes");
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZUnAuthenticatedAttributes::Encode()
{
    FZZBytes ret;
    FZZBytes retData,contentType,signingTime,messageDigest;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    
    //messageDigest
    if ( m_messageDigest.getLen() > 0 ) {
        FZZBytes ostr_messageDigest;
        if ( !ostr_messageDigest.setMaxLen(m_messageDigest.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = ostr_messageDigest.getData();
        if ( asn1_octet_string_to_der(m_messageDigest.getData(),m_messageDigest.getLen(),&buffer,&bufferlen) != 1) {
            return ret;
        }
        ostr_messageDigest.setLen(bufferlen);
        
        
        FZZBytes oid_messageDigest_set;
        if ( !oid_messageDigest_set.setMaxLen(ostr_messageDigest.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = oid_messageDigest_set.getData();
        if ( asn1_set_to_der(ostr_messageDigest.getData(),ostr_messageDigest.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        oid_messageDigest_set.setLen(bufferlen);
        
        int32_t messageDigest_tag_nodes[] = {1,2,840,113549,1,9,4};
        size_t messageDigest_tag_nodes_count = 7;
        FZZBytes messageDigestalg_tag((unsigned char *)messageDigest_tag_nodes,messageDigest_tag_nodes_count*4);
        
        FZZBytes oid_messageDigest_tag;
        if ( !oid_messageDigest_tag.setMaxLen(messageDigestalg_tag.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = oid_messageDigest_tag.getData();
        if (asn1_object_identifier_to_der( (uint32_t *)messageDigestalg_tag.getData(), messageDigestalg_tag.getLen()/4, &buffer,&bufferlen) != 1) {
            return ret;
        }
        oid_messageDigest_tag.setLen(bufferlen);
        
        FZZBytes messageDigestseq;
        messageDigestseq.addData(oid_messageDigest_tag);
        messageDigestseq.addData(oid_messageDigest_set);
        
        if ( !messageDigest.setMaxLen(messageDigestseq.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = messageDigest.getData();
        if ( asn1_sequence_to_der(messageDigestseq.getData(),messageDigestseq.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        messageDigest.setLen(bufferlen);
    }
    
    retData.addData(contentType);
    retData.addData(signingTime);
    if ( messageDigest.getLen() > 0 ) {
        retData.addData(messageDigest);
    }
    
    
    if ( !ret.setMaxLen(retData.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = ret.getData();
    if ( asn1_implicit_sequence_to_der(1,retData.getData(),retData.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    ret.setLen(bufferlen);
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZUnAuthenticatedAttributes::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    const uint8_t * in_els = NULL;
    size_t in_els_len = 0;
    
    int ret = 0;
    
    if ((ret = asn1_implicit_sequence_from_der(1,&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    in = data;
    inlen = datalen;
    
    while( inlen > 0 ) {
        if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        
        in_els = data;
        in_els_len = datalen;
        
        uint32_t nodes[32] = {0};
        size_t nodes_count = 0;
        if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in_els, &in_els_len)) != 1) {
            return isTF;
        }
        
        if ((ret = asn1_set_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
            return isTF;
        }
        
        in_els = data;
        in_els_len = datalen;
        
        if (nodes[0] == 1 && nodes[1] == 2 && nodes[2] == 840 && nodes[3] == 113549 && nodes[4] == 1 && nodes[5] == 9 && nodes[6] == 4) {
            //cms :: messageDigest
            if ((ret = asn1_octet_string_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
                return isTF;
            }
            m_messageDigest.setData(data, datalen);
        }
        
    }
    
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZUnAuthenticatedAttributes::getPlainText()
{
    FZZBytes encdata = Encode();
    encdata.updataData(0, 0x31);
    return encdata;
}
//-----------------------------------------------------------------------------------------------------------------
