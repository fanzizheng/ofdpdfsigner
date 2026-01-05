//
//  Created by zizheng fan on 2023/09/26
//
#ifndef FZZWRSIDROOT_H
#define FZZWRSIDROOT_H

#include "office/FZZXMLElementObject.h"

#define FZZWRSIDROOT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRSIDROOT_Name "rsidRoot"

#define FZZWRSIDROOT_NEW_ROOT_STR "00A0687D"

class FZZWRsidRoot : public FZZXMLElementObject
{
public:
    
    FZZWRsidRoot(FZZOfficeObject * parent);
    FZZWRsidRoot(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRsidRoot(const FZZWRsidRoot& obj);
    virtual ~FZZWRsidRoot();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWRsidRoot();
private:
    
    
};

#endif //FZZWRSIDROOT_H
