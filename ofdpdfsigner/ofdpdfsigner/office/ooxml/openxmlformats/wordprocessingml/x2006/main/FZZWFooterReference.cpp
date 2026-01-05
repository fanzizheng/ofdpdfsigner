//
//  Created by zizheng fan on 2023/11/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFooterReference.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWFooterReference**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWFooterReference::FZZWFooterReference() : FZZXMLElementObject()
{
    //DLOG("FZZWFooterReference()");
    FZZConst::addClassCount("FZZWFooterReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFooterReference::FZZWFooterReference(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWFooterReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFooterReference::FZZWFooterReference(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWFooterReference");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFooterReference::FZZWFooterReference(const FZZWFooterReference& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWFooterReference");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFooterReference::~FZZWFooterReference()
{
    //DLOG("~FZZWFooterReference()");
    FZZConst::delClassCount("FZZWFooterReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFooterReference::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFooterReference::getType()
{
    string retstr = getAttribute_String("w:type");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFooterReference::setRID(string value)
{
    setAttribute_String("r:id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFooterReference::getRID()
{
    string retstr = getAttribute_String("r:id");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWB::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWB::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------

