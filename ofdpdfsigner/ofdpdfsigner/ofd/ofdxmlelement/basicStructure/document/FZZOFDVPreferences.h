//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDVPREFERENCES_H
#define FZZOFDVPREFERENCES_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDZoom.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDZoomMode.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDHideWindowUI.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDHideMenubar.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDHideToolbar.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDTabDisplay.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageLayout.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageMode.h"

#define FZZOFDVPREFERENCES_Name "ofd:VPreferences"

class FZZOFDVPreferences : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDVPreferences(FZZOFDXMLFileObject * parent);
    FZZOFDVPreferences(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDVPreferences(const FZZOFDVPreferences& obj);
    virtual ~FZZOFDVPreferences();
    
public:
    FZZOFDPageMode * setPageMode();
    FZZOFDPageMode * getPageMode();
    FZZOFDPageLayout * setPageLayout();
    FZZOFDPageLayout * getPageLayout();
    FZZOFDTabDisplay * setTabDisplay();
    FZZOFDTabDisplay * getTabDisplay();
    FZZOFDHideToolbar * setHideToolbar();
    FZZOFDHideToolbar * getHideToolbar();
    FZZOFDHideMenubar * setHideMenubar();
    FZZOFDHideMenubar * getHideMenubar();
    FZZOFDHideWindowUI * setHideWindowUI();
    FZZOFDHideWindowUI * getHideWindowUI();
    //Zoom 和 ZoomMode 只能有一个存在，因此获取的时候要判断有哪一个并使用
    FZZOFDZoom * setZoom();
    FZZOFDZoom * getZoom();
    FZZOFDZoomMode * setZoomMode();
    FZZOFDZoomMode * getZoomMode();

    
protected:
    FZZOFDVPreferences();
private:
    FZZOFDZoom * m_FZZOFDZoom;
    FZZOFDZoomMode * m_FZZOFDZoomMode;
    FZZOFDHideWindowUI * m_FZZOFDHideWindowUI;
    FZZOFDHideMenubar * m_FZZOFDHideMenubar;
    FZZOFDHideToolbar * m_FZZOFDHideToolbar;
    FZZOFDTabDisplay * m_FZZOFDTabDisplay;
    FZZOFDPageLayout * m_FZZOFDPageLayout;
    FZZOFDPageMode * m_FZZOFDPageMode;
};

#endif //FZZOFDVPREFERENCES_H
