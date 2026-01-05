//
//  Created by zizheng fan on 2023/07/31
//
#ifndef FZZAPRSTDASH_H
#define FZZAPRSTDASH_H

#include "office/FZZXMLElementObject.h"

#define FZZAPRSTDASH_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAPRSTDASH_Name "prstDash"

class FZZAprstDash : public FZZXMLElementObject
{
public:
    
    FZZAprstDash(FZZOfficeObject * parent);
    FZZAprstDash(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAprstDash(const FZZAprstDash& obj);
    virtual ~FZZAprstDash();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZAprstDash();
private:
    
    
};

#endif //FZZAPRSTDASH_H
