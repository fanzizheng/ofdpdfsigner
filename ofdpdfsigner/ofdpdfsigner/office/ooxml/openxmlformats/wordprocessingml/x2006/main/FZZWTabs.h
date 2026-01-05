//
//  Created by zizheng fan on 2023/11/16
//
#ifndef FZZWTABS_H
#define FZZWTABS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTab.h"

#define FZZWTABS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTABS_Name "tabs"

class FZZWTabs : public FZZXMLElementObject
{
public:
    
    FZZWTabs(FZZOfficeObject * parent);
    FZZWTabs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTabs(const FZZWTabs& obj);
    virtual ~FZZWTabs();
    
public:
//    void setVal(string value);
//    string getVal();
    
//    void setValue(string value);
//    string getValue();
    FZZWTab * addTab();
    vector<FZZWTab*> * getTabs();
    
protected:
    FZZWTabs();
private:
    
    vector<FZZWTab*> m_FZZWTabs;
};

#endif //FZZWTABS_H
