//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCubicBezier.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCubicBezier**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCubicBezier::FZZOFDCubicBezier() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCubicBezier()");
    FZZConst::addClassCount("FZZOFDCubicBezier");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCubicBezier::FZZOFDCubicBezier(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDCubicBezier");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCubicBezier::FZZOFDCubicBezier(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCubicBezier");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCubicBezier::FZZOFDCubicBezier(const FZZOFDCubicBezier& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCubicBezier");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCubicBezier::~FZZOFDCubicBezier()
{
    //DLOG("~FZZOFDCubicBezier()");
    FZZConst::delClassCount("FZZOFDCubicBezier");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::setPoint3(string value)
{
    setAttribute_String("Point3",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCubicBezier::getPoint3()
{
    return getAttribute_String("Point3");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::setPoint1(string value)
{
    setAttribute_String("Point1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCubicBezier::getPoint1()
{
    return getAttribute_String("Point1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::setPoint2(string value)
{
    setAttribute_String("Point2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCubicBezier::getPoint2()
{
    return getAttribute_String("Point2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::setPoint3(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point3",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::getPoint3(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Point3");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::setPoint1(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point1",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::getPoint1(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Point1");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::setPoint2(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point2",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCubicBezier::getPoint2(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Point2");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
