//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPermission.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPermission**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission::FZZOFDPermission() : FZZOFDXMLElementObject(),m_FZZOFDPrint(NULL),m_FZZOFDValidPeriod(NULL),m_FZZOFDEdit(NULL)
,m_FZZOFDAnnot(NULL),m_FZZOFDExport(NULL),m_FZZOFDWatermark(NULL),m_FZZOFDSignature_Permission(NULL),m_FZZOFDPrintScreen(NULL)
{
    //DLOG("FZZOFDPermission()");
    FZZConst::addClassCount("FZZOFDPermission");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission::FZZOFDPermission(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDPrint(NULL),m_FZZOFDValidPeriod(NULL),m_FZZOFDEdit(NULL),m_FZZOFDAnnot(NULL),m_FZZOFDExport(NULL),m_FZZOFDWatermark(NULL),m_FZZOFDSignature_Permission(NULL),m_FZZOFDPrintScreen(NULL)
{
    
    FZZConst::addClassCount("FZZOFDPermission");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission::FZZOFDPermission(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDPrint(NULL),m_FZZOFDValidPeriod(NULL)
,m_FZZOFDEdit(NULL),m_FZZOFDAnnot(NULL),m_FZZOFDExport(NULL),m_FZZOFDWatermark(NULL),m_FZZOFDSignature_Permission(NULL),m_FZZOFDPrintScreen(NULL)
{
    FZZConst::addClassCount("FZZOFDPermission");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission::FZZOFDPermission(const FZZOFDPermission& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPermission");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDPrint = obj.m_FZZOFDPrint != NULL ? new FZZOFDPrint(*obj.m_FZZOFDPrint) : NULL;
    m_FZZOFDValidPeriod = obj.m_FZZOFDValidPeriod != NULL ? new FZZOFDValidPeriod(*obj.m_FZZOFDValidPeriod) : NULL;
    m_FZZOFDEdit = obj.m_FZZOFDEdit != NULL ? new FZZOFDEdit(*obj.m_FZZOFDEdit) : NULL;
    m_FZZOFDAnnot = obj.m_FZZOFDAnnot != NULL ? new FZZOFDAnnot(*obj.m_FZZOFDAnnot) : NULL;
    m_FZZOFDExport = obj.m_FZZOFDExport != NULL ? new FZZOFDExport(*obj.m_FZZOFDExport) : NULL;
    m_FZZOFDWatermark = obj.m_FZZOFDWatermark != NULL ? new FZZOFDWatermark(*obj.m_FZZOFDWatermark) : NULL;
    m_FZZOFDSignature_Permission = obj.m_FZZOFDSignature_Permission != NULL ? new FZZOFDSignature_Permission(*obj.m_FZZOFDSignature_Permission) : NULL;
    m_FZZOFDPrintScreen = obj.m_FZZOFDPrintScreen != NULL ? new FZZOFDPrintScreen(*obj.m_FZZOFDPrintScreen) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission::~FZZOFDPermission()
{
    //DLOG("~FZZOFDPermission()");
    FZZConst::delClassCount("FZZOFDPermission");
    if ( m_FZZOFDPrint != NULL ) {
        delete m_FZZOFDPrint;
        m_FZZOFDPrint = NULL;
    }
    if ( m_FZZOFDValidPeriod != NULL ) {
        delete m_FZZOFDValidPeriod;
        m_FZZOFDValidPeriod = NULL;
    }
    if ( m_FZZOFDEdit != NULL ) {
        delete m_FZZOFDEdit;
        m_FZZOFDEdit = NULL;
    }
    if ( m_FZZOFDAnnot != NULL ) {
        delete m_FZZOFDAnnot;
        m_FZZOFDAnnot = NULL;
    }
    if ( m_FZZOFDExport != NULL ) {
        delete m_FZZOFDExport;
        m_FZZOFDExport = NULL;
    }
    if ( m_FZZOFDWatermark != NULL ) {
        delete m_FZZOFDWatermark;
        m_FZZOFDWatermark = NULL;
    }
    if ( m_FZZOFDSignature_Permission != NULL ) {
        delete m_FZZOFDSignature_Permission;
        m_FZZOFDSignature_Permission = NULL;
    }
    if ( m_FZZOFDPrintScreen != NULL ) {
        delete m_FZZOFDPrintScreen;
        m_FZZOFDPrintScreen = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint * FZZOFDPermission::setPrint()
{
    return m_FZZOFDPrint = setElementObject(m_FZZOFDPrint,FZZOFDPRINT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint * FZZOFDPermission::getPrint()
{
    return m_FZZOFDPrint = getElementObject(m_FZZOFDPrint,FZZOFDPRINT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod * FZZOFDPermission::setValidPeriod()
{
    return m_FZZOFDValidPeriod = setElementObject(m_FZZOFDValidPeriod,FZZOFDVALIDPERIOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod * FZZOFDPermission::getValidPeriod()
{
    return m_FZZOFDValidPeriod = getElementObject(m_FZZOFDValidPeriod,FZZOFDVALIDPERIOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit * FZZOFDPermission::setEdit()
{
    return m_FZZOFDEdit = setElementObject(m_FZZOFDEdit,FZZOFDEDIT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEdit * FZZOFDPermission::getEdit()
{
    return m_FZZOFDEdit = getElementObject(m_FZZOFDEdit,FZZOFDEDIT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot * FZZOFDPermission::setAnnot()
{
    return m_FZZOFDAnnot = setElementObject(m_FZZOFDAnnot,FZZOFDANNOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot * FZZOFDPermission::getAnnot()
{
    return m_FZZOFDAnnot = getElementObject(m_FZZOFDAnnot,FZZOFDANNOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport * FZZOFDPermission::setExport()
{
    return m_FZZOFDExport = setElementObject(m_FZZOFDExport,FZZOFDEXPORT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExport * FZZOFDPermission::getExport()
{
    return m_FZZOFDExport = getElementObject(m_FZZOFDExport,FZZOFDEXPORT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark * FZZOFDPermission::setWatermark()
{
    return m_FZZOFDWatermark = setElementObject(m_FZZOFDWatermark,FZZOFDWATERMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWatermark * FZZOFDPermission::getWatermark()
{
    return m_FZZOFDWatermark = getElementObject(m_FZZOFDWatermark,FZZOFDWATERMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission * FZZOFDPermission::setSignature()
{
    return m_FZZOFDSignature_Permission = setElementObject(m_FZZOFDSignature_Permission,FZZOFDSIGNATURE_PERMISSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature_Permission * FZZOFDPermission::getSignature()
{
    return m_FZZOFDSignature_Permission = getElementObject(m_FZZOFDSignature_Permission,FZZOFDSIGNATURE_PERMISSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen * FZZOFDPermission::setPrintScreen()
{
    return m_FZZOFDPrintScreen = setElementObject(m_FZZOFDPrintScreen,FZZOFDPRINTSCREEN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrintScreen * FZZOFDPermission::getPrintScreen()
{
    return m_FZZOFDPrintScreen = getElementObject(m_FZZOFDPrintScreen,FZZOFDPRINTSCREEN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
