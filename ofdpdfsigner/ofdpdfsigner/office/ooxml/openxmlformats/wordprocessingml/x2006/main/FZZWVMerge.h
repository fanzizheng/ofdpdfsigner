//
//  Created by zizheng fan on 2023/11/17
//
#ifndef FZZWVMERGE_H
#define FZZWVMERGE_H

#include "office/FZZXMLElementObject.h"

#define FZZWVMERGE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWVMERGE_Name "vMerge"

class FZZWVMerge : public FZZXMLElementObject
{
public:
    
    FZZWVMerge(FZZOfficeObject * parent);
    FZZWVMerge(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWVMerge(const FZZWVMerge& obj);
    virtual ~FZZWVMerge();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWVMerge();
private:
    
    
};

#endif //FZZWVMERGE_H
