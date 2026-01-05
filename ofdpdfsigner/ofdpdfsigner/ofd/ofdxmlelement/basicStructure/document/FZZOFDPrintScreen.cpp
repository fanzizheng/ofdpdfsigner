//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPrintScreen.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPrintScreen**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen::FZZOFDPrintScreen() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPrintScreen()");
    FZZConst::addClassCount("FZZOFDPrintScreen");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen::FZZOFDPrintScreen(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPrintScreen");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen::FZZOFDPrintScreen(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPrintScreen");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen::FZZOFDPrintScreen(const FZZOFDPrintScreen& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPrintScreen");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen::~FZZOFDPrintScreen()
{
    //DLOG("~FZZOFDPrintScreen()");
    FZZConst::delClassCount("FZZOFDPrintScreen");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPrintScreen::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDPrintScreen::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------

