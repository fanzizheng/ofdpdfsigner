//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocBody_Signatures.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocBody_Signatures**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures::FZZOFDDocBody_Signatures() : FZZOFDXMLElementObject()
{

    FZZConst::addClassCount("FZZOFDDocBody_Signatures");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures::FZZOFDDocBody_Signatures(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDDocBody_Signatures");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures::FZZOFDDocBody_Signatures(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocBody_Signatures");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures::FZZOFDDocBody_Signatures(const FZZOFDDocBody_Signatures& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDDocBody_Signatures");
    if ( this == &obj ) {
        return;
    }

    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures::~FZZOFDDocBody_Signatures()
{

    FZZConst::delClassCount("FZZOFDDocBody_Signatures");

    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocBody_Signatures::setValue(string value)
{
//    if ( value[0] != '/' ) {
//        value = "/" + value;
//    }
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocBody_Signatures::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
