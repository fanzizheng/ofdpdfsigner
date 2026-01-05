//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDQuadraticBezier.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDQuadraticBezier**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDQuadraticBezier::FZZOFDQuadraticBezier() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDQuadraticBezier()");
    FZZConst::addClassCount("FZZOFDQuadraticBezier");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDQuadraticBezier::FZZOFDQuadraticBezier(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDQuadraticBezier");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDQuadraticBezier::FZZOFDQuadraticBezier(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDQuadraticBezier");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDQuadraticBezier::FZZOFDQuadraticBezier(const FZZOFDQuadraticBezier& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDQuadraticBezier");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDQuadraticBezier::~FZZOFDQuadraticBezier()
{
    //DLOG("~FZZOFDQuadraticBezier()");
    FZZConst::delClassCount("FZZOFDQuadraticBezier");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDQuadraticBezier::setPoint1(string value)
{
    setAttribute_String("Point1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDQuadraticBezier::getPoint1()
{
    return getAttribute_String("Point1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDQuadraticBezier::setPoint2(string value)
{
    setAttribute_String("Point2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDQuadraticBezier::getPoint2()
{
    return getAttribute_String("Point2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDQuadraticBezier::setPoint1(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point1",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDQuadraticBezier::getPoint1(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Point1");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDQuadraticBezier::setPoint2(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point2",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDQuadraticBezier::getPoint2(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Point2");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
