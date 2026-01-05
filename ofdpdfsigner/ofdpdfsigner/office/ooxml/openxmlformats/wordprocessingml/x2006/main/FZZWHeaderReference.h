//
//  Created by zizheng fan on 2023/11/15
//
#ifndef FZZWHEADERREFERENCE_H
#define FZZWHEADERREFERENCE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcPr.h"

#define FZZWHEADERREFERENCE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWHEADERREFERENCE_Name "headerReference"

class FZZWHeaderReference : public FZZXMLElementObject
{
public:
    
    FZZWHeaderReference(FZZOfficeObject * parent);
    FZZWHeaderReference(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWHeaderReference(const FZZWHeaderReference& obj);
    virtual ~FZZWHeaderReference();
    
public:
    void setType(string value);
    string getType();
    void setRID(string value);
    string getRID();
//    void setValue(string value);
//    string getValue();
    

    
protected:
    FZZWHeaderReference();
private:
    
    
};

#endif //FZZWHEADERREFERENCE_H
