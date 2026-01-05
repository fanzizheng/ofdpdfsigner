//
//  Created by zizheng fan on 2023/08/30
//
#ifndef CTCONTENTTYPES_DEFAULT_H
#define CTCONTENTTYPES_DEFAULT_H

#include "office/FZZXMLElementObject.h"

#define CTContentTypes_Default_Find_Key "schemas.openxmlformats.org/package/2006/content-types"
#define CTContentTypes_Default_Name "Default"

class CTContentTypes_Default : public FZZXMLElementObject
{
public:
    
    CTContentTypes_Default(FZZOfficeObject * parent);
    CTContentTypes_Default(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    CTContentTypes_Default(const CTContentTypes_Default& obj);
    virtual ~CTContentTypes_Default();
    //static CTContentTypes_Default* getInstance(XMLDocument* doc, XMLElement* ele);
public:
    string getExtension();
    void setExtension(string value);
    string getContentType();
    void setContentType(string value);
protected:
    CTContentTypes_Default();
private:
    
    
    //string m_Extension;
    //string m_ContentType;
};

#endif //CTCONTENTTYPES_DEFAULT_H
