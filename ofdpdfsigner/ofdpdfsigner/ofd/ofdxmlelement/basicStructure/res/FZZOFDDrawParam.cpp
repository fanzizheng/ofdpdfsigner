//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDDrawParam.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDrawParam**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam::FZZOFDDrawParam() : FZZOFDXMLElementObject(),m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL)
{
    //DLOG("FZZOFDDrawParam()");
    FZZConst::addClassCount("FZZOFDDrawParam");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam::FZZOFDDrawParam(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL)
{
    FZZConst::addClassCount("FZZOFDDrawParam");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam::FZZOFDDrawParam(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL)
{
    FZZConst::addClassCount("FZZOFDDrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam::FZZOFDDrawParam(const FZZOFDDrawParam& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDrawParam");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDFillColor = obj.m_FZZOFDFillColor != NULL ? new FZZOFDFillColor(*obj.m_FZZOFDFillColor) : NULL;
    m_FZZOFDStrokeColor = obj.m_FZZOFDStrokeColor != NULL ? new FZZOFDStrokeColor(*obj.m_FZZOFDStrokeColor) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam::~FZZOFDDrawParam()
{
    //DLOG("~FZZOFDDrawParam()");
    FZZConst::delClassCount("FZZOFDDrawParam");
        
    if ( m_FZZOFDFillColor != NULL ) {
        delete m_FZZOFDFillColor;
        m_FZZOFDFillColor = NULL;
    }
    if ( m_FZZOFDStrokeColor != NULL ) {
        delete m_FZZOFDStrokeColor;
        m_FZZOFDStrokeColor = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDrawParam::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setRelative(string value)
{
    setAttribute_String("Relative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDrawParam::getRelative()
{
    return getAttribute_String("Relative");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDDrawParam::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setRelative(long value)
{
    setAttribute_long("Relative",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDDrawParam::getRelative_long()
{
    return getAttribute_long("Relative");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setLineWidth(double value)
{
    setAttribute_double("LineWidth",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDDrawParam::getLineWidth()
{
    return getAttribute_double("LineWidth");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setJoin(FZZOFDLineJoinType::TYPE type)
{
    setAttribute_String("Join",FZZOFDLineJoinType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLineJoinType::TYPE FZZOFDDrawParam::getJoin()
{
    return FZZOFDLineJoinType::toType(getAttribute_String("Join").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setCap(FZZOFDLineCapType::TYPE type)
{
    setAttribute_String("Cap",FZZOFDLineCapType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLineCapType::TYPE FZZOFDDrawParam::getCap()
{
    return FZZOFDLineCapType::toType(getAttribute_String("Cap").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setDashOffset(double value)
{
    setAttribute_double("DashOffset",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDDrawParam::getDashOffset()
{
    return getAttribute_double("DashOffset");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setDashPattern(string value)
{
    setAttribute_String("DashPattern",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDrawParam::getDashPattern()
{
    return getAttribute_String("DashPattern");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setDashPattern(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("DashPattern",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::getDashPattern(/*out*/vector<string> & array)
{
    string strid = getAttribute_String("DashPattern");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawParam::setMiterLimit(double value)
{
    setAttribute_double("MiterLimit",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDDrawParam::getMiterLimit()
{
    return getAttribute_double("MiterLimit");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFillColor * FZZOFDDrawParam::setFillColor()
{
    return m_FZZOFDFillColor = setElementObject(m_FZZOFDFillColor,FZZOFDFILLCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFillColor * FZZOFDDrawParam::getFillColor()
{
    return m_FZZOFDFillColor = getElementObject(m_FZZOFDFillColor,FZZOFDFILLCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStrokeColor * FZZOFDDrawParam::setStrokeColor()
{
    return m_FZZOFDStrokeColor = setElementObject(m_FZZOFDStrokeColor,FZZOFDSTROKECOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStrokeColor * FZZOFDDrawParam::getStrokeColor()
{
    return m_FZZOFDStrokeColor = getElementObject(m_FZZOFDStrokeColor,FZZOFDSTROKECOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
