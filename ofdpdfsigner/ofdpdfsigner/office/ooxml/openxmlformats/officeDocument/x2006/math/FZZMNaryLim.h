//
//  Created by zizheng fan on 2023/05/25
//
#ifndef FZZMNARYLIM_H
#define FZZMNARYLIM_H

#include "office/FZZXMLElementObject.h"

#define FZZMNARYLIM_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMNARYLIM_Name "naryLim"

class FZZMNaryLim : public FZZXMLElementObject
{
public:
    
    FZZMNaryLim(FZZOfficeObject * parent);
    FZZMNaryLim(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMNaryLim(const FZZMNaryLim& obj);
    virtual ~FZZMNaryLim();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMNaryLim();
private:
    
    
};

#endif //FZZMNARYLIM_H
