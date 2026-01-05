//
//  Created by zizheng fan on 2023/08/25
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExt.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAExt**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAExt::FZZAExt() : FZZXMLElementObject(),m_CTThemeFamily(NULL),m_FZZA14UseLocalDpi(NULL)
{
    //DLOG("FZZAExt()");
    FZZConst::addClassCount("FZZAExt");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExt::FZZAExt(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTThemeFamily(NULL),m_FZZA14UseLocalDpi(NULL)
{
    FZZConst::addClassCount("FZZAExt");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExt::FZZAExt(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_CTThemeFamily(NULL),m_FZZA14UseLocalDpi(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAExt");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZAExt::FZZAExt(const FZZAExt& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAExt");
    if ( this == &obj ) {
        return;
    }

    m_CTThemeFamily = obj.m_CTThemeFamily != NULL ? new FZZThemeFamily(*obj.m_CTThemeFamily) : NULL;
    m_FZZA14UseLocalDpi = obj.m_FZZA14UseLocalDpi != NULL ? new FZZA14UseLocalDpi(*obj.m_FZZA14UseLocalDpi) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExt::~FZZAExt()
{
  
    FZZConst::delClassCount("FZZAExt");
    if ( m_CTThemeFamily != NULL ) {
        delete m_CTThemeFamily;
        m_CTThemeFamily = NULL;
    }
    if ( m_FZZA14UseLocalDpi != NULL ) {
        delete m_FZZA14UseLocalDpi;
        m_FZZA14UseLocalDpi = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAExt::setUri(string uri)
{
    setAttribute_String("uri",uri);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAExt::getUri()
{
    return getAttribute_String("uri");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAExt::setCx(string uri)
{
    setAttribute_String("cx",uri);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAExt::getCx()
{
    return getAttribute_String("cx");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAExt::setCy(string uri)
{
    setAttribute_String("cy",uri);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAExt::getCy()
{
    return getAttribute_String("cy");
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily * FZZAExt::setCTThemeFamily()
{
 
    return m_CTThemeFamily = setElementObject(m_CTThemeFamily,FZZTHEMEFAMILY_Find_Key,FZZTHEMEFAMILY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily * FZZAExt::getCTThemeFamily()
{
    return m_CTThemeFamily = getElementObject(m_CTThemeFamily,FZZTHEMEFAMILY_Find_Key,FZZTHEMEFAMILY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi * FZZAExt::setUseLocalDpi()
{
 
    return m_FZZA14UseLocalDpi = setElementObject(m_FZZA14UseLocalDpi,FZZA14USELOCALDPI_Find_Key,FZZA14USELOCALDPI_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi * FZZAExt::getUseLocalDpi()
{
    return m_FZZA14UseLocalDpi = getElementObject(m_FZZA14UseLocalDpi,FZZA14USELOCALDPI_Find_Key,FZZA14USELOCALDPI_Name);
}
//-----------------------------------------------------------------------------------------------------------------
