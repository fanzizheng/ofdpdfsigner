//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDTEMPLATEDIR_H
#define FZZOFDTEMPLATEDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDPageXML.h"

class FZZOFDTemplateDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDTemplateDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDTemplateDir();
    
public:
    FZZOFDPageXML* getPageXML();
    FZZOFDPageXML* setPageXML();

protected:
    
private:
    FZZOFDTemplateDir();
private:
    FZZOFDPageXML * m_FZZOFDPageXML;
};

#endif //FZZOFDTEMPLATEDIR_H
