//
//  Created by zizheng fan on 2023/11/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblpPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblpPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr::FZZWTblpPr() : FZZXMLElementObject()
{
    //DLOG("FZZWTblpPr()");
    FZZConst::addClassCount("FZZWTblpPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr::FZZWTblpPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblpPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr::FZZWTblpPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblpPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr::FZZWTblpPr(const FZZWTblpPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblpPr");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr::~FZZWTblpPr()
{
    //DLOG("~FZZWTblpPr()");
    FZZConst::delClassCount("FZZWTblpPr");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setVertAnchor(string value)
{
    setAttribute_String("w:vertAnchor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getVertAnchor()
{
    string retstr = getAttribute_String("w:vertAnchor");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setHorzAnchor(string value)
{
    setAttribute_String("w:horzAnchor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getHorzAnchor()
{
    string retstr = getAttribute_String("w:horzAnchor");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setTblpY(string value)
{
    setAttribute_String("w:tblpY",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getTblpY()
{
    string retstr = getAttribute_String("w:tblpY");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setTblpX(string value)
{
    setAttribute_String("w:tblpX",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getTblpX()
{
    string retstr = getAttribute_String("w:tblpX");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setLeftFromText(string value)
{
    setAttribute_String("w:leftFromText",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getLeftFromText()
{
    string retstr = getAttribute_String("w:leftFromText");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setRightFromText(string value)
{
    setAttribute_String("w:rightFromText",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getRightFromText()
{
    string retstr = getAttribute_String("w:rightFromText");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setTopFromText(string value)
{
    setAttribute_String("w:topFromText",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getTopFromText()
{
    string retstr = getAttribute_String("w:topFromText");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblpPr::setBottomFromText(string value)
{
    setAttribute_String("w:bottomFromText",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblpPr::getBottomFromText()
{
    string retstr = getAttribute_String("w:bottomFromText");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWTblpPr::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWTblpPr::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
