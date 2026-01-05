//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDURI.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDURI**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI::FZZOFDURI() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDURI()");
    FZZConst::addClassCount("FZZOFDURI");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI::FZZOFDURI(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDURI");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI::FZZOFDURI(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDURI");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI::FZZOFDURI(const FZZOFDURI& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDURI");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI::~FZZOFDURI()
{
    //DLOG("~FZZOFDURI()");
    FZZConst::delClassCount("FZZOFDURI");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDURI::setURI(string value)
{
    setAttribute_String("URI",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDURI::getURI()
{
    return getAttribute_String("URI");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDURI::setBase(string value)
{
    setAttribute_String("Base",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDURI::getBase()
{
    return getAttribute_String("Base");
}
//-----------------------------------------------------------------------------------------------------------------
