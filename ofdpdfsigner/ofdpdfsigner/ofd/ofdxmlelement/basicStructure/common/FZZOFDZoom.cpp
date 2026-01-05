//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDZoom.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDZoom**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom::FZZOFDZoom() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDZoom()");
    FZZConst::addClassCount("FZZOFDZoom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom::FZZOFDZoom(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDZoom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom::FZZOFDZoom(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDZoom");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom::FZZOFDZoom(const FZZOFDZoom& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDZoom");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom::~FZZOFDZoom()
{
    //DLOG("~FZZOFDZoom()");
    FZZConst::delClassCount("FZZOFDZoom");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDZoom::setValue(double value)
{
    setValue_double(value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDZoom::getValue()
{
    return getValue_double();
}
//-----------------------------------------------------------------------------------------------------------------
