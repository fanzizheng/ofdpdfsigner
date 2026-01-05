//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNATUREMETHOD_H
#define FZZOFDSIGNATUREMETHOD_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDSIGNATUREMETHOD_Name "ofd:SignatureMethod"

class FZZOFDSignatureMethod : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSignatureMethod(FZZOFDXMLFileObject * parent);
    FZZOFDSignatureMethod(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignatureMethod(const FZZOFDSignatureMethod& obj);
    virtual ~FZZOFDSignatureMethod();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDSignatureMethod();
private:
  
};

#endif //FZZOFDSIGNATUREMETHOD_H
