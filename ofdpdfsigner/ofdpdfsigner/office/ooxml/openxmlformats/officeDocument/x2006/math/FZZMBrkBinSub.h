//
//  Created by zizheng fan on 2023/05/16.
//
#ifndef FZZMBRKBINSUB_H
#define FZZMBRKBINSUB_H

#include "office/FZZXMLElementObject.h"

#define FZZMBRKBINSUB_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMBRKBINSUB_Name "brkBinSub"

class FZZMBrkBinSub : public FZZXMLElementObject
{
public:
    
    FZZMBrkBinSub(FZZOfficeObject * parent);
    FZZMBrkBinSub(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMBrkBinSub(const FZZMBrkBinSub& obj);
    virtual ~FZZMBrkBinSub();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMBrkBinSub();
private:
    
    
};

#endif //FZZMBRKBINSUB_H
