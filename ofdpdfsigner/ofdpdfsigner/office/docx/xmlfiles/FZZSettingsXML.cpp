//
//  Created by zizheng fan on 2023/04/16.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZSettingsXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZSettingsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSettingsXML::FZZSettingsXML() : FZZOfficeObject(),m_FZZWZoom(NULL),m_FZZWBordersDoNotSurroundFooter(NULL),
    m_FZZWBordersDoNotSurroundHeader(NULL),m_FZZWCharacterSpacingControl(NULL),m_FZZWDefaultTabStop(NULL),
    m_FZZWDisplayHorizontalDrawingGridEvery(NULL),m_FZZWDisplayVerticalDrawingGridEvery(NULL),
    m_FZZWDrawingGridVerticalSpacing(NULL),m_FZZWCompat(NULL),m_FZZWRsids(NULL),m_FZZWProofState(NULL),m_FZZWClrSchemeMapping(NULL),m_FZZWDecimalSymbol(NULL),m_FZZWListSeparator(NULL),m_FZZWThemeFontLang(NULL),m_FZZW15ChartTrackingRefBased(NULL),m_FZZW15DocId(NULL),m_FZZW14DocId(NULL),m_FZZWEvenAndOddHeaders(NULL)
{
    //DLOG("FZZSettingsXML()");
    FZZConst::addClassCount("FZZSettingsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:settings");
    ofd_Document->SetAttribute(OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_NAME,OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_VALUE );
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_OFFICE_NAME, MICROSOFT_OFFICE_OFFICE_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_URN_VML_NAME, MICROSOFT_URN_VML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_URN_OFFICE_WORD_NAME, MICROSOFT_URN_OFFICE_WORD_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_NAME, OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDML_NAME, MICROSOFT_OFFICE_WORD_2010_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2012_WORDML_NAME, MICROSOFT_OFFICE_WORD_2012_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2016_WORDML_CID_NAME, MICROSOFT_OFFICE_WORD_2016_WORDML_CID_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_NAME, MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_NAME, MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_SCHEMALIBRARY_2006_MAIN_NAME, OPENXMLFORMATS_SCHEMALIBRARY_2006_MAIN_VALUE);
    ofd_Document->SetAttribute(MC_IGNORABLE_NAME, MC_IGNORABLE_VALUE1);
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = SETTINGSXML_FILENAME;
    
    defaultInit();
}
//-----------------------------------------------------------------------------------------------------------------
FZZSettingsXML::FZZSettingsXML(XMLDocument * doc) : FZZOfficeObject(doc),m_FZZWZoom(NULL),m_FZZWBordersDoNotSurroundFooter(NULL),
    m_FZZWBordersDoNotSurroundHeader(NULL),m_FZZWCharacterSpacingControl(NULL),m_FZZWDefaultTabStop(NULL),
