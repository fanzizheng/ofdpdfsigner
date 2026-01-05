//
//  Created by zizheng fan on 2023/08/10
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAschemeClr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr::FZZAschemeClr() : FZZXMLElementObject(),m_CTlumMod(NULL),m_CTsatMod(NULL),m_CTtint(NULL),m_CTshade(NULL)
{
    //DLOG("FZZAschemeClr()");
    FZZConst::addClassCount("FZZAschemeClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr::FZZAschemeClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_CTlumMod(NULL),m_CTsatMod(NULL),m_CTtint(NULL),m_CTshade(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAschemeClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr::FZZAschemeClr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTlumMod(NULL),m_CTsatMod(NULL),m_CTtint(NULL),m_CTshade(NULL)
{
    FZZConst::addClassCount("FZZAschemeClr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr::FZZAschemeClr(const FZZAschemeClr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAschemeClr");
    if ( this == &obj ) {
        return;
    }

    m_CTlumMod = obj.m_CTlumMod != NULL ? new FZZAlumMod(*obj.m_CTlumMod) : NULL;
    m_CTsatMod = obj.m_CTsatMod != NULL ? new FZZAsatMod(*obj.m_CTsatMod) : NULL;
    m_CTtint = obj.m_CTtint != NULL ? new FZZAtint(*obj.m_CTtint) : NULL;
    m_CTshade = obj.m_CTshade != NULL ? new FZZAshade(*obj.m_CTshade) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr::~FZZAschemeClr()
{
    //DLOG("~FZZAschemeClr()");
    FZZConst::delClassCount("FZZAschemeClr");
    if ( m_CTlumMod != NULL ) {
        delete m_CTlumMod;
        m_CTlumMod = NULL;
    }
    
    if ( m_CTsatMod != NULL ) {
        delete m_CTsatMod;
        m_CTsatMod = NULL;
    }
    
    if ( m_CTtint != NULL ) {
        delete m_CTtint;
        m_CTtint = NULL;
    }
    
    if ( m_CTshade != NULL ) {
        delete m_CTshade;
        m_CTshade = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAschemeClr::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAschemeClr::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod * FZZAschemeClr::setLumMod()
{
    return m_CTlumMod = setElementObject(m_CTlumMod,FZZALUMMOD_Find_Key,FZZALUMMOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlumMod * FZZAschemeClr::getLumMod()
{
    return m_CTlumMod = getElementObject(m_CTlumMod,FZZALUMMOD_Find_Key,FZZALUMMOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod * FZZAschemeClr::setSatMod()
{
    return m_CTsatMod = setElementObject(m_CTsatMod,FZZASATMOD_Find_Key,FZZASATMOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsatMod * FZZAschemeClr::getSatMod()
{
    return m_CTsatMod = getElementObject(m_CTsatMod,FZZASATMOD_Find_Key,FZZASATMOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAtint * FZZAschemeClr::setTint()
{
    return m_CTtint = setElementObject(m_CTtint,FZZATINT_Find_Key,FZZATINT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAtint * FZZAschemeClr::getTint()
{
    return m_CTtint = getElementObject(m_CTtint,FZZATINT_Find_Key,FZZATINT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAshade * FZZAschemeClr::setShade()
{
    return m_CTshade = setElementObject(m_CTshade,FZZASHADE_Find_Key,FZZASHADE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAshade * FZZAschemeClr::getShade()
{
    return m_CTshade = getElementObject(m_CTshade,FZZASHADE_Find_Key,FZZASHADE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
