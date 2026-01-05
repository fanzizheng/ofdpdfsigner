//
//  Created by zizheng fan on 2023/11/13
//
#ifndef FZZWRSTYLE_H
#define FZZWRSTYLE_H

#include "office/FZZXMLElementObject.h"

#define FZZWRSTYLE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRSTYLE_Name "rStyle"

class FZZWRStyle : public FZZXMLElementObject
{
public:
    
    FZZWRStyle(FZZOfficeObject * parent);
    FZZWRStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRStyle(const FZZWRStyle& obj);
    virtual ~FZZWRStyle();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWRStyle();
private:
    
    
};

#endif //FZZWRSTYLE_H
