//
//  Created by zizheng fan on 2024/03/13.
//
#include "basic/FZZConst.h"
#include "ofd/FZZOFDSignCleaner.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDSignCleaner*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignCleaner::FZZOFDSignCleaner() : m_reader(NULL)
{
    //DLOG("FZZOFDSignCleaner()");
    FZZConst::addClassCount("FZZOFDSignCleaner");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignCleaner::FZZOFDSignCleaner(FZZOFD* reader) : FZZOFDSignCleaner()
{
    m_reader = reader;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignCleaner::~FZZOFDSignCleaner()
{
    //DLOG("~FZZOFDSignCleaner()");
    FZZConst::delClassCount("FZZOFDSignCleaner");
    m_reader = NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSignCleaner::clean(FZZBytes & outOFDFileData)
{
    if ( m_reader == NULL ) {
        return;
    }
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) {
        return;
    }
    FZZOFDXML* ofd = ofdDir->getOFDXML();
    if ( ofd == NULL ) {
        return;
    }
    
    vector<FZZOFDDocBody*>* docBodyList = ofd->getDocBodys();
    if ( docBodyList == NULL ) {
        return;
    }
    
    vector<FZZOFDDocBody*>::const_iterator iter;
    for (iter = docBodyList->begin(); iter != docBodyList->end(); iter++) {
        FZZOFDDocBody* docBody = *iter;
        if ( docBody == NULL ) {
            continue;
        }
        
        FZZOFDDocBody_Signatures * signatures = docBody->getSignatures();
        if ( signatures != NULL ) {
            string strSignaturesXml_FileName = signatures->getValue();
            if ( strSignaturesXml_FileName[0] == '/' ) {
                strSignaturesXml_FileName = strSignaturesXml_FileName.substr(1);
            }
            size_t pos = strSignaturesXml_FileName.find_last_of("/");
            if ( pos != string::npos ) {
                ofdDir->deleteDirFile(strSignaturesXml_FileName.substr(0, pos + 1));
            } 
            docBody->deleteElement(FZZOFDDOCBODY_SIGNATURES_Name);
        }//if ( signatures != NULL )
        
        
    }
    ofdDir->FlushXMLObject(ofd);
    
    
    
   
    m_reader->Close(outOFDFileData);
}
//-----------------------------------------------------------------------------------------------------------------




