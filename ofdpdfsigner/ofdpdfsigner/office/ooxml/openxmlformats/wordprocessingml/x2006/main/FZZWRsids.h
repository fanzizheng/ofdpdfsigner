//
//  Created by zizheng fan on 2023/09/25
//
#ifndef FZZWRSIDS_H
#define FZZWRSIDS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsid.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsidRoot.h"


#define FZZWRSIDS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRSIDS_Name "rsids"

class FZZWRsids : public FZZXMLElementObject
{
public:
    
    FZZWRsids(FZZOfficeObject * parent);
    FZZWRsids(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRsids(const FZZWRsids& obj);
    virtual ~FZZWRsids();
    
public:
    FZZWRsidRoot * setRsidRoot();
    FZZWRsidRoot * getRsidRoot();

    FZZWRsid * addRsid();
    vector<FZZWRsid*> * getRsids();
protected:
    FZZWRsids();
private:
    FZZWRsidRoot* m_FZZWRsidRoot;
    vector<FZZWRsid*> m_FZZWRsids;
};

#endif //FZZWRSIDS_H
