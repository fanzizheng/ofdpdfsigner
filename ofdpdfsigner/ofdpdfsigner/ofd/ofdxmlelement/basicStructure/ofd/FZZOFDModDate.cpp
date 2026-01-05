//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDModDate.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDModDate**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate::FZZOFDModDate() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDModDate()");
    FZZConst::addClassCount("FZZOFDModDate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate::FZZOFDModDate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDModDate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate::FZZOFDModDate(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDModDate");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate::FZZOFDModDate(const FZZOFDModDate& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDModDate");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate::~FZZOFDModDate()
{
    //DLOG("~FZZOFDModDate()");
    FZZConst::delClassCount("FZZOFDModDate");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDModDate::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDModDate::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
