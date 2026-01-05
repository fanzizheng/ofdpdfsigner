//
//  Created by zizheng fan on 2023/10/11
//
#ifndef FZZWRPR_H
#define FZZWRPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpacing.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWJc.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLang.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSzCS.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSz.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWKern.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRFonts.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWColor.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBCs.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWB.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14TextFill.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVertAlign.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNoProof.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRStyle.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWW.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWU.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVanish.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPosition.h"

#define FZZWRPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRPR_Name "rPr"

class FZZWRPr : public FZZXMLElementObject
{
public:
    
    FZZWRPr(FZZOfficeObject * parent);
    FZZWRPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRPr(const FZZWRPr& obj);
    virtual ~FZZWRPr();
    
public:
    FZZWSpacing * setSpacing();
    FZZWSpacing * getSpacing();
    FZZWJc * setJc();
    FZZWJc * getJc();
    FZZWLang * setLang();
    FZZWLang * getLang();
    FZZWSzCS * setSzCS();
    FZZWSzCS * getSzCS();
    FZZWSz * setSz();
    FZZWSz * getSz();
    FZZWKern * setKern();
    FZZWKern * getKern();
    FZZWRFonts * setRFonts();
    FZZWRFonts * getRFonts();
    FZZWColor * setColor();
    FZZWColor * getColor();
    FZZWBCs * setBCs();
    FZZWBCs * getBCs();
    FZZWB * setB();
    FZZWB * getB();
    FZZW14TextFill * setTextFill();
    FZZW14TextFill * getTextFill();
    FZZWVertAlign * setVertAlign();
    FZZWVertAlign * getVertAlign();
    FZZWNoProof * setNoProof();
    FZZWNoProof * getNoProof();
    FZZWRStyle * setRStyle();
    FZZWRStyle * getRStyle();
    FZZWW * setW();
    FZZWW * getW();
    FZZWU * setU();
    FZZWU * getU();
    FZZWVanish * setVanish();
    FZZWVanish * getVanish();
    FZZWPosition * setPosition();
    FZZWPosition * getPosition();
protected:
    FZZWRPr();
private:
    FZZWSpacing * m_FZZWSpacing;
    FZZWJc * m_FZZWJc;
    FZZWLang * m_FZZWLang;
    FZZWSzCS * m_FZZWSzCS;
    FZZWSz * m_FZZWSz;
    FZZWKern * m_FZZWKern;
    FZZWRFonts * m_FZZWRFonts;
    FZZWColor * m_FZZWColor;
    FZZWBCs * m_FZZWBCs;
    FZZWB * m_FZZWB;
    FZZW14TextFill * m_FZZW14TextFill;
    FZZWVertAlign * m_FZZWVertAlign;
    FZZWNoProof * m_FZZWNoProof;
    FZZWRStyle * m_FZZWRStyle;
    FZZWW * m_FZZWW;
    FZZWU * m_FZZWU;
    FZZWVanish * m_FZZWVanish;
    FZZWPosition * m_FZZWPosition;
};

#endif //FZZWRPR_H
