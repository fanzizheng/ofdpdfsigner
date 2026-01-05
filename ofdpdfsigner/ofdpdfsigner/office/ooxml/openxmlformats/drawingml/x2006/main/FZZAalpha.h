//
//  Created by zizheng fan on 2023/07/18
//
#ifndef FZZAALPHA_H
#define FZZAALPHA_H

#include "office/FZZXMLElementObject.h"

#define FZZAALPHA_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAALPHA_Name "alpha"

class FZZAalpha : public FZZXMLElementObject
{
public:
    
    FZZAalpha(FZZOfficeObject * parent);
    FZZAalpha(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAalpha(const FZZAalpha& obj);
    virtual ~FZZAalpha();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZAalpha();
private:
    
    
};

#endif //FZZAALPHA_H
