//
//  Created by zizheng fan on 2023/11/24
//
#ifndef FZZWLVLJC_H
#define FZZWLVLJC_H

#include "office/FZZXMLElementObject.h"

#define FZZWLVLJC_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLVLJC_Name "lvlJc"

class FZZWLvlJc : public FZZXMLElementObject
{
public:
    
    FZZWLvlJc(FZZOfficeObject * parent);
    FZZWLvlJc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLvlJc(const FZZWLvlJc& obj);
    virtual ~FZZWLvlJc();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWLvlJc();
private:
    
    
};

#endif //FZZWLVLJC_H
