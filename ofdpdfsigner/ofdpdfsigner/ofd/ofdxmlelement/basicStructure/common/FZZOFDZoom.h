//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDZOOM_H
#define FZZOFDZOOM_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDZOOM_Name "ofd:Zoom"

class FZZOFDZoom : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDZoom(FZZOFDXMLFileObject * parent);
    FZZOFDZoom(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDZoom(const FZZOFDZoom& obj);
    virtual ~FZZOFDZoom();
    
public:
    void setValue(double value);
    double getValue();
    
    
protected:
    FZZOFDZoom();
private:
    
};

#endif //FZZOFDLEFT_H
