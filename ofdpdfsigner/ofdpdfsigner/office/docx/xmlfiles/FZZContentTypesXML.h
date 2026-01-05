//
//  Created by zizheng fan on 2023/04/14.
//
#ifndef FZZCONTENTTYPESXML_H
#define FZZCONTENTTYPESXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/package/x2006/content_types/CTContentTypes_Default.h"
#include "office/ooxml/openxmlformats/package/x2006/content_types/CTContentTypes_Override.h"



#define CONTENTTYPESXML_FILENAME "[Content_Types].xml"



class FZZContentTypesXML : public FZZOfficeObject
{
public:
    FZZContentTypesXML();
    FZZContentTypesXML(XMLDocument * doc);
    FZZContentTypesXML(const FZZContentTypesXML& obj);
    virtual ~FZZContentTypesXML();

public:
    vector<CTContentTypes_Default *> * getDefaults() ;
    vector<CTContentTypes_Override *> * getOverrides() ;
    CTContentTypes_Default * addDefault();
    CTContentTypes_Override * addOverride();
public:
    bool isHave_Default_ContentType(string type);
protected:
    
private:
    vector<CTContentTypes_Default *> m_DefaultList;
    vector<CTContentTypes_Override *> m_OverrideList;

    
};

#endif //FZZCONTENTTYPESXML_H
