//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDAbstract.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAbstract**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract::FZZOFDAbstract() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDAbstract()");
    FZZConst::addClassCount("FZZOFDAbstract");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract::FZZOFDAbstract(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDAbstract");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract::FZZOFDAbstract(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDAbstract");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract::FZZOFDAbstract(const FZZOFDAbstract& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDAbstract");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract::~FZZOFDAbstract()
{
    //DLOG("~FZZOFDAbstract()");
    FZZConst::delClassCount("FZZOFDAbstract");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbstract::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAbstract::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
