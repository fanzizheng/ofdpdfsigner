//
//  Created by zizheng fan on 2023/09/05
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSig.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSig**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSig::FZZWSig() : FZZXMLElementObject()
{
    //DLOG("FZZWSig()");
    FZZConst::addClassCount("FZZWSig");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSig::FZZWSig(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSig");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSig::FZZWSig(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSig");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSig::FZZWSig(const FZZWSig& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSig");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSig::~FZZWSig()
{
    //DLOG("~FZZWSig()");
    FZZConst::delClassCount("FZZWSig");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSig::setUsb0(string value)
{
    setAttribute_String("w:usb0",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSig::getUsb0()
{
    return getAttribute_String("w:usb0");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSig::setUsb1(string value)
{
    setAttribute_String("w:usb1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSig::getUsb1()
{
    return getAttribute_String("w:usb1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSig::setUsb2(string value)
{
    setAttribute_String("w:usb2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSig::getUsb2()
{
    return getAttribute_String("w:usb2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSig::setUsb3(string value)
{
    setAttribute_String("w:usb3",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSig::getUsb3()
{
    return getAttribute_String("w:usb3");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSig::setCsb0(string value)
{
    setAttribute_String("w:csb0",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSig::getCsb0()
{
    return getAttribute_String("w:csb0");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSig::setCsb1(string value)
{
    setAttribute_String("w:csb1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSig::getCsb1()
{
    return getAttribute_String("w:csb1");
}
//-----------------------------------------------------------------------------------------------------------------
