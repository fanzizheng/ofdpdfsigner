//
//  Created by zizheng fan on 2022/11/17.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZSES_Signature_V4.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_Signature_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V4::FZZSES_Signature_V4() : m_TBSSign(NULL)
{
    //DLOG("FZZSES_Signature_V4()");
    FZZConst::addClassCount("FZZSES_Signature_V4");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V4::FZZSES_Signature_V4(FZZTBS_Sign_V4* TBSSign,const FZZBytes& FZZCert,const FZZBytes& signatureAlgID,const FZZBytes& signature,const FZZBytes& timeStamp):FZZSES_Signature_V4()
{
    m_TBSSign = new FZZTBS_Sign_V4(*TBSSign);
    m_Cert = FZZCert;
    m_signatureAlgID = signatureAlgID;
    m_signature = signature;
    m_timeStamp = timeStamp;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V4::FZZSES_Signature_V4(const FZZBytes& data) :FZZSES_Signature_V4()
{
    Deccode(data);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V4::FZZSES_Signature_V4(const FZZSES_Signature_V4& obj):FZZSES_Signature_V4()
{
    //DLOG("FZZSES_Signature_V4(const FZZSES_Signature_V4& obj)");
    if ( this == &obj ) {
        return;
    }
    m_TBSSign = obj.m_TBSSign == NULL ? NULL : new FZZTBS_Sign_V4(*obj.m_TBSSign);
    m_Cert = obj.m_Cert;
    m_signatureAlgID = obj.m_signatureAlgID;
    m_signature = obj.m_signature;
    m_timeStamp = obj.m_timeStamp;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V4::~FZZSES_Signature_V4()
{
    //DLOG("~FZZSES_Signature_V4()");
    FZZConst::delClassCount("FZZSES_Signature_V4");
    if ( m_TBSSign != NULL ) {
        delete m_TBSSign;
        m_TBSSign = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//sign seal data
// v4:
//    sequence                      v4_1
//      ->sequence                  v4_1_1      //sign seal info
//      ->octet string              v4_1_2      //Certificate of seal maker
//      ->object identifier         v4_1_3      //signature algorithm identifier
//      ->bit string                v4_1_4      //signature value
//      ->bit string                v4_1_5      //Timestamp of the signature value [Optional]
bool FZZSES_Signature_V4::Deccode(const FZZBytes& seq)
{
    bool isTF = false;
    const uint8_t * src_p = seq.getData();
    size_t src_len = seq.getLen();
    
    const uint8_t * in = src_p;
    size_t inlen = src_len;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    //v4_1
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    in = data;
    inlen = datalen;
    //v4_1_1
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    if ( m_TBSSign != NULL ) {
        delete m_TBSSign;
        m_TBSSign = NULL;
    }
    m_TBSSign = new FZZTBS_Sign_V4(data,datalen);
    //---------test begin --------
    //FZZBytes cc = m_TBSSign->Encode();
    //DLOG("m_TBSSign %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    
    //v4_1_2
    m_Cert.clear();
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_Cert.setData(data, datalen);
    
    uint32_t nodes[32];
    size_t nodes_count = 0;
    //v4_1_4
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in, &inlen)) != 1) {
        return isTF;
    }
    m_signatureAlgID.setData((unsigned char *)nodes,nodes_count*4);
    
    //v4_1_3
    m_signature.clear();
    if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_signature.setData(data, datalen/8);
    
    if ( inlen != 0 ) {
        //v4_1_5
        m_timeStamp.clear();
        if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        m_timeStamp.setData(data, datalen/8);
    }
    isTF = true;
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_Signature_V4::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,FZZCert,signatureAlgID,signature,timeStamp;
    
    if ( m_TBSSign == NULL ) {
        return ret;
    }
    
    if ( !FZZCert.setMaxLen(m_Cert.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = FZZCert.getData();
    if ( asn1_octet_string_to_der(m_Cert.getData(),m_Cert.getLen(),&buffer,&bufferlen) != 1) {
        return ret;
    }
    FZZCert.setLen(bufferlen);
    
    if ( !signatureAlgID.setMaxLen(m_signatureAlgID.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = signatureAlgID.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)m_signatureAlgID.getData(), m_signatureAlgID.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    signatureAlgID.setLen(bufferlen);
    
    if ( !signature.setMaxLen(m_signature.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = signature.getData();
    if (asn1_bit_string_to_der(m_signature.getData(), m_signature.getLen()*8, &buffer,&bufferlen) != 1) {
        return ret;
    }
    signature.setLen(bufferlen);
    
    
    retData.addData(m_TBSSign->Encode());
    retData.addData(FZZCert);
    retData.addData(signatureAlgID);
    retData.addData(signature);
    
    if ( m_timeStamp.getLen() > 0 ) {
        if ( !timeStamp.setMaxLen(m_timeStamp.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = timeStamp.getData();
        if (asn1_bit_string_to_der(m_timeStamp.getData(), m_timeStamp.getLen()*8, &buffer,&bufferlen) != 1) {
            return ret;
        }
        timeStamp.setLen(bufferlen);
        retData.addData(timeStamp);
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




