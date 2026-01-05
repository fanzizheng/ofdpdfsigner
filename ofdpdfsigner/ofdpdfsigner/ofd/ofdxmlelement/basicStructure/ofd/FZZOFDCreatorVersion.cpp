//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreatorVersion.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCreatorVersion**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion::FZZOFDCreatorVersion() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCreatorVersion()");
    FZZConst::addClassCount("FZZOFDCreatorVersion");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion::FZZOFDCreatorVersion(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDCreatorVersion");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion::FZZOFDCreatorVersion(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCreatorVersion");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion::FZZOFDCreatorVersion(const FZZOFDCreatorVersion& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDCreatorVersion");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion::~FZZOFDCreatorVersion()
{
    //DLOG("~FZZOFDCreatorVersion()");
    FZZConst::delClassCount("FZZOFDCreatorVersion");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCreatorVersion::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCreatorVersion::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
