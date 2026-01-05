//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo_Keywords.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocInfo_Keywords**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords::FZZOFDDocInfo_Keywords() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocInfo_Keywords()");
    FZZConst::addClassCount("FZZOFDDocInfo_Keywords");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords::FZZOFDDocInfo_Keywords(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDDocInfo_Keywords");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords::FZZOFDDocInfo_Keywords(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocInfo_Keywords");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords::FZZOFDDocInfo_Keywords(const FZZOFDDocInfo_Keywords& obj) : FZZOFDXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZOFDDocBody");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDDocInfo_Keyword*>::const_iterator itr;
    for( itr = obj.m_FZZOFDDocInfo_Keywords.begin(); itr != obj.m_FZZOFDDocInfo_Keywords.end(); itr++ ) {
        FZZOFDDocInfo_Keyword * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDDocInfo_Keywords.push_back(new FZZOFDDocInfo_Keyword(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keywords::~FZZOFDDocInfo_Keywords()
{
    //DLOG("~FZZOFDDocInfo_Keywords()");
    FZZConst::delClassCount("FZZOFDDocInfo_Keywords");
        
    vector<FZZOFDDocInfo_Keyword*>::const_iterator itr;
    for( itr = m_FZZOFDDocInfo_Keywords.begin(); itr != m_FZZOFDDocInfo_Keywords.end(); itr++ ) {
        FZZOFDDocInfo_Keyword * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDDocInfo_Keywords.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keyword * FZZOFDDocInfo_Keywords::addKeyword()
{
    return addElementObject(&m_FZZOFDDocInfo_Keywords,FZZOFDDOCINFOKEYWORD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDDocInfo_Keyword*> * FZZOFDDocInfo_Keywords::getKeywordList()
{
    getElementObjectList(&m_FZZOFDDocInfo_Keywords,FZZOFDDOCINFOKEYWORD_Name);
    return &m_FZZOFDDocInfo_Keywords;
}
//-----------------------------------------------------------------------------------------------------------------

