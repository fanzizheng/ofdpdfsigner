//
//  Created by zizheng fan on 2023/08/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfontScheme_Item.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAfontScheme_Item**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item::FZZAfontScheme_Item() : FZZXMLElementObject(),m_latin(NULL),m_ea(NULL),m_cs(NULL)
{
    //DLOG("FZZAfontScheme_Item()");
    FZZConst::addClassCount("FZZAfontScheme_Item");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item::FZZAfontScheme_Item(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_latin(NULL),m_ea(NULL),m_cs(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAfontScheme_Item");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item::FZZAfontScheme_Item(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_latin(NULL),m_ea(NULL),m_cs(NULL)
{
    FZZConst::addClassCount("FZZAfontScheme_Item");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item::FZZAfontScheme_Item(const FZZAfontScheme_Item& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAfontScheme_Item");
    if ( this == &obj ) {
        return;
    }

    m_latin = obj.m_latin != NULL ? new FZZAfont_ea_cs(*obj.m_latin) : NULL;
    m_ea = obj.m_ea != NULL ? new FZZAfont_ea_cs(*obj.m_ea) : NULL;
    m_cs = obj.m_cs != NULL ? new FZZAfont_ea_cs(*obj.m_cs) : NULL;
    
    vector<FZZAfont_ea_cs *>::const_iterator itr;
    for( itr = obj.m_fonts.begin(); itr != obj.m_fonts.end(); itr++ ) {
        FZZAfont_ea_cs * temp = *itr;
        if ( temp != NULL ) {
            m_fonts.push_back(new FZZAfont_ea_cs(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme_Item::~FZZAfontScheme_Item()
{
    //DLOG("~FZZAfontScheme_Item()");
    FZZConst::delClassCount("FZZAfontScheme_Item");
    if ( m_latin != NULL ) {
        delete m_latin;
        m_latin = NULL;
    }
    
    if ( m_ea != NULL ) {
        delete m_ea;
        m_ea = NULL;
    }
    
    if ( m_cs != NULL ) {
        delete m_cs;
        m_cs = NULL;
    }
    
    vector<FZZAfont_ea_cs *>::const_iterator itr;
    for( itr = m_fonts.begin(); itr != m_fonts.end(); itr++ ) {
        FZZAfont_ea_cs * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_fonts.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::setLatin()
{
    return m_latin = setElementObject(m_latin,FZZAFONT_EA_CS_Find_Key,"latin");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::getLatin()
{
    return m_latin = getElementObject(m_latin,FZZAFONT_EA_CS_Find_Key,"latin");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::setEa()
{
    return m_ea = setElementObject(m_ea,FZZAFONT_EA_CS_Find_Key,"ea");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::getEa()
{
    return m_ea = getElementObject(m_ea,FZZAFONT_EA_CS_Find_Key,"ea");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::setCs()
{
    return m_cs = setElementObject(m_cs,FZZAFONT_EA_CS_Find_Key,"cs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::getCs()
{
    return m_cs = getElementObject(m_cs,FZZAFONT_EA_CS_Find_Key,"cs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs * FZZAfontScheme_Item::addFont()
{
    return addElementObject(&m_fonts,FZZAFONT_EA_CS_Find_Key,"font");
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAfont_ea_cs *>* FZZAfontScheme_Item::getFonts()
{
    getElementObjectList(&m_fonts,FZZAFONT_EA_CS_Find_Key,"font");
    return &m_fonts;
}
//-----------------------------------------------------------------------------------------------------------------
