//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageMode.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageMode**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode::FZZOFDPageMode() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPageMode()");
    FZZConst::addClassCount("FZZOFDPageMode");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode::FZZOFDPageMode(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPageMode");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode::FZZOFDPageMode(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPageMode");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode::FZZOFDPageMode(const FZZOFDPageMode& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPageMode");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode::~FZZOFDPageMode()
{
    //DLOG("~FZZOFDPageMode()");
    FZZConst::delClassCount("FZZOFDPageMode");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageMode::setType(FZZOFDPageMode::TYPE value)
{
    string strtype = "None";
    switch (value) {
        case FZZOFDPageMode::TYPE::None:
            strtype = "None";
            break;
        case FZZOFDPageMode::TYPE::FullScreen:
            strtype = "FullScreen";
            break;
        case FZZOFDPageMode::TYPE::UseOutlines:
            strtype = "UseOutlines";
            break;
        case FZZOFDPageMode::TYPE::UseThumbs:
            strtype = "UseThumbs";
            break;
        case FZZOFDPageMode::TYPE::UseCustomTags:
            strtype = "UseCustomTags";
            break;
        case FZZOFDPageMode::TYPE::UseLayers:
            strtype = "UseLayers";
            break;
        case FZZOFDPageMode::TYPE::UseAttatchs:
            strtype = "UseAttatchs";
            break;
        case FZZOFDPageMode::TYPE::UseBookmarks:
            strtype = "UseBookmarks";
            break;
        default:
            strtype = "None";
            break;

    }
    setValue_String(strtype);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode::TYPE FZZOFDPageMode::getType()
{
    FZZOFDPageMode::TYPE retvalue = FZZOFDPageMode::TYPE::None;
    string data = getValue_String();
    if (data == "None") {
        retvalue = FZZOFDPageMode::TYPE::None;
    }
    else if (data == "FullScreen") {
        retvalue = FZZOFDPageMode::TYPE::FullScreen;
    }
    else if (data == "UseOutlines") {
        retvalue = FZZOFDPageMode::TYPE::UseOutlines;
    }
    else if (data == "UseThumbs") {
        retvalue = FZZOFDPageMode::TYPE::UseThumbs;
    }
    else if (data == "UseCustomTags") {
        retvalue = FZZOFDPageMode::TYPE::UseCustomTags;
    }
    else if (data == "UseLayers") {
        retvalue = FZZOFDPageMode::TYPE::UseLayers;
    }
    else if (data == "UseAttatchs") {
        retvalue = FZZOFDPageMode::TYPE::UseAttatchs;
    }
    else if (data == "UseBookmarks") {
        retvalue = FZZOFDPageMode::TYPE::UseBookmarks;
    }
    return retvalue;
}
//-----------------------------------------------------------------------------------------------------------------
