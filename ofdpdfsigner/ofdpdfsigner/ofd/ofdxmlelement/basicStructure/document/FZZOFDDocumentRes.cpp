//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocumentRes.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocumentRes**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes::FZZOFDDocumentRes() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocumentRes()");
    FZZConst::addClassCount("FZZOFDDocumentRes");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes::FZZOFDDocumentRes(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDDocumentRes");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes::FZZOFDDocumentRes(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocumentRes");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes::FZZOFDDocumentRes(const FZZOFDDocumentRes& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDocumentRes");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes::~FZZOFDDocumentRes()
{
    //DLOG("~FZZOFDDocumentRes()");
    FZZConst::delClassCount("FZZOFDDocumentRes");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocumentRes::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocumentRes::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------

