//
//  Created by zizheng fan on 2023/11/07
//
#ifndef FZZWBASEDON_H
#define FZZWBASEDON_H

#include "office/FZZXMLElementObject.h"

#define FZZWBASEDON_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBASEDON_Name "basedOn"

class FZZWBasedOn : public FZZXMLElementObject
{
public:
    
    FZZWBasedOn(FZZOfficeObject * parent);
    FZZWBasedOn(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBasedOn(const FZZWBasedOn& obj);
    virtual ~FZZWBasedOn();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWBasedOn();
private:
    
    
};

#endif //FZZWBASEDON_H
