//
//  Created by zizheng fan on 2023/11/15
//
#ifndef FZZWFOOTERREFERENCE_H
#define FZZWFOOTERREFERENCE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcPr.h"

#define FZZWFOOTERREFERENCE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWFOOTERREFERENCE_Name "footerReference"

class FZZWFooterReference : public FZZXMLElementObject
{
public:
    
    FZZWFooterReference(FZZOfficeObject * parent);
    FZZWFooterReference(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWFooterReference(const FZZWFooterReference& obj);
    virtual ~FZZWFooterReference();
    
public:
    void setType(string value);
    string getType();
    void setRID(string value);
    string getRID();
//    void setValue(string value);
//    string getValue();

    
protected:
    FZZWFooterReference();
private:
    
    
};

#endif //FZZWFOOTERREFERENCE_H
