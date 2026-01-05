//
//  Created by zizheng fan on 2023/05/07.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSWsp.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPSWsp**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp::FZZWPSWsp() : FZZXMLElementObject(),m_FZZWPSCNvCnPr(NULL),m_FZZWPSSpPr(NULL),m_FZZWPSStyle(NULL),m_FZZWPSBodyPr(NULL)
{
    //DLOG("FZZWPSWsp()");
    FZZConst::addClassCount("FZZWPSWsp");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp::FZZWPSWsp(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWPSCNvCnPr(NULL),m_FZZWPSSpPr(NULL),m_FZZWPSStyle(NULL),m_FZZWPSBodyPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPSWsp");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp::FZZWPSWsp(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPSCNvCnPr(NULL),m_FZZWPSSpPr(NULL),m_FZZWPSStyle(NULL),m_FZZWPSBodyPr(NULL)
{
    FZZConst::addClassCount("FZZWPSWsp");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp::FZZWPSWsp(const FZZWPSWsp& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPSWsp");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPSCNvCnPr = obj.m_FZZWPSCNvCnPr != NULL ? new FZZWPSCNvCnPr(*obj.m_FZZWPSCNvCnPr) : NULL;
    m_FZZWPSSpPr = obj.m_FZZWPSSpPr != NULL ? new FZZWPSSpPr(*obj.m_FZZWPSSpPr) : NULL;
    m_FZZWPSStyle = obj.m_FZZWPSStyle != NULL ? new FZZWPSStyle(*obj.m_FZZWPSStyle) : NULL;
    m_FZZWPSBodyPr = obj.m_FZZWPSBodyPr != NULL ? new FZZWPSBodyPr(*obj.m_FZZWPSBodyPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSWsp::~FZZWPSWsp()
{
    //DLOG("~FZZWPSWsp()");
    FZZConst::delClassCount("FZZWPSWsp");
    if ( m_FZZWPSCNvCnPr != NULL ) {
        delete m_FZZWPSCNvCnPr;
        m_FZZWPSCNvCnPr = NULL;
    }
    if ( m_FZZWPSSpPr != NULL ) {
        delete m_FZZWPSSpPr;
        m_FZZWPSSpPr = NULL;
    }
    if ( m_FZZWPSStyle != NULL ) {
        delete m_FZZWPSStyle;
        m_FZZWPSStyle = NULL;
    }
    if ( m_FZZWPSBodyPr != NULL ) {
        delete m_FZZWPSBodyPr;
        m_FZZWPSBodyPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr * FZZWPSWsp::setCNvCnPr()
{
    return m_FZZWPSCNvCnPr = setElementObject(m_FZZWPSCNvCnPr,FZZWPSCNVCNPR_Find_Key,FZZWPSCNVCNPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr * FZZWPSWsp::getCNvCnPr()
{
    return m_FZZWPSCNvCnPr = getElementObject(m_FZZWPSCNvCnPr,FZZWPSCNVCNPR_Find_Key,FZZWPSCNVCNPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr * FZZWPSWsp::setSpPr()
{
    return m_FZZWPSSpPr = setElementObject(m_FZZWPSSpPr,FZZWPSSPPR_Find_Key,FZZWPSSPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr * FZZWPSWsp::getSpPr()
{
    return m_FZZWPSSpPr = getElementObject(m_FZZWPSSpPr,FZZWPSSPPR_Find_Key,FZZWPSSPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle * FZZWPSWsp::setStyle()
{
    return m_FZZWPSStyle = setElementObject(m_FZZWPSStyle,FZZWPSSTYLE_Find_Key,FZZWPSSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle * FZZWPSWsp::getStyle()
{
    return m_FZZWPSStyle = getElementObject(m_FZZWPSStyle,FZZWPSSTYLE_Find_Key,FZZWPSSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr * FZZWPSWsp::setBodyPr()
{
    return m_FZZWPSBodyPr = setElementObject(m_FZZWPSBodyPr,FZZWPSBODYPR_Find_Key,FZZWPSBODYPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr * FZZWPSWsp::getBodyPr()
{
    return m_FZZWPSBodyPr = getElementObject(m_FZZWPSBodyPr,FZZWPSBODYPR_Find_Key,FZZWPSBODYPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
