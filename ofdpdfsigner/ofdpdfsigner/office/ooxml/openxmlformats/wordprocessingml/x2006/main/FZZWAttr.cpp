//
//  Created by zizheng fan on 2023/11/29
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAttr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWAttr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWAttr::FZZWAttr() : FZZXMLElementObject()
{
    //DLOG("FZZWAttr()");
    FZZConst::addClassCount("FZZWAttr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAttr::FZZWAttr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWAttr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAttr::FZZWAttr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWAttr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAttr::FZZWAttr(const FZZWAttr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWAttr");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAttr::~FZZWAttr()
{
    //DLOG("~FZZWAttr()");
    FZZConst::delClassCount("FZZWAttr");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWAttr::setName(string value)
{
    setAttribute_String("w:name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWAttr::getName()
{
    return getAttribute_String("w:name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWAttr::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWAttr::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
