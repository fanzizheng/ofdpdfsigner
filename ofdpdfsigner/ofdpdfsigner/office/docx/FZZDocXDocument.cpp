//
//  Created by zizheng fan on 2023/04/03.
//
#include "basic/FZZConst.h"
#include "office/docx/FZZDocXDocument.h"
#include "basic/FZZZipTracks.h"
#include "basic/FZZOFDFilesContainer.h"
#include "office/docx/FZZDocXConst.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZDocXDocument**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZDocXDocument::FZZDocXDocument()
{
    //DLOG("FZZDocXDocument()");
    FZZConst::addClassCount("FZZDocXDocument");
    m_workDir = FZZConst::createuuid();
    m_DocXDir = new FZZDocXDir(&m_OFDFilesContainer,m_workDir);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZDocXDocument::~FZZDocXDocument()
{
    //DLOG("~FZZDocXDocument()");
    FZZConst::delClassCount("FZZDocXDocument");
    if ( m_DocXDir != NULL ) {
        delete m_DocXDir;
        m_DocXDir = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZDocXDocument::Read(FZZBytes & indata)
{
    m_workDir = FZZConst::createuuid();
    if ( m_workDir.empty() ) {
        return false;
    }
    FZZZipTracks zipTracks;
    if (!zipTracks.UnZip(m_workDir,indata.getData(), indata.getLen(),&m_OFDFilesContainer)) {
        return false;
    }
    
    if ( m_DocXDir != NULL ) {
        delete m_DocXDir;
        m_DocXDir = NULL;
    }
    m_DocXDir = new FZZDocXDir(&m_OFDFilesContainer,m_workDir);
    //--------test begin --------------------
    //FZZContentTypesXML* ctxml = m_DocXDir->getContentTypesXML();
    
    //--------test end ----------------------
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::FlushAll()
{
    if ( m_DocXDir == NULL ) {
        return;
    }
    m_DocXDir->FlushAll();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::Close(FZZBytes & outdata)
{
    zip_mem(outdata);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::zip_mem(FZZBytes & outData)
{
    FZZZipTracks zipTracks;
#ifdef MINIZIPNG
    zipTracks.CreateZip_mem();
    addZip(&zipTracks, m_workDir);
    outData = zipTracks.CloseZip_mem();
#else

#endif
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::addZip(FZZZipTracks* zipTracks,string rootpath)
{
    vector<string> fileNames;
    vector<string> dirNames;
    string tempdir;
    bool isfind = false;
    m_OFDFilesContainer.getFilesName(rootpath, fileNames);
    for ( int i = 0; i < fileNames.size();i++ ) {
        isfind = false;
        size_t indexOf = fileNames[i].find_last_of("/");
        if (indexOf != string::npos) {
            tempdir = fileNames[i].substr(0, indexOf + 1);
        } else {
            FZZBytes * tempdata = m_OFDFilesContainer.getFileData(rootpath, fileNames[i]);
            zipTracks->AddFileToZip(fileNames[i].c_str(), tempdata->getData(), tempdata->getLen());
            continue;
        }
        for (int z =0; z < dirNames.size(); z++) {
            if ( dirNames[z] == tempdir ) {
                isfind = true;
                break;
            }
        }
        if (!isfind) {
            dirNames.push_back(tempdir);
            zipTracks->AddFileToZip(tempdir.c_str(), NULL, 0);
        }
        
        FZZBytes * tempdata = m_OFDFilesContainer.getFileData(rootpath, fileNames[i]);
        zipTracks->AddFileToZip(fileNames[i].c_str(), tempdata->getData(), tempdata->getLen());
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody * FZZDocXDocument::getBody()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    FZZDocumentXML * docxml = wordDir->getDocumentXML();
    if ( docxml == NULL ) {
        return NULL;
    }
    FZZWBody * body = docxml->getBody();
    if ( body == NULL ) {
        body = docxml->setBody();
        if ( body == NULL ) {
            return NULL;
        }
    }
    return body;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZDocXDocument::addParagraph()
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return NULL;
    }
    FZZWP* retP = body->addP();
    
    if ( retP != NULL ) {
        retP->setDocXDir(m_DocXDir);
    }
    
    return retP;
}
//-----------------------------------------------------------------------------------------------------------------
size_t FZZDocXDocument::getParagraphCount()
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return 0;
    }
    vector<FZZWP*> * pList = body->getPList();
    if ( pList == NULL ) {
        return 0;
    }
    return pList->size();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZDocXDocument::getParagraph(size_t index)
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return NULL;
    }
    vector<FZZWP*> * pList = body->getPList();
    if ( pList == NULL || pList->size() == 0 ) {
        return NULL;
    }
    
    if ( index > pList->size() -1 ) {
        return NULL;
    }
    
    FZZWP * tempP = *(pList->begin()+index);
    if ( tempP != NULL ) {
        tempP->setDocXDir(m_DocXDir);
    }
    return tempP;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl * FZZDocXDocument::addTable()
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return NULL;
    }
    FZZWTbl* retTable = body->addTable();
    
    if ( retTable != NULL ) {
        retTable->setDocXDir(m_DocXDir);
    }
    
    return retTable;
}
//-----------------------------------------------------------------------------------------------------------------
size_t FZZDocXDocument::getTableCount()
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return 0;
    }
    vector<FZZWTbl*> * tableList = body->getTableList();
    if ( tableList == NULL ) {
        return 0;
    }
    return tableList->size();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl * FZZDocXDocument::getTable(size_t index)
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return NULL;
    }
    vector<FZZWTbl*> * tableList = body->getTableList();
    if ( tableList == NULL || tableList->size() == 0 ) {
        return NULL;
    }
    
    if ( index > tableList->size() -1 ) {
        return NULL;
    }
    
    FZZWTbl * tempTable = *(tableList->begin()+index);
    if ( tempTable != NULL ) {
        tempTable->setDocXDir(m_DocXDir);
    }
    return tempTable;
}
//-----------------------------------------------------------------------------------------------------------------
vector<PageElement*>* FZZDocXDocument::getPageElements()
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return NULL;
    }
    return body->getPageElements();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::getDefaultPageSize(long& width,long& height)
{
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        width = 11906;
        height = 16838;
        return;
    }

    FZZWPgSz * tempPgSz = NULL;
    FZZWSectPr * tempSectPr = body->getSectPr();
    if ( tempSectPr != NULL ) {
        tempPgSz = tempSectPr->getPgSz();
        if ( tempPgSz != NULL ) {
            width = strtol(tempPgSz->getW().c_str(),NULL,10);
            height = strtol(tempPgSz->getH().c_str(),NULL,10);
        }//if ( tempPgSz != NULL )
    }//if ( tempSectPr != NULL )
}
//-----------------------------------------------------------------------------------------------------------------
FZZSettingsXML * FZZDocXDocument::getSettingsXML()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    return wordDir->getSettingsXML();
}
//-----------------------------------------------------------------------------------------------------------------
FZZStylesXML * FZZDocXDocument::getStylesXml()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    return wordDir->getStylesXML();
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontTableXML * FZZDocXDocument::getFontTableXML()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    return wordDir->getFontTableXML();
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeXML * FZZDocXDocument::getThemeXML()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    FZZThemeDir * themeDir = wordDir->getThemeDir();
    if ( themeDir == NULL ) {
        return NULL;
    }
    return themeDir->getThemeXML();
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXMLRels * FZZDocXDocument::getDocumentXMLRels()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    FZZRelsDir * relsDir = wordDir->getRelsDir();
    if ( relsDir == NULL ) {
        return NULL;
    }
    return relsDir->getDocumentXMLRels();
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * FZZDocXDocument::getMediaFileData(string fileName)
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    FZZMediaDir * mediaDir = wordDir->getMediaDir();
    if ( mediaDir == NULL ) {
        return NULL;
    }
    return mediaDir->getResFile(fileName);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::getFooters(string firstXml_id,FZZFooterXML** firstXml,string defaultxml_id,FZZFooterXML** defaultXml,string   evenXml_id,FZZFooterXML** evenXml )
{
    *firstXml = NULL;
    *evenXml = NULL;
    *defaultXml = NULL;
    if ( m_DocXDir == NULL ) {
        return ;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return ;
    }
    
    FZZDocumentXMLRels * documentXMLRels = getDocumentXMLRels();
    if ( documentXMLRels == NULL ) {
        return ;
    }
    
    if ( !firstXml_id.empty() ) {
        *firstXml = wordDir->getFooterXML(documentXMLRels->getTarget(firstXml_id));
    }
    
    if ( !defaultxml_id.empty() ) {
        *defaultXml = wordDir->getFooterXML(documentXMLRels->getTarget(defaultxml_id));
    }
    
    if ( !evenXml_id.empty() ) {
        *evenXml = wordDir->getFooterXML(documentXMLRels->getTarget(evenXml_id));
    }
    
    if ( *evenXml == NULL && *defaultXml != NULL ) {
        vector<string> idlist;
        vector<string> targetlist;
        documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_FOOTER,idlist, targetlist);
        vector<string>::const_iterator id_itr;
        for ( id_itr = idlist.begin(); id_itr != idlist.end(); id_itr++ ) {
            if ( *id_itr == defaultxml_id ) {
                continue;
            }
            if ( !firstXml_id.empty() && *id_itr == firstXml_id ) {
                continue;
            }
            evenXml_id = *id_itr;
            string FileName = documentXMLRels->getTarget(evenXml_id);
            *evenXml = wordDir->getFooterXML(FileName);
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::getFooters(FZZFooterXML** firstXml,FZZFooterXML** defaultXml,FZZFooterXML** evenXml )
{
    *evenXml = NULL;
    *defaultXml = NULL;
    if ( m_DocXDir == NULL ) {
        return ;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return ;
    }
    
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return ;
    }
    FZZWSectPr * ctwSectPr = body->getSectPr();
    if ( ctwSectPr == NULL ) {
        return ;
    }
    
    FZZDocumentXMLRels * documentXMLRels = getDocumentXMLRels();
    if ( documentXMLRels == NULL ) {
        return ;
    }
    
    
    string defaultxml_id = "";
    string evenXml_id = "";
    string firstXml_id = "";
    vector<FZZWFooterReference*> * ctwFooterReferenceList = ctwSectPr->getFooterReferences();
    if ( ctwFooterReferenceList->size() == 0 ) {
        vector<PageElement*>* pageEleList = getPageElements();
        vector<PageElement*>::const_iterator itr_PageElement;
        
        for( itr_PageElement = pageEleList->begin(); itr_PageElement != pageEleList->end(); itr_PageElement++ ) {
            PageElement * temp = *itr_PageElement;
            if ( temp == NULL ) {
                continue;
            }
            if ( temp->type == "w:p" ) {
                FZZWPPr * ctwPPr = ((FZZWP *)(temp->object))->getPPr();
                if ( ctwPPr != NULL ) {
                    FZZWSectPr * ctwSectPr = ctwPPr->getSectPr();
                    if ( ctwSectPr != NULL ) {
                        ctwFooterReferenceList = ctwSectPr->getFooterReferences();
                        
                    }
                }
                
            }
        }
    }
    vector<FZZWFooterReference*>::const_iterator footer_itr;
    for( footer_itr = ctwFooterReferenceList->begin(); footer_itr != ctwFooterReferenceList->end(); footer_itr++ ) {
        FZZWFooterReference * temp = *footer_itr;
        if ( temp != NULL ) {
            string strType = temp->getType();
            string strRid = temp->getRID();
            if ( strRid.empty() ) {
                continue;
            }
                                   
            string FileName = documentXMLRels->getTarget(strRid);
            if ( strType == "even" ) {
                *evenXml = wordDir->getFooterXML(FileName);
                evenXml_id = strRid;
            } else if ( strType == "default" ) {
                *defaultXml = wordDir->getFooterXML(FileName);
                defaultxml_id = strRid;
            } else if ( strType == "first" ) {
                *firstXml = wordDir->getFooterXML(FileName);
                firstXml_id = strRid;
            }
            
        }
    }
    
    if ( *evenXml == NULL && *defaultXml != NULL ) {
        vector<string> idlist;
        vector<string> targetlist;
        documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_FOOTER,idlist, targetlist);
        vector<string>::const_iterator id_itr;
        for ( id_itr = idlist.begin(); id_itr != idlist.end(); id_itr++ ) {
            if ( *id_itr == defaultxml_id ) {
                continue;
            }
            if ( !firstXml_id.empty() && *id_itr == firstXml_id ) {
                continue;
            }
            evenXml_id = *id_itr;
            string FileName = documentXMLRels->getTarget(evenXml_id);
            *evenXml = wordDir->getFooterXML(FileName);
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::getHeaders(string firstXml_id,FZZHeaderXML** firstXml,string defaultxml_id,FZZHeaderXML** defaultXml,string evenXml_id,FZZHeaderXML** evenXml)
{
    *firstXml = NULL;
    *evenXml = NULL;
    *defaultXml = NULL;
    if ( m_DocXDir == NULL ) {
        return ;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return ;
    }
    
    FZZDocumentXMLRels * documentXMLRels = getDocumentXMLRels();
    if ( documentXMLRels == NULL ) {
        return ;
    }
    
    if ( !firstXml_id.empty() ) {
        *firstXml = wordDir->getHeaderXML(documentXMLRels->getTarget(firstXml_id));
    }
    
    if ( !defaultxml_id.empty() ) {
        *defaultXml = wordDir->getHeaderXML(documentXMLRels->getTarget(defaultxml_id));
    }
    
    if ( !evenXml_id.empty() ) {
        *evenXml = wordDir->getHeaderXML(documentXMLRels->getTarget(evenXml_id));
    }
    
    if ( *evenXml == NULL && *defaultXml != NULL ) {
        vector<string> idlist;
        vector<string> targetlist;
        documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_HEADER,idlist, targetlist);
        vector<string>::const_iterator id_itr;
        for ( id_itr = idlist.begin(); id_itr != idlist.end(); id_itr++ ) {
            if ( *id_itr == defaultxml_id ) {
                continue;
            }
            if ( !firstXml_id.empty() && *id_itr == firstXml_id ) {
                continue;
            }
            evenXml_id = *id_itr;
            string FileName = documentXMLRels->getTarget(evenXml_id);
            *evenXml = wordDir->getHeaderXML(FileName);
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocXDocument::getHeaders(FZZHeaderXML** firstXml,FZZHeaderXML** defaultXml,FZZHeaderXML** evenXml)
{
    *evenXml = NULL;
    *defaultXml = NULL;
    if ( m_DocXDir == NULL ) {
        return ;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return ;
    }
    
    FZZWBody * body = getBody();
    if ( body == NULL ) {
        return ;
    }
    FZZWSectPr * ctwSectPr = body->getSectPr();
    if ( ctwSectPr == NULL ) {
        return ;
    }
    
    FZZDocumentXMLRels * documentXMLRels = getDocumentXMLRels();
    if ( documentXMLRels == NULL ) {
        return ;
    }
    
    
    string defaultxml_id = "";
    string evenXml_id = "";
    string firstXml_id = "";
    vector<FZZWHeaderReference*> * ctwHeaderReferenceList = ctwSectPr->getHeaderReferences();
    if ( ctwHeaderReferenceList->size() == 0 ) {
        vector<PageElement*>* pageEleList = getPageElements();
        vector<PageElement*>::const_iterator itr_PageElement;
        
        for( itr_PageElement = pageEleList->begin(); itr_PageElement != pageEleList->end(); itr_PageElement++ ) {
            PageElement * temp = *itr_PageElement;
            if ( temp == NULL ) {
                continue;
            }
            if ( temp->type == "w:p" ) {
                FZZWPPr * ctwPPr = ((FZZWP *)(temp->object))->getPPr();
                if ( ctwPPr != NULL ) {
                    FZZWSectPr * ctwSectPr = ctwPPr->getSectPr();
                    if ( ctwSectPr != NULL ) {
                        ctwHeaderReferenceList = ctwSectPr->getHeaderReferences();
                        
                    }
                }
                
            }
        }
    }
    vector<FZZWHeaderReference*>::const_iterator header_itr;
    for( header_itr = ctwHeaderReferenceList->begin(); header_itr != ctwHeaderReferenceList->end(); header_itr++ ) {
        FZZWHeaderReference * temp = *header_itr;
        if ( temp != NULL ) {
            string strType = temp->getType();
            string strRid = temp->getRID();
            if ( strRid.empty() ) {
                continue;
            }
                                   
            string headerFileName = documentXMLRels->getTarget(strRid);
            if ( strType == "even" ) {
                *evenXml = wordDir->getHeaderXML(headerFileName);
                evenXml_id = strRid;
            } else if ( strType == "default" ) {
                *defaultXml = wordDir->getHeaderXML(headerFileName);
                defaultxml_id = strRid;
            } else if ( strType == "first" ) {
                *firstXml = wordDir->getHeaderXML(headerFileName);
                firstXml_id = strRid;
            }
            
        }
    }
    
    if ( *evenXml == NULL && *defaultXml != NULL ) {
        vector<string> idlist;
        vector<string> targetlist;
        documentXMLRels->getTarget(DOCUMENTXMLRELS_TYPE_HEADER,idlist, targetlist);
        vector<string>::const_iterator id_itr;
        for ( id_itr = idlist.begin(); id_itr != idlist.end(); id_itr++ ) {
            if ( *id_itr == defaultxml_id ) {
                continue;
            }
            if ( !firstXml_id.empty() && *id_itr == firstXml_id ) {
                continue;
            }
            evenXml_id = *id_itr;
            string FileName = documentXMLRels->getTarget(evenXml_id);
            *evenXml = wordDir->getHeaderXML(FileName);
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberingXML * FZZDocXDocument::getNumberingXML()
{
    if ( m_DocXDir == NULL ) {
        return NULL;
    }
    FZZWordDir * wordDir = m_DocXDir->getWordDir();
    if ( wordDir == NULL ) {
        return NULL;
    }
    
    return wordDir->getNumberingXML();
}
//-----------------------------------------------------------------------------------------------------------------
