//
//  Created by zizheng fan on 2024/10/16.
//
#ifndef FZZOFDENTRIESMAPXML_H
#define FZZOFDENTRIESMAPXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptEntry.h"
#include "basic/FZZAtomicInteger.h"

//#define FZZOFDENTRIESMAPXML_FILENAME "entriesmap.dat"

class FZZOFDEntriesMapXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDEntriesMapXML();
    FZZOFDEntriesMapXML(XMLDocument * doc);
    FZZOFDEntriesMapXML(const FZZOFDEntriesMapXML& obj);
    virtual ~FZZOFDEntriesMapXML();

public:
    string getID();
    void setID(string value);
    
    
    FZZOFDEncryptEntry* addEncryptEntry();
    vector<FZZOFDEncryptEntry*>* getEncryptEntryList();
    
public:
  
protected:
    
private:
    vector<FZZOFDEncryptEntry*> m_FZZOFDEncryptEntrys;
    
};

#endif //FZZOFDENTRIESMAPXML_H
