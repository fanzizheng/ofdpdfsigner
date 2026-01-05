//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDEdit.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEdit**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit::FZZOFDEdit() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDEdit()");
    FZZConst::addClassCount("FZZOFDEdit");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit::FZZOFDEdit(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDEdit");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit::FZZOFDEdit(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDEdit");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit::FZZOFDEdit(const FZZOFDEdit& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEdit");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit::~FZZOFDEdit()
{
    //DLOG("~FZZOFDEdit()");
    FZZConst::delClassCount("FZZOFDEdit");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEdit::setValue(bool value)
{
    setValue_Bool(value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDEdit::getValue()
{
    return getValue_Bool();
}
//-----------------------------------------------------------------------------------------------------------------

