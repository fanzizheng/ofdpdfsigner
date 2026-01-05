//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNATUREDATETIME_H
#define FZZOFDSIGNATUREDATETIME_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDSIGNATUREDATETIME_Name "ofd:SignatureDateTime"

class FZZOFDSignatureDateTime : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSignatureDateTime(FZZOFDXMLFileObject * parent);
    FZZOFDSignatureDateTime(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignatureDateTime(const FZZOFDSignatureDateTime& obj);
    virtual ~FZZOFDSignatureDateTime();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDSignatureDateTime();
private:
  
};

#endif //FZZOFDSIGNATUREDATETIME_H
