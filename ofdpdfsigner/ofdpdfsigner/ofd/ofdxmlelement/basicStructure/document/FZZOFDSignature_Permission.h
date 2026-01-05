//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDSIGNATURE_PERMISSION_H
#define FZZOFDSIGNATURE_PERMISSION_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDSIGNATURE_PERMISSION_Name "ofd:Signature"

class FZZOFDSignature_Permission : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDSignature_Permission(FZZOFDXMLFileObject * parent);
    FZZOFDSignature_Permission(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignature_Permission(const FZZOFDSignature_Permission& obj);
    virtual ~FZZOFDSignature_Permission();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDSignature_Permission();
private:
    
};

#endif //FZZOFDSIGNATURE_PERMISSION_H
