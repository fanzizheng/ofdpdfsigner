//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDSignsDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignsDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignsDir::FZZOFDSignsDir() :FZZOFDBaseDir(),m_FZZOFDSignaturesXML(NULL),m_maxSignIndex(0)
{
    //DLOG("FZZOFDSignsDir()");
    FZZConst::addClassCount("FZZOFDSignsDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignsDir::FZZOFDSignsDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_FZZOFDSignaturesXML(NULL),m_maxSignIndex(0)
{
    FZZConst::addClassCount("FZZOFDSignsDir");
    //Doc_0/Signs/
    setPath(path);
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignsDir::~FZZOFDSignsDir()
{
    //DLOG("~FZZOFDSignsDir()");
    FZZConst::delClassCount("FZZOFDSignsDir");
    if ( m_FZZOFDSignaturesXML != NULL ) {
        delete m_FZZOFDSignaturesXML;
        m_FZZOFDSignaturesXML = NULL;
    }
    
    vector<FZZOFDSignDir*>::const_iterator itr;
    for( itr = m_FZZOFDSignDirList.begin(); itr != m_FZZOFDSignDirList.end(); itr++ ) {
        FZZOFDSignDir * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDSignDirList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignaturesXML* FZZOFDSignsDir::getSignaturesXML()
{
    if ( m_FZZOFDSignaturesXML != NULL ) {
        return m_FZZOFDSignaturesXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDSIGNATURESXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDSignaturesXML = new FZZOFDSignaturesXML(doc);
    }

    return m_FZZOFDSignaturesXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignaturesXML* FZZOFDSignsDir::setSignaturesXML()
{
    getSignaturesXML();
    if ( m_FZZOFDSignaturesXML == NULL ) {
        m_FZZOFDSignaturesXML = new FZZOFDSignaturesXML();
    }
    return m_FZZOFDSignaturesXML;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDSignDir *> * FZZOFDSignsDir::getSignDirList()
{
    if ( m_FZZOFDSignDirList.size() <= 0 ) {
        FZZOFDSignaturesXML* signaturesXML = getSignaturesXML();
        if ( signaturesXML == NULL ) {
            goto err;
        }
        vector<FZZOFDSignature*>* signatureList = signaturesXML->getSignatureList();
        if ( signatureList == NULL || signatureList->size() <= 0 ) {
            goto err;
        }
        vector<FZZOFDSignature*>::const_iterator signature_itr;
        for( signature_itr = signatureList->begin(); signature_itr != signatureList->end(); signature_itr++ ) {
            FZZOFDSignature * signatureObj = *signature_itr;
            if ( signatureObj == NULL ) {
                continue;
            }
            string sid = signatureObj->getID();
            string strSignatureXml_FileName = signatureObj->getBaseLoc();
            strSignatureXml_FileName = FZZConst::replace_all(strSignatureXml_FileName,"\\","/");
            if ( strSignatureXml_FileName[0] == '/' ) {
                strSignatureXml_FileName = strSignatureXml_FileName.substr(1);
//                size_t rootpos = strSignatureXml_FileName.find(m_Path);
//                if ( rootpos != string::npos ) {
//                    strSignatureXml_FileName = strSignatureXml_FileName.substr(rootpos+m_Path.length());
//                }
            }
            size_t pos = strSignatureXml_FileName.find_last_of("/");
            FZZOFDSignDir * signDir = NULL;
            if ( pos != string::npos ) {
                //FZZOFDSignDir * signDir = new FZZOFDSignDir(m_OFDFilesContainer,m_Root,m_Path+strSignatureXml_FileName.substr(0, pos + 1));
                string dirName = strSignatureXml_FileName.substr(0, pos + 1);
                size_t rootpos = dirName.find(m_Path);
                if ( rootpos == string::npos ) {
                    dirName = m_Path + dirName;
                }
                signDir = new FZZOFDSignDir(m_OFDFilesContainer,m_Root,dirName);
                
                transform(dirName.begin(), dirName.end(), dirName.begin(), ::tolower);
                size_t indexOf = dirName.find("sign_");
                if (indexOf != string::npos) {
                    string numb = dirName.substr(indexOf + 5);
                    indexOf = numb.find("/");
                    if (indexOf != string::npos) {
                        numb = numb.substr(0,indexOf);
                        int num = (int)strtol(numb.c_str(),NULL,10);
                        if (m_maxSignIndex <= num) {
                            m_maxSignIndex = num + 1;
                        }
                    }
                }
                
            }
//            else {
//                signDir = new FZZOFDSignDir(m_OFDFilesContainer,m_Root,m_Path);
//            }
            if ( signDir != NULL ) {
                signDir->setSignID(sid);
                m_FZZOFDSignDirList.push_back(signDir);
            }
        }//for
        
    }//if ( m_FZZOFDSignDirList.size() <= 0 )
err:
    return &m_FZZOFDSignDirList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignDir * FZZOFDSignsDir::addSignDir()
{
    if ( m_FZZOFDSignDirList.size() <= 0 ) {
        getSignDirList();
    }
    
    FZZOFDSignDir * signDir = new FZZOFDSignDir(m_OFDFilesContainer,m_Root,m_Path+"Sign_"+FZZConst::fmt(m_maxSignIndex)+"/");
    if ( signDir != NULL ) {
        m_FZZOFDSignDirList.push_back(signDir);
        m_maxSignIndex++;
    }
    return signDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignDir * FZZOFDSignsDir::getSignDir(string signDirPath)
{
    getSignDirList();
    FZZOFDSignDir * retDir = NULL;
    vector<FZZOFDSignDir*>::const_iterator signature_it;
    for( signature_it = m_FZZOFDSignDirList.begin(); signature_it != m_FZZOFDSignDirList.end(); signature_it++ ) {
        FZZOFDSignDir* signDir = *signature_it;
        if ( signDir == NULL ) {
            continue;
        }
        
        if ( signDirPath == signDir->getPath() ) {
            retDir = signDir;
            break;
        }
        
        
    }
    return retDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML * FZZOFDSignsDir::getSignatureXML(string signDirPath)
{
    FZZOFDSignDir * signDir = getSignDir(signDirPath);
    return signDir != NULL ? signDir->getSignatureXML() : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
