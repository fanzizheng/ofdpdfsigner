//
//  Created by zizheng fan on 2023/04/01.
//
#include "basic/FZZConst.h"
#include "office/FZZXMLElementObject.h"
#include "office/FZZOfficeObject.h"
#include "office/docx/FZZDocXConst.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZXMLElementObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZXMLElementObject::FZZXMLElementObject() : m_doc(NULL), m_ofd_Node(NULL),m_Parent(NULL)
{
    //DLOG("FZZXMLElementObject()");
    FZZConst::addClassCount("FZZXMLElementObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZXMLElementObject::FZZXMLElementObject(FZZOfficeObject * parent) : FZZXMLElementObject()
{
    m_Parent = parent;
}
//-----------------------------------------------------------------------------------------------------------------
FZZXMLElementObject::FZZXMLElementObject(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key,bool isOnly) : FZZXMLElementObject(parent)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    m_doc = doc;
    if (m_doc != NULL) {
        if ( isOnly ) {
            m_ofd_Node = node->FirstChildElement(key.c_str());
            if (m_ofd_Node == NULL) {
                XMLElement* element = m_doc->NewElement(key.c_str());
                m_ofd_Node = node->InsertEndChild(element);
            }
        } else {
            XMLElement* element = m_doc->NewElement(key.c_str());
            m_ofd_Node = node->InsertEndChild(element);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZXMLElementObject::FZZXMLElementObject(const FZZXMLElementObject& obj) : FZZXMLElementObject()
{
    //DLOG("CT_Action(const CT_Action& obj)");
    if ( this == &obj ) {
        return;
    }
    m_doc = obj.m_doc;
    m_ofd_Node = obj.m_ofd_Node;
    m_Parent = obj.m_Parent;
}
//-----------------------------------------------------------------------------------------------------------------
FZZXMLElementObject::~FZZXMLElementObject()
{
    //DLOG("~FZZXMLElementObject()");
    FZZConst::delClassCount("FZZXMLElementObject");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZXMLElementObject::getAttribute_String(string key)
{
    if (m_doc == NULL) {
        return "";
    }
    if (m_ofd_Node == NULL) {
        return "";
    }

    XMLElement* element = m_ofd_Node->ToElement();
    const char* value;
    XMLError queryResult = element->QueryStringAttribute(key.c_str(), &value);
    if (XML_SUCCESS == queryResult) {
        return value == NULL ? "" : value;
    }
    else {
        return "";
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZXMLElementObject::setAttribute_String(string key,string value)
{
    if (m_doc == NULL) {
        return;
    }
    if (m_ofd_Node == NULL) {
        return;
    }
    
    XMLElement* element = m_ofd_Node->ToElement();
    element->DeleteAttribute(key.c_str());
    element->SetAttribute(key.c_str(), value.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
map<string,string>* FZZXMLElementObject::getXmlnsList()
{
    if ( m_Parent == NULL ) {
        return NULL;
    }
    return m_Parent->getXmlnsList();
}
//-----------------------------------------------------------------------------------------------------------------
XMLElement* FZZXMLElementObject::getElement(map<string,string> * XmlnsList,XMLNode* m_ofd_Node,const char * const s1,const char * const subkey,string & outkey)
{
    if ( m_Parent == NULL ) {
        return NULL;
    }
    return m_Parent->getElement(XmlnsList,m_ofd_Node,s1,subkey,outkey);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZXMLElementObject::getValue_String()
{
    string retstr = "";
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return retstr;
    }
    
    XMLElement* ele = m_ofd_Node->ToElement();
    if (ele != NULL) {
        const char* tempcharp = ele->GetText();
        if ( tempcharp != NULL ) {
            retstr = xmldata_format_value(tempcharp);
        }
    }
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZXMLElementObject::setValue_String(string value)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return;
    }

    if (value.empty()) {
        return;
    }
    
    XMLElement* ele = m_ofd_Node->ToElement();
    if (ele != NULL) {
        ele->SetText(value.c_str());
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
