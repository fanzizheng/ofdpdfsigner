//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDXMLELEMENTOBJECT_H
#define FZZOFDXMLELEMENTOBJECT_H

class FZZOFDXMLFileObject;

class FZZOFDXMLElementObject
{
public:
    FZZOFDXMLElementObject(FZZOFDXMLFileObject * parent);
    FZZOFDXMLElementObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key,bool isOnly);
    FZZOFDXMLElementObject(const FZZOFDXMLElementObject& obj);
    virtual ~FZZOFDXMLElementObject();
    template <typename T>
    static T* getInstance(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLElement* ele,T* type);
public:
    void deleteElement(string key);
    void clearElementObjectList(string s1);
protected:
    FZZOFDXMLElementObject();
    
    string getAttribute_String(string key);
    void setAttribute_String(string key,string value);
    
    int getAttribute_Int(string key);
    void setAttribute_Int(string key,int value);
    
    long getAttribute_long(string key);
    void setAttribute_long(string key,long value);
    
    bool getAttribute_Bool(string key,bool defaultValue);
    void setAttribute_Bool(string key,bool value);
    
    float getAttribute_float(string key);
    void setAttribute_float(string key,float value);
    
    double getAttribute_double(string key);
    void setAttribute_double(string key,double value);
    
    
    
    string getValue_String();
    void setValue_String(string value);
    
    int getValue_Int();
    void setValue_Int(int value);
    
    long getValue_long();
    void setValue_long(long value);
    
    bool getValue_Bool();
    void setValue_Bool(bool value);
    
    float getValue_float();
    void setValue_float(float value);
    
    double getValue_double();
    void setValue_double(double value);
    
    
    
    
    XMLElement* getElement(XMLNode* m_ofd_Node,const char * const s1);
    
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
    
   
    

    //FZZXMLElementObject*
protected:
    XMLDocument* m_doc;
    XMLNode* m_ofd_Node;
    FZZOFDXMLFileObject * m_Parent;
    
    
};

template<typename T>
inline T* FZZOFDXMLElementObject::getInstance(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLElement* ele,T* type)
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
inline T* FZZOFDXMLElementObject::addElementObject(vector<T*>* list,const char * const s1)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    if ( list->size() == 0 ) {
        getElementObjectList(list,s1);
    }

    //getElement(m_ofd_Node,s1);
    T* tempObject = new T(m_Parent,m_doc, m_ofd_Node,s1);
    if ( tempObject != NULL ) {
        list->push_back(tempObject);
    }
    return (T*)tempObject;
}

template <typename T>
inline T* FZZOFDXMLElementObject::addElementObject_NoAddList(T* elementObject,const char * const s1)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    T* tempObject = new T(m_Parent,m_doc, m_ofd_Node,s1);
    return (T*)tempObject;
}

template <typename T>
inline void FZZOFDXMLElementObject::getElementObjectList(vector<T*>* list ,const char * const s1)
{
    if ( list->size() == 0 ) {
        XMLElement* ele = getElement(m_ofd_Node,s1);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, s1) == 0) {
                T * temp = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(T*)NULL);
                if ( temp != NULL ) {
                    list->push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
}



template<typename T>
inline T* FZZOFDXMLElementObject::setElementObject(T* elementObject,const char * const s1)
{
    
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }
    
    if ( elementObject == NULL ) {
        XMLElement* ele = getElement(m_ofd_Node,s1);
        
        if (ele == NULL) {
            elementObject = new T(m_Parent,m_doc, m_ofd_Node,s1);
        }
        else {
            elementObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,elementObject);
        }

    }

    return (T*)elementObject;
    
}

template<typename T>
inline T* FZZOFDXMLElementObject::getElementObject(T* elementObject,const char * const s1)
{
    if (m_doc == NULL || m_ofd_Node == NULL ) {
        return NULL;
    }

    if (elementObject == NULL) {
        XMLElement* ele = getElement(m_ofd_Node,s1);
        if (ele != NULL) {
            elementObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,elementObject);
        }
        else {
            elementObject = NULL;
        }
    }
    return (T*)elementObject;
}




#endif //FZZOFDXMLELEMENTOBJECT_H
