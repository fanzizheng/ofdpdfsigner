//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDDir.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDir::FZZOFDDir() : FZZOFDBaseDir(),m_OFDXML(NULL),m_FZZOFDEntriesXML(NULL),m_FZZOFDEncryptionsXML(NULL)
{
    //DLOG("FZZOFDDir()");
    FZZConst::addClassCount("FZZOFDDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDir::FZZOFDDir(FZZOFDFilesContainer* filesContainer,string Root) : FZZOFDBaseDir(filesContainer,Root),m_OFDXML(NULL),m_FZZOFDEntriesXML(NULL),m_FZZOFDEncryptionsXML(NULL)
{
    FZZConst::addClassCount("FZZOFDDir");
    setPath("");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDir::~FZZOFDDir()
{
    //DLOG("~FZZOFDDir()");
    FZZConst::delClassCount("FZZOFDDir");
    if ( m_OFDXML != NULL ) {
        delete m_OFDXML;
        m_OFDXML = NULL;
    }
    
    if ( m_FZZOFDEntriesXML != NULL ) {
        delete m_FZZOFDEntriesXML;
        m_FZZOFDEntriesXML = NULL;
    }
    
    if ( m_FZZOFDEncryptionsXML != NULL ) {
        delete m_FZZOFDEncryptionsXML;
        m_FZZOFDEncryptionsXML = NULL;
    }
    
    vector<FZZOFDDocDir*>::const_iterator itr;
    for( itr = m_FZZOFDDocDirList.begin(); itr != m_FZZOFDDocDirList.end(); itr++ ) {
        FZZOFDDocDir * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDDocDirList.clear();

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML* FZZOFDDir::getOFDXML()
{
    if ( m_OFDXML != NULL ) {
        return m_OFDXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDXML_FILENAME);
    if ( doc != NULL ) {
        m_OFDXML = new FZZOFDXML(doc);

    }

    return m_OFDXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML* FZZOFDDir::setOFDXML()
{
    getOFDXML();
    if ( m_OFDXML == NULL ) {
        m_OFDXML = new FZZOFDXML();
    }
    return m_OFDXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML* FZZOFDDir::getEntriesXML()
{
    if ( m_FZZOFDEntriesXML != NULL ) {
        return m_FZZOFDEntriesXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDENTRIESXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDEntriesXML = new FZZOFDEntriesXML(doc);

    }

    return m_FZZOFDEntriesXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML* FZZOFDDir::setEntriesXML()
{
    getEntriesXML();
    if ( m_FZZOFDEntriesXML == NULL ) {
        m_FZZOFDEntriesXML = new FZZOFDEntriesXML();
    }
    return m_FZZOFDEntriesXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptionsXML* FZZOFDDir::getEncryptionsXML()
{
    if ( m_FZZOFDEncryptionsXML != NULL ) {
        return m_FZZOFDEncryptionsXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDENCRYPTIONSXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDEncryptionsXML = new FZZOFDEncryptionsXML(doc);

    }

    return m_FZZOFDEncryptionsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptionsXML* FZZOFDDir::setEncryptionsXML()
{
    getEncryptionsXML();
    if ( m_FZZOFDEncryptionsXML == NULL ) {
        m_FZZOFDEncryptionsXML = new FZZOFDEncryptionsXML();
    }
    return m_FZZOFDEncryptionsXML;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDir::FlushAll()
{
    vector<FZZOFDDocDir*>::const_iterator itr;
    for( itr = m_FZZOFDDocDirList.begin(); itr != m_FZZOFDDocDirList.end(); itr++ ) {
        FZZOFDDocDir * docDir = *itr;
        if ( docDir != NULL ) {
            docDir->FlushXMLObject(docDir->getDocumentXML());
            docDir->FlushXMLObject(docDir->getPublicResXML());
            docDir->FlushXMLObject(docDir->getDocumentResXML());
            docDir->FlushXMLObject(docDir->getExtensionsXML());
            FZZOFDSignsDir * SignsDir = docDir->getSignsDir();
            if ( SignsDir != NULL ) {
                SignsDir->FlushXMLObject(SignsDir->getSignaturesXML());
                vector<FZZOFDSignDir *>* signDirList =  SignsDir->getSignDirList();
                if ( signDirList != NULL && signDirList->size() > 0 ) {
                    vector<FZZOFDSignDir*>::const_iterator signDiritr;
                    for( signDiritr = signDirList->begin(); signDiritr != signDirList->end(); signDiritr++ ) {
                        FZZOFDSignDir * signDir = *signDiritr;
                        if ( signDir != NULL ) {
                            signDir->FlushXMLObject(signDir->getSignatureXML());
                            
                        }
                    }
                }//if ( signDirList != NULL && signDirList->size() > 0 )
            }//if ( SignsDir != NULL )
            FZZOFDTagsDir * tagsDir = docDir->getTagsDir();
            if ( tagsDir != NULL ) {
                tagsDir->FlushXMLObject(tagsDir->getCustomTagsXML());
            }
            vector<FZZOFDTemplateDir *> * templateDirList = docDir->getTemplateList();
            if ( templateDirList != NULL && templateDirList->size() > 0 ) {
                vector<FZZOFDTemplateDir*>::const_iterator templateDiritr;
                for( templateDiritr = templateDirList->begin(); templateDiritr != templateDirList->end(); templateDiritr++ ) {
                    FZZOFDTemplateDir * templateDir = *templateDiritr;
                    if ( templateDir != NULL ) {
                        templateDir->FlushXMLObject(templateDir->getPageXML());
                    }
                }
            }
            vector<FZZOFDPageDir *> * pageDirList = docDir->getPageDirList();
            if ( pageDirList != NULL && pageDirList->size() > 0 ) {
                vector<FZZOFDPageDir*>::const_iterator pageDiritr;
                for( pageDiritr = pageDirList->begin(); pageDiritr != pageDirList->end(); pageDiritr++ ) {
                    FZZOFDPageDir * pageDir = *pageDiritr;
                    if ( pageDir != NULL ) {
                        pageDir->FlushXMLObject(pageDir->getPageXML());
                        pageDir->FlushXMLObject(pageDir->getPageResXML());
                        pageDir->FlushXMLObject(pageDir->getAnnotationXML());
                    }
                }
            }
            FZZOFDAnnotsDir * annotsDir = docDir->getAnnotsDir();
            if ( annotsDir != NULL ) {
                annotsDir->FlushXMLObject(annotsDir->getAnnotationsXML());
                vector<FZZOFDPageDir *> * annotPageDirList = annotsDir->getPageDirList();
                if ( annotPageDirList != NULL && annotPageDirList->size() > 0 ) {
                    vector<FZZOFDPageDir*>::const_iterator annotPageDiritr;
                    for( annotPageDiritr = annotPageDirList->begin(); annotPageDiritr != annotPageDirList->end(); annotPageDiritr++ ) {
                        FZZOFDPageDir * annotPageDir = *annotPageDiritr;
                        if ( annotPageDir != NULL ) {
                            annotPageDir->FlushXMLObject(annotPageDir->getPageXML());
                            annotPageDir->FlushXMLObject(annotPageDir->getPageResXML());
                            annotPageDir->FlushXMLObject(annotPageDir->getAnnotationXML());
                        }
                    }
                }
            }
            FZZOFDAttachsDir * attachsDir = docDir->getAttachsDir();
            if ( attachsDir != NULL ) {
                attachsDir->FlushXMLObject(attachsDir->getAttachmentsXML());
            }
        }//if ( docDir != NULL ) {
    }
    
    FZZOFDXML* OFDXML = getOFDXML();
    FlushXMLObject(OFDXML);
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDir::FlushEntriesXML()
{
    FZZOFDEntriesXML* OFDEntriesXML = getEntriesXML();
    if ( OFDEntriesXML != NULL ) {
        FlushXMLObject(OFDEntriesXML);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDir::FlushEncryptionsXML()
{
    FZZOFDEncryptionsXML* OFDEncryptionsXML = getEncryptionsXML();
    if ( OFDEncryptionsXML != NULL ) {
        FlushXMLObject(OFDEncryptionsXML);
    }
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDDocDir *> * FZZOFDDir::getDocDirList()
{
    if ( m_FZZOFDDocDirList.size() <= 0 ) {
        FZZOFDXML* ofdXml = getOFDXML();
        if ( ofdXml == NULL ) {
            goto err;
        }
        vector<FZZOFDDocBody*>* docBodyList = ofdXml->getDocBodys();
        if ( docBodyList == NULL || docBodyList->size() <= 0 ) {
            goto err;
        }
       
        vector<FZZOFDDocBody*>::const_iterator docbody_itr;
        for( docbody_itr = docBodyList->begin(); docbody_itr != docBodyList->end(); docbody_itr++ ) {
            FZZOFDDocBody * docBody = *docbody_itr;
            if ( docBody == NULL ) {
                continue;
            }
            FZZOFDDocRoot * docRoot = docBody->getDocRoot();
            if ( docRoot != NULL ) {
                //Doc_0/Document.xml
                string strDocumentXml_FileName = docRoot->getValue();
                strDocumentXml_FileName = FZZConst::replace_all(strDocumentXml_FileName,"\\","/");
                if ( strDocumentXml_FileName[0] == '/' ) {
                    strDocumentXml_FileName = strDocumentXml_FileName.substr(1);
//                    size_t rootpos = strDocumentXml_FileName.find(m_Path);
//                    if ( rootpos != string::npos ) {
//                        strDocumentXml_FileName = strDocumentXml_FileName.substr(rootpos+m_Path.length());
//                    }
                }
                size_t pos = strDocumentXml_FileName.find_last_of("/");
                if ( pos != string::npos ) {
                    FZZOFDDocDir * cofdDocDir = new FZZOFDDocDir(m_OFDFilesContainer,m_Root,m_Path+strDocumentXml_FileName.substr(0, pos + 1));
                    if ( cofdDocDir != NULL ) {
                        m_FZZOFDDocDirList.push_back(cofdDocDir);
                        
                        FZZOFDDocBody_Signatures * signatures = docBody->getSignatures();
                        if ( signatures != NULL ) {
                            string strSignaturesXml_FileName = signatures->getValue();
                            if ( strSignaturesXml_FileName[0] == '/' ) {
                                strSignaturesXml_FileName = strSignaturesXml_FileName.substr(1);
//                                size_t rootpos = strSignaturesXml_FileName.find(m_Path);
//                                if ( rootpos != string::npos ) {
//                                    strSignaturesXml_FileName = strSignaturesXml_FileName.substr(rootpos+m_Path.length());
//                                }
                            }
                            pos = strSignaturesXml_FileName.find_last_of("/");
                            if ( pos != string::npos ) {
                                cofdDocDir->getSignsDir(m_Path+strSignaturesXml_FileName.substr(0, pos + 1));
                            } else {
                                cofdDocDir->getSignsDir();
                            }
                        }//if ( signatures != NULL )
                    }//if ( cofdDocDir != NULL )
                }
                
                
            }//docRoot != NULL
            
        }//for
    }
err:
    return &m_FZZOFDDocDirList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir * FZZOFDDir::getDocDir_default()
{
    getDocDirList();
    FZZOFDDocDir * docDir = NULL;
    if ( m_FZZOFDDocDirList.size() > 0 ) {
        docDir = *(m_FZZOFDDocDirList.begin());
    }
    return docDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir * FZZOFDDir::setDocDir_default()
{
    FZZOFDDocDir * cofdDocDir = getDocDir_default();
    if ( cofdDocDir == NULL ) {
        FZZOFDXML* ofdXML = setOFDXML();
        if ( ofdXML == NULL ) {
            return cofdDocDir;
        }
        FZZOFDDocBody* docBody = ofdXML->getDocBody_default();
        if ( docBody == NULL ) {
            docBody = ofdXML->addDocBody();
        }
        if ( docBody != NULL ) {
            FZZOFDDocRoot * docRoot = docBody->setDocRoot();
            if ( docRoot == NULL ) {
                return cofdDocDir;
            }
            FZZOFDDocInfo * docInfo = docBody->setDocInfo();
            if ( docInfo == NULL ) {
                return cofdDocDir;
            }
            
            FZZOFDDocID * docID = docInfo->setDocID();
            if ( docID != NULL ) {
                char uuid[37];
                string strdocid = random_uuid(uuid);
                strdocid = FZZConst::replace_all(strdocid, "-","");
                docID->setValue(strdocid.c_str());
            }
            FZZOFDCreationDate * creationDate = docInfo->setCreationDate();
            if ( creationDate != NULL ) {
                time_t createDate;
                time(&createDate);
                creationDate->setValue(FZZConst::format_time_YYYY_MM_DD(createDate));
            }
            FZZOFDCreator * ofdCreator = docInfo->setCreator();
            if ( ofdCreator != NULL ) {
                ofdCreator->setValue(OFD_CREATOR);
            }
            FZZOFDCreatorVersion * creatorVersion = docInfo->setCreatorVersion();
            if ( creatorVersion != NULL ) {
                creatorVersion->setValue(OFD_VERSION);
            }
            
            cofdDocDir = new FZZOFDDocDir(m_OFDFilesContainer,m_Root,m_Path+"Doc_0/");
            if ( cofdDocDir != NULL ) {
                m_FZZOFDDocDirList.push_back(cofdDocDir);
                docRoot->setValue(cofdDocDir->getPath()+FZZOFDDOCUMENTXML_FILENAME);
            }
            
            FZZOFDDocumentXML* docXML = cofdDocDir->setDocumentXML();
            if (docXML == NULL) {
                return cofdDocDir;
            }
            FZZOFDCommonData * commonData = docXML->setCommonData();
            if (commonData == NULL) {
                return cofdDocDir;
            }
            FZZOFDPageArea * pageArea = commonData->setPageArea();
            if (pageArea == NULL) {
                return cofdDocDir;
            }
            FZZOFDPhysicalBox * physicalBox = pageArea->setPhysicalBox();
            if (physicalBox == NULL) {
                return cofdDocDir;
            }
            physicalBox->setValue(PAGE_SIZE_A4);
        }
        
    }
    return cofdDocDir;
}
//-----------------------------------------------------------------------------------------------------------------

