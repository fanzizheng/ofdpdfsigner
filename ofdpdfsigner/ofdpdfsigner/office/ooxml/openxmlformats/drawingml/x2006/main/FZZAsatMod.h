//
//  Created by zizheng fan on 2023/08/03
//
#ifndef FZZASATMOD_H
#define FZZASATMOD_H

#include "office/FZZXMLElementObject.h"

#define FZZASATMOD_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZASATMOD_Name "satMod"

class FZZAsatMod : public FZZXMLElementObject
{
public:
    
    FZZAsatMod(FZZOfficeObject * parent);
    FZZAsatMod(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAsatMod(const FZZAsatMod& obj);
    virtual ~FZZAsatMod();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZAsatMod();
private:
    
    
};

#endif //FZZASATMOD_H
