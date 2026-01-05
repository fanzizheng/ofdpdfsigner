//
//  Created by zizheng fan on 2023/07/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstGeom.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAPrstGeom**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom::FZZAPrstGeom() : FZZXMLElementObject(),m_FZZAAvLst(NULL)
{
    //DLOG("FZZAPrstGeom()");
    FZZConst::addClassCount("FZZAPrstGeom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom::FZZAPrstGeom(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAAvLst(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAPrstGeom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom::FZZAPrstGeom(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAAvLst(NULL)
{
    FZZConst::addClassCount("FZZAPrstGeom");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom::FZZAPrstGeom(const FZZAPrstGeom& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAPrstGeom");
    if ( this == &obj ) {
        return;
    }
    m_FZZAAvLst = obj.m_FZZAAvLst != NULL ? new FZZAAvLst(*obj.m_FZZAAvLst) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom::~FZZAPrstGeom()
{
    //DLOG("~FZZAPrstGeom()");
    FZZConst::delClassCount("FZZAPrstGeom");
    if ( m_FZZAAvLst != NULL ) {
        delete m_FZZAAvLst;
        m_FZZAAvLst = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAPrstGeom::setPrst(string value)
{
    setAttribute_String("prst",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAPrstGeom::getPrst()
{
    return getAttribute_String("prst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst * FZZAPrstGeom::setAvLst()
{
    return m_FZZAAvLst = setElementObject(m_FZZAAvLst,FZZAAVLST_Find_Key,FZZAAVLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst * FZZAPrstGeom::getAvLst()
{
    return m_FZZAAvLst = getElementObject(m_FZZAAvLst,FZZAAVLST_Find_Key,FZZAAVLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
