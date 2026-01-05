//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_CustomTags.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocument_CustomTags**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags::FZZOFDDocument_CustomTags() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocument_CustomTags()");
    FZZConst::addClassCount("FZZOFDDocument_CustomTags");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags::FZZOFDDocument_CustomTags(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDDocument_CustomTags");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags::FZZOFDDocument_CustomTags(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocument_CustomTags");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags::FZZOFDDocument_CustomTags(const FZZOFDDocument_CustomTags& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDocument_CustomTags");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags::~FZZOFDDocument_CustomTags()
{
    //DLOG("~FZZOFDDocument_CustomTags()");
    FZZConst::delClassCount("FZZOFDDocument_CustomTags");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocument_CustomTags::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocument_CustomTags::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
