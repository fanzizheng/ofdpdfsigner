//
//  Created by zizheng fan on 2022/11/12.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZSES_CertList.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_CertList******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList::FZZSES_CertList() : m_certs(NULL),m_certDigestList(NULL)
{
    //DLOG("FZZSES_CertList()");
    FZZConst::addClassCount("FZZSES_CertList");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList::FZZSES_CertList(uint32_t type,const unsigned char * data,size_t datalen):FZZSES_CertList()
{
    Deccode(type,data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList::FZZSES_CertList(uint32_t type,const FZZBytes & data):FZZSES_CertList()
{
    Deccode(type,data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList::FZZSES_CertList(FZZCertInfoList * certs) :FZZSES_CertList()
{
    m_certs = new FZZCertInfoList(*certs);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList::FZZSES_CertList(FZZCertDigestList * certDigestList) : FZZSES_CertList()
{
    m_certDigestList = new FZZCertDigestList(*certDigestList);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList::FZZSES_CertList(const FZZSES_CertList& obj):FZZSES_CertList()
{
    //DLOG("FZZSES_CertList(const FZZSES_CertList& obj)");
    if ( this == &obj ) {
        return;
    }
    m_certs = obj.m_certs == NULL ? NULL : new FZZCertInfoList(*obj.m_certs);
    m_certDigestList = obj.m_certDigestList == NULL ? NULL : new FZZCertDigestList(*obj.m_certDigestList);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSES_CertList ::~FZZSES_CertList()
{
    //DLOG("~FZZSES_CertList()");
    FZZConst::delClassCount("FZZSES_CertList");
    if ( m_certs != NULL ) {
        delete m_certs;
        m_certs = NULL;
    }
    
    if ( m_certDigestList != NULL ) {
        delete m_certDigestList;
        m_certDigestList = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZSES_CertList::Encode()
{
    FZZBytes retData;
    
    if ( m_certs != NULL ) {
        retData = m_certs->Encode();
    } else if ( m_certDigestList != NULL ) {
        retData = m_certDigestList->Encode();
    }
    
    return retData;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZSES_CertList::Deccode(uint32_t type,const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
//    const uint8_t * in = indata;
//    size_t inlen = inlenght;
//    const uint8_t * data = NULL;
//    size_t datalen = 0;
//    
//    int ret = 0;
    
//    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
//        return isTF;
//    }
    
    if ( type == 1) {
        m_certs = new FZZCertInfoList(indata,inlenght);
        //---------test begin --------
//        FZZBytes bb = m_certs->Encode();
//        DLOG("m_certs : %s",FZZConst::HexEncode(bb.getData(), bb.getLen()).c_str());
        //---------test end ----------
        
    } else if ( type == 2 ) {
        m_certDigestList = new FZZCertDigestList(indata,inlenght);
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






