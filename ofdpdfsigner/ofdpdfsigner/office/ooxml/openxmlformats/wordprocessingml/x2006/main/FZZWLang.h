//
//  Created by zizheng fan on 2023/10/12
//
#ifndef FZZWLANG_H
#define FZZWLANG_H

#include "office/FZZXMLElementObject.h"

#define FZZWLANG_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLANG_Name "lang"

class FZZWLang : public FZZXMLElementObject
{
public:
    
    FZZWLang(FZZOfficeObject * parent);
    FZZWLang(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLang(const FZZWLang& obj);
    virtual ~FZZWLang();
    
public:
    void setVal(string value);
    string getVal();
    void setEastAsia(string value);
    string getEastAsia();
    void setBidi(string value);
    string getBidi();
protected:
    FZZWLang();
private:
    
    
};

#endif //FZZWLANG_H
