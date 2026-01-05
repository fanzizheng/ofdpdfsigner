//
//  Created by zizheng fan on 2023/09/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDisplayVerticalDrawingGridEvery.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDisplayVerticalDrawingGridEvery**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery::FZZWDisplayVerticalDrawingGridEvery() : FZZXMLElementObject()
{
    //DLOG("FZZWDisplayVerticalDrawingGridEvery()");
    FZZConst::addClassCount("FZZWDisplayVerticalDrawingGridEvery");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery::FZZWDisplayVerticalDrawingGridEvery(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDisplayVerticalDrawingGridEvery");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery::FZZWDisplayVerticalDrawingGridEvery(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDisplayVerticalDrawingGridEvery");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery::FZZWDisplayVerticalDrawingGridEvery(const FZZWDisplayVerticalDrawingGridEvery& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDisplayVerticalDrawingGridEvery");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery::~FZZWDisplayVerticalDrawingGridEvery()
{
    //DLOG("~FZZWDisplayVerticalDrawingGridEvery()");
    FZZConst::delClassCount("FZZWDisplayVerticalDrawingGridEvery");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDisplayVerticalDrawingGridEvery::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDisplayVerticalDrawingGridEvery::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
