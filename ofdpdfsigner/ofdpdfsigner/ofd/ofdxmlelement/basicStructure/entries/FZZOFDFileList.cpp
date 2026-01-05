//
//  Created by zizheng fan on 2024/09/25.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/entries/FZZOFDFileList.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDFileList**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList::FZZOFDFileList() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDFileList()");
    FZZConst::addClassCount("FZZOFDFileList");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList::FZZOFDFileList(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDFileList");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList::FZZOFDFileList(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDFileList");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList::FZZOFDFileList(const FZZOFDFileList& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDFileList");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDFile*>::const_iterator p_itr;
    for( p_itr = obj.m_FZZOFDFiles.begin(); p_itr != obj.m_FZZOFDFiles.end(); p_itr++ ) {
        FZZOFDFile * temp = *p_itr;
        if ( temp != NULL ) {
            m_FZZOFDFiles.push_back(new FZZOFDFile(*temp));
        }
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList::~FZZOFDFileList()
{
    //DLOG("~FZZOFDFileList()");
    FZZConst::delClassCount("FZZOFDFileList");
    
    vector<FZZOFDFile*>::const_iterator p_itr;
    for( p_itr = m_FZZOFDFiles.begin(); p_itr != m_FZZOFDFiles.end(); p_itr++ ) {
        FZZOFDFile * temp = *p_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDFiles.clear();
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFile * FZZOFDFileList::addFile()
{
    return addElementObject(&m_FZZOFDFiles,FZZOFDFILE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDFile*> * FZZOFDFileList::getFileList()
{
    getElementObjectList(&m_FZZOFDFiles,FZZOFDFILE_Name);
    return &m_FZZOFDFiles;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFileList::clearFile()
{
    vector<FZZOFDFile*>::const_iterator p_itr;
    for( p_itr = m_FZZOFDFiles.begin(); p_itr != m_FZZOFDFiles.end(); p_itr++ ) {
        FZZOFDFile * temp = *p_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDFiles.clear();
    
    clearElementObjectList(FZZOFDFILE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
