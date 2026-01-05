//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedValue.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignedValue**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue::FZZOFDSignedValue() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSignedValue()");
    FZZConst::addClassCount("FZZOFDSignedValue");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue::FZZOFDSignedValue(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDSignedValue");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue::FZZOFDSignedValue(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSignedValue");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue::FZZOFDSignedValue(const FZZOFDSignedValue& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignedValue");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue::~FZZOFDSignedValue()
{
    //DLOG("~FZZOFDSignedValue()");
    FZZConst::delClassCount("FZZOFDSignedValue");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignedValue::setValue(string value)
{
//    if ( value[0] != '/' ) {
//        value = "/" + value;
//    }
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignedValue::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
