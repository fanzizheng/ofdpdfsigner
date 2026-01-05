//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDSignature_Permission.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignature_Permission**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission::FZZOFDSignature_Permission() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSignature_Permission()");
    FZZConst::addClassCount("FZZOFDSignature_Permission");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission::FZZOFDSignature_Permission(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDSignature_Permission");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission::FZZOFDSignature_Permission(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSignature_Permission");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission::FZZOFDSignature_Permission(const FZZOFDSignature_Permission& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignature_Permission");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission::~FZZOFDSignature_Permission()
{
    //DLOG("~FZZOFDSignature_Permission()");
    FZZConst::delClassCount("FZZOFDSignature_Permission");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignature_Permission::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDSignature_Permission::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------

