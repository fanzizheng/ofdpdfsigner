//
//  Created by zizheng fan on 2023/10/30
//
#ifndef FZZWPPR_H
#define FZZWPPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInd.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpacing.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWJc.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSectPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPBdr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPStyle.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWWidowControl.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTabs.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFramePr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumPr.h"

#define FZZWPPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPPR_Name "pPr"

class FZZWPPr : public FZZXMLElementObject
{
public:
    
    FZZWPPr(FZZOfficeObject * parent);
    FZZWPPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPPr(const FZZWPPr& obj);
    virtual ~FZZWPPr();
    
public:
    FZZWRPr * setRPr();
    FZZWRPr * getRPr();
    FZZWInd * setInd();
    FZZWInd * getInd();
    FZZWSpacing * setSpacing();
    FZZWSpacing * getSpacing();
    FZZWJc * setJc();
    FZZWJc * getJc();
    FZZWSectPr * setSectPr();
    FZZWSectPr * getSectPr();
    FZZWPStyle * setPStyle();
    FZZWPStyle * getPStyle();
    FZZWPBdr * setPBdr();
    FZZWPBdr * getPBdr();
    FZZWWidowControl * setWidowControl();
    FZZWWidowControl * getWidowControl();
    FZZWTabs * setTabs();
    FZZWTabs * getTabs();
    FZZWFramePr * setFramePr();
    FZZWFramePr * getFramePr();
    FZZWNumPr * setNumPr();
    FZZWNumPr * getNumPr();
protected:
    FZZWPPr();
private:
    FZZWRPr * m_FZZWRPr;
    FZZWInd * m_FZZWInd;
    FZZWSpacing * m_FZZWSpacing;
    FZZWJc * m_FZZWJc;
    FZZWSectPr * m_FZZWSectPr;
    FZZWPStyle * m_FZZWPStyle;
    FZZWPBdr * m_FZZWPBdr;
    FZZWWidowControl * m_FZZWWidowControl;
    FZZWTabs * m_FZZWTabs;
    FZZWFramePr * m_FZZWFramePr;
    FZZWNumPr * m_FZZWNumPr;
};

#endif //FZZWPPR_H
