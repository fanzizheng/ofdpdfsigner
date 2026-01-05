//
//  Created by zizheng fan on 2023/11/29
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPosition.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPosition**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition::FZZWPosition() : FZZXMLElementObject()
{
    //DLOG("FZZWPosition()");
    FZZConst::addClassCount("FZZWPosition");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition::FZZWPosition(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPosition");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition::FZZWPosition(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPosition");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition::FZZWPosition(const FZZWPosition& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPosition");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition::~FZZWPosition()
{
    //DLOG("~FZZWPosition()");
    FZZConst::delClassCount("FZZWPosition");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPosition::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPosition::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
