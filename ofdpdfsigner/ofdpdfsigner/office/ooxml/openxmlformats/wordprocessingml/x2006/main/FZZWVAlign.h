//
//  Created by zizheng fan on 2023/11/17
//
#ifndef FZZWVALIGN_H
#define FZZWVALIGN_H

#include "office/FZZXMLElementObject.h"

#define FZZWVALIGN_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWVALIGN_Name "vAlign"

class FZZWVAlign : public FZZXMLElementObject
{
public:
    
    FZZWVAlign(FZZOfficeObject * parent);
    FZZWVAlign(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWVAlign(const FZZWVAlign& obj);
    virtual ~FZZWVAlign();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWVAlign();
private:
    
    
};

#endif //FZZWVALIGN_H
