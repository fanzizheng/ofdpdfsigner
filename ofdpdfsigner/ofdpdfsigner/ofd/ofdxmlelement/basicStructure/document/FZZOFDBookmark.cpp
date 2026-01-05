//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmark.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBookmark**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark::FZZOFDBookmark() : FZZOFDXMLElementObject(),m_FZZOFDDest(NULL)
{
    //DLOG("FZZOFDBookmark()");
    FZZConst::addClassCount("FZZOFDBookmark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark::FZZOFDBookmark(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false),m_FZZOFDDest(NULL)
{
    
    FZZConst::addClassCount("FZZOFDBookmark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark::FZZOFDBookmark(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDDest(NULL)
{
    FZZConst::addClassCount("FZZOFDBookmark");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark::FZZOFDBookmark(const FZZOFDBookmark& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDBookmark");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDDest = obj.m_FZZOFDDest != NULL ? new FZZOFDDest(*obj.m_FZZOFDDest) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark::~FZZOFDBookmark()
{
    //DLOG("~FZZOFDBookmark()");
    FZZConst::delClassCount("FZZOFDBookmark");
    if ( m_FZZOFDDest != NULL ) {
        delete m_FZZOFDDest;
        m_FZZOFDDest = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBookmark::setName(string value)
{
    setAttribute_String("Name", value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBookmark::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest * FZZOFDBookmark::setDest()
{
    return m_FZZOFDDest = setElementObject(m_FZZOFDDest,FZZOFDDEST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest * FZZOFDBookmark::getDest()
{
    return m_FZZOFDDest = getElementObject(m_FZZOFDDest,FZZOFDDEST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
