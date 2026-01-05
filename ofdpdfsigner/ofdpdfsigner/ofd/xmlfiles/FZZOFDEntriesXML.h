//
//  Created by zizheng fan on 2024/09/25.
//
#ifndef FZZOFDENTRIESXML_H
#define FZZOFDENTRIESXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/entries/FZZOFDFileList.h"
#include "ofd/ofdxmlelement/basicStructure/entries/FZZOFDSignedValueLoc.h"
#include "basic/FZZAtomicInteger.h"

#define FZZOFDENTRIESXML_FILENAME "OFDEntries.xml"

class FZZOFDEntriesXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDEntriesXML();
    FZZOFDEntriesXML(XMLDocument * doc);
    FZZOFDEntriesXML(const FZZOFDEntriesXML& obj);
    virtual ~FZZOFDEntriesXML();

public:
    string getID();
    string getCreatorName();
    string getVersion();
    string getCreationDate();
    
    void setID(string value);
    void setCreatorName(string value);
    void setVersion(string value);
    void setCreationDate(string value);
    
    FZZOFDSignedValueLoc * setSignedValueLoc();
    FZZOFDSignedValueLoc * getSignedValueLoc();
    FZZOFDFileList * setFileList();
    FZZOFDFileList * getFileList();
    
public:
  
protected:
    
private:
    FZZOFDSignedValueLoc * m_FZZOFDSignedValueLoc;
    FZZOFDFileList * m_FZZOFDFileList;
    
};

#endif //FZZOFDENTRIESXML_H
