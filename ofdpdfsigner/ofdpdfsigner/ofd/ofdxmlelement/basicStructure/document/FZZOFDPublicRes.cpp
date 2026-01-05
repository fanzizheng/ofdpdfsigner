//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPublicRes.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPublicRes**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes::FZZOFDPublicRes() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPublicRes()");
    FZZConst::addClassCount("FZZOFDPublicRes");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes::FZZOFDPublicRes(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPublicRes");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes::FZZOFDPublicRes(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPublicRes");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes::FZZOFDPublicRes(const FZZOFDPublicRes& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPublicRes");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes::~FZZOFDPublicRes()
{
    //DLOG("~FZZOFDPublicRes()");
    FZZConst::delClassCount("FZZOFDPublicRes");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPublicRes::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPublicRes::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------

