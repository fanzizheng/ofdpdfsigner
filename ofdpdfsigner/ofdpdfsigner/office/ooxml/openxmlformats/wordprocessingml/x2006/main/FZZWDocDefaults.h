//
//  Created by zizheng fan on 2023/10/13
//
#ifndef FZZWDOCDEFAULTS_H
#define FZZWDOCDEFAULTS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPrDefault.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPrDefault.h"

#define FZZWDOCDEFAULTS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDOCDEFAULTS_Name "docDefaults"

class FZZWDocDefaults : public FZZXMLElementObject
{
public:
    
    FZZWDocDefaults(FZZOfficeObject * parent);
    FZZWDocDefaults(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDocDefaults(const FZZWDocDefaults& obj);
    virtual ~FZZWDocDefaults();
    
public:
//    FZZWRPrDefault * addRPrDefault();
//    vector<FZZWRPrDefault*> * getRPrDefaults();
    FZZWRPrDefault * setRPrDefault();
    FZZWRPrDefault * getRPrDefault();
    
//    FZZWPPrDefault * addPPrDefault();
//    vector<FZZWPPrDefault*> * getPPrDefaults();
    FZZWPPrDefault * setPPrDefault();
    FZZWPPrDefault * getPPrDefault();
protected:
    FZZWDocDefaults();
private:
    //vector<FZZWRPrDefault*> m_FZZWRPrDefaults;
    FZZWRPrDefault * m_FZZWRPrDefault;
    //vector<FZZWPPrDefault*> m_FZZWPPrDefaults;
    FZZWPPrDefault * m_FZZWPPrDefault;
};

#endif //FZZWDOCDEFAULTS_H
