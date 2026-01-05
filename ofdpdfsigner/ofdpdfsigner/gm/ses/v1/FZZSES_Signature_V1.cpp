//
//  Created by zizheng fan on 2022/11/08.
//
#include "basic/FZZConst.h"
#include "gm/ses/v1/FZZSES_Signature_V1.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_Signature_V1******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V1::FZZSES_Signature_V1() : m_TBSSign(NULL)
{
    //DLOG("FZZSES_Signature_V1()");
    FZZConst::addClassCount("FZZSES_Signature_V1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V1::FZZSES_Signature_V1(FZZTBS_Sign_V1* TBSSign,const FZZBytes& signature):FZZSES_Signature_V1()
{
    m_TBSSign = new FZZTBS_Sign_V1(*TBSSign);
 
    m_signature = signature;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V1::FZZSES_Signature_V1(const FZZBytes& data) :FZZSES_Signature_V1()
{
    Deccode(data);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V1::FZZSES_Signature_V1(const FZZSES_Signature_V1& obj):FZZSES_Signature_V1()
{
    //DLOG("FZZSES_Signature_V1(const FZZSES_Signature_V1& obj)");
    if ( this == &obj ) {
        return;
    }
    m_TBSSign = obj.m_TBSSign == NULL ? NULL : new FZZTBS_Sign_V1(*obj.m_TBSSign);
    m_signature = obj.m_signature;

}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_Signature_V1::~FZZSES_Signature_V1()
{
    //DLOG("~FZZSES_Signature_V1()");
    FZZConst::delClassCount("FZZSES_Signature_V1");
    if ( m_TBSSign != NULL ) {
        delete m_TBSSign;
        m_TBSSign = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//sign seal data
// v1:
//    sequence                      v4_1
//      ->sequence                  v4_1_1      //sign seal info
//      ->bit string                v4_1_4      //sign value

bool FZZSES_Signature_V1::Deccode(const FZZBytes& seq)
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
    m_TBSSign = new FZZTBS_Sign_V1(data,datalen);
    //---------test begin --------
    //FZZBytes cc = m_TBSSign->Encode();
    //DLOG("m_TBSSign %s",FZZConst::HexEncode(cc.getData(), cc.getLen()).c_str());
    //---------test end ----------
    //v4_1_3
    m_signature.clear();
    if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_signature.setData(data, datalen/8);
    
    isTF = true;
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_Signature_V1::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,FZZCert,signatureAlgID,signature,timeStamp;
    
    if ( m_TBSSign == NULL ) {
        return ret;
    }
    
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
    retData.addData(signature);
    
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




