//
//  Created by zizheng fan on 2023/10/19
//
#ifndef FZZWTBLPR_H
#define FZZWTBLPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblInd.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblCellMar.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblStyle.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblW.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblLook.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblBorders.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWJc.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblpPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblOverlap.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblLayout.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblCellSpacing.h"

#define FZZWTBLPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLPR_Name "tblPr"

class FZZWTblPr : public FZZXMLElementObject
{
public:
    
    FZZWTblPr(FZZOfficeObject * parent);
    FZZWTblPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblPr(const FZZWTblPr& obj);
    virtual ~FZZWTblPr();
    
public:
    FZZWTblInd * setTblInd();
    FZZWTblInd * getTblInd();
    FZZWTblCellMar * setTblCellMar();
    FZZWTblCellMar * getTblCellMar();
    FZZWTblStyle * setTblStyle();
    FZZWTblStyle * getTblStyle();
    FZZWTblW * setTblW();
    FZZWTblW * getTblW();
    FZZWTblLook * setTblLook();
    FZZWTblLook * getTblLook();
    FZZWTblBorders * setTblBorders();
    FZZWTblBorders * getTblBorders();
    FZZWJc * setJc();
    FZZWJc * getJc();
    FZZWTblpPr * setTblpPr();
    FZZWTblpPr * getTblpPr();
    FZZWTblOverlap * setTblOverlap();
    FZZWTblOverlap * getTblOverlap();
    FZZWTblLayout * setTblLayout();
    FZZWTblLayout * getTblLayout();
    FZZWTblCellSpacing * setTblCellSpacing();
    FZZWTblCellSpacing * getTblCellSpacing();
protected:
    FZZWTblPr();
private:
    FZZWTblInd * m_FZZWTblInd;
    FZZWTblCellMar * m_FZZWTblCellMar;
    FZZWTblStyle * m_FZZWTblStyle;
    FZZWTblW * m_FZZWTblW;
    FZZWTblLook * m_FZZWTblLook;
    FZZWTblBorders * m_FZZWTblBorders;
    FZZWJc * m_FZZWJc;
    FZZWTblpPr * m_FZZWTblpPr;
    FZZWTblOverlap * m_FZZWTblOverlap;
    FZZWTblLayout * m_FZZWTblLayout;
    FZZWTblCellSpacing * m_FZZWTblCellSpacing;
};

#endif //FZZWTBLPR_H
