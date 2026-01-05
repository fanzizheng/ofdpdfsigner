//
//  Created by zizheng fan on 2023/11/28
//
#ifndef FZZWSMARTTAG_H
#define FZZWSMARTTAG_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSmartTagPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWR.h"

#define FZZWSMARTTAG_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSMARTTAG_Name "smartTag"

class FZZWSmartTag : public FZZXMLElementObject
{
public:
    
    FZZWSmartTag(FZZOfficeObject * parent);
    FZZWSmartTag(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSmartTag(const FZZWSmartTag& obj);
    virtual ~FZZWSmartTag();
    
public:
    FZZWSmartTagPr * setSmartTagPr();
    FZZWSmartTagPr * getSmartTagPr();
    FZZWR * addR();
    vector<FZZWR*> * getRList();
    
protected:
    FZZWSmartTag();
private:
    FZZWSmartTagPr * m_FZZWSmartTagPr;
    vector<FZZWR*> m_FZZWRs;
};

#endif //FZZWSMARTTAG_H
