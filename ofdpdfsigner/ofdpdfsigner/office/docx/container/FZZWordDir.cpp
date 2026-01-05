//
//  Created by zizheng fan on 2023/04/06.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZWordDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWordDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWordDir::FZZWordDir() :FZZBaseDir() ,m_RelsDir(NULL),m_ThemeDir(NULL),m_DocumentXML(NULL),m_FontTableXML(NULL)
    ,m_SettingsXML(NULL),m_StylesXML(NULL),m_WebSettingsXML(NULL),m_MediaDir(NULL),m_EndnotesXML(NULL),m_FootnotesXML(NULL),m_NumberingXML(NULL)
{
    //DLOG("FZZWordDir()");
    FZZConst::addClassCount("FZZWordDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWordDir::FZZWordDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZBaseDir(filesContainer,Root),m_RelsDir(NULL),m_ThemeDir(NULL),m_DocumentXML(NULL),m_FontTableXML(NULL)
    ,m_SettingsXML(NULL),m_StylesXML(NULL),m_WebSettingsXML(NULL),m_MediaDir(NULL),m_EndnotesXML(NULL),m_FootnotesXML(NULL),m_NumberingXML(NULL)
{
    FZZConst::addClassCount("FZZWordDir");
    setPath(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWordDir::~FZZWordDir()
{
    //DLOG("~FZZWordDir()");
    FZZConst::delClassCount("FZZWordDir");
    if ( m_RelsDir != NULL ) {
        delete m_RelsDir;
        m_RelsDir = NULL;
    }
    
    if ( m_ThemeDir != NULL ) {
        delete m_ThemeDir;
        m_ThemeDir = NULL;
    }
    
    if ( m_DocumentXML != NULL ) {
        delete m_DocumentXML;
        m_DocumentXML = NULL;
    }
    
    if ( m_FontTableXML != NULL ) {
        delete m_FontTableXML;
        m_FontTableXML = NULL;
    }
    
    if ( m_SettingsXML != NULL ) {
        delete m_SettingsXML;
        m_SettingsXML = NULL;
    }
    
    if ( m_StylesXML != NULL ) {
        delete m_StylesXML;
        m_StylesXML = NULL;
    }
    
    if ( m_WebSettingsXML != NULL ) {
        delete m_WebSettingsXML;
        m_WebSettingsXML = NULL;
    }
    
    if ( m_MediaDir != NULL ) {
        delete m_MediaDir;
        m_MediaDir = NULL;
    }
    
    if ( m_EndnotesXML != NULL ) {
        delete m_EndnotesXML;
        m_EndnotesXML = NULL;
    }
    
    if ( m_FootnotesXML != NULL ) {
        delete m_FootnotesXML;
        m_FootnotesXML = NULL;
    }

    if ( m_NumberingXML != NULL ) {
        delete m_NumberingXML;
        m_NumberingXML = NULL;
    }
    
    map<string,FZZFooterXML*>::const_iterator footerItr;
    for(footerItr = m_FooterXMLList.begin(); footerItr != m_FooterXMLList.end(); footerItr++) {
        if ( footerItr->second != NULL ) {
            delete footerItr->second;
        }
    } //for
    m_FooterXMLList.clear();
    
    map<string,FZZHeaderXML*>::const_iterator headerItr;
    for(headerItr = m_HeaderXMLList.begin(); headerItr != m_HeaderXMLList.end(); headerItr++) {
        if ( headerItr->second != NULL ) {
            delete headerItr->second;
        }
    } //for
    m_HeaderXMLList.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsDir * FZZWordDir::getRelsDir()
{
    if ( m_RelsDir != NULL ) {
        return m_RelsDir;
    }
    
    m_RelsDir = new FZZRelsDir(m_OFDFilesContainer,m_Root,m_Path+"_rels/");
    return m_RelsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeDir * FZZWordDir::getThemeDir()
{
    if ( m_ThemeDir != NULL ) {
        return m_ThemeDir;
    }
    
    m_ThemeDir = new FZZThemeDir(m_OFDFilesContainer,m_Root,m_Path+"theme/");
    return m_ThemeDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZMediaDir * FZZWordDir::getMediaDir()
{
    if ( m_MediaDir != NULL ) {
        return m_MediaDir;
    }
    
    m_MediaDir = new FZZMediaDir(m_OFDFilesContainer,m_Root,m_Path+"media/");
    return m_MediaDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXML * FZZWordDir::getDocumentXML()
{
    if ( m_DocumentXML != NULL ) {
        return m_DocumentXML;
    }
    
    XMLDocument * doc = getXMLDocument(DOCUMENTXML_FILENAME);
    if ( doc != NULL ) {
        m_DocumentXML = new FZZDocumentXML(doc);
        
    } else {
        m_DocumentXML = new FZZDocumentXML();
    }
  
    return m_DocumentXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontTableXML * FZZWordDir::getFontTableXML()
{
    if ( m_FontTableXML != NULL ) {
        return m_FontTableXML;
    }
    
    XMLDocument * doc = getXMLDocument(FONTTABLEXML_FILENAME);
    if ( doc != NULL ) {
        m_FontTableXML = new FZZFontTableXML(doc);
        
    } else {
        m_FontTableXML = new FZZFontTableXML();
    }
  
    return m_FontTableXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSettingsXML * FZZWordDir::getSettingsXML()
{
    if ( m_SettingsXML != NULL ) {
        return m_SettingsXML;
    }
    
    XMLDocument * doc = getXMLDocument(SETTINGSXML_FILENAME);
    if ( doc != NULL ) {
        m_SettingsXML = new FZZSettingsXML(doc);
        
    } else {
        m_SettingsXML = new FZZSettingsXML();
    }
  
    return m_SettingsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZStylesXML * FZZWordDir::getStylesXML()
{
    if ( m_StylesXML != NULL ) {
        return m_StylesXML;
    }
    
    XMLDocument * doc = getXMLDocument(STYLESXML_FILENAME);
    if ( doc != NULL ) {
        m_StylesXML = new FZZStylesXML(doc);
        
    } else {
        m_StylesXML = new FZZStylesXML();
    }
  
    return m_StylesXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWebSettingsXML * FZZWordDir::getWebSettingsXML()
{
    if ( m_WebSettingsXML != NULL ) {
        return m_WebSettingsXML;
    }
    
    XMLDocument * doc = getXMLDocument(WEBSETTINGSXML_FILENAME);
    if ( doc != NULL ) {
        m_WebSettingsXML = new FZZWebSettingsXML(doc);
        
    } else {
        m_WebSettingsXML = new FZZWebSettingsXML();
    }
  
    return m_WebSettingsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZEndnotesXML * FZZWordDir::getEndnotesXML()
{
    if ( m_EndnotesXML != NULL ) {
        return m_EndnotesXML;
    }
    
    XMLDocument * doc = getXMLDocument(ENDNOTESXML_FILENAME);
    if ( doc != NULL ) {
        m_EndnotesXML = new FZZEndnotesXML(doc);
        
    } else {
        m_EndnotesXML = new FZZEndnotesXML();
    }
  
    return m_EndnotesXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFootnotesXML * FZZWordDir::getFootnotesXML()
{
    if ( m_FootnotesXML != NULL ) {
        return m_FootnotesXML;
    }
    
    XMLDocument * doc = getXMLDocument(FOOTNOTESXML_FILENAME);
    if ( doc != NULL ) {
        m_FootnotesXML = new FZZFootnotesXML(doc);
        
    } else {
        m_FootnotesXML = new FZZFootnotesXML();
    }
  
    return m_FootnotesXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberingXML * FZZWordDir::getNumberingXML()
{
    if ( m_NumberingXML != NULL ) {
        return m_NumberingXML;
    }
    
    FZZRelsDir * relsDir = getRelsDir();
    if ( relsDir != NULL ) {
        FZZDocumentXMLRels* documentXMLRels = relsDir->getDocumentXMLRels();
        if ( documentXMLRels != NULL ) {
            vector<string> idList;
            vector<string> targetList;
            documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_NUMBERING, idList,targetList);
            
            vector<string>::const_iterator itr;
            for( itr = targetList.begin(); itr != targetList.end(); itr++ ) {
                string temp = *itr;
                if ( !temp.empty() ) {
                    XMLDocument * doc = getXMLDocument(temp);
                    if ( doc != NULL ) {
                        m_NumberingXML = new FZZNumberingXML(doc);
                    } else {
                        m_NumberingXML = new FZZNumberingXML();
                    }//if
                    break;
                }//if
            }//for
        }
    }
    
//    XMLDocument * doc = getXMLDocument(NUMBERINGXML_FILENAME);
//    if ( doc != NULL ) {
//        m_NumberingXML = new FZZNumberingXML(doc);
//
//    } else {
//        m_NumberingXML = new FZZNumberingXML();
//    }
  
    return m_NumberingXML;
}
//-----------------------------------------------------------------------------------------------------------------
map<string,FZZFooterXML *>* FZZWordDir::getFooterXMLList()
{
    if ( m_FooterXMLList.size() > 0 ) {
        return &m_FooterXMLList;
    }
    FZZRelsDir * relsDir = getRelsDir();
    if ( relsDir != NULL ) {
        FZZDocumentXMLRels* documentXMLRels = relsDir->getDocumentXMLRels();
        if ( documentXMLRels != NULL ) {
            vector<string> idList;
            vector<string> targetList;
            documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_FOOTER,idList, targetList);
            
            vector<string>::const_iterator itr;
            for( itr = targetList.begin(); itr != targetList.end(); itr++ ) {
                string temp = *itr;
                if ( !temp.empty() ) {
                    XMLDocument * doc = getXMLDocument(temp);
                    if ( doc != NULL ) {
                        FZZFooterXML* footerXml = new FZZFooterXML(doc);
                        if ( footerXml != NULL ) {
                            auto isExitPari = m_FooterXMLList.insert(pair<string,FZZFooterXML*>(temp,footerXml));
                            if ( !isExitPari.second ) {
                                delete footerXml;
                            }
                        }
            
                    }//if
                }//if
            }//for
            
        }//if
    }//if
    return &m_FooterXMLList;
}
//-----------------------------------------------------------------------------------------------------------------
map<string,FZZHeaderXML *>* FZZWordDir::getHeaderXMLList()
{
    if ( m_HeaderXMLList.size() > 0 ) {
        return &m_HeaderXMLList;
    }
    FZZRelsDir * relsDir = getRelsDir();
    if ( relsDir != NULL ) {
        FZZDocumentXMLRels* documentXMLRels = relsDir->getDocumentXMLRels();
        if ( documentXMLRels != NULL ) {
            vector<string> idList;
            vector<string> targetList;
            documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_HEADER, idList,targetList);
            
            vector<string>::const_iterator itr;
            for( itr = targetList.begin(); itr != targetList.end(); itr++ ) {
                string temp = *itr;
                if ( !temp.empty() ) {
                    XMLDocument * doc = getXMLDocument(temp);
                    if ( doc != NULL ) {
                        FZZHeaderXML* headerXml = new FZZHeaderXML(doc);
                        if ( headerXml != NULL ) {
                            auto isExitPari = m_HeaderXMLList.insert(pair<string,FZZHeaderXML*>(temp,headerXml));
                            if ( !isExitPari.second ) {
                                delete headerXml;
                            }
                        }
                    }//if
                }//if
            }//for
            
        }//if
    }//if
    return &m_HeaderXMLList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFooterXML * FZZWordDir::getFooterXML(string FileName)
{
    map<string,FZZFooterXML *>* footerXMLList = getFooterXMLList();
    if ( footerXMLList == NULL ) {
        return NULL;
    }
    FZZFooterXML * ret = NULL;
    map<string,FZZFooterXML*>::const_iterator footerItr;
    for(footerItr = footerXMLList->begin(); footerItr != footerXMLList->end(); footerItr++) {
        if ( footerItr->first == FileName && footerItr->second != NULL ) {
            ret = footerItr->second;
            break;
        }
    } //for
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZHeaderXML * FZZWordDir::getHeaderXML(string FileName)
{
    map<string,FZZHeaderXML *>* headerXMLList = getHeaderXMLList();
    if ( headerXMLList == NULL ) {
        return NULL;
    }
    FZZHeaderXML * ret = NULL;
    map<string,FZZHeaderXML*>::const_iterator headerItr;
    for(headerItr = headerXMLList->begin(); headerItr != headerXMLList->end(); headerItr++) {
        if ( headerItr->first == FileName && headerItr->second != NULL ) {
            ret = headerItr->second;
            break;
        }
    } //for
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFooterXML * FZZWordDir::addFooterXML()
{
    FZZRelsDir * relsDir = getRelsDir();
    if ( relsDir == NULL ) {
        return NULL;
    }
    
    FZZDocumentXMLRels* documentXMLRels = relsDir->getDocumentXMLRels();
    if ( documentXMLRels == NULL ) {
        return NULL;
    }
    
    FZZRelationship * ctRelationship = documentXMLRels->addRelationship();
    if ( ctRelationship == NULL ) {
        return NULL;
    }
    vector<string> idList;
    vector<string> targetList;
    documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_FOOTER, idList,targetList);
    
    string filename = "footer"+FZZConst::fmt(targetList.size()+1)+".xml";
    string id = documentXMLRels->getNexId();
    ctRelationship->setId(id);
    ctRelationship->setType(DOCUMENTXMLRELS_TYPE_FOOTER);
    ctRelationship->setTarget(filename);
    
    FZZFooterXML* footerXml = new FZZFooterXML();
    if ( footerXml != NULL ) {
        footerXml->setFileName(filename);
        auto isExitPari = m_FooterXMLList.insert(pair<string,FZZFooterXML*>(filename,footerXml));
        if ( !isExitPari.second ) {
            delete footerXml;
        }
    }
    return footerXml;
}
//-----------------------------------------------------------------------------------------------------------------
FZZHeaderXML * FZZWordDir::addHeaderXML()
{
    FZZRelsDir * relsDir = getRelsDir();
    if ( relsDir == NULL ) {
        return NULL;
    }
    
    FZZDocumentXMLRels* documentXMLRels = relsDir->getDocumentXMLRels();
    if ( documentXMLRels == NULL ) {
        return NULL;
    }
    
    FZZRelationship * ctRelationship = documentXMLRels->addRelationship();
    if ( ctRelationship == NULL ) {
        return NULL;
    }
    vector<string> idList;
    vector<string> targetList;
    documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_FOOTER, idList,targetList);
    
    string filename = "header"+FZZConst::fmt(targetList.size()+1)+".xml";
    string id = documentXMLRels->getNexId();
    ctRelationship->setId(id);
    ctRelationship->setType(DOCUMENTXMLRELS_TYPE_HEADER);
    ctRelationship->setTarget(filename);
    
    FZZHeaderXML* headerXML = new FZZHeaderXML();
    if ( headerXML != NULL ) {
        headerXML->setFileName(filename);
        auto isExitPari = m_HeaderXMLList.insert(pair<string,FZZHeaderXML*>(filename,headerXML));
        if ( !isExitPari.second ) {
            delete headerXML;
        }
    }
    
    return headerXML;
}
//-----------------------------------------------------------------------------------------------------------------
