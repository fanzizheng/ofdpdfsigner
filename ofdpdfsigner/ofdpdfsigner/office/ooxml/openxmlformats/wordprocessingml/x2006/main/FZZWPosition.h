//
//  Created by zizheng fan on 2023/11/29
//
#ifndef FZZWPOSITION_H
#define FZZWPOSITION_H

#include "office/FZZXMLElementObject.h"

#define FZZWPOSITION_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPOSITION_Name "position"

class FZZWPosition : public FZZXMLElementObject
{
public:
    
    FZZWPosition(FZZOfficeObject * parent);
    FZZWPosition(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPosition(const FZZWPosition& obj);
    virtual ~FZZWPosition();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWPosition();
private:
    
    
};

#endif //FZZWPOSITION_H
