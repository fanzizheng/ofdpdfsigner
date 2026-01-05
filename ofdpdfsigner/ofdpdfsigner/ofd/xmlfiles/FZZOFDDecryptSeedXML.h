//
//  Created by zizheng fan on 2024/10/16.
//
#ifndef FZZOFDDECRYPTSEEDXML_H
#define FZZOFDDECRYPTSEEDXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDUserInfo.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDExtendParams.h"
#include "basic/FZZAtomicInteger.h"

//#define FZZOFDDECRYPTSEEDXML_FILENAME "decryptseed.dat"

class FZZOFDDecryptSeedXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDDecryptSeedXML();
    FZZOFDDecryptSeedXML(XMLDocument * doc);
    FZZOFDDecryptSeedXML(const FZZOFDDecryptSeedXML& obj);
    virtual ~FZZOFDDecryptSeedXML();

public:
    string getID();
    string getEncryptCaseId();
    
    void setID(string value);
    void setEncryptCaseId(string value);
    
    
    FZZOFDExtendParams * setExtendParams();
    FZZOFDExtendParams * getExtendParams();
    
    FZZOFDUserInfo* addUserInfo();
    vector<FZZOFDUserInfo*>* getUserInfoList();
    

    
public:
  
protected:
    
private:
    FZZOFDExtendParams * m_FZZOFDExtendParams;
    vector<FZZOFDUserInfo*> m_FZZOFDUserInfos;
    

    
};

#endif //FZZOFDDECRYPTSEEDXML_H
