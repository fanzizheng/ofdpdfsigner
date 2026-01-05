//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDAttachsDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAttachsDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachsDir::FZZOFDAttachsDir() :FZZOFDBaseDir(),m_FZZOFDAttachmentsXML(NULL),m_FileNameIndex(0)
{
    //DLOG("FZZOFDAttachsDir()");
    FZZConst::addClassCount("FZZOFDAttachsDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachsDir::FZZOFDAttachsDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_FZZOFDAttachmentsXML(NULL)
{
    FZZConst::addClassCount("FZZOFDAttachsDir");
    //Pages/Page_0/
    setPath(path);
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachsDir::~FZZOFDAttachsDir()
{
    //DLOG("~FZZOFDAttachsDir()");
    FZZConst::delClassCount("FZZOFDAttachsDir");
    if ( m_FZZOFDAttachmentsXML != NULL ) {
        delete m_FZZOFDAttachmentsXML;
        m_FZZOFDAttachmentsXML = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachmentsXML* FZZOFDAttachsDir::getAttachmentsXML()
{
    if ( m_FZZOFDAttachmentsXML != NULL ) {
        return m_FZZOFDAttachmentsXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDATTACHMENTSXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDAttachmentsXML = new FZZOFDAttachmentsXML(doc);

    } 

    return m_FZZOFDAttachmentsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachmentsXML* FZZOFDAttachsDir::setAttachmentsXML()
{
    getAttachmentsXML();
    if ( m_FZZOFDAttachmentsXML == NULL ) {
        m_FZZOFDAttachmentsXML = new FZZOFDAttachmentsXML();
    }
    return m_FZZOFDAttachmentsXML;
}
//-----------------------------------------------------------------------------------------------------------------
