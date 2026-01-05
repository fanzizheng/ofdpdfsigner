//
//  Created by zizheng fan on 2023/06/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGd.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAGd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAGd::FZZAGd() : FZZXMLElementObject()
{
    //DLOG("FZZAGd()");
    FZZConst::addClassCount("FZZAGd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGd::FZZAGd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAGd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGd::FZZAGd(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAGd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGd::FZZAGd(const FZZAGd& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAGd");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGd::~FZZAGd()
{
    //DLOG("~FZZAGd()");
    FZZConst::delClassCount("FZZAGd");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAGd::setName(string value)
{
    setAttribute_String("name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAGd::getName()
{
    return getAttribute_String("name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAGd::setFmla(string value)
{
    setAttribute_String("fmla",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAGd::getFmla()
{
    return getAttribute_String("fmla");
}
//-----------------------------------------------------------------------------------------------------------------
