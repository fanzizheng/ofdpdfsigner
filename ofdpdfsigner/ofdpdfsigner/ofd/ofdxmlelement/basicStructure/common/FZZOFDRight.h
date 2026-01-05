//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDRIGHT_H
#define FZZOFDRIGHT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDRIGHT_Name "ofd:Right"

class FZZOFDRight : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDRight(FZZOFDXMLFileObject * parent);
    FZZOFDRight(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDRight(const FZZOFDRight& obj);
    virtual ~FZZOFDRight();
    
public:
    void setValue(double value);
    double getValue();
    
    
protected:
    FZZOFDRight();
private:
    
};

#endif //FZZOFDRIGHT_H
