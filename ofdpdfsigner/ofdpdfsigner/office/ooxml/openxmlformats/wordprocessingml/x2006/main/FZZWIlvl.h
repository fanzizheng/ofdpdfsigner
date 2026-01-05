//
//  Created by zizheng fan on 2023/11/21
//
#ifndef FZZWILVL_H
#define FZZWILVL_H

#include "office/FZZXMLElementObject.h"

#define FZZWILVL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWILVL_Name "ilvl"

class FZZWIlvl : public FZZXMLElementObject
{
public:
    
    FZZWIlvl(FZZOfficeObject * parent);
    FZZWIlvl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWIlvl(const FZZWIlvl& obj);
    virtual ~FZZWIlvl();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWIlvl();
private:
    
    
};

#endif //FZZWILVL_H
