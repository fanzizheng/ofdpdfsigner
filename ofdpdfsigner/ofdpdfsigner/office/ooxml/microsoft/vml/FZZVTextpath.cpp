//
//  Created by zizheng fan on 2024/02/02.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVTextpath.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVTextpath**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath::FZZVTextpath() : FZZXMLElementObject()
{
    //DLOG("FZZVTextpath()");
    FZZConst::addClassCount("FZZVTextpath");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath::FZZVTextpath(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVTextpath");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath::FZZVTextpath(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVTextpath");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath::FZZVTextpath(const FZZVTextpath& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVTextpath");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath::~FZZVTextpath()
{
    //DLOG("~FZZVTextpath()");
    FZZConst::delClassCount("FZZVTextpath");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setStyle(string value)
{
    setAttribute_String("style",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getStyle()
{
    return getAttribute_String("style");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setOn(string value)
{
    setAttribute_String("on",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getOn()
{
    return getAttribute_String("on");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setFitshape(string value)
{
    setAttribute_String("fitshape",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getFitshape()
{
    return getAttribute_String("fitshape");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setFitpath(string value)
{
    setAttribute_String("fitpath",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getFitpath()
{
    return getAttribute_String("fitpath");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setTrim(string value)
{
    setAttribute_String("trim",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getTrim()
{
    return getAttribute_String("trim");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setXscale(string value)
{
    setAttribute_String("xscale",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getXscale()
{
    return getAttribute_String("xscale");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextpath::setString(string value)
{
    setAttribute_String("string",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextpath::getString()
{
    return getAttribute_String("string");
}
//-----------------------------------------------------------------------------------------------------------------
