//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreator.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCreator**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator::FZZOFDCreator() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCreator()");
    FZZConst::addClassCount("FZZOFDCreator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator::FZZOFDCreator(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDCreator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator::FZZOFDCreator(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCreator");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator::FZZOFDCreator(const FZZOFDCreator& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDCreator");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator::~FZZOFDCreator()
{
    //DLOG("~FZZOFDCreator()");
    FZZConst::delClassCount("FZZOFDCreator");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCreator::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCreator::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
