//
//  Created by zizheng fan on 2024/10/16.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDUserInfo.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDUserInfo**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfo::FZZOFDUserInfo() : FZZOFDXMLElementObject(),m_UserCert(NULL),m_EncryptedWK(NULL),m_IVValue(NULL)
{
    //DLOG("FZZOFDUserInfo()");
    FZZConst::addClassCount("FZZOFDUserInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfo::FZZOFDUserInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false),m_UserCert(NULL),m_EncryptedWK(NULL),m_IVValue(NULL)
{
    
    FZZConst::addClassCount("FZZOFDUserInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfo::FZZOFDUserInfo(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_UserCert(NULL),m_EncryptedWK(NULL),m_IVValue(NULL)
{
    FZZConst::addClassCount("FZZOFDUserInfo");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfo::FZZOFDUserInfo(const FZZOFDUserInfo& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDUserInfo");
    if ( this == &obj ) {
        return;
    }
    
    m_UserCert = obj.m_UserCert != NULL ? new FZZOFDUserInfoItem(*obj.m_UserCert) : NULL;
    m_EncryptedWK = obj.m_EncryptedWK != NULL ? new FZZOFDUserInfoItem(*obj.m_EncryptedWK) : NULL;
    m_IVValue = obj.m_IVValue != NULL ? new FZZOFDUserInfoItem(*obj.m_IVValue) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfo::~FZZOFDUserInfo()
{
    //DLOG("~FZZOFDUserInfo()");
    FZZConst::delClassCount("FZZOFDUserInfo");
    
    if ( m_UserCert != NULL ) {
        delete m_UserCert;
        m_UserCert = NULL;
    }
    
    if ( m_EncryptedWK != NULL ) {
        delete m_EncryptedWK;
        m_EncryptedWK = NULL;
    }
    
    if ( m_IVValue != NULL ) {
        delete m_IVValue;
        m_IVValue = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDUserInfo::setUserName(string value)
{
    setAttribute_String("UserName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserInfo::getUserName()
{
    return getAttribute_String("UserName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDUserInfo::setUserType(string value)
{
    setAttribute_String("UserType",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserInfo::getUserType()
{
    return getAttribute_String("UserType");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem * FZZOFDUserInfo::setUserCert()
{
    return m_UserCert = setElementObject(m_UserCert,FZZOFDUSERINFOITEM_USERCERT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem * FZZOFDUserInfo::getUserCert()
{
    return m_UserCert = getElementObject(m_UserCert,FZZOFDUSERINFOITEM_USERCERT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem * FZZOFDUserInfo::setEncryptedWK()
{
    return m_EncryptedWK = setElementObject(m_EncryptedWK,FZZOFDUSERINFOITEM_ENCRYPTEDWK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem * FZZOFDUserInfo::getEncryptedWK()
{
    return m_EncryptedWK = getElementObject(m_EncryptedWK,FZZOFDUSERINFOITEM_ENCRYPTEDWK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem * FZZOFDUserInfo::setIVValue()
{
    return m_IVValue = setElementObject(m_IVValue,FZZOFDUSERINFOITEM_IVVALUE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem * FZZOFDUserInfo::getIVValue()
{
    return m_IVValue = getElementObject(m_IVValue,FZZOFDUSERINFOITEM_IVVALUE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
