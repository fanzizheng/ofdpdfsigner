//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDATTACHSDIR_H
#define FZZOFDATTACHSDIR_H

#include "ofd/container/FZZOFDBaseDir.h"

#include "ofd/xmlfiles/FZZOFDAttachmentsXML.h"

class FZZOFDAttachsDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDAttachsDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDAttachsDir();
    
public:
    FZZOFDAttachmentsXML* getAttachmentsXML();
    FZZOFDAttachmentsXML* setAttachmentsXML();

    int getFileNameIndex() {return ++m_FileNameIndex; }
protected:
    
private:
    FZZOFDAttachsDir();
private:
    FZZOFDAttachmentsXML * m_FZZOFDAttachmentsXML;
    int m_FileNameIndex;
};

#endif //FZZOFDATTACHSDIR_H
