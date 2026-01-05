//
//  Created by zizheng fan on 2023/05/19.
//
#ifndef FZZMINTLIM_H
#define FZZMINTLIM_H

#include "office/FZZXMLElementObject.h"

#define FZZMINTLIM_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMINTLIM_Name "intLim"

class FZZMIntLim : public FZZXMLElementObject
{
public:
    
    FZZMIntLim(FZZOfficeObject * parent);
    FZZMIntLim(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMIntLim(const FZZMIntLim& obj);
    virtual ~FZZMIntLim();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMIntLim();
private:
    
    
};

#endif //FZZMINTLIM_H
