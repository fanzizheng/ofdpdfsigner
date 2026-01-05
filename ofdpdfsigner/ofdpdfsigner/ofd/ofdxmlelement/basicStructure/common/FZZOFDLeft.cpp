//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLeft.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDLeft**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft::FZZOFDLeft() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDLeft()");
    FZZConst::addClassCount("FZZOFDLeft");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft::FZZOFDLeft(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDLeft");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft::FZZOFDLeft(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDLeft");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft::FZZOFDLeft(const FZZOFDLeft& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDLeft");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLeft::~FZZOFDLeft()
{
    //DLOG("~FZZOFDLeft()");
    FZZConst::delClassCount("FZZOFDLeft");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLeft::setValue(double value)
{
    setValue_double(value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDLeft::getValue()
{
    return getValue_double();
}
//-----------------------------------------------------------------------------------------------------------------
