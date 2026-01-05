//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDBaseDir.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBaseDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseDir::FZZOFDBaseDir() : m_Root(""),m_Path(""),m_OFDFilesContainer(NULL)
{
    //DLOG("FZZOFDBaseDir()");
    FZZConst::addClassCount("FZZOFDBaseDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseDir::FZZOFDBaseDir(FZZOFDFilesContainer* filesContainer,string Root) :FZZOFDBaseDir()
{
    m_OFDFilesContainer = filesContainer;
    m_Root = Root;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseDir::~FZZOFDBaseDir()
{
    //DLOG("~FZZOFDBaseDir()");
    FZZConst::delClassCount("FZZOFDBaseDir");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * FZZOFDBaseDir::getResFile(string filename)
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
XMLDocument * FZZOFDBaseDir::getXMLDocument(string filename)
{
    if ( m_OFDFilesContainer == NULL ) {
        return NULL;
    }
    FZZBytes * xmldata = m_OFDFilesContainer->getFileData(m_Root, m_Path.empty() ? filename : m_Path+filename);
    if ( xmldata == NULL ) {
        return NULL;
    }
    
    //xmldata_format((char *)xmldata->getData(),xmldata->getLen(),xmldata);
    
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
void FZZOFDBaseDir::FlushXMLObject(FZZOFDXMLFileObject * ofdXMLFileObject)
{
    if ( ofdXMLFileObject == NULL || m_OFDFilesContainer == NULL ) {
        return;
    }
    
    string srchash = ofdXMLFileObject->getHash();
    string currhash = ofdXMLFileObject->getCurrHash();
    if ( srchash != currhash ) {
        string xmldata = ofdXMLFileObject->getXMLData();
        m_OFDFilesContainer->updateFile(m_Root, m_Path.empty() ? ofdXMLFileObject->getFileName() : m_Path+ofdXMLFileObject->getFileName(),(unsigned char *)(xmldata.c_str()),xmldata.length() );
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseDir::FlushResFile(string filename,FZZBytes * filedata)
{
    if ( filedata == NULL || m_OFDFilesContainer == NULL ) {
        return;
    }
    m_OFDFilesContainer->updateFile(m_Root, m_Path.empty() ? filename : m_Path+filename,(unsigned char *)(filedata->getData()),filedata->getLen() );
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseDir::FlushResFile(string filename,const unsigned char* const filedata,int filedataLen)
{
    if ( filedata == NULL || m_OFDFilesContainer == NULL ) {
        return;
    }
    m_OFDFilesContainer->updateFile(m_Root, m_Path.empty() ? filename : m_Path+filename,(unsigned char*)filedata,filedataLen );
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseDir::setResFile(string fullfilename,FZZBytes * filedata)
{
    if ( filedata == NULL || m_OFDFilesContainer == NULL ) {
        return;
    }
    m_OFDFilesContainer->updateFile(m_Root,fullfilename,(unsigned char *)(filedata->getData()),filedata->getLen() );
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDBaseDir::getPathIndex(string tempPath)
{
    transform(tempPath.begin(), tempPath.end(), tempPath.begin(), ::tolower);
    if ( tempPath[tempPath.length()-1] == '/' ) {
        tempPath = tempPath.substr(0,tempPath.length()-1);
    }
    size_t pos = tempPath.find_last_of("_");
    if ( pos != string::npos ) {
        tempPath = tempPath.substr(pos+1);
    }
    
    return (int)strtol(tempPath.c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseDir::deleteDirFile(string dirName)
{
    if ( m_OFDFilesContainer == NULL ) {
        return;
    }
    m_OFDFilesContainer->removeDirFile(m_Root, m_Path.empty() ? dirName : m_Path+dirName);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseDir::deleteResFile(string fullfilename)
{
    if ( m_OFDFilesContainer == NULL ) {
        return;
    }
    m_OFDFilesContainer->removeFile(m_Root, fullfilename);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDBaseDir::existsFile(string filename)
{
    if ( m_OFDFilesContainer == NULL ) {
        return false;
    }
    return m_OFDFilesContainer->exists(m_Root, m_Path.empty() ? filename : m_Path+filename);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBaseDir::getFileName_RelativePath(string fullpath)
{
    string strRet = fullpath;
    size_t pos = fullpath.find(m_Path);
    if ( pos != string::npos ) {
        strRet = fullpath.substr(pos+m_Path.length());
    }
    return strRet;
}
//-----------------------------------------------------------------------------------------------------------------
