//
//  Created by zizheng fan on 2023/11/02
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTbl.h"
#include "office/FZZOfficeObject.h"
#include "office/docx/container/FZZWordDir.h"
#include "office/docx/container/FZZDocXDir.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTbl**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl::FZZWTbl() : FZZXMLElementObject(),m_FZZWTblPr(NULL),m_FZZWTblGrid(NULL),m_DocXDir(NULL)
{
    //DLOG("FZZWTbl()");
    FZZConst::addClassCount("FZZWTbl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl::FZZWTbl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWTblPr(NULL),m_FZZWTblGrid(NULL),m_DocXDir(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTbl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl::FZZWTbl(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTblPr(NULL),m_FZZWTblGrid(NULL),m_DocXDir(NULL)
{
    FZZConst::addClassCount("FZZWTbl");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl::FZZWTbl(const FZZWTbl& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTbl");
    if ( this == &obj ) {
        return;
    }
    m_DocXDir = obj.m_DocXDir;
    m_FZZWTblPr = obj.m_FZZWTblPr != NULL ? new FZZWTblPr(*obj.m_FZZWTblPr) : NULL;
    m_FZZWTblGrid = obj.m_FZZWTblGrid != NULL ? new FZZWTblGrid(*obj.m_FZZWTblGrid) : NULL;
    
    vector<FZZWTr*>::const_iterator itr;
    for( itr = obj.m_FZZWTrs.begin(); itr != obj.m_FZZWTrs.end(); itr++ ) {
        FZZWTr * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWTrs.push_back(new FZZWTr(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl::~FZZWTbl()
{
    //DLOG("~FZZWTbl()");
    FZZConst::delClassCount("FZZWTbl");
    
    
    if ( m_FZZWTblPr != NULL ) {
        delete m_FZZWTblPr;
        m_FZZWTblPr = NULL;
    }
    if ( m_FZZWTblGrid != NULL ) {
        delete m_FZZWTblGrid;
        m_FZZWTblGrid = NULL;
    }
    
    vector<FZZWTr*>::const_iterator itr;
    for( itr = m_FZZWTrs.begin(); itr != m_FZZWTrs.end(); itr++ ) {
        FZZWTr * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWTrs.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWTbl::setTblPr()
{
    return m_FZZWTblPr = setElementObject(m_FZZWTblPr,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWTbl::getTblPr()
{
    return m_FZZWTblPr = getElementObject(m_FZZWTblPr,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid * FZZWTbl::setTblGrid()
{
    return m_FZZWTblGrid = setElementObject(m_FZZWTblGrid,FZZWTBLGRID_Find_Key,FZZWTBLGRID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid * FZZWTbl::getTblGrid()
{
    return m_FZZWTblGrid = getElementObject(m_FZZWTblGrid,FZZWTBLGRID_Find_Key,FZZWTBLGRID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr * FZZWTbl::addTr()
{
    return addElementObject(&m_FZZWTrs,FZZWTR_Find_Key,FZZWTR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWTr*> * FZZWTbl::getTrList()
{
    getElementObjectList(&m_FZZWTrs,FZZWTR_Find_Key,FZZWTR_Name);
    return &m_FZZWTrs;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTbl::setDocXDir(FZZDocXDir * docXDir)
{
    m_DocXDir = docXDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr * FZZWTbl::addRow()
{
    FZZWTr * retTr = addTr();
    if ( retTr != NULL ) {
        retTr->setDocXDir(m_DocXDir);
    }
    return retTr;
}
//-----------------------------------------------------------------------------------------------------------------
size_t FZZWTbl::getRowCount()
{
    vector<FZZWTr*> * TrList = getTrList();
    if ( TrList == NULL ) {
        return 0;
    }
    return TrList->size();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr * FZZWTbl::getRow(size_t index)
{
    vector<FZZWTr*> * TrList = getTrList();
    if ( TrList == NULL || TrList->size() == 0 ) {
        return NULL;
    }
    
    if ( index > TrList->size() -1 ) {
        return NULL;
    }
    
    FZZWTr * tempTr = *(TrList->begin()+index);
    if ( tempTr != NULL ) {
        tempTr->setDocXDir(m_DocXDir);
    }
    return tempTr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTbl::setStyleID(string styleid)
{
    FZZWTblPr * tblpr = setTblPr();
    if ( tblpr != NULL ) {
        FZZWTblStyle * tblStyle = tblpr->setTblStyle();
        if ( tblStyle != NULL ) {
            tblStyle->setVal(styleid);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle * FZZWTbl::setStyle_Default()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    FZZStylesXML * stylesXML = wordDir->getStylesXML();
    if ( stylesXML == NULL ) {
        return NULL;
    }
    FZZWStyle * style = stylesXML->addStyle();
    if ( style == NULL ) {
        return NULL;
    }
    style->setType("table");
    style->setStyleId(stylesXML->getNextStyleID_ToString());
    FZZWName * ctwName = style->setName();
    if ( ctwName != NULL ) {
        ctwName->setVal("Table "+style->getStyleId());
    }
    FZZWBasedOn * cwBasedOn = style->setBasedOn();
    if ( cwBasedOn != NULL ) {
        cwBasedOn->setVal("a1");
    }
    FZZWUiPriority * uiPriority = style->setUiPriority();
    if ( uiPriority != NULL ) {
        uiPriority->setVal("39");
    }
    FZZWPPr * ctwPpr = style->setPpr();
    if ( ctwPpr != NULL ) {
        FZZWSpacing * ctwSpacing = ctwPpr->setSpacing();
        if ( ctwSpacing != NULL ) {
            ctwSpacing->setAfter("0");
            ctwSpacing->setLine("240");
            ctwSpacing->setLineRule("auto");
        }
    }
    //FZZWTblPr * ctwTblPr = style->addTblPr();
    FZZWTblPr * ctwTblPr = style->setTblPr();
    if ( ctwTblPr != NULL ) {
        FZZWTblBorders * tblBorders = ctwTblPr->setTblBorders();
        if ( tblBorders != NULL ) {
            FZZWTop * top = tblBorders->setTop();
            if ( top != NULL ) {
                top->setVal("single");
                top->setSz("4");
                top->setSpace("0");
                top->setColor("auto");
            }
            FZZWLeft * left = tblBorders->setLeft();
            if ( left != NULL ) {
                left->setVal("single");
                left->setSz("4");
                left->setSpace("0");
                left->setColor("auto");
            }
            FZZWBottom * bottom = tblBorders->setBottom();
            if ( bottom != NULL ) {
                bottom->setVal("single");
                bottom->setSz("4");
                bottom->setSpace("0");
                bottom->setColor("auto");
            }
            FZZWRight * right = tblBorders->setRight();
            if ( right != NULL ) {
                right->setVal("single");
                right->setSz("4");
                right->setSpace("0");
                right->setColor("auto");
            }
            FZZWInsideH * insideH = tblBorders->setInsideH();
            if ( insideH != NULL ) {
                insideH->setVal("single");
                insideH->setSz("4");
                insideH->setSpace("0");
                insideH->setColor("auto");
            }
            FZZWInsideV * insideV = tblBorders->setInsideV();
            if ( insideV != NULL ) {
                insideV->setVal("single");
                insideV->setSz("4");
                insideV->setSpace("0");
                insideV->setColor("auto");
            }
        }
    }
    return style;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWTbl::setTblPr_Default()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    FZZStylesXML * stylesXML = wordDir->getStylesXML();
    if ( stylesXML == NULL ) {
        return NULL;
    }
    
    FZZWTblPr * tblpr = setTblPr();
    if ( tblpr != NULL ) {
        FZZWTblStyle * tblStyle = tblpr->setTblStyle();
        if ( tblStyle != NULL ) {
            tblStyle->setVal(stylesXML->getCurrStyleID_ToString());
        }
        FZZWTblW * ctwTblW = tblpr->setTblW();
        if ( ctwTblW != NULL ) {
            ctwTblW->setW("0");
            ctwTblW->setType("auto");
        }
        FZZWTblLook * ctwTblLook = tblpr->setTblLook();
        if ( ctwTblLook != NULL ) {
            ctwTblLook->setVal("04A0");
            ctwTblLook->setFirstRow("1");
            ctwTblLook->setLastRow("0");
            ctwTblLook->setFirstColumn("1");
            ctwTblLook->setLastColumn("0");
            ctwTblLook->setNoHBand("0");
            ctwTblLook->setNoVBand("1");
        }
    }
    return tblpr;
}
//-----------------------------------------------------------------------------------------------------------------


