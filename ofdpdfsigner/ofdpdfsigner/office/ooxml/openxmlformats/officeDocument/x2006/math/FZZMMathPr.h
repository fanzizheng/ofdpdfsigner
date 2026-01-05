//
//  Created by zizheng fan on 2023/05/24
//
#ifndef FZZMMATHPR_H
#define FZZMMATHPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMBrkBin.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMBrkBinSub.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMDefJc.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMDispDef.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMIntLim.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMLMargin.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMMathFont.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMNaryLim.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMRMargin.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMSmallFrac.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMWrapIndent.h"

#define FZZMMATHPR_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMMATHPR_Name "mathPr"

class FZZMMathPr : public FZZXMLElementObject
{
public:
    
    FZZMMathPr(FZZOfficeObject * parent);
    FZZMMathPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMMathPr(const FZZMMathPr& obj);
    virtual ~FZZMMathPr();
    
public:
    FZZMBrkBin * setBrkBin();
    FZZMBrkBin * getBrkBin();
    FZZMBrkBinSub * setBrkBinSub();
    FZZMBrkBinSub * getBrkBinSub();
    FZZMDefJc * setDefJc();
    FZZMDefJc * getDefJc();
    FZZMDispDef * setDispDef();
    FZZMDispDef * getDispDef();
    FZZMIntLim * setIntLim();
    FZZMIntLim * getIntLim();
    FZZMLMargin * setLMargin();
    FZZMLMargin * getLMargin();
    FZZMMathFont * setMathFont();
    FZZMMathFont * getMathFont();
    FZZMNaryLim * setNaryLim();
    FZZMNaryLim * getNaryLim();
    FZZMRMargin * setRMargin();
    FZZMRMargin * getRMargin();
    FZZMSmallFrac * setSmallFrac();
    FZZMSmallFrac * getSmallFrac();
    FZZMWrapIndent * setWrapIndent();
    FZZMWrapIndent * getWrapIndent();
protected:
    FZZMMathPr();
private:
    FZZMBrkBin* m_FZZMBrkBin;
    FZZMBrkBinSub * m_FZZMBrkBinSub;
    FZZMDefJc * m_FZZMDefJc;
    FZZMDispDef * m_FZZMDispDef;
    FZZMIntLim * m_FZZMIntLim;
    FZZMLMargin * m_FZZMLMargin;
    FZZMMathFont * m_FZZMMathFont;
    FZZMNaryLim * m_FZZMNaryLim;
    FZZMRMargin * m_FZZMRMargin;
    FZZMSmallFrac * m_FZZMSmallFrac;
    FZZMWrapIndent * m_FZZMWrapIndent;
};

#endif //FZZMMATHPR_H
