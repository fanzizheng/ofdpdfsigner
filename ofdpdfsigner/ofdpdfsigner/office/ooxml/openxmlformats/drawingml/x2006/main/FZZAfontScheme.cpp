//
//  Created by zizheng fan on 2023/08/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfontScheme.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAfontScheme**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme::FZZAfontScheme() : FZZXMLElementObject(),m_MajorFont(NULL),m_MinorFont(NULL)
{
    //DLOG("FZZAfontScheme()");
    FZZConst::addClassCount("FZZAfontScheme");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme::FZZAfontScheme(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_MajorFont(NULL),m_MinorFont(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAfontScheme");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme::FZZAfontScheme(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_MajorFont(NULL),m_MinorFont(NULL)
{
    FZZConst::addClassCount("FZZAfontScheme");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme::FZZAfontScheme(const FZZAfontScheme& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAfontScheme");
    if ( this == &obj ) {
        return;
    }
    
    m_MajorFont = obj.m_MajorFont != NULL ? new FZZAfontScheme_Item(*obj.m_MajorFont) : NULL;
    m_MinorFont = obj.m_MinorFont != NULL ? new FZZAfontScheme_Item(*obj.m_MinorFont) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme::~FZZAfontScheme()
{
    //DLOG("~FZZAfontScheme()");
    FZZConst::delClassCount("FZZAfontScheme");
    
    if ( m_MajorFont != NULL ) {
        delete m_MajorFont;
        m_MajorFont = NULL;
    }
    
    if ( m_MinorFont != NULL ) {
        delete m_MinorFont;
        m_MinorFont = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAfontScheme::setName(string value)
{
    setAttribute_String("name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAfontScheme::getName()
{
    return getAttribute_String("name");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item * FZZAfontScheme::setMajorFont()
{
    return m_MajorFont = setElementObject(m_MajorFont,FZZAFONTSCHEME_ITEM_Find_Key,"majorFont");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item * FZZAfontScheme::getMajorFont()
{
    return m_MajorFont = getElementObject(m_MajorFont,FZZAFONTSCHEME_ITEM_Find_Key,"majorFont");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item * FZZAfontScheme::setMinorFont()
{
    return m_MinorFont = setElementObject(m_MinorFont,FZZAFONTSCHEME_ITEM_Find_Key,"minorFont");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item * FZZAfontScheme::getMinorFont()
{
    return m_MinorFont = getElementObject(m_MinorFont,FZZAFONTSCHEME_ITEM_Find_Key,"minorFont");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
