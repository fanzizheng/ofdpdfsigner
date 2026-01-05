//
//  Created by zizheng fan on 2023/09/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCharset.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWCharset**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset::FZZWCharset() : FZZXMLElementObject()
{
    //DLOG("FZZWCharset()");
    FZZConst::addClassCount("FZZWCharset");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset::FZZWCharset(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWCharset");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset::FZZWCharset(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWCharset");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset::FZZWCharset(const FZZWCharset& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWCharset");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset::~FZZWCharset()
{
    //DLOG("~FZZWCharset()");
    FZZConst::delClassCount("FZZWCharset");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCharset::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCharset::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
