//
//  Created by zizheng fan on 2023/04/04.
//
#ifndef FZZDOCXDIR_H
#define FZZDOCXDIR_H

#include "office/docx/container/FZZBaseDir.h"
#include "office/docx/container/FZZRelsDir.h"
#include "office/docx/container/FZZDocPropsDir.h"
#include "office/docx/container/FZZWordDir.h"
#include "office/docx/xmlfiles/FZZContentTypesXML.h"



class FZZDocXDir : public FZZBaseDir
{
public:
    FZZDocXDir(FZZOFDFilesContainer* filesContainer,string Root);
    virtual ~FZZDocXDir();
    
public:
    FZZRelsDir * getRelsDir();
    FZZDocPropsDir * getDocPropsDir();
    FZZWordDir * getWordDir();
    
    FZZContentTypesXML* getContentTypesXML();
    
    void FlushAll();
    
   
    
protected:
    
private:
    FZZDocXDir();
private:
    FZZRelsDir * m_RelsDir;
    FZZDocPropsDir * m_DocPropsDir;
    FZZWordDir * m_WordDir;
    FZZContentTypesXML* m_ContentTypesXML;
};

#endif //FZZDOCXDIR_H
