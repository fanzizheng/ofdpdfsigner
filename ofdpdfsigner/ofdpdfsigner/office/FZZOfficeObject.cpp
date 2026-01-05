//
//  Created by zizheng fan on 2023/04/01.
//
#include "basic/FZZConst.h"
#include "office/FZZOfficeObject.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "office/docx/FZZDocXConst.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOfficeObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOfficeObject::FZZOfficeObject() : FZZOFDObject(),m_FileName(""),m_HashValue("")
{
    //DLOG("FZZOfficeObject()");
    FZZConst::addClassCount("FZZOfficeObject");
    DefaultInitXmlnsList();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOfficeObject::FZZOfficeObject(XMLDocument * doc) : FZZOFDObject(doc),m_FileName("")
{
    FZZConst::addClassCount("FZZOfficeObject");
    DefaultInitXmlnsList();
    InitXmlnsList();
    
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
FZZOfficeObject::FZZOfficeObject(const FZZOfficeObject& obj) : FZZOFDObject(obj)
{
    FZZConst::addClassCount("FZZOfficeObject");
    if ( this == &obj ) {
        return;
    }
    this->m_doc = obj.m_doc;
    this->m_ofd_Node = obj.m_ofd_Node;
    this->m_FileName = obj.m_FileName;
    this->m_HashValue = obj.m_HashValue;
    
    copy(obj.m_XmlnsList.begin(),obj.m_XmlnsList.end(),inserter(m_XmlnsList,m_XmlnsList.begin()));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOfficeObject::~FZZOfficeObject()
{
    //DLOG("~FZZOfficeObject()");
    FZZConst::delClassCount("FZZOfficeObject");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOfficeObject::DefaultInitXmlnsList()
{
    m_XmlnsList.insert(pair<string,string>("a",OPENXMLFORMATS_DRAWINGML_2006_MAIN_VALUE));
    m_XmlnsList.insert(pair<string,string>("pic",OPENXMLFORMATS_DRAWINGML_2006_PICTURE_VALUE));
    m_XmlnsList.insert(pair<string,string>("a14",OPENXMLFORMATS_OFFICE_DRAWING_2010_MAIN_VALUE));
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOfficeObject::getCurrHash()
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
void FZZOfficeObject::InitXmlnsList()
{
    if ( m_ofd_Node == NULL ) return;
    XMLElement* xmlElement = m_ofd_Node->ToElement();
    if ( xmlElement != NULL ) {
        const XMLAttribute* attr = xmlElement->FirstAttribute();
        while( attr != NULL ) {
            string name = getXmlnsKey(attr->Name());
            string value = attr->Value();
            m_XmlnsList.insert(pair<string,string>(name,value));
            attr = attr->Next();
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOfficeObject::getXmlnsKey(const char * const name)
{
    vector<string> s;
    FZZConst::split(name, ":", s);
    if ( s.size() == 2 ) {
        return s[1];
    } else {
        return "";
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOfficeObject::findXmlnsKey(map<string,string> * XmlnsList,const char * const s1,vector<string>& keys)
{
    if ( XmlnsList == NULL ) {
        return;
    }
    map<string,string>::const_iterator itr;
    for( itr = XmlnsList->begin(); itr != XmlnsList->end(); itr++ ) {
        if ( itr->second.find(s1) != string::npos  ) {
            keys.push_back(itr->first);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
XMLElement* FZZOfficeObject::getElement(map<string,string> * XmlnsList,XMLNode* m_ofd_Node,const char * const key,const char * const subkey,string & outkey)
{
    XMLElement* ele = NULL;
    if ( m_ofd_Node == NULL ) {
        return ele;
    }
    vector<string> keys;
    findXmlnsKey(XmlnsList,key,keys);
    if ( keys.size() == 0 ) {
        return ele;
    } else {
        vector<string>::const_iterator itr;
        for( itr = keys.begin(); itr != keys.end(); itr++ ) {
            string key = *itr;
            if ( !key.empty() )
                key = key + ":" + subkey;
            else
                key = subkey;
            outkey = key;
            ele = m_ofd_Node->FirstChildElement(key.c_str());
            if (ele != NULL) {
                break;
            }
            
        }
        
    }
    keys.clear();
    return ele;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOfficeObject::setXMLElement_Value(string key,string value)
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
string FZZOfficeObject::getXMLElement_Value(string key)
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
string FZZOfficeObject::getAttribute_String(string key,string AttrKey)
{
    if (m_doc == NULL) {
        return "";
    }
    if (m_ofd_Node == NULL) {
        return "";
    }
    
    string retstr = "";

    XMLElement* element = m_ofd_Node->FirstChildElement(key.c_str());
    if (element != NULL) {
        
        const char* value;
        XMLError queryResult = element->QueryStringAttribute(AttrKey.c_str(), &value);
        if (XML_SUCCESS == queryResult) {
            retstr = value;
        }
        else {
            retstr = "";
        }
        
      
    }
    return retstr;

}
//-----------------------------------------------------------------------------------------------------------------
void FZZOfficeObject::setAttribute_String(string key,string AttrKey,string value)
{
    if (m_doc == NULL) {
        return;
    }
    if (m_ofd_Node == NULL) {
        return;
    }
    
    XMLNode* tempnode = m_ofd_Node->FirstChildElement(key.c_str());
    if (tempnode == NULL) {
        XMLElement* element = m_doc->NewElement(key.c_str());
        element->DeleteAttribute(AttrKey.c_str());
        element->SetAttribute(AttrKey.c_str(), value.c_str());
        m_ofd_Node->InsertEndChild(element);
    }
    else {
        XMLElement* element = tempnode->ToElement();
        element->DeleteAttribute(AttrKey.c_str());
        element->SetAttribute(AttrKey.c_str(), value.c_str());
    }
    
}
//-----------------------------------------------------------------------------------------------------------------

