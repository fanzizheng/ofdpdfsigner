//
//  Created by zizheng fan on 2023/08/04
//
#ifndef FZZATINT_H
#define FZZATINT_H

#include "office/FZZXMLElementObject.h"

#define FZZATINT_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZATINT_Name "tint"

class FZZAtint : public FZZXMLElementObject
{
public:
    
    FZZAtint(FZZOfficeObject * parent);
    FZZAtint(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAtint(const FZZAtint& obj);
    virtual ~FZZAtint();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZAtint();
private:
    
    
};

#endif //FZZATINT_H
