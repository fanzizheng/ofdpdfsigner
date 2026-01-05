//
//  Created by zizheng fan on 2023/11/24
//
#ifndef FZZWMULTILEVELTYPE_H
#define FZZWMULTILEVELTYPE_H

#include "office/FZZXMLElementObject.h"

#define FZZWMULTILEVELTYPE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWMULTILEVELTYPE_Name "multiLevelType"

class FZZWMultiLevelType : public FZZXMLElementObject
{
public:
    
    FZZWMultiLevelType(FZZOfficeObject * parent);
    FZZWMultiLevelType(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWMultiLevelType(const FZZWMultiLevelType& obj);
    virtual ~FZZWMultiLevelType();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWMultiLevelType();
private:
    
    
};

#endif //FZZWMULTILEVELTYPE_H
