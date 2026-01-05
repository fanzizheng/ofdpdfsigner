//
//  Created by zizheng fan on 2022/11/14.
//
#include "basic/FZZConst.h"
#include "gm/ses/v4/FZZExtensionDatas.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSES_SealInfo_V4******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZExtensionDatas::FZZExtensionDatas()
{
    //DLOG("FZZExtensionDatas()");
    FZZConst::addClassCount("FZZExtensionDatas");
}
//-----------------------------------------------------------------------------------------------------------------
FZZExtensionDatas::FZZExtensionDatas(const unsigned char * data,size_t datalen):FZZExtensionDatas()
{
    Deccode(data,datalen);
}
//-----------------------------------------------------------------------------------------------------------------
FZZExtensionDatas::FZZExtensionDatas(const FZZBytes & data):FZZExtensionDatas()
{
    Deccode(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZExtensionDatas::FZZExtensionDatas(const FZZExtensionDatas& obj):FZZExtensionDatas()
{
    //DLOG("FZZExtensionDatas(const FZZExtensionDatas& obj)");
    if ( this == &obj ) {
        return;
    }
    vector<FZZExtData *>::const_iterator itr;
    for( itr = (obj.m_ExtDatalist.begin()); itr != obj.m_ExtDatalist.end(); itr++ ) {
        m_ExtDatalist.push_back(new FZZExtData(**itr));
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZExtensionDatas ::~FZZExtensionDatas()
{
    //DLOG("~FZZExtensionDatas()");
    FZZConst::delClassCount("FZZExtensionDatas");
    vector<FZZExtData *>::const_iterator itr;
    for( itr = (m_ExtDatalist.begin()); itr != m_ExtDatalist.end(); itr++ ) {
        delete *itr;
    }
    m_ExtDatalist.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZExtensionDatas::Encode()
{
    FZZBytes ret;
    FZZBytes retData;
    
    unsigned char * buffer = NULL;
    size_t bufferlen =0;
    
    FZZBytes temp,tempExtData;
    FZZExtData * itemExtData;
    
    vector<FZZExtData *>::const_iterator itr;
    for( itr = m_ExtDatalist.begin(); itr != m_ExtDatalist.end(); itr++ ) {
        itemExtData = *itr;
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
bool FZZExtensionDatas::Deccode(const unsigned char * indata,size_t inlenght)
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
        m_ExtDatalist.push_back(new FZZExtData(data,datalen));
    }
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------






