//
//  Created by zizheng fan on 2023/04/27.
//
#ifndef FZZW15DOCID_H
#define FZZW15DOCID_H

#include "office/FZZXMLElementObject.h"

#define FZZW15DOCID_Find_Key "schemas.microsoft.com/office/word/2012/wordml"

#define FZZW15DOCID_Name "docId"

class FZZW15DocId : public FZZXMLElementObject
{
public:
    
    FZZW15DocId(FZZOfficeObject * parent);
    FZZW15DocId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW15DocId(const FZZW15DocId& obj);
    virtual ~FZZW15DocId();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZW15DocId();
private:
    
    
};

#endif //FZZW15DOCID_H
