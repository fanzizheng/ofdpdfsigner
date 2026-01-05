//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDLEFT_H
#define FZZOFDLEFT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDLEFT_Name "ofd:Left"

class FZZOFDLeft : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDLeft(FZZOFDXMLFileObject * parent);
    FZZOFDLeft(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDLeft(const FZZOFDLeft& obj);
    virtual ~FZZOFDLeft();
    
public:
    void setValue(double value);
    double getValue();
    
    
protected:
    FZZOFDLeft();
private:
    
};

#endif //FZZOFDLEFT_H
