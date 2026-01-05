//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDWatermark.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDWatermark**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark::FZZOFDWatermark() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDWatermark()");
    FZZConst::addClassCount("FZZOFDWatermark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark::FZZOFDWatermark(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDWatermark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark::FZZOFDWatermark(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDWatermark");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark::FZZOFDWatermark(const FZZOFDWatermark& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDWatermark");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark::~FZZOFDWatermark()
{
    //DLOG("~FZZOFDWatermark()");
    FZZConst::delClassCount("FZZOFDWatermark");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDWatermark::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDWatermark::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------

