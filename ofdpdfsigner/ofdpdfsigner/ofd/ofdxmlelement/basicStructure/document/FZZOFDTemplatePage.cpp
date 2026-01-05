//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDTemplatePage.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTemplatePage**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplatePage::FZZOFDTemplatePage() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDTemplatePage()");
    FZZConst::addClassCount("FZZOFDTemplatePage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplatePage::FZZOFDTemplatePage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDTemplatePage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplatePage::FZZOFDTemplatePage(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDTemplatePage");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplatePage::FZZOFDTemplatePage(const FZZOFDTemplatePage& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDTemplatePage");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplatePage::~FZZOFDTemplatePage()
{
    //DLOG("~FZZOFDTemplatePage()");
    FZZConst::delClassCount("FZZOFDTemplatePage");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplatePage::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTemplatePage::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplatePage::setID(long value)
{
    
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDTemplatePage::getID_long()
{
    return getAttribute_long("ID");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplatePage::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTemplatePage::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplatePage::setBaseLoc(string value)
{
    setAttribute_String("BaseLoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTemplatePage::getBaseLoc()
{
    return getAttribute_String("BaseLoc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplatePage::setZOrder(Type value)
{
    string strvalue = "Background";

    switch (value) {
    case Type::Body:
        strvalue = "Body";
        break;
    case Type::Background:
        strvalue = "Background";
        break;
    case Type::Foreground:
        strvalue = "Foreground";
        break;
    default:
        strvalue = "Background";
        break;
    }
    setAttribute_String("ZOrder",strvalue);
}
//-----------------------------------------------------------------------------------------------------------------
Type FZZOFDTemplatePage::getZOrder()
{
    string value = getAttribute_String("ZOrder");
    Type typeret = Type::Background;
    if (value == "Body") {
        typeret = Type::Body;
    }
    else if (value == "Background") {
        typeret = Type::Background;
    }
    else if (value == "Foreground") {
        typeret = Type::Foreground;
    }
    else {
        typeret = Type::Background;
    }
    return typeret;
}
//-----------------------------------------------------------------------------------------------------------------
