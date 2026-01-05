//
//  Created by zizheng fan on 2023/11/17
//
#ifndef FZZWU_H
#define FZZWU_H

#include "office/FZZXMLElementObject.h"

#define FZZWU_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWU_Name "u"

class FZZWU : public FZZXMLElementObject
{
public:
    
    FZZWU(FZZOfficeObject * parent);
    FZZWU(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWU(const FZZWU& obj);
    virtual ~FZZWU();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWU();
private:
    
    
};

#endif //FZZWU_H
