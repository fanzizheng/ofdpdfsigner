//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDHideToolbar.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDHideToolbar**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar::FZZOFDHideToolbar() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDHideToolbar()");
    FZZConst::addClassCount("FZZOFDHideToolbar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar::FZZOFDHideToolbar(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDHideToolbar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar::FZZOFDHideToolbar(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDHideToolbar");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar::FZZOFDHideToolbar(const FZZOFDHideToolbar& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDHideToolbar");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar::~FZZOFDHideToolbar()
{
    //DLOG("~FZZOFDHideToolbar()");
    FZZConst::delClassCount("FZZOFDHideToolbar");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDHideToolbar::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDHideToolbar::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------
