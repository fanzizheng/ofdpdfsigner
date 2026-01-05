//
//  Created by zizheng fan on 2024/09/25.
//
#ifndef FZZOFDSIGNEDVALUELOC_H
#define FZZOFDSIGNEDVALUELOC_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDSIGNEDVALUELOC_Name "ofd:SignedValueLoc"

class FZZOFDSignedValueLoc : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSignedValueLoc(FZZOFDXMLFileObject * parent);
    FZZOFDSignedValueLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignedValueLoc(const FZZOFDSignedValueLoc& obj);
    virtual ~FZZOFDSignedValueLoc();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDSignedValueLoc();
private:
    
};

#endif //FZZOFDSIGNEDVALUELOC_H
