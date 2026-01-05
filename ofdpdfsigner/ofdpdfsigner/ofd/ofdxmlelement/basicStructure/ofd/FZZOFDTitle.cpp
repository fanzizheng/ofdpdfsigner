//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDTitle.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTitle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle::FZZOFDTitle() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDTitle()");
    FZZConst::addClassCount("FZZOFDTitle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle::FZZOFDTitle(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDTitle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle::FZZOFDTitle(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDTitle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle::FZZOFDTitle(const FZZOFDTitle& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDTitle");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle::~FZZOFDTitle()
{
    //DLOG("~FZZOFDTitle()");
    FZZConst::delClassCount("FZZOFDTitle");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTitle::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTitle::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
