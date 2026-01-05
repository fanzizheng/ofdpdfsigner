//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnPage.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAnnPage**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnPage::FZZOFDAnnPage() : FZZOFDXMLElementObject(),m_FZZOFDFileLoc(NULL)
{
    //DLOG("FZZOFDAnnPage()");
    FZZConst::addClassCount("FZZOFDAnnPage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnPage::FZZOFDAnnPage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDFileLoc(NULL)
{
    
    FZZConst::addClassCount("FZZOFDAnnPage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnPage::FZZOFDAnnPage(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDFileLoc(NULL)
{
    FZZConst::addClassCount("FZZOFDAnnPage");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnPage::FZZOFDAnnPage(const FZZOFDAnnPage& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAnnPage");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDFileLoc = obj.m_FZZOFDFileLoc != NULL ? new FZZOFDFileLoc(*obj.m_FZZOFDFileLoc) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnPage::~FZZOFDAnnPage()
{
    //DLOG("~FZZOFDAnnPage()");
    FZZConst::delClassCount("FZZOFDAnnPage");
    
    if ( m_FZZOFDFileLoc != NULL ) {
        delete m_FZZOFDFileLoc;
        m_FZZOFDFileLoc = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnPage::setPageID(string value)
{
    setAttribute_String("PageID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAnnPage::getPageID()
{
    return getAttribute_String("PageID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnPage::setPageID(long value)
{
    
    setAttribute_long("PageID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDAnnPage::getPageID_long()
{
    return getAttribute_long("PageID");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDAnnPage::setFileLoc()
{
    return m_FZZOFDFileLoc = setElementObject(m_FZZOFDFileLoc,FZZOFDFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDAnnPage::getFileLoc()
{
    return m_FZZOFDFileLoc = getElementObject(m_FZZOFDFileLoc,FZZOFDFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
