//
//  Created by zizheng fan on 2023/11/21
//
#ifndef FZZWABSTRACTNUMID_H
#define FZZWABSTRACTNUMID_H

#include "office/FZZXMLElementObject.h"

#define FZZWABSTRACTNUMID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWABSTRACTNUMID_Name "abstractNumId"

class FZZWAbstractNumId : public FZZXMLElementObject
{
public:
    
    FZZWAbstractNumId(FZZOfficeObject * parent);
    FZZWAbstractNumId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWAbstractNumId(const FZZWAbstractNumId& obj);
    virtual ~FZZWAbstractNumId();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWAbstractNumId();
private:
    
    
};

#endif //FZZWABSTRACTNUMID_H
