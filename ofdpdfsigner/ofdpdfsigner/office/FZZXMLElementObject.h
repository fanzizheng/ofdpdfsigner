//
//  Created by zizheng fan on 2023/04/01.
//
#ifndef FZZXMLELEMENTOBJECT_H
#define FZZXMLELEMENTOBJECT_H

class FZZOfficeObject;

class FZZXMLElementObject
{
public:
    FZZXMLElementObject(FZZOfficeObject * parent);
    FZZXMLElementObject(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key,bool isOnly);
    FZZXMLElementObject(const FZZXMLElementObject& obj);
    virtual ~FZZXMLElementObject();
    template <typename T>
    static T* getInstance(FZZOfficeObject * parent,XMLDocument* doc, XMLElement* ele,T* type);
public:
    
protected:
    FZZXMLElementObject();
    
    string getAttribute_String(string key);
    void setAttribute_String(string key,string value);
    
    string getValue_String();
    void setValue_String(string value);
    
    map<string,string>* getXmlnsList();
    XMLElement* getElement(map<string,string> * XmlnsList,XMLNode* m_ofd_Node,const char * const s1,const char * const subkey,string & outkey);
    
    template <typename T>
    T* setElementObject(T* elementObject,const char * const s1,const char * const subkey);

    template <typename T>
    T* getElementObject(T* elementObject,const char * const s1,const char * const subkey);
    
    template <typename T>
    T* addElementObject(vector<T*>* list,const char * const s1,const char * const subkey);
    
    template <typename T>
    void getElementObjectList(vector<T*>* list ,const char * const s1,const char * const subkey);

    //FZZXMLElementObject*
protected:
    XMLDocument* m_doc;
    XMLNode* m_ofd_Node;
    FZZOfficeObject * m_Parent;
    
    
};

template<typename T>
inline T* FZZXMLElementObject::getInstance(FZZOfficeObject * parent,XMLDocument* doc, XMLElement* ele,T* type)
{
    if (doc != NULL && ele != NULL) {
        T* temp = new T(parent);
        temp->m_doc = doc;
        temp->m_ofd_Node = ele;
        return temp;
    }
    else {
        return NULL;
    }
}

template <typename T>
inline T* FZZXMLElementObject::addElementObject(vector<T*>* list,const char * const s1,const char * const subkey)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    if ( list->size() == 0 ) {
        getElementObjectList(list,s1,subkey);
    }
    
    string key;
    getElement(getXmlnsList(),m_ofd_Node,s1,subkey,key);
    T* tempObject = new T(m_Parent,m_doc, m_ofd_Node,key);
    if ( tempObject != NULL ) {
        list->push_back(tempObject);
    }
    return (T*)tempObject;
}

template <typename T>
inline void FZZXMLElementObject::getElementObjectList(vector<T*>* list ,const char * const s1,const char * const subkey)
{
    if ( list->size() == 0 ) {
        string key;
        XMLElement* ele = getElement(getXmlnsList(),m_ofd_Node,s1,subkey,key);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, key.c_str()) == 0) {
                T * temp = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,(T*)NULL);
                if ( temp != NULL ) {
                    list->push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
}

template<typename T>
inline T* FZZXMLElementObject::setElementObject(T* elementObject,const char * const s1,const char * const subkey)
{
    
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    
    if ( elementObject == NULL ) {
        string key;
        XMLElement* ele = getElement(getXmlnsList(),m_ofd_Node,s1,subkey,key);
        if ( key.empty() ) {
            key = subkey;
        }
        if (ele == NULL) {
            elementObject = new T(m_Parent,m_doc, m_ofd_Node,key);
        }
        else {
            elementObject = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,elementObject);
        }

    }

    return (T*)elementObject;
    
}

template<typename T>
inline T* FZZXMLElementObject::getElementObject(T* elementObject,const char * const s1,const char * const subkey)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }

    if (elementObject == NULL) {
        string key;
        XMLElement* ele = getElement(getXmlnsList(),m_ofd_Node,s1,subkey,key);
        if (ele != NULL) {
            elementObject = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,elementObject);
        }
        else {
            elementObject = NULL;
        }
    }
    return (T*)elementObject;
}

#endif //FZZXMLELEMENTOBJECT_H
