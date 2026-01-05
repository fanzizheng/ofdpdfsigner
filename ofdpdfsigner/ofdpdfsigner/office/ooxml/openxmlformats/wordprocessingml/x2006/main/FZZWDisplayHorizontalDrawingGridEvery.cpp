//
//  Created by zizheng fan on 2023/09/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDisplayHorizontalDrawingGridEvery.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDisplayHorizontalDrawingGridEvery**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery::FZZWDisplayHorizontalDrawingGridEvery() : FZZXMLElementObject()
{
    //DLOG("FZZWDisplayHorizontalDrawingGridEvery()");
    FZZConst::addClassCount("FZZWDisplayHorizontalDrawingGridEvery");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery::FZZWDisplayHorizontalDrawingGridEvery(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDisplayHorizontalDrawingGridEvery");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery::FZZWDisplayHorizontalDrawingGridEvery(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDisplayHorizontalDrawingGridEvery");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery::FZZWDisplayHorizontalDrawingGridEvery(const FZZWDisplayHorizontalDrawingGridEvery& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDisplayHorizontalDrawingGridEvery");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery::~FZZWDisplayHorizontalDrawingGridEvery()
{
    //DLOG("~FZZWDisplayHorizontalDrawingGridEvery()");
    FZZConst::delClassCount("FZZWDisplayHorizontalDrawingGridEvery");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDisplayHorizontalDrawingGridEvery::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDisplayHorizontalDrawingGridEvery::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
