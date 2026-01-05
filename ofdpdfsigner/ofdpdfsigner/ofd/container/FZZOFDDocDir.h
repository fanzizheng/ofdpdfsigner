//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDOCDIR_H
#define FZZOFDDOCDIR_H

#include "ofd/container/FZZOFDBaseDir.h"
#include "ofd/xmlfiles/FZZOFDDocumentXML.h"
#include "ofd/xmlfiles/FZZOFDResXML.h"
//#include "ofd/xmlfiles/FZZOFDAttachmentsXML.h"
//#include "ofd/xmlfiles/FZZOFDAnnotationsXML.h"
#include "ofd/xmlfiles/FZZOFDExtensionsXML.h"

#include "ofd/container/FZZOFDSignsDir.h"
#include "ofd/container/FZZOFDResDir.h"
#include "ofd/container/FZZOFDTagsDir.h"
#include "ofd/container/FZZOFDTemplateDir.h"
#include "ofd/container/FZZOFDPageDir.h"
#include "ofd/container/FZZOFDAnnotsDir.h"
#include "ofd/container/FZZOFDAttachsDir.h"

class FZZOFDDocDir : public FZZOFDBaseDir
{
public:
    
    FZZOFDDocDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZOFDDocDir();
    
    
public:
    
    FZZOFDDocumentXML* getDocumentXML();
    FZZOFDPublicResXML* getPublicResXML();
    FZZOFDDocumentResXML* getDocumentResXML();
    FZZOFDExtensionsXML* getExtensionsXML();
    
    FZZOFDDocumentXML* setDocumentXML();
    FZZOFDPublicResXML* setPublicResXML();
    FZZOFDDocumentResXML* setDocumentResXML();
    FZZOFDExtensionsXML* setExtensionsXML();
  
    
    FZZOFDSignsDir * getSignsDir();
    FZZOFDSignsDir * getSignsDir(string path);
    
    FZZOFDResDir * getResDir();
    FZZOFDTagsDir * getTagsDir();
    
    FZZOFDTemplateDir * addTemplateDir();
    vector<FZZOFDTemplateDir *> * getTemplateList();
    FZZOFDTemplateDir * getTemplateDir(string strId);
    FZZOFDPageDir * addPageDir();
    vector<FZZOFDPageDir *> * getPageDirList();
    
    FZZOFDAnnotsDir * getAnnotsDir();
    FZZOFDAttachsDir * getAttachsDir();
    
protected:
    
private:
    FZZOFDDocDir();
private:
    int m_index;
   
    
    FZZOFDDocumentXML * m_FZZOFDDocumentXML;
    FZZOFDPublicResXML * m_FZZOFDPublicResXML;
    FZZOFDDocumentResXML * m_FZZOFDDocumentResXML;
    FZZOFDExtensionsXML * m_FZZOFDExtensionsXML;
    
    
    FZZOFDSignsDir * m_FZZOFDSignsDir;
    FZZOFDResDir * m_FZZOFDResDir;
    FZZOFDTagsDir  * m_FZZOFDTagsDir;
    FZZOFDAnnotsDir * m_FZZOFDAnnotsDir;
    FZZOFDAttachsDir * m_FZZOFDAttachsDir;
    vector<FZZOFDTemplateDir *> m_FZZOFDTemplateDirList;
    vector<FZZOFDPageDir *> m_FZZOFDPageDirList;

};

#endif //FZZOFDDOCDIR_H
