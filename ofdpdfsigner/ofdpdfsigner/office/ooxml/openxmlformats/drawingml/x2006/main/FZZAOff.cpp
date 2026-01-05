//
//  Created by zizheng fan on 2023/07/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAOff.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAOff**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAOff::FZZAOff() : FZZXMLElementObject()//,m_FZZAExtLst(NULL)
{
    //DLOG("FZZAOff()");
    FZZConst::addClassCount("FZZAOff");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAOff::FZZAOff(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)//,m_FZZAExtLst(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAOff");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAOff::FZZAOff(FZZOfficeObject * parent) : FZZXMLElementObject(parent)//,m_FZZAExtLst(NULL)
{
    FZZConst::addClassCount("FZZAOff");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAOff::FZZAOff(const FZZAOff& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAOff");
    if ( this == &obj ) {
        return;
    }
    //m_FZZAExtLst = obj.m_FZZAExtLst != NULL ? new FZZAExtLst(*obj.m_FZZAExtLst) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAOff::~FZZAOff()
{
    //DLOG("~FZZAOff()");
    FZZConst::delClassCount("FZZAOff");
//    if ( m_FZZAExtLst != NULL ) {
//        delete m_FZZAExtLst;
//        m_FZZAExtLst = NULL;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAOff::setX(string value)
{
    setAttribute_String("x",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAOff::getX()
{
    return getAttribute_String("x");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAOff::setY(string value)
{
    setAttribute_String("y",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAOff::getY()
{
    return getAttribute_String("y");
}
//-----------------------------------------------------------------------------------------------------------------
//FZZAExtLst * FZZAOff::setExtLst()
//{
//    return m_FZZAExtLst = setElementObject(m_FZZAExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZAExtLst * FZZAOff::getExtLst()
//{
//    return m_FZZAExtLst = getElementObject(m_FZZAExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
//}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
