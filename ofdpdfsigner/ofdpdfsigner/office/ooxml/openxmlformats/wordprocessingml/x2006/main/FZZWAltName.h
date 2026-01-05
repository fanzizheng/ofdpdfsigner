//
//  Created by zizheng fan on 2023/09/04
//
#ifndef FZZWALTNAME_H
#define FZZWALTNAME_H

#include "office/FZZXMLElementObject.h"

#define FZZWALTNAME_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWALTNAME_Name "altName"

class FZZWAltName : public FZZXMLElementObject
{
public:
    
    FZZWAltName(FZZOfficeObject * parent);
    FZZWAltName(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWAltName(const FZZWAltName& obj);
    virtual ~FZZWAltName();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWAltName();
private:
    
    
};

#endif //FZZWALTNAME_H
