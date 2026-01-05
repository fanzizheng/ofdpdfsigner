//
//  Created by zizheng fan on 2023/11/22
//
#ifndef FZZWTMPL_H
#define FZZWTMPL_H

#include "office/FZZXMLElementObject.h"

#define FZZWTMPL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTMPL_Name "tmpl"

class FZZWTmpl : public FZZXMLElementObject
{
public:
    
    FZZWTmpl(FZZOfficeObject * parent);
    FZZWTmpl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTmpl(const FZZWTmpl& obj);
    virtual ~FZZWTmpl();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTmpl();
private:
    
    
};

#endif //FZZWTMPL_H
