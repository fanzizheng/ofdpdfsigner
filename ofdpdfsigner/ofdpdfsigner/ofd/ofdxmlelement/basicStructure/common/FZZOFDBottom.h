//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDBOTTOM_H
#define FZZOFDBOTTOM_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDBOTTOM_Name "ofd:Bottom"

class FZZOFDBottom : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDBottom(FZZOFDXMLFileObject * parent);
    FZZOFDBottom(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDBottom(const FZZOFDBottom& obj);
    virtual ~FZZOFDBottom();
    
public:
    void setValue(double value);
    double getValue();
    
    
protected:
    FZZOFDBottom();
private:
    
};

#endif //FZZOFDBOTTOM_H
