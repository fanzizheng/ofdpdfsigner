//
//  Created by zizheng fan on 2022/11/03.
//
#include "basic/FZZConst.h"
#include "gm/ses/data/FZZSignerInfo.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
#include "gm/crypto/FZZCert.h"
#include "gm/crypto/FZZCertGenerator.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSignerInfo*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSignerInfo::FZZSignerInfo() : m_version(1),m_Issuer(""),m_authenticatedAttributes(NULL),m_unauthenticatedAttributes(NULL)
{
    //DLOG("FZZSignerInfo()");
    FZZConst::addClassCount("FZZSignerInfo");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZSignerInfo::FZZSignerInfo(const unsigned char * data,size_t datalen) :FZZSignerInfo()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSignerInfo::FZZSignerInfo(const FZZBytes & data) :FZZSignerInfo()
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
FZZSignerInfo::FZZSignerInfo(const FZZSignerInfo& obj):FZZSignerInfo()
{
    //DLOG("FZZSignerInfo(const FZZSignerInfo& obj)");
    if ( this == &obj ) {
        return;
    }
    m_version = obj.m_version;
    m_Issuer = obj.m_Issuer;
    m_SerialNumber.setData(obj.m_SerialNumber.getData(), obj.m_SerialNumber.getLen());
    m_digestAlgorithm.setData(obj.m_digestAlgorithm.getData(), obj.m_digestAlgorithm.getLen());
    m_digestEncryptionAlgorithm.setData(obj.m_digestEncryptionAlgorithm.getData(), obj.m_digestEncryptionAlgorithm.getLen());
    m_encryptedDigest.setData(obj.m_encryptedDigest.getData(), obj.m_encryptedDigest.getLen());
    m_authenticatedAttributes = obj.m_authenticatedAttributes == NULL ? NULL : new FZZAuthenticatedAttributes(*(obj.m_authenticatedAttributes));
    m_unauthenticatedAttributes = obj.m_unauthenticatedAttributes == NULL ? NULL : new FZZUnAuthenticatedAttributes(*(obj.m_unauthenticatedAttributes));
//    vector<FZZBytes *>::const_iterator itr;
//    for( itr = obj.m_unauthenticatedAttributes.begin(); itr != obj.m_unauthenticatedAttributes.end(); itr++ ) {
//        m_unauthenticatedAttributes.push_back(new FZZBytes(**itr));
//    }
}


//-----------------------------------------------------------------------------------------------------------------
FZZSignerInfo::~FZZSignerInfo()
{
    //DLOG("~FZZSignerInfo()");
    FZZConst::delClassCount("FZZSignerInfo");
    if ( m_authenticatedAttributes != NULL ) {
        delete m_authenticatedAttributes;
        m_authenticatedAttributes = NULL;
    }
    
    if ( m_unauthenticatedAttributes != NULL ) {
        delete m_unauthenticatedAttributes;
        m_unauthenticatedAttributes = NULL;
    }
    
//    vector<FZZBytes *>::const_iterator itr;
//    for( itr = m_unauthenticatedAttributes.begin(); itr != m_unauthenticatedAttributes.end(); itr++ ) {
//        delete *itr;
//    }
//    m_unauthenticatedAttributes.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSignerInfo::Encode()
{
    FZZBytes ret;
    FZZBytes retData,version,temp,issuerdata,issuerandsndata,sndata,issuerandsnseq,encryptedDigest,authenticatedAttributes,unauthenticatedAttributes;
    uint8_t issuer[256] = {0};
    size_t issuer_len = 0;
    
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
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
    //Issuer and SerialNumber
    FZZCertGenerator cg;
    cg.set_x509_name(m_Issuer, issuer, &issuer_len, sizeof(issuer));
    
 
    if ( !issuerdata.setMaxLen(issuer_len + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = issuerdata.getData();
    if ( asn1_sequence_to_der(issuer,issuer_len,&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    issuerdata.setLen(bufferlen);
    
    if ( !sndata.setMaxLen(m_SerialNumber.getLen()+20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = sndata.getData();
    if ( asn1_integer_to_der(m_SerialNumber.getData(),m_SerialNumber.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    sndata.setLen(bufferlen);
    
    issuerandsndata.addData(issuerdata);
    issuerandsndata.addData(sndata);
    
    if ( !issuerandsnseq.setMaxLen(issuerandsndata.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = issuerandsnseq.getData();
    if ( asn1_sequence_to_der(issuerandsndata.getData(),issuerandsndata.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    issuerandsnseq.setLen(bufferlen);
    //digestAlgorithm
    FZZBytes oid_destalg;
    if ( !oid_destalg.setMaxLen(m_digestAlgorithm.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = oid_destalg.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)m_digestAlgorithm.getData(), m_digestAlgorithm.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    oid_destalg.setLen(bufferlen);
    
    FZZBytes oid_destalg_seq;
    if ( !oid_destalg_seq.setMaxLen(oid_destalg.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = oid_destalg_seq.getData();
    if ( asn1_sequence_to_der(oid_destalg.getData(),oid_destalg.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    oid_destalg_seq.setLen(bufferlen);
    //authenticatedAttributes
    if ( m_authenticatedAttributes != NULL ) {
        authenticatedAttributes = m_authenticatedAttributes->Encode();
    }
    //digestEncryptionAlgorithm
    FZZBytes oid_destalg1;
    if ( !oid_destalg1.setMaxLen(m_digestEncryptionAlgorithm.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = oid_destalg1.getData();
    if (asn1_object_identifier_to_der( (uint32_t *)m_digestEncryptionAlgorithm.getData(), m_digestEncryptionAlgorithm.getLen()/4, &buffer,&bufferlen) != 1) {
        return ret;
    }
    oid_destalg1.setLen(bufferlen);
    
    FZZBytes oid_destalg_seq1;
    if ( !oid_destalg_seq1.setMaxLen(oid_destalg1.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = oid_destalg_seq1.getData();
    if ( asn1_sequence_to_der(oid_destalg1.getData(),oid_destalg1.getLen(),&buffer,&bufferlen) != 1 ) {
        return ret;
    }
    oid_destalg_seq1.setLen(bufferlen);
    //encryptedDigest
    if ( !encryptedDigest.setMaxLen(m_encryptedDigest.getLen() + 20) ) {
        return ret;
    }
    bufferlen = 0;
    buffer = encryptedDigest.getData();
    if ( asn1_octet_string_to_der(m_encryptedDigest.getData(),m_encryptedDigest.getLen(),&buffer,&bufferlen) != 1) {
        return ret;
    }
    encryptedDigest.setLen(bufferlen);
    //unauthenticatedAttributes
    if ( m_unauthenticatedAttributes != NULL ) {
        unauthenticatedAttributes = m_unauthenticatedAttributes->Encode();
    }
    
    retData.addData(version);
    retData.addData(issuerandsnseq);
    retData.addData(oid_destalg_seq);
    if ( authenticatedAttributes.getLen() > 0 ) {
        retData.addData(authenticatedAttributes);
    }
    retData.addData(oid_destalg_seq1);
    retData.addData(encryptedDigest);
    if ( unauthenticatedAttributes.getLen() > 0 ) {
        retData.addData(unauthenticatedAttributes);
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
bool FZZSignerInfo::Deccode(const unsigned char * indata,size_t inlenght)
{
    
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    const uint8_t * in_els = NULL;
    size_t in_els_len = 0;
    //const uint8_t * in_els_begin = NULL;
    
    
    int ret = 0;
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    in = data;
    inlen = datalen;
    
    if ((ret = asn1_integer_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_version = FZZConst::BytesToUint32(data, datalen);
    
    //Issuer and SerialNumber
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    in_els = data;
    in_els_len = datalen;
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
        return isTF;
    }
    
    FZZCert certobj;
    m_Issuer = certobj.get_x509_name_rdn(data,datalen);
    
    if ((ret = asn1_integer_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
        return isTF;
    }
    
    m_SerialNumber.setData(data, datalen);
    
    //digestAlgorithm
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }

    uint32_t nodes[32] = {0};
    size_t nodes_count = 0;
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &data, &datalen)) != 1) {
        return isTF;
    }
    m_digestAlgorithm.setData((unsigned char *)nodes,nodes_count*4);
    //authenticatedAttributes
    if ( m_authenticatedAttributes != NULL ) {
        delete m_authenticatedAttributes;
        m_authenticatedAttributes = NULL;
    }
    if ( inlen > 0 && *in == 0xA0 ) {
        m_authenticatedAttributes = new FZZAuthenticatedAttributes((unsigned char *)in,inlen);
        if ((ret = asn1_implicit_sequence_from_der(0,&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
    }
    
    //digestEncryptionAlgorithm
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }

    uint32_t nodes1[32] = {0};
    size_t nodes_count1 = 0;
    if ((ret = asn1_object_identifier_from_der(nodes1, &nodes_count1, &data, &datalen)) != 1) {
        return isTF;
    }
    m_digestEncryptionAlgorithm.setData((unsigned char *)nodes1,nodes_count1*4);
    //encryptedDigest
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    m_encryptedDigest.setData(data, datalen);
    //unauthenticatedAttributes
    if ( inlen > 0 ) {
        if ( m_unauthenticatedAttributes != NULL ) {
            delete m_unauthenticatedAttributes;
            m_unauthenticatedAttributes = NULL;
        }
        m_unauthenticatedAttributes = new FZZUnAuthenticatedAttributes((unsigned char *)in,inlen);
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------


