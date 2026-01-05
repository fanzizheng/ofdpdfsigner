//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDABSTRACT_H
#define FZZOFDABSTRACT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDABSTRACT_Name "ofd:Abstract"

class FZZOFDAbstract : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDAbstract(FZZOFDXMLFileObject * parent);
    FZZOFDAbstract(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAbstract(const FZZOFDAbstract& obj);
    virtual ~FZZOFDAbstract();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDAbstract();
private:
  
};

#endif //FZZOFDABSTRACT_H
