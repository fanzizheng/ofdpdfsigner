//
//  Created by zizheng fan on 2023/08/29
//
#ifndef FZZRELATIONSHIP_H
#define FZZRELATIONSHIP_H

#include "office/FZZXMLElementObject.h"

#define FZZRELATIONSHIP_Find_Key "schemas.openxmlformats.org/package/2006/relationships"

#define FZZRELATIONSHIP_Name "Relationship"

class FZZRelationship : public FZZXMLElementObject
{
public:
    
    FZZRelationship(FZZOfficeObject * parent);
    FZZRelationship(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZRelationship(const FZZRelationship& obj);
    virtual ~FZZRelationship();
    //static FZZRelationship* getInstance(XMLDocument* doc, XMLElement* ele);
public:
    string getId();
    void setId(string value);
    string getType();
    void setType(string value);
    string getTarget();
    void setTarget(string value);
protected:
    FZZRelationship();
private:

    
};

#endif //FZZRELATIONSHIP_H
