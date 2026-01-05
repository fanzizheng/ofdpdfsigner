//
//  Created by zizheng fan on 2023/04/01.
//
#ifndef FZZOFFICEOBJECT_H
#define FZZOFFICEOBJECT_H


#include "ofd/FZZOFDObject.h"
#include "office/FZZXMLElementObject.h"
//#include "office/docx/container/FZZDocXDir.h"


class FZZOfficeObject : public FZZOFDObject
{
public:
    FZZOfficeObject(XMLDocument * doc);
    FZZOfficeObject(const FZZOfficeObject& obj);
    virtual ~FZZOfficeObject();
public:
    string getXmlnsKey(const char * const name);
    void findXmlnsKey(map<string,string> * XmlnsList,const char * const s1,vector<string>& keys);
    XMLElement* getElement(map<string,string> * XmlnsList,XMLNode* m_ofd_Node,const char * const key,const char * const subkey,string & outkey);
    
    void setFileName(string filename) { m_FileName = filename; }
    string getFileName() { return m_FileName; }
    string getHash() { return m_HashValue; }
    string getCurrHash();
    
    map<string,string>* getXmlnsList() { return &m_XmlnsList;}
    
protected:
    FZZOfficeObject();
    void DefaultInitXmlnsList();
    void InitXmlnsList();
//    string getXmlnsKey(string name);
//    void findXmlnsKey(string s1,string s2,vector<string>& keys);
//    XMLElement* getElement(string s1,string s2,string subkey,string & outkey);
    
    void setXMLElement_Value(string key,string value);
    string getXMLElement_Value(string key);
    
    string getAttribute_String(string key,string AttrKey);
    void setAttribute_String(string key,string AttrKey,string value);
    
    template <typename T>
    T* setElementObject(T* elementObject,const char * const s1,const char * const subkey);
    
    template <typename T>
    T* getElementObject(T* elementObject,const char * const s1,const char * const subkey);
    
    template <typename T>
    T* addElementObject(vector<T*>* list,const char * const s1,const char * const subkey);
    
    template <typename T>
    void getElementObjectList(vector<T*>* list ,const char * const s1,const char * const subkey);

protected:
    
    string m_FileName;
    string m_HashValue;
    map<string,string> m_XmlnsList;
    
    
private:
    
 
    
};


template<typename T>
inline T* FZZOfficeObject::setElementObject(T* elementObject,const char * const s1,const char * const subkey)
{
    
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    
    if ( elementObject == NULL ) {
        string key;
        XMLElement* ele = getElement(&m_XmlnsList,m_ofd_Node,s1,subkey,key);
        if (ele == NULL) {
            elementObject = new T(this,m_doc, m_ofd_Node,key);
        }
        else {
            elementObject = FZZXMLElementObject::getInstance(this,m_doc, ele,elementObject);
        }

    }

    return (T*)elementObject;
    
}

template<typename T>
inline T* FZZOfficeObject::getElementObject(T* elementObject,const char * const s1,const char * const subkey)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }

    if (elementObject == NULL) {
        string key;
        XMLElement* ele = getElement(&m_XmlnsList,m_ofd_Node,s1,subkey,key);
        if (ele != NULL) {
            elementObject = FZZXMLElementObject::getInstance(this,m_doc, ele,elementObject);
        }
        else {
            elementObject = NULL;
        }
    }
    return (T*)elementObject;
}


template <typename T>
inline T* FZZOfficeObject::addElementObject(vector<T*>* list,const char * const s1,const char * const subkey)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    if ( list->size() == 0 ) {
        getElementObjectList(list,s1,subkey);
    }
    
    string key;
    getElement(getXmlnsList(),m_ofd_Node,s1,subkey,key);
    T* tempObject = new T(this,m_doc, m_ofd_Node,key);
    if ( tempObject != NULL ) {
        list->push_back(tempObject);
    }
    return (T*)tempObject;
}

template <typename T>
inline void FZZOfficeObject::getElementObjectList(vector<T*>* list ,const char * const s1,const char * const subkey)
{
    if ( list->size() == 0 ) {
        string key;
        XMLElement* ele = getElement(getXmlnsList(),m_ofd_Node,s1,subkey,key);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, key.c_str()) == 0) {
                T * temp = FZZXMLElementObject::getInstance(this,m_doc, ele,(T*)NULL);
                if ( temp != NULL ) {
                    list->push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
}

#endif //FZZOFFICEOBJECT_H
