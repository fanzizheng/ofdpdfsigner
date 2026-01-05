//
//  Created by zizheng fan on 2023/08/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgradFill.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAgradFill**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAgradFill::FZZAgradFill() : FZZXMLElementObject(),m_CTgsLst(NULL),m_CTlin(NULL)
{
    //DLOG("FZZAgradFill()");
    FZZConst::addClassCount("FZZAgradFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgradFill::FZZAgradFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_CTgsLst(NULL),m_CTlin(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAgradFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgradFill::FZZAgradFill(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTgsLst(NULL),m_CTlin(NULL)
{
    FZZConst::addClassCount("FZZAgradFill");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgradFill::FZZAgradFill(const FZZAgradFill& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAgradFill");
    if ( this == &obj ) {
        return;
    }
    m_CTgsLst = obj.m_CTgsLst != NULL ? new FZZAgsLst(*obj.m_CTgsLst) : NULL;
    m_CTlin = obj.m_CTlin != NULL ? new FZZAlin(*obj.m_CTlin) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgradFill::~FZZAgradFill()
{
    //DLOG("~FZZAgradFill()");
    FZZConst::delClassCount("FZZAgradFill");
    if ( m_CTgsLst != NULL ) {
        delete m_CTgsLst;
        m_CTgsLst = NULL;
    }
    
    if ( m_CTlin != NULL ) {
        delete m_CTlin;
        m_CTlin = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAgradFill::setRotWithShape(string value)
{
    setAttribute_String("rotWithShape",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAgradFill::getRotWithShape()
{
    return getAttribute_String("rotWithShape");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst * FZZAgradFill::setgsLst()
{
    return m_CTgsLst = setElementObject(m_CTgsLst,FZZAGSLIST_Find_Key,FZZAGSLIST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst * FZZAgradFill::getgsLst()
{
    return m_CTgsLst = getElementObject(m_CTgsLst,FZZAGSLIST_Find_Key,FZZAGSLIST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlin * FZZAgradFill::setLin()
{
    return m_CTlin = setElementObject(m_CTlin,FZZALIN_Find_Key,FZZALIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlin * FZZAgradFill::getLin()
{
    return m_CTlin = getElementObject(m_CTlin,FZZALIN_Find_Key,FZZALIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
