//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDHideWindowUI.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDHideWindowUI**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI::FZZOFDHideWindowUI() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDHideWindowUI()");
    FZZConst::addClassCount("FZZOFDHideWindowUI");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI::FZZOFDHideWindowUI(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDHideWindowUI");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI::FZZOFDHideWindowUI(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDHideWindowUI");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI::FZZOFDHideWindowUI(const FZZOFDHideWindowUI& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDHideWindowUI");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI::~FZZOFDHideWindowUI()
{
    //DLOG("~FZZOFDHideWindowUI()");
    FZZConst::delClassCount("FZZOFDHideWindowUI");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDHideWindowUI::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDHideWindowUI::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------
