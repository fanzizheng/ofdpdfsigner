//
//  Created by zizheng fan on 2023/09/04
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAltName.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWAltName**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName::FZZWAltName() : FZZXMLElementObject()
{
    //DLOG("FZZWAltName()");
    FZZConst::addClassCount("FZZWAltName");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName::FZZWAltName(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWAltName");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName::FZZWAltName(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWAltName");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName::FZZWAltName(const FZZWAltName& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWAltName");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName::~FZZWAltName()
{
    //DLOG("~FZZWAltName()");
    FZZConst::delClassCount("FZZWAltName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWAltName::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWAltName::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
