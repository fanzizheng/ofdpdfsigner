//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDRight.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDRight**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight::FZZOFDRight() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDRight()");
    FZZConst::addClassCount("FZZOFDRight");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight::FZZOFDRight(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDRight");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight::FZZOFDRight(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDRight");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight::FZZOFDRight(const FZZOFDRight& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDRight");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRight::~FZZOFDRight()
{
    //DLOG("~FZZOFDRight()");
    FZZConst::delClassCount("FZZOFDRight");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRight::setValue(double value)
{
    setValue_double(value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDRight::getValue()
{
    return getValue_double();
}
//-----------------------------------------------------------------------------------------------------------------
