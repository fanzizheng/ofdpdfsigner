//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreationDate.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCreationDate**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate::FZZOFDCreationDate() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCreationDate()");
    FZZConst::addClassCount("FZZOFDCreationDate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate::FZZOFDCreationDate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDCreationDate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate::FZZOFDCreationDate(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCreationDate");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate::FZZOFDCreationDate(const FZZOFDCreationDate& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDCreationDate");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate::~FZZOFDCreationDate()
{
    //DLOG("~FZZOFDCreationDate()");
    FZZConst::delClassCount("FZZOFDCreationDate");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCreationDate::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCreationDate::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
