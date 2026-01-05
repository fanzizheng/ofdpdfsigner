//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDDocDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir::FZZOFDDocDir() :FZZOFDBaseDir(),m_FZZOFDDocumentXML(NULL),m_FZZOFDPublicResXML(NULL),m_FZZOFDDocumentResXML(NULL)
,m_index(0),m_FZZOFDSignsDir(NULL),m_FZZOFDResDir(NULL),m_FZZOFDTagsDir(NULL),m_FZZOFDAnnotsDir(NULL),m_FZZOFDAttachsDir(NULL)
,m_FZZOFDExtensionsXML(NULL)
{
    //DLOG("FZZOFDDocDir()");
    FZZConst::addClassCount("FZZOFDDocDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir::FZZOFDDocDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_FZZOFDDocumentXML(NULL),m_FZZOFDPublicResXML(NULL),m_FZZOFDDocumentResXML(NULL),m_index(0),m_FZZOFDSignsDir(NULL)
,m_FZZOFDResDir(NULL),m_FZZOFDTagsDir(NULL),m_FZZOFDAnnotsDir(NULL),m_FZZOFDAttachsDir(NULL),m_FZZOFDExtensionsXML(NULL)
{
    FZZConst::addClassCount("FZZOFDDocDir");
    //Doc_0/
    setPath(path);
    
    m_index = getPathIndex(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir::~FZZOFDDocDir()
{
    //DLOG("~FZZOFDDocDir()");
    FZZConst::delClassCount("FZZOFDDocDir");
    if ( m_FZZOFDDocumentXML != NULL ) {
        delete m_FZZOFDDocumentXML;
        m_FZZOFDDocumentXML = NULL;
    }
    if ( m_FZZOFDPublicResXML != NULL ) {
        delete m_FZZOFDPublicResXML;
        m_FZZOFDPublicResXML = NULL;
    }
    if ( m_FZZOFDDocumentResXML != NULL ) {
        delete m_FZZOFDDocumentResXML;
        m_FZZOFDDocumentResXML = NULL;
    }
    if ( m_FZZOFDExtensionsXML != NULL ) {
        delete m_FZZOFDExtensionsXML;
        m_FZZOFDExtensionsXML = NULL;
    }
    
    if ( m_FZZOFDSignsDir != NULL ) {
        delete m_FZZOFDSignsDir;
        m_FZZOFDSignsDir = NULL;
    }
    if ( m_FZZOFDResDir != NULL ) {
        delete m_FZZOFDResDir;
        m_FZZOFDResDir = NULL;
    }
    if ( m_FZZOFDTagsDir != NULL ) {
        delete m_FZZOFDTagsDir;
        m_FZZOFDTagsDir = NULL;
    }
    if ( m_FZZOFDAnnotsDir != NULL ) {
        delete m_FZZOFDAnnotsDir;
        m_FZZOFDAnnotsDir = NULL;
    }
    if ( m_FZZOFDAttachsDir != NULL ) {
        delete m_FZZOFDAttachsDir;
        m_FZZOFDAttachsDir = NULL;
    }
    
    vector<FZZOFDTemplateDir*>::const_iterator tpl_itr;
    for( tpl_itr = m_FZZOFDTemplateDirList.begin(); tpl_itr != m_FZZOFDTemplateDirList.end(); tpl_itr++ ) {
        FZZOFDTemplateDir * temp = *tpl_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDTemplateDirList.clear();
    
    vector<FZZOFDPageDir*>::const_iterator page_itr;
    for( page_itr = m_FZZOFDPageDirList.begin(); page_itr != m_FZZOFDPageDirList.end(); page_itr++ ) {
        FZZOFDPageDir * temp = *page_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDPageDirList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML* FZZOFDDocDir::setDocumentXML()
{
    getDocumentXML();
    if ( m_FZZOFDDocumentXML == NULL ) {
        m_FZZOFDDocumentXML = new FZZOFDDocumentXML();
    }
    return m_FZZOFDDocumentXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicResXML* FZZOFDDocDir::setPublicResXML()
{
    getPublicResXML();
    if ( m_FZZOFDPublicResXML == NULL ) {
        m_FZZOFDPublicResXML = new FZZOFDPublicResXML();
        FZZOFDDocumentXML* docXml = getDocumentXML();
        if ( m_FZZOFDPublicResXML != NULL && docXml != NULL ) {
            FZZOFDCommonData * commonData = docXml->setCommonData();
            if ( commonData != NULL ) {
                FZZOFDPublicRes * pubRes = commonData->setPublicRes();
                if ( pubRes != NULL ) {
                    pubRes->setValue(FZZOFDPUBLICRESXML_FILENAME);
                    m_FZZOFDPublicResXML->setBaseLoc("Res");
                }
            }
        }
    }
    return m_FZZOFDPublicResXML;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentResXML* FZZOFDDocDir::setDocumentResXML()
{
    getDocumentResXML();
    if ( m_FZZOFDDocumentResXML == NULL ) {
        m_FZZOFDDocumentResXML = new FZZOFDDocumentResXML();
        FZZOFDDocumentXML* docXml = getDocumentXML();
        if ( m_FZZOFDDocumentResXML != NULL && docXml != NULL ) {
            FZZOFDCommonData * commonData = docXml->setCommonData();
            if ( commonData != NULL ) {
                FZZOFDDocumentRes * docRes = commonData->setDocumentRes();
                if ( docRes != NULL ) {
                    docRes->setValue(FZZOFDDOCUMENTRESXML_FILENAME);
                    m_FZZOFDDocumentResXML->setBaseLoc("Res");
                }
            }
        }
    }
    return m_FZZOFDDocumentResXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtensionsXML* FZZOFDDocDir::setExtensionsXML()
{
    getExtensionsXML();
    if ( m_FZZOFDExtensionsXML == NULL ) {
        FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
        if ( ofdDocumentXML != NULL ) {
            //暂时没有考虑m_FZZOFDExtensionsXML 的存储
            m_FZZOFDExtensionsXML = new FZZOFDExtensionsXML();
            FZZOFDDocument_Extensions * ofdDocument_Extensions = ofdDocumentXML->setExtensions();
            ofdDocument_Extensions->setValue("Res/" FZZOFDEXTENSIONSXML_FILENAME);
        }
    }
    return m_FZZOFDExtensionsXML;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML* FZZOFDDocDir::getDocumentXML()
{
    if ( m_FZZOFDDocumentXML != NULL ) {
        return m_FZZOFDDocumentXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDDOCUMENTXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDDocumentXML = new FZZOFDDocumentXML(doc);
    }
    return m_FZZOFDDocumentXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicResXML* FZZOFDDocDir::getPublicResXML()
{
    if ( m_FZZOFDPublicResXML != NULL ) {
        return m_FZZOFDPublicResXML;
    }
    
    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML == NULL ) {
        return m_FZZOFDPublicResXML;
    }
    FZZOFDCommonData * ofdCommonData = ofdDocumentXML->getCommonData();
    if ( ofdCommonData == NULL ) {
        return m_FZZOFDPublicResXML;
    }
    
    FZZOFDPublicRes * PublicRes = ofdCommonData->getPublicRes();
    if ( PublicRes == NULL ) {
        return m_FZZOFDPublicResXML;
    }
    string filename = PublicRes->getValue();
    if ( filename.empty() ) {
        return m_FZZOFDPublicResXML;
    }

    //XMLDocument * doc = getXMLDocument(FZZOFDPUBLICRESXML_FILENAME);
    XMLDocument * doc = getXMLDocument(filename);
    if ( doc != NULL ) {
        m_FZZOFDPublicResXML = new FZZOFDPublicResXML(doc);
    }
    return m_FZZOFDPublicResXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentResXML* FZZOFDDocDir::getDocumentResXML()
{
    if ( m_FZZOFDDocumentResXML != NULL ) {
        return m_FZZOFDDocumentResXML;
    }

    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML == NULL ) {
        return m_FZZOFDDocumentResXML;
    }
    FZZOFDCommonData * ofdCommonData = ofdDocumentXML->getCommonData();
    if ( ofdCommonData == NULL ) {
        return m_FZZOFDDocumentResXML;
    }
    
    FZZOFDDocumentRes * documentRes = ofdCommonData->getDocumentRes();
    if ( documentRes == NULL ) {
        return m_FZZOFDDocumentResXML;
    }
    string filename = documentRes->getValue();
    if ( filename.empty() ) {
        return m_FZZOFDDocumentResXML;
    }

    //XMLDocument * doc = getXMLDocument(FZZOFDDOCUMENTRESXML_FILENAME);
    XMLDocument * doc = getXMLDocument(filename);
    if ( doc != NULL ) {
        m_FZZOFDDocumentResXML = new FZZOFDDocumentResXML(doc);
    }
    return m_FZZOFDDocumentResXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignsDir * FZZOFDDocDir::getSignsDir()
{
    if ( m_FZZOFDSignsDir != NULL ) {
        return m_FZZOFDSignsDir;
    }
    
    m_FZZOFDSignsDir = new FZZOFDSignsDir(m_OFDFilesContainer,m_Root,m_Path+"Signs/");
    return m_FZZOFDSignsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignsDir * FZZOFDDocDir::getSignsDir(string path)
{
    if ( m_FZZOFDSignsDir != NULL ) {
        if ( m_FZZOFDSignsDir->getPath() == path ) {
            return m_FZZOFDSignsDir;
        } else {
            delete m_FZZOFDSignsDir;
            m_FZZOFDSignsDir = NULL;
        }
    }
    
    m_FZZOFDSignsDir = new FZZOFDSignsDir(m_OFDFilesContainer,m_Root,path);
    return m_FZZOFDSignsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResDir * FZZOFDDocDir::getResDir()
{
    if ( m_FZZOFDResDir != NULL ) {
        return m_FZZOFDResDir;
    }
    string respath = "Res";
    FZZOFDPublicResXML* ofdPublicResXML = getPublicResXML();
    FZZOFDDocumentResXML* ofdDocumentResXML = getDocumentResXML();
    if ( ofdDocumentResXML != NULL ) {
        string temprespath = ofdDocumentResXML->getBaseLoc();
        if ( !temprespath.empty() ) {
            respath = temprespath;
        }
    }
    
    if ( ofdPublicResXML != NULL ) {
        string temprespath = ofdPublicResXML->getBaseLoc();
        if ( !temprespath.empty() ) {
            
            temprespath = FZZConst::replace_all(temprespath,"\\","/");
            if ( temprespath[0] == '/' ) {
                temprespath = temprespath.substr(1);
                
            }
            size_t rootpos = temprespath.find(m_Path);
            if ( rootpos != string::npos ) {
                temprespath = temprespath.substr(rootpos+m_Path.length());
            }
            if ( !temprespath.empty() ) {
                respath = temprespath;
            }
        }
    }
    
    m_FZZOFDResDir = new FZZOFDResDir(m_OFDFilesContainer,m_Root,m_Path+respath+"/");
    return m_FZZOFDResDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTagsDir * FZZOFDDocDir::getTagsDir()
{
    if ( m_FZZOFDTagsDir != NULL ) {
        return m_FZZOFDTagsDir;
    }
    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML != NULL ) {
        
        
        FZZOFDDocument_CustomTags * ofdDocument_Annotations = ofdDocumentXML->getCustomTags();
        if ( ofdDocument_Annotations != NULL ) {
            
        
            //Annots/Annotations.xml or  Annotations.xml
            string strAnnotationsXML_FileName = ofdDocument_Annotations->getValue();
            strAnnotationsXML_FileName = FZZConst::replace_all(strAnnotationsXML_FileName,"\\","/");
            if ( strAnnotationsXML_FileName[0] == '/' ) {
                //strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(1);
                size_t rootpos = strAnnotationsXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            size_t pos = strAnnotationsXML_FileName.find_last_of("/");
            if ( pos != string::npos ) {
                m_FZZOFDTagsDir = new FZZOFDTagsDir(m_OFDFilesContainer,m_Root,m_Path+strAnnotationsXML_FileName.substr(0, pos + 1));
            } else {
                m_FZZOFDTagsDir = new FZZOFDTagsDir(m_OFDFilesContainer,m_Root,m_Path);
            }
            return m_FZZOFDTagsDir;
        }
    }
    m_FZZOFDTagsDir = new FZZOFDTagsDir(m_OFDFilesContainer,m_Root,m_Path+"Tags/");
    return m_FZZOFDTagsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplateDir * FZZOFDDocDir::addTemplateDir()
{
    getTemplateList();
    FZZOFDTemplateDir * ofdTemplateDir = new FZZOFDTemplateDir(m_OFDFilesContainer,m_Root,m_Path + "Tpls/Tpl_" + FZZConst::fmt((int)m_FZZOFDTemplateDirList.size())+"/");
    if ( ofdTemplateDir != NULL ) {
        m_FZZOFDTemplateDirList.push_back(ofdTemplateDir);
    }
    return ofdTemplateDir;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDTemplateDir *> * FZZOFDDocDir::getTemplateList()
{
    if ( m_FZZOFDTemplateDirList.size() <= 0 ) {
        FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
        if ( ofdDocumentXML == NULL ) {
            goto err;
        }
        FZZOFDCommonData * ofdCommonData = ofdDocumentXML->getCommonData();
        if ( ofdCommonData == NULL ) {
            goto err;
        }
        vector<FZZOFDTemplatePage*> * ofdTemplatePageList = ofdCommonData->getTemplatePageList();
        if ( ofdTemplatePageList == NULL || ofdTemplatePageList->size() <= 0 ) {
            goto err;
        }
       
        vector<FZZOFDTemplatePage*>::const_iterator tpl_itr;
        for( tpl_itr = ofdTemplatePageList->begin(); tpl_itr != ofdTemplatePageList->end(); tpl_itr++ ) {
            FZZOFDTemplatePage * templatePage = *tpl_itr;
            if ( templatePage == NULL ) {
                continue;
            }
            //Tpls/Tpl_0/Content.xml
            string strContentXML_FileName = templatePage->getBaseLoc();
            
                
            strContentXML_FileName = FZZConst::replace_all(strContentXML_FileName,"\\","/");
            if ( strContentXML_FileName[0] == '/' ) {
                //strContentXML_FileName = strContentXML_FileName.substr(1);
                size_t rootpos = strContentXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strContentXML_FileName = strContentXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            size_t pos = strContentXML_FileName.find_last_of("/");
            if ( pos != string::npos ) {
                FZZOFDTemplateDir * ofdTemplateDir = new FZZOFDTemplateDir(m_OFDFilesContainer,m_Root,m_Path+strContentXML_FileName.substr(0, pos + 1));
                
                if ( ofdTemplateDir != NULL ) {
                    m_FZZOFDTemplateDirList.push_back(ofdTemplateDir);
                }//if ( ofdTemplateDir != NULL )
            }
                
                
            
            
        }//for
    }
err:
    return &m_FZZOFDTemplateDirList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplateDir * FZZOFDDocDir::getTemplateDir(string strId)
{
    getTemplateList();
    FZZOFDTemplateDir * retDir = NULL;
    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML == NULL ) {
        return retDir;
    }
    FZZOFDCommonData * ofdCommonData = ofdDocumentXML->getCommonData();
    if ( ofdCommonData == NULL ) {
        return retDir;
    }
    vector<FZZOFDTemplatePage*> * ofdTemplatePageList = ofdCommonData->getTemplatePageList();
    if ( ofdTemplatePageList == NULL || ofdTemplatePageList->size() <= 0 ) {
        return retDir;
    }
   
    vector<FZZOFDTemplatePage*>::const_iterator tpl_itr;
    for( tpl_itr = ofdTemplatePageList->begin(); tpl_itr != ofdTemplatePageList->end(); tpl_itr++ ) {
        FZZOFDTemplatePage * templatePage = *tpl_itr;
        if ( templatePage == NULL ) {
            continue;
        }
        if ( templatePage->getID() != strId ) {
            continue;
        }
        //Tpls/Tpl_0/Content.xml
        string strContentXML_FileName = templatePage->getBaseLoc();
        
            
        strContentXML_FileName = FZZConst::replace_all(strContentXML_FileName,"\\","/");
        if ( strContentXML_FileName[0] == '/' ) {
            //strContentXML_FileName = strContentXML_FileName.substr(1);
            size_t rootpos = strContentXML_FileName.find(m_Path);
            if ( rootpos != string::npos ) {
                strContentXML_FileName = strContentXML_FileName.substr(rootpos+m_Path.length());
            }
        }
        size_t pos = strContentXML_FileName.find_last_of("/");
        if ( pos != string::npos ) {
            strContentXML_FileName = m_Path+strContentXML_FileName.substr(0, pos + 1);
            
            
        } else {
            strContentXML_FileName = m_Path+strContentXML_FileName;
        }
        
        vector<FZZOFDTemplateDir *>::const_iterator itr;
        for( itr = m_FZZOFDTemplateDirList.begin(); itr != m_FZZOFDTemplateDirList.end(); itr++ ) {
            FZZOFDTemplateDir * tdir = *itr;
            if ( tdir == NULL ) {
                continue;
            }
            if ( tdir->getPath() == strContentXML_FileName) {
                retDir = tdir;
                break;
            }
        }
        break;
            
        
        
    }//for
    return retDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageDir * FZZOFDDocDir::addPageDir()
{
    getPageDirList();
    FZZOFDPageDir * ofdPageDir = NULL;
    if ( m_FZZOFDPageDirList.size() <= 0 ) {
        ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path + "Pages/Page_0/");
    } else {
        FZZOFDPageDir * ofdPageDir_last = *(m_FZZOFDPageDirList.begin()+m_FZZOFDPageDirList.size()-1);
        if ( ofdPageDir_last == NULL ) {
            ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path + "Pages/Page_" + FZZConst::fmt((int)m_FZZOFDPageDirList.size())+"/");
        } else {
            string path = ofdPageDir_last->getPath();
            size_t pos = path.find("Page_");
            if ( pos != string::npos ) {
                path = path.substr(0,pos+5);
            }
            ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,path + FZZConst::fmt((int)m_FZZOFDPageDirList.size())+"/");
        }
    }
    if ( ofdPageDir != NULL ) {
        m_FZZOFDPageDirList.push_back(ofdPageDir);
    }
    return ofdPageDir;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPageDir *> * FZZOFDDocDir::getPageDirList()
{
    if ( m_FZZOFDPageDirList.size() <= 0 ) {
        FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
        if ( ofdDocumentXML == NULL ) {
            goto err;
        }
        FZZOFDPages * ofdPages = ofdDocumentXML->getPages();
        if ( ofdPages == NULL ) {
            goto err;
        }
        vector<FZZOFDPageElem*> * ofdPageList = ofdPages->getPageList();
        if ( ofdPageList == NULL || ofdPageList->size() <= 0 ) {
            goto err;
        }
       
        vector<FZZOFDPageElem*>::const_iterator p_itr;
        for( p_itr = ofdPageList->begin(); p_itr != ofdPageList->end(); p_itr++ ) {
            FZZOFDPageElem * ofdPage = *p_itr;
            if ( ofdPage == NULL ) {
                continue;
            }
            //Pages/Page_0/Content.xml
            string strContentXML_FileName = ofdPage->getBaseLoc();
            
                
            strContentXML_FileName = FZZConst::replace_all(strContentXML_FileName,"\\","/");
            if ( strContentXML_FileName[0] == '/' ) {
                //strContentXML_FileName = strContentXML_FileName.substr(1);
                size_t rootpos = strContentXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strContentXML_FileName = strContentXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            size_t pos = strContentXML_FileName.find_last_of("/");
            if ( pos != string::npos ) {
                FZZOFDPageDir * ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path+strContentXML_FileName.substr(0, pos + 1));
                ofdPageDir->setPageId(ofdPage->getID());
                if ( ofdPageDir != NULL ) {
                    m_FZZOFDPageDirList.push_back(ofdPageDir);
                }//if ( ofdTemplateDir != NULL )
            }
                
                
            
            
        }//for
    }
err:
    return &m_FZZOFDPageDirList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotsDir * FZZOFDDocDir::getAnnotsDir()
{
    if ( m_FZZOFDAnnotsDir != NULL ) {
        return m_FZZOFDAnnotsDir;
    }
    
    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML != NULL ) {
        
    
        FZZOFDDocument_Annotations * ofdDocument_Annotations = ofdDocumentXML->getAnnotations();
        if ( ofdDocument_Annotations != NULL ) {
            
        
            //Annots/Annotations.xml or  Annotations.xml
            string strAnnotationsXML_FileName = ofdDocument_Annotations->getValue();
            strAnnotationsXML_FileName = FZZConst::replace_all(strAnnotationsXML_FileName,"\\","/");
            if ( strAnnotationsXML_FileName[0] == '/' ) {
                //strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(1);
                size_t rootpos = strAnnotationsXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            size_t pos = strAnnotationsXML_FileName.find_last_of("/");
            if ( pos != string::npos ) {
                m_FZZOFDAnnotsDir = new FZZOFDAnnotsDir(m_OFDFilesContainer,m_Root,m_Path+strAnnotationsXML_FileName.substr(0, pos + 1));
            } else {
                m_FZZOFDAnnotsDir = new FZZOFDAnnotsDir(m_OFDFilesContainer,m_Root,m_Path);
            }
            return m_FZZOFDAnnotsDir;
        }
    }

    m_FZZOFDAnnotsDir = new FZZOFDAnnotsDir(m_OFDFilesContainer,m_Root,m_Path+"Annots/");
    return m_FZZOFDAnnotsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachsDir * FZZOFDDocDir::getAttachsDir()
{
    if ( m_FZZOFDAttachsDir != NULL ) {
        return m_FZZOFDAttachsDir;
    }
    
    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML != NULL ) {
        
        FZZOFDDocument_Attachments * ofdDocument_Attachments = ofdDocumentXML->getAttachments();
        if ( ofdDocument_Attachments != NULL ) {
            //Attachs/Attachments.xml or  Attachments.xml
            string strAnnotationsXML_FileName = ofdDocument_Attachments->getValue();
            strAnnotationsXML_FileName = FZZConst::replace_all(strAnnotationsXML_FileName,"\\","/");
            if ( strAnnotationsXML_FileName[0] == '/' ) {
                //strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(1);
                size_t rootpos = strAnnotationsXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            size_t pos = strAnnotationsXML_FileName.find_last_of("/");
            if ( pos != string::npos ) {
                m_FZZOFDAttachsDir = new FZZOFDAttachsDir(m_OFDFilesContainer,m_Root,m_Path+strAnnotationsXML_FileName.substr(0, pos + 1));
            } else {
                m_FZZOFDAttachsDir = new FZZOFDAttachsDir(m_OFDFilesContainer,m_Root,m_Path);
            }
            return m_FZZOFDAttachsDir;
        }
    }

    m_FZZOFDAttachsDir = new FZZOFDAttachsDir(m_OFDFilesContainer,m_Root,m_Path+"Attachs/");
    return m_FZZOFDAttachsDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtensionsXML* FZZOFDDocDir::getExtensionsXML()
{
    if ( m_FZZOFDExtensionsXML != NULL ) {
        return m_FZZOFDExtensionsXML;
    }
    
    FZZOFDDocumentXML* ofdDocumentXML = getDocumentXML();
    if ( ofdDocumentXML != NULL ) {
        FZZOFDDocument_Extensions * ofdDocument_Extensions = ofdDocumentXML->getExtensions();
        if ( ofdDocument_Extensions != NULL ) {
            //Res/Extensions.xml
            string strAnnotationsXML_FileName = ofdDocument_Extensions->getValue();
            strAnnotationsXML_FileName = FZZConst::replace_all(strAnnotationsXML_FileName,"\\","/");
            if ( strAnnotationsXML_FileName[0] == '/' ) {
                //strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(1);
                size_t rootpos = strAnnotationsXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strAnnotationsXML_FileName = strAnnotationsXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            XMLDocument * doc = getXMLDocument(strAnnotationsXML_FileName);
            if ( doc != NULL ) {
                m_FZZOFDExtensionsXML = new FZZOFDExtensionsXML(doc);

            }
            
        } else {
            XMLDocument * doc = getXMLDocument("Res/" FZZOFDEXTENSIONSXML_FILENAME);
            if ( doc != NULL ) {
                m_FZZOFDExtensionsXML = new FZZOFDExtensionsXML(doc);
            }
        }
    }

    
    

    return m_FZZOFDExtensionsXML;
}
//-----------------------------------------------------------------------------------------------------------------
