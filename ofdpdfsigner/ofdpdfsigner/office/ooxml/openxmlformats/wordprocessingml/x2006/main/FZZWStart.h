//
//  Created by zizheng fan on 2023/11/23
//
#ifndef FZZWSTART_H
#define FZZWSTART_H

#include "office/FZZXMLElementObject.h"

#define FZZWSTART_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSTART_Name "start"

class FZZWStart : public FZZXMLElementObject
{
public:
    
    FZZWStart(FZZOfficeObject * parent);
    FZZWStart(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWStart(const FZZWStart& obj);
    virtual ~FZZWStart();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWStart();
private:
    
    
};

#endif //FZZWSTART_H
