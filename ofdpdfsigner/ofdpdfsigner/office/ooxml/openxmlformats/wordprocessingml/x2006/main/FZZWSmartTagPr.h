//
//  Created by zizheng fan on 2023/11/28
//
#ifndef FZZWSMARTTAGPR_H
#define FZZWSMARTTAGPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAttr.h"

#define FZZWSMARTTAGPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSMARTTAGPR_Name "smartTagPr"

class FZZWSmartTagPr : public FZZXMLElementObject
{
public:
    
    FZZWSmartTagPr(FZZOfficeObject * parent);
    FZZWSmartTagPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSmartTagPr(const FZZWSmartTagPr& obj);
    virtual ~FZZWSmartTagPr();
    
public:
    FZZWAttr * addAttr();
    vector<FZZWAttr*> * getAttrList();
protected:
    FZZWSmartTagPr();
private:
    vector<FZZWAttr *> m_FZZWAttrList;
    
};

#endif //FZZWSMARTTAGPR_H
