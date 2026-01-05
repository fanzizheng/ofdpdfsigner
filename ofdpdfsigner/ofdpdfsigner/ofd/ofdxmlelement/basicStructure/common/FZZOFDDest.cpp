//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDDest.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDest**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest::FZZOFDDest() : FZZOFDXMLElementObject(),m_FZZOFDLeft(NULL),m_FZZOFDRight(NULL),m_FZZOFDTop(NULL),m_FZZOFDBottom(NULL),m_FZZOFDZoom(NULL)
{
    //DLOG("FZZOFDDest()");
    FZZConst::addClassCount("FZZOFDDest");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest::FZZOFDDest(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDLeft(NULL),m_FZZOFDRight(NULL),m_FZZOFDTop(NULL),m_FZZOFDBottom(NULL),m_FZZOFDZoom(NULL)
{
    
    FZZConst::addClassCount("FZZOFDDest");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest::FZZOFDDest(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDLeft(NULL),m_FZZOFDRight(NULL),m_FZZOFDTop(NULL)
,m_FZZOFDBottom(NULL),m_FZZOFDZoom(NULL)
{
    FZZConst::addClassCount("FZZOFDDest");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest::FZZOFDDest(const FZZOFDDest& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDest");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDLeft = obj.m_FZZOFDLeft != NULL ? new FZZOFDLeft(*obj.m_FZZOFDLeft) : NULL;
    m_FZZOFDRight = obj.m_FZZOFDRight != NULL ? new FZZOFDRight(*obj.m_FZZOFDRight) : NULL;
    m_FZZOFDTop = obj.m_FZZOFDTop != NULL ? new FZZOFDTop(*obj.m_FZZOFDTop) : NULL;
    m_FZZOFDBottom = obj.m_FZZOFDBottom != NULL ? new FZZOFDBottom(*obj.m_FZZOFDBottom) : NULL;
    m_FZZOFDZoom = obj.m_FZZOFDZoom != NULL ? new FZZOFDZoom(*obj.m_FZZOFDZoom) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDest::~FZZOFDDest()
{
    //DLOG("~FZZOFDDest()");
    FZZConst::delClassCount("FZZOFDDest");
    if ( m_FZZOFDLeft != NULL ) {
        delete m_FZZOFDLeft;
        m_FZZOFDLeft = NULL;
    }
    if ( m_FZZOFDRight != NULL ) {
        delete m_FZZOFDRight;
        m_FZZOFDRight = NULL;
    }
    if ( m_FZZOFDTop != NULL ) {
        delete m_FZZOFDTop;
        m_FZZOFDTop = NULL;
    }
    if ( m_FZZOFDBottom != NULL ) {
        delete m_FZZOFDBottom;
        m_FZZOFDBottom = NULL;
    }
    if ( m_FZZOFDZoom != NULL ) {
        delete m_FZZOFDZoom;
        m_FZZOFDZoom = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDest::setType(DestType type)
{
    string value = "XYZ";

    switch (type) {
    case DestType::XYZ:
        value = "XYZ";
        break;
    case DestType::Fit:
        value = "Fit";
        break;
    case DestType::FitH:
        value = "FitH";
        break;
    case DestType::FitV:
        value = "FitV";
        break;
    case DestType::FitR:
        value = "FitR";
        break;
    default:
        value = "XYZ";
        break;
    }
    setAttribute_String("Type",value);
}
//-----------------------------------------------------------------------------------------------------------------
DestType FZZOFDDest::getType()
{
    string value = getAttribute_String("Type");
    DestType destType = DestType::XYZ;
    if ( value == "XYZ" ) {
        destType = DestType::XYZ;
    }
    else if ( value == "Fit" ) {
        destType = DestType::Fit;
    }
    else if ( value == "FitH" ) {
        destType = DestType::FitH;
    }
    else if ( value == "FitV" ) {
        destType = DestType::FitV;
    }
    else if ( value == "FitR" ) {
        destType = DestType::FitR;
    }
    else {
        destType = DestType::XYZ;
    }
    return destType;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDest::setPageID(string value)
{
    setAttribute_String("PageID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDest::getPageID()
{
    return getAttribute_String("PageID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDest::setPageID(long value)
{
 
    setAttribute_long("PageID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDDest::getPageID_long()
{
    return getAttribute_long("PageID");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft * FZZOFDDest::setLeft()
{
    return m_FZZOFDLeft = setElementObject(m_FZZOFDLeft,FZZOFDLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft * FZZOFDDest::getLeft()
{
    return m_FZZOFDLeft = getElementObject(m_FZZOFDLeft,FZZOFDLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight * FZZOFDDest::setRight()
{
    return m_FZZOFDRight = setElementObject(m_FZZOFDRight,FZZOFDRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight * FZZOFDDest::getRight()
{
    return m_FZZOFDRight = getElementObject(m_FZZOFDRight,FZZOFDRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop * FZZOFDDest::setTop()
{
    return m_FZZOFDTop = setElementObject(m_FZZOFDTop,FZZOFDTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop * FZZOFDDest::getTop()
{
    return m_FZZOFDTop = getElementObject(m_FZZOFDTop,FZZOFDTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom * FZZOFDDest::setBottom()
{
    return m_FZZOFDBottom = setElementObject(m_FZZOFDBottom,FZZOFDBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom * FZZOFDDest::getBottom()
{
    return m_FZZOFDBottom = getElementObject(m_FZZOFDBottom,FZZOFDBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom * FZZOFDDest::setZoom()
{
    return m_FZZOFDZoom = setElementObject(m_FZZOFDZoom,FZZOFDZOOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom * FZZOFDDest::getZoom()
{
    return m_FZZOFDZoom = getElementObject(m_FZZOFDZoom,FZZOFDZOOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
