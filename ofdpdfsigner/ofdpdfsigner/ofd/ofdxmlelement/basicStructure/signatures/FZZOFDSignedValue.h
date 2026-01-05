//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNEDVALUE_H
#define FZZOFDSIGNEDVALUE_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDSIGNEDVALUE_Name "ofd:SignedValue"

class FZZOFDSignedValue : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSignedValue(FZZOFDXMLFileObject * parent);
    FZZOFDSignedValue(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignedValue(const FZZOFDSignedValue& obj);
    virtual ~FZZOFDSignedValue();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDSignedValue();
private:
  
};

#endif //FZZOFDSIGNEDVALUE_H
