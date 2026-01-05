//
//  Created by zizheng fan on 2023/06/05
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICNvPicPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPICNvPicPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr::FZZPICNvPicPr() : FZZXMLElementObject(),m_FZZPICCNvPr(NULL),m_FZZPICCNvPicPr(NULL)
{
    //DLOG("FZZPICNvPicPr()");
    FZZConst::addClassCount("FZZPICNvPicPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr::FZZPICNvPicPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZPICCNvPr(NULL),m_FZZPICCNvPicPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZPICNvPicPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr::FZZPICNvPicPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZPICCNvPr(NULL),m_FZZPICCNvPicPr(NULL)
{
    FZZConst::addClassCount("FZZPICNvPicPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr::FZZPICNvPicPr(const FZZPICNvPicPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZPICNvPicPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZPICCNvPr = obj.m_FZZPICCNvPr != NULL ? new FZZPICCNvPr(*obj.m_FZZPICCNvPr) : NULL;
    m_FZZPICCNvPicPr = obj.m_FZZPICCNvPicPr != NULL ? new FZZPICCNvPicPr(*obj.m_FZZPICCNvPicPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr::~FZZPICNvPicPr()
{
    //DLOG("~FZZPICNvPicPr()");
    FZZConst::delClassCount("FZZPICNvPicPr");
    if ( m_FZZPICCNvPr != NULL ) {
        delete m_FZZPICCNvPr;
        m_FZZPICCNvPr = NULL;
    }
    if ( m_FZZPICCNvPicPr != NULL ) {
        delete m_FZZPICCNvPicPr;
        m_FZZPICCNvPicPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZPICNvPicPr::setXmlnsPic(string value)
//{
//    setAttribute_String("xmlns:pic",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZPICNvPicPr::getXmlnsPic()
//{
//    return getAttribute_String("xmlns:pic");
//}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr * FZZPICNvPicPr::setCNvPr()
{
    return m_FZZPICCNvPr = setElementObject(m_FZZPICCNvPr,FZZPICCNVPR_Find_Key,FZZPICCNVPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPr * FZZPICNvPicPr::getCNvPr()
{
    return m_FZZPICCNvPr = getElementObject(m_FZZPICCNvPr,FZZPICCNVPR_Find_Key,FZZPICCNVPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr * FZZPICNvPicPr::setCNvPicPr()
{
    return m_FZZPICCNvPicPr = setElementObject(m_FZZPICCNvPicPr,FZZPICCNVPICPR_Find_Key,FZZPICCNVPICPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICCNvPicPr * FZZPICNvPicPr::getCNvPicPr()
{
    return m_FZZPICCNvPicPr = getElementObject(m_FZZPICCNvPicPr,FZZPICCNVPICPR_Find_Key,FZZPICCNVPICPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
