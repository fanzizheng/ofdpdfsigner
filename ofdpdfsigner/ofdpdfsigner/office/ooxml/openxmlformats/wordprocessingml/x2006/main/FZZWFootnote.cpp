//
//  Created by zizheng fan on 2023/11/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFootnote.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWFootnote**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWFootnote::FZZWFootnote() : FZZXMLElementObject(),m_FZZWP(NULL)
{
    //DLOG("FZZWFootnote()");
    FZZConst::addClassCount("FZZWFootnote");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFootnote::FZZWFootnote(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWP(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWFootnote");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFootnote::FZZWFootnote(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWP(NULL)
{
    FZZConst::addClassCount("FZZWFootnote");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFootnote::FZZWFootnote(const FZZWFootnote& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWFootnote");
    if ( this == &obj ) {
        return;
    }

    m_FZZWP = obj.m_FZZWP != NULL ? new FZZWP(*obj.m_FZZWP) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFootnote::~FZZWFootnote()
{
    //DLOG("~FZZWFootnote()");
    FZZConst::delClassCount("FZZWFootnote");
    
    if ( m_FZZWP != NULL ) {
        delete m_FZZWP;
        m_FZZWP = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFootnote::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFootnote::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFootnote::setId(string value)
{
    setAttribute_String("w:id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFootnote::getId()
{
    return getAttribute_String("w:id");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWFootnote::setP()
{
    return m_FZZWP = setElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWFootnote::getP()
{
    return m_FZZWP = getElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
