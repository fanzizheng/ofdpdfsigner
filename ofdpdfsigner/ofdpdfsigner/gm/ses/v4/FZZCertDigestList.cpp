//
//  Created by zizheng fan on 2022/11/10.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZCertDigestList.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCertDigestList******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestList::FZZCertDigestList()
{
    //DLOG("FZZCertDigestList()");
    FZZConst::addClassCount("FZZCertDigestList");
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestList::FZZCertDigestList(const unsigned char * data,size_t datalen):FZZCertDigestList()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestList::FZZCertDigestList(const FZZBytes & data):FZZCertDigestList()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestList::FZZCertDigestList(const FZZCertDigestList& obj):FZZCertDigestList()
{
    //DLOG("FZZCertInfoList(const FZZCertInfoList& obj)");
    if ( this == &obj ) {
        return;
    }
    vector<FZZCertDigestObj *>::const_iterator itr;
    for( itr = (obj.m_certdigestlist.begin()); itr != obj.m_certdigestlist.end(); itr++ ) {
        m_certdigestlist.push_back(new FZZCertDigestObj(**itr));
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZCertDigestList ::~FZZCertDigestList()
{
    //DLOG("~FZZCertDigestList()");
    FZZConst::delClassCount("FZZCertDigestList");
    vector<FZZCertDigestObj *>::const_iterator itr;
    for( itr = (m_certdigestlist.begin()); itr != m_certdigestlist.end(); itr++ ) {
        delete *itr;
    }
    m_certdigestlist.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCertDigestList::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,tempExtData;
    FZZCertDigestObj * itemExtData;
    
    vector<FZZCertDigestObj *>::const_iterator itr;
    for( itr = m_certdigestlist.begin(); itr != m_certdigestlist.end(); itr++ ) {
        itemExtData = *itr;
        
//        temp = itemExtData->Encode();
//        if ( !tempExtData.setMaxLen(temp.getLen() + 20) ) {
//            return ret;
//        }
//        bufferlen = 0;
//        buffer = tempExtData.getData();
//        if (asn1_sequence_to_der(temp.getData(),temp.getLen(),&buffer,&bufferlen) != 1) {
//            continue;
//        }
//        tempExtData.setLen(bufferlen);
        
        retData.addData(itemExtData->Encode());
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
bool FZZCertDigestList::Deccode(const unsigned char * indata,size_t inlenght)
{
    bool isTF = false;
    
    const uint8_t * in = indata;
    size_t inlen = inlenght;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    
    while( inlen > 0 ) {
        if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
            return isTF;
        }
        m_certdigestlist.push_back(new FZZCertDigestObj(data,datalen));
        
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






