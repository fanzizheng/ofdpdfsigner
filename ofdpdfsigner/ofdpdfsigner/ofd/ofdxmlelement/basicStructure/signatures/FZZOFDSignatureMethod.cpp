//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignatureMethod.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignatureMethod**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod::FZZOFDSignatureMethod() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSignatureMethod()");
    FZZConst::addClassCount("FZZOFDSignatureMethod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod::FZZOFDSignatureMethod(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDSignatureMethod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod::FZZOFDSignatureMethod(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSignatureMethod");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod::FZZOFDSignatureMethod(const FZZOFDSignatureMethod& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignatureMethod");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod::~FZZOFDSignatureMethod()
{
    //DLOG("~FZZOFDSignatureMethod()");
    FZZConst::delClassCount("FZZOFDSignatureMethod");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignatureMethod::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignatureMethod::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
