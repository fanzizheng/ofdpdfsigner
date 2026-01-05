//
//  Created by zizheng fan on 2023/11/06
//
#ifndef FZZWTBLGRID_H
#define FZZWTBLGRID_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWGridCol.h"


#define FZZWTBLGRID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLGRID_Name "tblGrid"

class FZZWTblGrid : public FZZXMLElementObject
{
public:
    
    FZZWTblGrid(FZZOfficeObject * parent);
    FZZWTblGrid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblGrid(const FZZWTblGrid& obj);
    virtual ~FZZWTblGrid();
    
public:
    FZZWGridCol * addGridCol();
    vector<FZZWGridCol*> * getGridColList();
protected:
    FZZWTblGrid();
private:
    vector<FZZWGridCol*> m_FZZWGridCols;
    
};

#endif //FZZWTBLGRID_H
