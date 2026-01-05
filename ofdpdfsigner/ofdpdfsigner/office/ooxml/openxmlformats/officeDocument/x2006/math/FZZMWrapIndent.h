//
//  Created by zizheng fan on 2023/05/30
//
#ifndef FZZMWRAPINDENT_H
#define FZZMWRAPINDENT_H

#include "office/FZZXMLElementObject.h"

#define FZZMWRAPINDENT_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMWRAPINDENT_Name "wrapIndent"

class FZZMWrapIndent : public FZZXMLElementObject
{
public:
    
    FZZMWrapIndent(FZZOfficeObject * parent);
    FZZMWrapIndent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMWrapIndent(const FZZMWrapIndent& obj);
    virtual ~FZZMWrapIndent();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMWrapIndent();
private:
    
    
};

#endif //FZZMWRAPINDENT_H
