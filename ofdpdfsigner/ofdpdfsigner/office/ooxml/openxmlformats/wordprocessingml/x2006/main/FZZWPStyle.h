//
//  Created by zizheng fan on 2023/11/09
//
#ifndef FZZWPSTYLE_H
#define FZZWPSTYLE_H

#include "office/FZZXMLElementObject.h"

#define FZZWPSTYLE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPSTYLE_Name "pStyle"

class FZZWPStyle : public FZZXMLElementObject
{
public:
    
    FZZWPStyle(FZZOfficeObject * parent);
    FZZWPStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPStyle(const FZZWPStyle& obj);
    virtual ~FZZWPStyle();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWPStyle();
private:
    
    
};

#endif //FZZWPSTYLE_H
