//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDDIR_H
#define FZZOFDDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDXML.h"
#include "ofd/container/FZZOFDDocDir.h"
#include "ofd/xmlfiles/FZZOFDEntriesXML.h"
#include "ofd/xmlfiles/FZZOFDEntriesMapXML.h"
#include "ofd/xmlfiles/FZZOFDEncryptionsXML.h"
#include "ofd/xmlfiles/FZZOFDDecryptSeedXML.h"

class FZZOFDDir : public FZZOFDBaseDir
{
public:
    FZZOFDDir(FZZOFDFilesContainer* filesContainer,string Root);
    virtual ~FZZOFDDir();
    
public:
    
    
    FZZOFDXML* getOFDXML();
    FZZOFDXML* setOFDXML();
    //完整性
    FZZOFDEntriesXML* getEntriesXML();
    FZZOFDEntriesXML* setEntriesXML();
    //加密
    FZZOFDEncryptionsXML* getEncryptionsXML();
    FZZOFDEncryptionsXML* setEncryptionsXML();
   
    vector<FZZOFDDocDir *> * getDocDirList();
    FZZOFDDocDir * getDocDir_default();
    
    FZZOFDDocDir * setDocDir_default();

    void FlushAll();
    
    //完整性
    void FlushEntriesXML();
    //加密
    void FlushEncryptionsXML();
    
protected:
    
private:
    FZZOFDDir();
private:
    
    FZZOFDXML* m_OFDXML;
    vector<FZZOFDDocDir *> m_FZZOFDDocDirList;
    //FZZOFDDocDir * m_DocDir_Defult;
    FZZOFDEntriesXML * m_FZZOFDEntriesXML;
    FZZOFDEncryptionsXML * m_FZZOFDEncryptionsXML;
};

#endif //FZZOFDDIR_H
