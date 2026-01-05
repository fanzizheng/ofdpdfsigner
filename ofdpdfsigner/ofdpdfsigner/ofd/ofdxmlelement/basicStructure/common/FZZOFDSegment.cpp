//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDSegment.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSegment**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment::FZZOFDSegment() : FZZOFDXMLElementObject(),m_FZZOFDColor(NULL)
{
    //DLOG("FZZOFDSegment()");
    FZZConst::addClassCount("FZZOFDSegment");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment::FZZOFDSegment(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDColor(NULL)
{
    
    FZZConst::addClassCount("FZZOFDSegment");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment::FZZOFDSegment(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDColor(NULL)
{
    FZZConst::addClassCount("FZZOFDSegment");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment::FZZOFDSegment(const FZZOFDSegment& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSegment");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDColor = obj.m_FZZOFDColor != NULL ? new FZZOFDColor(*obj.m_FZZOFDColor) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment::~FZZOFDSegment()
{
    //DLOG("~FZZOFDSegment()");
    FZZConst::delClassCount("FZZOFDSegment");
    if ( m_FZZOFDColor != NULL ) {
        delete m_FZZOFDColor;
        m_FZZOFDColor = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSegment::setPosition(double value)
{
    setAttribute_double("Position",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDSegment::getPosition()
{
    return getAttribute_double("Position");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor * FZZOFDSegment::setColor()
{
    return m_FZZOFDColor = setElementObject(m_FZZOFDColor,FZZOFDCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor * FZZOFDSegment::getColor()
{
    return m_FZZOFDColor = getElementObject(m_FZZOFDColor,FZZOFDCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
