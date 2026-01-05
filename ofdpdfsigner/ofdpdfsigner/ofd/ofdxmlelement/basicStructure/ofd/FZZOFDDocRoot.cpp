//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocRoot.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocRoot**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot::FZZOFDDocRoot() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocRoot()");
    FZZConst::addClassCount("FZZOFDDocRoot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot::FZZOFDDocRoot(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDDocRoot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot::FZZOFDDocRoot(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocRoot");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot::FZZOFDDocRoot(const FZZOFDDocRoot& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDDocRoot");
    if ( this == &obj ) {
        return;
    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot::~FZZOFDDocRoot()
{
    //DLOG("~FZZOFDDocRoot()");
    FZZConst::delClassCount("FZZOFDDocRoot");

    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocRoot::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocRoot::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
