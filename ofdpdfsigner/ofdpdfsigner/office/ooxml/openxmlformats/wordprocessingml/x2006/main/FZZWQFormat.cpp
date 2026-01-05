//
//  Created by zizheng fan on 2023/10/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWQFormat.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWQFormat**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat::FZZWQFormat() : FZZXMLElementObject()
{
    //DLOG("FZZWQFormat()");
    FZZConst::addClassCount("FZZWQFormat");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat::FZZWQFormat(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWQFormat");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat::FZZWQFormat(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWQFormat");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat::FZZWQFormat(const FZZWQFormat& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWQFormat");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat::~FZZWQFormat()
{
    //DLOG("~FZZWQFormat()");
    FZZConst::delClassCount("FZZWQFormat");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWQFormat::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWQFormat::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
