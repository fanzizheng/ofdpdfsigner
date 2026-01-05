//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBorder.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBorder**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder::FZZOFDBorder() : FZZOFDXMLElementObject(),m_FZZOFDBorderColor(NULL),m_FZZOFDColor(NULL)
{
    //DLOG("FZZOFDBorder()");
    FZZConst::addClassCount("FZZOFDBorder");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder::FZZOFDBorder(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDBorderColor(NULL),m_FZZOFDColor(NULL)
{
    
    FZZConst::addClassCount("FZZOFDBorder");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder::FZZOFDBorder(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDBorderColor(NULL),m_FZZOFDColor(NULL)
{
    FZZConst::addClassCount("FZZOFDBorder");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder::FZZOFDBorder(const FZZOFDBorder& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDBorder");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDBorderColor = obj.m_FZZOFDBorderColor != NULL ? new FZZOFDBorderColor(*obj.m_FZZOFDBorderColor) : NULL;
    m_FZZOFDColor = obj.m_FZZOFDColor != NULL ? new FZZOFDColor(*obj.m_FZZOFDColor) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder::~FZZOFDBorder()
{
    //DLOG("~FZZOFDBorder()");
    FZZConst::delClassCount("FZZOFDBorder");
    if ( m_FZZOFDBorderColor != NULL ) {
        delete m_FZZOFDBorderColor;
        m_FZZOFDBorderColor = NULL;
    }
    if ( m_FZZOFDColor != NULL ) {
        delete m_FZZOFDColor;
        m_FZZOFDColor = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBorder::setLineWidth(double value)
{
    setAttribute_double("LineWidth",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBorder::getLineWidth()
{
    return getAttribute_double("LineWidth");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBorder::setDashPattern(string value)
{
    setAttribute_String("DashPattern",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBorder::getDashPattern()
{
    return getAttribute_String("DashPattern");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBorder::setDashPattern(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("DashPattern",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBorder::getDashPattern(/*out*/vector<string> & array)
{
    string strid = getAttribute_String("DashPattern");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBorder::setHorizonalCornerRadius(double value)
{
    setAttribute_double("HorizonalCornerRadius",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBorder::getHorizonalCornerRadius()
{
    return getAttribute_double("HorizonalCornerRadius");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBorder::setDashOffset(double value)
{
    setAttribute_double("DashOffset",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBorder::getDashOffset()
{
    return getAttribute_double("DashOffset");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorderColor * FZZOFDBorder::setBorderColor()
{
    return m_FZZOFDBorderColor = setElementObject(m_FZZOFDBorderColor,FZZOFDBORDERCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorderColor * FZZOFDBorder::getBorderColor()
{
    return m_FZZOFDBorderColor = getElementObject(m_FZZOFDBorderColor,FZZOFDBORDERCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor * FZZOFDBorder::setColor()
{
    return m_FZZOFDColor = setElementObject(m_FZZOFDColor,FZZOFDCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor * FZZOFDBorder::getColor()
{
    return m_FZZOFDColor = getElementObject(m_FZZOFDColor,FZZOFDCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
