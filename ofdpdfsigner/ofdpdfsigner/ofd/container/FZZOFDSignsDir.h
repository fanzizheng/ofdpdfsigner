//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNSDIR_H
#define FZZOFDSIGNSDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDSignaturesXML.h"
#include "ofd/container/FZZOFDSignDir.h"

class FZZOFDSignsDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDSignsDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDSignsDir();
    
public:
    FZZOFDSignaturesXML* getSignaturesXML();
    FZZOFDSignaturesXML* setSignaturesXML();
    
    vector<FZZOFDSignDir *> * getSignDirList();
    FZZOFDSignDir * getSignDir(string signDirPath);
    
    FZZOFDSignatureXML * getSignatureXML(string signDirPath);
    
    
    FZZOFDSignDir * addSignDir();
protected:
    
private:
    FZZOFDSignsDir();
private:
    FZZOFDSignaturesXML * m_FZZOFDSignaturesXML;
    vector<FZZOFDSignDir *> m_FZZOFDSignDirList;
    int m_maxSignIndex;
};

#endif //FZZOFDSIGNSDIR_H
