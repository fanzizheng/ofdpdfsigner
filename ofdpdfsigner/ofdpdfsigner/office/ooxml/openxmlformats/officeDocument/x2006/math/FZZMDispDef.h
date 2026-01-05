//
//  Created by zizheng fan on 2023/05/18.
//
#ifndef FZZMDISPDEF_H
#define FZZMDISPDEF_H

#include "office/FZZXMLElementObject.h"

#define FZZMDISPDEF_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMDISPDEF_Name "dispDef"

class FZZMDispDef : public FZZXMLElementObject
{
public:
    
    FZZMDispDef(FZZOfficeObject * parent);
    FZZMDispDef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMDispDef(const FZZMDispDef& obj);
    virtual ~FZZMDispDef();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMDispDef();
private:
    
    
};

#endif //FZZMDISPDEF_H
