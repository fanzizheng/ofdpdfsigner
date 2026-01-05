//
//  Created by zizheng fan on 2023/09/07
//
#ifndef FZZWFAMILY_H
#define FZZWFAMILY_H

#include "office/FZZXMLElementObject.h"

#define FZZWFAMILY_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWFAMILY_Name "family"

class FZZWFamily : public FZZXMLElementObject
{
public:
    
    FZZWFamily(FZZOfficeObject * parent);
    FZZWFamily(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWFamily(const FZZWFamily& obj);
    virtual ~FZZWFamily();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWFamily();
private:
    
    
};

#endif //FZZWFAMILY_H
