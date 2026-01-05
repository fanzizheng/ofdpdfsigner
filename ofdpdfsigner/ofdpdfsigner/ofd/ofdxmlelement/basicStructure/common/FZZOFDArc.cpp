//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDArc.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDArc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArc::FZZOFDArc() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDArc()");
    FZZConst::addClassCount("FZZOFDArc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArc::FZZOFDArc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDArc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArc::FZZOFDArc(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDArc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArc::FZZOFDArc(const FZZOFDArc& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDArc");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArc::~FZZOFDArc()
{
    //DLOG("~FZZOFDArc()");
    FZZConst::delClassCount("FZZOFDArc");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setEllipseSize(string value)
{
    setAttribute_String("EllipseSize",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDArc::getEllipseSize()
{
    return getAttribute_String("EllipseSize");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setEllipseSize(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("EllipseSize",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::getEllipseSize(/*out*/vector<string> & array)
{
    string strid = getAttribute_String("EllipseSize");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setSweepDirection(bool value)
{
    setAttribute_Bool("SweepDirection",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDArc::getSweepDirection()
{
    return getAttribute_Bool("SweepDirection",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setLargeArc(bool value)
{
    setAttribute_Bool("LargeArc",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDArc::getLargeArc()
{
    return getAttribute_Bool("LargeArc",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setRotationAngle(double value)
{
    setAttribute_double("RotationAngle",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDArc::getRotationAngle()
{
    return getAttribute_double("RotationAngle");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setEndPoint(string value)
{
    setAttribute_String("EndPoint",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDArc::getEndPoint()
{
    return getAttribute_String("EndPoint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::setEndPoint(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("EndPoint",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArc::getEndPoint(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("EndPoint");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
