//
//  Created by zizheng fan on 2023/10/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLatentStyles.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLatentStyles**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles::FZZWLatentStyles() : FZZXMLElementObject()
{
    //DLOG("FZZWLatentStyles()");
    FZZConst::addClassCount("FZZWLatentStyles");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles::FZZWLatentStyles(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLatentStyles");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles::FZZWLatentStyles(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLatentStyles");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles::FZZWLatentStyles(const FZZWLatentStyles& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLatentStyles");
    if ( this == &obj ) {
        return;
    }
    vector<FZZWLsdException*>::const_iterator itr;
    for( itr = obj.m_FZZWLsdExceptions.begin(); itr != obj.m_FZZWLsdExceptions.end(); itr++ ) {
        FZZWLsdException * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWLsdExceptions.push_back(new FZZWLsdException(*temp));
        }
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles::~FZZWLatentStyles()
{
    //DLOG("~FZZWLatentStyles()");
    FZZConst::delClassCount("FZZWLatentStyles");
    
    
    vector<FZZWLsdException*>::const_iterator itr;
    for( itr = m_FZZWLsdExceptions.begin(); itr != m_FZZWLsdExceptions.end(); itr++ ) {
        FZZWLsdException * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWLsdExceptions.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLatentStyles::setDefLockedState(string value)
{
    setAttribute_String("w:defLockedState",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLatentStyles::getDefLockedState()
{
    return getAttribute_String("w:defLockedState");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLsdException * FZZWLatentStyles::addFZZWLsdException()
{
    return addElementObject(&m_FZZWLsdExceptions,FZZWLSDEXCEPTION_Find_Key,FZZWLSDEXCEPTION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWLsdException*> * FZZWLatentStyles::getFZZWLsdExceptions()
{
    getElementObjectList(&m_FZZWLsdExceptions,FZZWLSDEXCEPTION_Find_Key,FZZWLSDEXCEPTION_Name);
    return &m_FZZWLsdExceptions;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLatentStyles::setDefUIPriority(string value)
{
    setAttribute_String("w:defUIPriority",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLatentStyles::getDefUIPriority()
{
    return getAttribute_String("w:defUIPriority");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLatentStyles::setDefSemiHidden(string value)
{
    setAttribute_String("w:defSemiHidden",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLatentStyles::getDefSemiHidden()
{
    return getAttribute_String("w:defSemiHidden");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLatentStyles::setDefUnhideWhenUsed(string value)
{
    setAttribute_String("w:defUnhideWhenUsed",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLatentStyles::getDefUnhideWhenUsed()
{
    return getAttribute_String("w:defUnhideWhenUsed");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLatentStyles::setDefQFormat(string value)
{
    setAttribute_String("w:defQFormat",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLatentStyles::getDefQFormat()
{
    return getAttribute_String("w:defQFormat");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLatentStyles::setCount(string value)
{
    setAttribute_String("w:count",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLatentStyles::getCount()
{
    return getAttribute_String("w:count");
}
//-----------------------------------------------------------------------------------------------------------------
