//
//  Created by zizheng fan on 2023/10/07
//
#ifndef FZZWSZCS_H
#define FZZWSZCS_H

#include "office/FZZXMLElementObject.h"

#define FZZWSZCS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSZCS_Name "szCs"

class FZZWSzCS : public FZZXMLElementObject
{
public:
    
    FZZWSzCS(FZZOfficeObject * parent);
    FZZWSzCS(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSzCS(const FZZWSzCS& obj);
    virtual ~FZZWSzCS();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWSzCS();
private:
    
    
};

#endif //FZZWSZCS_H
