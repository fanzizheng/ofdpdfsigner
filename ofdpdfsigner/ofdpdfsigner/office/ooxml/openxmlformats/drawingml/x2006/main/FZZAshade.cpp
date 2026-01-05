//
//  Created by zizheng fan on 2023/08/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAshade.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAshade**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAshade::FZZAshade() : FZZXMLElementObject()
{
    //DLOG("FZZAshade()");
    FZZConst::addClassCount("FZZAshade");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAshade::FZZAshade(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAshade");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAshade::FZZAshade(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAshade");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAshade::FZZAshade(const FZZAshade& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAshade");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAshade::~FZZAshade()
{
    //DLOG("~FZZAshade()");
    FZZConst::delClassCount("FZZAshade");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAshade::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAshade::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
