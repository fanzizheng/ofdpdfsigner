//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDMaxSignId.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDMaxSignId**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId::FZZOFDMaxSignId() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDMaxSignId()");
    FZZConst::addClassCount("FZZOFDMaxSignId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId::FZZOFDMaxSignId(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDMaxSignId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId::FZZOFDMaxSignId(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDMaxSignId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId::FZZOFDMaxSignId(const FZZOFDMaxSignId& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDMaxSignId");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId::~FZZOFDMaxSignId()
{
    //DLOG("~FZZOFDMaxSignId()");
    FZZConst::delClassCount("FZZOFDMaxSignId");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMaxSignId::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDMaxSignId::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
