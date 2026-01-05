//
//  Created by zizheng fan on 2023/07/05
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFillRect.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAFillRect**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect::FZZAFillRect() : FZZXMLElementObject()
{
    //DLOG("FZZAFillRect()");
    FZZConst::addClassCount("FZZAFillRect");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect::FZZAFillRect(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAFillRect");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect::FZZAFillRect(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAFillRect");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect::FZZAFillRect(const FZZAFillRect& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAFillRect");
    if ( this == &obj ) {
        return;
    }
    //m_FZZAExtLst = obj.m_FZZAExtLst != NULL ? new FZZAExtLst(*obj.m_FZZAExtLst) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect::~FZZAFillRect()
{
    //DLOG("~FZZAFillRect()");
    FZZConst::delClassCount("FZZAFillRect");
//    if ( m_FZZAExtLst != NULL ) {
//        delete m_FZZAExtLst;
//        m_FZZAExtLst = NULL;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZAFillRect::setEmbed(string value)
//{
//    setAttribute_String("r:embed",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZAFillRect::getEmbed()
//{
//    return getAttribute_String("r:embed");
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZAExtLst * FZZAFillRect::setExtLst()
//{
//    return m_FZZAExtLst = setElementObject(m_FZZAExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZAExtLst * FZZAFillRect::getExtLst()
//{
//    return m_FZZAExtLst = getElementObject(m_FZZAExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
//}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
