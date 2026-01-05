//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDCropBox.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCropBox**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox::FZZOFDCropBox() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCropBox()");
    FZZConst::addClassCount("FZZOFDCropBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox::FZZOFDCropBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDCropBox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox::FZZOFDCropBox(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCropBox");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox::FZZOFDCropBox(const FZZOFDCropBox& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCropBox");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox::~FZZOFDCropBox()
{
    //DLOG("~FZZOFDCropBox()");
    FZZConst::delClassCount("FZZOFDCropBox");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCropBox::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCropBox::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCropBox::setValue(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCropBox::getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getValue_String();
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
