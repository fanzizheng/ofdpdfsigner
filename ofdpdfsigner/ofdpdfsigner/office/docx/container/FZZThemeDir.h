//
//  Created by zizheng fan on 2023/04/07.
//
#ifndef FZZTHEMEDIR_H
#define FZZTHEMEDIR_H

#include "office/docx/container/FZZBaseDir.h"
#include "office/docx/xmlfiles/FZZThemeXML.h"

class FZZThemeDir : public FZZBaseDir
{
public:
    
    FZZThemeDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZThemeDir();
    
public:
    FZZThemeXML* getThemeXML();
  
protected:
    
private:
    FZZThemeDir();
    FZZThemeXML* m_ThemeXML;
};

#endif //FZZTHEMEDIR_H
