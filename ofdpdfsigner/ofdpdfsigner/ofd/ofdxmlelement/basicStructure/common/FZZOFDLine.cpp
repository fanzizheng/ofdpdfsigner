//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLine.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDLine**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLine::FZZOFDLine() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDLine()");
    FZZConst::addClassCount("FZZOFDLine");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLine::FZZOFDLine(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDLine");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLine::FZZOFDLine(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDLine");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLine::FZZOFDLine(const FZZOFDLine& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDLine");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLine::~FZZOFDLine()
{
    //DLOG("~FZZOFDLine()");
    FZZConst::delClassCount("FZZOFDLine");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLine::setPoint1(string value)
{
    setAttribute_String("Point1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDLine::getPoint1()
{
    return getAttribute_String("Point1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLine::setPoint1(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point1",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLine::getPoint1(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Point1");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
