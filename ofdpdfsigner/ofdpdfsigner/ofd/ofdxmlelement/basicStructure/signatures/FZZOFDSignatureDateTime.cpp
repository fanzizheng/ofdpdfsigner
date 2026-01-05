//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignatureDateTime.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignatureDateTime**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime::FZZOFDSignatureDateTime() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSignatureDateTime()");
    FZZConst::addClassCount("FZZOFDSignatureDateTime");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime::FZZOFDSignatureDateTime(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDSignatureDateTime");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime::FZZOFDSignatureDateTime(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSignatureDateTime");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime::FZZOFDSignatureDateTime(const FZZOFDSignatureDateTime& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignatureDateTime");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime::~FZZOFDSignatureDateTime()
{
    //DLOG("~FZZOFDSignatureDateTime()");
    FZZConst::delClassCount("FZZOFDSignatureDateTime");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignatureDateTime::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignatureDateTime::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
