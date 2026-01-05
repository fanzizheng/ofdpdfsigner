//
//  Created by zizheng fan on 2023/11/01
//
#ifndef FZZWTAB_H
#define FZZWTAB_H

#include "office/FZZXMLElementObject.h"

#define FZZWTAB_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTAB_Name "tab"
//Tab key on keyboard
class FZZWTab : public FZZXMLElementObject
{
public:
    
    FZZWTab(FZZOfficeObject * parent);
    FZZWTab(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTab(const FZZWTab& obj);
    virtual ~FZZWTab();
    
public:
    void setVal(string value);
    string getVal();
    void setPos(string value);
    string getPos();
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTab();
private:
    
    
};

#endif //FZZWTAB_H
