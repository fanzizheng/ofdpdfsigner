//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Annotations.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocument_Annotations**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations::FZZOFDDocument_Annotations() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocument_Annotations()");
    FZZConst::addClassCount("FZZOFDDocument_Annotations");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations::FZZOFDDocument_Annotations(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDDocument_Annotations");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations::FZZOFDDocument_Annotations(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocument_Annotations");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations::FZZOFDDocument_Annotations(const FZZOFDDocument_Annotations& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDocument_Annotations");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations::~FZZOFDDocument_Annotations()
{
    //DLOG("~FZZOFDDocument_Annotations()");
    FZZConst::delClassCount("FZZOFDDocument_Annotations");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocument_Annotations::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocument_Annotations::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
