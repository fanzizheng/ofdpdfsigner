//
//  Created by zizheng fan on 2023/04/03.
//
#ifndef FZZDOCXDOCUMENT_H
#define FZZDOCXDOCUMENT_H

#include "basic/FZZOFDFilesContainer.h"
#include "office/docx/container/FZZDocXDir.h"
#include "office/docx/xmlfiles/FZZStylesXML.h"
#include "office/docx/xmlfiles/FZZSettingsXML.h"

class FZZOFDFilesContainer;
class FZZZipTracks;

class FZZDocXDocument 
{
public:
    FZZDocXDocument();
    
    virtual ~FZZDocXDocument();
public:
    bool Read(FZZBytes & indata);
    void FlushAll();
    void Close(FZZBytes & outdata);
    
    void getDefaultPageSize(long& width,long& height);
    
    vector<PageElement*>* getPageElements();
    FZZSettingsXML * getSettingsXML();
    FZZStylesXML * getStylesXml();
    FZZThemeXML * getThemeXML();
    FZZFontTableXML * getFontTableXML();
    FZZDocumentXMLRels * getDocumentXMLRels();
    FZZBytes * getMediaFileData(string fileName);
    
    FZZWP * addParagraph();
    size_t getParagraphCount();
    FZZWP * getParagraph(size_t index);
    
    FZZWTbl * addTable();
    size_t getTableCount();
    FZZWTbl * getTable(size_t index);
    
    void getFooters(FZZFooterXML** firstXml,FZZFooterXML** defaultXml,FZZFooterXML** evenXml);
    void getFooters(string firstXml_id,FZZFooterXML** firstXml,string defaultxml_id,FZZFooterXML** defaultXml,string   evenXml_id,FZZFooterXML** evenXml );
    void getHeaders(FZZHeaderXML** firstXml,FZZHeaderXML** defaultXml,FZZHeaderXML** evenXml);
    void getHeaders(string firstXml_id,FZZHeaderXML** firstXml,string defaultxml_id,FZZHeaderXML** defaultXml,string evenXml_id,FZZHeaderXML** evenXml);
    
    FZZNumberingXML * getNumberingXML();

protected:
    FZZOFDFilesContainer m_OFDFilesContainer;
private:
    void zip_mem(FZZBytes & outData);
    void addZip(FZZZipTracks* zipTracks,string rootpath);
    
    FZZWBody * getBody();
    
    
private:
    string m_workDir;
    FZZDocXDir* m_DocXDir;
    
};

#endif //FZZDOCXDOCUMENT_H
