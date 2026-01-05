//
//  Created by zizheng fan on 2023/10/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLsdException.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLsdException**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLsdException::FZZWLsdException() : FZZXMLElementObject()
{
    //DLOG("FZZWLsdException()");
    FZZConst::addClassCount("FZZWLsdException");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLsdException::FZZWLsdException(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLsdException");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLsdException::FZZWLsdException(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLsdException");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLsdException::FZZWLsdException(const FZZWLsdException& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLsdException");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLsdException::~FZZWLsdException()
{
    //DLOG("~FZZWLsdException()");
    FZZConst::delClassCount("FZZWLsdException");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLsdException::setName(string value)
{
    setAttribute_String("w:name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLsdException::getName()
{
    return getAttribute_String("w:name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLsdException::setUiPriority(string value)
{
    setAttribute_String("w:uiPriority",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLsdException::getUiPriority()
{
    return getAttribute_String("w:uiPriority");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLsdException::setQFormat(string value)
{
    setAttribute_String("w:qFormat",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLsdException::getQFormat()
{
    return getAttribute_String("w:qFormat");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLsdException::setSemiHidden(string value)
{
    setAttribute_String("w:semiHidden",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLsdException::getSemiHidden()
{
    return getAttribute_String("w:semiHidden");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLsdException::setUnhideWhenUsed(string value)
{
    setAttribute_String("w:unhideWhenUsed",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLsdException::getUnhideWhenUsed()
{
    return getAttribute_String("w:unhideWhenUsed");
}
//-----------------------------------------------------------------------------------------------------------------
