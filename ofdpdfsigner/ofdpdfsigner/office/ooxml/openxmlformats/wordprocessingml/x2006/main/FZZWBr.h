//
//  Created by zizheng fan on 2023/11/16
//
#ifndef FZZWBR_H
#define FZZWBR_H

#include "office/FZZXMLElementObject.h"

#define FZZWBR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBR_Name "br"

class FZZWBr : public FZZXMLElementObject
{
public:
    
    FZZWBr(FZZOfficeObject * parent);
    FZZWBr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBr(const FZZWBr& obj);
    virtual ~FZZWBr();
    
public:
    void setType(string value);
    string getType();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWBr();
private:
    
    
};

#endif //FZZWBR_H
