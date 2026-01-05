//
//  Created by zizheng fan on 2023/05/29
//
#ifndef FZZMSMALLFRAC_H
#define FZZMSMALLFRAC_H

#include "office/FZZXMLElementObject.h"

#define FZZMSMALLFRAC_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMSMALLFRAC_Name "smallFrac"

class FZZMSmallFrac : public FZZXMLElementObject
{
public:
    
    FZZMSmallFrac(FZZOfficeObject * parent);
    FZZMSmallFrac(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMSmallFrac(const FZZMSmallFrac& obj);
    virtual ~FZZMSmallFrac();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMSmallFrac();
private:
    
    
};

#endif //FZZMSMALLFRAC_H
