//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDDOCBODY_SIGNATURES_H
#define FZZOFDDOCBODY_SIGNATURES_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCBODY_SIGNATURES_Name "ofd:Signatures"

class FZZOFDDocBody_Signatures : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocBody_Signatures(FZZOFDXMLFileObject * parent);
    FZZOFDDocBody_Signatures(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocBody_Signatures(const FZZOFDDocBody_Signatures& obj);
    virtual ~FZZOFDDocBody_Signatures();
    
public:
    void setValue(string value);
    string getValue();
protected:
    FZZOFDDocBody_Signatures();
private:
    
    
};

#endif //FZZOFDDOCBODY_SIGNATURES_H
