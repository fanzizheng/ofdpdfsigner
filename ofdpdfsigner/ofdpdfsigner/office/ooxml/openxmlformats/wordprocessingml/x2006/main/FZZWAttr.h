//
//  Created by zizheng fan on 2023/11/29
//
#ifndef FZZWATTR_H
#define FZZWATTR_H

#include "office/FZZXMLElementObject.h"

#define FZZWATTR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWATTR_Name "attr"

class FZZWAttr : public FZZXMLElementObject
{
public:
    
    FZZWAttr(FZZOfficeObject * parent);
    FZZWAttr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWAttr(const FZZWAttr& obj);
    virtual ~FZZWAttr();
    
public:
    void setName(string value);
    string getName();
    void setVal(string value);
    string getVal();
protected:
    FZZWAttr();
private:
    
    
};

#endif //FZZWATTR_H
