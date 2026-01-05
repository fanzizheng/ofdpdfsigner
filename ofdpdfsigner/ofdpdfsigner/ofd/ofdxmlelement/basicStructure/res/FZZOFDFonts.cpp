//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFonts.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDFonts**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFonts::FZZOFDFonts() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDFonts()");
    FZZConst::addClassCount("FZZOFDFonts");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFonts::FZZOFDFonts(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDFonts");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFonts::FZZOFDFonts(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDFonts");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFonts::FZZOFDFonts(const FZZOFDFonts& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDFonts");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDFont*>::const_iterator itr;
    for( itr = obj.m_FZZOFDFonts.begin(); itr != obj.m_FZZOFDFonts.end(); itr++ ) {
        FZZOFDFont * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDFonts.push_back(new FZZOFDFont(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFonts::~FZZOFDFonts()
{
    //DLOG("~FZZOFDFonts()");
    FZZConst::delClassCount("FZZOFDFonts");
        
    vector<FZZOFDFont*>::const_iterator itr;
    for( itr = m_FZZOFDFonts.begin(); itr != m_FZZOFDFonts.end(); itr++ ) {
        FZZOFDFont * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDFonts.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont * FZZOFDFonts::addFont()
{
    return addElementObject(&m_FZZOFDFonts,FZZOFDFONT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDFont*> * FZZOFDFonts::getFontList()
{
    getElementObjectList(&m_FZZOFDFonts,FZZOFDFONT_Name);
    return &m_FZZOFDFonts;
}
//-----------------------------------------------------------------------------------------------------------------

