//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDGouraudShd.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDGouraudShd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd::FZZOFDGouraudShd() : FZZOFDXMLElementObject(),m_FZZOFDBackColor(NULL)
{
    //DLOG("FZZOFDGouraudShd()");
    FZZConst::addClassCount("FZZOFDGouraudShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd::FZZOFDGouraudShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDBackColor(NULL)
{
    
    FZZConst::addClassCount("FZZOFDGouraudShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd::FZZOFDGouraudShd(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDBackColor(NULL)
{
    FZZConst::addClassCount("FZZOFDGouraudShd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd::FZZOFDGouraudShd(const FZZOFDGouraudShd& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDGouraudShd");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDBackColor = obj.m_FZZOFDBackColor != NULL ? new FZZOFDBackColor(*obj.m_FZZOFDBackColor) : NULL;
    
    vector<FZZOFDPoint*>::const_iterator itr;
    for( itr = obj.m_FZZOFDPoints.begin(); itr != obj.m_FZZOFDPoints.end(); itr++ ) {
        FZZOFDPoint * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDPoints.push_back(new FZZOFDPoint(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd::~FZZOFDGouraudShd()
{
    //DLOG("~FZZOFDGouraudShd()");
    FZZConst::delClassCount("FZZOFDGouraudShd");
    
    if ( m_FZZOFDBackColor != NULL ) {
        delete m_FZZOFDBackColor;
        m_FZZOFDBackColor = NULL;
    }
    
    vector<FZZOFDPoint*>::const_iterator itr;
    for( itr = m_FZZOFDPoints.begin(); itr != m_FZZOFDPoints.end(); itr++ ) {
        FZZOFDPoint * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDPoints.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGouraudShd::setExtend(bool value)
{
    setAttribute_String("Extend",value ? "1" : "0");
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDGouraudShd::getExtend()
{
    return getAttribute_String("Extend") == "1" ? true : false;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBackColor * FZZOFDGouraudShd::setBackColor()
{
    return m_FZZOFDBackColor = setElementObject(m_FZZOFDBackColor,FZZOFDBACKCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBackColor * FZZOFDGouraudShd::getBackColor()
{
    return m_FZZOFDBackColor = getElementObject(m_FZZOFDBackColor,FZZOFDBACKCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint * FZZOFDGouraudShd::addPoint()
{
    return addElementObject(&m_FZZOFDPoints,FZZOFDPOINT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPoint*> * FZZOFDGouraudShd::getPointList()
{
    getElementObjectList(&m_FZZOFDPoints,FZZOFDPOINT_Name);
    return &m_FZZOFDPoints;
}
//-----------------------------------------------------------------------------------------------------------------
