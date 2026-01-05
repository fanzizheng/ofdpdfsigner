//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDCHECKVALUE_H
#define FZZOFDCHECKVALUE_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDCHECKVALUE_Name "ofd:CheckValue"

class FZZOFDCheckValue : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDCheckValue(FZZOFDXMLFileObject * parent);
    FZZOFDCheckValue(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCheckValue(const FZZOFDCheckValue& obj);
    virtual ~FZZOFDCheckValue();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDCheckValue();
private:
  
};

#endif //FZZOFDCHECKVALUE_H
