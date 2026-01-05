//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDPageDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageDir::FZZOFDPageDir() :FZZOFDBaseDir(),m_PageId(""),m_FZZOFDPageXML(NULL),m_FZZOFDPageResXML(NULL),m_FZZOFDPageAnnotXML(NULL)
{
    //DLOG("FZZOFDPageDir()");
    FZZConst::addClassCount("FZZOFDPageDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageDir::FZZOFDPageDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_PageId(""),m_FZZOFDPageXML(NULL),m_FZZOFDPageResXML(NULL),m_FZZOFDPageAnnotXML(NULL)
{
    FZZConst::addClassCount("FZZOFDPageDir");
    //Pages/Page_0/
    setPath(path);
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageDir::~FZZOFDPageDir()
{
    //DLOG("~FZZOFDPageDir()");
    FZZConst::delClassCount("FZZOFDPageDir");
    if ( m_FZZOFDPageXML != NULL ) {
        delete m_FZZOFDPageXML;
        m_FZZOFDPageXML = NULL;
    }
    if ( m_FZZOFDPageResXML != NULL ) {
        delete m_FZZOFDPageResXML;
        m_FZZOFDPageResXML = NULL;
    }
    if ( m_FZZOFDPageAnnotXML != NULL ) {
        delete m_FZZOFDPageAnnotXML;
        m_FZZOFDPageAnnotXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML* FZZOFDPageDir::getPageXML()
{
    if ( m_FZZOFDPageXML != NULL ) {
        return m_FZZOFDPageXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDPAGEXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDPageXML = new FZZOFDPageXML(doc);

    } 

    return m_FZZOFDPageXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageResXML* FZZOFDPageDir::getPageResXML()
{
    if ( m_FZZOFDPageResXML != NULL ) {
        return m_FZZOFDPageResXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDPAGERESXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDPageResXML = new FZZOFDPageResXML(doc);

    }

    return m_FZZOFDPageResXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML* FZZOFDPageDir::getAnnotationXML()
{
    if ( m_FZZOFDPageAnnotXML != NULL ) {
        return m_FZZOFDPageAnnotXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDPAGEANNOTXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDPageAnnotXML = new FZZOFDPageAnnotXML(doc);

    }
    return m_FZZOFDPageAnnotXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML* FZZOFDPageDir::setPageXML()
{
    getPageXML();
    if ( m_FZZOFDPageXML == NULL ) {
        m_FZZOFDPageXML = new FZZOFDPageXML();
        
        m_FZZOFDPageXML->setPageIndex(getPathIndex(getPath()));
    }
    return m_FZZOFDPageXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageResXML* FZZOFDPageDir::setPageResXML()
{
    getPageResXML();
    if ( m_FZZOFDPageResXML == NULL ) {
        m_FZZOFDPageResXML = new FZZOFDPageResXML();
    }
    return m_FZZOFDPageResXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML* FZZOFDPageDir::setAnnotationXML()
{
    getAnnotationXML();
    if ( m_FZZOFDPageAnnotXML == NULL ) {
        m_FZZOFDPageAnnotXML = new FZZOFDPageAnnotXML();
    }
    return m_FZZOFDPageAnnotXML;
}
//-----------------------------------------------------------------------------------------------------------------
