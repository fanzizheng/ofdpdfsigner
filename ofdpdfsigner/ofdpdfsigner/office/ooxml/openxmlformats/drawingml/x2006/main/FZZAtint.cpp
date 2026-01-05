//
//  Created by zizheng fan on 2023/08/04
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAtint.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAtint**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAtint::FZZAtint() : FZZXMLElementObject()
{
    //DLOG("FZZAtint()");
    FZZConst::addClassCount("FZZAtint");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAtint::FZZAtint(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAtint");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAtint::FZZAtint(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAtint");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAtint::FZZAtint(const FZZAtint& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAtint");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAtint::~FZZAtint()
{
    //DLOG("~FZZAtint()");
    FZZConst::delClassCount("FZZAtint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAtint::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAtint::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
