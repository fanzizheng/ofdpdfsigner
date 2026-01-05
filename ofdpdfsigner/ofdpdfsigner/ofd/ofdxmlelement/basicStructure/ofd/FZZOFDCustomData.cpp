//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCustomData.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCustomData**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomData::FZZOFDCustomData() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCustomData()");
    FZZConst::addClassCount("FZZOFDCustomData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomData::FZZOFDCustomData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{

    FZZConst::addClassCount("FZZOFDCustomData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomData::FZZOFDCustomData(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCustomData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomData::FZZOFDCustomData(const FZZOFDCustomData& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDCustomData");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomData::~FZZOFDCustomData()
{
    //DLOG("~FZZOFDCustomData()");
    FZZConst::delClassCount("FZZOFDCustomData");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCustomData::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCustomData::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCustomData::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCustomData::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
