//
//  Created by zizheng fan on 2023/04/05.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZRelsDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZRelsDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZRelsDir::FZZRelsDir() :FZZBaseDir(),m_RelsXML(NULL),m_DocumentXMLRels(NULL)
{
    //DLOG("FZZRelsDir()");
    FZZConst::addClassCount("FZZRelsDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsDir::FZZRelsDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZBaseDir(filesContainer,Root)
    ,m_RelsXML(NULL),m_DocumentXMLRels(NULL)
{
    FZZConst::addClassCount("FZZRelsDir");
    setPath(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsDir::~FZZRelsDir()
{
    //DLOG("~FZZRelsDir()");
    FZZConst::delClassCount("FZZRelsDir");
    if ( m_RelsXML != NULL ) {
        delete m_RelsXML;
        m_RelsXML = NULL;
    }
    if ( m_DocumentXMLRels != NULL ) {
        delete m_DocumentXMLRels;
        m_DocumentXMLRels = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsXML* FZZRelsDir::getRelsXML()
{
    if ( m_RelsXML != NULL ) {
        return m_RelsXML;
    }
    
    XMLDocument * doc = getXMLDocument(RELSXML_FILENAME);
    if ( doc != NULL ) {
        m_RelsXML = new FZZRelsXML(doc);
        
    } else {
        m_RelsXML = new FZZRelsXML();
    }
  
    return m_RelsXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXMLRels* FZZRelsDir::getDocumentXMLRels()
{
    if ( m_DocumentXMLRels != NULL ) {
        return m_DocumentXMLRels;
    }
    
    XMLDocument * doc = getXMLDocument(DOCUMENTXMLRELS_FILENAME);
    if ( doc != NULL ) {
        m_DocumentXMLRels = new FZZDocumentXMLRels(doc);
        
    } else {
        m_DocumentXMLRels = new FZZDocumentXMLRels();
    }
  
    return m_DocumentXMLRels;
}
//-----------------------------------------------------------------------------------------------------------------
