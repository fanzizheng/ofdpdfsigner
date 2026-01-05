//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDCheckValue.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCheckValue**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue::FZZOFDCheckValue() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCheckValue()");
    FZZConst::addClassCount("FZZOFDCheckValue");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue::FZZOFDCheckValue(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDCheckValue");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue::FZZOFDCheckValue(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCheckValue");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue::FZZOFDCheckValue(const FZZOFDCheckValue& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCheckValue");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue::~FZZOFDCheckValue()
{
    //DLOG("~FZZOFDCheckValue()");
    FZZConst::delClassCount("FZZOFDCheckValue");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCheckValue::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCheckValue::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
