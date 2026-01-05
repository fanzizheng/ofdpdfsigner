//
//  Created by zizheng fan on 2023/10/30
//
#ifndef FZZWALLOWPNG_H
#define FZZWALLOWPNG_H

#include "office/FZZXMLElementObject.h"

#define FZZWALLOWPNG_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWALLOWPNG_Name "allowPNG"

class FZZWAllowPNG : public FZZXMLElementObject
{
public:
    
    FZZWAllowPNG(FZZOfficeObject * parent);
    FZZWAllowPNG(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWAllowPNG(const FZZWAllowPNG& obj);
    virtual ~FZZWAllowPNG();
    
public:
    
protected:
    FZZWAllowPNG();
private:
    
    
};

#endif //FZZWALLOWPNG_H
