//
//  Created by zizheng fan on 2023/11/13
//
#ifndef FZZWSDT_H
#define FZZWSDT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtEndPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtContent.h"

#define FZZWSDT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSDT_Name "sdt"

class FZZWSdt : public FZZXMLElementObject
{
public:
    
    FZZWSdt(FZZOfficeObject * parent);
    FZZWSdt(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSdt(const FZZWSdt& obj);
    virtual ~FZZWSdt();
    
public:
    FZZWSdtPr * setSdtPr();
    FZZWSdtPr * getSdtPr();
    FZZWSdtEndPr * setSdtEndPr();
    FZZWSdtEndPr * getSdtEndPr();
    FZZWSdtContent * setSdtContent();
    FZZWSdtContent * getSdtContent();
protected:
    FZZWSdt();
private:
    FZZWSdtPr * m_FZZWSdtPr;
    FZZWSdtEndPr * m_FZZWSdtEndPr;
    FZZWSdtContent * m_FZZWSdtContent;
};

#endif //FZZWSDT_H
