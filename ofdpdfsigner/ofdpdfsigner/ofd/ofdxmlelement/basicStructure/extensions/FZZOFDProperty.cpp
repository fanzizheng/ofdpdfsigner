//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/extensions/FZZOFDProperty.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDProperty**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProperty::FZZOFDProperty() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDProperty()");
    FZZConst::addClassCount("FZZOFDProperty");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProperty::FZZOFDProperty(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDProperty");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProperty::FZZOFDProperty(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDProperty");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProperty::FZZOFDProperty(const FZZOFDProperty& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDProperty");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProperty::~FZZOFDProperty()
{
    //DLOG("~FZZOFDProperty()");
    FZZConst::delClassCount("FZZOFDProperty");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProperty::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProperty::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProperty::setType(string value)
{
    setAttribute_String("Type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProperty::getType()
{
    return getAttribute_String("Type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProperty::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProperty::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
