//
//  Created by zizheng fan on 2023/11/22
//
#ifndef FZZWSUFF_H
#define FZZWSUFF_H

#include "office/FZZXMLElementObject.h"

#define FZZWSUFF_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSUFF_Name "suff"

class FZZWSuff : public FZZXMLElementObject
{
public:
    
    FZZWSuff(FZZOfficeObject * parent);
    FZZWSuff(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSuff(const FZZWSuff& obj);
    virtual ~FZZWSuff();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWSuff();
private:
    
    
};

#endif //FZZWSUFF_H
