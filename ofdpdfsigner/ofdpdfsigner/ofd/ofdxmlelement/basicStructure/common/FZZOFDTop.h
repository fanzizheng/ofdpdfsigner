//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDTOP_H
#define FZZOFDTOP_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDTOP_Name "ofd:Top"

class FZZOFDTop : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDTop(FZZOFDXMLFileObject * parent);
    FZZOFDTop(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTop(const FZZOFDTop& obj);
    virtual ~FZZOFDTop();
    
public:
    void setValue(double value);
    double getValue();
    
    
protected:
    FZZOFDTop();
private:
    
};

#endif //FZZOFDTOP_H
