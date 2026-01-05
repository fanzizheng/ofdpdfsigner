//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDRadialShd.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDRadialShd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd::FZZOFDRadialShd() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDRadialShd()");
    FZZConst::addClassCount("FZZOFDRadialShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd::FZZOFDRadialShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDRadialShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd::FZZOFDRadialShd(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDRadialShd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd::FZZOFDRadialShd(const FZZOFDRadialShd& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDRadialShd");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDSegment*>::const_iterator itr;
    for( itr = obj.m_FZZOFDSegments.begin(); itr != obj.m_FZZOFDSegments.end(); itr++ ) {
        FZZOFDSegment * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDSegments.push_back(new FZZOFDSegment(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRadialShd::~FZZOFDRadialShd()
{
    //DLOG("~FZZOFDRadialShd()");
    FZZConst::delClassCount("FZZOFDRadialShd");
    vector<FZZOFDSegment*>::const_iterator itr;
    for( itr = m_FZZOFDSegments.begin(); itr != m_FZZOFDSegments.end(); itr++ ) {
        FZZOFDSegment * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDSegments.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setMapType(FZZOFDMapType::TYPE type)
{
    setAttribute_String("MapType",FZZOFDMapType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMapType::TYPE FZZOFDRadialShd::getMapType()
{
    return FZZOFDMapType::toType(getAttribute_String("MapType").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setMapUnit(double value)
{
    setAttribute_double("MapUnit",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDRadialShd::getMapUnit()
{
    return getAttribute_double("MapUnit");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setEccentricity(double value)
{
    setAttribute_double("Eccentricity",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDRadialShd::getEccentricity()
{
    return getAttribute_double("Eccentricity");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setAngle(double value)
{
    setAttribute_double("Angle",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDRadialShd::getAngle()
{
    return getAttribute_double("Angle");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setStartPoint(string value)
{
    setAttribute_String("StartPoint",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDRadialShd::getStartPoint()
{
    return getAttribute_String("StartPoint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setEndPoint(string value)
{
    setAttribute_String("EndPoint",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDRadialShd::getEndPoint()
{
    return getAttribute_String("EndPoint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setStartRadius(double value)
{
    setAttribute_double("StartRadius",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDRadialShd::getStartRadius()
{
    return getAttribute_double("StartRadius");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setEndRadius(double value)
{
    setAttribute_double("EndRadius",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDRadialShd::getEndRadius()
{
    return getAttribute_double("EndRadius");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setExtend(FZZOFDExtend::TYPE type)
{
    setAttribute_String("Extend",FZZOFDExtend::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtend::TYPE FZZOFDRadialShd::getExtend()
{
    return FZZOFDExtend::toType(getAttribute_String("Extend").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment * FZZOFDRadialShd::addSegment()
{
    return addElementObject(&m_FZZOFDSegments,FZZOFDSEGMENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDSegment*> * FZZOFDRadialShd::getSegmentList()
{
    getElementObjectList(&m_FZZOFDSegments,FZZOFDSEGMENT_Name);
    return &m_FZZOFDSegments;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setStartPoint(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("StartPoint",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::getStartPoint(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("StartPoint");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::setEndPoint(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("EndPoint",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRadialShd::getEndPoint(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("EndPoint");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
