//
//  Created by zizheng fan on 2023/07/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZABlip.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZABlip**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZABlip::FZZABlip() : FZZXMLElementObject(),m_FZZAExtLst(NULL)
{
    //DLOG("FZZABlip()");
    FZZConst::addClassCount("FZZABlip");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZABlip::FZZABlip(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAExtLst(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZABlip");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZABlip::FZZABlip(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAExtLst(NULL)
{
    FZZConst::addClassCount("FZZABlip");
}
//-----------------------------------------------------------------------------------------------------------------
FZZABlip::FZZABlip(const FZZABlip& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZABlip");
    if ( this == &obj ) {
        return;
    }
    m_FZZAExtLst = obj.m_FZZAExtLst != NULL ? new FZZAExtLst(*obj.m_FZZAExtLst) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZABlip::~FZZABlip()
{
    //DLOG("~FZZABlip()");
    FZZConst::delClassCount("FZZABlip");
    if ( m_FZZAExtLst != NULL ) {
        delete m_FZZAExtLst;
        m_FZZAExtLst = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZABlip::setEmbed(string value)
{
    setAttribute_String("r:embed",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZABlip::getEmbed()
{
    return getAttribute_String("r:embed");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst * FZZABlip::setExtLst()
{
    return m_FZZAExtLst = setElementObject(m_FZZAExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst * FZZABlip::getExtLst()
{
    return m_FZZAExtLst = getElementObject(m_FZZAExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
