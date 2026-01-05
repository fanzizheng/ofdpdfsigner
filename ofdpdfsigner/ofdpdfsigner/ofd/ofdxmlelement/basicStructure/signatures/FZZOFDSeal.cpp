//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSeal.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSeal**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal::FZZOFDSeal() : FZZOFDXMLElementObject(),m_BaseLoc(NULL),m_ImageLoc(NULL)
{
    //DLOG("FZZOFDSeal()");
    FZZConst::addClassCount("FZZOFDSeal");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal::FZZOFDSeal(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_BaseLoc(NULL),m_ImageLoc(NULL)
{
    
    FZZConst::addClassCount("FZZOFDSeal");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal::FZZOFDSeal(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_BaseLoc(NULL),m_ImageLoc(NULL)
{
    FZZConst::addClassCount("FZZOFDSeal");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal::FZZOFDSeal(const FZZOFDSeal& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSeal");
    if ( this == &obj ) {
        return;
    }
    m_BaseLoc = obj.m_BaseLoc != NULL ? new FZZOFDFileLoc(*obj.m_BaseLoc) : NULL;
    m_ImageLoc = obj.m_ImageLoc != NULL ? new FZZOFDFileLoc(*obj.m_ImageLoc) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal::~FZZOFDSeal()
{
    //DLOG("~FZZOFDSeal()");
    FZZConst::delClassCount("FZZOFDSeal");
    if ( m_BaseLoc != NULL ) {
        delete m_BaseLoc;
        m_BaseLoc = NULL;
    }
    if ( m_ImageLoc != NULL ) {
        delete m_ImageLoc;
        m_ImageLoc = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDSeal::setBaseLoc()
{
    return m_BaseLoc = setElementObject(m_BaseLoc,FZZOFDBASELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDSeal::getBaseLoc()
{
    return m_BaseLoc = getElementObject(m_BaseLoc,FZZOFDBASELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDSeal::setImageLoc()
{
    return m_ImageLoc = setElementObject(m_ImageLoc,FZZOFDIMAGELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDSeal::getImageLoc()
{
    return m_ImageLoc = getElementObject(m_ImageLoc,FZZOFDIMAGELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
