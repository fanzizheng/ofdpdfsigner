//
//  Created by zizheng fan on 2023/11/17
//
#ifndef FZZWTBLLAYOUT_H
#define FZZWTBLLAYOUT_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLLAYOUT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLLAYOUT_Name "tblLayout"

class FZZWTblLayout : public FZZXMLElementObject
{
public:
    
    FZZWTblLayout(FZZOfficeObject * parent);
    FZZWTblLayout(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblLayout(const FZZWTblLayout& obj);
    virtual ~FZZWTblLayout();
    
public:
    void setType(string value);
    string getType();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTblLayout();
private:
    
    
};

#endif //FZZWTBLLAYOUT_H
