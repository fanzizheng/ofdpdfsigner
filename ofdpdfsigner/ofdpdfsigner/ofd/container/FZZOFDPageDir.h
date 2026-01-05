//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDPAGEDIR_H
#define FZZOFDPAGEDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDPageXML.h"
#include "ofd/xmlfiles/FZZOFDResXML.h"
#include "ofd/xmlfiles/FZZOFDPageAnnotXML.h"

class FZZOFDPageDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDPageDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDPageDir();
    
public:
    FZZOFDPageXML* getPageXML();
    FZZOFDPageResXML* getPageResXML();
    FZZOFDPageAnnotXML* getAnnotationXML();
    
    FZZOFDPageXML* setPageXML();
    FZZOFDPageResXML* setPageResXML();
    FZZOFDPageAnnotXML* setAnnotationXML();

    void setPageId(string id) { m_PageId = id; }
    string getPageId() { return m_PageId; }
protected:
    
private:
    FZZOFDPageDir();
private:
    string m_PageId;
    FZZOFDPageXML * m_FZZOFDPageXML;
    FZZOFDPageResXML * m_FZZOFDPageResXML;
    FZZOFDPageAnnotXML * m_FZZOFDPageAnnotXML;
};

#endif //FZZOFDPAGEDIR_H
