//
//  Created by zizheng fan on 2023/06/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPEffectExtent.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPEffectExtent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent::FZZWPEffectExtent() : FZZXMLElementObject()
{
    //DLOG("FZZWPEffectExtent()");
    FZZConst::addClassCount("FZZWPEffectExtent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent::FZZWPEffectExtent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPEffectExtent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent::FZZWPEffectExtent(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPEffectExtent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent::FZZWPEffectExtent(const FZZWPEffectExtent& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPEffectExtent");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent::~FZZWPEffectExtent()
{
    //DLOG("~FZZWPEffectExtent()");
    FZZConst::delClassCount("FZZWPEffectExtent");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPEffectExtent::setL(string value)
{
    setAttribute_String("l",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPEffectExtent::getL()
{
    return getAttribute_String("l");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPEffectExtent::setT(string value)
{
    setAttribute_String("t",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPEffectExtent::getT()
{
    return getAttribute_String("t");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPEffectExtent::setR(string value)
{
    setAttribute_String("r",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPEffectExtent::getR()
{
    return getAttribute_String("r");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPEffectExtent::setB(string value)
{
    setAttribute_String("b",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPEffectExtent::getB()
{
    return getAttribute_String("b");
}
//-----------------------------------------------------------------------------------------------------------------
