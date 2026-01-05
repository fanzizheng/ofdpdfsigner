//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDACTION_H
#define FZZOFDACTION_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDURI.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDGoto.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDGotoA.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDSound.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDMovie.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDRegion.h"

#define FZZOFDACTION_Name "ofd:Action"

class FZZOFDAction : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDAction(FZZOFDXMLFileObject * parent);
    FZZOFDAction(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAction(const FZZOFDAction& obj);
    virtual ~FZZOFDAction();
    
public:
    void setEvent(EventType event);
    EventType getEvent();
    FZZOFDURI * setURI();
    FZZOFDURI * getURI();
    FZZOFDGoto * setGoto();
    FZZOFDGoto * getGoto();
    FZZOFDGotoA * setGotoA();
    FZZOFDGotoA * getGotoA();
    FZZOFDSound * setSound();
    FZZOFDSound * getSound();
    FZZOFDMovie * setMovie();
    FZZOFDMovie * getMovie();
    FZZOFDRegion * setRegion();
    FZZOFDRegion * getRegion();

    
protected:
    FZZOFDAction();
private:
    void deleteOFDActions();
private:
    FZZOFDURI * m_FZZOFDURI;
    FZZOFDGoto * m_FZZOFDGoto;
    FZZOFDGotoA * m_FZZOFDGotoA;
    FZZOFDSound * m_FZZOFDSound;
    FZZOFDMovie * m_FZZOFDMovie;
    FZZOFDRegion * m_FZZOFDRegion;
};

#endif //FZZOFDACTION_H
