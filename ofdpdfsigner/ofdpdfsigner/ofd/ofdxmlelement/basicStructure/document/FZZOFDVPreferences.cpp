//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDVPreferences.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDVPreferences**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences::FZZOFDVPreferences() : FZZOFDXMLElementObject(),m_FZZOFDZoom(NULL),m_FZZOFDZoomMode(NULL),m_FZZOFDHideWindowUI(NULL)
,m_FZZOFDHideMenubar(NULL),m_FZZOFDHideToolbar(NULL),m_FZZOFDTabDisplay(NULL),m_FZZOFDPageLayout(NULL),m_FZZOFDPageMode(NULL)
{
    //DLOG("FZZOFDVPreferences()");
    FZZConst::addClassCount("FZZOFDVPreferences");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences::FZZOFDVPreferences(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDZoom(NULL),m_FZZOFDZoomMode(NULL),m_FZZOFDHideWindowUI(NULL),m_FZZOFDHideMenubar(NULL),m_FZZOFDHideToolbar(NULL),m_FZZOFDTabDisplay(NULL)
,m_FZZOFDPageLayout(NULL),m_FZZOFDPageMode(NULL)
{
    
    FZZConst::addClassCount("FZZOFDVPreferences");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences::FZZOFDVPreferences(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDZoom(NULL),m_FZZOFDZoomMode(NULL)
,m_FZZOFDHideWindowUI(NULL),m_FZZOFDHideMenubar(NULL),m_FZZOFDHideToolbar(NULL),m_FZZOFDTabDisplay(NULL),m_FZZOFDPageLayout(NULL),m_FZZOFDPageMode(NULL)
{
    FZZConst::addClassCount("FZZOFDVPreferences");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences::FZZOFDVPreferences(const FZZOFDVPreferences& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDVPreferences");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDZoom = obj.m_FZZOFDZoom != NULL ? new FZZOFDZoom(*obj.m_FZZOFDZoom) : NULL;
    m_FZZOFDZoomMode = obj.m_FZZOFDZoomMode != NULL ? new FZZOFDZoomMode(*obj.m_FZZOFDZoomMode) : NULL;
    m_FZZOFDHideWindowUI = obj.m_FZZOFDHideWindowUI != NULL ? new FZZOFDHideWindowUI(*obj.m_FZZOFDHideWindowUI) : NULL;
    m_FZZOFDHideMenubar = obj.m_FZZOFDHideMenubar != NULL ? new FZZOFDHideMenubar(*obj.m_FZZOFDHideMenubar) : NULL;
    m_FZZOFDHideToolbar = obj.m_FZZOFDHideToolbar != NULL ? new FZZOFDHideToolbar(*obj.m_FZZOFDHideToolbar) : NULL;
    m_FZZOFDTabDisplay = obj.m_FZZOFDTabDisplay != NULL ? new FZZOFDTabDisplay(*obj.m_FZZOFDTabDisplay) : NULL;
    m_FZZOFDPageLayout = obj.m_FZZOFDPageLayout != NULL ? new FZZOFDPageLayout(*obj.m_FZZOFDPageLayout) : NULL;
    m_FZZOFDPageMode = obj.m_FZZOFDPageMode != NULL ? new FZZOFDPageMode(*obj.m_FZZOFDPageMode) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences::~FZZOFDVPreferences()
{
    //DLOG("~FZZOFDVPreferences()");
    FZZConst::delClassCount("FZZOFDVPreferences");
    if ( m_FZZOFDZoom != NULL ) {
        delete m_FZZOFDZoom;
        m_FZZOFDZoom = NULL;
    }
    if ( m_FZZOFDZoomMode != NULL ) {
        delete m_FZZOFDZoomMode;
        m_FZZOFDZoomMode = NULL;
    }
    if ( m_FZZOFDHideWindowUI != NULL ) {
        delete m_FZZOFDHideWindowUI;
        m_FZZOFDHideWindowUI = NULL;
    }
    if ( m_FZZOFDHideMenubar != NULL ) {
        delete m_FZZOFDHideMenubar;
        m_FZZOFDHideMenubar = NULL;
    }
    if ( m_FZZOFDHideToolbar != NULL ) {
        delete m_FZZOFDHideToolbar;
        m_FZZOFDHideToolbar = NULL;
    }
    if ( m_FZZOFDTabDisplay != NULL ) {
        delete m_FZZOFDTabDisplay;
        m_FZZOFDTabDisplay = NULL;
    }
    if ( m_FZZOFDPageLayout != NULL ) {
        delete m_FZZOFDPageLayout;
        m_FZZOFDPageLayout = NULL;
    }
    if ( m_FZZOFDPageMode != NULL ) {
        delete m_FZZOFDPageMode;
        m_FZZOFDPageMode = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom * FZZOFDVPreferences::setZoom()
{
    if ( m_FZZOFDZoomMode != NULL ) {
        delete m_FZZOFDZoomMode;
        m_FZZOFDZoomMode = NULL;
    }
    deleteElement(FZZOFDZOOMMODE_Name);
    return m_FZZOFDZoom = setElementObject(m_FZZOFDZoom,FZZOFDZOOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoom * FZZOFDVPreferences::getZoom()
{
    return m_FZZOFDZoom = getElementObject(m_FZZOFDZoom,FZZOFDZOOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode * FZZOFDVPreferences::setZoomMode()
{
    if ( m_FZZOFDZoom != NULL ) {
        delete m_FZZOFDZoom;
        m_FZZOFDZoom = NULL;
    }
    deleteElement(FZZOFDZOOM_Name);
    return m_FZZOFDZoomMode = setElementObject(m_FZZOFDZoomMode,FZZOFDZOOMMODE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDZoomMode * FZZOFDVPreferences::getZoomMode()
{
    return m_FZZOFDZoomMode = getElementObject(m_FZZOFDZoomMode,FZZOFDZOOMMODE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI * FZZOFDVPreferences::setHideWindowUI()
{
    return m_FZZOFDHideWindowUI = setElementObject(m_FZZOFDHideWindowUI,FZZOFDHIDEWINDOWUI_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideWindowUI * FZZOFDVPreferences::getHideWindowUI()
{
    return m_FZZOFDHideWindowUI = getElementObject(m_FZZOFDHideWindowUI,FZZOFDHIDEWINDOWUI_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar * FZZOFDVPreferences::setHideMenubar()
{
    return m_FZZOFDHideMenubar = setElementObject(m_FZZOFDHideMenubar,FZZOFDHIDEMENUBAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideMenubar * FZZOFDVPreferences::getHideMenubar()
{
    return m_FZZOFDHideMenubar = getElementObject(m_FZZOFDHideMenubar,FZZOFDHIDEMENUBAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar * FZZOFDVPreferences::setHideToolbar()
{
    return m_FZZOFDHideToolbar = setElementObject(m_FZZOFDHideToolbar,FZZOFDHIDETOOLBAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDHideToolbar * FZZOFDVPreferences::getHideToolbar()
{
    return m_FZZOFDHideToolbar = getElementObject(m_FZZOFDHideToolbar,FZZOFDHIDETOOLBAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay * FZZOFDVPreferences::setTabDisplay()
{
    return m_FZZOFDTabDisplay = setElementObject(m_FZZOFDTabDisplay,FZZOFDTABDISPLAY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTabDisplay * FZZOFDVPreferences::getTabDisplay()
{
    return m_FZZOFDTabDisplay = getElementObject(m_FZZOFDTabDisplay,FZZOFDTABDISPLAY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout * FZZOFDVPreferences::setPageLayout()
{
    return m_FZZOFDPageLayout = setElementObject(m_FZZOFDPageLayout,FZZOFDPAGELAYOUT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout * FZZOFDVPreferences::getPageLayout()
{
    return m_FZZOFDPageLayout = getElementObject(m_FZZOFDPageLayout,FZZOFDPAGELAYOUT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode * FZZOFDVPreferences::setPageMode()
{
    return m_FZZOFDPageMode = setElementObject(m_FZZOFDPageMode,FZZOFDPAGEMODE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageMode * FZZOFDVPreferences::getPageMode()
{
    return m_FZZOFDPageMode = getElementObject(m_FZZOFDPageMode,FZZOFDPAGEMODE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
