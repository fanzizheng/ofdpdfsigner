//
//  Created by zizheng fan on 2023/07/11
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAXfrm.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAXfrm**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm::FZZAXfrm() : FZZXMLElementObject(),m_FZZAOff(NULL),m_FZZAExt(NULL)
{
    //DLOG("FZZAXfrm()");
    FZZConst::addClassCount("FZZAXfrm");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm::FZZAXfrm(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAOff(NULL),m_FZZAExt(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAXfrm");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm::FZZAXfrm(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAOff(NULL),m_FZZAExt(NULL)
{
    FZZConst::addClassCount("FZZAXfrm");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm::FZZAXfrm(const FZZAXfrm& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAXfrm");
    if ( this == &obj ) {
        return;
    }
    m_FZZAOff = obj.m_FZZAOff != NULL ? new FZZAOff(*obj.m_FZZAOff) : NULL;
    m_FZZAExt = obj.m_FZZAExt != NULL ? new FZZAExt(*obj.m_FZZAExt) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm::~FZZAXfrm()
{
    //DLOG("~FZZAXfrm()");
    FZZConst::delClassCount("FZZAXfrm");
    if ( m_FZZAOff != NULL ) {
        delete m_FZZAOff;
        m_FZZAOff = NULL;
    }
    if ( m_FZZAExt != NULL ) {
        delete m_FZZAExt;
        m_FZZAExt = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAXfrm::setRot(string value)
{
    setAttribute_String("rot",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAXfrm::getRot()
{
    return getAttribute_String("rot");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAOff * FZZAXfrm::setOff()
{
    return m_FZZAOff = setElementObject(m_FZZAOff,FZZAOFF_Find_Key,FZZAOFF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAOff * FZZAXfrm::getOff()
{
    return m_FZZAOff = getElementObject(m_FZZAOff,FZZAOFF_Find_Key,FZZAOFF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExt * FZZAXfrm::setExt()
{
    return m_FZZAExt = setElementObject(m_FZZAExt,FZZAEXT_Find_Key,FZZAEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExt * FZZAXfrm::getExt()
{
    return m_FZZAExt = getElementObject(m_FZZAExt,FZZAEXT_Find_Key,FZZAEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
