//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDExtendData.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDExtendData**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData::FZZOFDExtendData() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDExtendData()");
    FZZConst::addClassCount("FZZOFDExtendData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData::FZZOFDExtendData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDExtendData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData::FZZOFDExtendData(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDExtendData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData::FZZOFDExtendData(const FZZOFDExtendData& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDExtendData");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData::~FZZOFDExtendData()
{
    //DLOG("~FZZOFDExtendData()");
    FZZConst::delClassCount("FZZOFDExtendData");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtendData::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDExtendData::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
