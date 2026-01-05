//
//  Created by zizheng fan on 2023/05/18.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMDispDef.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMDispDef**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef::FZZMDispDef() : FZZXMLElementObject()
{
    //DLOG("FZZWRsidRoot()");
    FZZConst::addClassCount("FZZMDispDef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef::FZZMDispDef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMDispDef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef::FZZMDispDef(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMDispDef");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef::FZZMDispDef(const FZZMDispDef& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMDispDef");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef::~FZZMDispDef()
{
    //DLOG("~FZZMDispDef()");
    FZZConst::delClassCount("FZZMDispDef");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMDispDef::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMDispDef::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
