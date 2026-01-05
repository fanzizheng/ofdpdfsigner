//
//  Created by zizheng fan on 2023/08/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/package/x2006/content_types/CTContentTypes_Default.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************CTContentTypes_Default**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Default::CTContentTypes_Default() : FZZXMLElementObject()
{
    //DLOG("CTContentTypes_Default()");
    FZZConst::addClassCount("CTContentTypes_Default");
    
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Default::CTContentTypes_Default(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("CTContentTypes_Default");
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Default::CTContentTypes_Default(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("CTContentTypes_Default");
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Default::CTContentTypes_Default(const CTContentTypes_Default& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("CTContentTypes_Default");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Default::~CTContentTypes_Default()
{
    //DLOG("~CTContentTypes_Default()");
    FZZConst::delClassCount("CTContentTypes_Default");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//CTContentTypes_Default* CTContentTypes_Default::getInstance(XMLDocument* doc, XMLElement* ele)
//{
//    if (doc != NULL && ele != NULL) {
//        CTContentTypes_Default* temp = new CTContentTypes_Default();
//        temp->m_doc = doc;
//        temp->m_ofd_Node = ele;
//        return temp;
//    }
//    else {
//        return NULL;
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
string CTContentTypes_Default::getExtension()
{
    return getAttribute_String("Extension");
}
//-----------------------------------------------------------------------------------------------------------------
void CTContentTypes_Default::setExtension(string value)
{
    setAttribute_String("Extension",value);
}
//-----------------------------------------------------------------------------------------------------------------
string CTContentTypes_Default::getContentType()
{
    return getAttribute_String("ContentType");
}
//-----------------------------------------------------------------------------------------------------------------
void CTContentTypes_Default::setContentType(string value)
{
    setAttribute_String("ContentType",value);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
