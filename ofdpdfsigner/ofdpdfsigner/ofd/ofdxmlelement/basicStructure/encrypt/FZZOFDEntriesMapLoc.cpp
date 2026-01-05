//
//  Created by zizheng fan on 2024/10/19.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEntriesMapLoc.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEntriesMapLoc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc::FZZOFDEntriesMapLoc() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDEntriesMapLoc()");
    FZZConst::addClassCount("FZZOFDEntriesMapLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc::FZZOFDEntriesMapLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDEntriesMapLoc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc::FZZOFDEntriesMapLoc(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDEntriesMapLoc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc::FZZOFDEntriesMapLoc(const FZZOFDEntriesMapLoc& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEntriesMapLoc");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc::~FZZOFDEntriesMapLoc()
{
    //DLOG("~FZZOFDEntriesMapLoc()");
    FZZConst::delClassCount("FZZOFDEntriesMapLoc");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEntriesMapLoc::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEntriesMapLoc::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
