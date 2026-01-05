//
//  Created by zizheng fan on 2023/11/27
//
#ifndef FZZWLVL_H
#define FZZWLVL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStart.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumFmt.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSuff.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvlText.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvlJc.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"

#define FZZWLVL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLVL_Name "lvl"

class FZZWLvl : public FZZXMLElementObject
{
public:
    
    FZZWLvl(FZZOfficeObject * parent);
    FZZWLvl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLvl(const FZZWLvl& obj);
    virtual ~FZZWLvl();
    
public:
    void setIlvl(string value);
    string getIlvl();
    
    FZZWStart * setStart();
    FZZWStart * getStart();
    FZZWNumFmt * setNumFmt();
    FZZWNumFmt * getNumFmt();
    FZZWSuff * setSuff();
    FZZWSuff * getSuff();
    FZZWLvlText * setLvlText();
    FZZWLvlText * getLvlText();
    FZZWLvlJc * setLvlJc();
    FZZWLvlJc * getLvlJc();
    
    FZZWPPr * setPPr();
    FZZWPPr * getPPr();
    FZZWRPr * setRPr();
    FZZWRPr * getRPr();
    
protected:
    FZZWLvl();
private:
    FZZWStart * m_FZZWStart;
    FZZWNumFmt * m_FZZWNumFmt;
    FZZWSuff * m_FZZWSuff;
    FZZWLvlText * m_FZZWLvlText;
    FZZWLvlJc * m_FZZWLvlJc;
    FZZWPPr * m_FZZWPPr;
    FZZWRPr * m_FZZWRPr;
};

#endif //FZZWLVL_H
