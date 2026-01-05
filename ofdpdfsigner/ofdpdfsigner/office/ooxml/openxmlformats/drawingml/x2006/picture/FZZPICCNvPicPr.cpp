//
//  Created by zizheng fan on 2023/06/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICCNvPicPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPICCNvPicPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr::FZZPICCNvPicPr() : FZZXMLElementObject()
{
    //DLOG("FZZPICCNvPicPr()");
    FZZConst::addClassCount("FZZPICCNvPicPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr::FZZPICCNvPicPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZPICCNvPicPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr::FZZPICCNvPicPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZPICCNvPicPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr::FZZPICCNvPicPr(const FZZPICCNvPicPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZPICCNvPicPr");
    if ( this == &obj ) {
        return;
    }
    //m_FZZAGraphicData = obj.m_FZZAGraphicData != NULL ? new FZZAGraphicData(*obj.m_FZZAGraphicData) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr::~FZZPICCNvPicPr()
{
    //DLOG("~FZZPICCNvPicPr()");
    FZZConst::delClassCount("FZZPICCNvPicPr");
//    if ( m_FZZAGraphicData != NULL ) {
//        delete m_FZZAGraphicData;
//        m_FZZAGraphicData = NULL;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZPICCNvPicPr::setXmlnsPic(string value)
//{
//    setAttribute_String("xmlns:pic",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZPICCNvPicPr::getXmlnsPic()
//{
//    return getAttribute_String("xmlns:pic");
//}
//-----------------------------------------------------------------------------------------------------------------
//FZZAGraphicData * FZZPICCNvPicPr::setGraphicData()
//{
//    return m_FZZAGraphicData = setElementObject(m_FZZAGraphicData,FZZAGRAPHICDATA_Find_Key,FZZAGRAPHICDATA_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZAGraphicData * FZZPICCNvPicPr::getGraphicData()
//{
//    return m_FZZAGraphicData = getElementObject(m_FZZAGraphicData,FZZAGRAPHICDATA_Find_Key,FZZAGRAPHICDATA_Name);
//}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
