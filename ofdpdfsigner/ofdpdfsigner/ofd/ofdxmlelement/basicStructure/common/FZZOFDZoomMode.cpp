//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDZoomMode.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDZoomMode**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode::FZZOFDZoomMode() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDZoomMode()");
    FZZConst::addClassCount("FZZOFDZoomMode");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode::FZZOFDZoomMode(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDZoomMode");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode::FZZOFDZoomMode(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDZoomMode");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode::FZZOFDZoomMode(const FZZOFDZoomMode& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDZoomMode");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode::~FZZOFDZoomMode()
{
    //DLOG("~FZZOFDZoomMode()");
    FZZConst::delClassCount("FZZOFDZoomMode");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDZoomMode::setType(FZZOFDZoomMode::TYPE type)
{
    string strtpte = "Default";
    switch(type) {
        case FZZOFDZoomMode::TYPE::TYPE_Default:
            strtpte = "Default";
            break;
        case FZZOFDZoomMode::TYPE::TYPE_FitHeight:
            strtpte = "FitHeight";
            break;
        case FZZOFDZoomMode::TYPE::TYPE_FitWidth:
            strtpte = "FitWidth";
            break;
        case FZZOFDZoomMode::TYPE::TYPT_FitRect:
            strtpte = "FitRect";
            break;
    }
    setValue_String(strtpte);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode::TYPE FZZOFDZoomMode::getType()
{
    string value = getValue_String();
    FZZOFDZoomMode::TYPE temp = FZZOFDZoomMode::TYPE::TYPE_Default;
    if ( value == "Default" ) {
        temp = FZZOFDZoomMode::TYPE::TYPE_Default;
    } else if (value == "FitHeight") {
        temp = FZZOFDZoomMode::TYPE::TYPE_FitHeight;
    }
    else if (value == "FitWidth") {
        temp = FZZOFDZoomMode::TYPE::TYPE_FitWidth;
    }
    else if (value == "FitRect") {
        temp = FZZOFDZoomMode::TYPE::TYPT_FitRect;
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
