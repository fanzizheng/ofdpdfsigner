//
//  Created by zizheng fan on 2023/11/14
//
#ifndef FZZWCR_H
#define FZZWCR_H

#include "office/FZZXMLElementObject.h"

#define FZZWCR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCR_Name "cr"

class FZZWCr : public FZZXMLElementObject
{
public:
    
    FZZWCr(FZZOfficeObject * parent);
    FZZWCr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWCr(const FZZWCr& obj);
    virtual ~FZZWCr();
    
public:
//    void setVal(string value);
//    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWCr();
private:
    
    
};

#endif //FZZWCR_H
