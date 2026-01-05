//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameter.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDParameter**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter::FZZOFDParameter() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDParameter()");
    FZZConst::addClassCount("FZZOFDParameter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter::FZZOFDParameter(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDParameter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter::FZZOFDParameter(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDParameter");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter::FZZOFDParameter(const FZZOFDParameter& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDParameter");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter::~FZZOFDParameter()
{
    //DLOG("~FZZOFDParameter()");
    FZZConst::delClassCount("FZZOFDParameter");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDParameter::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDParameter::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDParameter::setType(string value)
{
    setAttribute_String("Type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDParameter::getType()
{
    return getAttribute_String("Type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDParameter::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDParameter::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
