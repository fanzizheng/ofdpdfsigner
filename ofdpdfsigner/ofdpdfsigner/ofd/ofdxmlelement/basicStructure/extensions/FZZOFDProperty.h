//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDPROPERTY_H
#define FZZOFDPROPERTY_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPROPERTY_Name "ofd:Property"

class FZZOFDProperty : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDProperty(FZZOFDXMLFileObject * parent);
    FZZOFDProperty(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDProperty(const FZZOFDProperty& obj);
    virtual ~FZZOFDProperty();
    
public:
    void setName(string value);
    string getName();
    void setType(string value);
    string getType();
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDProperty();
private:
    
};

#endif //FZZOFDPROPERTY_H
