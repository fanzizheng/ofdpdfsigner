//
//  Created by zizheng fan on 2024/10/17.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncParameter.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEncParameter**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncParameter::FZZOFDEncParameter() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDEncParameter()");
    FZZConst::addClassCount("FZZOFDEncParameter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncParameter::FZZOFDEncParameter(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDEncParameter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncParameter::FZZOFDEncParameter(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDEncParameter");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncParameter::FZZOFDEncParameter(const FZZOFDEncParameter& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEncParameter");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncParameter::~FZZOFDEncParameter()
{
    //DLOG("~FZZOFDEncParameter()");
    FZZConst::delClassCount("FZZOFDEncParameter");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncParameter::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncParameter::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncParameter::setValue(string value)
{
    setAttribute_String("Value",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncParameter::getValue()
{
    return getAttribute_String("Value");
}
//-----------------------------------------------------------------------------------------------------------------

