//
//  Created by zizheng fan on 2024/10/17.
//
#ifndef FZZOFDUSERINFOITEM_H
#define FZZOFDUSERINFOITEM_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDUSERINFOITEM_USERCERT_Name "ofd:UserCert"
#define FZZOFDUSERINFOITEM_ENCRYPTEDWK_Name "ofd:EncryptedWK"
#define FZZOFDUSERINFOITEM_IVVALUE_Name "ofd:IVValue"

class FZZOFDUserInfoItem : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDUserInfoItem(FZZOFDXMLFileObject * parent);
    FZZOFDUserInfoItem(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDUserInfoItem(const FZZOFDUserInfoItem& obj);
    virtual ~FZZOFDUserInfoItem();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDUserInfoItem();
private:
    
};

#endif //FZZOFDUSERINFOITEM_H
