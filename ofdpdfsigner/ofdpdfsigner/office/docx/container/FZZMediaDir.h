//
//  Created by zizheng fan on 2023/04/07.
//
#ifndef FZZMEDIADIR_H
#define FZZMEDIADIR_H

#include "office/docx/container/FZZBaseDir.h"


class FZZMediaDir : public FZZBaseDir
{
public:
    
    FZZMediaDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZMediaDir();
    
public:
    
  
protected:
    
private:
    FZZMediaDir();
   
};

#endif //FZZMEDIADIR_H
