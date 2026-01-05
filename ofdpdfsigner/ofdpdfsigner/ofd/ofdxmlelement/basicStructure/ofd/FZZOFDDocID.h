//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDDOCID_H
#define FZZOFDDOCID_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCID_Name "ofd:DocID"

class FZZOFDDocID : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocID(FZZOFDXMLFileObject * parent);
    FZZOFDDocID(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocID(const FZZOFDDocID& obj);
    virtual ~FZZOFDDocID();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDDocID();
private:
  
};

#endif //FZZOFDDOCID_H
