//
//  Created by zizheng fan on 2022/11/02.
//
#include "basic/FZZConst.h"
#include "gm/ses/data/FZZSignedData.h"
#include "gmssl/asn1.h"
#include "gmssl/oid.h"
#include "gm/ses/data/FZZContentInfo.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSignedData*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSignedData::FZZSignedData() : m_version(1),m_ContentInfo(NULL)
{
    //DLOG("FZZSignedData()");
    FZZConst::addClassCount("FZZSignedData");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZSignedData::FZZSignedData(const unsigned char * data,size_t datalen) :FZZSignedData()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSignedData::FZZSignedData(const FZZBytes & data) :FZZSignedData()
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
FZZSignedData::FZZSignedData(const FZZSignedData& obj):FZZSignedData()
{
    //DLOG("FZZSignedData(const FZZSignedData& obj)");
    if ( this == &obj ) {
        return;
    }
    m_version = obj.m_version;
    vector<FZZBytes *>::const_iterator itr;
    for( itr = obj.m_digestAlgorithms.begin(); itr != obj.m_digestAlgorithms.end(); itr++ ) {
        m_digestAlgorithms.push_back(new FZZBytes(**itr));
    }
    for( itr = obj.m_certificates.begin(); itr != obj.m_certificates.end(); itr++ ) {
        m_certificates.push_back(new FZZBytes(**itr));
    }
    for( itr = obj.m_crls.begin(); itr != obj.m_crls.end(); itr++ ) {
        m_crls.push_back(new FZZBytes(**itr));
    }
    
    m_ContentInfo = obj.m_ContentInfo == NULL ? NULL : new FZZContentInfo(*(obj.m_ContentInfo));
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = obj.m_signerInfos.begin(); SignerInfo_itr != obj.m_signerInfos.end(); SignerInfo_itr++ ) {
        m_signerInfos.push_back(new FZZSignerInfo(**SignerInfo_itr));
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZSignedData::~FZZSignedData()
{
    //DLOG("~FZZSignedData()");
    FZZConst::delClassCount("FZZSignedData");
    clear_digestAlgorithms();
    clear_certificates();
    clear_crls();
    clear_signerInfos();
    if ( m_ContentInfo != NULL ) {
        delete m_ContentInfo;
        m_ContentInfo = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSignedData::Encode()
{
    FZZBytes ret;
    FZZBytes retData,version,temp,digestAlgorithms,digestAlgorithms_data,contentInfo,
          certsdata,certs,clsdata,cls,signerInfosdata,signerInfos;
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
    //digestAlgorithms
    bufferlen = 0;
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_digestAlgorithms.begin(); itr != m_digestAlgorithms.end(); itr++ ) {
        FZZBytes* destalg = *itr;
        FZZBytes oid_destalg;
        if ( !oid_destalg.setMaxLen(destalg->getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = oid_destalg.getData();
        if (asn1_object_identifier_to_der( (uint32_t *)destalg->getData(), destalg->getLen()/4, &buffer,&bufferlen) != 1) {
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
        digestAlgorithms_data.addData(oid_destalg_seq);
    }
    
    if ( digestAlgorithms_data.getLen() > 0 ) {
        
        if ( !digestAlgorithms.setMaxLen(digestAlgorithms_data.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = digestAlgorithms.getData();
        if ( asn1_set_to_der(digestAlgorithms_data.getData(),digestAlgorithms_data.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        digestAlgorithms.setLen(bufferlen);
    }
    //contentInfo
    if ( m_ContentInfo != NULL ) {
        contentInfo = m_ContentInfo->Encode();
    }
    //certificates
    for( itr = m_certificates.begin(); itr != m_certificates.end(); itr++ ) {
        certsdata.addData(**itr);
    }
    if ( certsdata.getLen() > 0 ) {
        
        if ( !certs.setMaxLen(certsdata.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = certs.getData();
        if ( asn1_implicit_sequence_to_der(0,certsdata.getData(),certsdata.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        certs.setLen(bufferlen);
    }
    
    //cls
    for( itr = m_crls.begin(); itr != m_crls.end(); itr++ ) {
        clsdata.addData(**itr);
    }
    if ( clsdata.getLen() > 0 ) {
        
        if ( !cls.setMaxLen(clsdata.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = cls.getData();
        if ( asn1_implicit_sequence_to_der(0,clsdata.getData(),clsdata.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        cls.setLen(bufferlen);
    }
    
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = m_signerInfos.begin(); SignerInfo_itr != m_signerInfos.end(); SignerInfo_itr++ ) {
        FZZSignerInfo * tempSignerInfo = *SignerInfo_itr;
        if ( tempSignerInfo != NULL ) {
            FZZBytes tempSignerInfodata = tempSignerInfo->Encode();
            signerInfosdata.addData(tempSignerInfodata);
        }
    }
    
    if ( signerInfosdata.getLen() > 0 ) {
        
        if ( !signerInfos.setMaxLen(signerInfosdata.getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = signerInfos.getData();
        if ( asn1_set_to_der(signerInfosdata.getData(),signerInfosdata.getLen(),&buffer,&bufferlen) != 1 ) {
            return ret;
        }
        signerInfos.setLen(bufferlen);
    }
    
    
    retData.addData(version);
    retData.addData(digestAlgorithms);
    retData.addData(contentInfo);
    if ( certs.getLen() > 0 ) {
        retData.addData(certs);
    }
    if ( cls.getLen() > 0 ) {
        retData.addData(cls);
    }
    if ( signerInfos.getLen() > 0 ) {
        retData.addData(signerInfos);
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
bool FZZSignedData::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    const uint8_t * in_els = NULL;
    size_t in_els_len = 0;
    const uint8_t * in_els_begin = NULL;
    
    
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
    
    //digestAlgorithms
    if ((ret = asn1_set_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    
    in_els = data;
    in_els_len = datalen;
    clear_digestAlgorithms();
    while ( in_els_len > 0 ) {
        if ((ret = asn1_sequence_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
            return isTF;
        }
        uint32_t nodes[32] = {0};
        size_t nodes_count = 0;
        if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &data, &datalen)) != 1) {
            return isTF;
        }
        m_digestAlgorithms.push_back(new FZZBytes((unsigned char *)nodes,nodes_count*4));
    }
    
    //contentInfo
    if ( m_ContentInfo != NULL ) {
        delete m_ContentInfo;
        m_ContentInfo = NULL;
    }
    if ( inlen > 0 ) {
        m_ContentInfo = new FZZContentInfo(in, inlen);
        if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        
    }
    //certificates
    if ( inlen > 0 && *in == 0xA0 ) {
        if ((ret = asn1_implicit_sequence_from_der(0,&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        in_els = data;
        in_els_len = datalen;
        clear_certificates();
        while ( in_els_len > 0 ) {
            in_els_begin = in_els;
            if ((ret = asn1_sequence_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
                return isTF;
            }
            
            m_certificates.push_back(new FZZBytes(in_els_begin,in_els-in_els_begin));
        }
    }
    
    //crls
    if ( inlen > 0 && *in == 0xA0 ) {
        if ((ret = asn1_implicit_sequence_from_der(0,&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        in_els = data;
        in_els_len = datalen;
        clear_crls();
        while ( in_els_len > 0 ) {
            in_els_begin = in_els;
            if ((ret = asn1_sequence_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
                return isTF;
            }
            
            m_crls.push_back(new FZZBytes(in_els,in_els-in_els_begin));
        }
    }
    //signerInfos
    if ((ret = asn1_set_from_der(&data, &datalen, &in, &inlen)) != 1) {
        return isTF;
    }
    
    
    in_els = data;
    in_els_len = datalen;
    clear_signerInfos();
    while ( in_els_len > 0 ) {
        m_signerInfos.push_back(new FZZSignerInfo(in_els,in_els_len));
        if ((ret = asn1_sequence_from_der(&data, &datalen, &in_els, &in_els_len)) != 1) {
            return isTF;
        }
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSignedData::clear_digestAlgorithms()
{
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_digestAlgorithms.begin(); itr != m_digestAlgorithms.end(); itr++ ) {
        delete *itr;
    }
    m_digestAlgorithms.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSignedData::clear_certificates()
{
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_certificates.begin(); itr != m_certificates.end(); itr++ ) {
        delete *itr;
    }
    m_certificates.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSignedData::clear_crls()
{
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_crls.begin(); itr != m_crls.end(); itr++ ) {
        delete *itr;
    }
    m_crls.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSignedData::clear_signerInfos()
{
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = m_signerInfos.begin(); SignerInfo_itr != m_signerInfos.end(); SignerInfo_itr++ ) {
        delete *SignerInfo_itr;
    }
    m_signerInfos.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSignedData::setContentInfo(FZZContentInfo* contentInfo)
{
    if ( m_ContentInfo != NULL ) {
        delete m_ContentInfo;
        m_ContentInfo = NULL;
    }
    m_ContentInfo = new FZZContentInfo(*contentInfo);
}
//-----------------------------------------------------------------------------------------------------------------
FZZCert FZZSignedData::getCertSignCert(string issuer,FZZBytes * SerialNumber)
{
    FZZCert ret;
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_certificates.begin(); itr != m_certificates.end(); itr++ ) {
        FZZBytes* certdata = *itr;
        if (certdata == NULL) {
            continue;
        }
        FZZCert cert;
        cert.loadCert(*certdata);
        string sn = FZZConst::HexEncodeNoSpace(SerialNumber->getData(), SerialNumber->getLen());
        if ( cert.getIssuer() == issuer && cert.getSerialNumber() == sn ) {
            ret = cert;
            break;
        }
        
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
