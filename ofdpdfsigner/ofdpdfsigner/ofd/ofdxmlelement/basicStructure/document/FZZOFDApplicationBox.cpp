//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDApplicationBox.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDApplicationBox**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox::FZZOFDApplicationBox() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDApplicationBox()");
    FZZConst::addClassCount("FZZOFDApplicationBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox::FZZOFDApplicationBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDApplicationBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox::FZZOFDApplicationBox(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDApplicationBox");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox::FZZOFDApplicationBox(const FZZOFDApplicationBox& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDApplicationBox");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox::~FZZOFDApplicationBox()
{
    //DLOG("~FZZOFDApplicationBox()");
    FZZConst::delClassCount("FZZOFDApplicationBox");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDApplicationBox::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDApplicationBox::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDApplicationBox::setValue(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDApplicationBox::getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getValue_String();
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
