//
//  Created by zizheng fan on 2023/07/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAouterShdw.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAouterShdw**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAouterShdw::FZZAouterShdw() : FZZXMLElementObject(),m_CTSrgbClr(NULL)
{
    //DLOG("FZZAouterShdw()");
    FZZConst::addClassCount("FZZAouterShdw");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAouterShdw::FZZAouterShdw(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) :
    FZZXMLElementObject(parent,doc,node,key,false),m_CTSrgbClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAouterShdw");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAouterShdw::FZZAouterShdw(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTSrgbClr(NULL)
{
    FZZConst::addClassCount("FZZAouterShdw");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAouterShdw::FZZAouterShdw(const FZZAouterShdw& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAouterShdw");
    if ( this == &obj ) {
        return;
    }
    m_CTSrgbClr = obj.m_CTSrgbClr != NULL ? new FZZASrgbClr(*obj.m_CTSrgbClr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAouterShdw::~FZZAouterShdw()
{
    //DLOG("~FZZAouterShdw()");
    FZZConst::delClassCount("FZZAouterShdw");
    if ( m_CTSrgbClr != NULL ) {
        delete m_CTSrgbClr;
        m_CTSrgbClr = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAouterShdw::setBlurRad(string value)
{
    setAttribute_String("blurRad",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAouterShdw::getBlurRad()
{
    return getAttribute_String("blurRad");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAouterShdw::setDist(string value)
{
    setAttribute_String("dist",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAouterShdw::getDist()
{
    return getAttribute_String("dist");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAouterShdw::setDir(string value)
{
    setAttribute_String("dir",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAouterShdw::getDir()
{
    return getAttribute_String("dir");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAouterShdw::setAlgn(string value)
{
    setAttribute_String("algn",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAouterShdw::getAlgn()
{
    return getAttribute_String("algn");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAouterShdw::setRotWithShape(string value)
{
    setAttribute_String("rotWithShape",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAouterShdw::getRotWithShape()
{
    return getAttribute_String("rotWithShape");
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr * FZZAouterShdw::setSrgbClr()
{
    return m_CTSrgbClr = setElementObject(m_CTSrgbClr,FZZASRGBCLR_Find_Key,FZZASRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr * FZZAouterShdw::getSrgbClr()
{
    return m_CTSrgbClr = getElementObject(m_CTSrgbClr,FZZASRGBCLR_Find_Key,FZZASRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
