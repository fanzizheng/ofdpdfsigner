//
//  Created by zizheng fan on 2023/11/02
//
#ifndef FZZWTBL_H
#define FZZWTBL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblGrid.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStyle.h"

#define FZZWTBL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBL_Name "tbl"

class FZZWTbl : public FZZXMLElementObject
{
public:
    
    FZZWTbl(FZZOfficeObject * parent);
    FZZWTbl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTbl(const FZZWTbl& obj);
    virtual ~FZZWTbl();
    
public:
    FZZWTblPr * setTblPr();
    FZZWTblPr * getTblPr();
    FZZWTblGrid * setTblGrid();
    FZZWTblGrid * getTblGrid();
    FZZWTr * addTr();
    vector<FZZWTr*> * getTrList();
public:
    void setDocXDir(FZZDocXDir * docXDir);
    FZZWTr * addRow();
    size_t getRowCount();
    FZZWTr * getRow(size_t index);
    
    void setStyleID(string styleid);
    FZZWStyle * setStyle_Default();
    //first Call setStyle_Default function, then call this function
    FZZWTblPr * setTblPr_Default();
    
protected:
    FZZWTbl();
private:
    FZZWTblPr * m_FZZWTblPr;
    FZZWTblGrid * m_FZZWTblGrid;
    vector<FZZWTr*> m_FZZWTrs;
    FZZDocXDir * m_DocXDir;
};

#endif //FZZWTBL_H
