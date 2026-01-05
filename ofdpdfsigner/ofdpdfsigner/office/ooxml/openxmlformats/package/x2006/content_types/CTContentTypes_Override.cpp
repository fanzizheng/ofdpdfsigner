//
//  Created by zizheng fan on 2023/08/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/package/x2006/content_types/CTContentTypes_Override.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************CTContentTypes_Override**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Override::CTContentTypes_Override() : FZZXMLElementObject()
{
    //DLOG("CTContentTypes_Override()");
    FZZConst::addClassCount("CTContentTypes_Override");
    
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Override::CTContentTypes_Override(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("CTContentTypes_Override");
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Override::CTContentTypes_Override(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("CTContentTypes_Override");
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Override::CTContentTypes_Override(const CTContentTypes_Override& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("CTContentTypes_Override");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Override::~CTContentTypes_Override()
{
    //DLOG("~CTContentTypes_Override()");
    FZZConst::delClassCount("CTContentTypes_Override");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//CTContentTypes_Override* CTContentTypes_Override::getInstance(XMLDocument* doc, XMLElement* ele)
//{
//    if (doc != NULL && ele != NULL) {
//        CTContentTypes_Override* temp = new CTContentTypes_Override();
//        temp->m_doc = doc;
//        temp->m_ofd_Node = ele;
//        return temp;
//    }
//    else {
//        return NULL;
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
string CTContentTypes_Override::getPartName()
{
    return getAttribute_String("PartName");
}
//-----------------------------------------------------------------------------------------------------------------
void CTContentTypes_Override::setPartName(string value)
{
    setAttribute_String("PartName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string CTContentTypes_Override::getContentType()
{
    return getAttribute_String("ContentType");
}
//-----------------------------------------------------------------------------------------------------------------
void CTContentTypes_Override::setContentType(string value)
{
    setAttribute_String("ContentType",value);
}
//-----------------------------------------------------------------------------------------------------------------
