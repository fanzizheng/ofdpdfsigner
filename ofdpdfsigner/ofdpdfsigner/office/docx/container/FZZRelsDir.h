//
//  Created by zizheng fan on 2023/04/05.
//
#ifndef FZZRELSDIR_H
#define FZZRELSDIR_H

#include "office/docx/container/FZZBaseDir.h"
#include "office/docx/xmlfiles/FZZRelsXML.h"
#include "office/docx/xmlfiles/FZZDocumentXMLRels.h"

class FZZRelsDir : public FZZBaseDir
{
public:
    
    FZZRelsDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZRelsDir();
    
public:
    FZZRelsXML* getRelsXML();
    FZZDocumentXMLRels* getDocumentXMLRels();
protected:
    
private:
    FZZRelsDir();
    FZZRelsXML * m_RelsXML;
    FZZDocumentXMLRels * m_DocumentXMLRels;
};

#endif //FZZRELSDIR_H
