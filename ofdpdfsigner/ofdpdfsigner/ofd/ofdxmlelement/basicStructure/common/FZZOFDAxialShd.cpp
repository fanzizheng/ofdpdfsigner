//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDAxialShd.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAxialShd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAxialShd::FZZOFDAxialShd() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDAxialShd()");
    FZZConst::addClassCount("FZZOFDAxialShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAxialShd::FZZOFDAxialShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDAxialShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAxialShd::FZZOFDAxialShd(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDAxialShd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAxialShd::FZZOFDAxialShd(const FZZOFDAxialShd& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAxialShd");
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
FZZOFDAxialShd::~FZZOFDAxialShd()
{
    //DLOG("~FZZOFDAxialShd()");
    FZZConst::delClassCount("FZZOFDAxialShd");
    
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
void FZZOFDAxialShd::setMapType(FZZOFDMapType::TYPE type)
{
    setAttribute_String("MapType",FZZOFDMapType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMapType::TYPE FZZOFDAxialShd::getMapType()
{
    return FZZOFDMapType::toType(getAttribute_String("MapType").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::setMapUnit(double value)
{
    setAttribute_double("MapUnit",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDAxialShd::getMapUnit()
{
    return getAttribute_double("MapUnit");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::setStartPoint(string value)
{
    setAttribute_String("StartPoint",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAxialShd::getStartPoint()
{
    return getAttribute_String("StartPoint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::setEndPoint(string value)
{
    setAttribute_String("EndPoint",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAxialShd::getEndPoint()
{
    return getAttribute_String("EndPoint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::setExtend(FZZOFDExtend::TYPE type)
{
    setAttribute_String("Extend",FZZOFDExtend::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtend::TYPE FZZOFDAxialShd::getExtend()
{
    return FZZOFDExtend::toType(getAttribute_String("Extend").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSegment * FZZOFDAxialShd::addSegment()
{
    return addElementObject(&m_FZZOFDSegments,FZZOFDSEGMENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDSegment*> * FZZOFDAxialShd::getSegmentList()
{
    getElementObjectList(&m_FZZOFDSegments,FZZOFDSEGMENT_Name);
    return &m_FZZOFDSegments;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::setStartPoint(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("StartPoint",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::getStartPoint(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("StartPoint");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::setEndPoint(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("EndPoint",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAxialShd::getEndPoint(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("EndPoint");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
