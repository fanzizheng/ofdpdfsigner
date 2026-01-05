//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDColor**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor::FZZOFDColor() : FZZOFDXMLElementObject(),m_FZZOFDPattern(NULL),m_FZZOFDRadialShd(NULL),m_FZZOFDLaGouraudShd(NULL)
,m_FZZOFDGouraudShd(NULL),m_FZZOFDAxialShd(NULL)
{
    //DLOG("FZZOFDColor()");
    FZZConst::addClassCount("FZZOFDColor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor::FZZOFDColor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDPattern(NULL),m_FZZOFDRadialShd(NULL),m_FZZOFDLaGouraudShd(NULL),m_FZZOFDGouraudShd(NULL),m_FZZOFDAxialShd(NULL)
{
    
    FZZConst::addClassCount("FZZOFDColor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor::FZZOFDColor(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDPattern(NULL),m_FZZOFDRadialShd(NULL)
,m_FZZOFDLaGouraudShd(NULL),m_FZZOFDGouraudShd(NULL),m_FZZOFDAxialShd(NULL)
{
    FZZConst::addClassCount("FZZOFDColor");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor::FZZOFDColor(const FZZOFDColor& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDColor");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDPattern = obj.m_FZZOFDPattern != NULL ? new FZZOFDPattern(*obj.m_FZZOFDPattern) : NULL;
    m_FZZOFDRadialShd = obj.m_FZZOFDRadialShd != NULL ? new FZZOFDRadialShd(*obj.m_FZZOFDRadialShd) : NULL;
    m_FZZOFDLaGouraudShd = obj.m_FZZOFDLaGouraudShd != NULL ? new FZZOFDLaGouraudShd(*obj.m_FZZOFDLaGouraudShd) : NULL;
    m_FZZOFDGouraudShd = obj.m_FZZOFDGouraudShd != NULL ? new FZZOFDGouraudShd(*obj.m_FZZOFDGouraudShd) : NULL;
    m_FZZOFDAxialShd = obj.m_FZZOFDAxialShd != NULL ? new FZZOFDAxialShd(*obj.m_FZZOFDAxialShd) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor::~FZZOFDColor()
{
    //DLOG("~FZZOFDColor()");
    FZZConst::delClassCount("FZZOFDColor");
    if ( m_FZZOFDPattern != NULL ) {
        delete m_FZZOFDPattern;
        m_FZZOFDPattern = NULL;
    }
    if ( m_FZZOFDRadialShd != NULL ) {
        delete m_FZZOFDRadialShd;
        m_FZZOFDRadialShd = NULL;
    }
    if ( m_FZZOFDLaGouraudShd != NULL ) {
        delete m_FZZOFDLaGouraudShd;
        m_FZZOFDLaGouraudShd = NULL;
    }
    if ( m_FZZOFDGouraudShd != NULL ) {
        delete m_FZZOFDGouraudShd;
        m_FZZOFDGouraudShd = NULL;
    }
    if ( m_FZZOFDAxialShd != NULL ) {
        delete m_FZZOFDAxialShd;
        m_FZZOFDAxialShd = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::setValue(string value)
{
    setAttribute_String("Value",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDColor::getValue()
{
    return getAttribute_String("Value");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::setValue(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("Value",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::getValue(/*out*/vector<string> & array)
{
    string strid = getAttribute_String("Value");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::setIndex(string value)
{
    setAttribute_String("Index",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDColor::getIndex()
{
    return getAttribute_String("Index");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::setColorSpace(string value)
{
    setAttribute_String("ColorSpace",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDColor::getColorSpace()
{
    return getAttribute_String("ColorSpace");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::setColorSpace(long value)
{
    setAttribute_long("ColorSpace",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDColor::getColorSpace_long()
{
    return getAttribute_long("ColorSpace");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::setAlpha(int value)
{
    setAttribute_Int("Alpha",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDColor::getAlpha()
{
    //return getAttribute_Int("Alpha");
    string strAlpha = getAttribute_String("Alpha");
    if ( strAlpha.empty() ) {
        return 255;
    } else {
        return (int)strtol(strAlpha.c_str(),NULL,10);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColor::deleteObject()
{
    if ( m_FZZOFDPattern != NULL ) {
        delete m_FZZOFDPattern;
        m_FZZOFDPattern = NULL;
    }
    deleteElement(FZZOFDPATTERN_Name);
    if ( m_FZZOFDRadialShd != NULL ) {
        delete m_FZZOFDRadialShd;
        m_FZZOFDRadialShd = NULL;
    }
    deleteElement(FZZOFDRADIALSHD_Name);
    if ( m_FZZOFDLaGouraudShd != NULL ) {
        delete m_FZZOFDLaGouraudShd;
        m_FZZOFDLaGouraudShd = NULL;
    }
    deleteElement(FZZOFDLAGOURAUDSHD_Name);
    if ( m_FZZOFDGouraudShd != NULL ) {
        delete m_FZZOFDGouraudShd;
        m_FZZOFDGouraudShd = NULL;
    }
    deleteElement(FZZOFDGOURAUDSHD_Name);
    if ( m_FZZOFDAxialShd != NULL ) {
        delete m_FZZOFDAxialShd;
        m_FZZOFDAxialShd = NULL;
    }
    deleteElement(FZZOFDAXIALSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern * FZZOFDColor::setPattern()
{
    deleteObject();
    return m_FZZOFDPattern = setElementObject(m_FZZOFDPattern,FZZOFDPATTERN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern * FZZOFDColor::getPattern()
{
    return m_FZZOFDPattern = getElementObject(m_FZZOFDPattern,FZZOFDPATTERN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd * FZZOFDColor::setRadialShd()
{
    deleteObject();
    return m_FZZOFDRadialShd = setElementObject(m_FZZOFDRadialShd,FZZOFDRADIALSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd * FZZOFDColor::getRadialShd()
{
    return m_FZZOFDRadialShd = getElementObject(m_FZZOFDRadialShd,FZZOFDRADIALSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd * FZZOFDColor::setLaGouraudShd()
{
    deleteObject();
    return m_FZZOFDLaGouraudShd = setElementObject(m_FZZOFDLaGouraudShd,FZZOFDLAGOURAUDSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd * FZZOFDColor::getLaGouraudShd()
{
    return m_FZZOFDLaGouraudShd = getElementObject(m_FZZOFDLaGouraudShd,FZZOFDLAGOURAUDSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd * FZZOFDColor::setGouraudShd()
{
    deleteObject();
    return m_FZZOFDGouraudShd = setElementObject(m_FZZOFDGouraudShd,FZZOFDGOURAUDSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGouraudShd * FZZOFDColor::getGouraudShd()
{
    return m_FZZOFDGouraudShd = getElementObject(m_FZZOFDGouraudShd,FZZOFDGOURAUDSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAxialShd * FZZOFDColor::setAxialShd()
{
    deleteObject();
    return m_FZZOFDAxialShd = setElementObject(m_FZZOFDAxialShd,FZZOFDAXIALSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAxialShd * FZZOFDColor::getAxialShd()
{
    return m_FZZOFDAxialShd = getElementObject(m_FZZOFDAxialShd,FZZOFDAXIALSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
