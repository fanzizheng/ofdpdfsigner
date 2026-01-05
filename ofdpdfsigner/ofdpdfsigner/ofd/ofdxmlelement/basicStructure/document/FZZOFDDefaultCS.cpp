//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDefaultCS.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDefaultCS**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS::FZZOFDDefaultCS() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDefaultCS()");
    FZZConst::addClassCount("FZZOFDDefaultCS");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS::FZZOFDDefaultCS(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDDefaultCS");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS::FZZOFDDefaultCS(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDefaultCS");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS::FZZOFDDefaultCS(const FZZOFDDefaultCS& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDefaultCS");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS::~FZZOFDDefaultCS()
{
    //DLOG("~FZZOFDDefaultCS()");
    FZZConst::delClassCount("FZZOFDDefaultCS");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDefaultCS::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDefaultCS::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDefaultCS::setValue(long value)
{
    
    setValue_long(value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDDefaultCS::getLongValue()
{
    return getValue_long();
   
}
//-----------------------------------------------------------------------------------------------------------------
