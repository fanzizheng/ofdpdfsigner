//
//  Created by zizheng fan on 2023/08/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASysClr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZASysClr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr::FZZASysClr() : FZZXMLElementObject()
{
    //DLOG("FZZASysClr()");
    FZZConst::addClassCount("FZZASysClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr::FZZASysClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZASysClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr::FZZASysClr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZASysClr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr::FZZASysClr(const FZZASysClr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZASysClr");
    if ( this == &obj ) {
        return;
    }

    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr::~FZZASysClr()
{
    //DLOG("~FZZASysClr()");
    FZZConst::delClassCount("FZZASysClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZASysClr::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZASysClr::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZASysClr::setLastClr(string value)
{
    setAttribute_String("lastClr",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZASysClr::getLastClr()
{
    return getAttribute_String("lastClr");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
