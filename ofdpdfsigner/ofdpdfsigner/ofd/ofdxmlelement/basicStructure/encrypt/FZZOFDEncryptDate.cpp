//
//  Created by zizheng fan on 2024/10/19.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptDate.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEncryptDate**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate::FZZOFDEncryptDate() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDEncryptDate()");
    FZZConst::addClassCount("FZZOFDEncryptDate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate::FZZOFDEncryptDate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDEncryptDate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate::FZZOFDEncryptDate(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDEncryptDate");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate::FZZOFDEncryptDate(const FZZOFDEncryptDate& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEncryptDate");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate::~FZZOFDEncryptDate()
{
    //DLOG("~FZZOFDEncryptDate()");
    FZZConst::delClassCount("FZZOFDEncryptDate");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptDate::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptDate::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
