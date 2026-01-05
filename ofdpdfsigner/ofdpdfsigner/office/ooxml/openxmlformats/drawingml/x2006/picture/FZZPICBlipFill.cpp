//
//  Created by zizheng fan on 2023/05/31
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICBlipFill.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPICBlipFill**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill::FZZPICBlipFill() : FZZXMLElementObject(),m_FZZABlip(NULL),m_FZZAStretch(NULL)
{
    //DLOG("FZZPICBlipFill()");
    FZZConst::addClassCount("FZZPICBlipFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill::FZZPICBlipFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZABlip(NULL),m_FZZAStretch(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZPICBlipFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill::FZZPICBlipFill(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZABlip(NULL),m_FZZAStretch(NULL)
{
    FZZConst::addClassCount("FZZPICBlipFill");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill::FZZPICBlipFill(const FZZPICBlipFill& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZPICBlipFill");
    if ( this == &obj ) {
        return;
    }
    m_FZZABlip = obj.m_FZZABlip != NULL ? new FZZABlip(*obj.m_FZZABlip) : NULL;
    m_FZZAStretch = obj.m_FZZAStretch != NULL ? new FZZAStretch(*obj.m_FZZAStretch) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill::~FZZPICBlipFill()
{
    //DLOG("~FZZPICBlipFill()");
    FZZConst::delClassCount("FZZPICBlipFill");
    if ( m_FZZABlip != NULL ) {
        delete m_FZZABlip;
        m_FZZABlip = NULL;
    }
    if ( m_FZZAStretch != NULL ) {
        delete m_FZZAStretch;
        m_FZZAStretch = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZPICBlipFill::setXmlnsPic(string value)
//{
//    setAttribute_String("xmlns:pic",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZPICBlipFill::getXmlnsPic()
//{
//    return getAttribute_String("xmlns:pic");
//}
//-----------------------------------------------------------------------------------------------------------------
FZZABlip * FZZPICBlipFill::setBlip()
{
    return m_FZZABlip = setElementObject(m_FZZABlip,FZZABLIP_Find_Key,FZZABLIP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZABlip * FZZPICBlipFill::getBlip()
{
    return m_FZZABlip = getElementObject(m_FZZABlip,FZZABLIP_Find_Key,FZZABLIP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch * FZZPICBlipFill::setStretch()
{
    return m_FZZAStretch = setElementObject(m_FZZAStretch,FZZASTRETCH_Find_Key,FZZASTRETCH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch * FZZPICBlipFill::getStretch()
{
    return m_FZZAStretch = getElementObject(m_FZZAStretch,FZZASTRETCH_Find_Key,FZZASTRETCH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
