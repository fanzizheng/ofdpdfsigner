//
//  Created by zizheng fan on 2023/06/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstTxWarp.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAPrstTxWarp**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp::FZZAPrstTxWarp() : FZZXMLElementObject(),m_FZZAAvLst(NULL)
{
    //DLOG("FZZAExt()");
    FZZConst::addClassCount("FZZAPrstTxWarp");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp::FZZAPrstTxWarp(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAAvLst(NULL)
{
    FZZConst::addClassCount("FZZAPrstTxWarp");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp::FZZAPrstTxWarp(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZAAvLst(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAPrstTxWarp");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp::FZZAPrstTxWarp(const FZZAPrstTxWarp& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAExt");
    if ( this == &obj ) {
        return;
    }

    m_FZZAAvLst = obj.m_FZZAAvLst != NULL ? new FZZAAvLst(*obj.m_FZZAAvLst) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp::~FZZAPrstTxWarp()
{
  
    FZZConst::delClassCount("FZZAPrstTxWarp");
    if ( m_FZZAAvLst != NULL ) {
        delete m_FZZAAvLst;
        m_FZZAAvLst = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAPrstTxWarp::setPrst(string uri)
{
    setAttribute_String("prst",uri);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAPrstTxWarp::getPrst()
{
    return getAttribute_String("prst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst * FZZAPrstTxWarp::setAvLst()
{
 
    return m_FZZAAvLst = setElementObject(m_FZZAAvLst,FZZAAVLST_Find_Key,FZZAAVLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAAvLst * FZZAPrstTxWarp::getAvLst()
{
    return m_FZZAAvLst = getElementObject(m_FZZAAvLst,FZZAAVLST_Find_Key,FZZAAVLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------

