//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDSubstitution.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSubstitution**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution::FZZOFDSubstitution() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSubstitution()");
    FZZConst::addClassCount("FZZOFDSubstitution");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution::FZZOFDSubstitution(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDSubstitution");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution::FZZOFDSubstitution(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSubstitution");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution::FZZOFDSubstitution(const FZZOFDSubstitution& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSubstitution");
    if ( this == &obj ) {
        return;
    }
    
    
 
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution::~FZZOFDSubstitution()
{
    //DLOG("~FZZOFDSubstitution()");
    FZZConst::delClassCount("FZZOFDSubstitution");
        
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSubstitution::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSubstitution::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSubstitution::setValue(long value)
{
    setValue_long(value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDSubstitution::getLongValue()
{
    return getValue_long();
}
//-----------------------------------------------------------------------------------------------------------------
