//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDPRINTSCREEN_H
#define FZZOFDPRINTSCREEN_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPRINTSCREEN_Name "ofd:PrintScreen"

class FZZOFDPrintScreen : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPrintScreen(FZZOFDXMLFileObject * parent);
    FZZOFDPrintScreen(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPrintScreen(const FZZOFDPrintScreen& obj);
    virtual ~FZZOFDPrintScreen();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDPrintScreen();
private:
    
};

#endif //FZZOFDPRINTSCREEN_H
