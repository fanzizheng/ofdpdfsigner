//
//  Created by zizheng fan on 2023/11/20
//
#ifndef FZZWTXBXCONTENT_H
#define FZZWTXBXCONTENT_H

#include "office/FZZXMLElementObject.h"


#define FZZWTXBXCONTENT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTXBXCONTENT_Name "txbxContent"

class FZZWP;

class FZZWTxbxContent : public FZZXMLElementObject
{
public:
    
    FZZWTxbxContent(FZZOfficeObject * parent);
    FZZWTxbxContent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTxbxContent(const FZZWTxbxContent& obj);
    virtual ~FZZWTxbxContent();
    
public:
    
    
    FZZWP * addP();
    vector<FZZWP*> * getPList();
protected:
    FZZWTxbxContent();
private:
    vector<FZZWP*> m_FZZWPs;
    
};

#endif //FZZWTXBXCONTENT_H
