//
//  Created by zizheng fan on 2023/05/10.
//
#ifndef FZZW14DOCID_H
#define FZZW14DOCID_H

#include "office/FZZXMLElementObject.h"

#define FZZW14DOCID_Find_Key "schemas.microsoft.com/office/word/2010/wordml"
#define FZZW14DOCID_Name "docId"

class FZZW14DocId : public FZZXMLElementObject
{
public:
    
    FZZW14DocId(FZZOfficeObject * parent);
    FZZW14DocId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW14DocId(const FZZW14DocId& obj);
    virtual ~FZZW14DocId();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZW14DocId();
private:
    
    
};

#endif //FZZW14DOCID_H
