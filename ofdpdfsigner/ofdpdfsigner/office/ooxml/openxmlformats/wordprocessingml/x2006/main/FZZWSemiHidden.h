//
//  Created by zizheng fan on 2023/10/24
//
#ifndef FZZWSEMIHIDDEN_H
#define FZZWSEMIHIDDEN_H

#include "office/FZZXMLElementObject.h"

#define FZZWSEMIHIDDEN_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSEMIHIDDEN_Name "semiHidden"

class FZZWSemiHidden : public FZZXMLElementObject
{
public:
    
    FZZWSemiHidden(FZZOfficeObject * parent);
    FZZWSemiHidden(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSemiHidden(const FZZWSemiHidden& obj);
    virtual ~FZZWSemiHidden();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWSemiHidden();
private:
    
    
};

#endif //FZZWSEMIHIDDEN_H
