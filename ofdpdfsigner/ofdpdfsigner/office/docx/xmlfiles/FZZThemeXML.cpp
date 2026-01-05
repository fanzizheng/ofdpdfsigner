//
//  Created by zizheng fan on 2023/04/08.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZThemeXML.h"
#include "office/docx/FZZDocXConst.h"
#include "office/ooxml/microsoft/office/thememl/x2012/main/FZZThemeFamily.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASrgbClr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASysClr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme_Item.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZThemeXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZThemeXML::FZZThemeXML() : FZZOfficeObject(),m_CTObjectDefaults(NULL),m_CTExtraClrSchemeLst(NULL),m_CTExtLst(NULL),
    m_CTthemeElements(NULL)
{
    //DLOG("FZZThemeXML()");
    FZZConst::addClassCount("FZZThemeXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("a:theme");
    ofd_Document->SetAttribute(OPENXMLFORMATS_DRAWINGML_2006_MAIN_NAME, OPENXMLFORMATS_DRAWINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute("name", "Office 主题​​");
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    
    InitXmlnsList();
    
    m_FileName = THEMEXML_FILENAME;
    
    setThemeElements();
    if ( m_CTthemeElements != NULL ) {
        FZZAClrScheme * clrScheme = m_CTthemeElements->setClrScheme();
        if ( clrScheme != NULL ) {
            clrScheme->setName("Office");
            FZZASrgbClr * srgbClr = NULL;
            
            FZZASysClr* sysClr;
            FZZAClrScheme_Item * item = clrScheme->addDk();
            if ( item != NULL ) {
                sysClr = item->setSysClr();
                if ( sysClr != NULL ) {
                    sysClr->setVal("windowText");
                    sysClr->setLastClr("000000");
                }
            }
            
            item = clrScheme->addLt();
            if ( item != NULL ) {
                sysClr = item->setSysClr();
                if ( sysClr != NULL ) {
                    sysClr->setVal("window");
                    sysClr->setLastClr("FFFFFF");
                }
            }
            
            item = clrScheme->addDk();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("44546A");
                }
            }
            item = clrScheme->addLt();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("E7E6E6");
                }
            }
            
            item = clrScheme->addAccent();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("4472C4");
                }
            }
            
            item = clrScheme->addAccent();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("ED7D31");
                }
            }
            
            item = clrScheme->addAccent();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("A5A5A5");
                }
            }
            
            item = clrScheme->addAccent();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("FFC000");
                }
            }
            
            item = clrScheme->addAccent();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("5B9BD5");
                }
            }
            
            item = clrScheme->addAccent();
            if ( item != NULL ) {
                srgbClr = item->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("70AD47");
                }
            }
            
            FZZAClrScheme_Item * hlink = clrScheme->setHlink();
            if ( hlink != NULL ) {
                srgbClr = hlink->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("0563C1");
                }
            }
            FZZAClrScheme_Item * folHlink = clrScheme->setFolHlink();
            if ( folHlink != NULL ) {
                srgbClr = folHlink->setSrgbClr();
                if ( srgbClr != NULL ) {
                    srgbClr->setVal("954F72");
                }
            }
            
        }//if ( clrScheme != NULL )
        FZZAfontScheme * fontScheme = m_CTthemeElements->setfontScheme();
        if ( fontScheme != NULL ) {
            fontScheme->setName("Office");
            FZZAfont_ea_cs * font_ea_cs = NULL;
            FZZAfontScheme_Item * tempFontSchemeitem = fontScheme->setMajorFont();
            if ( tempFontSchemeitem != NULL ) {
                font_ea_cs = tempFontSchemeitem->setLatin();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setTypeface("等线 Light");
                    font_ea_cs->setPanose("020F0302020204030204");
                }
                font_ea_cs = tempFontSchemeitem->setEa();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setTypeface("");
                }
                font_ea_cs = tempFontSchemeitem->setCs();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setTypeface("");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Jpan");
                    font_ea_cs->setTypeface("游ゴシック Light");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Hang");
                    font_ea_cs->setTypeface("맑은 고딕");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Hans");
                    font_ea_cs->setTypeface("等线 Light");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Hant");
                    font_ea_cs->setTypeface("新細明體");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Arab");
                    font_ea_cs->setTypeface("Times New Roman");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Hebr");
                    font_ea_cs->setTypeface("Times New Roman");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Thai");
                    font_ea_cs->setTypeface("Angsana New");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Ethi");
                    font_ea_cs->setTypeface("Nyala");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Beng");
                    font_ea_cs->setTypeface("Vrinda");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Gujr");
                    font_ea_cs->setTypeface("Shruti");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Khmr");
                    font_ea_cs->setTypeface("MoolBoran");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Knda");
                    font_ea_cs->setTypeface("Tunga");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Guru");
                    font_ea_cs->setTypeface("Raavi");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Cans");
                    font_ea_cs->setTypeface("Euphemia");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Cher");
                    font_ea_cs->setTypeface("Plantagenet Cherokee");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Yiii");
                    font_ea_cs->setTypeface("Microsoft Yi Baiti");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Tibt");
                    font_ea_cs->setTypeface("Microsoft Himalaya");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Thaa");
                    font_ea_cs->setTypeface("MV Boli");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Deva");
                    font_ea_cs->setTypeface("Mangal");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Telu");
                    font_ea_cs->setTypeface("Gautami");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Taml");
                    font_ea_cs->setTypeface("Latha");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Syrc");
                    font_ea_cs->setTypeface("Estrangelo Edessa");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Orya");
                    font_ea_cs->setTypeface("Kalinga");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Mlym");
                    font_ea_cs->setTypeface("Kartika");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Laoo");
                    font_ea_cs->setTypeface("DokChampa");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Sinh");
                    font_ea_cs->setTypeface("Iskoola Pota");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Mong");
                    font_ea_cs->setTypeface("Mongolian Baiti");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Viet");
                    font_ea_cs->setTypeface("Times New Roman");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Uigh");
                    font_ea_cs->setTypeface("Microsoft Uighur");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Geor");
                    font_ea_cs->setTypeface("Sylfaen");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Armn");
                    font_ea_cs->setTypeface("Arial");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Bugi");
                    font_ea_cs->setTypeface("Leelawadee UI");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Bopo");
                    font_ea_cs->setTypeface("Microsoft JhengHei");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Java");
                    font_ea_cs->setTypeface("Javanese Text");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Lisu");
                    font_ea_cs->setTypeface("Segoe UI");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Mymr");
                    font_ea_cs->setTypeface("Myanmar Text");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Nkoo");
                    font_ea_cs->setTypeface("Ebrima");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Olck");
                    font_ea_cs->setTypeface("Nirmala UI");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Osma");
                    font_ea_cs->setTypeface("Ebrima");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Phag");
                    font_ea_cs->setTypeface("Phagspa");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Syrn");
                    font_ea_cs->setTypeface("Estrangelo Edessa");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Syrj");
                    font_ea_cs->setTypeface("Estrangelo Edessa");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Syre");
                    font_ea_cs->setTypeface("Estrangelo Edessa");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Sora");
                    font_ea_cs->setTypeface("Nirmala UI");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Tale");
                    font_ea_cs->setTypeface("Microsoft Tai Le");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Talu");
                    font_ea_cs->setTypeface("Microsoft New Tai Lue");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setScript("Tfng");
                    font_ea_cs->setTypeface("Ebrima");
                }
            }
            
            tempFontSchemeitem = fontScheme->setMinorFont();
            if ( tempFontSchemeitem != NULL ) {
                font_ea_cs = tempFontSchemeitem->setLatin();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setTypeface("等线");
                    font_ea_cs->setPanose("020F0502020204030204");
                }
                font_ea_cs = tempFontSchemeitem->setEa();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setTypeface("");
                }
                font_ea_cs = tempFontSchemeitem->setCs();
                if ( font_ea_cs != NULL ) {
                    font_ea_cs->setTypeface("");
                }
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Jpan");font_ea_cs->setTypeface("游明朝");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Hang");font_ea_cs->setTypeface("맑은 고딕");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Hans");font_ea_cs->setTypeface("等线");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Hant");font_ea_cs->setTypeface("新細明體");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Arab");font_ea_cs->setTypeface("Arial");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Hebr");font_ea_cs->setTypeface("Arial");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Thai");font_ea_cs->setTypeface("Cordia New");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Ethi");font_ea_cs->setTypeface("Nyala");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Beng");font_ea_cs->setTypeface("Vrinda");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Gujr");font_ea_cs->setTypeface("Shruti");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Khmr");font_ea_cs->setTypeface("DaunPenh");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Knda");font_ea_cs->setTypeface("Tunga");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Guru");font_ea_cs->setTypeface("Raavi");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Cans");font_ea_cs->setTypeface("Euphemia");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Cher");font_ea_cs->setTypeface("Plantagenet Cherokee");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Yiii");font_ea_cs->setTypeface("Microsoft Yi Baiti");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Tibt");font_ea_cs->setTypeface("Microsoft Himalaya");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Thaa");font_ea_cs->setTypeface("MV Boli");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Deva");font_ea_cs->setTypeface("Mangal");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Telu");font_ea_cs->setTypeface("Gautami");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Taml");font_ea_cs->setTypeface("Latha");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Syrc");font_ea_cs->setTypeface("Estrangelo Edessa");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Orya");font_ea_cs->setTypeface("Kalinga");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Mlym");font_ea_cs->setTypeface("Kartika");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Laoo");font_ea_cs->setTypeface("DokChampa");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Sinh");font_ea_cs->setTypeface("Iskoola Pota");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Mong");font_ea_cs->setTypeface("Mongolian Baiti");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Viet");font_ea_cs->setTypeface("Arial");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Uigh");font_ea_cs->setTypeface("Microsoft Uighur");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Geor");font_ea_cs->setTypeface("Sylfaen");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Armn");font_ea_cs->setTypeface("Arial");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Bugi");font_ea_cs->setTypeface("Leelawadee UI");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Bopo");font_ea_cs->setTypeface("Microsoft JhengHei");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Java");font_ea_cs->setTypeface("Javanese Text");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Lisu");font_ea_cs->setTypeface("Segoe UI");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Mymr");font_ea_cs->setTypeface("Myanmar Text");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Nkoo");font_ea_cs->setTypeface("Ebrima");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Olck");font_ea_cs->setTypeface("Nirmala UI");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Osma");font_ea_cs->setTypeface("Ebrima");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Phag");font_ea_cs->setTypeface("Phagspa");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Syrn");font_ea_cs->setTypeface("Estrangelo Edessa");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Syrj");font_ea_cs->setTypeface("Estrangelo Edessa");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Syre");font_ea_cs->setTypeface("Estrangelo Edessa");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Sora");font_ea_cs->setTypeface("Nirmala UI");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Tale");font_ea_cs->setTypeface("Microsoft Tai Le");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Talu");font_ea_cs->setTypeface("Microsoft New Tai Lue");}
                font_ea_cs = tempFontSchemeitem->addFont();
                if ( font_ea_cs != NULL ) {font_ea_cs->setScript("Tfng");font_ea_cs->setTypeface("Ebrima");}
                
            }
        }//if ( fontScheme != NULL )
        FZZAfmtScheme * fmtScheme = m_CTthemeElements->setfmtScheme();
        if ( fmtScheme != NULL ) {
            fmtScheme->setName("Office");
            FZZAsolidFill * tempSolidFill = NULL;
            FZZAschemeClr * tempSchemeClr = NULL;
            FZZAgradFill * tempGradFill = NULL;
            FZZAgs * tempCTgs = NULL;
            FZZAgsLst * tempCTgsLst = NULL;
            FZZAlumMod * tempLumMod = NULL;
            FZZAsatMod * tempCTsatMod = NULL;
            FZZAtint * tempCTtint = NULL;
            FZZAlin * tempCTlin = NULL;
            FZZAshade * tempCTshade = NULL;
            FZZALn * tempCTln = NULL;
            FZZAprstDash * tempCTprstDash = NULL;
            FZZAmiter * tempCTmiter = NULL;
            //FZZAeffectStyle * tempCTeffectStyle = NULL;
            FZZAfmtScheme_Item * tempfmtSchemeitem = fmtScheme->setFillStyleLst();
            if ( tempfmtSchemeitem != NULL ) {
                tempSolidFill = tempfmtSchemeitem->addsolidFill();
                if ( tempSolidFill != NULL ) {
                    tempSchemeClr = tempSolidFill->setSchemeClr();
                    if ( tempSchemeClr != NULL ) {
                        tempSchemeClr->setVal("phClr");
                    }
                }
                tempGradFill = tempfmtSchemeitem->addgradFill();
                if ( tempGradFill != NULL ) {
                    tempGradFill->setRotWithShape("1");
                    tempCTgsLst = tempGradFill->setgsLst();
                    if ( tempCTgsLst != NULL ) {
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("0");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("110000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("105000");
                                tempCTtint = tempSchemeClr->setTint();
                                if ( tempCTtint != NULL ) tempCTtint->setVal("67000");
                            }
                        }
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("50000");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("105000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("103000");
                                tempCTtint = tempSchemeClr->setTint();
                                if ( tempCTtint != NULL ) tempCTtint->setVal("73000");
                            }
                        }
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("100000");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("105000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("109000");
                                tempCTtint = tempSchemeClr->setTint();
                                if ( tempCTtint != NULL ) tempCTtint->setVal("81000");
                            }
                        }
                    } //if ( tempCTgsLst != NULL )
                    
                    tempCTlin = tempGradFill->setLin();
                    if ( tempCTlin != NULL ) {
                        tempCTlin->setAng("5400000");
                        tempCTlin->setScaled("0");
                    }
                }
                //-------------
                tempGradFill = tempfmtSchemeitem->addgradFill();
                if ( tempGradFill != NULL ) {
                    tempGradFill->setRotWithShape("1");
                    tempCTgsLst = tempGradFill->setgsLst();
                    if ( tempCTgsLst != NULL ) {
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("0");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("103000");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("102000");
                                tempCTtint = tempSchemeClr->setTint();
                                if ( tempCTtint != NULL ) tempCTtint->setVal("94000");
                            }
                        }
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("50000");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("110000");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("100000");
                                tempCTshade = tempSchemeClr->setShade();
                                if ( tempCTshade != NULL ) tempCTshade->setVal("100000");
                            }
                        }
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("100000");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("99000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("120000");
                                tempCTshade = tempSchemeClr->setShade();
                                if ( tempCTshade != NULL ) tempCTshade->setVal("78000");
                            }
                        }
                    } //if ( tempCTgsLst != NULL )
                    
                    tempCTlin = tempGradFill->setLin();
                    if ( tempCTlin != NULL ) {
                        tempCTlin->setAng("5400000");
                        tempCTlin->setScaled("0");
                    }
                }
            }//if ( tempfmtSchemeitem != NULL )
            tempfmtSchemeitem = fmtScheme->setLnStyleLst();
            if ( tempfmtSchemeitem != NULL ) {
                tempCTln = tempfmtSchemeitem->addLn();
                if ( tempCTln != NULL ) {
                    tempCTln->setW("6350");
                    tempCTln->setCap("flat");
                    tempCTln->setCmpd("sng");
                    tempCTln->setAlgn("ctr");
                    tempSolidFill = tempCTln->setSolidFill();
                    if ( tempSolidFill != NULL ) {
                        tempSchemeClr = tempSolidFill->setSchemeClr();
                        if ( tempSchemeClr != NULL ) {
                            tempSchemeClr->setVal("phClr");
                        }
                    }
                    tempCTprstDash = tempCTln->setPrstDash();
                    if ( tempCTprstDash != NULL ) tempCTprstDash->setVal("solid");
                    tempCTmiter = tempCTln->setMiter();
                    if ( tempCTmiter != NULL ) tempCTmiter->setLim("800000");
                }
                tempCTln = tempfmtSchemeitem->addLn();
                if ( tempCTln != NULL ) {
                    tempCTln->setW("12700");
                    tempCTln->setCap("flat");
                    tempCTln->setCmpd("sng");
                    tempCTln->setAlgn("ctr");
                    tempSolidFill = tempCTln->setSolidFill();
                    if ( tempSolidFill != NULL ) {
                        tempSchemeClr = tempSolidFill->setSchemeClr();
                        if ( tempSchemeClr != NULL ) {
                            tempSchemeClr->setVal("phClr");
                        }
                    }
                    tempCTprstDash = tempCTln->setPrstDash();
                    if ( tempCTprstDash != NULL ) tempCTprstDash->setVal("solid");
                    tempCTmiter = tempCTln->setMiter();
                    if ( tempCTmiter != NULL ) tempCTmiter->setLim("800000");
                }
                tempCTln = tempfmtSchemeitem->addLn();
                if ( tempCTln != NULL ) {
                    tempCTln->setW("19050");
                    tempCTln->setCap("flat");
                    tempCTln->setCmpd("sng");
                    tempCTln->setAlgn("ctr");
                    tempSolidFill = tempCTln->setSolidFill();
                    if ( tempSolidFill != NULL ) {
                        tempSchemeClr = tempSolidFill->setSchemeClr();
                        if ( tempSchemeClr != NULL ) {
                            tempSchemeClr->setVal("phClr");
                        }
                    }
                    tempCTprstDash = tempCTln->setPrstDash();
                    if ( tempCTprstDash != NULL ) tempCTprstDash->setVal("solid");
                    tempCTmiter = tempCTln->setMiter();
                    if ( tempCTmiter != NULL ) tempCTmiter->setLim("800000");
                }
            }//if ( tempfmtSchemeitem != NULL )
            tempfmtSchemeitem = fmtScheme->setEffectStyleLst();
            if ( tempfmtSchemeitem != NULL ) {
                FZZAeffectLst * tempCTeffectLst = NULL;
                FZZAouterShdw* tempCTouterShdw = NULL;
                FZZASrgbClr * tempCTSrgbClr = NULL;
                FZZAalpha * tempCTalpha = NULL;
                FZZAeffectStyle * tempCTeffectStyle = NULL;
                tempCTeffectStyle = tempfmtSchemeitem->addEffectStyle();
                if ( tempCTeffectStyle != NULL ) {
                    tempCTeffectLst = tempCTeffectStyle->setEffectLst();
                }
                tempCTeffectStyle = tempfmtSchemeitem->addEffectStyle();
                if ( tempCTeffectStyle != NULL ) {
                    tempCTeffectLst = tempCTeffectStyle->setEffectLst();
                }
                tempCTeffectStyle = tempfmtSchemeitem->addEffectStyle();
                if ( tempCTeffectStyle != NULL ) {
                    tempCTeffectLst = tempCTeffectStyle->setEffectLst();
                    if ( tempCTeffectLst != NULL ) {
                        tempCTouterShdw = tempCTeffectLst->addOuterShdw();
                        if ( tempCTouterShdw != NULL ) {
                            tempCTouterShdw->setBlurRad("57150");
                            tempCTouterShdw->setDist("19050");
                            tempCTouterShdw->setDir("5400000");
                            tempCTouterShdw->setAlgn("ctr");
                            tempCTouterShdw->setRotWithShape("0");
                            tempCTSrgbClr = tempCTouterShdw->setSrgbClr();
                            if ( tempCTSrgbClr != NULL ) {
                                tempCTSrgbClr->setVal("000000");
                                tempCTalpha = tempCTSrgbClr->setAlpha();
                                if ( tempCTalpha != NULL ) {
                                    tempCTalpha->setVal("63000");
                                }
                            }
                        }
                    }
                }
            }//if ( tempfmtSchemeitem != NULL )
            tempfmtSchemeitem = fmtScheme->setBgFillStyleLst();
            if ( tempfmtSchemeitem != NULL ) {
                tempSolidFill = tempfmtSchemeitem->addsolidFill();
                if ( tempSolidFill != NULL ) {
                    tempSchemeClr = tempSolidFill->setSchemeClr();
                    if ( tempSchemeClr != NULL ) {
                        tempSchemeClr->setVal("phClr");
                    }
                }
                tempSolidFill = tempfmtSchemeitem->addsolidFill();
                if ( tempSolidFill != NULL ) {
                    tempSchemeClr = tempSolidFill->setSchemeClr();
                    if ( tempSchemeClr != NULL ) {
                        tempSchemeClr->setVal("phClr");
                        tempCTtint = tempSchemeClr->setTint();
                        if ( tempCTtint != NULL ) tempCTtint->setVal("95000");
                        tempCTsatMod = tempSchemeClr->setSatMod();
                        if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("170000");
                        
                    }
                }
                tempGradFill = tempfmtSchemeitem->addgradFill();
                if ( tempGradFill != NULL ) {
                    tempGradFill->setRotWithShape("1");
                    tempCTgsLst = tempGradFill->setgsLst();
                    if ( tempCTgsLst != NULL ) {
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("0");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempCTtint = tempSchemeClr->setTint();
                                if ( tempCTtint != NULL ) tempCTtint->setVal("93000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("150000");
                                tempCTshade = tempSchemeClr->setShade();
                                if ( tempCTshade != NULL ) tempCTshade->setVal("98000");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("102000");
                                
                                
                            }
                        }
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("50000");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempCTtint = tempSchemeClr->setTint();
                                if ( tempCTtint != NULL ) tempCTtint->setVal("98000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("130000");
                                tempCTshade = tempSchemeClr->setShade();
                                if ( tempCTshade != NULL ) tempCTshade->setVal("90000");
                                tempLumMod = tempSchemeClr->setLumMod();
                                if ( tempLumMod != NULL ) tempLumMod->setVal("103000");
                            }
                        }
                        tempCTgs = tempCTgsLst->addgs();
                        if ( tempCTgs != NULL ) {
                            tempCTgs->setPos("100000");
                            tempSchemeClr = tempCTgs->setSchemeClr();
                            if ( tempSchemeClr != NULL ) {
                                tempSchemeClr->setVal("phClr");
                                tempCTshade = tempSchemeClr->setShade();
                                if ( tempCTshade != NULL ) tempCTshade->setVal("63000");
                                tempCTsatMod = tempSchemeClr->setSatMod();
                                if ( tempCTsatMod != NULL ) tempCTsatMod->setVal("120000");
                                
                            }
                        }
                    } //if ( tempCTgsLst != NULL )
                    
                    tempCTlin = tempGradFill->setLin();
                    if ( tempCTlin != NULL ) {
                        tempCTlin->setAng("5400000");
                        tempCTlin->setScaled("0");
                    }
                }
            }//if ( tempfmtSchemeitem != NULL )
        }//if ( fmtScheme != NULL )
        
    }//if ( m_CTthemeElements != NULL )
    
    setObjectDefaults();
    setExtraClrSchemeLst();
    setExtLst();
    if ( m_CTExtLst != NULL ) {
        FZZAExt* ctExt = m_CTExtLst->addExt();
        if ( ctExt != NULL ) {
            ctExt->setUri("{05A4C25C-085E-4340-85A3-A5531E510DB2}");
            FZZThemeFamily * ctThemeFamily = ctExt->setCTThemeFamily();
        }
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeXML::FZZThemeXML(XMLDocument * doc) : FZZOfficeObject(doc),m_CTObjectDefaults(NULL),m_CTExtraClrSchemeLst(NULL),m_CTExtLst(NULL),m_CTthemeElements(NULL)
{
    FZZConst::addClassCount("FZZThemeXML");
    m_FileName = THEMEXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeXML::FZZThemeXML(const FZZThemeXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZThemeXML");
    if ( this == &obj ) {
        return;
    }

    m_CTObjectDefaults = obj.m_CTObjectDefaults != NULL ? new FZZAObjectDefaults(*obj.m_CTObjectDefaults) : NULL;
    m_CTExtraClrSchemeLst = obj.m_CTExtraClrSchemeLst != NULL ? new FZZAExtraClrSchemeLst(*obj.m_CTExtraClrSchemeLst) : NULL;
    m_CTExtLst = obj.m_CTExtLst != NULL ? new FZZAExtLst(*obj.m_CTExtLst) : NULL;
    m_CTthemeElements = obj.m_CTthemeElements != NULL ? new FZZAthemeElements(*obj.m_CTthemeElements) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeXML::~FZZThemeXML()
{
    //DLOG("~FZZThemeXML()");
    FZZConst::delClassCount("FZZThemeXML");
    
    if ( m_CTObjectDefaults != NULL ) {
        delete m_CTObjectDefaults;
        m_CTObjectDefaults = NULL;
    }
    
    if ( m_CTExtraClrSchemeLst != NULL ) {
        delete m_CTExtraClrSchemeLst;
        m_CTExtraClrSchemeLst = NULL;
    }
    
    if ( m_CTExtLst != NULL ) {
        delete m_CTExtLst;
        m_CTExtLst = NULL;
    }
    
    if ( m_CTthemeElements != NULL ) {
        delete m_CTthemeElements;
        m_CTthemeElements = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults * FZZThemeXML::setObjectDefaults()
{

    return m_CTObjectDefaults = setElementObject(m_CTObjectDefaults,FZZAOBJECTDEFAULTS_Find_Key,FZZAOBJECTDEFAULTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults * FZZThemeXML::getObjectDefaults()
{
    return m_CTObjectDefaults = getElementObject(m_CTObjectDefaults,FZZAOBJECTDEFAULTS_Find_Key,FZZAOBJECTDEFAULTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst * FZZThemeXML::setExtraClrSchemeLst()
{

    return m_CTExtraClrSchemeLst = setElementObject(m_CTExtraClrSchemeLst,FZZAEXTRACLRSCHEMELST_Find_Key,FZZAEXTRACLRSCHEMELST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst * FZZThemeXML::getExtraClrSchemeLst()
{
    return m_CTExtraClrSchemeLst = getElementObject(m_CTExtraClrSchemeLst,FZZAEXTRACLRSCHEMELST_Find_Key,FZZAEXTRACLRSCHEMELST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst * FZZThemeXML::setExtLst()
{

    return m_CTExtLst = setElementObject(m_CTExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst * FZZThemeXML::getExtLst()
{
    return m_CTExtLst = getElementObject(m_CTExtLst,FZZAEXTLST_Find_Key,FZZAEXTLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements * FZZThemeXML::setThemeElements()
{

    return m_CTthemeElements = setElementObject(m_CTthemeElements,FZZATHEMEELEMENTS_Find_Key,FZZATHEMEELEMENTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAthemeElements * FZZThemeXML::getThemeElements()
{
    return m_CTthemeElements = getElementObject(m_CTthemeElements,FZZATHEMEELEMENTS_Find_Key,FZZATHEMEELEMENTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
