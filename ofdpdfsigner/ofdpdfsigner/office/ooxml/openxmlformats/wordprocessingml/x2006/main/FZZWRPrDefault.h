//
//  Created by zizheng fan on 2023/10/09
//
#ifndef FZZWRPRDEFAULT_H
#define FZZWRPRDEFAULT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"


#define FZZWRPRDEFAULT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRPRDEFAULT_Name "rPrDefault"

class FZZWRPrDefault : public FZZXMLElementObject
{
public:
    
    FZZWRPrDefault(FZZOfficeObject * parent);
    FZZWRPrDefault(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRPrDefault(const FZZWRPrDefault& obj);
    virtual ~FZZWRPrDefault();
    
public:
    FZZWRPr * setRPr();
    FZZWRPr * getRPr();


protected:
    FZZWRPrDefault();
private:
    FZZWRPr* m_FZZWRPr;
    
};

#endif //FZZWRPRDEFAULT_H
