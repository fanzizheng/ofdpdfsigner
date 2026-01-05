//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDHIDEMENUBAR_H
#define FZZOFDHIDEMENUBAR_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDHIDEMENUBAR_Name "ofd:HideMenubar"

class FZZOFDHideMenubar : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDHideMenubar(FZZOFDXMLFileObject * parent);
    FZZOFDHideMenubar(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDHideMenubar(const FZZOFDHideMenubar& obj);
    virtual ~FZZOFDHideMenubar();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDHideMenubar();
private:
    
};

#endif //FZZOFDHIDEMENUBAR_H
