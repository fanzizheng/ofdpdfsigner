//
//  Created by zizheng fan on 2023/07/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicData.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAGraphicData**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData::FZZAGraphicData() : FZZXMLElementObject(),m_FZZPICPic(NULL),m_FZZWPSWsp(NULL)
{
    //DLOG("FZZAGraphicData()");
    FZZConst::addClassCount("FZZAGraphicData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData::FZZAGraphicData(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZPICPic(NULL),m_FZZWPSWsp(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAGraphicData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData::FZZAGraphicData(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZPICPic(NULL),m_FZZWPSWsp(NULL)
{
    FZZConst::addClassCount("FZZAGraphicData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData::FZZAGraphicData(const FZZAGraphicData& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAGraphicData");
    if ( this == &obj ) {
        return;
    }
    m_FZZPICPic = obj.m_FZZPICPic != NULL ? new FZZPICPic(*obj.m_FZZPICPic) : NULL;
    m_FZZWPSWsp = obj.m_FZZWPSWsp != NULL ? new FZZWPSWsp(*obj.m_FZZWPSWsp) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData::~FZZAGraphicData()
{
    //DLOG("~FZZAGraphicData()");
    FZZConst::delClassCount("FZZAGraphicData");
    if ( m_FZZPICPic != NULL ) {
        delete m_FZZPICPic;
        m_FZZPICPic = NULL;
    }
    if ( m_FZZWPSWsp != NULL ) {
        delete m_FZZWPSWsp;
        m_FZZWPSWsp = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAGraphicData::setUri(string value)
{
    setAttribute_String("uri",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAGraphicData::getUri()
{
    return getAttribute_String("uri");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic * FZZAGraphicData::setPic()
{
    return m_FZZPICPic = setElementObject(m_FZZPICPic,FZZPICPIC_Find_Key,FZZPICPIC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic * FZZAGraphicData::getPic()
{
    return m_FZZPICPic = getElementObject(m_FZZPICPic,FZZPICPIC_Find_Key,FZZPICPIC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp * FZZAGraphicData::setWsp()
{
    return m_FZZWPSWsp = setElementObject(m_FZZWPSWsp,FZZWPSWSP_Find_Key,FZZWPSWSP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp * FZZAGraphicData::getWsp()
{
    return m_FZZWPSWsp = getElementObject(m_FZZWPSWsp,FZZWPSWSP_Find_Key,FZZWPSWSP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
