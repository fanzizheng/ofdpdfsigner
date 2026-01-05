//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDMaxUnitID.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDMaxUnitID**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID::FZZOFDMaxUnitID() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDMaxUnitID()");
    FZZConst::addClassCount("FZZOFDMaxUnitID");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID::FZZOFDMaxUnitID(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDMaxUnitID");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID::FZZOFDMaxUnitID(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDMaxUnitID");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID::FZZOFDMaxUnitID(const FZZOFDMaxUnitID& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDMaxUnitID");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID::~FZZOFDMaxUnitID()
{
    //DLOG("~FZZOFDMaxUnitID()");
    FZZConst::delClassCount("FZZOFDMaxUnitID");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMaxUnitID::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDMaxUnitID::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMaxUnitID::setValue(long value)
{
    
    setValue_long(value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDMaxUnitID::getLongValue()
{
    return getValue_long();
    
}
//-----------------------------------------------------------------------------------------------------------------
