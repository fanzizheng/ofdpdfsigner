//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDXMLFILEOBJECT_H
#define FZZOFDXMLFILEOBJECT_H


#include "ofd/FZZOFDObject.h"
#include "ofd/FZZOFDXMLElementObject.h"


class FZZOFDXMLFileObject : public FZZOFDObject
{
public:
    FZZOFDXMLFileObject(XMLDocument * doc);
    FZZOFDXMLFileObject(const FZZOFDXMLFileObject& obj);
    virtual ~FZZOFDXMLFileObject();
public:
    
    XMLElement* getElement(XMLNode* m_ofd_Node,const char * const key);
    
    void setFileName(string filename) { m_FileName = filename; }
    string getFileName() { return m_FileName; }
    string getHash() { return m_HashValue; }
    string getCurrHash();
    
protected:
    FZZOFDXMLFileObject();
    
    void setXMLElement_Value(string key,string value);
    string getXMLElement_Value(string key);
    
    string getAttribute_String(string key);
    void setAttribute_String(string key,string value);
    
    template <typename T>
    T* setElementObject(T* elementObject,const char * const s1);
    
    template <typename T>
    T* getElementObject(T* elementObject,const char * const s1);
    
    template <typename T>
    T* addElementObject(vector<T*>* list,const char * const s1);
    
    template <typename T>
    T* addElementObject_NoAddList(T* elementObject,const char * const s1);
    
    template <typename T>
    void getElementObjectList(vector<T*>* list ,const char * const s1);

protected:
    
    string m_FileName;
    string m_HashValue;
    
    
    
private:
    
 
    
};


template<typename T>
inline T* FZZOFDXMLFileObject::setElementObject(T* elementObject,const char * const s1)
{
    
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    
    if ( elementObject == NULL ) {
        XMLElement* ele = getElement(m_ofd_Node,s1);
        if (ele == NULL) {
            elementObject = new T(this,m_doc, m_ofd_Node,s1);
        }
        else {
            elementObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,elementObject);
        }

    }

    return (T*)elementObject;
    
}

template<typename T>
inline T* FZZOFDXMLFileObject::getElementObject(T* elementObject,const char * const s1)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }

    if (elementObject == NULL) {

        XMLElement* ele = getElement(m_ofd_Node,s1);
        if (ele != NULL) {
            elementObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,elementObject);
        }
        else {
            elementObject = NULL;
        }
    }
    return (T*)elementObject;
}


template <typename T>
inline T* FZZOFDXMLFileObject::addElementObject(vector<T*>* list,const char * const s1)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    if ( list->size() == 0 ) {
        getElementObjectList(list,s1);
    }
    

    //getElement(m_ofd_Node,s1);
    T* tempObject = new T(this,m_doc, m_ofd_Node,s1);
    if ( tempObject != NULL ) {
        list->push_back(tempObject);
    }
    return (T*)tempObject;
}

template <typename T>
inline T* FZZOFDXMLFileObject::addElementObject_NoAddList(T* elementObject,const char * const s1)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    T* tempObject = new T(this,m_doc, m_ofd_Node,s1);
    return (T*)tempObject;
}

template <typename T>
inline void FZZOFDXMLFileObject::getElementObjectList(vector<T*>* list ,const char * const s1)
{
    if ( list->size() == 0 ) {

        XMLElement* ele = getElement(m_ofd_Node,s1);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, s1) == 0) {
                T * temp = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,(T*)NULL);
                if ( temp != NULL ) {
                    list->push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
}

#endif //FZZOFDXMLFILEOBJECT_H
