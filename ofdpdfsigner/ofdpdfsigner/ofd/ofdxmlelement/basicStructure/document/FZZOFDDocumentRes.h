//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDDOCUMENTRES_H
#define FZZOFDDOCUMENTRES_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCUMENTRES_Name "ofd:DocumentRes"

class FZZOFDDocumentRes : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDDocumentRes(FZZOFDXMLFileObject * parent);
    FZZOFDDocumentRes(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocumentRes(const FZZOFDDocumentRes& obj);
    virtual ~FZZOFDDocumentRes();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDDocumentRes();
private:
    
};

#endif //FZZOFDDOCUMENTRES_H
