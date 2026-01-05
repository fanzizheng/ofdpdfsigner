//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDCommonData.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCommonData**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData::FZZOFDCommonData() : FZZOFDXMLElementObject(),m_FZZOFDMaxUnitID(NULL),m_FZZOFDPublicRes(NULL),m_FZZOFDDocumentRes(NULL)
,m_FZZOFDDefaultCS(NULL),m_FZZOFDPageArea(NULL)
{
    //DLOG("FZZOFDCommonData()");
    FZZConst::addClassCount("FZZOFDCommonData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData::FZZOFDCommonData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDMaxUnitID(NULL),m_FZZOFDPublicRes(NULL),m_FZZOFDDocumentRes(NULL),m_FZZOFDDefaultCS(NULL),m_FZZOFDPageArea(NULL)
{
    
    FZZConst::addClassCount("FZZOFDCommonData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData::FZZOFDCommonData(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDMaxUnitID(NULL),m_FZZOFDPublicRes(NULL)
,m_FZZOFDDocumentRes(NULL),m_FZZOFDDefaultCS(NULL),m_FZZOFDPageArea(NULL)
{
    FZZConst::addClassCount("FZZOFDCommonData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData::FZZOFDCommonData(const FZZOFDCommonData& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCommonData");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDMaxUnitID = obj.m_FZZOFDMaxUnitID != NULL ? new FZZOFDMaxUnitID(*obj.m_FZZOFDMaxUnitID) : NULL;
    m_FZZOFDPublicRes = obj.m_FZZOFDPublicRes != NULL ? new FZZOFDPublicRes(*obj.m_FZZOFDPublicRes) : NULL;
    m_FZZOFDDocumentRes = obj.m_FZZOFDDocumentRes != NULL ? new FZZOFDDocumentRes(*obj.m_FZZOFDDocumentRes) : NULL;
    m_FZZOFDDefaultCS = obj.m_FZZOFDDefaultCS != NULL ? new FZZOFDDefaultCS(*obj.m_FZZOFDDefaultCS) : NULL;
    m_FZZOFDPageArea = obj.m_FZZOFDPageArea != NULL ? new FZZOFDPageArea(*obj.m_FZZOFDPageArea) : NULL;
    
    vector<FZZOFDTemplatePage*>::const_iterator itr;
    for( itr = obj.m_FZZOFDTemplatePages.begin(); itr != obj.m_FZZOFDTemplatePages.end(); itr++ ) {
        FZZOFDTemplatePage * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDTemplatePages.push_back(new FZZOFDTemplatePage(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData::~FZZOFDCommonData()
{
    //DLOG("~FZZOFDCommonData()");
    FZZConst::delClassCount("FZZOFDCommonData");
    
    if ( m_FZZOFDMaxUnitID != NULL ) {
        delete m_FZZOFDMaxUnitID;
        m_FZZOFDMaxUnitID = NULL;
    }
    if ( m_FZZOFDPublicRes != NULL ) {
        delete m_FZZOFDPublicRes;
        m_FZZOFDPublicRes = NULL;
    }
    if ( m_FZZOFDDocumentRes != NULL ) {
        delete m_FZZOFDDocumentRes;
        m_FZZOFDDocumentRes = NULL;
    }
    if ( m_FZZOFDDefaultCS != NULL ) {
        delete m_FZZOFDDefaultCS;
        m_FZZOFDDefaultCS = NULL;
    }
    if ( m_FZZOFDPageArea != NULL ) {
        delete m_FZZOFDPageArea;
        m_FZZOFDPageArea = NULL;
    }
    
    vector<FZZOFDTemplatePage*>::const_iterator itr;
    for( itr = m_FZZOFDTemplatePages.begin(); itr != m_FZZOFDTemplatePages.end(); itr++ ) {
        FZZOFDTemplatePage * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDTemplatePages.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplatePage * FZZOFDCommonData::addTemplatePage()
{
    return addElementObject(&m_FZZOFDTemplatePages,FZZOFDTEMPLATEPAGE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDTemplatePage*> * FZZOFDCommonData::getTemplatePageList()
{
    getElementObjectList(&m_FZZOFDTemplatePages,FZZOFDTEMPLATEPAGE_Name);
    return &m_FZZOFDTemplatePages;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID * FZZOFDCommonData::setMaxUnitID()
{
    return m_FZZOFDMaxUnitID = setElementObject(m_FZZOFDMaxUnitID,FZZOFDMAXUNITID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxUnitID * FZZOFDCommonData::getMaxUnitID()
{
    return m_FZZOFDMaxUnitID = getElementObject(m_FZZOFDMaxUnitID,FZZOFDMAXUNITID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes * FZZOFDCommonData::setPublicRes()
{
    return m_FZZOFDPublicRes = setElementObject(m_FZZOFDPublicRes,FZZOFDPUBLICRES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicRes * FZZOFDCommonData::getPublicRes()
{
    return m_FZZOFDPublicRes = getElementObject(m_FZZOFDPublicRes,FZZOFDPUBLICRES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes * FZZOFDCommonData::setDocumentRes()
{
    return m_FZZOFDDocumentRes = setElementObject(m_FZZOFDDocumentRes,FZZOFDDOCUMENTRES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentRes * FZZOFDCommonData::getDocumentRes()
{
    return m_FZZOFDDocumentRes = getElementObject(m_FZZOFDDocumentRes,FZZOFDDOCUMENTRES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS * FZZOFDCommonData::setDefaultCS()
{
    return m_FZZOFDDefaultCS = setElementObject(m_FZZOFDDefaultCS,FZZOFDDEFAULTCS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDefaultCS * FZZOFDCommonData::getDefaultCS()
{
    return m_FZZOFDDefaultCS = getElementObject(m_FZZOFDDefaultCS,FZZOFDDEFAULTCS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea * FZZOFDCommonData::setPageArea()
{
    return m_FZZOFDPageArea = setElementObject(m_FZZOFDPageArea,FZZOFDPAGEAREA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea * FZZOFDCommonData::getPageArea()
{
    return m_FZZOFDPageArea = getElementObject(m_FZZOFDPageArea,FZZOFDPAGEAREA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
