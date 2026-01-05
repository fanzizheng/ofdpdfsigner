//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/page/FZZOFDTemplate.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTemplate**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplate::FZZOFDTemplate() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDTemplate()");
    FZZConst::addClassCount("FZZOFDTemplate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplate::FZZOFDTemplate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDTemplate");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplate::FZZOFDTemplate(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDTemplate");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplate::FZZOFDTemplate(const FZZOFDTemplate& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDTemplate");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplate::~FZZOFDTemplate()
{
    //DLOG("~FZZOFDTemplate()");
    FZZConst::delClassCount("FZZOFDTemplate");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplate::setZOrder(Type type)
{
    string value = "Body";
    
    switch (type) {
    case Type::Body:
        value = "Body";
        break;
    case Type::Background:
        value = "Background";
        break;
    case Type::Foreground:
        value = "Foreground";
        break;
    default:
        value = "Body";
        break;
    }
    setAttribute_String("ZOrder",value);
}
//-----------------------------------------------------------------------------------------------------------------
Type FZZOFDTemplate::getZOrder()
{
    string strValue = getAttribute_String("ZOrder");
    Type type = Type::Body;
    if (strValue == "Body") {
        type = Type::Body;
    }
    else if (strValue == "Background") {
        type = Type::Background;
    }
    else if (strValue == "Foreground") {
        type = Type::Foreground;
    }
    else {
        type = Type::Body;
    }
    
    return type;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplate::setTemplateID(string value)
{
    setAttribute_String("TemplateID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTemplate::getTemplateID()
{
    return getAttribute_String("TemplateID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTemplate::setTemplateID(long value)
{
    setAttribute_long("TemplateID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDTemplate::getTemplateID_long()
{
    return getAttribute_long("TemplateID");
}
//-----------------------------------------------------------------------------------------------------------------
