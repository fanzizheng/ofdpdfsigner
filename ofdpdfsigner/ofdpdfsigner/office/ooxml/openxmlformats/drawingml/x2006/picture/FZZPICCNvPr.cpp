//
//  Created by zizheng fan on 2023/06/02
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICCNvPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPICCNvPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr::FZZPICCNvPr() : FZZXMLElementObject()
{
    //DLOG("FZZPICCNvPr()");
    FZZConst::addClassCount("FZZPICCNvPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr::FZZPICCNvPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZPICCNvPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr::FZZPICCNvPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZPICCNvPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr::FZZPICCNvPr(const FZZPICCNvPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZPICCNvPr");
    if ( this == &obj ) {
        return;
    }
    //m_FZZAGraphicData = obj.m_FZZAGraphicData != NULL ? new FZZAGraphicData(*obj.m_FZZAGraphicData) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr::~FZZPICCNvPr()
{
    //DLOG("~FZZPICCNvPr()");
    FZZConst::delClassCount("FZZPICCNvPr");
//    if ( m_FZZAGraphicData != NULL ) {
//        delete m_FZZAGraphicData;
//        m_FZZAGraphicData = NULL;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPICCNvPr::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZPICCNvPr::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPICCNvPr::setName(string value)
{
    setAttribute_String("name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZPICCNvPr::getName()
{
    return getAttribute_String("name");
}
//-----------------------------------------------------------------------------------------------------------------
//FZZAGraphicData * FZZPICCNvPr::setGraphicData()
//{
//    return m_FZZAGraphicData = setElementObject(m_FZZAGraphicData,FZZAGRAPHICDATA_Find_Key,FZZAGRAPHICDATA_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZAGraphicData * FZZPICCNvPr::getGraphicData()
//{
//    return m_FZZAGraphicData = getElementObject(m_FZZAGraphicData,FZZAGRAPHICDATA_Find_Key,FZZAGRAPHICDATA_Name);
//}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
