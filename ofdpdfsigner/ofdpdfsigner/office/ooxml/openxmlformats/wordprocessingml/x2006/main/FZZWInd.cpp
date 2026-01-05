//
//  Created by zizheng fan on 2023/11/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInd.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWInd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWInd::FZZWInd() : FZZXMLElementObject()
{
    //DLOG("FZZWInd()");
    FZZConst::addClassCount("FZZWInd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInd::FZZWInd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWInd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInd::FZZWInd(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWInd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInd::FZZWInd(const FZZWInd& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWInd");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInd::~FZZWInd()
{
    //DLOG("~FZZWInd()");
    FZZConst::delClassCount("FZZWInd");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setFirstLineChars(string value)
{
    setAttribute_String("w:firstLineChars",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getFirstLineChars()
{
    return getAttribute_String("w:firstLineChars");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setFirstLine(string value)
{
    setAttribute_String("w:firstLine",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getFirstLine()
{
    return getAttribute_String("w:firstLine");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setRight(string value)
{
    setAttribute_String("w:right",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getRight()
{
    return getAttribute_String("w:right");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setLeft(string value)
{
    setAttribute_String("w:left",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getLeft()
{
    return getAttribute_String("w:left");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setHanging(string value)
{
    setAttribute_String("w:hanging",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getHanging()
{
    return getAttribute_String("w:hanging");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setHangingChars(string value)
{
    setAttribute_String("w:hangingChars",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getHangingChars()
{
    return getAttribute_String("w:hangingChars");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInd::setLeftChars(string value)
{
    setAttribute_String("w:leftChars",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInd::getLeftChars()
{
    return getAttribute_String("w:leftChars");
}
//-----------------------------------------------------------------------------------------------------------------
