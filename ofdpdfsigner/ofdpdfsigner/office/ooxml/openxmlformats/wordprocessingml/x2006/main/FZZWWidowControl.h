//
//  Created by zizheng fan on 2023/11/14
//
#ifndef FZZWWIDOWCONTROL_H
#define FZZWWIDOWCONTROL_H

#include "office/FZZXMLElementObject.h"

#define FZZWWIDOWCONTROL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWWIDOWCONTROL_Name "widowControl"

class FZZWWidowControl : public FZZXMLElementObject
{
public:
    
    FZZWWidowControl(FZZOfficeObject * parent);
    FZZWWidowControl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWWidowControl(const FZZWWidowControl& obj);
    virtual ~FZZWWidowControl();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWWidowControl();
private:
    
    
};

#endif //FZZWWIDOWCONTROL_H
