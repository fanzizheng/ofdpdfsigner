//
//  Created by zizheng fan on 2024/10/17.
//
#ifndef FZZOFDENCPARAMETER_H
#define FZZOFDENCPARAMETER_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDENCPARAMETER_Name "ofd:Parameter"

class FZZOFDEncParameter : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDEncParameter(FZZOFDXMLFileObject * parent);
    FZZOFDEncParameter(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEncParameter(const FZZOFDEncParameter& obj);
    virtual ~FZZOFDEncParameter();
    
public:
    void setName(string value);
    string getName();
    void setValue(string value);
    string getValue();
  
    
protected:
    FZZOFDEncParameter();
private:
    
};

#endif //FZZOFDENCPARAMETER_H
