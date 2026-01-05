//
//  Created by zizheng fan on 2023/04/03.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZBaseDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZBaseDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZBaseDir::FZZBaseDir() : m_Root(""),m_Path(""),m_OFDFilesContainer(NULL)
{
    //DLOG("FZZBaseDir()");
    FZZConst::addClassCount("FZZBaseDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBaseDir::FZZBaseDir(FZZOFDFilesContainer* filesContainer,string Root) :FZZBaseDir()
{
    m_OFDFilesContainer = filesContainer;
    m_Root = Root;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZBaseDir::~FZZBaseDir()
{
    //DLOG("~FZZBaseDir()");
    FZZConst::delClassCount("FZZBaseDir");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * FZZBaseDir::getResFile(string filename)
{
    if ( m_OFDFilesContainer == NULL ) {
        return NULL;
    }
    FZZBytes * data = m_OFDFilesContainer->getFileData(m_Root, m_Path.empty() ? filename : m_Path+filename);
    if ( data == NULL ) {
        return NULL;
    }
    return data;
}
//-----------------------------------------------------------------------------------------------------------------
XMLDocument * FZZBaseDir::getXMLDocument(string filename)
{
    if ( m_OFDFilesContainer == NULL ) {
        return NULL;
    }
    FZZBytes * xmldata = m_OFDFilesContainer->getFileData(m_Root, m_Path.empty() ? filename : m_Path+filename);
    if ( xmldata == NULL ) {
        return NULL;
    }
    
    xmldata_format((char *)xmldata->getData(),xmldata->getLen(),xmldata);
    
    XMLDocument * doc = new XMLDocument();
    if ( doc == NULL ) {
        doc = NULL;
    }
    doc->Parse((char *)xmldata->getData(),xmldata->getLen());
    if (doc->Error()) {
        delete doc;
        doc = NULL;
    }
    return doc;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZBaseDir::FlushOfficeObject(FZZOfficeObject * officeObject)
{
    if ( officeObject == NULL || m_OFDFilesContainer == NULL ) {
        return;
    }
    
    string srchash = officeObject->getHash();
    string currhash = officeObject->getCurrHash();
    if ( srchash != currhash ) {
        string xmldata = officeObject->getXMLData();
        m_OFDFilesContainer->updateFile(m_Root, m_Path.empty() ? officeObject->getFileName() : m_Path+officeObject->getFileName(),(unsigned char *)(xmldata.c_str()),xmldata.length() );
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZBaseDir::FlushResFile(string filename,FZZBytes * filedata)
{
    if ( filedata == NULL || m_OFDFilesContainer == NULL ) {
        return;
    }
    m_OFDFilesContainer->updateFile(m_Root, m_Path.empty() ? filename : m_Path+filename,(unsigned char *)(filedata->getData()),filedata->getLen() );
}
//-----------------------------------------------------------------------------------------------------------------
string FZZBaseDir::getResFileName(string inName,string inExtName,int & ID)
{
    if ( m_OFDFilesContainer == NULL ) {
        return "";
    }
  
    ID = 0;
    string tempstr = "";
    for( int i = 1; i < 100000; i++ ) {
        tempstr = inName + FZZConst::fmt(i)+"."+inExtName;
        if ( m_OFDFilesContainer->exists(m_Root, m_Path.empty() ? tempstr : m_Path+tempstr) ) {
            continue;
        } else {
            ID = i;
            break;
        }
    }
    return tempstr;
}
//-----------------------------------------------------------------------------------------------------------------
