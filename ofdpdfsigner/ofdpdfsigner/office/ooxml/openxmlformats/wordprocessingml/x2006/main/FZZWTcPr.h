//
//  Created by zizheng fan on 2023/11/03
//
#ifndef FZZWTCPR_H
#define FZZWTCPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcW.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWShd.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVAlign.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcBorders.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVMerge.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWGridSpan.h"

#define FZZWTCPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTCPR_Name "tcPr"

class FZZWTcPr : public FZZXMLElementObject
{
public:
    
    FZZWTcPr(FZZOfficeObject * parent);
    FZZWTcPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTcPr(const FZZWTcPr& obj);
    virtual ~FZZWTcPr();
    
public:
//    FZZWTblInd * setTblInd();
//    FZZWTblInd * getTblInd();
//    FZZWTblCellMar * setTblCellMar();
//    FZZWTblCellMar * getTblCellMar();
    FZZWTcW * setTcW();
    FZZWTcW * getTcW();
    
    FZZWShd * setShd();
    FZZWShd * getShd();
    FZZWVAlign * setVAlign();
    FZZWVAlign * getVAlign();
    FZZWTcBorders * setTcBorders();
    FZZWTcBorders * getTcBorders();
    FZZWVMerge * setVMerge();
    FZZWVMerge * getVMerge();
    FZZWGridSpan * setGridSpan();
    FZZWGridSpan * getGridSpan();
protected:
    FZZWTcPr();
private:
    FZZWTcW * m_FZZWTcW;
    FZZWShd * m_FZZWShd;
    FZZWVAlign * m_FZZWVAlign;
    FZZWTcBorders * m_FZZWTcBorders;
    FZZWVMerge * m_FZZWVMerge;
    FZZWGridSpan * m_FZZWGridSpan;
    
};

#endif //FZZWTCPR_H
