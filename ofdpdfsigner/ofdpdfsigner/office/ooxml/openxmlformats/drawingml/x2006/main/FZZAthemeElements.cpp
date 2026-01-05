//
//  Created by zizheng fan on 2023/08/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAthemeElements.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAthemeElements**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements::FZZAthemeElements() : FZZXMLElementObject(),m_CTClrScheme(NULL),m_CTfontScheme(NULL),m_CTfmtScheme(NULL)
{
    //DLOG("FZZAthemeElements()");
    FZZConst::addClassCount("FZZAthemeElements");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements::FZZAthemeElements(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_CTClrScheme(NULL),m_CTfontScheme(NULL),m_CTfmtScheme(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAthemeElements");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements::FZZAthemeElements(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTClrScheme(NULL),m_CTfontScheme(NULL),m_CTfmtScheme(NULL)
{
    FZZConst::addClassCount("FZZAthemeElements");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements::FZZAthemeElements(const FZZAthemeElements& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAthemeElements");
    if ( this == &obj ) {
        return;
    }

    m_CTClrScheme = obj.m_CTClrScheme != NULL ? new FZZAClrScheme(*obj.m_CTClrScheme) : NULL;
    m_CTfontScheme = obj.m_CTfontScheme != NULL ? new FZZAfontScheme(*obj.m_CTfontScheme) : NULL;
    m_CTfmtScheme = obj.m_CTfmtScheme != NULL ? new FZZAfmtScheme(*obj.m_CTfmtScheme) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements::~FZZAthemeElements()
{
   
    FZZConst::delClassCount("FZZAthemeElements");
    if ( m_CTClrScheme != NULL ) {
        delete m_CTClrScheme;
        m_CTClrScheme = NULL;
    }
    
    if ( m_CTfontScheme != NULL ) {
        delete m_CTfontScheme;
        m_CTfontScheme = NULL;
    }
    
    if ( m_CTfmtScheme != NULL ) {
        delete m_CTfmtScheme;
        m_CTfmtScheme = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme * FZZAthemeElements::setClrScheme()
{
    return m_CTClrScheme = setElementObject(m_CTClrScheme,FZZACLRSCHEME_Find_Key,FZZACLRSCHEME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme * FZZAthemeElements::getClrScheme()
{
    return m_CTClrScheme = getElementObject(m_CTClrScheme,FZZACLRSCHEME_Find_Key,FZZACLRSCHEME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme * FZZAthemeElements::setfontScheme()
{
    return m_CTfontScheme = setElementObject(m_CTfontScheme,FZZAFONTSCHEME_Find_Key,FZZAFONTSCHEME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfontScheme * FZZAthemeElements::getfontScheme()
{
    return m_CTfontScheme = getElementObject(m_CTfontScheme,FZZAFONTSCHEME_Find_Key,FZZAFONTSCHEME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme * FZZAthemeElements::setfmtScheme()
{
    return m_CTfmtScheme = setElementObject(m_CTfmtScheme,FZZAFMTSCHEME_Find_Key,FZZAFMTSCHEME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme * FZZAthemeElements::getfmtScheme()
{
    return m_CTfmtScheme = getElementObject(m_CTfmtScheme,FZZAFMTSCHEME_Find_Key,FZZAFMTSCHEME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
