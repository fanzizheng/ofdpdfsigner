//
//  Created by zizheng fan on 2023/09/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWListSeparator.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWListSeparator**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator::FZZWListSeparator() : FZZXMLElementObject()
{
    //DLOG("FZZWListSeparator()");
    FZZConst::addClassCount("FZZWListSeparator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator::FZZWListSeparator(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWListSeparator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator::FZZWListSeparator(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWListSeparator");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator::FZZWListSeparator(const FZZWListSeparator& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWListSeparator");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator::~FZZWListSeparator()
{
    //DLOG("~FZZWListSeparator()");
    FZZConst::delClassCount("FZZWListSeparator");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWListSeparator::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWListSeparator::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
