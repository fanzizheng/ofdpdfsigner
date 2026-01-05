//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDOutlineElem.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDOutlineElem**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem::FZZOFDOutlineElem() : FZZOFDXMLElementObject(),m_FZZOFDActions(NULL)
{
    //DLOG("FZZOFDOutlineElem()");
    FZZConst::addClassCount("FZZOFDOutlineElem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem::FZZOFDOutlineElem(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDActions(NULL)
{
    
    FZZConst::addClassCount("FZZOFDOutlineElem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem::FZZOFDOutlineElem(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDActions(NULL)
{
    FZZConst::addClassCount("FZZOFDOutlineElem");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem::FZZOFDOutlineElem(const FZZOFDOutlineElem& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDOutlineElem");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDActions = obj.m_FZZOFDActions != NULL ? new FZZOFDActions(*obj.m_FZZOFDActions) : NULL;
    
    vector<FZZOFDOutlineElem*>::const_iterator itr;
    for( itr = obj.m_FZZOFDOutlineElems.begin(); itr != obj.m_FZZOFDOutlineElems.end(); itr++ ) {
        FZZOFDOutlineElem * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDOutlineElems.push_back(new FZZOFDOutlineElem(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem::~FZZOFDOutlineElem()
{
    //DLOG("~FZZOFDOutlineElem()");
    FZZConst::delClassCount("FZZOFDOutlineElem");
    
    if ( m_FZZOFDActions != NULL ) {
        delete m_FZZOFDActions;
        m_FZZOFDActions = NULL;
    }
    
    vector<FZZOFDOutlineElem*>::const_iterator itr;
    for( itr = m_FZZOFDOutlineElems.begin(); itr != m_FZZOFDOutlineElems.end(); itr++ ) {
        FZZOFDOutlineElem * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDOutlineElems.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDOutlineElem::setTitle(string title)
{
    setAttribute_String("Title",title);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDOutlineElem::getTitle()
{
    return getAttribute_String("Title");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDOutlineElem::setCount(int count)
{
    setAttribute_Int("Count",count);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDOutlineElem::getCount()
{
    return getAttribute_Int("Count");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDOutlineElem::setExpanded(bool expanded)
{
    setAttribute_Bool("Expanded",expanded);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDOutlineElem::getExpanded()
{
    return getAttribute_Bool("Expanded",false);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDOutlineElem::setActions()
{
    return m_FZZOFDActions = setElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDOutlineElem::getActions()
{
    return m_FZZOFDActions = getElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem * FZZOFDOutlineElem::addOutlineElem()
{
    return addElementObject(&m_FZZOFDOutlineElems,FZZOFDOUTLINEELEM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDOutlineElem*> * FZZOFDOutlineElem::getOutlineElemList()
{
    getElementObjectList(&m_FZZOFDOutlineElems,FZZOFDOUTLINEELEM_Name);
    return &m_FZZOFDOutlineElems;
}
//-----------------------------------------------------------------------------------------------------------------
