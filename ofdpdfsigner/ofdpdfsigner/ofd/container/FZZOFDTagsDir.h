//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDTAGSDIR_H
#define FZZOFDTAGSDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDCustomTagsXML.h"

class FZZOFDTagsDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDTagsDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDTagsDir();
    
public:
    FZZOFDCustomTagsXML* getCustomTagsXML();
    FZZOFDCustomTagsXML* setCustomTagsXML();
    
protected:
    
private:
    FZZOFDTagsDir();
private:
    FZZOFDCustomTagsXML * m_FZZOFDCustomTagsXML;
};

#endif //FZZOFDTAGSDIR_H
