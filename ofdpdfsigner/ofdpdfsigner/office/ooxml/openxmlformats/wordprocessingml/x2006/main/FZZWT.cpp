//
//  Created by zizheng fan on 2023/10/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWT.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWT**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWT::FZZWT() : FZZXMLElementObject()
{
    //DLOG("FZZWT()");
    FZZConst::addClassCount("FZZWT");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWT::FZZWT(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWT");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWT::FZZWT(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWT");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWT::FZZWT(const FZZWT& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWT");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWT::~FZZWT()
{
    //DLOG("~FZZWT()");
    FZZConst::delClassCount("FZZWT");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWT::setSpace(string value)
{
    setAttribute_String("xml:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWT::getSpace()
{
    return getAttribute_String("xml:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWT::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWT::getValue()
{
    string ret = getValue_String();
    return ret == "" ? " " : ret ;
}
//-----------------------------------------------------------------------------------------------------------------
