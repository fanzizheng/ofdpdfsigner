//
//  Created by zizheng fan on 2023/04/20.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVTextbox.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVTextbox**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox::FZZVTextbox() : FZZXMLElementObject(),m_FZZWTxbxContent(NULL)
{
    //DLOG("FZZVTextbox()");
    FZZConst::addClassCount("FZZVTextbox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox::FZZVTextbox(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWTxbxContent(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVTextbox");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox::FZZVTextbox(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTxbxContent(NULL)
{
    FZZConst::addClassCount("FZZVTextbox");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox::FZZVTextbox(const FZZVTextbox& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVTextbox");
    if ( this == &obj ) {
        return;
    }
    m_FZZWTxbxContent = obj.m_FZZWTxbxContent != NULL ? new FZZWTxbxContent(*obj.m_FZZWTxbxContent) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox::~FZZVTextbox()
{
    //DLOG("~FZZVTextbox()");
    FZZConst::delClassCount("FZZVTextbox");
    if ( m_FZZWTxbxContent != NULL ) {
        delete m_FZZWTxbxContent;
        m_FZZWTxbxContent = NULL;
    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextbox::setInset(string value)
{
    setAttribute_String("inset",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextbox::getInset()
{
    return getAttribute_String("inset");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVTextbox::setStyle(string value)
{
    setAttribute_String("style",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVTextbox::getStyle()
{
    return getAttribute_String("style");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent * FZZVTextbox::setTxbxContent()
{
    return m_FZZWTxbxContent = setElementObject(m_FZZWTxbxContent,FZZWTXBXCONTENT_Find_Key,FZZWTXBXCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent * FZZVTextbox::getTxbxContent()
{
    return m_FZZWTxbxContent = getElementObject(m_FZZWTxbxContent,FZZWTXBXCONTENT_Find_Key,FZZWTXBXCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
