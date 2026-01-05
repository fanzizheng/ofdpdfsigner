//
//  Created by zizheng fan on 2023/11/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFramePr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWFramePr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr::FZZWFramePr() : FZZXMLElementObject()
{
    //DLOG("FZZWFramePr()");
    FZZConst::addClassCount("FZZWFramePr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr::FZZWFramePr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWFramePr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr::FZZWFramePr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWFramePr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr::FZZWFramePr(const FZZWFramePr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWFramePr");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr::~FZZWFramePr()
{
    //DLOG("~FZZWFramePr()");
    FZZConst::delClassCount("FZZWFramePr");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setWrap(string value)
{
    setAttribute_String("w:wrap",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getWrap()
{
    string retstr = getAttribute_String("w:wrap");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setVAnchor(string value)
{
    setAttribute_String("w:vAnchor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getVAnchor()
{
    string retstr = getAttribute_String("w:vAnchor");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setHAnchor(string value)
{
    setAttribute_String("w:hAnchor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getHAnchor()
{
    string retstr = getAttribute_String("w:hAnchor");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setX(string value)
{
    setAttribute_String("w:x",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getX()
{
    string retstr = getAttribute_String("w:x");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setY(string value)
{
    setAttribute_String("w:y",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getY()
{
    string retstr = getAttribute_String("w:y");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setXAlign(string value)
{
    setAttribute_String("w:xAlign",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getXAlign()
{
    string retstr = getAttribute_String("w:xAlign");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFramePr::setYAlign(string value)
{
    setAttribute_String("w:yAlign",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFramePr::getYAlign()
{
    string retstr = getAttribute_String("w:yAlign");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
