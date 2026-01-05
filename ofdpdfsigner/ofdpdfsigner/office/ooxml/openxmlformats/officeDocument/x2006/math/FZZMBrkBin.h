//
//  Created by zizheng fan on 2023/05/16.
//
#ifndef FZZMBRKBIN_H
#define FZZMBRKBIN_H

#include "office/FZZXMLElementObject.h"

#define FZZMBRKBIN_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"

#define FZZMBRKBIN_Name "brkBin"

class FZZMBrkBin : public FZZXMLElementObject
{
public:
    
    FZZMBrkBin(FZZOfficeObject * parent);
    FZZMBrkBin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMBrkBin(const FZZMBrkBin& obj);
    virtual ~FZZMBrkBin();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMBrkBin();
private:
    
    
};

#endif //FZZMBRKBIN_H
