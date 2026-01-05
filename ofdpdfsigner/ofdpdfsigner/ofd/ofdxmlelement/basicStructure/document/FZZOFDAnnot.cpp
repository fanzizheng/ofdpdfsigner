//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDAnnot.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAnnot**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot::FZZOFDAnnot() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDAnnot()");
    FZZConst::addClassCount("FZZOFDAnnot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot::FZZOFDAnnot(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDAnnot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot::FZZOFDAnnot(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDAnnot");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot::FZZOFDAnnot(const FZZOFDAnnot& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAnnot");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot::~FZZOFDAnnot()
{
    //DLOG("~FZZOFDAnnot()");
    FZZConst::delClassCount("FZZOFDAnnot");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAnnot::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------

