//
//  Created by zizheng fan on 2023/10/12
//
#ifndef FZZWJC_H
#define FZZWJC_H

#include "office/FZZXMLElementObject.h"

#define FZZWJC_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWJC_Name "jc"

class FZZWJc : public FZZXMLElementObject
{
public:
    
    FZZWJc(FZZOfficeObject * parent);
    FZZWJc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWJc(const FZZWJc& obj);
    virtual ~FZZWJc();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWJc();
private:
    
    
};

#endif //FZZWJC_H
