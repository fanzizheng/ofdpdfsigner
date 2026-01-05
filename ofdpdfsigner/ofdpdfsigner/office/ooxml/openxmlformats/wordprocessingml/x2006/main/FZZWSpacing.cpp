//
//  Created by zizheng fan on 2023/10/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpacing.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSpacing**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing::FZZWSpacing() : FZZXMLElementObject()
{
    //DLOG("FZZWSpacing()");
    FZZConst::addClassCount("FZZWSpacing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing::FZZWSpacing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSpacing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing::FZZWSpacing(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSpacing");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing::FZZWSpacing(const FZZWSpacing& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSpacing");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing::~FZZWSpacing()
{
    //DLOG("~FZZWSpacing()");
    FZZConst::delClassCount("FZZWSpacing");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSpacing::setBefore(string value)
{
    setAttribute_String("w:before",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSpacing::getBefore()
{
    return getAttribute_String("w:before");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSpacing::setAfter(string value)
{
    setAttribute_String("w:after",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSpacing::getAfter()
{
    return getAttribute_String("w:after");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSpacing::setLine(string value)
{
    setAttribute_String("w:line",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSpacing::getLine()
{
    return getAttribute_String("w:line");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSpacing::setLineRule(string value)
{
    setAttribute_String("w:lineRule",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSpacing::getLineRule()
{
    return getAttribute_String("w:lineRule");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSpacing::setAfterLines(string value)
{
    setAttribute_String("w:afterLines",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSpacing::getAfterLines()
{
    return getAttribute_String("w:afterLines");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSpacing::setBeforeLines(string value)
{
    setAttribute_String("w:beforeLines",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSpacing::getBeforeLines()
{
    return getAttribute_String("w:beforeLines");
}
//-----------------------------------------------------------------------------------------------------------------
