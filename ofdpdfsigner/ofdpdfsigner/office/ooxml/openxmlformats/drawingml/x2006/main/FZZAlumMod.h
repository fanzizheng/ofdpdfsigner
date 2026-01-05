//
//  Created by zizheng fan on 2023/08/03
//
#ifndef FZZALUMMOD_H
#define FZZALUMMOD_H

#include "office/FZZXMLElementObject.h"

#define FZZALUMMOD_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZALUMMOD_Name "lumMod"

class FZZAlumMod : public FZZXMLElementObject
{
public:
    
    FZZAlumMod(FZZOfficeObject * parent);
    FZZAlumMod(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAlumMod(const FZZAlumMod& obj);
    virtual ~FZZAlumMod();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZAlumMod();
private:
    
    
};

#endif //FZZALUMMOD_H
