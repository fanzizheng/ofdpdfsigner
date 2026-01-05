//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Attachments.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocument_Attachments**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments::FZZOFDDocument_Attachments() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocument_Attachments()");
    FZZConst::addClassCount("FZZOFDDocument_Attachments");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments::FZZOFDDocument_Attachments(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDDocument_Attachments");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments::FZZOFDDocument_Attachments(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocument_Attachments");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments::FZZOFDDocument_Attachments(const FZZOFDDocument_Attachments& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDocument_Attachments");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments::~FZZOFDDocument_Attachments()
{
    //DLOG("~FZZOFDDocument_Attachments()");
    FZZConst::delClassCount("FZZOFDDocument_Attachments");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocument_Attachments::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocument_Attachments::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
