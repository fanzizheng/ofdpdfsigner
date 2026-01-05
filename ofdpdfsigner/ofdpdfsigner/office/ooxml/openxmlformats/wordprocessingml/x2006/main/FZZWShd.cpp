//
//  Created by zizheng fan on 2023/11/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWShd.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWShd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWShd::FZZWShd() : FZZXMLElementObject()
{
    //DLOG("FZZWShd()");
    FZZConst::addClassCount("FZZWShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWShd::FZZWShd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWShd::FZZWShd(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWShd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWShd::FZZWShd(const FZZWShd& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWShd");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWShd::~FZZWShd()
{
    //DLOG("~FZZWShd()");
    FZZConst::delClassCount("FZZWShd");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWShd::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWShd::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWShd::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWShd::getColor()
{
    return getAttribute_String("w:color");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWShd::setFill(string value)
{
    setAttribute_String("w:fill",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWShd::getFill()
{
    return getAttribute_String("w:fill");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWShd::setThemeFill(string value)
{
    setAttribute_String("w:themeFill",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWShd::getThemeFill()
{
    return getAttribute_String("w:themeFill");
}
//-----------------------------------------------------------------------------------------------------------------
