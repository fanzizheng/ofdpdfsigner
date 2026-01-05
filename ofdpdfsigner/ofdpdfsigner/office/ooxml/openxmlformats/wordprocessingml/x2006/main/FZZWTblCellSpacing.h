//
//  Created by zizheng fan on 2024/02/21
//
#ifndef FZZWTBLCELLSPACING_H
#define FZZWTBLCELLSPACING_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLCELLSPACING_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLCELLSPACING_Name "tblCellSpacing"

class FZZWTblCellSpacing : public FZZXMLElementObject
{
public:
    
    FZZWTblCellSpacing(FZZOfficeObject * parent);
    FZZWTblCellSpacing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblCellSpacing(const FZZWTblCellSpacing& obj);
    virtual ~FZZWTblCellSpacing();
    
public:
    void setW(string value);
    string getW();
    void setType(string value);
    string getType();
protected:
    FZZWTblCellSpacing();
private:
    
    
};

#endif //FZZWTBLCELLSPACING_H
