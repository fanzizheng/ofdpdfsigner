//
//  Created by zizheng fan on 2023/10/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPgMar.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPgMar**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar::FZZWPgMar() : FZZXMLElementObject()
{
    //DLOG("FZZWPgMar()");
    FZZConst::addClassCount("FZZWPgMar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar::FZZWPgMar(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPgMar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar::FZZWPgMar(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPgMar");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar::FZZWPgMar(const FZZWPgMar& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPgMar");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar::~FZZWPgMar()
{
    //DLOG("~FZZWPgMar()");
    FZZConst::delClassCount("FZZWPgMar");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setTop(string value)
{
    setAttribute_String("w:top",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getTop()
{
    return getAttribute_String("w:top");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setRight(string value)
{
    setAttribute_String("w:right",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getRight()
{
    return getAttribute_String("w:right");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setBottom(string value)
{
    setAttribute_String("w:bottom",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getBottom()
{
    return getAttribute_String("w:bottom");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setLeft(string value)
{
    setAttribute_String("w:left",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getLeft()
{
    return getAttribute_String("w:left");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setHeader(string value)
{
    setAttribute_String("w:header",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getHeader()
{
    return getAttribute_String("w:header");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setFooter(string value)
{
    setAttribute_String("w:footer",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getFooter()
{
    return getAttribute_String("w:footer");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgMar::setGutter(string value)
{
    setAttribute_String("w:gutter",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgMar::getGutter()
{
    return getAttribute_String("w:gutter");
}
//-----------------------------------------------------------------------------------------------------------------
