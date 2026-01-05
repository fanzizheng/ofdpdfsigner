//
//  Created by zizheng fan on 2023/11/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWEndnote.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWEndnote**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWEndnote::FZZWEndnote() : FZZXMLElementObject(),m_FZZWP(NULL)
{
    //DLOG("FZZWEndnote()");
    FZZConst::addClassCount("FZZWEndnote");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEndnote::FZZWEndnote(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWP(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWEndnote");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEndnote::FZZWEndnote(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWP(NULL)
{
    FZZConst::addClassCount("FZZWEndnote");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEndnote::FZZWEndnote(const FZZWEndnote& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWEndnote");
    if ( this == &obj ) {
        return;
    }

    m_FZZWP = obj.m_FZZWP != NULL ? new FZZWP(*obj.m_FZZWP) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEndnote::~FZZWEndnote()
{
    //DLOG("~FZZWEndnote()");
    FZZConst::delClassCount("FZZWEndnote");
    
    if ( m_FZZWP != NULL ) {
        delete m_FZZWP;
        m_FZZWP = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWEndnote::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWEndnote::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWEndnote::setId(string value)
{
    setAttribute_String("w:id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWEndnote::getId()
{
    return getAttribute_String("w:id");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWEndnote::setP()
{
    return m_FZZWP = setElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWEndnote::getP()
{
    return m_FZZWP = getElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
