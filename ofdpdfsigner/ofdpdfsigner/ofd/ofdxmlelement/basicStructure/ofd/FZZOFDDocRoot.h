//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDDOCROOT_H
#define FZZOFDDOCROOT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCROOT_Name "ofd:DocRoot"

class FZZOFDDocRoot : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocRoot(FZZOFDXMLFileObject * parent);
    FZZOFDDocRoot(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocRoot(const FZZOFDDocRoot& obj);
    virtual ~FZZOFDDocRoot();
    
public:
    void setValue(string value);
    string getValue();
protected:
    FZZOFDDocRoot();
private:
    
    
};

#endif //FZZOFDDOCROOT_H
