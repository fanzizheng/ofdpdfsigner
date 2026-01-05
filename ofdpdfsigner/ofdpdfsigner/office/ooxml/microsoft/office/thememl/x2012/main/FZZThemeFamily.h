//
//  Created by zizheng fan on 2023/05/10.
//
#ifndef FZZTHEMEFAMILY_H
#define FZZTHEMEFAMILY_H

#include "office/FZZXMLElementObject.h"

#define FZZTHEMEFAMILY_Find_Key "schemas.microsoft.com/office/thememl/2012/main"

#define FZZTHEMEFAMILY_Name "thm15:themeFamily"

class FZZThemeFamily : public FZZXMLElementObject
{
public:
    
    FZZThemeFamily(FZZOfficeObject * parent);
    FZZThemeFamily(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZThemeFamily(const FZZThemeFamily& obj);
    virtual ~FZZThemeFamily();
    
public:
    
protected:
    FZZThemeFamily();
private:
    
    
};

#endif //FZZTHEMEFAMILY_H
