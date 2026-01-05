//
//  Created by zizheng fan on 2024/09/25.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/entries/FZZOFDSignedValueLoc.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignedValueLoc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc::FZZOFDSignedValueLoc() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSignedValueLoc()");
    FZZConst::addClassCount("FZZOFDSignedValueLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc::FZZOFDSignedValueLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDSignedValueLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc::FZZOFDSignedValueLoc(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSignedValueLoc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc::FZZOFDSignedValueLoc(const FZZOFDSignedValueLoc& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignedValueLoc");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc::~FZZOFDSignedValueLoc()
{
    //DLOG("~FZZOFDSignedValueLoc()");
    FZZConst::delClassCount("FZZOFDSignedValueLoc");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignedValueLoc::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignedValueLoc::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
