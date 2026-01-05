//
//  Created by zizheng fan on 2023/08/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsatMod.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAsatMod**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod::FZZAsatMod() : FZZXMLElementObject()
{
    //DLOG("FZZAsatMod()");
    FZZConst::addClassCount("FZZAsatMod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod::FZZAsatMod(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAsatMod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod::FZZAsatMod(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAsatMod");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod::FZZAsatMod(const FZZAsatMod& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAsatMod");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod::~FZZAsatMod()
{
    //DLOG("~FZZAsatMod()");
    FZZConst::delClassCount("FZZAsatMod");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAsatMod::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAsatMod::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
