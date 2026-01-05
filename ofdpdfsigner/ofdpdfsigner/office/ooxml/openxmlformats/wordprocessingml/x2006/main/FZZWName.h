//
//  Created by zizheng fan on 2023/10/24
//
#ifndef FZZWNAME_H
#define FZZWNAME_H

#include "office/FZZXMLElementObject.h"

#define FZZWNAME_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNAME_Name "name"

class FZZWName : public FZZXMLElementObject
{
public:
    
    FZZWName(FZZOfficeObject * parent);
    FZZWName(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWName(const FZZWName& obj);
    virtual ~FZZWName();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWName();
private:
    
    
};

#endif //FZZWNAME_H
