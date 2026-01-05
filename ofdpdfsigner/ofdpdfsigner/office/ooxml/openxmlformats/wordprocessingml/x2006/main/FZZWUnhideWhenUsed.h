//
//  Created by zizheng fan on 2023/10/18
//
#ifndef FZZWUNHIDEWHENUSED_H
#define FZZWUNHIDEWHENUSED_H

#include "office/FZZXMLElementObject.h"

#define FZZWUNHIDEWHENUSED_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWUNHIDEWHENUSED_Name "unhideWhenUsed"

class FZZWUnhideWhenUsed : public FZZXMLElementObject
{
public:
    
    FZZWUnhideWhenUsed(FZZOfficeObject * parent);
    FZZWUnhideWhenUsed(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWUnhideWhenUsed(const FZZWUnhideWhenUsed& obj);
    virtual ~FZZWUnhideWhenUsed();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWUnhideWhenUsed();
private:
    
    
};

#endif //FZZWUNHIDEWHENUSED_H
