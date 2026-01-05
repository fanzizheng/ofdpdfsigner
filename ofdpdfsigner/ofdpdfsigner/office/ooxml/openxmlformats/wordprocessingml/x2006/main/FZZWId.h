//
//  Created by zizheng fan on 2023/11/13
//
#ifndef FZZWID_H
#define FZZWID_H

#include "office/FZZXMLElementObject.h"

#define FZZWID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWID_Name "id"

class FZZWId : public FZZXMLElementObject
{
public:
    
    FZZWId(FZZOfficeObject * parent);
    FZZWId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWId(const FZZWId& obj);
    virtual ~FZZWId();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWId();
private:
    
    
};

#endif //FZZWID_H
