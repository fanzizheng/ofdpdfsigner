//
//  Created by zizheng fan on 2023/10/12
//
#ifndef FZZWKERN_H
#define FZZWKERN_H

#include "office/FZZXMLElementObject.h"

#define FZZWKERN_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWKERN_Name "kern"

class FZZWKern : public FZZXMLElementObject
{
public:
    
    FZZWKern(FZZOfficeObject * parent);
    FZZWKern(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWKern(const FZZWKern& obj);
    virtual ~FZZWKern();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWKern();
private:
    
    
};

#endif //FZZWKERN_H
