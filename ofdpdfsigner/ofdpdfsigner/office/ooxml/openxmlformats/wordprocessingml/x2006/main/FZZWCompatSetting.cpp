//
//  Created by zizheng fan on 2023/09/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCompatSetting.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWCompatSetting**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWCompatSetting::FZZWCompatSetting() : FZZXMLElementObject()
{
    //DLOG("FZZWCompatSetting()");
    FZZConst::addClassCount("FZZWCompatSetting");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompatSetting::FZZWCompatSetting(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWCompatSetting");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompatSetting::FZZWCompatSetting(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWCompatSetting");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompatSetting::FZZWCompatSetting(const FZZWCompatSetting& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWCompatSetting");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompatSetting::~FZZWCompatSetting()
{
    //DLOG("~FZZWCompatSetting()");
    FZZConst::delClassCount("FZZWCompatSetting");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCompatSetting::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCompatSetting::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCompatSetting::setName(string value)
{
    setAttribute_String("w:name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCompatSetting::getName()
{
    return getAttribute_String("w:name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCompatSetting::setUri(string value)
{
    setAttribute_String("w:uri",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCompatSetting::getUri()
{
    return getAttribute_String("w:uri");
}
//-----------------------------------------------------------------------------------------------------------------