m_FZZWDisplayHorizontalDrawingGridEvery(NULL),m_FZZWDisplayVerticalDrawingGridEvery(NULL),
m_FZZWDrawingGridVerticalSpacing(NULL),m_FZZWCompat(NULL),m_FZZWRsids(NULL),m_FZZWProofState(NULL),m_FZZWClrSchemeMapping(NULL),m_FZZWDecimalSymbol(NULL),m_FZZWListSeparator(NULL),m_FZZWThemeFontLang(NULL),m_FZZW15ChartTrackingRefBased(NULL),m_FZZW15DocId(NULL),m_FZZW14DocId(NULL),m_FZZWEvenAndOddHeaders(NULL)
{
    FZZConst::addClassCount("FZZSettingsXML");
    
    m_FileName = SETTINGSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSettingsXML::FZZSettingsXML(const FZZSettingsXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZSettingsXML");
    if ( this == &obj ) {
        return;
    }
    m_FZZWZoom = obj.m_FZZWZoom != NULL ? new FZZWZoom(*obj.m_FZZWZoom) : NULL;
    m_FZZWBordersDoNotSurroundFooter = obj.m_FZZWBordersDoNotSurroundFooter != NULL ? new FZZWBordersDoNotSurroundFooter(*obj.m_FZZWBordersDoNotSurroundFooter) : NULL;
    m_FZZWBordersDoNotSurroundHeader = obj.m_FZZWBordersDoNotSurroundHeader != NULL ? new FZZWBordersDoNotSurroundHeader(*obj.m_FZZWBordersDoNotSurroundHeader) : NULL;
    
    m_FZZWCharacterSpacingControl = obj.m_FZZWCharacterSpacingControl != NULL ? new FZZWCharacterSpacingControl(*obj.m_FZZWCharacterSpacingControl) : NULL;
    m_FZZWDefaultTabStop = obj.m_FZZWDefaultTabStop != NULL ? new FZZWDefaultTabStop(*obj.m_FZZWDefaultTabStop) : NULL;
    m_FZZWDisplayHorizontalDrawingGridEvery = obj.m_FZZWDisplayHorizontalDrawingGridEvery != NULL ? new FZZWDisplayHorizontalDrawingGridEvery(*obj.m_FZZWDisplayHorizontalDrawingGridEvery) : NULL;
    m_FZZWDisplayVerticalDrawingGridEvery = obj.m_FZZWDisplayVerticalDrawingGridEvery != NULL ? new FZZWDisplayVerticalDrawingGridEvery(*obj.m_FZZWDisplayVerticalDrawingGridEvery) : NULL;
    m_FZZWDrawingGridVerticalSpacing = obj.m_FZZWDrawingGridVerticalSpacing != NULL ? new FZZWDrawingGridVerticalSpacing(*obj.m_FZZWDrawingGridVerticalSpacing) : NULL;
    m_FZZWCompat = obj.m_FZZWCompat != NULL ? new FZZWCompat(*obj.m_FZZWCompat) : NULL;
    m_FZZWRsids = obj.m_FZZWRsids != NULL ? new FZZWRsids(*obj.m_FZZWRsids) : NULL;
    
    m_FZZWProofState = obj.m_FZZWProofState != NULL ? new FZZWProofState(*obj.m_FZZWProofState) : NULL;
    m_FZZWClrSchemeMapping = obj.m_FZZWClrSchemeMapping != NULL ? new FZZWClrSchemeMapping(*obj.m_FZZWClrSchemeMapping) : NULL;
    m_FZZWDecimalSymbol = obj.m_FZZWDecimalSymbol != NULL ? new FZZWDecimalSymbol(*obj.m_FZZWDecimalSymbol) : NULL;
    m_FZZWListSeparator = obj.m_FZZWListSeparator != NULL ? new FZZWListSeparator(*obj.m_FZZWListSeparator) : NULL;
    m_FZZWThemeFontLang = obj.m_FZZWThemeFontLang != NULL ? new FZZWThemeFontLang(*obj.m_FZZWThemeFontLang) : NULL;
 
    m_FZZW15ChartTrackingRefBased = obj.m_FZZW15ChartTrackingRefBased != NULL ? new FZZW15ChartTrackingRefBased(*obj.m_FZZW15ChartTrackingRefBased) : NULL;
    m_FZZW15DocId = obj.m_FZZW15DocId != NULL ? new FZZW15DocId(*obj.m_FZZW15DocId) : NULL;
    m_FZZW14DocId = obj.m_FZZW14DocId != NULL ? new FZZW14DocId(*obj.m_FZZW14DocId) : NULL;
    m_FZZWEvenAndOddHeaders = obj.m_FZZWEvenAndOddHeaders != NULL ? new FZZWEvenAndOddHeaders(*obj.m_FZZWEvenAndOddHeaders) : NULL;
    
    vector<FZZMMathPr*>::const_iterator itr;
    for( itr = obj.m_FZZMMathPrs.begin(); itr != obj.m_FZZMMathPrs.end(); itr++ ) {
        FZZMMathPr * temp = *itr;
        if ( temp != NULL ) {
            m_FZZMMathPrs.push_back(new FZZMMathPr(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZSettingsXML::~FZZSettingsXML()
{
    //DLOG("~FZZSettingsXML()");
    FZZConst::delClassCount("FZZSettingsXML");
    if ( m_FZZWZoom != NULL ) {
        delete m_FZZWZoom;
        m_FZZWZoom = NULL;
    }
    if ( m_FZZWBordersDoNotSurroundFooter != NULL ) {
        delete m_FZZWBordersDoNotSurroundFooter;
        m_FZZWBordersDoNotSurroundFooter = NULL;
    }
    if ( m_FZZWBordersDoNotSurroundHeader != NULL ) {
        delete m_FZZWBordersDoNotSurroundHeader;
        m_FZZWBordersDoNotSurroundHeader = NULL;
    }
    
    if ( m_FZZWCharacterSpacingControl != NULL ) {
        delete m_FZZWCharacterSpacingControl;
        m_FZZWCharacterSpacingControl = NULL;
    }
    if ( m_FZZWDefaultTabStop != NULL ) {
        delete m_FZZWDefaultTabStop;
        m_FZZWDefaultTabStop = NULL;
    }
    if ( m_FZZWDisplayHorizontalDrawingGridEvery != NULL ) {
        delete m_FZZWDisplayHorizontalDrawingGridEvery;
        m_FZZWDisplayHorizontalDrawingGridEvery = NULL;
    }
    if ( m_FZZWDisplayVerticalDrawingGridEvery != NULL ) {
        delete m_FZZWDisplayVerticalDrawingGridEvery;
        m_FZZWDisplayVerticalDrawingGridEvery = NULL;
    }
    if ( m_FZZWDrawingGridVerticalSpacing != NULL ) {
        delete m_FZZWDrawingGridVerticalSpacing;
        m_FZZWDrawingGridVerticalSpacing = NULL;
    }
    if ( m_FZZWCompat != NULL ) {
        delete m_FZZWCompat;
        m_FZZWCompat = NULL;
    }
    if ( m_FZZWRsids != NULL ) {
        delete m_FZZWRsids;
        m_FZZWRsids = NULL;
    }
    
    if ( m_FZZWProofState != NULL ) {
        delete m_FZZWProofState;
        m_FZZWProofState = NULL;
    }
    if ( m_FZZWClrSchemeMapping != NULL ) {
        delete m_FZZWClrSchemeMapping;
        m_FZZWClrSchemeMapping = NULL;
    }
    if ( m_FZZWDecimalSymbol != NULL ) {
        delete m_FZZWDecimalSymbol;
        m_FZZWDecimalSymbol = NULL;
    }
    if ( m_FZZWListSeparator != NULL ) {
        delete m_FZZWListSeparator;
        m_FZZWListSeparator = NULL;
    }
    if ( m_FZZWThemeFontLang != NULL ) {
        delete m_FZZWThemeFontLang;
        m_FZZWThemeFontLang = NULL;
    }
    
    if ( m_FZZW15ChartTrackingRefBased != NULL ) {
        delete m_FZZW15ChartTrackingRefBased;
        m_FZZW15ChartTrackingRefBased = NULL;
    }
    if ( m_FZZW15DocId != NULL ) {
        delete m_FZZW15DocId;
        m_FZZW15DocId = NULL;
    }
    if ( m_FZZW14DocId != NULL ) {
        delete m_FZZW14DocId;
        m_FZZW14DocId = NULL;
    }
    
    if ( m_FZZWEvenAndOddHeaders != NULL ) {
        delete m_FZZWEvenAndOddHeaders;
        m_FZZWEvenAndOddHeaders = NULL;
    }
    
    vector<FZZMMathPr*>::const_iterator itr;
    for( itr = m_FZZMMathPrs.begin(); itr != m_FZZMMathPrs.end(); itr++ ) {
        FZZMMathPr * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZMMathPrs.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSettingsXML::defaultInit()
{
    FZZWZoom * zoom = setZoom();
    if ( zoom != NULL ) {
        zoom->setPercent("154");
    }
    FZZWBordersDoNotSurroundHeader * tempBordersDoNotSurroundHeader = setBordersDoNotSurroundHeader();
    FZZWBordersDoNotSurroundFooter * tempBordersDoNotSurroundFooter = setBordersDoNotSurroundFooter();
    FZZWProofState * ctwProofState = setProofState();
    if ( ctwProofState != NULL ) {
        ctwProofState->setSpelling("clean");
        ctwProofState->setGrammar("clean");
    }
    FZZWDefaultTabStop * DefaultTabStop = setDefaultTabStop();
    if ( DefaultTabStop != NULL ) { DefaultTabStop->setVal("420"); }
    FZZWDrawingGridVerticalSpacing * drawingGridVerticalSpacing = setDrawingGridVerticalSpacing();
    if ( drawingGridVerticalSpacing != NULL ) { drawingGridVerticalSpacing->setVal("156"); }
    FZZWDisplayHorizontalDrawingGridEvery * displayHorizontalDrawingGridEvery = setDisplayHorizontalDrawingGridEvery();
    if ( displayHorizontalDrawingGridEvery != NULL ) { displayHorizontalDrawingGridEvery->setVal("0"); }
    FZZWDisplayVerticalDrawingGridEvery * displayVerticalDrawingGridEvery = setDisplayVerticalDrawingGridEvery();
    if ( displayVerticalDrawingGridEvery != NULL ) { displayVerticalDrawingGridEvery->setVal("2"); }
    FZZWCharacterSpacingControl * characterSpacingControl = setCharacterSpacingControl();
    if ( characterSpacingControl != NULL ) { characterSpacingControl->setVal("compressPunctuation"); }
    FZZWCompat * compat = setCompat();
    if ( compat != NULL ) {
        FZZWSpaceForUL * SpaceForUL = compat->setSpaceForUL();
        FZZWBalanceSingleByteDoubleByteWidth * BalanceSingleByteDoubleByteWidth = compat->setBalanceSingleByteDoubleByteWidth();
        FZZWDoNotLeaveBackslashAlone * DoNotLeaveBackslashAlone = compat->setDoNotLeaveBackslashAlone();
        FZZWUlTrailSpace * UlTrailSpace = compat->setUlTrailSpace();
        FZZWDoNotExpandShiftReturn * DoNotExpandShiftReturn = compat->setDoNotExpandShiftReturn();
        FZZWAdjustLineHeightInTable * AdjustLineHeightInTable = compat->setAdjustLineHeightInTable();
        FZZWUseFELayout * UseFELayout = compat->setUseFELayout();

        FZZWCompatSetting * CompatSetting = NULL;
        CompatSetting = compat->addCompatSetting();
        if ( CompatSetting != NULL ) {
            CompatSetting->setName("compatibilityMode");
            CompatSetting->setUri("http://schemas.microsoft.com/office/word");
            CompatSetting->setVal("15");
        }
        CompatSetting = compat->addCompatSetting();
        if ( CompatSetting != NULL ) {
            CompatSetting->setName("overrideTableStyleFontSizeAndJustification");
            CompatSetting->setUri("http://schemas.microsoft.com/office/word");
            CompatSetting->setVal("1");
        }
        CompatSetting = compat->addCompatSetting();
        if ( CompatSetting != NULL ) {
            CompatSetting->setName("enableOpenTypeFeatures");
            CompatSetting->setUri("http://schemas.microsoft.com/office/word");
            CompatSetting->setVal("1");
        }
        CompatSetting = compat->addCompatSetting();
        if ( CompatSetting != NULL ) {
            CompatSetting->setName("doNotFlipMirrorIndents");
            CompatSetting->setUri("http://schemas.microsoft.com/office/word");
            CompatSetting->setVal("1");
        }
        CompatSetting = compat->addCompatSetting();
        if ( CompatSetting != NULL ) {
            CompatSetting->setName("differentiateMultirowTableHeaders");
            CompatSetting->setUri("http://schemas.microsoft.com/office/word");
            CompatSetting->setVal("1");
        }
        CompatSetting = compat->addCompatSetting();
        if ( CompatSetting != NULL ) {
            CompatSetting->setName("useWord2013TrackBottomHyphenation");
            CompatSetting->setUri("http://schemas.microsoft.com/office/word");
            CompatSetting->setVal("0");
        }
    }
    FZZWRsids * Rsids = setRsids();
    if ( Rsids != NULL ) {
        FZZWRsid::SetCurrRsid(FZZWRSIDROOT_NEW_ROOT_STR);
        
        FZZWRsidRoot * rsidRoot = Rsids->setRsidRoot();
        if ( rsidRoot != NULL ) { rsidRoot->setVal(FZZWRsid::GetCurrRsid_String()); }
        FZZWRsid * rsid = NULL;
//        rsid = Rsids->addRsid();
//        if ( rsid != NULL ) { rsid->setVal(FZZWRsid::GetCurrRsid_Next_String()); }
        rsid = Rsids->addRsid();
        if ( rsid != NULL && rsidRoot != NULL ) { rsid->setVal(rsidRoot->getVal()); }
    }
    
    FZZMMathPr* mathPr = addMathPr();
    if ( mathPr != NULL ) {
        FZZMMathFont * mathFont = mathPr->setMathFont();
        if ( mathFont != NULL ) { mathFont->setVal("Cambria Math"); }
        FZZMBrkBin * BrkBin = mathPr->setBrkBin();
        if ( BrkBin != NULL ) { BrkBin->setVal("before"); }
        FZZMBrkBinSub * BrkBinSub = mathPr->setBrkBinSub();
        if ( BrkBinSub != NULL ) { BrkBinSub->setVal("--"); }
        FZZMSmallFrac * SmallFrac = mathPr->setSmallFrac();
        if ( SmallFrac != NULL ) { SmallFrac->setVal("0"); }
        FZZMDispDef * DispDef = mathPr->setDispDef();
        FZZMLMargin * LMargin = mathPr->setLMargin();
        if ( LMargin != NULL ) { LMargin->setVal("0"); }
        FZZMRMargin * RMargin = mathPr->setRMargin();
        if ( RMargin != NULL ) { RMargin->setVal("0"); }
        FZZMDefJc * DefJc = mathPr->setDefJc();
        if ( DefJc != NULL ) { DefJc->setVal("centerGroup"); }
        FZZMWrapIndent * WrapIndent = mathPr->setWrapIndent();
        if ( WrapIndent != NULL ) { WrapIndent->setVal("1440"); }
        FZZMIntLim * IntLim = mathPr->setIntLim();
        if ( IntLim != NULL ) { IntLim->setVal("subSup"); }
        FZZMNaryLim * NaryLim = mathPr->setNaryLim();
        if ( NaryLim != NULL ) { NaryLim->setVal("undOvr"); }
     
    }
    
    FZZWThemeFontLang * ThemeFontLang = setWThemeFontLang();
    if ( ThemeFontLang != NULL ) {
        ThemeFontLang->setVal("en-US");
        ThemeFontLang->setEastAsia("zh-CN");
    }
    FZZWClrSchemeMapping * ClrSchemeMapping = setClrSchemeMapping();
    if ( ClrSchemeMapping != NULL ) {
        ClrSchemeMapping->setBg1("light1");
        ClrSchemeMapping->setT1("dark1");
        ClrSchemeMapping->setBg2("light2");
        ClrSchemeMapping->setT2("dark2");
        ClrSchemeMapping->setAccent1("accent1");
        ClrSchemeMapping->setAccent2("accent2");
        ClrSchemeMapping->setAccent3("accent3");
        ClrSchemeMapping->setAccent4("accent4");
        ClrSchemeMapping->setAccent5("accent5");
        ClrSchemeMapping->setAccent6("accent6");
        ClrSchemeMapping->setHyperlink("hyperlink");
        ClrSchemeMapping->setFollowedHyperlink("followedHyperlink");
    }
    
    FZZWDecimalSymbol * DecimalSymbol = setDecimalSymbol();
    if ( DecimalSymbol != NULL ) { DecimalSymbol->setVal("."); }
    FZZWListSeparator * ListSeparator = setListSeparator();
    if ( ListSeparator != NULL ) { ListSeparator->setVal(","); }
    FZZW14DocId * W14DocId = setW14DocId();
    if ( W14DocId != NULL ) { W14DocId->setVal("73AE3C00"); }
    FZZW15ChartTrackingRefBased * W15ChartTrackingRefBased = setW15ChartTrackingRefBased();
 
    FZZW15DocId * W15DocId = setW15DocId();
    if ( W15DocId != NULL ) { W15DocId->setVal("{5041E3B0-02D2-4E42-8A24-15F4607243E9}"); }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom * FZZSettingsXML::setZoom()
{
    return m_FZZWZoom = setElementObject(m_FZZWZoom,FZZWZOOM_Find_Key,FZZWZOOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom * FZZSettingsXML::getZoom()
{
    return m_FZZWZoom = getElementObject(m_FZZWZoom,FZZWZOOM_Find_Key,FZZWZOOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader * FZZSettingsXML::setBordersDoNotSurroundHeader()
{
    return m_FZZWBordersDoNotSurroundHeader = setElementObject(m_FZZWBordersDoNotSurroundHeader,FZZWBORDERSDONOTSURROUNDHEADER_Find_Key,FZZWBORDERSDONOTSURROUNDHEADER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader * FZZSettingsXML::getBordersDoNotSurroundHeader()
{
    return m_FZZWBordersDoNotSurroundHeader = getElementObject(m_FZZWBordersDoNotSurroundHeader,FZZWBORDERSDONOTSURROUNDHEADER_Find_Key,FZZWBORDERSDONOTSURROUNDHEADER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter * FZZSettingsXML::setBordersDoNotSurroundFooter()
{
    return m_FZZWBordersDoNotSurroundFooter = setElementObject(m_FZZWBordersDoNotSurroundFooter,FZZWBORDERSDONOTSURROUNDFOOTER_Find_Key,FZZWBORDERSDONOTSURROUNDFOOTER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter * FZZSettingsXML::getBordersDoNotSurroundFooter()
{
    return m_FZZWBordersDoNotSurroundFooter = getElementObject(m_FZZWBordersDoNotSurroundFooter,FZZWBORDERSDONOTSURROUNDFOOTER_Find_Key,FZZWBORDERSDONOTSURROUNDFOOTER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl * FZZSettingsXML::setCharacterSpacingControl()
{
    return m_FZZWCharacterSpacingControl = setElementObject(m_FZZWCharacterSpacingControl,FZZWCHARACTERSPACINGCONTROL_Find_Key,FZZWCHARACTERSPACINGCONTROL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl * FZZSettingsXML::getCharacterSpacingControl()
{
    return m_FZZWCharacterSpacingControl = getElementObject(m_FZZWCharacterSpacingControl,FZZWCHARACTERSPACINGCONTROL_Find_Key,FZZWCHARACTERSPACINGCONTROL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop * FZZSettingsXML::setDefaultTabStop()
{
    return m_FZZWDefaultTabStop = setElementObject(m_FZZWDefaultTabStop,FZZWDEFAULTTABSTOP_Find_Key,FZZWDEFAULTTABSTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop * FZZSettingsXML::getDefaultTabStop()
{
    return m_FZZWDefaultTabStop = getElementObject(m_FZZWDefaultTabStop,FZZWDEFAULTTABSTOP_Find_Key,FZZWDEFAULTTABSTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery * FZZSettingsXML::setDisplayHorizontalDrawingGridEvery()
{
    return m_FZZWDisplayHorizontalDrawingGridEvery = setElementObject(m_FZZWDisplayHorizontalDrawingGridEvery,FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_Find_Key,FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayHorizontalDrawingGridEvery * FZZSettingsXML::getDisplayHorizontalDrawingGridEvery()
{
    return m_FZZWDisplayHorizontalDrawingGridEvery = getElementObject(m_FZZWDisplayHorizontalDrawingGridEvery,FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_Find_Key,FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery * FZZSettingsXML::setDisplayVerticalDrawingGridEvery()
{
    return m_FZZWDisplayVerticalDrawingGridEvery = setElementObject(m_FZZWDisplayVerticalDrawingGridEvery,FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_Find_Key,FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDisplayVerticalDrawingGridEvery * FZZSettingsXML::getDisplayVerticalDrawingGridEvery()
{
    return m_FZZWDisplayVerticalDrawingGridEvery = getElementObject(m_FZZWDisplayVerticalDrawingGridEvery,FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_Find_Key,FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing * FZZSettingsXML::setDrawingGridVerticalSpacing()
{
    return m_FZZWDrawingGridVerticalSpacing = setElementObject(m_FZZWDrawingGridVerticalSpacing,FZZWDRAWINGGRIDVERTICALSPACING_Find_Key,FZZWDRAWINGGRIDVERTICALSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing * FZZSettingsXML::getDrawingGridVerticalSpacing()
{
    return m_FZZWDrawingGridVerticalSpacing = getElementObject(m_FZZWDrawingGridVerticalSpacing,FZZWDRAWINGGRIDVERTICALSPACING_Find_Key,FZZWDRAWINGGRIDVERTICALSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat * FZZSettingsXML::setCompat()
{
    return m_FZZWCompat = setElementObject(m_FZZWCompat,FZZWCOMPAT_Find_Key,FZZWCOMPAT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat * FZZSettingsXML::getCompat()
{
    return m_FZZWCompat = getElementObject(m_FZZWCompat,FZZWCOMPAT_Find_Key,FZZWCOMPAT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids * FZZSettingsXML::setRsids()
{
    return m_FZZWRsids = setElementObject(m_FZZWRsids,FZZWRSIDS_Find_Key,FZZWRSIDS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids * FZZSettingsXML::getRsids()
{
    return m_FZZWRsids = getElementObject(m_FZZWRsids,FZZWRSIDS_Find_Key,FZZWRSIDS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathPr* FZZSettingsXML::addMathPr()
{
    return addElementObject(&m_FZZMMathPrs,FZZMMATHPR_Find_Key,FZZMMATHPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZMMathPr*> * FZZSettingsXML::getMathPrs()
{
    getElementObjectList(&m_FZZMMathPrs,FZZMMATHPR_Find_Key,FZZMMATHPR_Name);
    return &m_FZZMMathPrs;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState * FZZSettingsXML::setProofState()
{
    return m_FZZWProofState = setElementObject(m_FZZWProofState,FZZWPROOFSTATE_Find_Key,FZZWPROOFSTATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState * FZZSettingsXML::getProofState()
{
    return m_FZZWProofState = getElementObject(m_FZZWProofState,FZZWPROOFSTATE_Find_Key,FZZWPROOFSTATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping * FZZSettingsXML::setClrSchemeMapping()
{
    return m_FZZWClrSchemeMapping = setElementObject(m_FZZWClrSchemeMapping,FZZWCLRSCHEMEMAPPING_Find_Key,FZZWCLRSCHEMEMAPPING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping * FZZSettingsXML::getClrSchemeMapping()
{
    return m_FZZWClrSchemeMapping = getElementObject(m_FZZWClrSchemeMapping,FZZWCLRSCHEMEMAPPING_Find_Key,FZZWCLRSCHEMEMAPPING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol * FZZSettingsXML::setDecimalSymbol()
{
    return m_FZZWDecimalSymbol = setElementObject(m_FZZWDecimalSymbol,FZZWDECIMALSYMBOL_Find_Key,FZZWDECIMALSYMBOL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol * FZZSettingsXML::getDecimalSymbol()
{
    return m_FZZWDecimalSymbol = getElementObject(m_FZZWDecimalSymbol,FZZWDECIMALSYMBOL_Find_Key,FZZWDECIMALSYMBOL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator * FZZSettingsXML::setListSeparator()
{
    return m_FZZWListSeparator = setElementObject(m_FZZWListSeparator,FZZWLISTSEPARATOR_Find_Key,FZZWLISTSEPARATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWListSeparator * FZZSettingsXML::getListSeparator()
{
    return m_FZZWListSeparator = getElementObject(m_FZZWListSeparator,FZZWLISTSEPARATOR_Find_Key,FZZWLISTSEPARATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang * FZZSettingsXML::setWThemeFontLang()
{
    return m_FZZWThemeFontLang = setElementObject(m_FZZWThemeFontLang,FZZWTHEMEFONTLANG_Find_Key,FZZWTHEMEFONTLANG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang * FZZSettingsXML::getWThemeFontLang()
{
    return m_FZZWThemeFontLang = getElementObject(m_FZZWThemeFontLang,FZZWTHEMEFONTLANG_Find_Key,FZZWTHEMEFONTLANG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased * FZZSettingsXML::setW15ChartTrackingRefBased()
{
    return m_FZZW15ChartTrackingRefBased = setElementObject(m_FZZW15ChartTrackingRefBased,FZZW15CHARTTRACKINGREFBASED_Find_Key,FZZW15CHARTTRACKINGREFBASED_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased * FZZSettingsXML::getW15ChartTrackingRefBased()
{
    return m_FZZW15ChartTrackingRefBased = getElementObject(m_FZZW15ChartTrackingRefBased,FZZW15CHARTTRACKINGREFBASED_Find_Key,FZZW15CHARTTRACKINGREFBASED_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId * FZZSettingsXML::setW14DocId()
{
    return m_FZZW14DocId = setElementObject(m_FZZW14DocId,FZZW14DOCID_Find_Key,FZZW14DOCID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId * FZZSettingsXML::getW14DocId()
{
    return m_FZZW14DocId = getElementObject(m_FZZW14DocId,FZZW14DOCID_Find_Key,FZZW14DOCID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId * FZZSettingsXML::setW15DocId()
{
    return m_FZZW15DocId = setElementObject(m_FZZW15DocId,FZZW15DOCID_Find_Key,FZZW15DOCID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId * FZZSettingsXML::getW15DocId()
{
    return m_FZZW15DocId = getElementObject(m_FZZW15DocId,FZZW15DOCID_Find_Key,FZZW15DOCID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders * FZZSettingsXML::setEvenAndOddHeaders()
{
    return m_FZZWEvenAndOddHeaders = setElementObject(m_FZZWEvenAndOddHeaders,FZZWEVENANDODDHEADERS_Find_Key,FZZWEVENANDODDHEADERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders * FZZSettingsXML::getEvenAndOddHeaders()
{
    return m_FZZWEvenAndOddHeaders = getElementObject(m_FZZWEvenAndOddHeaders,FZZWEVENANDODDHEADERS_Find_Key,FZZWEVENANDODDHEADERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
