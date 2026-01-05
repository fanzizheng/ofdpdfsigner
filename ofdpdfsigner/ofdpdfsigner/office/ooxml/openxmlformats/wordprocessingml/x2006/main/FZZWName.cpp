//
//  Created by zizheng fan on 2023/10/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWName.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWName**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWName::FZZWName() : FZZXMLElementObject()
{
    //DLOG("FZZWName()");
    FZZConst::addClassCount("FZZWName");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWName::FZZWName(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWName");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWName::FZZWName(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWName");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWName::FZZWName(const FZZWName& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWName");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWName::~FZZWName()
{
    //DLOG("~FZZWName()");
    FZZConst::delClassCount("FZZWName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWName::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWName::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
