//
//  Created by zizheng fan on 2023/05/06.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSStyle.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPSStyle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle::FZZWPSStyle() : FZZXMLElementObject(),m_FZZALnRef(NULL),m_FZZAFontRef(NULL),m_FZZAFillRef(NULL),m_FZZAEffectRef(NULL)
{
    //DLOG("FZZWPSStyle()");
    FZZConst::addClassCount("FZZWPSStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle::FZZWPSStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZALnRef(NULL),m_FZZAFontRef(NULL),m_FZZAFillRef(NULL),m_FZZAEffectRef(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPSStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle::FZZWPSStyle(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZALnRef(NULL),m_FZZAFontRef(NULL),m_FZZAFillRef(NULL),m_FZZAEffectRef(NULL)
{
    FZZConst::addClassCount("FZZWPSStyle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle::FZZWPSStyle(const FZZWPSStyle& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPSStyle");
    if ( this == &obj ) {
        return;
    }
    m_FZZALnRef = obj.m_FZZALnRef != NULL ? new FZZALnRef(*obj.m_FZZALnRef) : NULL;
    m_FZZAFontRef = obj.m_FZZAFontRef != NULL ? new FZZAFontRef(*obj.m_FZZAFontRef) : NULL;
    m_FZZAFillRef = obj.m_FZZAFillRef != NULL ? new FZZAFillRef(*obj.m_FZZAFillRef) : NULL;
    m_FZZAEffectRef = obj.m_FZZAEffectRef != NULL ? new FZZAEffectRef(*obj.m_FZZAEffectRef) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSStyle::~FZZWPSStyle()
{
    //DLOG("~FZZWPSStyle()");
    FZZConst::delClassCount("FZZWPSStyle");
    if ( m_FZZALnRef != NULL ) {
        delete m_FZZALnRef;
        m_FZZALnRef = NULL;
    }
    if ( m_FZZAFontRef != NULL ) {
        delete m_FZZAFontRef;
        m_FZZAFontRef = NULL;
    }
    if ( m_FZZAFillRef != NULL ) {
        delete m_FZZAFillRef;
        m_FZZAFillRef = NULL;
    }
    if ( m_FZZAEffectRef != NULL ) {
        delete m_FZZAEffectRef;
        m_FZZAEffectRef = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef * FZZWPSStyle::setLnRef()
{
    return m_FZZALnRef = setElementObject(m_FZZALnRef,FZZALNREF_Find_Key,FZZALNREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef * FZZWPSStyle::getLnRef()
{
    return m_FZZALnRef = getElementObject(m_FZZALnRef,FZZALNREF_Find_Key,FZZALNREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef * FZZWPSStyle::setFontRef()
{
    return m_FZZAFontRef = setElementObject(m_FZZAFontRef,FZZAFONTREF_Find_Key,FZZAFONTREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef * FZZWPSStyle::getFontRef()
{
    return m_FZZAFontRef = getElementObject(m_FZZAFontRef,FZZAFONTREF_Find_Key,FZZAFONTREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef * FZZWPSStyle::setFillRef()
{
    return m_FZZAFillRef = setElementObject(m_FZZAFillRef,FZZAFILLREF_Find_Key,FZZAFILLREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef * FZZWPSStyle::getFillRef()
{
    return m_FZZAFillRef = getElementObject(m_FZZAFillRef,FZZAFILLREF_Find_Key,FZZAFILLREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef * FZZWPSStyle::setEffectRef()
{
    return m_FZZAEffectRef = setElementObject(m_FZZAEffectRef,FZZAEFFECTREF_Find_Key,FZZAEFFECTREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef * FZZWPSStyle::getEffectRef()
{
    return m_FZZAEffectRef = getElementObject(m_FZZAEffectRef,FZZAEFFECTREF_Find_Key,FZZAEFFECTREF_Name);
}
//-----------------------------------------------------------------------------------------------------------------

