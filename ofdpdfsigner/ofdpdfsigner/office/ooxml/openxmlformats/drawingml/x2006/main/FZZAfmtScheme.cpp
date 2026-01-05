//
//  Created by zizheng fan on 2023/08/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAfmtScheme**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme::FZZAfmtScheme() : FZZXMLElementObject(),m_FillStyleLst(NULL),m_LnStyleLst(NULL),m_EffectStyleLst(NULL),m_BgFillStyleLst(NULL)
{
    //DLOG("FZZAfmtScheme()");
    FZZConst::addClassCount("FZZAfmtScheme");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme::FZZAfmtScheme(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FillStyleLst(NULL),m_LnStyleLst(NULL),m_EffectStyleLst(NULL),m_BgFillStyleLst(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAfmtScheme");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme::FZZAfmtScheme(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FillStyleLst(NULL),m_LnStyleLst(NULL),m_EffectStyleLst(NULL),m_BgFillStyleLst(NULL)
{
    FZZConst::addClassCount("FZZAfmtScheme");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme::FZZAfmtScheme(const FZZAfmtScheme& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAfmtScheme");
    if ( this == &obj ) {
        return;
    }
    
    m_FillStyleLst = obj.m_FillStyleLst != NULL ? new FZZAfmtScheme_Item(*obj.m_FillStyleLst) : NULL;
    m_LnStyleLst = obj.m_LnStyleLst != NULL ? new FZZAfmtScheme_Item(*obj.m_LnStyleLst) : NULL;
    m_EffectStyleLst = obj.m_EffectStyleLst != NULL ? new FZZAfmtScheme_Item(*obj.m_EffectStyleLst) : NULL;
    m_BgFillStyleLst = obj.m_BgFillStyleLst != NULL ? new FZZAfmtScheme_Item(*obj.m_BgFillStyleLst) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme::~FZZAfmtScheme()
{
    //DLOG("~FZZAfmtScheme()");
    FZZConst::delClassCount("FZZAfmtScheme");
    
    if ( m_FillStyleLst != NULL ) {
        delete m_FillStyleLst;
        m_FillStyleLst = NULL;
    }
    
    if ( m_LnStyleLst != NULL ) {
        delete m_LnStyleLst;
        m_LnStyleLst = NULL;
    }
    
    if ( m_EffectStyleLst != NULL ) {
        delete m_EffectStyleLst;
        m_EffectStyleLst = NULL;
    }
    
    if ( m_BgFillStyleLst != NULL ) {
        delete m_BgFillStyleLst;
        m_BgFillStyleLst = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAfmtScheme::setName(string value)
{
    setAttribute_String("name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAfmtScheme::getName()
{
    return getAttribute_String("name");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::setFillStyleLst()
{
    return m_FillStyleLst = setElementObject(m_FillStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"fillStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::getFillStyleLst()
{
    return m_FillStyleLst = getElementObject(m_FillStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"fillStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::setLnStyleLst()
{
    return m_LnStyleLst = setElementObject(m_LnStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"lnStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::getLnStyleLst()
{
    return m_LnStyleLst = getElementObject(m_LnStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"lnStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::setEffectStyleLst()
{
    return m_EffectStyleLst = setElementObject(m_EffectStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"effectStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::getEffectStyleLst()
{
    return m_EffectStyleLst = getElementObject(m_EffectStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"effectStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::setBgFillStyleLst()
{
    return m_BgFillStyleLst = setElementObject(m_BgFillStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"bgFillStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item * FZZAfmtScheme::getBgFillStyleLst()
{
    return m_BgFillStyleLst = getElementObject(m_BgFillStyleLst,FZZAFMTSCHEME_ITEM_Find_Key,"bgFillStyleLst");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
