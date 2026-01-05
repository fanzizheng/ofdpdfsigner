//
//  Created by zizheng fan on 2023/04/08.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZStylesXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZStylesXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZStylesXML::FZZStylesXML() : FZZOfficeObject(),m_FZZWDocDefaults(NULL),m_FZZWLatentStyles(NULL),m_StyleId(-2)
{
    //DLOG("FZZStylesXML()");
    FZZConst::addClassCount("FZZStylesXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:styles");
    ofd_Document->SetAttribute(OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_NAME, OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_NAME, OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDML_NAME, MICROSOFT_OFFICE_WORD_2010_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2012_WORDML_NAME, MICROSOFT_OFFICE_WORD_2012_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2016_WORDML_CID_NAME, MICROSOFT_OFFICE_WORD_2016_WORDML_CID_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_NAME, MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_NAME, MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_VALUE);
    ofd_Document->SetAttribute(MC_IGNORABLE_NAME, MC_IGNORABLE_VALUE1);
    
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    m_FileName = STYLESXML_FILENAME;
    
    defaultInit();
}
//-----------------------------------------------------------------------------------------------------------------
FZZStylesXML::FZZStylesXML(XMLDocument * doc) : FZZOfficeObject(doc),m_FZZWDocDefaults(NULL),m_FZZWLatentStyles(NULL)
{
    FZZConst::addClassCount("FZZStylesXML");
    m_FileName = STYLESXML_FILENAME;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZStylesXML::FZZStylesXML(const FZZStylesXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZStylesXML");
    if ( this == &obj ) {
        return;
    }
    
    m_StyleId = obj.m_StyleId;
    m_FZZWDocDefaults = obj.m_FZZWDocDefaults != NULL ? new FZZWDocDefaults(*obj.m_FZZWDocDefaults) : NULL;
    m_FZZWLatentStyles = obj.m_FZZWLatentStyles != NULL ? new FZZWLatentStyles(*obj.m_FZZWLatentStyles) : NULL;
    
    vector<FZZWStyle*>::const_iterator itr;
    for( itr = obj.m_FZZWStyles.begin(); itr != obj.m_FZZWStyles.end(); itr++ ) {
        FZZWStyle * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWStyles.push_back(new FZZWStyle(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZStylesXML::~FZZStylesXML()
{
    //DLOG("~FZZStylesXML()");
    FZZConst::delClassCount("FZZStylesXML");
    
    if ( m_FZZWDocDefaults != NULL ) {
        delete m_FZZWDocDefaults;
        m_FZZWDocDefaults = NULL;
    }
    if ( m_FZZWLatentStyles != NULL ) {
        delete m_FZZWLatentStyles;
        m_FZZWLatentStyles = NULL;
    }
    
    vector<FZZWStyle*>::const_iterator itr;
    for( itr = m_FZZWStyles.begin(); itr != m_FZZWStyles.end(); itr++ ) {
        FZZWStyle * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWStyles.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZStylesXML::defaultInit()
{
    FZZWDocDefaults * DocDefaults = setDocDefaults();
    if ( DocDefaults != NULL ) {
        FZZWRPrDefault * rprDefault = NULL;
        FZZWPPrDefault * pprDefault = NULL;
        FZZWRPr * rpr = NULL;
        FZZWPPr * ppr = NULL;
        rprDefault = DocDefaults->setRPrDefault();//DocDefaults->addRPrDefault();
        if ( rprDefault != NULL ) {
            rpr = rprDefault->setRPr();
            if ( rpr != NULL ) {
                FZZWRFonts * rFonts = rpr->setRFonts();
                if ( rFonts != NULL ) {
                    rFonts->setAsciiTheme("minorHAnsi");
                    rFonts->setEastAsiaTheme("minorEastAsia");
                    rFonts->setHAnsiTheme("minorHAnsi");
                    rFonts->setCstheme("minorBidi");
                }
                FZZWKern * Kern = rpr->setKern();
                if ( Kern != NULL ) { Kern->setVal("2"); }
                FZZWSz * Sz = rpr->setSz();
                if ( Sz != NULL ) { Sz->setVal("21"); }
                FZZWSzCS * SzCS = rpr->setSzCS();
                if ( SzCS != NULL ) { SzCS->setVal("24"); }
                FZZWLang * Lang = rpr->setLang();
                if ( Lang != NULL ) {
                    Lang->setVal("en-US");
                    Lang->setEastAsia("zh-CN");
                    Lang->setBidi("ar-SA");
                }
            }
        }
        pprDefault = DocDefaults->setPPrDefault();//DocDefaults->addPPrDefault();
        if ( pprDefault != NULL ) {
            ppr = pprDefault->setPPr();
            if ( ppr != NULL ) {
                FZZWSpacing * Spacing = ppr->setSpacing();
                if ( Spacing != NULL ) {
                    Spacing->setAfter("220");
                    Spacing->setLine("360");
                    Spacing->setLineRule("auto");
                }
                FZZWJc * Jc = ppr->setJc();
                if ( Jc != NULL ) { Jc->setVal("both"); }
                
            }
        }
    }
    
    FZZWLatentStyles * LatentStyles = setLatentStyles();
    if ( LatentStyles != NULL ) {
        LatentStyles->setDefLockedState("0");
        LatentStyles->setDefUIPriority("99");
        LatentStyles->setDefSemiHidden("0");
        LatentStyles->setDefUnhideWhenUsed("0");
        LatentStyles->setDefQFormat("0");
        
        FZZWLsdException * LsdException = NULL;
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("Normal");
            LsdException->setUiPriority("0");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 1");
            LsdException->setUiPriority("9");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 2");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 3");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 4");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 5");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 6");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 7");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 8");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("heading 9");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("9");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 1");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 2");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 3");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 4");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 5");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 6");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 7");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 8");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index 9");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 1");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 2");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 3");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 4");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 5");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 6");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 7");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 8");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toc 9");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("39");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("Normal Indent");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("footnote text");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("annotation text");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("header");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("footer");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("index heading");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("caption");
            LsdException->setSemiHidden("1");
            LsdException->setUiPriority("35");
            LsdException->setUnhideWhenUsed("1");
            LsdException->setQFormat("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("table of figures");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("envelope address");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("envelope return");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("footnote reference");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("annotation reference");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("line number");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("page number");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("endnote reference");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("endnote text");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("table of authorities");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("macro");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("toa heading");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("List");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("List Bullet");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
        if ( LsdException != NULL ) {
            LsdException->setName("List Number");
            LsdException->setSemiHidden("1");
            LsdException->setUnhideWhenUsed("1");
        }
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Bullet 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Bullet 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Bullet 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Bullet 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Number 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Number 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Number 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Number 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Title");LsdException->setUiPriority("10");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Closing" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Signature" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Default Paragraph Font" );LsdException->setSemiHidden("1");LsdException->setUiPriority("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text Indent" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Continue" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Continue 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Continue 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Continue 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Continue 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Message Header" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Subtitle");LsdException->setUiPriority("11");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Salutation" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Date" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text First Indent" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text First Indent 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Note Heading" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text Indent 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Body Text Indent 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Block Text" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Hyperlink" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("FollowedHyperlink" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Strong");LsdException->setUiPriority("22");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Emphasis");LsdException->setUiPriority("20");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Document Map" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Plain Text" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("E-mail Signature" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Top of Form" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Bottom of Form" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Normal (Web)" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Acronym" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Address" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Cite" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Code" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Definition" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Keyboard" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Preformatted" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Sample" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Typewriter" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("HTML Variable" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Normal Table" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("annotation subject" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("No List" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Outline List 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Outline List 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Outline List 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Simple 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Simple 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Simple 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Classic 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Classic 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Classic 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Classic 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Colorful 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Colorful 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Colorful 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Columns 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Columns 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Columns 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Columns 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Columns 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 6" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 7" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid 8" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 4" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 5" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 6" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 7" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table List 8" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table 3D effects 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table 3D effects 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table 3D effects 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Contemporary" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Elegant" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Professional" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Subtle 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Subtle 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Web 1" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Web 2" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Web 3" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Balloon Text" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Grid");LsdException->setUiPriority("39");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Table Theme" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Placeholder Text" );LsdException->setSemiHidden("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("No Spacing");LsdException->setUiPriority("1");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading Accent 1");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List Accent 1");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid Accent 1");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1 Accent 1");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2 Accent 1");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1 Accent 1");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Revision" );LsdException->setSemiHidden("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Paragraph");LsdException->setUiPriority("34");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Quote");LsdException->setUiPriority("29");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Intense Quote");LsdException->setUiPriority("30");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2 Accent 1");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1 Accent 1");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2 Accent 1");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3 Accent 1");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List Accent 1");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading Accent 1");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List Accent 1");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid Accent 1");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading Accent 2");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List Accent 2");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid Accent 2");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1 Accent 2");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2 Accent 2");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1 Accent 2");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2 Accent 2");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1 Accent 2");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2 Accent 2");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3 Accent 2");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List Accent 2");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading Accent 2");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List Accent 2");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid Accent 2");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading Accent 3");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List Accent 3");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid Accent 3");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1 Accent 3");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2 Accent 3");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1 Accent 3");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2 Accent 3");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1 Accent 3");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2 Accent 3");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3 Accent 3");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List Accent 3");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading Accent 3");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List Accent 3");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid Accent 3");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading Accent 4");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List Accent 4");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid Accent 4");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1 Accent 4");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2 Accent 4");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1 Accent 4");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2 Accent 4");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1 Accent 4");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2 Accent 4");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3 Accent 4");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List Accent 4");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading Accent 4");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List Accent 4");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid Accent 4");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading Accent 5");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List Accent 5");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid Accent 5");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1 Accent 5");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2 Accent 5");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1 Accent 5");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2 Accent 5");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1 Accent 5");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2 Accent 5");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3 Accent 5");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List Accent 5");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading Accent 5");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List Accent 5");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid Accent 5");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Shading Accent 6");LsdException->setUiPriority("60");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light List Accent 6");LsdException->setUiPriority("61");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Light Grid Accent 6");LsdException->setUiPriority("62");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 1 Accent 6");LsdException->setUiPriority("63");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Shading 2 Accent 6");LsdException->setUiPriority("64");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 1 Accent 6");LsdException->setUiPriority("65");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium List 2 Accent 6");LsdException->setUiPriority("66");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 1 Accent 6");LsdException->setUiPriority("67");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 2 Accent 6");LsdException->setUiPriority("68");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Medium Grid 3 Accent 6");LsdException->setUiPriority("69");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Dark List Accent 6");LsdException->setUiPriority("70");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Shading Accent 6");LsdException->setUiPriority("71");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful List Accent 6");LsdException->setUiPriority("72");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Colorful Grid Accent 6");LsdException->setUiPriority("73");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Subtle Emphasis");LsdException->setUiPriority("19");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Intense Emphasis");LsdException->setUiPriority("21");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Subtle Reference");LsdException->setUiPriority("31");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Intense Reference");LsdException->setUiPriority("32");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Book Title");LsdException->setUiPriority("33");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Bibliography" );LsdException->setSemiHidden("1");LsdException->setUiPriority("37");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("TOC Heading" );LsdException->setSemiHidden("1");LsdException->setUiPriority("39");LsdException->setUnhideWhenUsed("1");LsdException->setQFormat("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Plain Table 1");LsdException->setUiPriority("41");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Plain Table 2");LsdException->setUiPriority("42");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Plain Table 3");LsdException->setUiPriority("43");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Plain Table 4");LsdException->setUiPriority("44");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Plain Table 5");LsdException->setUiPriority("45");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table Light");LsdException->setUiPriority("40");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light Accent 1");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2 Accent 1");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3 Accent 1");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4 Accent 1");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark Accent 1");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful Accent 1");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful Accent 1");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light Accent 2");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2 Accent 2");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3 Accent 2");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4 Accent 2");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark Accent 2");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful Accent 2");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful Accent 2");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light Accent 3");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2 Accent 3");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3 Accent 3");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4 Accent 3");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark Accent 3");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful Accent 3");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful Accent 3");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light Accent 4");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2 Accent 4");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3 Accent 4");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4 Accent 4");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark Accent 4");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful Accent 4");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful Accent 4");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light Accent 5");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2 Accent 5");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3 Accent 5");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4 Accent 5");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark Accent 5");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful Accent 5");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful Accent 5");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 1 Light Accent 6");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 2 Accent 6");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 3 Accent 6");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 4 Accent 6");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 5 Dark Accent 6");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 6 Colorful Accent 6");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Grid Table 7 Colorful Accent 6");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light Accent 1");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2 Accent 1");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3 Accent 1");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4 Accent 1");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark Accent 1");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful Accent 1");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful Accent 1");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light Accent 2");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2 Accent 2");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3 Accent 2");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4 Accent 2");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark Accent 2");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful Accent 2");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful Accent 2");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light Accent 3");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2 Accent 3");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3 Accent 3");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4 Accent 3");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark Accent 3");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful Accent 3");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful Accent 3");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light Accent 4");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2 Accent 4");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3 Accent 4");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4 Accent 4");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark Accent 4");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful Accent 4");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful Accent 4");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light Accent 5");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2 Accent 5");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3 Accent 5");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4 Accent 5");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark Accent 5");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful Accent 5");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful Accent 5");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 1 Light Accent 6");LsdException->setUiPriority("46");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 2 Accent 6");LsdException->setUiPriority("47");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 3 Accent 6");LsdException->setUiPriority("48");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 4 Accent 6");LsdException->setUiPriority("49");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 5 Dark Accent 6");LsdException->setUiPriority("50");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 6 Colorful Accent 6");LsdException->setUiPriority("51");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("List Table 7 Colorful Accent 6");LsdException->setUiPriority("52");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Mention" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Smart Hyperlink" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Hashtag" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Unresolved Mention" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        LsdException = LatentStyles->addFZZWLsdException();
                if ( LsdException != NULL ) {LsdException->setName("Smart Link" );LsdException->setSemiHidden("1");LsdException->setUnhideWhenUsed("1");}
        
        vector<FZZWLsdException*> * lsdlist = LatentStyles->getFZZWLsdExceptions();
        LatentStyles->setCount(lsdlist == NULL ? "0" : FZZConst::fmt(lsdlist->size()));
    }
    
    FZZWName * ctwName = NULL;
    FZZWUnhideWhenUsed * ctwUnhideWhenUsed = NULL;
    FZZWSemiHidden * ctwSemiHidden = NULL;
    FZZWUiPriority * ctwUiPriority = NULL;
    FZZWQFormat * ctwQFormat = NULL;
    FZZWTblPr * ctwTblPr  = NULL;
    FZZWTblInd * ctwTblInd = NULL;
    FZZWTblCellMar * ctwTblCellMar = NULL;
    FZZWTop * ctwTop = NULL;
    FZZWLeft * ctwLeft = NULL;
    FZZWBottom * ctwBottom = NULL;
    FZZWRight * ctwRight = NULL;
    
    FZZWStyle * style = addStyle();
    if ( style != NULL ) {
        style->setType("paragraph");
        style->setDefault("1");
        style->setStyleId(getNextStyleID_ToString());
        ctwName = style->setName();
        if ( ctwName != NULL ) { ctwName->setVal("Normal"); }
        ctwQFormat = style->setQFormat();
    }
    
    style = addStyle();
    if ( style != NULL ) {
        style->setType("character");
        style->setDefault("1");
        style->setStyleId(getNextStyleID_ToString());
        ctwName = style->setName();
        if ( ctwName != NULL ) { ctwName->setVal("Default Paragraph Font"); }
        ctwUiPriority = style->setUiPriority();
        if ( ctwUiPriority != NULL ) { ctwUiPriority->setVal("1"); }
        ctwSemiHidden = style->setSemiHidden();
        ctwUnhideWhenUsed = style->setUnhideWhenUsed();
    }
    style = addStyle();
    if ( style != NULL ) {
        style->setType("table");
        style->setDefault("1");
        style->setStyleId(getNextStyleID_ToString());
        ctwName = style->setName();
        if ( ctwName != NULL ) { ctwName->setVal("Normal Table"); }
        ctwUiPriority = style->setUiPriority();
        if ( ctwUiPriority != NULL ) { ctwUiPriority->setVal("99"); }
        ctwSemiHidden = style->setSemiHidden();
        ctwUnhideWhenUsed = style->setUnhideWhenUsed();
        //ctwTblPr = style->addTblPr();
        ctwTblPr = style->setTblPr();
        if ( ctwTblPr != NULL ) {
            ctwTblInd = ctwTblPr->setTblInd();
            if ( ctwTblInd != NULL ) { ctwTblInd->setW("0"); ctwTblInd->setType("dxa"); }
            ctwTblCellMar = ctwTblPr->setTblCellMar();
            if ( ctwTblCellMar != NULL ) {
                ctwTop = ctwTblCellMar->setTop();
                if ( ctwTop != NULL ) { ctwTop->setW("0"); ctwTop->setType("dxa"); }
                ctwLeft = ctwTblCellMar->setLeft();
                if ( ctwLeft != NULL ) { ctwLeft->setW("108"); ctwLeft->setType("dxa"); }
                ctwBottom = ctwTblCellMar->setBottom();
                if ( ctwBottom != NULL ) { ctwBottom->setW("0"); ctwBottom->setType("dxa"); }
                ctwRight = ctwTblCellMar->setRight();
                if ( ctwRight != NULL ) { ctwRight->setW("108"); ctwRight->setType("dxa"); }
            }
        }
    }
    style = addStyle();
    if ( style != NULL ) {
        style->setType("numbering");
        style->setDefault("1");
        style->setStyleId(getNextStyleID_ToString());
        ctwName = style->setName();
        if ( ctwName != NULL ) { ctwName->setVal("No List"); }
        ctwUiPriority = style->setUiPriority();
        if ( ctwUiPriority != NULL ) { ctwUiPriority->setVal("99"); }
        ctwSemiHidden = style->setSemiHidden();
        ctwUnhideWhenUsed = style->setUnhideWhenUsed();
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults * FZZStylesXML::setDocDefaults()
{
    return m_FZZWDocDefaults = setElementObject(m_FZZWDocDefaults,FZZWDOCDEFAULTS_Find_Key,FZZWDOCDEFAULTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults * FZZStylesXML::getDocDefaults()
{
    return m_FZZWDocDefaults = getElementObject(m_FZZWDocDefaults,FZZWDOCDEFAULTS_Find_Key,FZZWDOCDEFAULTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles * FZZStylesXML::setLatentStyles()
{
    return m_FZZWLatentStyles = setElementObject(m_FZZWLatentStyles,FZZWLATENTSTYLES_Find_Key,FZZWLATENTSTYLES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLatentStyles * FZZStylesXML::getLatentStyles()
{
    return m_FZZWLatentStyles = getElementObject(m_FZZWLatentStyles,FZZWLATENTSTYLES_Find_Key,FZZWLATENTSTYLES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle * FZZStylesXML::addStyle()
{
    return addElementObject(&m_FZZWStyles,FZZWSTYLE_Find_Key,FZZWSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWStyle*> * FZZStylesXML::getStyles()
{
    getElementObjectList(&m_FZZWStyles,FZZWSTYLE_Find_Key,FZZWSTYLE_Name);
    
    if ( m_FZZWStyles.size() > 0 ) {
        int maxid = -2;
        vector<FZZWStyle*> * styleList = &m_FZZWStyles;
        vector<FZZWStyle*>::const_iterator itr;
        for( itr = styleList->begin(); itr != styleList->end(); itr++ ) {
            FZZWStyle * temp = *itr;
            if ( temp != NULL ) {
                string tempid = temp->getStyleId();
                if ( tempid.length() == 1 ) {
                    maxid = -1;
                    continue;
                } else if ( tempid.length() > 1 ) {
                    tempid = tempid.substr(1);
                    size_t pos = tempid.find("a");
                    if ( pos != string::npos ) {
                        tempid = tempid.substr(pos+1);
                        int num = atoi(tempid.c_str());
                        if ( maxid < num ) {
                            maxid = num;
                        }
                    }
                }
                
                
            }
        }
        m_StyleId = maxid;
    }
    
    return &m_FZZWStyles;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZStylesXML::getNextStyleID_ToString()
{
    m_StyleId++;
    if ( m_StyleId == -1 ) {
        return "a";
    }
    return "a"+FZZConst::fmt(m_StyleId);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZStylesXML::getCurrStyleID_ToString()
{
    if ( m_StyleId == -2 ) {
        return getNextStyleID_ToString();
    }
    if ( m_StyleId == -1 ) {
        return "a";
    }
    return "a"+FZZConst::fmt(m_StyleId);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle * FZZStylesXML::getStyle(string styleId)
{
    FZZWStyle * ret = NULL;
    vector<FZZWStyle*> * ctwStyleList = getStyles();
    string tempStyleId = "";
    vector<FZZWStyle*>::const_iterator itr;
    for( itr = ctwStyleList->begin(); itr != ctwStyleList->end(); itr++ ) {
        FZZWStyle * temp = *itr;
        if ( temp != NULL ) {
            tempStyleId = temp->getStyleId();
            if ( tempStyleId == styleId ) {
                ret = temp;
                break;
            }
        }
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
