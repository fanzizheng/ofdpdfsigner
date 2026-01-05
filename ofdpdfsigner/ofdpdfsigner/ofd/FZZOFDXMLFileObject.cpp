//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "ofd/FZZOFDXMLElementObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDXMLFileObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLFileObject::FZZOFDXMLFileObject() : FZZOFDObject(),m_FileName(""),m_HashValue("")
{
    //DLOG("FZZOFDXMLFileObject()");
    FZZConst::addClassCount("FZZOFDXMLFileObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLFileObject::FZZOFDXMLFileObject(XMLDocument * doc) : FZZOFDObject(doc),m_FileName("")
{
    FZZConst::addClassCount("FZZOFDXMLFileObject");

    string xmldata = getXMLData();
    FZZBytes filedata;
    filedata.setData((unsigned char *)xmldata.c_str(),xmldata.length());
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    gmCrypto.Digest("SM3", filedata, hashData);
    if ( hashData.getLen() < 8 ) {
        m_HashValue = "";
    }
    m_HashValue = FZZConst::Base64Encode(hashData.getData(),hashData.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLFileObject::FZZOFDXMLFileObject(const FZZOFDXMLFileObject& obj) : FZZOFDObject(obj)
{
    FZZConst::addClassCount("FZZOFDXMLFileObject");
    if ( this == &obj ) {
        return;
    }
    this->m_doc = obj.m_doc;
    this->m_ofd_Node = obj.m_ofd_Node;
    this->m_FileName = obj.m_FileName;
    this->m_HashValue = obj.m_HashValue;
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXMLFileObject::~FZZOFDXMLFileObject()
{
    //DLOG("~FZZOFDXMLFileObject()");
    FZZConst::delClassCount("FZZOFDXMLFileObject");
    
    
}
//-----------------------------------------------------------------------------------------------------------------

string FZZOFDXMLFileObject::getCurrHash()
{
    string retstr = "";
    string xmldata = getXMLData();
    FZZBytes filedata;
    filedata.setData((unsigned char *)xmldata.c_str(),xmldata.length());
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    gmCrypto.Digest("SM3", filedata, hashData);
    if ( hashData.getLen() < 8 ) {
        retstr = "";
    }
    retstr = FZZConst::Base64Encode(hashData.getData(),hashData.getLen());
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

XMLElement* FZZOFDXMLFileObject::getElement(XMLNode* m_ofd_Node,const char * const key)
{
    XMLElement* ele = NULL;
    if ( m_ofd_Node == NULL ) {
        return ele;
    }
    
    ele = m_ofd_Node->FirstChildElement(key);
    return ele;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXMLFileObject::setXMLElement_Value(string key,string value)
{
    if (m_doc == NULL || m_ofd_Node == NULL) {
        return;
    }

    XMLNode* tempnode = m_ofd_Node->FirstChildElement(key.c_str());
    if (tempnode == NULL) {
        XMLElement* element = m_doc->NewElement(key.c_str());
        element->SetText(value.c_str());
        m_ofd_Node->InsertEndChild(element);
    }
    else {
        tempnode->ToElement()->SetText(value.c_str());
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDXMLFileObject::getXMLElement_Value(string key)
{
    if (m_doc == NULL) {
        return NULL;
    }
    if (m_ofd_Node == NULL) {
        return NULL;
    }
    
    string retstr = "";

    XMLElement* ele = m_ofd_Node->FirstChildElement(key.c_str());
    if (ele != NULL) {
        const char* tempcharp = ele->GetText();
        if ( tempcharp != NULL ) {
            retstr = tempcharp;
        }
    }
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDXMLFileObject::getAttribute_String(string key)
{
//    if (m_doc == NULL) {
//        return "";
//    }
//    if (m_ofd_Node == NULL) {
//        return "";
//    }
//    
//    string retstr = "";
//
//    XMLElement* element = m_ofd_Node->FirstChildElement(key.c_str());
//    if (element != NULL) {
//        
//        const char* value;
//        XMLError queryResult = element->QueryStringAttribute(AttrKey.c_str(), &value);
//        if (XML_SUCCESS == queryResult) {
//            retstr = value;
//        }
//        else {
//            retstr = "";
//        }
//        
//      
//    }
//    return retstr;
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
void FZZOFDXMLFileObject::setAttribute_String(string key,string value)
{
//    if (m_doc == NULL) {
//        return;
//    }
//    if (m_ofd_Node == NULL) {
//        return;
//    }
//
//    XMLNode* tempnode = m_ofd_Node->FirstChildElement(key.c_str());
//    if (tempnode == NULL) {
//        XMLElement* element = m_doc->NewElement(key.c_str());
//        element->DeleteAttribute(AttrKey.c_str());
//        element->SetAttribute(AttrKey.c_str(), value.c_str());
//        m_ofd_Node->InsertEndChild(element);
//    }
//    else {
//        XMLElement* element = tempnode->ToElement();
//        element->DeleteAttribute(AttrKey.c_str());
//        element->SetAttribute(AttrKey.c_str(), value.c_str());
//    }
    
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

