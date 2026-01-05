//
//  Created by zizheng fan on 2023/08/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgs.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAgs**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAgs::FZZAgs() : FZZXMLElementObject(),m_CTschemeClr(NULL)
{
    //DLOG("FZZAgs()");
    FZZConst::addClassCount("FZZAgs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgs::FZZAgs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) :
    FZZXMLElementObject(parent,doc,node,key,false),m_CTschemeClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAgs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgs::FZZAgs(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTschemeClr(NULL)
{
    FZZConst::addClassCount("FZZAgs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgs::FZZAgs(const FZZAgs& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAgs");
    if ( this == &obj ) {
        return;
    }
    m_CTschemeClr = obj.m_CTschemeClr != NULL ? new FZZAschemeClr(*obj.m_CTschemeClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgs::~FZZAgs()
{
    //DLOG("~FZZAgs()");
    FZZConst::delClassCount("FZZAgs");
    if ( m_CTschemeClr != NULL ) {
        delete m_CTschemeClr;
        m_CTschemeClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAgs::setPos(string value)
{
    setAttribute_String("pos",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAgs::getPos()
{
    return getAttribute_String("pos");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAgs::setSchemeClr()
{
    return m_CTschemeClr = setElementObject(m_CTschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAgs::getSchemeClr()
{
    return m_CTschemeClr = getElementObject(m_CTschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
