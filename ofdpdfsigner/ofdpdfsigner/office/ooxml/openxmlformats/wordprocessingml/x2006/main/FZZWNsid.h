//
//  Created by zizheng fan on 2023/11/23
//
#ifndef FZZWNSID_H
#define FZZWNSID_H

#include "office/FZZXMLElementObject.h"

#define FZZWNSID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNSID_Name "nsid"

class FZZWNsid : public FZZXMLElementObject
{
public:
    
    FZZWNsid(FZZOfficeObject * parent);
    FZZWNsid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWNsid(const FZZWNsid& obj);
    virtual ~FZZWNsid();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWNsid();
private:
    
    
};

#endif //FZZWNSID_H
