//
//  Created by zizheng fan on 2023/05/17.
//
#ifndef FZZMDEFJC_H
#define FZZMDEFJC_H

#include "office/FZZXMLElementObject.h"

#define FZZMDEFJC_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMDEFJC_Name "defJc"

class FZZMDefJc : public FZZXMLElementObject
{
public:
    
    FZZMDefJc(FZZOfficeObject * parent);
    FZZMDefJc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMDefJc(const FZZMDefJc& obj);
    virtual ~FZZMDefJc();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMDefJc();
private:
    
    
};

#endif //FZZMDEFJC_H
