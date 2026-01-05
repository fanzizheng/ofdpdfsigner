//
//  Created by zizheng fan on 2023/04/16.
//
#ifndef FZZSETTINGSXML_H
#define FZZSETTINGSXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWZoom.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBordersDoNotSurroundFooter.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBordersDoNotSurroundHeader.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCharacterSpacingControl.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDefaultTabStop.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDisplayHorizontalDrawingGridEvery.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDisplayVerticalDrawingGridEvery.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawingGridVerticalSpacing.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCompat.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsids.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMMathPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWProofState.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWClrSchemeMapping.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDecimalSymbol.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWListSeparator.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWThemeFontLang.h"
#include "office/ooxml/microsoft/office/word/x2012/wordml/FZZW15ChartTrackingRefBased.h"
#include "office/ooxml/microsoft/office/word/x2012/wordml/FZZW15DocId.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14DocId.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWEvenAndOddHeaders.h"

#define SETTINGSXML_FILENAME "settings.xml"

class FZZSettingsXML : public FZZOfficeObject
{
public:
    FZZSettingsXML();
    FZZSettingsXML(XMLDocument * doc);
    FZZSettingsXML(const FZZSettingsXML& obj);
    virtual ~FZZSettingsXML();
    
 
public:
    FZZWZoom * setZoom();
    FZZWZoom * getZoom();
    FZZWBordersDoNotSurroundHeader * setBordersDoNotSurroundHeader();
    FZZWBordersDoNotSurroundHeader * getBordersDoNotSurroundHeader();
    FZZWBordersDoNotSurroundFooter * setBordersDoNotSurroundFooter();
    FZZWBordersDoNotSurroundFooter * getBordersDoNotSurroundFooter();
    
    FZZWCharacterSpacingControl * setCharacterSpacingControl();
    FZZWCharacterSpacingControl * getCharacterSpacingControl();
    FZZWDefaultTabStop * setDefaultTabStop();
    FZZWDefaultTabStop * getDefaultTabStop();
    FZZWDisplayHorizontalDrawingGridEvery * setDisplayHorizontalDrawingGridEvery();
    FZZWDisplayHorizontalDrawingGridEvery * getDisplayHorizontalDrawingGridEvery();
    FZZWDisplayVerticalDrawingGridEvery * setDisplayVerticalDrawingGridEvery();
    FZZWDisplayVerticalDrawingGridEvery * getDisplayVerticalDrawingGridEvery();
    FZZWDrawingGridVerticalSpacing * setDrawingGridVerticalSpacing();
    FZZWDrawingGridVerticalSpacing * getDrawingGridVerticalSpacing();
    FZZWCompat * setCompat();
    FZZWCompat * getCompat();
    FZZWRsids * setRsids();
    FZZWRsids * getRsids();
    
    FZZWProofState * setProofState();
    FZZWProofState * getProofState();
    FZZWClrSchemeMapping * setClrSchemeMapping();
    FZZWClrSchemeMapping * getClrSchemeMapping();
    FZZWDecimalSymbol * setDecimalSymbol();
    FZZWDecimalSymbol * getDecimalSymbol();
    FZZWListSeparator * setListSeparator();
    FZZWListSeparator * getListSeparator();
    FZZWThemeFontLang * setWThemeFontLang();
    FZZWThemeFontLang * getWThemeFontLang();
    FZZW15ChartTrackingRefBased * setW15ChartTrackingRefBased();
    FZZW15ChartTrackingRefBased * getW15ChartTrackingRefBased();
    FZZW15DocId * setW15DocId();
    FZZW15DocId * getW15DocId();
    FZZW14DocId * setW14DocId();
    FZZW14DocId * getW14DocId();
    FZZWEvenAndOddHeaders * setEvenAndOddHeaders();
    FZZWEvenAndOddHeaders * getEvenAndOddHeaders();
    
    FZZMMathPr* addMathPr();
    vector<FZZMMathPr*> * getMathPrs();
protected:
    void defaultInit();
private:
    FZZWZoom * m_FZZWZoom;
    FZZWBordersDoNotSurroundFooter * m_FZZWBordersDoNotSurroundFooter;
    FZZWBordersDoNotSurroundHeader * m_FZZWBordersDoNotSurroundHeader;
    FZZWCharacterSpacingControl * m_FZZWCharacterSpacingControl;
    FZZWDefaultTabStop * m_FZZWDefaultTabStop;
    FZZWDisplayHorizontalDrawingGridEvery * m_FZZWDisplayHorizontalDrawingGridEvery;
    FZZWDisplayVerticalDrawingGridEvery * m_FZZWDisplayVerticalDrawingGridEvery;
    FZZWDrawingGridVerticalSpacing * m_FZZWDrawingGridVerticalSpacing;
    FZZWCompat * m_FZZWCompat;
    FZZWRsids * m_FZZWRsids;
    
    FZZWProofState * m_FZZWProofState;
    FZZWClrSchemeMapping* m_FZZWClrSchemeMapping;
    FZZWDecimalSymbol * m_FZZWDecimalSymbol;
    FZZWListSeparator * m_FZZWListSeparator;
    FZZWThemeFontLang * m_FZZWThemeFontLang;
    
    FZZW15ChartTrackingRefBased * m_FZZW15ChartTrackingRefBased;
    FZZW15DocId * m_FZZW15DocId;
    FZZW14DocId * m_FZZW14DocId;
    
    FZZWEvenAndOddHeaders * m_FZZWEvenAndOddHeaders;
    
    vector<FZZMMathPr*> m_FZZMMathPrs;
};

#endif //FZZSETTINGSXML_H
