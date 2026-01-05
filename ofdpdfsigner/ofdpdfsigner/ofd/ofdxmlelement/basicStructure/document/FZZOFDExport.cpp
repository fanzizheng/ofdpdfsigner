//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDExport.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDExport**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport::FZZOFDExport() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDExport()");
    FZZConst::addClassCount("FZZOFDExport");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport::FZZOFDExport(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDExport");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport::FZZOFDExport(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDExport");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport::FZZOFDExport(const FZZOFDExport& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDExport");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport::~FZZOFDExport()
{
    //DLOG("~FZZOFDExport()");
    FZZConst::delClassCount("FZZOFDExport");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExport::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDExport::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------

