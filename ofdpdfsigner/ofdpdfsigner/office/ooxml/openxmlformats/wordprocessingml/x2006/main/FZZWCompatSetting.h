//
//  Created by zizheng fan on 2023/09/21
//
#ifndef FZZWCOMPATSETTING_H
#define FZZWCOMPATSETTING_H

#include "office/FZZXMLElementObject.h"

#define FZZWCOMPATSETTING_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCOMPATSETTING_Name "compatSetting"

class FZZWCompatSetting : public FZZXMLElementObject
{
public:
    
    FZZWCompatSetting(FZZOfficeObject * parent);
    FZZWCompatSetting(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWCompatSetting(const FZZWCompatSetting& obj);
    virtual ~FZZWCompatSetting();
    
public:
    void setVal(string value);
    string getVal();
    void setName(string value);
    string getName();
    void setUri(string value);
    string getUri();
protected:
    FZZWCompatSetting();
private:
    
    
};

#endif //FZZWCOMPATSETTING_H
