//
//  Created by zizheng fan on 2023/04/06.
//
#ifndef FZZWORDDIR_H
#define FZZWORDDIR_H

#include "office/docx/container/FZZBaseDir.h"
#include "office/docx/container/FZZRelsDir.h"
#include "office/docx/container/FZZThemeDir.h"
#include "office/docx/xmlfiles/FZZDocumentXML.h"
#include "office/docx/xmlfiles/FZZFontTableXML.h"
#include "office/docx/xmlfiles/FZZSettingsXML.h"
#include "office/docx/xmlfiles/FZZStylesXML.h"
#include "office/docx/xmlfiles/FZZWebSettingsXML.h"
#include "office/docx/container/FZZMediaDir.h"
#include "office/docx/xmlfiles/FZZEndnotesXML.h"
#include "office/docx/xmlfiles/FZZFooterXML.h"
#include "office/docx/xmlfiles/FZZFootnotesXML.h"
#include "office/docx/xmlfiles/FZZHeaderXML.h"
#include "office/docx/xmlfiles/FZZNumberingXML.h"

class FZZWordDir : public FZZBaseDir
{
public:
    
    FZZWordDir(FZZOFDFilesContainer* filesContainer,string Root,string path);
    virtual ~FZZWordDir();
    
public:
    FZZRelsDir * getRelsDir();
    FZZThemeDir * getThemeDir();
    FZZMediaDir * getMediaDir();
    
    FZZDocumentXML * getDocumentXML();
    FZZFontTableXML * getFontTableXML();
    FZZSettingsXML * getSettingsXML();
    FZZStylesXML * getStylesXML();
    FZZWebSettingsXML * getWebSettingsXML();
    FZZEndnotesXML * getEndnotesXML();
    FZZFootnotesXML * getFootnotesXML();
    FZZNumberingXML * getNumberingXML();
    
    map<string,FZZFooterXML *>* getFooterXMLList();
    map<string,FZZHeaderXML *>* getHeaderXMLList();
    
    FZZFooterXML * getFooterXML(string FileName);
    FZZHeaderXML * getHeaderXML(string FileName);
    
    
    
    FZZFooterXML * addFooterXML();
    FZZHeaderXML * addHeaderXML();
protected:
    
private:
    FZZWordDir();
    FZZRelsDir * m_RelsDir;
    FZZThemeDir * m_ThemeDir;
    FZZDocumentXML * m_DocumentXML;
    FZZFontTableXML * m_FontTableXML;
    FZZSettingsXML * m_SettingsXML;
    FZZStylesXML * m_StylesXML;
    FZZWebSettingsXML * m_WebSettingsXML;
    FZZEndnotesXML * m_EndnotesXML;
    FZZFootnotesXML * m_FootnotesXML;
    FZZNumberingXML * m_NumberingXML;
    map<string,FZZFooterXML *> m_FooterXMLList;
    map<string,FZZHeaderXML *> m_HeaderXMLList;
    
    FZZMediaDir * m_MediaDir;
    
};

#endif //FZZWORDDIR_H
