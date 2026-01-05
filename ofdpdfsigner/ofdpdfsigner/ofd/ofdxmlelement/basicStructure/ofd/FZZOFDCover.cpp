//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCover.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCover**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover::FZZOFDCover() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCover()");
    FZZConst::addClassCount("FZZOFDCover");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover::FZZOFDCover(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDDocBody");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover::FZZOFDCover(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCover");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover::FZZOFDCover(const FZZOFDCover& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDCover");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover::~FZZOFDCover()
{
    //DLOG("~FZZOFDCover()");
    FZZConst::delClassCount("FZZOFDCover");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCover::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCover::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
