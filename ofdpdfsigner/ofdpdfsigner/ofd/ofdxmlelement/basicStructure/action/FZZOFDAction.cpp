//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDAction.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAction**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAction::FZZOFDAction() : FZZOFDXMLElementObject(),m_FZZOFDURI(NULL),m_FZZOFDGoto(NULL),m_FZZOFDGotoA(NULL),m_FZZOFDSound(NULL)
,m_FZZOFDMovie(NULL),m_FZZOFDRegion(NULL)
{
    //DLOG("FZZOFDAction()");
    FZZConst::addClassCount("FZZOFDAction");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAction::FZZOFDAction(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDURI(NULL),m_FZZOFDGoto(NULL),m_FZZOFDGotoA(NULL),m_FZZOFDSound(NULL),m_FZZOFDMovie(NULL),m_FZZOFDRegion(NULL)
{
    
    FZZConst::addClassCount("FZZOFDAction");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAction::FZZOFDAction(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDURI(NULL),m_FZZOFDGoto(NULL)
,m_FZZOFDGotoA(NULL),m_FZZOFDSound(NULL),m_FZZOFDMovie(NULL),m_FZZOFDRegion(NULL)
{
    FZZConst::addClassCount("FZZOFDAction");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAction::FZZOFDAction(const FZZOFDAction& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAction");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDURI = obj.m_FZZOFDURI != NULL ? new FZZOFDURI(*obj.m_FZZOFDURI) : NULL;
    m_FZZOFDGoto = obj.m_FZZOFDGoto != NULL ? new FZZOFDGoto(*obj.m_FZZOFDGoto) : NULL;
    m_FZZOFDGotoA = obj.m_FZZOFDGotoA != NULL ? new FZZOFDGotoA(*obj.m_FZZOFDGotoA) : NULL;
    m_FZZOFDSound = obj.m_FZZOFDSound != NULL ? new FZZOFDSound(*obj.m_FZZOFDSound) : NULL;
    m_FZZOFDMovie = obj.m_FZZOFDMovie != NULL ? new FZZOFDMovie(*obj.m_FZZOFDMovie) : NULL;
    m_FZZOFDRegion = obj.m_FZZOFDRegion != NULL ? new FZZOFDRegion(*obj.m_FZZOFDRegion) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAction::~FZZOFDAction()
{
    //DLOG("~FZZOFDAction()");
    FZZConst::delClassCount("FZZOFDAction");
    if ( m_FZZOFDURI != NULL ) {
        delete m_FZZOFDURI;
        m_FZZOFDURI = NULL;
    }
    if ( m_FZZOFDGoto != NULL ) {
        delete m_FZZOFDGoto;
        m_FZZOFDGoto = NULL;
    }
    if ( m_FZZOFDGotoA != NULL ) {
        delete m_FZZOFDGotoA;
        m_FZZOFDGotoA = NULL;
    }
    if ( m_FZZOFDSound != NULL ) {
        delete m_FZZOFDSound;
        m_FZZOFDSound = NULL;
    }
    if ( m_FZZOFDMovie != NULL ) {
        delete m_FZZOFDMovie;
        m_FZZOFDMovie = NULL;
    }
    if ( m_FZZOFDRegion != NULL ) {
        delete m_FZZOFDRegion;
        m_FZZOFDRegion = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAction::setEvent(EventType event)
{
    string value;

    switch (event) {
    case EventType::DO:
        value = "DO";
        break;
    case EventType::PO:
        value = "PO";
        break;
    case EventType::CLICK:
        value = "CLICK";
        break;
    default:
        value = "DO";
        break;
    }
    setAttribute_String("Event",value);
}
//-----------------------------------------------------------------------------------------------------------------
EventType FZZOFDAction::getEvent()
{
    string value = getAttribute_String("Event");
    EventType et = EventType::DO;
    if (value == "DO") {
        et = EventType::DO;
    }
    else if (value == "PO") {
        et = EventType::PO;
    }
    else if (value == "CLICK") {
        et = EventType::CLICK;
    }
    else {
        et = EventType::DO;
    }
    return et;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI * FZZOFDAction::setURI()
{
    deleteOFDActions();
    return m_FZZOFDURI = setElementObject(m_FZZOFDURI,FZZOFDURI_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDURI * FZZOFDAction::getURI()
{
    return m_FZZOFDURI = getElementObject(m_FZZOFDURI,FZZOFDURI_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAction::deleteOFDActions()
{
    if ( m_FZZOFDURI != NULL ) {
        delete m_FZZOFDURI;
        m_FZZOFDURI = NULL;
    }
    deleteElement(FZZOFDURI_Name);
    if ( m_FZZOFDGoto != NULL ) {
        delete m_FZZOFDGoto;
        m_FZZOFDGoto = NULL;
    }
    deleteElement(FZZOFDGOTO_Name);
    if ( m_FZZOFDGotoA != NULL ) {
        delete m_FZZOFDGotoA;
        m_FZZOFDGotoA = NULL;
    }
    deleteElement(FZZOFDGOTOA_Name);
    if ( m_FZZOFDSound != NULL ) {
        delete m_FZZOFDSound;
        m_FZZOFDSound = NULL;
    }
    deleteElement(FZZOFDSOUND_Name);
    if ( m_FZZOFDMovie != NULL ) {
        delete m_FZZOFDMovie;
        m_FZZOFDMovie = NULL;
    }
    deleteElement(FZZOFDMOVIE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto * FZZOFDAction::setGoto()
{
    deleteOFDActions();
    return m_FZZOFDGoto = setElementObject(m_FZZOFDGoto,FZZOFDGOTO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGoto * FZZOFDAction::getGoto()
{
    return m_FZZOFDGoto = getElementObject(m_FZZOFDGoto,FZZOFDGOTO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA * FZZOFDAction::setGotoA()
{
    deleteOFDActions();
    return m_FZZOFDGotoA = setElementObject(m_FZZOFDGotoA,FZZOFDGOTOA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA * FZZOFDAction::getGotoA()
{
    return m_FZZOFDGotoA = getElementObject(m_FZZOFDGotoA,FZZOFDGOTOA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound * FZZOFDAction::setSound()
{
    deleteOFDActions();
    return m_FZZOFDSound = setElementObject(m_FZZOFDSound,FZZOFDSOUND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound * FZZOFDAction::getSound()
{
    return m_FZZOFDSound = getElementObject(m_FZZOFDSound,FZZOFDSOUND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie * FZZOFDAction::setMovie()
{
    deleteOFDActions();
    return m_FZZOFDMovie = setElementObject(m_FZZOFDMovie,FZZOFDMOVIE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie * FZZOFDAction::getMovie()
{
    return m_FZZOFDMovie = getElementObject(m_FZZOFDMovie,FZZOFDMOVIE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion * FZZOFDAction::setRegion()
{
    return m_FZZOFDRegion = setElementObject(m_FZZOFDRegion,FZZOFDREGION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion * FZZOFDAction::getRegion()
{
    return m_FZZOFDRegion = getElementObject(m_FZZOFDRegion,FZZOFDREGION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
