//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDSignDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSignDir::SealFileName = "Seal.esl";
string FZZOFDSignDir::SignedValueFileName = "SignedValue.dat";
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignDir::FZZOFDSignDir() :FZZOFDBaseDir(),m_index(0),m_SignID(""),m_FZZOFDSignatureXML(NULL)
{
    //DLOG("FZZOFDSignDir()");
    FZZConst::addClassCount("FZZOFDSignDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignDir::FZZOFDSignDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
,m_index(0),m_SignID(""),m_FZZOFDSignatureXML(NULL)
{
    FZZConst::addClassCount("FZZOFDSignDir");
    //Doc_0/Signs/
    setPath(path);
    
    m_index = getPathIndex(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignDir::~FZZOFDSignDir()
{
    //DLOG("~FZZOFDSignDir()");
    FZZConst::delClassCount("FZZOFDSignDir");
    if ( m_FZZOFDSignatureXML != NULL ) {
        delete m_FZZOFDSignatureXML;
        m_FZZOFDSignatureXML = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML* FZZOFDSignDir::getSignatureXML()
{
    if ( m_FZZOFDSignatureXML != NULL ) {
        return m_FZZOFDSignatureXML;
    }

    XMLDocument * doc = getXMLDocument(FZZOFDSIGNATUREXML_FILENAME);
    if ( doc != NULL ) {
        m_FZZOFDSignatureXML = new FZZOFDSignatureXML(doc);

    } 

    return m_FZZOFDSignatureXML;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML* FZZOFDSignDir::setSignatureXML()
{
    getSignatureXML();
    if ( m_FZZOFDSignatureXML == NULL ) {
        m_FZZOFDSignatureXML = new FZZOFDSignatureXML();
    }
    return m_FZZOFDSignatureXML;
}
//-----------------------------------------------------------------------------------------------------------------
