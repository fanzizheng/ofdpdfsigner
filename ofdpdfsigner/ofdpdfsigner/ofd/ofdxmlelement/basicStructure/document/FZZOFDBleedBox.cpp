//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBleedBox.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBleedBox**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox::FZZOFDBleedBox() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDBleedBox()");
    FZZConst::addClassCount("FZZOFDBleedBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox::FZZOFDBleedBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDBleedBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox::FZZOFDBleedBox(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDBleedBox");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox::FZZOFDBleedBox(const FZZOFDBleedBox& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDBleedBox");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox::~FZZOFDBleedBox()
{
    //DLOG("~FZZOFDBleedBox()");
    FZZConst::delClassCount("FZZOFDBleedBox");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBleedBox::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBleedBox::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBleedBox::setValue(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBleedBox::getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getValue_String();
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
