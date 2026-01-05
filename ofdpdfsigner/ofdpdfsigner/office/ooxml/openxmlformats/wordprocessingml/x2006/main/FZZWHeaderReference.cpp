//
//  Created by zizheng fan on 2023/11/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWHeaderReference.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblStylePr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWHeaderReference::FZZWHeaderReference() : FZZXMLElementObject()
{
    //DLOG("FZZWHeaderReference()");
    FZZConst::addClassCount("FZZWHeaderReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHeaderReference::FZZWHeaderReference(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWHeaderReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHeaderReference::FZZWHeaderReference(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWHeaderReference");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHeaderReference::FZZWHeaderReference(const FZZWHeaderReference& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWHeaderReference");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHeaderReference::~FZZWHeaderReference()
{
    //DLOG("~FZZWHeaderReference()");
    FZZConst::delClassCount("FZZWHeaderReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWHeaderReference::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWHeaderReference::getType()
{
    string retstr = getAttribute_String("w:type");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWHeaderReference::setRID(string value)
{
    setAttribute_String("r:id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWHeaderReference::getRID()
{
    string retstr = getAttribute_String("r:id");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWHeaderReference::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWHeaderReference::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------

