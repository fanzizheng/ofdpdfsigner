//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDHIDETOOLBAR_H
#define FZZOFDHIDETOOLBAR_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDHIDETOOLBAR_Name "ofd:HideToolbar"

class FZZOFDHideToolbar : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDHideToolbar(FZZOFDXMLFileObject * parent);
    FZZOFDHideToolbar(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDHideToolbar(const FZZOFDHideToolbar& obj);
    virtual ~FZZOFDHideToolbar();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDHideToolbar();
private:
    
};

#endif //FZZOFDHIDETOOLBAR_H
