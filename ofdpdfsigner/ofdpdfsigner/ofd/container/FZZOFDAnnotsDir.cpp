//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDAnnotsDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAnnotsDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotsDir::FZZOFDAnnotsDir() :FZZOFDBaseDir(),m_FZZOFDAnnotationsXML(NULL)
{
    //DLOG("FZZOFDAnnotsDir()");
    FZZConst::addClassCount("FZZOFDAnnotsDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotsDir::FZZOFDAnnotsDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_FZZOFDAnnotationsXML(NULL)
{
    FZZConst::addClassCount("FZZOFDAnnotsDir");
    //Pages/Page_0/
    setPath(path);
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotsDir::~FZZOFDAnnotsDir()
{
    //DLOG("~FZZOFDAnnotsDir()");
    FZZConst::delClassCount("FZZOFDAnnotsDir");
    if ( m_FZZOFDAnnotationsXML != NULL ) {
        delete m_FZZOFDAnnotationsXML;
        m_FZZOFDAnnotationsXML = NULL;
    }
    
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
FZZOFDAnnotationsXML* FZZOFDAnnotsDir::getAnnotationsXML()
{
    if ( m_FZZOFDAnnotationsXML != NULL ) {
        return m_FZZOFDAnnotationsXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDANNOTATIONSXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDAnnotationsXML = new FZZOFDAnnotationsXML(doc);

    } 

    return m_FZZOFDAnnotationsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotationsXML* FZZOFDAnnotsDir::setAnnotationsXML()
{
    getAnnotationsXML();
    if ( m_FZZOFDAnnotationsXML == NULL ) {
        m_FZZOFDAnnotationsXML = new FZZOFDAnnotationsXML();
    }
    return m_FZZOFDAnnotationsXML;
    
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPageDir *> * FZZOFDAnnotsDir::getPageDirList()
{
    if ( m_FZZOFDPageDirList.size() <= 0 ) {
        FZZOFDAnnotationsXML* ofdAnnotationsXML = getAnnotationsXML();
        if ( ofdAnnotationsXML == NULL ) {
            goto err;
        }
        vector<FZZOFDAnnPage*>* ofdAnnPageList = ofdAnnotationsXML->getPageList();
        vector<FZZOFDAnnPage*>::const_iterator ap_itr;
        for( ap_itr = ofdAnnPageList->begin(); ap_itr != ofdAnnPageList->end(); ap_itr++ ) {
            FZZOFDAnnPage * ofdAnnPage = *ap_itr;
            if ( ofdAnnPage == NULL ) {
                continue;
            }
            FZZOFDFileLoc * ofdFileLoc = ofdAnnPage->getFileLoc();
            if ( ofdFileLoc == NULL ) {
                continue;
            }
            //Page_0/Annotation.xml
            string strAnnotationXML_FileName = ofdFileLoc->getValue();
            
                
            strAnnotationXML_FileName = FZZConst::replace_all(strAnnotationXML_FileName,"\\","/");
            if ( strAnnotationXML_FileName[0] == '/' ) {
                //strAnnotationXML_FileName = strAnnotationXML_FileName.substr(1);
                size_t rootpos = strAnnotationXML_FileName.find(m_Path);
                if ( rootpos != string::npos ) {
                    strAnnotationXML_FileName = strAnnotationXML_FileName.substr(rootpos+m_Path.length());
                }
            }
            size_t pos = strAnnotationXML_FileName.find_last_of("/");
            FZZOFDPageDir * ofdPageDir = NULL;
            if ( pos != string::npos ) {
                ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path+strAnnotationXML_FileName.substr(0, pos + 1));
            } else {
                ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path);
            }
                
            if ( ofdPageDir != NULL ) {
                ofdPageDir->setPageId(ofdAnnPage->getPageID());
                m_FZZOFDPageDirList.push_back(ofdPageDir);
            }//if ( ofdTemplateDir != NULL )
            
            
        }//for
    }
err:
    return &m_FZZOFDPageDirList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageDir * FZZOFDAnnotsDir::addPageDir(string PageId)
{
    getPageDirList();
    FZZOFDPageDir * ofdPageDir = NULL;
    if ( m_FZZOFDPageDirList.size() <= 0 ) {
        ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path + "Page_0/");
    } else {
        FZZOFDPageDir * ofdPageDir_last = *(m_FZZOFDPageDirList.begin()+m_FZZOFDPageDirList.size()-1);
        if ( ofdPageDir_last == NULL ) {
            ofdPageDir = new FZZOFDPageDir(m_OFDFilesContainer,m_Root,m_Path + "Page_" + FZZConst::fmt((int)m_FZZOFDPageDirList.size())+"/");
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
        ofdPageDir->setPageId(PageId);
    }
    return ofdPageDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageDir * FZZOFDAnnotsDir::getPageDir(string PageId)
{
    getPageDirList();
    FZZOFDPageDir * pageDir = NULL;
    vector<FZZOFDPageDir *>::const_iterator itr;
    for( itr = m_FZZOFDPageDirList.begin(); itr != m_FZZOFDPageDirList.end(); itr++ ) {
        FZZOFDPageDir * tempdir = *itr;
        if (tempdir != NULL && tempdir->getPageId() == PageId ) {
            pageDir = tempdir;
            break;
        }
    }
    if ( pageDir == NULL ) {
        pageDir = addPageDir(PageId);
    }
    return pageDir;
}
//-----------------------------------------------------------------------------------------------------------------
