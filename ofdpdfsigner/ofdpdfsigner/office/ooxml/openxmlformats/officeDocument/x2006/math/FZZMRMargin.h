//
//  Created by zizheng fan on 2023/05/26
//
#ifndef FZZMRMARGIN_H
#define FZZMRMARGIN_H

#include "office/FZZXMLElementObject.h"

#define FZZMRMARGIN_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMRMARGIN_Name "rMargin"

class FZZMRMargin : public FZZXMLElementObject
{
public:
    
    FZZMRMargin(FZZOfficeObject * parent);
    FZZMRMargin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMRMargin(const FZZMRMargin& obj);
    virtual ~FZZMRMargin();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMRMargin();
private:
    
    
};

#endif //FZZMRMARGIN_H
