//
//  Created by zizheng fan on 2023/07/31
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAprstDash.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAprstDash**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash::FZZAprstDash() : FZZXMLElementObject()
{
    //DLOG("FZZAprstDash()");
    FZZConst::addClassCount("FZZAprstDash");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash::FZZAprstDash(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAprstDash");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash::FZZAprstDash(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAprstDash");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash::FZZAprstDash(const FZZAprstDash& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAprstDash");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAprstDash::~FZZAprstDash()
{
    //DLOG("~FZZAprstDash()");
    FZZConst::delClassCount("FZZAprstDash");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAprstDash::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAprstDash::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
