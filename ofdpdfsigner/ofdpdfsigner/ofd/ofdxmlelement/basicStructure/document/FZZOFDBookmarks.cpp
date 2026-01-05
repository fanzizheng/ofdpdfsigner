//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmarks.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBookmarks**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks::FZZOFDBookmarks() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDBookmarks()");
    FZZConst::addClassCount("FZZOFDBookmarks");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks::FZZOFDBookmarks(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDBookmarks");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks::FZZOFDBookmarks(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDBookmarks");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks::FZZOFDBookmarks(const FZZOFDBookmarks& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDBookmarks");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDBookmark*>::const_iterator itr;
    for( itr = obj.m_FZZOFDBookmarks.begin(); itr != obj.m_FZZOFDBookmarks.end(); itr++ ) {
        FZZOFDBookmark * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDBookmarks.push_back(new FZZOFDBookmark(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks::~FZZOFDBookmarks()
{
    //DLOG("~FZZOFDBookmarks()");
    FZZConst::delClassCount("FZZOFDBookmarks");
        
    vector<FZZOFDBookmark*>::const_iterator itr;
    for( itr = m_FZZOFDBookmarks.begin(); itr != m_FZZOFDBookmarks.end(); itr++ ) {
        FZZOFDBookmark * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDBookmarks.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmark * FZZOFDBookmarks::addBookmark()
{
    return addElementObject(&m_FZZOFDBookmarks,FZZOFDBOOKMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDBookmark*> * FZZOFDBookmarks::getBookmarkList()
{
    getElementObjectList(&m_FZZOFDBookmarks,FZZOFDBOOKMARK_Name);
    return &m_FZZOFDBookmarks;
}
//-----------------------------------------------------------------------------------------------------------------

