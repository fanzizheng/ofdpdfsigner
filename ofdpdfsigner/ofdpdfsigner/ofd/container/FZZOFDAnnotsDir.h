//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDANNOTSDIR_H
#define FZZOFDANNOTSDIR_H

#include "ofd/container/FZZOFDBaseDir.h"

#include "ofd/container/FZZOFDPageDir.h"
#include "ofd/xmlfiles/FZZOFDAnnotationsXML.h"

class FZZOFDAnnotsDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDAnnotsDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDAnnotsDir();
    
public:
    FZZOFDAnnotationsXML* getAnnotationsXML();
    FZZOFDAnnotationsXML* setAnnotationsXML();
    vector<FZZOFDPageDir *> * getPageDirList();
    FZZOFDPageDir * getPageDir(string PageId);
    FZZOFDPageDir * addPageDir(string PageId);

protected:
    
private:
    FZZOFDAnnotsDir();
private:
    FZZOFDAnnotationsXML * m_FZZOFDAnnotationsXML;
    vector<FZZOFDPageDir *> m_FZZOFDPageDirList;
};

#endif //FZZOFDANNOTSDIR_H
