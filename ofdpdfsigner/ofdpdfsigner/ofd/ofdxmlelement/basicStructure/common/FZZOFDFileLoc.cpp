//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDFileLoc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc::FZZOFDFileLoc() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDFileLoc()");
    FZZConst::addClassCount("FZZOFDFileLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc::FZZOFDFileLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDFileLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc::FZZOFDFileLoc(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDFileLoc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc::FZZOFDFileLoc(const FZZOFDFileLoc& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDFileLoc");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc::~FZZOFDFileLoc()
{
    //DLOG("~FZZOFDFileLoc()");
    FZZConst::delClassCount("FZZOFDFileLoc");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFileLoc::setValue(string value)
{
//    if ( value[0] != '/' ) {
//        value = "/" + value;
//    }
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFileLoc::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
