//
//  Created by zizheng fan on 2023/08/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAlumMod.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAlumMod**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod::FZZAlumMod() : FZZXMLElementObject()
{
    //DLOG("FZZAlumMod()");
    FZZConst::addClassCount("FZZAlumMod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod::FZZAlumMod(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAlumMod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod::FZZAlumMod(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAlumMod");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod::FZZAlumMod(const FZZAlumMod& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAlumMod");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod::~FZZAlumMod()
{
    //DLOG("~FZZAlumMod()");
    FZZConst::delClassCount("FZZAlumMod");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAlumMod::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAlumMod::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
