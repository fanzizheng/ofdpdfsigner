//
//  Created by zizheng fan on 2024/10/16.
//
#ifndef FZZOFDUSERINFO_H
#define FZZOFDUSERINFO_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDUserInfoItem.h"


#define FZZOFDUSERINFO_Name "ofd:UserInfo"

class FZZOFDUserInfo : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDUserInfo(FZZOFDXMLFileObject * parent);
    FZZOFDUserInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDUserInfo(const FZZOFDUserInfo& obj);
    virtual ~FZZOFDUserInfo();
    
public:
    
    void setUserName(string value);
    string getUserName();
    void setUserType(string value);
    string getUserType();
    
    FZZOFDUserInfoItem * setUserCert();
    FZZOFDUserInfoItem * getUserCert();
    FZZOFDUserInfoItem * setEncryptedWK();
    FZZOFDUserInfoItem * getEncryptedWK();
    FZZOFDUserInfoItem * setIVValue();
    FZZOFDUserInfoItem * getIVValue();
    
protected:
    FZZOFDUserInfo();
private:
    FZZOFDUserInfoItem * m_UserCert;
    FZZOFDUserInfoItem * m_EncryptedWK;
    FZZOFDUserInfoItem * m_IVValue;
    
};

#endif //FZZOFDUSERINFO_H
