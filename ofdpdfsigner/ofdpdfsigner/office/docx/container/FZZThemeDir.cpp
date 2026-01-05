//
//  Created by zizheng fan on 2023/04/07.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZThemeDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZThemeDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZThemeDir::FZZThemeDir() :FZZBaseDir(),m_ThemeXML(NULL)
{
    //DLOG("FZZThemeDir()");
    FZZConst::addClassCount("FZZThemeDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeDir::FZZThemeDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZBaseDir(filesContainer,Root)
    ,m_ThemeXML(NULL)
{
    FZZConst::addClassCount("FZZThemeDir");
    setPath(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeDir::~FZZThemeDir()
{
    //DLOG("~FZZThemeDir()");
    FZZConst::delClassCount("FZZThemeDir");
    if ( m_ThemeXML != NULL ) {
        delete m_ThemeXML;
        m_ThemeXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeXML* FZZThemeDir::getThemeXML()
{
    if ( m_ThemeXML != NULL ) {
        return m_ThemeXML;
    }
    
    XMLDocument * doc = getXMLDocument(THEMEXML_FILENAME);
    if ( doc != NULL ) {
        m_ThemeXML = new FZZThemeXML(doc);
        
    } else {
        m_ThemeXML = new FZZThemeXML();
    }
  
    return m_ThemeXML;
}
//-----------------------------------------------------------------------------------------------------------------
