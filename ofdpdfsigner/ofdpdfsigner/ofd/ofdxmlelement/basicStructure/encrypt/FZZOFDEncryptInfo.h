//
//  Created by zizheng fan on 2024/10/19.
//
#ifndef FZZOFDENCRYPTINFO_H
#define FZZOFDENCRYPTINFO_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDProvider.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptScope.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDExtendParams.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEntriesMapLoc.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDDecryptSeedLoc.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptDate.h"

#define FZZOFDENCRYPTINFO_Name "ofd:EncryptInfo"

class FZZOFDEncryptInfo : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDEncryptInfo(FZZOFDXMLFileObject * parent);
    FZZOFDEncryptInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEncryptInfo(const FZZOFDEncryptInfo& obj);
    virtual ~FZZOFDEncryptInfo();
    
public:
    void setID(string value);
    string getID();
    void setRelative(string value);
    string getRelative();
    
    FZZOFDProvider * setProvider();
    FZZOFDProvider * getProvider();
    FZZOFDEncryptScope * setEncryptScope();
    FZZOFDEncryptScope * getEncryptScope();
    FZZOFDExtendParams * setParameters();
    FZZOFDExtendParams * getParameters();
    FZZOFDEntriesMapLoc * setEntriesMapLoc();
    FZZOFDEntriesMapLoc * getEntriesMapLoc();
    FZZOFDDecryptSeedLoc * setDecryptSeedLoc();
    FZZOFDDecryptSeedLoc * getDecryptSeedLoc();
    FZZOFDEncryptDate * setEncryptDate();
    FZZOFDEncryptDate * getEncryptDate();
    
protected:
    FZZOFDEncryptInfo();
private:
    FZZOFDProvider * m_FZZOFDProvider;
    FZZOFDEncryptScope * m_FZZOFDEncryptScope;
    FZZOFDExtendParams * m_FZZOFDExtendParams;
    FZZOFDEntriesMapLoc * m_FZZOFDEntriesMapLoc;
    FZZOFDDecryptSeedLoc * m_FZZOFDDecryptSeedLoc;
    FZZOFDEncryptDate * m_FZZOFDEncryptDate;
    
};

#endif //FZZOFDENCRYPTINFO_H
