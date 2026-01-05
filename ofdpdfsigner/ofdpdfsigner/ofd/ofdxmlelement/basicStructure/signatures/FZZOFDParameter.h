//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDPARAMETER_H
#define FZZOFDPARAMETER_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPARAMETER_Name "ofd:Parameter"
#define CPARAMETER_Name "Parameter"

class FZZOFDParameter : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDParameter(FZZOFDXMLFileObject * parent);
    FZZOFDParameter(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDParameter(const FZZOFDParameter& obj);
    virtual ~FZZOFDParameter();
    
public:
    void setName(string value);
    string getName();
    void setType(string value);
    string getType();
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDParameter();
private:
  
};

#endif //FZZOFDPARAMETER_H
