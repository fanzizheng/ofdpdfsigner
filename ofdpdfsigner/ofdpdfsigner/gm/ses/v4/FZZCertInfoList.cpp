//
//  Created by zizheng fan on 2022/11/12.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZCertInfoList.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCertInfoList******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZCertInfoList::FZZCertInfoList()
{
    //DLOG("FZZCertInfoList()");
    FZZConst::addClassCount("FZZCertInfoList");
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertInfoList::FZZCertInfoList(const unsigned char * data,size_t datalen):FZZCertInfoList()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertInfoList::FZZCertInfoList(const FZZBytes & data):FZZCertInfoList()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZCertInfoList::FZZCertInfoList(const FZZCertInfoList& obj):FZZCertInfoList()
{
    //DLOG("FZZCertInfoList(const FZZCertInfoList& obj)");
    if ( this == &obj ) {
        return;
    }
    vector<FZZBytes *>::const_iterator itr;
    for( itr = (obj.m_certinfolist.begin()); itr != obj.m_certinfolist.end(); itr++ ) {
        m_certinfolist.push_back(new FZZBytes(**itr));
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertInfoList ::~FZZCertInfoList()
{
    //DLOG("~FZZCertInfoList()");
    FZZConst::delClassCount("FZZCertInfoList");
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_certinfolist.begin(); itr != m_certinfolist.end(); itr++ ) {
        delete *itr;
    }
    m_certinfolist.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCertInfoList::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes tempCert;
    FZZBytes * itemCert;
    
    vector<FZZBytes *>::const_iterator itr;
    for( itr = m_certinfolist.begin(); itr != m_certinfolist.end(); itr++ ) {
        itemCert = *itr;
        
        if ( !tempCert.setMaxLen(itemCert->getLen() + 20) ) {
            return ret;
        }
        bufferlen = 0;
        buffer = tempCert.getData();
        if ( asn1_octet_string_to_der(itemCert->getData(),itemCert->getLen(),&buffer,&bufferlen) != 1 ) {
            continue;
        }
        tempCert.setLen(bufferlen);
        
        retData.addData(tempCert);
        
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
bool FZZCertInfoList::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
    while( inlen > 0 ) {
        if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        m_certinfolist.push_back(new FZZBytes(data,datalen));
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






