//
//  Created by zizheng fan on 2023/11/21
//
#ifndef FZZWNUMID_H
#define FZZWNUMID_H

#include "office/FZZXMLElementObject.h"

#define FZZWNUMID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNUMID_Name "numId"

class FZZWNumId : public FZZXMLElementObject
{
public:
    
    FZZWNumId(FZZOfficeObject * parent);
    FZZWNumId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWNumId(const FZZWNumId& obj);
    virtual ~FZZWNumId();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWNumId();
private:
    
    
};

#endif //FZZWNUMID_H
