//
//  Created by zizheng fan on 2023/11/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWId.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWId**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWId::FZZWId() : FZZXMLElementObject()
{
    //DLOG("FZZWId()");
    FZZConst::addClassCount("FZZWId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWId::FZZWId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWId::FZZWId(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWId::FZZWId(const FZZWId& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWId");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWId::~FZZWId()
{
    //DLOG("~FZZWId()");
    FZZConst::delClassCount("FZZWId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWId::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWId::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
