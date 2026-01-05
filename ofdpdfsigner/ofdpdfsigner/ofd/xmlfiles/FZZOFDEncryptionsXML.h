//
//  Created by zizheng fan on 2024/10/16.
//
#ifndef FZZOFDENCRYPTIONSXML_H
#define FZZOFDENCRYPTIONSXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptInfo.h"
#include "basic/FZZAtomicInteger.h"

#define FZZOFDENCRYPTIONSXML_FILENAME "Encryptions.xml"

class FZZOFDEncryptionsXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDEncryptionsXML();
    FZZOFDEncryptionsXML(XMLDocument * doc);
    FZZOFDEncryptionsXML(const FZZOFDEncryptionsXML& obj);
    virtual ~FZZOFDEncryptionsXML();

public:
    FZZOFDEncryptInfo* addEncryptInfo();
    vector<FZZOFDEncryptInfo*>* getEncryptInfoList();
    
public:
  
protected:
    
private:
    vector<FZZOFDEncryptInfo*> m_FZZOFDEncryptInfos;
    
};

#endif //FZZOFDENCRYPTIONSXML_H
