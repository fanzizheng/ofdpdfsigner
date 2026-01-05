//
//  Created by zizheng fan on 2023/11/06
//
#ifndef FZZWGRIDCOL_H
#define FZZWGRIDCOL_H

#include "office/FZZXMLElementObject.h"

#define FZZWGRIDCOL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWGRIDCOL_Name "gridCol"

class FZZWGridCol : public FZZXMLElementObject
{
public:
    
    FZZWGridCol(FZZOfficeObject * parent);
    FZZWGridCol(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWGridCol(const FZZWGridCol& obj);
    virtual ~FZZWGridCol();
    
public:
    void setW(string value);
    string getW();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWGridCol();
private:
    
    
};

#endif //FZZWGRIDCOL_H
