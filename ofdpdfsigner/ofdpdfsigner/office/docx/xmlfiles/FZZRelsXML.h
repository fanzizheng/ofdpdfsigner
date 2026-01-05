//
//  Created by zizheng fan on 2023/04/16.
//
#ifndef FZZRELSXML_H
#define FZZRELSXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/package/x2006/FZZRelationship.h"

#define RELSXML_FILENAME ".rels"
#define RELSXML_TYPE_Extended_properties "http://schemas.openxmlformats.org/officeDocument/2006/relationships/extended-properties"
#define RELSXML_TYPE_Core_properties "http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties"
#define RELSXML_TYPE_Extended_OfficeDocument "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"

class FZZRelsXML : public FZZOfficeObject
{
public:
    FZZRelsXML();
    FZZRelsXML(XMLDocument * doc);
    FZZRelsXML(const FZZRelsXML& obj);
    virtual ~FZZRelsXML();
    
 
public:
    vector<FZZRelationship *> * getRelationships() ;
    FZZRelationship * addRelationship();
    
protected:
    
private:
    vector<FZZRelationship *> m_RelationshipList;

    
};

#endif //FZZRELSXML_H
