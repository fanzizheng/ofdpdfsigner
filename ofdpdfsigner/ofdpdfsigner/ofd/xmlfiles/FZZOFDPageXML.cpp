//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDPageXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML::FZZOFDPageXML() : FZZOFDXMLFileObject(),m_FZZOFDPageArea(NULL),m_FZZOFDContent(NULL),m_FZZOFDActions(NULL),m_index(-999)
{
    //DLOG("FZZOFDPageXML()");
    FZZConst::addClassCount("FZZOFDPageXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Page");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDPAGEXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML::FZZOFDPageXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_FZZOFDPageArea(NULL),m_FZZOFDContent(NULL),m_index(-999)
,m_FZZOFDActions(NULL)
{
    FZZConst::addClassCount("FZZOFDPageXML");
    m_FileName = FZZOFDPAGEXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML::FZZOFDPageXML(const FZZOFDPageXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDPageXML");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDPageArea = obj.m_FZZOFDPageArea != NULL ? new FZZOFDPageArea(*obj.m_FZZOFDPageArea) : NULL;
    m_FZZOFDContent = obj.m_FZZOFDContent != NULL ? new FZZOFDContent(*obj.m_FZZOFDContent) : NULL;
    m_FZZOFDActions = obj.m_FZZOFDActions != NULL ? new FZZOFDActions(*obj.m_FZZOFDActions) : NULL;
    
    vector<FZZOFDTemplate*>::const_iterator t_itr;
    for( t_itr = obj.m_FZZOFDTemplates.begin(); t_itr != obj.m_FZZOFDTemplates.end(); t_itr++ ) {
        FZZOFDTemplate * temp = *t_itr;
        if ( temp != NULL ) {
            m_FZZOFDTemplates.push_back(new FZZOFDTemplate(*temp));
        }
    }
    
    vector<FZZOFDPageRes*>::const_iterator r_itr;
    for( r_itr = obj.m_FZZOFDPageRess.begin(); r_itr != obj.m_FZZOFDPageRess.end(); r_itr++ ) {
        FZZOFDPageRes * temp = *r_itr;
        if ( temp != NULL ) {
            m_FZZOFDPageRess.push_back(new FZZOFDPageRes(*temp));
        }
    }
    
    m_index = obj.m_index;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML::~FZZOFDPageXML()
{
    //DLOG("~FZZOFDPageXML()");
    FZZConst::delClassCount("FZZOFDPageXML");
    if ( m_FZZOFDPageArea != NULL ) {
        delete m_FZZOFDPageArea;
        m_FZZOFDPageArea = NULL;
    }
    if ( m_FZZOFDContent != NULL ) {
        delete m_FZZOFDContent;
        m_FZZOFDContent = NULL;
    }
    if ( m_FZZOFDActions != NULL ) {
        delete m_FZZOFDActions;
        m_FZZOFDActions = NULL;
    }
    vector<FZZOFDTemplate *>::const_iterator t_itr;
    for( t_itr = m_FZZOFDTemplates.begin(); t_itr != m_FZZOFDTemplates.end(); t_itr++ ) {
        FZZOFDTemplate * temp = *t_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDTemplates.clear();
    
    vector<FZZOFDPageRes *>::const_iterator r_itr;
    for( r_itr = m_FZZOFDPageRess.begin(); r_itr != m_FZZOFDPageRess.end(); r_itr++ ) {
        FZZOFDPageRes * temp = *r_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDPageRess.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea * FZZOFDPageXML::setPageArea()
{
    return m_FZZOFDPageArea = setElementObject(m_FZZOFDPageArea,FZZOFDPAGEAREA_EXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea * FZZOFDPageXML::getPageArea()
{
    return m_FZZOFDPageArea = getElementObject(m_FZZOFDPageArea,FZZOFDPAGEAREA_EXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent * FZZOFDPageXML::setContent()
{
    return m_FZZOFDContent = setElementObject(m_FZZOFDContent,FZZOFDCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent * FZZOFDPageXML::getContent()
{
    return m_FZZOFDContent = getElementObject(m_FZZOFDContent,FZZOFDCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDPageXML::setActions()
{
    return m_FZZOFDActions = setElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDPageXML::getActions()
{
    return m_FZZOFDActions = getElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDTemplate*>* FZZOFDPageXML::getTemplateList()
{
    getElementObjectList(&m_FZZOFDTemplates,FZZOFDTEMPLATE_Name);
    return &m_FZZOFDTemplates;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTemplate* FZZOFDPageXML::addTemplate()
{
    return addElementObject(&m_FZZOFDTemplates,FZZOFDTEMPLATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPageRes*>* FZZOFDPageXML::getPageResList()
{
    getElementObjectList(&m_FZZOFDPageRess,FZZOFDPAGERES_Name);
    return &m_FZZOFDPageRess;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageRes* FZZOFDPageXML::addPageRes()
{
    return addElementObject(&m_FZZOFDPageRess,FZZOFDPAGERES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
