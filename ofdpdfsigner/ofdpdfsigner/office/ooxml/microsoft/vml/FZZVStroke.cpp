//
//  Created by zizheng fan on 2023/04/21.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVStroke.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVStroke**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke::FZZVStroke() : FZZXMLElementObject()
{
    //DLOG("FZZVStroke()");
    FZZConst::addClassCount("FZZVStroke");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke::FZZVStroke(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVStroke");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke::FZZVStroke(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVStroke");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke::FZZVStroke(const FZZVStroke& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVStroke");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke::~FZZVStroke()
{
    //DLOG("~FZZVLine()");
    FZZConst::delClassCount("FZZVStroke");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVStroke::setOpacity(string value)
{
    setAttribute_String("opacity",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVStroke::getOpacity()
{
    return getAttribute_String("opacity");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVStroke::setJoinstyle(string value)
{
    setAttribute_String("joinstyle",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVStroke::getJoinstyle()
{
    return getAttribute_String("joinstyle");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVStroke::setRound(string value)
{
    setAttribute_String("round",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVStroke::getRound()
{
    return getAttribute_String("round");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVStroke::setColor(string value)
{
    setAttribute_String("color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVStroke::getColor()
{
    return getAttribute_String("color");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVStroke::setWeight(string value)
{
    setAttribute_String("weight",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVStroke::getWeight()
{
    return getAttribute_String("weight");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVStroke::setEndarrow(string value)
{
    setAttribute_String("endarrow",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVStroke::getEndarrow()
{
    return getAttribute_String("endarrow");
}
//-----------------------------------------------------------------------------------------------------------------
