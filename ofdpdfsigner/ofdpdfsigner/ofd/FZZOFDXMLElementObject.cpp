//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDXMLElementObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLElementObject::FZZOFDXMLElementObject() : m_doc(NULL), m_ofd_Node(NULL),m_Parent(NULL)
{
    //DLOG("FZZOFDXMLElementObject()");
    FZZConst::addClassCount("FZZOFDXMLElementObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLElementObject::FZZOFDXMLElementObject(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject()
{
    m_Parent = parent;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLElementObject::FZZOFDXMLElementObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key,bool isOnly) : FZZOFDXMLElementObject(parent)
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
FZZOFDXMLElementObject::FZZOFDXMLElementObject(const FZZOFDXMLElementObject& obj) : FZZOFDXMLElementObject()
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
FZZOFDXMLElementObject::~FZZOFDXMLElementObject()
{
    //DLOG("~FZZOFDXMLElementObject()");
    FZZConst::delClassCount("FZZOFDXMLElementObject");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDXMLElementObject::getAttribute_String(string key)
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
void FZZOFDXMLElementObject::setAttribute_String(string key,string value)
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
int FZZOFDXMLElementObject::getAttribute_Int(string key)
{
    return (int)strtol(getAttribute_String(key).c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setAttribute_Int(string key,int value)
{
    setAttribute_String(key,FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDXMLElementObject::getAttribute_long(string key)
{
    return strtol(getAttribute_String(key).c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setAttribute_long(string key,long value)
{
    setAttribute_String(key,FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDXMLElementObject::getAttribute_Bool(string key,bool defaultValue)
{
    string strret = getAttribute_String(key);
    transform(strret.begin(), strret.end(), strret.begin(), ::tolower);
    bool ret = defaultValue;
    if ( !strret.empty() ) {
        if ( strret == "true" ) {
            ret = true;
        } else {
            ret = false;
        }
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setAttribute_Bool(string key,bool value)
{
    value ? setAttribute_String(key,"true") : setAttribute_String(key,"false");
}
//-----------------------------------------------------------------------------------------------------------------
float FZZOFDXMLElementObject::getAttribute_float(string key)
{
    return strtof(getAttribute_String(key).c_str(), NULL);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setAttribute_float(string key,float value)
{
    setAttribute_String(key,FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDXMLElementObject::getAttribute_double(string key)
{
    return strtod(getAttribute_String(key).c_str(), NULL);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setAttribute_double(string key,double value)
{
    setAttribute_String(key,FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
XMLElement* FZZOFDXMLElementObject::getElement(XMLNode* m_ofd_Node,const char * const s1)
{
    if ( m_Parent == NULL ) {
        return NULL;
    }
    return m_Parent->getElement(m_ofd_Node,s1);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDXMLElementObject::getValue_String()
{
    string retstr = "";
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return retstr;
    }
    
    XMLElement* ele = m_ofd_Node->ToElement();
    if (ele != NULL) {
        const char* tempcharp = ele->GetText();
        if ( tempcharp != NULL ) {
            //retstr = xmldata_format_value(tempcharp);
            retstr = tempcharp;
        }
    }
    retstr = FZZConst::replace_all(retstr, "\n", "");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setValue_String(string value)
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
int FZZOFDXMLElementObject::getValue_Int()
{
    return (int)strtol(getValue_String().c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setValue_Int(int value)
{
    setValue_String(FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDXMLElementObject::getValue_long()
{
    return strtol(getValue_String().c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setValue_long(long value)
{
    setValue_String(FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDXMLElementObject::getValue_Bool()
{
    string strret = getValue_String();
    transform(strret.begin(), strret.end(), strret.begin(), ::tolower);
    bool ret = false;
    if ( strret == "true" ) {
        ret = true;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setValue_Bool(bool value)
{
    value ? setValue_String("true") : setValue_String("false");
}
//-----------------------------------------------------------------------------------------------------------------
float FZZOFDXMLElementObject::getValue_float()
{
    return strtof(getValue_String().c_str(),NULL);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setValue_float(float value)
{
    setValue_String(FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDXMLElementObject::getValue_double()
{
    return strtod(getValue_String().c_str(),NULL);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::setValue_double(double value)
{
    setValue_String(FZZConst::fmt(value));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::deleteElement(string key)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return;
    }
    XMLElement* ele = getElement(m_ofd_Node,key.c_str());
    if (ele != NULL) {
        m_ofd_Node->DeleteChild(ele);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLElementObject::clearElementObjectList(string s1)
{
    
    XMLElement* ele = getElement(m_ofd_Node,s1.c_str());
    
    while (ele != NULL) {
        const char* elename = ele->Name();
        XMLElement* temp_ele = ele;
        ele = ele->NextSiblingElement();
        if (strcmp(elename, s1.c_str()) == 0) {
            m_ofd_Node->DeleteChild(temp_ele);
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------

