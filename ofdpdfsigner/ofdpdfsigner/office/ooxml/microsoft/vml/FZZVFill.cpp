//
//  Created by zizheng fan on 2024/02/07.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVFill.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVFill**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVFill::FZZVFill() : FZZXMLElementObject()
{
    //DLOG("FZZVFill()");
    FZZConst::addClassCount("FZZVFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill::FZZVFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill::FZZVFill(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVFill");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill::FZZVFill(const FZZVFill& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVFill");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill::~FZZVFill()
{
    //DLOG("~FZZVFill()");
    FZZConst::delClassCount("FZZVFill");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVFill::setOn(string value)
{
    setAttribute_String("on",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVFill::getOn()
{
    return getAttribute_String("on");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVFill::setColor2(string value)
{
    setAttribute_String("color2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVFill::getColor2()
{
    return getAttribute_String("color2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVFill::setFocus(string value)
{
    setAttribute_String("focus",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVFill::getFocus()
{
    return getAttribute_String("focus");
}
//-----------------------------------------------------------------------------------------------------------------

