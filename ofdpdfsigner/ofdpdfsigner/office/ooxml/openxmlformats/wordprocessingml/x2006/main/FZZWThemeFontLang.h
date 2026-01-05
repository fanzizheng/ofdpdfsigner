//
//  Created by zizheng fan on 2023/09/26
//
#ifndef FZZWTHEMEFONTLANG_H
#define FZZWTHEMEFONTLANG_H

#include "office/FZZXMLElementObject.h"

#define FZZWTHEMEFONTLANG_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTHEMEFONTLANG_Name "themeFontLang"

class FZZWThemeFontLang : public FZZXMLElementObject
{
public:
    
    FZZWThemeFontLang(FZZOfficeObject * parent);
    FZZWThemeFontLang(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWThemeFontLang(const FZZWThemeFontLang& obj);
    virtual ~FZZWThemeFontLang();
    
public:
    void setVal(string value);
    string getVal();
    void setEastAsia(string value);
    string getEastAsia();
protected:
    FZZWThemeFontLang();
private:
    
    
};

#endif //FZZWTHEMEFONTLANG_H
