//
//  Created by zizheng fan on 2023/06/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICPic.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPICPic**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic::FZZPICPic() : FZZXMLElementObject(),m_FZZPICSpPr(NULL),m_FZZPICBlipFill(NULL),m_FZZPICNvPicPr(NULL)
{
    //DLOG("FZZPICPic()");
    FZZConst::addClassCount("FZZPICPic");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic::FZZPICPic(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZPICSpPr(NULL),m_FZZPICBlipFill(NULL),m_FZZPICNvPicPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZPICPic");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic::FZZPICPic(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZPICSpPr(NULL),m_FZZPICBlipFill(NULL),m_FZZPICNvPicPr(NULL)
{
    FZZConst::addClassCount("FZZPICPic");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic::FZZPICPic(const FZZPICPic& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZPICPic");
    if ( this == &obj ) {
        return;
    }
    m_FZZPICSpPr = obj.m_FZZPICSpPr != NULL ? new FZZPICSpPr(*obj.m_FZZPICSpPr) : NULL;
    m_FZZPICBlipFill = obj.m_FZZPICBlipFill != NULL ? new FZZPICBlipFill(*obj.m_FZZPICBlipFill) : NULL;
    m_FZZPICNvPicPr = obj.m_FZZPICNvPicPr != NULL ? new FZZPICNvPicPr(*obj.m_FZZPICNvPicPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICPic::~FZZPICPic()
{
    //DLOG("~FZZPICPic()");
    FZZConst::delClassCount("FZZPICPic");
    if ( m_FZZPICSpPr != NULL ) {
        delete m_FZZPICSpPr;
        m_FZZPICSpPr = NULL;
    }
    if ( m_FZZPICBlipFill != NULL ) {
        delete m_FZZPICBlipFill;
        m_FZZPICBlipFill = NULL;
    }
    if ( m_FZZPICNvPicPr != NULL ) {
        delete m_FZZPICNvPicPr;
        m_FZZPICNvPicPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPICPic::setXmlnsPic(string value)
{
    setAttribute_String("xmlns:pic",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZPICPic::getXmlnsPic()
{
    return getAttribute_String("xmlns:pic");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr * FZZPICPic::setSpPr()
{
    return m_FZZPICSpPr = setElementObject(m_FZZPICSpPr,FZZPICSPPR_Find_Key,FZZPICSPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr * FZZPICPic::getSpPr()
{
    return m_FZZPICSpPr = getElementObject(m_FZZPICSpPr,FZZPICSPPR_Find_Key,FZZPICSPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill * FZZPICPic::setBlipFill()
{
    return m_FZZPICBlipFill = setElementObject(m_FZZPICBlipFill,FZZPICBLIPFILL_Find_Key,FZZPICBLIPFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICBlipFill * FZZPICPic::getBlipFill()
{
    return m_FZZPICBlipFill = getElementObject(m_FZZPICBlipFill,FZZPICBLIPFILL_Find_Key,FZZPICBLIPFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr * FZZPICPic::setNvPicPr()
{
    return m_FZZPICNvPicPr = setElementObject(m_FZZPICNvPicPr,FZZPICNVPICPR_Find_Key,FZZPICNVPICPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICNvPicPr * FZZPICPic::getNvPicPr()
{
    return m_FZZPICNvPicPr = getElementObject(m_FZZPICNvPicPr,FZZPICNVPICPR_Find_Key,FZZPICNVPICPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
