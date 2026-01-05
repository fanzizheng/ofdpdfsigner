//
//  Created by zizheng fan on 2023/11/03
//
#ifndef FZZWTBLW_H
#define FZZWTBLW_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLW_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLW_Name "tblW"

class FZZWTblW : public FZZXMLElementObject
{
public:
    
    FZZWTblW(FZZOfficeObject * parent);
    FZZWTblW(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblW(const FZZWTblW& obj);
    virtual ~FZZWTblW();
    
public:
    void setW(string value);
    string getW();
    
    void setType(string value);
    string getType();
    
protected:
    FZZWTblW();
private:
    
    
};

#endif //FZZWTBLW_H
