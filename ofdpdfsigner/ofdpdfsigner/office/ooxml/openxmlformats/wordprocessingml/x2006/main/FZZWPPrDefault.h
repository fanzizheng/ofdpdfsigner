//
//  Created by zizheng fan on 2023/11/07
//
#ifndef FZZWPPRDEFAULT_H
#define FZZWPPRDEFAULT_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZWPPRDEFAULT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPPRDEFAULT_Name "pPrDefault"

class FZZWPPrDefault : public FZZXMLElementObject
{
public:
    
    FZZWPPrDefault(FZZOfficeObject * parent);
    FZZWPPrDefault(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPPrDefault(const FZZWPPrDefault& obj);
    virtual ~FZZWPPrDefault();
    
public:
    FZZWPPr * setPPr();
    FZZWPPr * getPPr();


protected:
    FZZWPPrDefault();
private:
    FZZWPPr* m_FZZWPPr;
    
};

#endif //FZZWPPRDEFAULT_H
