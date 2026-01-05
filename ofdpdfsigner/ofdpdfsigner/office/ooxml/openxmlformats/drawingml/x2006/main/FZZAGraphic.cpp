//
//  Created by zizheng fan on 2023/07/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphic.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAGraphic**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic::FZZAGraphic() : FZZXMLElementObject(),m_FZZAGraphicData(NULL)
{
    //DLOG("FZZAGraphic()");
    FZZConst::addClassCount("FZZAGraphic");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic::FZZAGraphic(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAGraphicData(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAGraphic");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic::FZZAGraphic(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAGraphicData(NULL)
{
    FZZConst::addClassCount("FZZAGraphic");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic::FZZAGraphic(const FZZAGraphic& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAGraphic");
    if ( this == &obj ) {
        return;
    }
    m_FZZAGraphicData = obj.m_FZZAGraphicData != NULL ? new FZZAGraphicData(*obj.m_FZZAGraphicData) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic::~FZZAGraphic()
{
    //DLOG("~FZZAGraphic()");
    FZZConst::delClassCount("FZZAGraphic");
    if ( m_FZZAGraphicData != NULL ) {
        delete m_FZZAGraphicData;
        m_FZZAGraphicData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAGraphic::setXmlnsA(string value)
{
    setAttribute_String("xmlns:a",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAGraphic::getXmlnsA()
{
    return getAttribute_String("xmlns:a");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData * FZZAGraphic::setGraphicData()
{
    return m_FZZAGraphicData = setElementObject(m_FZZAGraphicData,FZZAGRAPHICDATA_Find_Key,FZZAGRAPHICDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicData * FZZAGraphic::getGraphicData()
{
    return m_FZZAGraphicData = getElementObject(m_FZZAGraphicData,FZZAGRAPHICDATA_Find_Key,FZZAGRAPHICDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
