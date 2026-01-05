//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageArea.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageArea**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea::FZZOFDPageArea() : FZZOFDXMLElementObject(),m_FZZOFDPhysicalBox(NULL),m_FZZOFDApplicationBox(NULL),m_FZZOFDContentBox(NULL)
,m_FZZOFDBleedBox(NULL),m_FZZOFDCropBox(NULL)
{
    //DLOG("FZZOFDPageArea()");
    FZZConst::addClassCount("FZZOFDPageArea");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea::FZZOFDPageArea(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDPhysicalBox(NULL),m_FZZOFDApplicationBox(NULL),m_FZZOFDContentBox(NULL),m_FZZOFDBleedBox(NULL),m_FZZOFDCropBox(NULL)
{
    
    FZZConst::addClassCount("FZZOFDPageArea");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea::FZZOFDPageArea(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDPhysicalBox(NULL)
,m_FZZOFDApplicationBox(NULL),m_FZZOFDContentBox(NULL),m_FZZOFDBleedBox(NULL),m_FZZOFDCropBox(NULL)
{
    FZZConst::addClassCount("FZZOFDPageArea");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea::FZZOFDPageArea(const FZZOFDPageArea& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPageArea");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDPhysicalBox = obj.m_FZZOFDPhysicalBox != NULL ? new FZZOFDPhysicalBox(*obj.m_FZZOFDPhysicalBox) : NULL;
    m_FZZOFDApplicationBox = obj.m_FZZOFDApplicationBox != NULL ? new FZZOFDApplicationBox(*obj.m_FZZOFDApplicationBox) : NULL;
    m_FZZOFDContentBox = obj.m_FZZOFDContentBox != NULL ? new FZZOFDContentBox(*obj.m_FZZOFDContentBox) : NULL;
    m_FZZOFDBleedBox = obj.m_FZZOFDBleedBox != NULL ? new FZZOFDBleedBox(*obj.m_FZZOFDBleedBox) : NULL;
    m_FZZOFDCropBox = obj.m_FZZOFDCropBox != NULL ? new FZZOFDCropBox(*obj.m_FZZOFDCropBox) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageArea::~FZZOFDPageArea()
{
    //DLOG("~FZZOFDPageArea()");
    FZZConst::delClassCount("FZZOFDPageArea");
    if ( m_FZZOFDPhysicalBox != NULL ) {
        delete m_FZZOFDPhysicalBox;
        m_FZZOFDPhysicalBox = NULL;
    }
    if ( m_FZZOFDApplicationBox != NULL ) {
        delete m_FZZOFDApplicationBox;
        m_FZZOFDApplicationBox = NULL;
    }
    if ( m_FZZOFDContentBox != NULL ) {
        delete m_FZZOFDContentBox;
        m_FZZOFDContentBox = NULL;
    }
    if ( m_FZZOFDBleedBox != NULL ) {
        delete m_FZZOFDBleedBox;
        m_FZZOFDBleedBox = NULL;
    }
    if ( m_FZZOFDCropBox != NULL ) {
        delete m_FZZOFDCropBox;
        m_FZZOFDCropBox = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox * FZZOFDPageArea::setPhysicalBox()
{
    return m_FZZOFDPhysicalBox = setElementObject(m_FZZOFDPhysicalBox,FZZOFDPHYSICALBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPhysicalBox * FZZOFDPageArea::getPhysicalBox()
{
    return m_FZZOFDPhysicalBox = getElementObject(m_FZZOFDPhysicalBox,FZZOFDPHYSICALBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox * FZZOFDPageArea::setApplicationBox()
{
    return m_FZZOFDApplicationBox = setElementObject(m_FZZOFDApplicationBox,FZZOFDAPPLICATIONBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDApplicationBox * FZZOFDPageArea::getApplicationBox()
{
    return m_FZZOFDApplicationBox = getElementObject(m_FZZOFDApplicationBox,FZZOFDAPPLICATIONBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox * FZZOFDPageArea::setContentBox()
{
    return m_FZZOFDContentBox = setElementObject(m_FZZOFDContentBox,FZZOFDCONTENTBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContentBox * FZZOFDPageArea::getContentBox()
{
    return m_FZZOFDContentBox = getElementObject(m_FZZOFDContentBox,FZZOFDCONTENTBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox * FZZOFDPageArea::setBleedBox()
{
    return m_FZZOFDBleedBox = setElementObject(m_FZZOFDBleedBox,FZZOFDBLEEDBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBleedBox * FZZOFDPageArea::getBleedBox()
{
    return m_FZZOFDBleedBox = getElementObject(m_FZZOFDBleedBox,FZZOFDBLEEDBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox * FZZOFDPageArea::setCropBox()
{
    return m_FZZOFDCropBox = setElementObject(m_FZZOFDCropBox,FZZOFDCROPBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCropBox * FZZOFDPageArea::getCropBox()
{
    return m_FZZOFDCropBox = getElementObject(m_FZZOFDCropBox,FZZOFDCROPBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPageArea::getBox()
{
    string strRet = "";
    FZZOFDPhysicalBox * ofdPb = getPhysicalBox();
    if (ofdPb != NULL) {
        strRet = ofdPb->getValue();
    } else {
        FZZOFDCropBox * ofdcb = getCropBox();
        if (ofdcb != NULL) {
            strRet = ofdcb->getValue();
        } else {
            FZZOFDApplicationBox * ofdab = getApplicationBox();
            if (ofdab != NULL) {
                strRet = ofdab->getValue();
            } else {
                FZZOFDContentBox * ofdctb = getContentBox();
                if (ofdctb != NULL) {
                    strRet = ofdctb->getValue();
                }
            }
        }
    }
    
    return strRet;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageArea::getBox(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    FZZOFDPhysicalBox * ofdPb = getPhysicalBox();
    if (ofdPb != NULL) {
        ofdPb->getValue(x,y,width,height);
    } else {
        FZZOFDCropBox * ofdcb = getCropBox();
        if (ofdcb != NULL) {
            ofdcb->getValue(x,y,width,height);
        } else {
            FZZOFDApplicationBox * ofdab = getApplicationBox();
            if (ofdab != NULL) {
                ofdab->getValue(x,y,width,height);
            } else {
                FZZOFDContentBox * ofdctb = getContentBox();
                if (ofdctb != NULL) {
                    ofdctb->getValue(x,y,width,height);
                }
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
