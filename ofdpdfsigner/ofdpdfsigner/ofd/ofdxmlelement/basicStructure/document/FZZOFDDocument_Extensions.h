//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDOCUMENT_EXTENSIONS_H
#define FZZOFDDOCUMENT_EXTENSIONS_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCUMENT_EXTENSIONS_Name "ofd:Extensions"

class FZZOFDDocument_Extensions : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocument_Extensions(FZZOFDXMLFileObject * parent);
    FZZOFDDocument_Extensions(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocument_Extensions(const FZZOFDDocument_Extensions& obj);
    virtual ~FZZOFDDocument_Extensions();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDDocument_Extensions();
private:
    
};

#endif //FZZOFDDOCUMENT_EXTENSIONS_H
