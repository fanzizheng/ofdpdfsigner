//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocID.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocID**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID::FZZOFDDocID() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocID()");
    FZZConst::addClassCount("FZZOFDDocID");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID::FZZOFDDocID(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDDocID");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID::FZZOFDDocID(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocID");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID::FZZOFDDocID(const FZZOFDDocID& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDDocID");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID::~FZZOFDDocID()
{
    //DLOG("~FZZOFDDocID()");
    FZZConst::delClassCount("FZZOFDDocID");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocID::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocID::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
