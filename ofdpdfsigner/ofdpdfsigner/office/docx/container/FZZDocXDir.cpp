//
//  Created by zizheng fan on 2023/04/04.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZDocXDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZDocXDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZDocXDir::FZZDocXDir() : FZZBaseDir(),m_RelsDir(NULL),m_DocPropsDir(NULL),m_WordDir(NULL),m_ContentTypesXML(NULL)
{
    //DLOG("FZZDocXDir()");
    FZZConst::addClassCount("FZZDocXDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocXDir::FZZDocXDir(FZZOFDFilesContainer* filesContainer,string Root) : FZZBaseDir(filesContainer,Root),m_RelsDir(NULL),m_DocPropsDir(NULL),m_WordDir(NULL),m_ContentTypesXML(NULL)
{
    FZZConst::addClassCount("FZZDocXDir");
    setPath("");
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocXDir::~FZZDocXDir()
{
    //DLOG("~FZZDocXDir()");
    FZZConst::delClassCount("FZZDocXDir");
    if ( m_RelsDir != NULL ) {
        delete m_RelsDir;
        m_RelsDir = NULL;
    }
    
    if ( m_DocPropsDir != NULL ) {
        delete m_DocPropsDir;
        m_DocPropsDir = NULL;
    }
    
    if ( m_WordDir != NULL ) {
        delete m_WordDir;
        m_WordDir = NULL;
    }
    
    if ( m_ContentTypesXML != NULL ) {
        delete m_ContentTypesXML;
        m_ContentTypesXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsDir * FZZDocXDir::getRelsDir()
{
    if ( m_RelsDir != NULL ) {
        return m_RelsDir;
    }
    
    m_RelsDir = new FZZRelsDir(m_OFDFilesContainer,m_Root,m_Path+"_rels/");
    return m_RelsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocPropsDir * FZZDocXDir::getDocPropsDir()
{
    if ( m_DocPropsDir != NULL ) {
        return m_DocPropsDir;
    }
    
    m_DocPropsDir = new FZZDocPropsDir(m_OFDFilesContainer,m_Root,m_Path+"docProps/");
    return m_DocPropsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWordDir * FZZDocXDir::getWordDir()
{
    if ( m_WordDir != NULL ) {
        return m_WordDir;
    }
    
    m_WordDir = new FZZWordDir(m_OFDFilesContainer,m_Root,m_Path+"word/");
    return m_WordDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentTypesXML* FZZDocXDir::getContentTypesXML()
{
    if ( m_ContentTypesXML != NULL ) {
        return m_ContentTypesXML;
    }
    
    XMLDocument * doc = getXMLDocument(CONTENTTYPESXML_FILENAME);
    if ( doc != NULL ) {
        m_ContentTypesXML = new FZZContentTypesXML(doc);
        
    } else {
        m_ContentTypesXML = new FZZContentTypesXML();
    }
    
  
    return m_ContentTypesXML;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDir::FlushAll()
{
    FZZRelsDir * relsDir = getRelsDir();
    if ( relsDir != NULL ) {
        FZZRelsXML*  tempRelsXML = relsDir->getRelsXML();
        relsDir->FlushOfficeObject(tempRelsXML);
    }
    
    FZZDocPropsDir * docPropsDir = getDocPropsDir();
    if ( docPropsDir != NULL ) {
        docPropsDir->FlushOfficeObject(docPropsDir->getAppXML());
        docPropsDir->FlushOfficeObject(docPropsDir->getCoreXML());
    }
    
    FZZWordDir* wordDir = getWordDir();
    if ( wordDir != NULL ) {
        wordDir->FlushOfficeObject(wordDir->getDocumentXML());
        wordDir->FlushOfficeObject(wordDir->getFontTableXML());
        wordDir->FlushOfficeObject(wordDir->getSettingsXML());
        wordDir->FlushOfficeObject(wordDir->getStylesXML());
        wordDir->FlushOfficeObject(wordDir->getWebSettingsXML());
        
        FZZRelsDir * wordRelsDir = wordDir->getRelsDir();
        if ( wordRelsDir != NULL ) {
            wordRelsDir->FlushOfficeObject(wordRelsDir->getDocumentXMLRels());
        }
        
        FZZThemeDir * wordThemeDir = wordDir->getThemeDir();
        if ( wordThemeDir != NULL ) {
            wordThemeDir->FlushOfficeObject(wordThemeDir->getThemeXML());
        }
        
        wordDir->FlushOfficeObject(wordDir->getEndnotesXML());
        wordDir->FlushOfficeObject(wordDir->getFootnotesXML());
        
        map<string,FZZFooterXML *>* footerXmlList = wordDir->getFooterXMLList();
        if ( footerXmlList != NULL && footerXmlList->size() > 0 ) {
            map<string,FZZFooterXML *>::const_iterator footerItr;
            for( footerItr = footerXmlList->begin(); footerItr != footerXmlList->end(); footerItr++ ) {
                FZZFooterXML * temp = footerItr->second;
                if ( temp != NULL ) {
                    wordDir->FlushOfficeObject(temp);
                }
            }
        }
        
        map<string,FZZHeaderXML *>* headerXmllist = wordDir->getHeaderXMLList();
        if ( headerXmllist != NULL && headerXmllist->size() > 0 ) {
            map<string,FZZHeaderXML *>::const_iterator headerItr;
            for( headerItr = headerXmllist->begin(); headerItr != headerXmllist->end(); headerItr++ ) {
                FZZHeaderXML * temp = headerItr->second;
                if ( temp != NULL ) {
                    wordDir->FlushOfficeObject(temp);
                }
            }
        }
        
    }
    
    FZZContentTypesXML* tempContentTypesXML = getContentTypesXML();
    FlushOfficeObject(tempContentTypesXML);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
