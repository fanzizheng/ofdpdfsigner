//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTop.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTop**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop::FZZOFDTop() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDTop()");
    FZZConst::addClassCount("FZZOFDTop");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop::FZZOFDTop(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDTop");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop::FZZOFDTop(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDTop");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop::FZZOFDTop(const FZZOFDTop& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDTop");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTop::~FZZOFDTop()
{
    //DLOG("~FZZOFDTop()");
    FZZConst::delClassCount("FZZOFDTop");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTop::setValue(double value)
{
    setValue_double(value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDTop::getValue()
{
    return getValue_double();
}
//-----------------------------------------------------------------------------------------------------------------
