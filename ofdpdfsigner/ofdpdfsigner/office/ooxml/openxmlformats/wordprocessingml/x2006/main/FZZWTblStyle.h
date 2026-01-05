//
//  Created by zizheng fan on 2023/11/06
//
#ifndef FZZWTBLSTYLE_H
#define FZZWTBLSTYLE_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLSTYLE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLSTYLE_Name "tblStyle"

class FZZWTblStyle : public FZZXMLElementObject
{
public:
    
    FZZWTblStyle(FZZOfficeObject * parent);
    FZZWTblStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblStyle(const FZZWTblStyle& obj);
    virtual ~FZZWTblStyle();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTblStyle();
private:
    
    
};

#endif //FZZWTBLSTYLE_H
