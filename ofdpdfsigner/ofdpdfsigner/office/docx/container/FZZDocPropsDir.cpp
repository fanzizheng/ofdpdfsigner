//
//  Created by zizheng fan on 2023/04/07.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZDocPropsDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZDocPropsDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZDocPropsDir::FZZDocPropsDir() :FZZBaseDir(),m_AppXML(NULL),m_CoreXML(NULL)
{
    //DLOG("FZZDocPropsDir()");
    FZZConst::addClassCount("FZZDocPropsDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocPropsDir::FZZDocPropsDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZBaseDir(filesContainer,Root),m_AppXML(NULL),m_CoreXML(NULL)
{
    FZZConst::addClassCount("FZZDocPropsDir");
    setPath(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocPropsDir::~FZZDocPropsDir()
{
    //DLOG("~FZZDocPropsDir()");
    FZZConst::delClassCount("FZZDocPropsDir");
    if ( m_AppXML != NULL ) {
        delete m_AppXML;
        m_AppXML = NULL;
    }
    if ( m_CoreXML != NULL ) {
        delete m_CoreXML;
        m_CoreXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAppXML* FZZDocPropsDir::getAppXML()
{
    if ( m_AppXML != NULL ) {
        return m_AppXML;
    }
    
    XMLDocument * doc = getXMLDocument(APPXML_FILENAME);
    if ( doc != NULL ) {
        m_AppXML = new FZZAppXML(doc);
        
    } else {
        m_AppXML = new FZZAppXML();
    }
  
    return m_AppXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZCoreXML* FZZDocPropsDir::getCoreXML()
{
    if ( m_CoreXML != NULL ) {
        return m_CoreXML;
    }
    
    XMLDocument * doc = getXMLDocument(COREXML_FILENAME);
    if ( doc != NULL ) {
        m_CoreXML = new FZZCoreXML(doc);
        
    } else {
        m_CoreXML = new FZZCoreXML();
    }
  
    return m_CoreXML;
}
//-----------------------------------------------------------------------------------------------------------------
