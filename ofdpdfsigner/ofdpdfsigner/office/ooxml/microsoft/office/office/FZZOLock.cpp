//
//  Created by zizheng fan on 2023/04/24.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOLock**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOLock::FZZOLock() : FZZXMLElementObject()
{
    //DLOG("FZZOLock()");
    FZZConst::addClassCount("FZZOLock");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock::FZZOLock(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZOLock");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock::FZZOLock(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOLock");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock::FZZOLock(const FZZOLock& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZOLock");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock::~FZZOLock()
{
    //DLOG("~FZZOLock()");
    FZZConst::delClassCount("FZZOLock");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setExt(string value)
{
    setAttribute_String("v:ext",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getExt()
{
    return getAttribute_String("v:ext");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setAspectratio(string value)
{
    setAttribute_String("aspectratio",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getAspectratio()
{
    return getAttribute_String("aspectratio");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setPosition(string value)
{
    setAttribute_String("position",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getPosition()
{
    return getAttribute_String("position");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setSelection(string value)
{
    setAttribute_String("selection",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getSelection()
{
    return getAttribute_String("selection");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setGrouping(string value)
{
    setAttribute_String("grouping",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getGrouping()
{
    return getAttribute_String("grouping");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setRotation(string value)
{
    setAttribute_String("rotation",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getRotation()
{
    return getAttribute_String("rotation");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setCropping(string value)
{
    setAttribute_String("cropping",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getCropping()
{
    return getAttribute_String("cropping");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOLock::setText(string value)
{
    setAttribute_String("text",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOLock::getText()
{
    return getAttribute_String("text");
}
//-----------------------------------------------------------------------------------------------------------------
