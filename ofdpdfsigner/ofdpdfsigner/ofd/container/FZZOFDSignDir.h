//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNDIR_H
#define FZZOFDSIGNDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDSignatureXML.h"

class FZZOFDSignDir : public FZZOFDBaseDir
{
public:
    static string SealFileName;
    static string SignedValueFileName ;
public:
    
    FZZOFDSignDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDSignDir();
    
public:
    int getIndex() {return m_index;}
    
    FZZOFDSignatureXML* getSignatureXML();
    FZZOFDSignatureXML* setSignatureXML();
    
    void setSignID(string value) { m_SignID = value; }
    string getSignID() { return m_SignID; }
protected:
    
private:
    FZZOFDSignDir();
private:
    int m_index;
    string m_SignID;
    FZZOFDSignatureXML * m_FZZOFDSignatureXML;
};

#endif //FZZOFDSIGNDIR_H
