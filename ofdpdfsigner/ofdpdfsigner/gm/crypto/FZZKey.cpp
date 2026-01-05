//
//  Created by zizheng fan on 2022/10/27.
//
#include "basic/FZZConst.h"
#include "gm/crypto/FZZKey.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZKey******************************************************/
//-----------------------------------------------------------------------------------------------------------------
const string FZZKey::KEYTYPE_SM2_PUB_KEY = "SM2_Public";
const string FZZKey::KEYTYPE_SM2_PRI_KEY = "SM2_Private";
const string FZZKey::KEYTYPE_SM1 = "SM1";
const string FZZKey::KEYTYPE_SM4 = "SM4";
const string FZZKey::KEYTYPE_SM2_PUB_KEY_ID = "SM2_Public_ID";
const string FZZKey::KEYTYPE_SM2_PRI_KEY_ID = "SM2_Private_ID";
const string FZZKey::KEYTYPE_SM1_ID = "SM1_ID";
const string FZZKey::KEYTYPE_SM4_ID = "SM4_ID";

//-----------------------------------------------------------------------------------------------------------------
FZZKey::FZZKey()
{
    //DLOG("FZZKey()");
    FZZConst::addClassCount("FZZKey");
   
}
//-----------------------------------------------------------------------------------------------------------------
FZZKey::FZZKey(string keytype,string keyid,const unsigned char * const data,int len) :FZZKey()
{
    setKeyData(data,len);
    setKeyID(keyid);
    setKeyType(keytype);
}
//-----------------------------------------------------------------------------------------------------------------
FZZKey::FZZKey(const FZZKey& obj):FZZKey()
{
    //DLOG("FZZKey(const FZZKey& obj)");
    if ( this == &obj ) {
        return;
    }
    m_KeyType = obj.m_KeyType;
    m_KeyID = obj.m_KeyID;
    m_KeyData = obj.m_KeyData;
}
//-----------------------------------------------------------------------------------------------------------------
FZZKey::~FZZKey()
{
    //DLOG("~FZZKey()");
    FZZConst::delClassCount("FZZKey");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
const FZZKey& FZZKey::operator=(const FZZKey& data)
{
    if ( this == &data ) {
        return *this;
    }
    m_KeyType = data.m_KeyType;
    m_KeyID = data.m_KeyID;
    m_KeyData = data.m_KeyData;
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZKey::clear()
{
    m_KeyType = "";
    m_KeyID = "";
    m_KeyData.clear();
}
//-----------------------------------------------------------------------------------------------------------------




