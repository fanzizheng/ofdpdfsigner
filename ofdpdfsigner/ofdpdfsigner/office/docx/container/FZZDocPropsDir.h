//
//  Created by zizheng fan on 2023/04/07.
//
#ifndef FZZDOCPROPSDIR_H
#define FZZDOCPROPSDIR_H

#include "office/docx/container/FZZBaseDir.h"
#include "office/docx/xmlfiles/FZZAppXML.h"
#include "office/docx/xmlfiles/FZZCoreXML.h"

class FZZDocPropsDir : public FZZBaseDir
{
public:
    
    FZZDocPropsDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZDocPropsDir();
    
public:
    FZZAppXML* getAppXML();
    FZZCoreXML* getCoreXML();
    
   
protected:
    
private:
    FZZDocPropsDir();
    
    FZZAppXML * m_AppXML;
    FZZCoreXML * m_CoreXML;
};

#endif //FZZDOCPROPSDIR_H
