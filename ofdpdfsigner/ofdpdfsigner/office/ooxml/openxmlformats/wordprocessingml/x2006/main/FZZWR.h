//
//  Created by zizheng fan on 2023/10/31
//
#ifndef FZZWR_H
#define FZZWR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWT.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTab.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawing.h"
#include "office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCAlternateContent.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSeparator.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWContinuationSeparator.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFldChar.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInstrText.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVertAlign.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLastRenderedPageBreak.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPict.h"

#define FZZWR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWR_Name "r"

class FZZWR : public FZZXMLElementObject
{
public:
    
    FZZWR(FZZOfficeObject * parent);
    FZZWR(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWR(const FZZWR& obj);
    virtual ~FZZWR();
    
public:
    void setRsidRPr(string value);
    string getRsidRPr();
    
    FZZWRPr * setRPr();
    FZZWRPr * getRPr();
    FZZWT * setT();
    FZZWT * getT();
    FZZWTab * setTab();
    FZZWTab * getTab();
    FZZWDrawing * setDrawing();
    FZZWDrawing * getDrawing();
    FZZMCAlternateContent * setAlternateContent();
    FZZMCAlternateContent * getAlternateContent();
    FZZWSeparator * setSeparator();
    FZZWSeparator * getSeparator();
    FZZWContinuationSeparator * setContinuationSeparator();
    FZZWContinuationSeparator * getContinuationSeparator();
    FZZWFldChar * setFldChar();
    FZZWFldChar * getFldChar();
    FZZWInstrText * setInstrText();
    FZZWInstrText * getInstrText();
    FZZWCr * setCr();
    FZZWCr * getCr();
    FZZWBr * setBr();
    FZZWBr * getBr();
    FZZWLastRenderedPageBreak * setLastRenderedPageBreak();
    FZZWLastRenderedPageBreak * getLastRenderedPageBreak();
    FZZWPict * setPict();
    FZZWPict * getPict();

protected:
    FZZWR();
private:
    FZZWRPr * m_FZZWRPr;
    FZZWT * m_FZZWT;
    FZZWTab * m_FZZWTab;
    FZZWDrawing * m_FZZWDrawing;
    FZZMCAlternateContent * m_FZZMCAlternateContent;
    FZZWSeparator * m_FZZWSeparator;
    FZZWContinuationSeparator * m_FZZWContinuationSeparator;
    FZZWFldChar * m_FZZWFldChar;
    FZZWInstrText * m_FZZWInstrText;
    FZZWCr * m_FZZWCr;
    FZZWBr * m_FZZWBr;
    FZZWLastRenderedPageBreak * m_FZZWLastRenderedPageBreak;
    FZZWPict * m_FZZWPict;
};

#endif //FZZWR_H
