//
//  Created by zizheng fan on 2023/07/04
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAAvLst.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAAvLst**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst::FZZAAvLst() : FZZXMLElementObject(),m_FZZAGd(NULL)
{
    //DLOG("FZZAAvLst()");
    FZZConst::addClassCount("FZZAAvLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst::FZZAAvLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAGd(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAAvLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst::FZZAAvLst(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAGd(NULL)
{
    FZZConst::addClassCount("FZZAAvLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst::FZZAAvLst(const FZZAAvLst& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAAvLst");
    if ( this == &obj ) {
        return;
    }
    m_FZZAGd = obj.m_FZZAGd != NULL ? new FZZAGd(*obj.m_FZZAGd) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst::~FZZAAvLst()
{
    //DLOG("~FZZAAvLst()");
    FZZConst::delClassCount("FZZAAvLst");
    if ( m_FZZAGd != NULL ) {
        delete m_FZZAGd;
        m_FZZAGd = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZAAvLst::setEmbed(string value)
//{
//    setAttribute_String("r:embed",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZAAvLst::getEmbed()
//{
//    return getAttribute_String("r:embed");
//}
////-----------------------------------------------------------------------------------------------------------------
FZZAGd * FZZAAvLst::setGd()
{
    return m_FZZAGd = setElementObject(m_FZZAGd,FZZAGD_Find_Key,FZZAGD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGd * FZZAAvLst::getGd()
{
    return m_FZZAGd = getElementObject(m_FZZAGd,FZZAGD_Find_Key,FZZAGD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
