//
//  Created by zizheng fan on 2023/10/30
//
#ifndef FZZWCOLOR_H
#define FZZWCOLOR_H

#include "office/FZZXMLElementObject.h"

#define FZZWCOLOR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCOLOR_Name "color"

class FZZWColor : public FZZXMLElementObject
{
public:
    
    FZZWColor(FZZOfficeObject * parent);
    FZZWColor(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWColor(const FZZWColor& obj);
    virtual ~FZZWColor();
    
public:
    void setVal(string value);
    string getVal();
    
    
protected:
    FZZWColor();
private:
    
    
};

#endif //FZZWCOLOR_H
