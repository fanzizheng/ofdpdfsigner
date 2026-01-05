//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDTagsDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTagsDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTagsDir::FZZOFDTagsDir() :FZZOFDBaseDir(),m_FZZOFDCustomTagsXML(NULL)
{
    //DLOG("FZZOFDTagsDir()");
    FZZConst::addClassCount("FZZOFDTagsDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTagsDir::FZZOFDTagsDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_FZZOFDCustomTagsXML(NULL)
{
    FZZConst::addClassCount("FZZOFDTagsDir");
    //Doc_0/Signs/
    setPath(path);
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTagsDir::~FZZOFDTagsDir()
{
    //DLOG("~FZZOFDTagsDir()");
    FZZConst::delClassCount("FZZOFDTagsDir");
    if ( m_FZZOFDCustomTagsXML != NULL ) {
        delete m_FZZOFDCustomTagsXML;
        m_FZZOFDCustomTagsXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTagsXML* FZZOFDTagsDir::getCustomTagsXML()
{
    if ( m_FZZOFDCustomTagsXML != NULL ) {
        return m_FZZOFDCustomTagsXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDCUSTOMTAGSXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDCustomTagsXML = new FZZOFDCustomTagsXML(doc);

    } 

    return m_FZZOFDCustomTagsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTagsXML* FZZOFDTagsDir::setCustomTagsXML()
{
    getCustomTagsXML();
    if ( m_FZZOFDCustomTagsXML == NULL ) {
        m_FZZOFDCustomTagsXML = new FZZOFDCustomTagsXML();
    }
    return m_FZZOFDCustomTagsXML;
}
//-----------------------------------------------------------------------------------------------------------------
