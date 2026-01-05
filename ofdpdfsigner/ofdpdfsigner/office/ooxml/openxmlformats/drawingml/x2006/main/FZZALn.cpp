//
//  Created by zizheng fan on 2023/07/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZALn.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZALn**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZALn::FZZALn() : FZZXMLElementObject(),m_CTsolidFill(NULL),m_CTmiter(NULL),m_CTprstDash(NULL)
{
    //DLOG("FZZALn()");
    FZZConst::addClassCount("FZZALn");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn::FZZALn(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) :
    FZZXMLElementObject(parent,doc,node,key,false),m_CTsolidFill(NULL),m_CTmiter(NULL),m_CTprstDash(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZALn");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn::FZZALn(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTsolidFill(NULL),m_CTmiter(NULL),m_CTprstDash(NULL)
{
    FZZConst::addClassCount("FZZALn");
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn::FZZALn(const FZZALn& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZALn");
    if ( this == &obj ) {
        return;
    }
    m_CTsolidFill = obj.m_CTsolidFill != NULL ? new FZZAsolidFill(*obj.m_CTsolidFill) : NULL;
    m_CTmiter = obj.m_CTmiter != NULL ? new FZZAmiter(*obj.m_CTmiter) : NULL;
    m_CTprstDash = obj.m_CTprstDash != NULL ? new FZZAprstDash(*obj.m_CTprstDash) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn::~FZZALn()
{
    //DLOG("~FZZALn()");
    FZZConst::delClassCount("FZZALn");
    if ( m_CTsolidFill != NULL ) {
        delete m_CTsolidFill;
        m_CTsolidFill = NULL;
    }
    
    if ( m_CTmiter != NULL ) {
        delete m_CTmiter;
        m_CTmiter = NULL;
    }
    
    if ( m_CTprstDash != NULL ) {
        delete m_CTprstDash;
        m_CTprstDash = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZALn::setW(string value)
{
    setAttribute_String("w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZALn::getW()
{
    return getAttribute_String("w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZALn::setCap(string value)
{
    setAttribute_String("cap",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZALn::getCap()
{
    return getAttribute_String("cap");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZALn::setCmpd(string value)
{
    setAttribute_String("cmpd",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZALn::getCmpd()
{
    return getAttribute_String("cmpd");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZALn::setAlgn(string value)
{
    setAttribute_String("algn",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZALn::getAlgn()
{
    return getAttribute_String("algn");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill * FZZALn::setSolidFill()
{
    return m_CTsolidFill = setElementObject(m_CTsolidFill,FZZASOLIDFILL_Find_Key,FZZASOLIDFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill * FZZALn::getSolidFill()
{
    return m_CTsolidFill = getElementObject(m_CTsolidFill,FZZASOLIDFILL_Find_Key,FZZASOLIDFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter * FZZALn::setMiter()
{
    return m_CTmiter = setElementObject(m_CTmiter,FZZAMITER_Find_Key,FZZAMITER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter * FZZALn::getMiter()
{
    return m_CTmiter = getElementObject(m_CTmiter,FZZAMITER_Find_Key,FZZAMITER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash * FZZALn::setPrstDash()
{
    return m_CTprstDash = setElementObject(m_CTprstDash,FZZAPRSTDASH_Find_Key,FZZAPRSTDASH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash * FZZALn::getPrstDash()
{
    return m_CTprstDash = getElementObject(m_CTprstDash,FZZAPRSTDASH_Find_Key,FZZAPRSTDASH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
