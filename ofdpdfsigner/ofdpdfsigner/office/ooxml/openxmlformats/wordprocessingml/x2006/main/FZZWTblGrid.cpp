//
//  Created by zizheng fan on 2023/11/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblGrid.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblGrid**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid::FZZWTblGrid() : FZZXMLElementObject()//,m_FZZWTblInd(NULL),m_FZZWTblCellMar(NULL)
{
    //DLOG("FZZWTblGrid()");
    FZZConst::addClassCount("FZZWTblGrid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid::FZZWTblGrid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)//,m_FZZWTblInd(NULL),m_FZZWTblCellMar(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblGrid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid::FZZWTblGrid(FZZOfficeObject * parent) : FZZXMLElementObject(parent)//,m_FZZWTblInd(NULL),m_FZZWTblCellMar(NULL)
{
    FZZConst::addClassCount("FZZWTblGrid");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid::FZZWTblGrid(const FZZWTblGrid& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblGrid");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWTblInd = obj.m_FZZWTblInd != NULL ? new FZZWTblInd(*obj.m_FZZWTblInd) : NULL;
    //m_FZZWTblCellMar = obj.m_FZZWTblCellMar != NULL ? new FZZWTblCellMar(*obj.m_FZZWTblCellMar) : NULL;
    
    vector<FZZWGridCol*>::const_iterator itr;
    for( itr = obj.m_FZZWGridCols.begin(); itr != obj.m_FZZWGridCols.end(); itr++ ) {
        FZZWGridCol * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWGridCols.push_back(new FZZWGridCol(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblGrid::~FZZWTblGrid()
{
    //DLOG("~FZZWTblGrid()");
    FZZConst::delClassCount("FZZWTblGrid");
    
    
//    if ( m_FZZWTblInd != NULL ) {
//        delete m_FZZWTblInd;
//        m_FZZWTblInd = NULL;
//    }
//    if ( m_FZZWTblCellMar != NULL ) {
//        delete m_FZZWTblCellMar;
//        m_FZZWTblCellMar = NULL;
//    }
    vector<FZZWGridCol*>::const_iterator itr;
    for( itr = m_FZZWGridCols.begin(); itr != m_FZZWGridCols.end(); itr++ ) {
        FZZWGridCol * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWGridCols.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridCol * FZZWTblGrid::addGridCol()
{
    return addElementObject(&m_FZZWGridCols,FZZWGRIDCOL_Find_Key,FZZWGRIDCOL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWGridCol*> * FZZWTblGrid::getGridColList()
{
    getElementObjectList(&m_FZZWGridCols,FZZWGRIDCOL_Find_Key,FZZWGRIDCOL_Name);
    return &m_FZZWGridCols;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
