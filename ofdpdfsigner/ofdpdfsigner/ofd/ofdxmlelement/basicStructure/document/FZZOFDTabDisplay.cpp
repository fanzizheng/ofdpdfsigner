//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDTabDisplay.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTabDisplay**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay::FZZOFDTabDisplay() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDTabDisplay()");
    FZZConst::addClassCount("FZZOFDTabDisplay");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay::FZZOFDTabDisplay(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDTabDisplay");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay::FZZOFDTabDisplay(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDTabDisplay");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay::FZZOFDTabDisplay(const FZZOFDTabDisplay& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDTabDisplay");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay::~FZZOFDTabDisplay()
{
    //DLOG("~FZZOFDTabDisplay()");
    FZZConst::delClassCount("FZZOFDTabDisplay");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTabDisplay::setType(FZZOFDTabDisplay::TYPE value)
{
    string strtpte = "FileName";
    switch(value) {
        case FZZOFDTabDisplay::TYPE::FileName:
            strtpte = "FileName";
            break;
        case FZZOFDTabDisplay::TYPE::DocTitle:
            strtpte = "DocTitle";
            break;
        default:
            strtpte = "FileName";
            break;
    }
    setValue_String(strtpte);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay::TYPE FZZOFDTabDisplay::getType()
{
    FZZOFDTabDisplay::TYPE retvalue = FZZOFDTabDisplay::TYPE::FileName;
    string data = getValue_String();
    if (data == "FileName") {
        retvalue = FZZOFDTabDisplay::TYPE::FileName;
    }
    else if (data == "DocTitle") {
        retvalue = FZZOFDTabDisplay::TYPE::DocTitle;
    }
    return retvalue;
}
//-----------------------------------------------------------------------------------------------------------------
