//
//  Created by zizheng fan on 2023/08/01
//
#ifndef FZZASHADE_H
#define FZZASHADE_H

#include "office/FZZXMLElementObject.h"

#define FZZASHADE_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZASHADE_Name "shade"

class FZZAshade : public FZZXMLElementObject
{
public:
    
    FZZAshade(FZZOfficeObject * parent);
    FZZAshade(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAshade(const FZZAshade& obj);
    virtual ~FZZAshade();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZAshade();
private:
    
    
};

#endif //FZZASHADE_H
