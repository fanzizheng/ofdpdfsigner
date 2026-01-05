//
//  Created by zizheng fan on 2024/10/19.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptScope.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEncryptScope**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope::FZZOFDEncryptScope() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDEncryptScope()");
    FZZConst::addClassCount("FZZOFDEncryptScope");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope::FZZOFDEncryptScope(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDEncryptScope");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope::FZZOFDEncryptScope(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDEncryptScope");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope::FZZOFDEncryptScope(const FZZOFDEncryptScope& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEncryptScope");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope::~FZZOFDEncryptScope()
{
    //DLOG("~FZZOFDEncryptScope()");
    FZZConst::delClassCount("FZZOFDEncryptScope");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptScope::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptScope::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
