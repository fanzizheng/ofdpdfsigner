//
//  Created by zizheng fan on 2023/10/19
//
#ifndef FZZWTBLIND_H
#define FZZWTBLIND_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLIND_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLIND_Name "tblInd"

class FZZWTblInd : public FZZXMLElementObject
{
public:
    
    FZZWTblInd(FZZOfficeObject * parent);
    FZZWTblInd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblInd(const FZZWTblInd& obj);
    virtual ~FZZWTblInd();
    
public:
    void setW(string value);
    string getW();
    void setType(string value);
    string getType();
protected:
    FZZWTblInd();
private:
    
    
};

#endif //FZZWTBLIND_H
