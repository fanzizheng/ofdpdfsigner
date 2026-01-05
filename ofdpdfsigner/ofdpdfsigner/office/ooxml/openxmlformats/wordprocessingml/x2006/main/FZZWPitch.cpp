//
//  Created by zizheng fan on 2023/09/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPitch.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPitch**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch::FZZWPitch() : FZZXMLElementObject()
{
    //DLOG("FZZWPitch()");
    FZZConst::addClassCount("FZZWPitch");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch::FZZWPitch(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPitch");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch::FZZWPitch(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPitch");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch::FZZWPitch(const FZZWPitch& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPitch");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch::~FZZWPitch()
{
    //DLOG("~FZZWPitch()");
    FZZConst::delClassCount("FZZWPitch");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPitch::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPitch::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
