//
//  Created by zizheng fan on 2023/06/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPExtent.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPExtent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent::FZZWPExtent() : FZZXMLElementObject()
{
    //DLOG("FZZWPExtent()");
    FZZConst::addClassCount("FZZWPExtent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent::FZZWPExtent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPExtent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent::FZZWPExtent(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPExtent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent::FZZWPExtent(const FZZWPExtent& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPExtent");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent::~FZZWPExtent()
{
    //DLOG("~FZZWPExtent()");
    FZZConst::delClassCount("FZZWPExtent");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPExtent::setCx(string value)
{
    setAttribute_String("cx",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPExtent::getCx()
{
    return getAttribute_String("cx");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPExtent::setCy(string value)
{
    setAttribute_String("cy",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPExtent::getCy()
{
    return getAttribute_String("cy");
}
//-----------------------------------------------------------------------------------------------------------------

