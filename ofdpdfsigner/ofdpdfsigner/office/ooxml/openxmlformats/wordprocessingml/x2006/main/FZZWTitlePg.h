//
//  Created by zizheng fan on 2024/02/07
//
#ifndef FZZWTITLEPG_H
#define FZZWTITLEPG_H

#include "office/FZZXMLElementObject.h"

#define FZZWTITLEPG_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTITLEPG_Name "titlePg"

class FZZWTitlePg : public FZZXMLElementObject
{
public:
    
    FZZWTitlePg(FZZOfficeObject * parent);
    FZZWTitlePg(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTitlePg(const FZZWTitlePg& obj);
    virtual ~FZZWTitlePg();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWTitlePg();
private:
    
    
};

#endif //FZZWTITLEPG_H
