//
//  Created by zizheng fan on 2023/09/06
//
#ifndef FZZWPANOSE1_H
#define FZZWPANOSE1_H

#include "office/FZZXMLElementObject.h"

#define FZZWPANOSE1_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPANOSE1_Name "panose1"

class FZZWPanose1 : public FZZXMLElementObject
{
public:
    
    FZZWPanose1(FZZOfficeObject * parent);
    FZZWPanose1(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPanose1(const FZZWPanose1& obj);
    virtual ~FZZWPanose1();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWPanose1();
private:
    
    
};

#endif //FZZWPANOSE1_H
