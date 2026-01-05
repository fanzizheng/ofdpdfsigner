//
//  Created by zizheng fan on 2023/09/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFont.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWFont**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWFont::FZZWFont() : FZZXMLElementObject(),m_FZZWAltName(NULL),m_FZZWSig(NULL),m_FZZWPitch(NULL),m_FZZWPanose1(NULL),
    m_FZZWFamily(NULL),m_FZZWCharset(NULL)
{
    //DLOG("FZZWFont()");
    FZZConst::addClassCount("FZZWFont");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFont::FZZWFont(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWAltName(NULL),m_FZZWSig(NULL),m_FZZWPitch(NULL),
    m_FZZWPanose1(NULL),m_FZZWFamily(NULL),m_FZZWCharset(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWFont");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFont::FZZWFont(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWAltName(NULL),m_FZZWSig(NULL),m_FZZWPitch(NULL),
    m_FZZWPanose1(NULL),m_FZZWFamily(NULL),m_FZZWCharset(NULL)
{
    FZZConst::addClassCount("FZZWFont");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFont::FZZWFont(const FZZWFont& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWFont");
    if ( this == &obj ) {
        return;
    }
    m_FZZWAltName = obj.m_FZZWAltName != NULL ? new FZZWAltName(*obj.m_FZZWAltName) : NULL;
    m_FZZWSig = obj.m_FZZWSig != NULL ? new FZZWSig(*obj.m_FZZWSig) : NULL;
    m_FZZWPitch = obj.m_FZZWPitch != NULL ? new FZZWPitch(*obj.m_FZZWPitch) : NULL;
    m_FZZWPanose1 = obj.m_FZZWPanose1 != NULL ? new FZZWPanose1(*obj.m_FZZWPanose1) : NULL;
    m_FZZWFamily = obj.m_FZZWFamily != NULL ? new FZZWFamily(*obj.m_FZZWFamily) : NULL;
    m_FZZWCharset = obj.m_FZZWCharset != NULL ? new FZZWCharset(*obj.m_FZZWCharset) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFont::~FZZWFont()
{
    //DLOG("~FZZWFont()");
    FZZConst::delClassCount("FZZWFont");
    if ( m_FZZWAltName != NULL ) {
        delete m_FZZWAltName;
        m_FZZWAltName = NULL;
    }
    
    if ( m_FZZWSig != NULL ) {
        delete m_FZZWSig;
        m_FZZWSig = NULL;
    }
    if ( m_FZZWPitch != NULL ) {
        delete m_FZZWPitch;
        m_FZZWPitch = NULL;
    }
    if ( m_FZZWPanose1 != NULL ) {
        delete m_FZZWPanose1;
        m_FZZWPanose1 = NULL;
    }
    if ( m_FZZWFamily != NULL ) {
        delete m_FZZWFamily;
        m_FZZWFamily = NULL;
    }
    if ( m_FZZWCharset != NULL ) {
        delete m_FZZWCharset;
        m_FZZWCharset = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFont::setName(string value)
{
    setAttribute_String("w:name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFont::getName()
{
    return getAttribute_String("w:name");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName * FZZWFont::setAltName()
{
    return m_FZZWAltName = setElementObject(m_FZZWAltName,FZZWALTNAME_Find_Key,FZZWALTNAME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAltName * FZZWFont::getAltName()
{
    return m_FZZWAltName = getElementObject(m_FZZWAltName,FZZWALTNAME_Find_Key,FZZWALTNAME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSig * FZZWFont::setSig()
{
    return m_FZZWSig = setElementObject(m_FZZWSig,FZZWSIG_Find_Key,FZZWSIG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSig * FZZWFont::getSig()
{
    return m_FZZWSig = getElementObject(m_FZZWSig,FZZWSIG_Find_Key,FZZWSIG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch * FZZWFont::setPitch()
{
    return m_FZZWPitch = setElementObject(m_FZZWPitch,FZZWPITCH_Find_Key,FZZWPITCH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPitch * FZZWFont::getPitch()
{
    return m_FZZWPitch = getElementObject(m_FZZWPitch,FZZWPITCH_Find_Key,FZZWPITCH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1 * FZZWFont::setPanose1()
{
    return m_FZZWPanose1 = setElementObject(m_FZZWPanose1,FZZWPANOSE1_Find_Key,FZZWPANOSE1_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1 * FZZWFont::getPanose1()
{
    return m_FZZWPanose1 = getElementObject(m_FZZWPanose1,FZZWPANOSE1_Find_Key,FZZWPANOSE1_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily * FZZWFont::setFamily()
{
    return m_FZZWFamily = setElementObject(m_FZZWFamily,FZZWFAMILY_Find_Key,FZZWFAMILY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily * FZZWFont::getFamily()
{
    return m_FZZWFamily = getElementObject(m_FZZWFamily,FZZWFAMILY_Find_Key,FZZWFAMILY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset * FZZWFont::setCharset()
{
    return m_FZZWCharset = setElementObject(m_FZZWCharset,FZZWCHARSET_Find_Key,FZZWCHARSET_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharset * FZZWFont::getCharset()
{
    return m_FZZWCharset = getElementObject(m_FZZWCharset,FZZWCHARSET_Find_Key,FZZWCHARSET_Name);
}
//-----------------------------------------------------------------------------------------------------------------


