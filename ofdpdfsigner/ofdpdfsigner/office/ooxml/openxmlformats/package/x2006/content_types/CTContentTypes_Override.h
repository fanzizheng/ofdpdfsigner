//
//  Created by zizheng fan on 2023/08/30
//
#ifndef CTCONTENTTYPES_OVERRIDE_H
#define CTCONTENTTYPES_OVERRIDE_H

#include "office/FZZXMLElementObject.h"

#define CTContentTypes_Override_Find_Key "schemas.openxmlformats.org/package/2006/content-types"
#define CTContentTypes_Override_Name "Override"

class CTContentTypes_Override : public FZZXMLElementObject
{
public:

    CTContentTypes_Override(FZZOfficeObject * parent);
    CTContentTypes_Override(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    CTContentTypes_Override(const CTContentTypes_Override& obj);
    virtual ~CTContentTypes_Override();
    //static CTContentTypes_Override* getInstance(XMLDocument* doc, XMLElement* ele);
public:
    string getPartName();
    void setPartName(string value);
    string getContentType();
    void setContentType(string value);
protected:
    CTContentTypes_Override();
private:

    
};

#endif //CTCONTENTTYPES_OVERRIDE_H
