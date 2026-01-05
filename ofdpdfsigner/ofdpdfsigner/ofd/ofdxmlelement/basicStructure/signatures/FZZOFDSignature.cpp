//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignature.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignature**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature::FZZOFDSignature() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSignature()");
    FZZConst::addClassCount("FZZOFDSignature");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature::FZZOFDSignature(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDSignature");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature::FZZOFDSignature(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSignature");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature::FZZOFDSignature(const FZZOFDSignature& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignature");
    if ( this == &obj ) {
        return;
    }
   
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature::~FZZOFDSignature()
{
    //DLOG("~FZZOFDSignature()");
    FZZConst::delClassCount("FZZOFDSignature");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignature::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignature::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignature::setType(FZZOFDSigType::TYPE value)
{
    setAttribute_String("Type",FZZOFDSigType::toString(value));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigType::TYPE FZZOFDSignature::getType()
{
    return FZZOFDSigType::toType(getAttribute_String("Type").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignature::setBaseLoc(string value)
{
//    if ( value[0] != '/' ) {
//        value = "/" + value;
//    }
    setAttribute_String("BaseLoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignature::getBaseLoc()
{
    return getAttribute_String("BaseLoc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignature::setRelative(string value)
{
    setAttribute_String("Relative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignature::getRelative()
{
    return getAttribute_String("Relative");
}
//-----------------------------------------------------------------------------------------------------------------

