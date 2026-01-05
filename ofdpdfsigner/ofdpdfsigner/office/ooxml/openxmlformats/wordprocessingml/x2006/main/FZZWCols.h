//
//  Created by zizheng fan on 2023/10/26
//
#ifndef FZZWCOLS_H
#define FZZWCOLS_H

#include "office/FZZXMLElementObject.h"

#define FZZWCOLS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCOLS_Name "cols"

class FZZWCols : public FZZXMLElementObject
{
public:
    
    FZZWCols(FZZOfficeObject * parent);
    FZZWCols(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWCols(const FZZWCols& obj);
    virtual ~FZZWCols();
    
public:
    void setSpace(string value);
    string getSpace();
    void setNum(string value);
    string getNum();
protected:
    FZZWCols();
private:
    
    
};

#endif //FZZWCOLS_H
