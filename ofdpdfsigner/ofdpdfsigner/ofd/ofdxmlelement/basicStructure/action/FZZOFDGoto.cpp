//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDGoto.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDGoto**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto::FZZOFDGoto() : FZZOFDXMLElementObject(),m_FZZOFDDest(NULL),m_FZZOFDBookmark(NULL)
{
    //DLOG("FZZOFDGoto()");
    FZZConst::addClassCount("FZZOFDGoto");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto::FZZOFDGoto(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDDest(NULL),m_FZZOFDBookmark(NULL)
{
    
    FZZConst::addClassCount("FZZOFDGoto");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto::FZZOFDGoto(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDDest(NULL),m_FZZOFDBookmark(NULL)
{
    FZZConst::addClassCount("FZZOFDGoto");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto::FZZOFDGoto(const FZZOFDGoto& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDGoto");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDDest = obj.m_FZZOFDDest != NULL ? new FZZOFDDest(*obj.m_FZZOFDDest) : NULL;
    m_FZZOFDBookmark = obj.m_FZZOFDBookmark != NULL ? new FZZOFDBookmark(*obj.m_FZZOFDBookmark) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto::~FZZOFDGoto()
{
    //DLOG("~FZZOFDGoto()");
    FZZConst::delClassCount("FZZOFDGoto");
    if ( m_FZZOFDDest != NULL ) {
        delete m_FZZOFDDest;
        m_FZZOFDDest = NULL;
    }
    if ( m_FZZOFDBookmark != NULL ) {
        delete m_FZZOFDBookmark;
        m_FZZOFDBookmark = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest * FZZOFDGoto::setDest()
{
    deleteObject();
    return m_FZZOFDDest = setElementObject(m_FZZOFDDest,FZZOFDDEST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest * FZZOFDGoto::getDest()
{
    return m_FZZOFDDest = getElementObject(m_FZZOFDDest,FZZOFDDEST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark * FZZOFDGoto::setBookmark()
{
    deleteObject();
    return m_FZZOFDBookmark = setElementObject(m_FZZOFDBookmark,FZZOFDBOOKMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark * FZZOFDGoto::getBookmark()
{
    return m_FZZOFDBookmark = getElementObject(m_FZZOFDBookmark,FZZOFDBOOKMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGoto::deleteObject()
{
    if ( m_FZZOFDDest != NULL ) {
        delete m_FZZOFDDest;
        m_FZZOFDDest = NULL;
    }
    if ( m_FZZOFDBookmark != NULL ) {
        delete m_FZZOFDBookmark;
        m_FZZOFDBookmark = NULL;
    }
    deleteElement(FZZOFDDEST_Name);
    deleteElement(FZZOFDBOOKMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
