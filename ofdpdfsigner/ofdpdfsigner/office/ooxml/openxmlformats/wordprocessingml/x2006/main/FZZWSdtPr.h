//
//  Created by zizheng fan on 2023/11/10
//
#ifndef FZZWSDTPR_H
#define FZZWSDTPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWId.h"

#define FZZWSDTPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSDTPR_Name "sdtPr"

class FZZWSdtPr : public FZZXMLElementObject
{
public:
    
    FZZWSdtPr(FZZOfficeObject * parent);
    FZZWSdtPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSdtPr(const FZZWSdtPr& obj);
    virtual ~FZZWSdtPr();
    
public:
    FZZWRPr * setRPr();
    FZZWRPr * getRPr();
    FZZWId * setId();
    FZZWId * getId();
   
protected:
    FZZWSdtPr();
private:
    FZZWRPr * m_FZZWRPr;
    FZZWId * m_FZZWId;
};

#endif //FZZWSDTPR_H
