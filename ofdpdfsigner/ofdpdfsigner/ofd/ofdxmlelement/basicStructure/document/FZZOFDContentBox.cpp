//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDContentBox.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDContentBox**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox::FZZOFDContentBox() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDContentBox()");
    FZZConst::addClassCount("FZZOFDContentBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox::FZZOFDContentBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDContentBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox::FZZOFDContentBox(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDContentBox");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox::FZZOFDContentBox(const FZZOFDContentBox& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDContentBox");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox::~FZZOFDContentBox()
{
    //DLOG("~FZZOFDContentBox()");
    FZZConst::delClassCount("FZZOFDContentBox");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDContentBox::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDContentBox::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDContentBox::setValue(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDContentBox::getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getValue_String();
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
