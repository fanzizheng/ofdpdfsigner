//
//  Created by zizheng fan on 2023/04/28.
//
#ifndef FZZWPSCNVCNPR_H
#define FZZWPSCNVCNPR_H

#include "office/FZZXMLElementObject.h"



#define FZZWPSCNVCNPR_Find_Key "schemas.microsoft.com/office/word/2010/wordprocessingShape"
#define FZZWPSCNVCNPR_Name "cNvCnPr"

class FZZWPSCNvCnPr : public FZZXMLElementObject
{
public:
    
    FZZWPSCNvCnPr(FZZOfficeObject * parent);
    FZZWPSCNvCnPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPSCNvCnPr(const FZZWPSCNvCnPr& obj);
    virtual ~FZZWPSCNvCnPr();
    
public:
    

protected:
    FZZWPSCNvCnPr();
private:

    
};

#endif //FZZWPSCNVCNPR_H
