//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDMove.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDMove**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMove::FZZOFDMove() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDMove()");
    FZZConst::addClassCount("FZZOFDMove");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMove::FZZOFDMove(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDMove");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMove::FZZOFDMove(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDMove");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMove::FZZOFDMove(const FZZOFDMove& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDMove");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMove::~FZZOFDMove()
{
    //DLOG("~FZZOFDMove()");
    FZZConst::delClassCount("FZZOFDMove");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMove::setPoint1(string value)
{
    setAttribute_String("Point1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDMove::getPoint1()
{
    return getAttribute_String("Point1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMove::setPoint1(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Point1",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMove::getPoint1(/*out*/double & x, /*out*/double & y)
{
    
    string strid = getAttribute_String("Point1");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
