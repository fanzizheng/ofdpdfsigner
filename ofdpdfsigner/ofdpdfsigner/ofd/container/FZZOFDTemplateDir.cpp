//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDTemplateDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTemplateDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplateDir::FZZOFDTemplateDir() :FZZOFDBaseDir(),m_FZZOFDPageXML(NULL)
{
    //DLOG("FZZOFDTemplateDir()");
    FZZConst::addClassCount("FZZOFDTemplateDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplateDir::FZZOFDTemplateDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_FZZOFDPageXML(NULL)
{
    FZZConst::addClassCount("FZZOFDTemplateDir");
    //Tpls/Tpl_0/
    setPath(path);
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplateDir::~FZZOFDTemplateDir()
{
    //DLOG("~FZZOFDTemplateDir()");
    FZZConst::delClassCount("FZZOFDTemplateDir");
    if ( m_FZZOFDPageXML != NULL ) {
        delete m_FZZOFDPageXML;
        m_FZZOFDPageXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML* FZZOFDTemplateDir::getPageXML()
{
    if ( m_FZZOFDPageXML != NULL ) {
        return m_FZZOFDPageXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDPAGEXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDPageXML = new FZZOFDPageXML(doc);

    } else {
        m_FZZOFDPageXML = new FZZOFDPageXML();
    }

    return m_FZZOFDPageXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML* FZZOFDTemplateDir::setPageXML()
{
    getPageXML();
    if ( m_FZZOFDPageXML == NULL ) {
        m_FZZOFDPageXML = new FZZOFDPageXML();
    }
    return m_FZZOFDPageXML;
}
//-----------------------------------------------------------------------------------------------------------------
