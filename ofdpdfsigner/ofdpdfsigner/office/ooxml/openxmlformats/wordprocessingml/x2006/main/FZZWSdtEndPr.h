//
//  Created by zizheng fan on 2023/11/10
//
#ifndef FZZWSDTENDPR_H
#define FZZWSDTENDPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"

#define FZZWSDTENDPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSDTENDPR_Name "sdtEndPr"

class FZZWSdtEndPr : public FZZXMLElementObject
{
public:
    
    FZZWSdtEndPr(FZZOfficeObject * parent);
    FZZWSdtEndPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSdtEndPr(const FZZWSdtEndPr& obj);
    virtual ~FZZWSdtEndPr();
    
public:
    FZZWRPr * setRPr();
    FZZWRPr * getRPr();
   
protected:
    FZZWSdtEndPr();
private:
    FZZWRPr * m_FZZWRPr;
    
};

#endif //FZZWSDTENDPR_H
