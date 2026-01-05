//
//  Created by zizheng fan on 2023/08/29
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/package/x2006/FZZRelationship.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZRelationship**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship::FZZRelationship() : FZZXMLElementObject()
{
    //DLOG("FZZRelationship()");
    FZZConst::addClassCount("FZZRelationship");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship::FZZRelationship(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZRelationship");
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship::FZZRelationship(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZRelationship");
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship::FZZRelationship(const FZZRelationship& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const FZZRelationship& obj)");
    FZZConst::addClassCount("FZZRelationship");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship::~FZZRelationship()
{
    //DLOG("~FZZRelationship()");
    FZZConst::delClassCount("FZZRelationship");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//FZZRelationship* FZZRelationship::getInstance(XMLDocument* doc, XMLElement* ele)
//{
//    if (doc != NULL && ele != NULL) {
//        FZZRelationship* temp = new FZZRelationship();
//        temp->m_doc = doc;
//        temp->m_ofd_Node = ele;
//        return temp;
//    }
//    else {
//        return NULL;
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
string FZZRelationship::getId()
{
    return getAttribute_String("Id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZRelationship::setId(string value)
{
    setAttribute_String("Id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZRelationship::getType()
{
    return getAttribute_String("Type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZRelationship::setType(string value)
{
    setAttribute_String("Type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZRelationship::getTarget()
{
    return getAttribute_String("Target");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZRelationship::setTarget(string value)
{
    setAttribute_String("Target",value);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
