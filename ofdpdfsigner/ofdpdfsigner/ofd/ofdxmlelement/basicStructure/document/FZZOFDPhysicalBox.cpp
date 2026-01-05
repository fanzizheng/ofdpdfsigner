//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPhysicalBox.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPhysicalBox**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox::FZZOFDPhysicalBox() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPhysicalBox()");
    FZZConst::addClassCount("FZZOFDPhysicalBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox::FZZOFDPhysicalBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPhysicalBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox::FZZOFDPhysicalBox(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPhysicalBox");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox::FZZOFDPhysicalBox(const FZZOFDPhysicalBox& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPhysicalBox");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox::~FZZOFDPhysicalBox()
{
    //DLOG("~FZZOFDPhysicalBox()");
    FZZConst::delClassCount("FZZOFDPhysicalBox");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPhysicalBox::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPhysicalBox::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPhysicalBox::setValue(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPhysicalBox::getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getValue_String();
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
