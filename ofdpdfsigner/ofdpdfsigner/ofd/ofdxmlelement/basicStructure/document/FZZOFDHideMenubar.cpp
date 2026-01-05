//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDHideMenubar.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDHideMenubar**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar::FZZOFDHideMenubar() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDHideMenubar()");
    FZZConst::addClassCount("FZZOFDHideMenubar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar::FZZOFDHideMenubar(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDHideMenubar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar::FZZOFDHideMenubar(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDHideMenubar");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar::FZZOFDHideMenubar(const FZZOFDHideMenubar& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDHideMenubar");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar::~FZZOFDHideMenubar()
{
    //DLOG("~FZZOFDHideMenubar()");
    FZZConst::delClassCount("FZZOFDHideMenubar");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDHideMenubar::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDHideMenubar::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------
