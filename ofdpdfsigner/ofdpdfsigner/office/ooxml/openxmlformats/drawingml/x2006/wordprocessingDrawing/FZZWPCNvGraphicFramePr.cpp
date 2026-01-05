//
//  Created by zizheng fan on 2023/06/19
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPCNvGraphicFramePr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPCNvGraphicFramePr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr::FZZWPCNvGraphicFramePr() : FZZXMLElementObject(),m_FZZAGraphicFrameLocks(NULL)
{
    //DLOG("FZZWPCNvGraphicFramePr()");
    FZZConst::addClassCount("FZZWPCNvGraphicFramePr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr::FZZWPCNvGraphicFramePr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAGraphicFrameLocks(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPCNvGraphicFramePr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr::FZZWPCNvGraphicFramePr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAGraphicFrameLocks(NULL)
{
    FZZConst::addClassCount("FZZWPCNvGraphicFramePr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr::FZZWPCNvGraphicFramePr(const FZZWPCNvGraphicFramePr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPCNvGraphicFramePr");
    if ( this == &obj ) {
        return;
    }
    m_FZZAGraphicFrameLocks = obj.m_FZZAGraphicFrameLocks != NULL ? new FZZAGraphicFrameLocks(*obj.m_FZZAGraphicFrameLocks) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr::~FZZWPCNvGraphicFramePr()
{
    //DLOG("~FZZWPCNvGraphicFramePr()");
    FZZConst::delClassCount("FZZWPCNvGraphicFramePr");
    if ( m_FZZAGraphicFrameLocks != NULL ) {
        delete m_FZZAGraphicFrameLocks;
        m_FZZAGraphicFrameLocks = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWPCNvGraphicFramePr::setVal(string value)
//{
//    setAttribute_String("val",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWPCNvGraphicFramePr::getVal()
//{
//    return getAttribute_String("val");
//}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks * FZZWPCNvGraphicFramePr::setGraphicFrameLocks()
{
    return m_FZZAGraphicFrameLocks = setElementObject(m_FZZAGraphicFrameLocks,FZZAGRAPHICFRAMELOCKS_Find_Key,FZZAGRAPHICFRAMELOCKS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks * FZZWPCNvGraphicFramePr::getGraphicFrameLocks()
{
    return m_FZZAGraphicFrameLocks = getElementObject(m_FZZAGraphicFrameLocks,FZZAGRAPHICFRAMELOCKS_Find_Key,FZZAGRAPHICFRAMELOCKS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
