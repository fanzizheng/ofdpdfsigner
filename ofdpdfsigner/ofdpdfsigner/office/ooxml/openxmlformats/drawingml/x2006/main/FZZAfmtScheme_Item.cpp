//
//  Created by zizheng fan on 2023/08/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme_Item.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAfmtScheme_Item**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item::FZZAfmtScheme_Item() : FZZXMLElementObject()//,m_latin(NULL),m_ea(NULL),m_cs(NULL)
{
    //DLOG("FZZAfmtScheme_Item()");
    FZZConst::addClassCount("FZZAfmtScheme_Item");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item::FZZAfmtScheme_Item(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)//,m_latin(NULL),m_ea(NULL),m_cs(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAfmtScheme_Item");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item::FZZAfmtScheme_Item(FZZOfficeObject * parent) : FZZXMLElementObject(parent)//,m_latin(NULL),m_ea(NULL),m_cs(NULL)
{
    FZZConst::addClassCount("FZZAfmtScheme_Item");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item::FZZAfmtScheme_Item(const FZZAfmtScheme_Item& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAfmtScheme_Item");
    if ( this == &obj ) {
        return;
    }


//
    vector<FZZAsolidFill *>::const_iterator itr;
    for( itr = obj.m_CTsolidFills.begin(); itr != obj.m_CTsolidFills.end(); itr++ ) {
        FZZAsolidFill * temp = *itr;
        if ( temp != NULL ) {
            m_CTsolidFills.push_back(new FZZAsolidFill(*temp));
        }
    }
    
    vector<FZZAgradFill *>::const_iterator itr_CTgradFill;
    for( itr_CTgradFill = obj.m_CTgradFills.begin(); itr_CTgradFill != obj.m_CTgradFills.end(); itr_CTgradFill++ ) {
        FZZAgradFill * temp = *itr_CTgradFill;
        if ( temp != NULL ) {
            m_CTgradFills.push_back(new FZZAgradFill(*temp));
        }
    }
    
    vector<FZZALn *>::const_iterator itr_CTln;
    for( itr_CTln = obj.m_CTlns.begin(); itr_CTln != obj.m_CTlns.end(); itr_CTln++ ) {
        FZZALn * temp = *itr_CTln;
        if ( temp != NULL ) {
            m_CTlns.push_back(new FZZALn(*temp));
        }
    }
    
    vector<FZZAeffectStyle *>::const_iterator itr_CTeffectStyle;
    for( itr_CTeffectStyle = obj.m_CTeffectStyles.begin(); itr_CTeffectStyle != obj.m_CTeffectStyles.end(); itr_CTeffectStyle++ ) {
        FZZAeffectStyle * temp = *itr_CTeffectStyle;
        if ( temp != NULL ) {
            m_CTeffectStyles.push_back(new FZZAeffectStyle(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfmtScheme_Item::~FZZAfmtScheme_Item()
{
    //DLOG("~FZZAfmtScheme_Item()");
    FZZConst::delClassCount("FZZAfmtScheme_Item");
//    if ( m_latin != NULL ) {
//        delete m_latin;
//        m_latin = NULL;
//    }
//
//    if ( m_ea != NULL ) {
//        delete m_ea;
//        m_ea = NULL;
//    }
//
//    if ( m_cs != NULL ) {
//        delete m_cs;
//        m_cs = NULL;
//    }
//

    vector<FZZAsolidFill *>::const_iterator itr;
    for( itr = m_CTsolidFills.begin(); itr != m_CTsolidFills.end(); itr++ ) {
        FZZAsolidFill * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_CTsolidFills.clear();
    
    vector<FZZAgradFill *>::const_iterator itr_CTgradFill;
    for( itr_CTgradFill = m_CTgradFills.begin(); itr_CTgradFill != m_CTgradFills.end(); itr_CTgradFill++ ) {
        FZZAgradFill * temp = *itr_CTgradFill;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_CTgradFills.clear();
    
    vector<FZZALn *>::const_iterator itr_CTln;
    for( itr_CTln = m_CTlns.begin(); itr_CTln != m_CTlns.end(); itr_CTln++ ) {
        FZZALn * temp = *itr_CTln;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_CTlns.clear();
    
    vector<FZZAeffectStyle *>::const_iterator itr_CTeffectStyle;
    for( itr_CTeffectStyle = m_CTeffectStyles.begin(); itr_CTeffectStyle != m_CTeffectStyles.end(); itr_CTeffectStyle++ ) {
        FZZAeffectStyle * temp = *itr_CTeffectStyle;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_CTeffectStyles.clear();
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill * FZZAfmtScheme_Item::addsolidFill()
{
    return addElementObject(&m_CTsolidFills,FZZASOLIDFILL_Find_Key,FZZASOLIDFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAsolidFill *>* FZZAfmtScheme_Item::getsolidFills()
{
    getElementObjectList(&m_CTsolidFills,FZZASOLIDFILL_Find_Key,FZZASOLIDFILL_Name);
    return &m_CTsolidFills;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgradFill * FZZAfmtScheme_Item::addgradFill()
{
    return addElementObject(&m_CTgradFills,FZZAGRADFILL_Find_Key,FZZAGRADFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAgradFill *>* FZZAfmtScheme_Item::getgradFills()
{
    getElementObjectList(&m_CTgradFills,FZZAGRADFILL_Find_Key,FZZAGRADFILL_Name);
    return &m_CTgradFills;
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn * FZZAfmtScheme_Item::addLn()
{
    return addElementObject(&m_CTlns,FZZALN_Find_Key,FZZALN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZALn *>* FZZAfmtScheme_Item::getLns()
{
    getElementObjectList(&m_CTlns,FZZALN_Find_Key,FZZALN_Name);
    return &m_CTlns;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectStyle * FZZAfmtScheme_Item::addEffectStyle()
{
    return addElementObject(&m_CTeffectStyles,FZZAEFFECTSTYLE_Find_Key,FZZAEFFECTSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAeffectStyle *>* FZZAfmtScheme_Item::getEffectStyles()
{
    getElementObjectList(&m_CTeffectStyles,FZZAEFFECTSTYLE_Find_Key,FZZAEFFECTSTYLE_Name);
    return &m_CTeffectStyles;
}
//-----------------------------------------------------------------------------------------------------------------
