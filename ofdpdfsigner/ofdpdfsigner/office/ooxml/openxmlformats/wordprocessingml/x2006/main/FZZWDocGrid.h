//
//  Created by zizheng fan on 2023/10/26
//
#ifndef FZZWDOCGRID_H
#define FZZWDOCGRID_H

#include "office/FZZXMLElementObject.h"

#define FZZWDOCGRID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDOCGRID_Name "docGrid"

class FZZWDocGrid : public FZZXMLElementObject
{
public:
    
    FZZWDocGrid(FZZOfficeObject * parent);
    FZZWDocGrid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDocGrid(const FZZWDocGrid& obj);
    virtual ~FZZWDocGrid();
    
public:
    void setLinePitch(string value);
    string getLinePitch();
    void setType(string value);
    string getType();
    void setCharSpace(string value);
    string getCharSpace();
protected:
    FZZWDocGrid();
private:
    
    
};

#endif //FZZWDOCGRID_H
