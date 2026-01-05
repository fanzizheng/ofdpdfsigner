//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDEDIT_H
#define FZZOFDEDIT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDEDIT_Name "ofd:Edit"

class FZZOFDEdit : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDEdit(FZZOFDXMLFileObject * parent);
    FZZOFDEdit(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEdit(const FZZOFDEdit& obj);
    virtual ~FZZOFDEdit();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDEdit();
private:
    
};

#endif //FZZOFDEDIT_H
