//
//  Created by zizheng fan on 2024/10/19.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDDecryptSeedLoc.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDecryptSeedLoc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc::FZZOFDDecryptSeedLoc() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDecryptSeedLoc()");
    FZZConst::addClassCount("FZZOFDDecryptSeedLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc::FZZOFDDecryptSeedLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDDecryptSeedLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc::FZZOFDDecryptSeedLoc(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDecryptSeedLoc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc::FZZOFDDecryptSeedLoc(const FZZOFDDecryptSeedLoc& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDecryptSeedLoc");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc::~FZZOFDDecryptSeedLoc()
{
    //DLOG("~FZZOFDDecryptSeedLoc()");
    FZZConst::delClassCount("FZZOFDDecryptSeedLoc");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDecryptSeedLoc::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDecryptSeedLoc::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
