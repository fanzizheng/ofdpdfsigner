//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Extensions.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocument_Extensions**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions::FZZOFDDocument_Extensions() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocument_Extensions()");
    FZZConst::addClassCount("FZZOFDDocument_Extensions");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions::FZZOFDDocument_Extensions(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDDocument_Extensions");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions::FZZOFDDocument_Extensions(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocument_Extensions");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions::FZZOFDDocument_Extensions(const FZZOFDDocument_Extensions& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDocument_Extensions");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions::~FZZOFDDocument_Extensions()
{
    //DLOG("~FZZOFDDocument_Extensions()");
    FZZConst::delClassCount("FZZOFDDocument_Extensions");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocument_Extensions::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocument_Extensions::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
