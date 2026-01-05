//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDHIDEWINDOWUI_H
#define FZZOFDHIDEWINDOWUI_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDHIDEWINDOWUI_Name "ofd:HideWindowUI"

class FZZOFDHideWindowUI : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDHideWindowUI(FZZOFDXMLFileObject * parent);
    FZZOFDHideWindowUI(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDHideWindowUI(const FZZOFDHideWindowUI& obj);
    virtual ~FZZOFDHideWindowUI();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDHideWindowUI();
private:
    
};

#endif //FZZOFDHIDEWINDOWUI_H
