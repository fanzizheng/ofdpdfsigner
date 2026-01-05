//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPages.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPages**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages::FZZOFDPages() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPages()");
    FZZConst::addClassCount("FZZOFDPages");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages::FZZOFDPages(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPages");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages::FZZOFDPages(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPages");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages::FZZOFDPages(const FZZOFDPages& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPages");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDPageElem*>::const_iterator itr;
    for( itr = obj.m_FZZOFDPageElems.begin(); itr != obj.m_FZZOFDPageElems.end(); itr++ ) {
        FZZOFDPageElem * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDPageElems.push_back(new FZZOFDPageElem(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages::~FZZOFDPages()
{
    //DLOG("~FZZOFDPages()");
    FZZConst::delClassCount("FZZOFDPages");
    
    vector<FZZOFDPageElem*>::const_iterator itr;
    for( itr = m_FZZOFDPageElems.begin(); itr != m_FZZOFDPageElems.end(); itr++ ) {
        FZZOFDPageElem * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDPageElems.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageElem * FZZOFDPages::addPage()
{
    return addElementObject(&m_FZZOFDPageElems,FZZOFDPAGEELEM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPageElem*> * FZZOFDPages::getPageList()
{
    getElementObjectList(&m_FZZOFDPageElems,FZZOFDPAGEELEM_Name);
    return &m_FZZOFDPageElems;
}
//-----------------------------------------------------------------------------------------------------------------
