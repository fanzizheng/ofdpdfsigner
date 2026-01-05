//
//  Created by zizheng fan on 2023/11/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTrPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr::FZZWTrPr() : FZZXMLElementObject(),m_FZZWTrHeight(NULL),m_FZZWTblHeader(NULL)
{
    //DLOG("FZZWTrPr()");
    FZZConst::addClassCount("FZZWTrPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr::FZZWTrPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWTrHeight(NULL),m_FZZWTblHeader(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTrPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr::FZZWTrPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTrHeight(NULL),m_FZZWTblHeader(NULL)
{
    FZZConst::addClassCount("FZZWTrPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr::FZZWTrPr(const FZZWTrPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTrPr");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZWTrHeight = obj.m_FZZWTrHeight != NULL ? new FZZWTrHeight(*obj.m_FZZWTrHeight) : NULL;
    m_FZZWTblHeader = obj.m_FZZWTblHeader != NULL ? new FZZWTblHeader(*obj.m_FZZWTblHeader) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr::~FZZWTrPr()
{
    //DLOG("~FZZWTrPr()");
    FZZConst::delClassCount("FZZWTrPr");
    
    if ( m_FZZWTrHeight != NULL ) {
        delete m_FZZWTrHeight;
        m_FZZWTrHeight = NULL;
    }

    if ( m_FZZWTblHeader != NULL ) {
        delete m_FZZWTblHeader;
        m_FZZWTblHeader = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight * FZZWTrPr::setTrHeight()
{
    return m_FZZWTrHeight = setElementObject(m_FZZWTrHeight,FZZWTRHEIGHT_Find_Key,FZZWTRHEIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight * FZZWTrPr::getTrHeight()
{
    return m_FZZWTrHeight = getElementObject(m_FZZWTrHeight,FZZWTRHEIGHT_Find_Key,FZZWTRHEIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader * FZZWTrPr::setTblHeader()
{
    return m_FZZWTblHeader = setElementObject(m_FZZWTblHeader,FZZWTBLHEADER_Find_Key,FZZWTBLHEADER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader * FZZWTrPr::getTblHeader()
{
    return m_FZZWTblHeader = getElementObject(m_FZZWTblHeader,FZZWTBLHEADER_Find_Key,FZZWTBLHEADER_Name);
}
//-----------------------------------------------------------------------------------------------------------------

