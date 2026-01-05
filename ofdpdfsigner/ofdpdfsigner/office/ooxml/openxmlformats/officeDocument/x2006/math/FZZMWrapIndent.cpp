//
//  Created by zizheng fan on 2023/05/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMWrapIndent.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMWrapIndent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent::FZZMWrapIndent() : FZZXMLElementObject()
{
    //DLOG("FZZMWrapIndent()");
    FZZConst::addClassCount("FZZMWrapIndent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent::FZZMWrapIndent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMWrapIndent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent::FZZMWrapIndent(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMWrapIndent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent::FZZMWrapIndent(const FZZMWrapIndent& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMWrapIndent");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent::~FZZMWrapIndent()
{
    //DLOG("~FZZMWrapIndent()");
    FZZConst::delClassCount("FZZMWrapIndent");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMWrapIndent::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMWrapIndent::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
