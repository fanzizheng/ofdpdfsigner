//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocInfo**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo::FZZOFDDocInfo() : FZZOFDXMLElementObject(),m_FZZOFDDocUsage(NULL),m_FZZOFDDocInfo_Keywords(NULL),m_FZZOFDCustomDatas(NULL),
m_FZZOFDCover(NULL),m_FZZOFDDocID(NULL),m_FZZOFDTitle(NULL),m_FZZOFDAuthor(NULL),m_FZZOFDSubjec(NULL),m_FZZOFDAbstract(NULL),
m_FZZOFDCreationDate(NULL),m_FZZOFDModDate(NULL),m_FZZOFDCreator(NULL),m_FZZOFDCreatorVersion(NULL)
{

    FZZConst::addClassCount("FZZOFDDocInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo::FZZOFDDocInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true),m_FZZOFDDocUsage(NULL),m_FZZOFDDocInfo_Keywords(NULL),m_FZZOFDCustomDatas(NULL),
m_FZZOFDCover(NULL),m_FZZOFDDocID(NULL),m_FZZOFDTitle(NULL),m_FZZOFDAuthor(NULL),m_FZZOFDSubjec(NULL),m_FZZOFDAbstract(NULL),
m_FZZOFDCreationDate(NULL),m_FZZOFDModDate(NULL),m_FZZOFDCreator(NULL),m_FZZOFDCreatorVersion(NULL)
{

    FZZConst::addClassCount("FZZOFDDocInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo::FZZOFDDocInfo(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDDocUsage(NULL),m_FZZOFDDocInfo_Keywords(NULL),
m_FZZOFDCustomDatas(NULL),m_FZZOFDCover(NULL),m_FZZOFDDocID(NULL),m_FZZOFDTitle(NULL),m_FZZOFDAuthor(NULL),m_FZZOFDSubjec(NULL),m_FZZOFDAbstract(NULL),
m_FZZOFDCreationDate(NULL),m_FZZOFDModDate(NULL),m_FZZOFDCreator(NULL),m_FZZOFDCreatorVersion(NULL)
{
    FZZConst::addClassCount("FZZOFDDocInfo");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo::FZZOFDDocInfo(const FZZOFDDocInfo& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDDocInfo");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDDocUsage = obj.m_FZZOFDDocUsage != NULL ? new FZZOFDDocUsage(*obj.m_FZZOFDDocUsage) : NULL;
    m_FZZOFDDocInfo_Keywords = obj.m_FZZOFDDocInfo_Keywords != NULL ? new FZZOFDDocInfo_Keywords(*obj.m_FZZOFDDocInfo_Keywords) : NULL;
    m_FZZOFDCustomDatas = obj.m_FZZOFDCustomDatas != NULL ? new FZZOFDCustomDatas(*obj.m_FZZOFDCustomDatas) : NULL;
    m_FZZOFDCover = obj.m_FZZOFDCover != NULL ? new FZZOFDCover(*obj.m_FZZOFDCover) : NULL;
    m_FZZOFDDocID = obj.m_FZZOFDDocID != NULL ? new FZZOFDDocID(*obj.m_FZZOFDDocID) : NULL;
    m_FZZOFDTitle = obj.m_FZZOFDTitle != NULL ? new FZZOFDTitle(*obj.m_FZZOFDTitle) : NULL;
    m_FZZOFDAuthor = obj.m_FZZOFDAuthor != NULL ? new FZZOFDAuthor(*obj.m_FZZOFDAuthor) : NULL;
    m_FZZOFDSubjec = obj.m_FZZOFDSubjec != NULL ? new FZZOFDSubjec(*obj.m_FZZOFDSubjec) : NULL;
    m_FZZOFDAbstract = obj.m_FZZOFDAbstract != NULL ? new FZZOFDAbstract(*obj.m_FZZOFDAbstract) : NULL;
    m_FZZOFDCreationDate = obj.m_FZZOFDCreationDate != NULL ? new FZZOFDCreationDate(*obj.m_FZZOFDCreationDate) : NULL;
    m_FZZOFDModDate = obj.m_FZZOFDModDate != NULL ? new FZZOFDModDate(*obj.m_FZZOFDModDate) : NULL;
    m_FZZOFDCreator = obj.m_FZZOFDCreator != NULL ? new FZZOFDCreator(*obj.m_FZZOFDCreator) : NULL;
    m_FZZOFDCreatorVersion = obj.m_FZZOFDCreatorVersion != NULL ? new FZZOFDCreatorVersion(*obj.m_FZZOFDCreatorVersion) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo::~FZZOFDDocInfo()
{

    FZZConst::delClassCount("FZZOFDDocInfo");
    if ( m_FZZOFDDocUsage != NULL ) {
        delete m_FZZOFDDocUsage;
        m_FZZOFDDocUsage = NULL;
    }
    if ( m_FZZOFDDocInfo_Keywords != NULL ) {
        delete m_FZZOFDDocInfo_Keywords;
        m_FZZOFDDocInfo_Keywords = NULL;
    }
    if ( m_FZZOFDCustomDatas != NULL ) {
        delete m_FZZOFDCustomDatas;
        m_FZZOFDCustomDatas = NULL;
    }
    if ( m_FZZOFDCover != NULL ) {
        delete m_FZZOFDCover;
        m_FZZOFDCover = NULL;
    }
    if ( m_FZZOFDDocID != NULL ) {
        delete m_FZZOFDDocID;
        m_FZZOFDDocID = NULL;
    }
    if ( m_FZZOFDTitle != NULL ) {
        delete m_FZZOFDTitle;
        m_FZZOFDTitle = NULL;
    }
    if ( m_FZZOFDAuthor != NULL ) {
        delete m_FZZOFDAuthor;
        m_FZZOFDAuthor = NULL;
    }
    if ( m_FZZOFDSubjec != NULL ) {
        delete m_FZZOFDSubjec;
        m_FZZOFDSubjec = NULL;
    }
    if ( m_FZZOFDAbstract != NULL ) {
        delete m_FZZOFDAbstract;
        m_FZZOFDAbstract = NULL;
    }
    if ( m_FZZOFDCreationDate != NULL ) {
        delete m_FZZOFDCreationDate;
        m_FZZOFDCreationDate = NULL;
    }
    if ( m_FZZOFDModDate != NULL ) {
        delete m_FZZOFDModDate;
        m_FZZOFDModDate = NULL;
    }
    if ( m_FZZOFDCreator != NULL ) {
        delete m_FZZOFDCreator;
        m_FZZOFDCreator = NULL;
    }
    if ( m_FZZOFDCreatorVersion != NULL ) {
        delete m_FZZOFDCreatorVersion;
        m_FZZOFDCreatorVersion = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZOFDDocBody::setExt(string value)
//{
//    setAttribute_String("v:ext",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZOFDDocBody::getExt()
//{
//    return getAttribute_String("v:ext");
//}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage * FZZOFDDocInfo::setDocUsage()
{
    return m_FZZOFDDocUsage = setElementObject(m_FZZOFDDocUsage,FZZOFDDOCUSAGE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage * FZZOFDDocInfo::getDocUsage()
{
    return m_FZZOFDDocUsage = getElementObject(m_FZZOFDDocUsage,FZZOFDDOCUSAGE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords * FZZOFDDocInfo::setKeywords()
{
    return m_FZZOFDDocInfo_Keywords = setElementObject(m_FZZOFDDocInfo_Keywords,FZZOFDDOCINFOKEYWORDS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords * FZZOFDDocInfo::getKeywords()
{
    return m_FZZOFDDocInfo_Keywords = getElementObject(m_FZZOFDDocInfo_Keywords,FZZOFDDOCINFOKEYWORDS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas * FZZOFDDocInfo::setCustomDatas()
{
    return m_FZZOFDCustomDatas = setElementObject(m_FZZOFDCustomDatas,FZZOFDCUSTOMDATAS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas * FZZOFDDocInfo::getCustomDatas()
{
    return m_FZZOFDCustomDatas = getElementObject(m_FZZOFDCustomDatas,FZZOFDCUSTOMDATAS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover * FZZOFDDocInfo::setCover()
{
    return m_FZZOFDCover = setElementObject(m_FZZOFDCover,FZZOFDCOVER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCover * FZZOFDDocInfo::getCover()
{
    return m_FZZOFDCover = getElementObject(m_FZZOFDCover,FZZOFDCOVER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID * FZZOFDDocInfo::setDocID()
{
    return m_FZZOFDDocID = setElementObject(m_FZZOFDDocID,FZZOFDDOCID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocID * FZZOFDDocInfo::getDocID()
{
    return m_FZZOFDDocID = getElementObject(m_FZZOFDDocID,FZZOFDDOCID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle * FZZOFDDocInfo::setTitle()
{
    return m_FZZOFDTitle = setElementObject(m_FZZOFDTitle,FZZOFDTITLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTitle * FZZOFDDocInfo::getTitle()
{
    return m_FZZOFDTitle = getElementObject(m_FZZOFDTitle,FZZOFDTITLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor * FZZOFDDocInfo::setAuthor()
{
    return m_FZZOFDAuthor = setElementObject(m_FZZOFDAuthor,FZZOFDAUTHOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor * FZZOFDDocInfo::getAuthor()
{
    return m_FZZOFDAuthor = getElementObject(m_FZZOFDAuthor,FZZOFDAUTHOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec * FZZOFDDocInfo::setSubjec()
{
    return m_FZZOFDSubjec = setElementObject(m_FZZOFDSubjec,FZZOFDSUBJEC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec * FZZOFDDocInfo::getSubjec()
{
    return m_FZZOFDSubjec = getElementObject(m_FZZOFDSubjec,FZZOFDSUBJEC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract * FZZOFDDocInfo::setAbstract()
{
    return m_FZZOFDAbstract = setElementObject(m_FZZOFDAbstract,FZZOFDABSTRACT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbstract * FZZOFDDocInfo::getAbstract()
{
    return m_FZZOFDAbstract = getElementObject(m_FZZOFDAbstract,FZZOFDABSTRACT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate * FZZOFDDocInfo::setCreationDate()
{
    return m_FZZOFDCreationDate = setElementObject(m_FZZOFDCreationDate,FZZOFDCREATIONDATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreationDate * FZZOFDDocInfo::getCreationDate()
{
    return m_FZZOFDCreationDate = getElementObject(m_FZZOFDCreationDate,FZZOFDCREATIONDATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate * FZZOFDDocInfo::setModDate()
{
    return m_FZZOFDModDate = setElementObject(m_FZZOFDModDate,FZZOFDMODDATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDModDate * FZZOFDDocInfo::getModDate()
{
    return m_FZZOFDModDate = getElementObject(m_FZZOFDModDate,FZZOFDMODDATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator * FZZOFDDocInfo::setCreator()
{
    return m_FZZOFDCreator = setElementObject(m_FZZOFDCreator,FZZOFDCREATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreator * FZZOFDDocInfo::getCreator()
{
    return m_FZZOFDCreator = getElementObject(m_FZZOFDCreator,FZZOFDCREATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion * FZZOFDDocInfo::setCreatorVersion()
{
    return m_FZZOFDCreatorVersion = setElementObject(m_FZZOFDCreatorVersion,FZZOFDCREATORVERSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCreatorVersion * FZZOFDDocInfo::getCreatorVersion()
{
    return m_FZZOFDCreatorVersion = getElementObject(m_FZZOFDCreatorVersion,FZZOFDCREATORVERSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
