//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDEXTENSION_H
#define FZZOFDEXTENSION_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/extensions/FZZOFDProperty.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDExtendData.h"


#define FZZOFDEXTENSION_Name "ofd:Extension"

class FZZOFDExtension : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDExtension(FZZOFDXMLFileObject * parent);
    FZZOFDExtension(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDExtension(const FZZOFDExtension& obj);
    virtual ~FZZOFDExtension();
    
public:
    void setAppName(string value);
    string getAppName();
    void setCompany(string value);
    string getCompany();
    void setAppVersion(string value);
    string getAppVersion();
    void setDate(string value);
    string getDate();
    void setRefId(string value);
    string getRefId();
    void setRefId(long value);
    long getRefId_long();
    FZZOFDProperty * addProperty();
    vector<FZZOFDProperty*> * getPropertyList();
    FZZOFDExtendData * addExtendData();
    vector<FZZOFDExtendData*> * getExtendDataList();
    
protected:
    FZZOFDExtension();
private:
    vector<FZZOFDProperty*> m_FZZOFDPropertys;
    vector<FZZOFDExtendData*> m_FZZOFDExtendDatas;
};

#endif //FZZOFDEXTENSION_H
