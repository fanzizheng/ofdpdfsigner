//
//  Created by zizheng fan on 2023/10/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"
#include "office/FZZOfficeObject.h"
#include "office/docx/container/FZZDocXDir.h"
#include "office/docx/FZZDocXConst.h"
#include "office/docx/FZZFileMagic.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWP**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWP::FZZWP() : FZZXMLElementObject(),m_DocXDir(NULL),m_FZZWPPr(NULL)
{
    //DLOG("FZZWP()");
    FZZConst::addClassCount("FZZWP");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP::FZZWP(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_DocXDir(NULL),m_FZZWPPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWP");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP::FZZWP(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_DocXDir(NULL),m_FZZWPPr(NULL)
{
    FZZConst::addClassCount("FZZWP");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP::FZZWP(const FZZWP& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWP");
    if ( this == &obj ) {
        return;
    }
    
    m_DocXDir = obj.m_DocXDir;
    m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
//    vector<FZZWPPr*>::const_iterator itr;
//    for( itr = obj.m_FZZWPPrs.begin(); itr != obj.m_FZZWPPrs.end(); itr++ ) {
//        FZZWPPr * temp = *itr;
//        if ( temp != NULL ) {
//            m_FZZWPPrs.push_back(new FZZWPPr(*temp));
//        }
//    }
//    
    vector<FZZWR*>::const_iterator itr_r;
    for( itr_r = obj.m_FZZWRs.begin(); itr_r != obj.m_FZZWRs.end(); itr_r++ ) {
        FZZWR * temp = *itr_r;
        if ( temp != NULL ) {
            m_FZZWRs.push_back(new FZZWR(*temp));
        }
    }
    
    vector<FZZWHyperlink*>::const_iterator itr_hl;
    for( itr_hl = obj.m_FZZWHyperlinkList.begin(); itr_hl != obj.m_FZZWHyperlinkList.end(); itr_hl++ ) {
        FZZWHyperlink * temp = *itr_hl;
        if ( temp != NULL ) {
            m_FZZWHyperlinkList.push_back(new FZZWHyperlink(*temp));
        }
    }
    
    vector<FZZWSmartTag*>::const_iterator itr_stl;
    for( itr_stl = obj.m_FZZWSmartTagList.begin(); itr_stl != obj.m_FZZWSmartTagList.end(); itr_stl++ ) {
        FZZWSmartTag * temp = *itr_stl;
        if ( temp != NULL ) {
            m_FZZWSmartTagList.push_back(new FZZWSmartTag(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP::~FZZWP()
{
    //DLOG("~FZZWP()");
    FZZConst::delClassCount("FZZWP");
    if ( m_FZZWPPr != NULL ) {
        delete m_FZZWPPr;
        m_FZZWPPr = NULL;
    }
    
    
//    vector<FZZWPPr*>::const_iterator itr;
//    for( itr = m_FZZWPPrs.begin(); itr != m_FZZWPPrs.end(); itr++ ) {
//        FZZWPPr * temp = *itr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_FZZWPPrs.clear();
//
    vector<FZZWR*>::const_iterator itr_r;
    for( itr_r = m_FZZWRs.begin(); itr_r != m_FZZWRs.end(); itr_r++ ) {
        FZZWR * temp = *itr_r;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWRs.clear();
    
    vector<FZZWHyperlink*>::const_iterator itr_hl;
    for( itr_hl = m_FZZWHyperlinkList.begin(); itr_hl != m_FZZWHyperlinkList.end(); itr_hl++ ) {
        FZZWHyperlink * temp = *itr_hl;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWHyperlinkList.clear();
    
    

    for( itr_r = m_FZZWRList_All.begin(); itr_r != m_FZZWRList_All.end(); itr_r++ ) {
        FZZWR * temp = *itr_r;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWRList_All.clear();
    
    vector<FZZWSmartTag*>::const_iterator itr_stl;
    for( itr_stl = m_FZZWSmartTagList.begin(); itr_stl != m_FZZWSmartTagList.end(); itr_stl++ ) {
        FZZWSmartTag * temp = *itr_stl;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWSmartTagList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWP::setParaId(string value)
{
    setAttribute_String("w14:paraId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWP::getParaId()
{
    return getAttribute_String("w14:paraId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWP::setTextId(string value)
{
    setAttribute_String("w14:textId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWP::getTextId()
{
    return getAttribute_String("w14:textId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWP::setRsidR(string value)
{
    setAttribute_String("w:rsidR",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWP::getRsidR()
{
    return getAttribute_String("w:rsidR");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWP::setRsidRDefault(string value)
{
    setAttribute_String("w:rsidRDefault",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWP::getRsidRDefault()
{
    return getAttribute_String("w:rsidRDefault");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWP::setRsidRPr(string value)
{
    setAttribute_String("w:rsidRPr",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWP::getRsidRPr()
{
    return getAttribute_String("w:rsidRPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWP::setPPr()
{
    return m_FZZWPPr = setElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWP::getPPr()
{
    return m_FZZWPPr = getElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//FZZWPPr * FZZWP::addPPr()
//{
//    return addElementObject(&m_FZZWPPrs,FZZWPPR_Find_Key,FZZWPPR_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//vector<FZZWPPr*> * FZZWP::getPPrs()
//{
//    getElementObjectList(&m_FZZWPPrs,FZZWPPR_Find_Key,FZZWPPR_Name);
//    return &m_FZZWPPrs;
//}
////-----------------------------------------------------------------------------------------------------------------
FZZWR * FZZWP::addR()
{
    return addElementObject(&m_FZZWRs,FZZWR_Find_Key,FZZWR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWR*> * FZZWP::getRList()
{
    getElementObjectList(&m_FZZWRs,FZZWR_Find_Key,FZZWR_Name);
    return &m_FZZWRs;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHyperlink * FZZWP::addHyperlinkList()
{
    return addElementObject(&m_FZZWHyperlinkList,FZZWHYPERLINK_Find_Key,FZZWHYPERLINK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWHyperlink*> * FZZWP::getHyperlinkList()
{
    getElementObjectList(&m_FZZWHyperlinkList,FZZWHYPERLINK_Find_Key,FZZWHYPERLINK_Name);
    return &m_FZZWHyperlinkList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTag * FZZWP::addSmartTag()
{
    return addElementObject(&m_FZZWSmartTagList,FZZWSMARTTAG_Find_Key,FZZWSMARTTAG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWSmartTag*> * FZZWP::getSmartTagList()
{
    getElementObjectList(&m_FZZWSmartTagList,FZZWSMARTTAG_Find_Key,FZZWSMARTTAG_Name);
    return &m_FZZWSmartTagList;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWR*> * FZZWP::getRList_All()
{
    if ( m_FZZWRList_All.size() == 0 ) {

        XMLElement* ele = m_ofd_Node->FirstChildElement();
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, "w:r") == 0 ) {
                
                FZZWR* temp = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZWR*)NULL);
                if ( temp != NULL ) {
                    m_FZZWRList_All.push_back(temp);
                }
            } else if (strcmp(elename, "w:hyperlink") == 0 ) {
                
                XMLElement* elesub = ele->FirstChildElement("w:r");
                if ( elesub != NULL ) {
                    FZZWR* temp = FZZXMLElementObject::getInstance(m_Parent,m_doc, elesub,(FZZWR*)NULL);
                    if ( temp != NULL ) {
                        m_FZZWRList_All.push_back(temp);
                    }
                }
            } else if ( strcmp(elename, "w:smartTag") == 0 ) {
                
                XMLElement* elesub = ele->FirstChildElement("w:r");
                while (elesub != NULL) {
                    const char* elename = elesub->Name();
                    if (strcmp(elename, "w:r") == 0) {
                        FZZWR* temp = FZZXMLElementObject::getInstance(m_Parent,m_doc, elesub,(FZZWR*)NULL);
                        if ( temp != NULL ) {
                            m_FZZWRList_All.push_back(temp);
                        }
                    }

                    elesub = elesub->NextSiblingElement();
                }
            }
           
            ele = ele->NextSiblingElement();
        }
    }
    
    return &m_FZZWRList_All;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZWP::addText(string text,string fontname,int fontsize,bool isBlob,int text_color_R ,int text_color_G ,int text_color_B ,int alpha)
{
    if ( m_DocXDir == NULL || text.empty() ) {
        return false;
    }
    FZZWR * tempR = addR();
    if ( tempR == NULL ) {
        return false;
    }
    
    FZZWRPr * tempRpr = tempR->setRPr();
    if ( tempRpr == NULL ) {
        return false;
    }
    if ( !fontname.empty()  ) {
        FZZWRFonts * rFonts = tempRpr->setRFonts();
        if ( rFonts != NULL ) {
            rFonts->setHint(fontname);
        }
    }
    if ( isBlob ) {
        tempRpr->setB();
        tempRpr->setBCs();
    }
    if ( fontsize > 0 ) {
        int tempFontSize = fontsize * 2;
        FZZWSz * tempSz = tempRpr->setSz();
        if ( tempSz != NULL ) {
            tempSz->setVal(FZZConst::fmt(tempFontSize));
        }
        FZZWSzCS * tempSzCS = tempRpr->setSzCS();
        if ( tempSzCS != NULL ) {
            tempSzCS->setVal(FZZConst::fmt(tempFontSize));
        }
    }
    string textcolor = ColorToString(text_color_R, text_color_G, text_color_B);
    if ( !textcolor.empty() ) {
        FZZWColor * tempColor = tempRpr->setColor();
        if ( tempColor != NULL ) {
            tempColor->setVal(textcolor);
        }
    }
    
    if ( alpha < 255 ) {
        FZZW14TextFill * tempTextFill = tempRpr->setTextFill();
        if ( tempTextFill != NULL ) {
            FZZW14SolidFill * tempSolidFill = tempTextFill->setSolidFill();
            if ( tempSolidFill != NULL ) {
                FZZW14SrgbClr * tempSrgbClr = tempSolidFill->setSrgbClr();
                if ( tempSrgbClr != NULL ) {
                    tempSrgbClr->setVal(textcolor);
                    FZZW14Alpha * tempAlpha = tempSrgbClr->setAlpha();
                    if ( tempAlpha != NULL ) {
                        tempAlpha->setVal(Alpha_OFDToWord(alpha));
                    }
                }
            }
        }
    }
    
    FZZWT * tempT = tempR->setT();
    if ( tempT == NULL ) {
        return false;
    }
    
    string tempText = FZZConst::Trim(text);
    if ( tempText.empty() ) {
        tempT->setSpace("preserve");
    }
    tempT->setValue(text);
    
    
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZWP::addImage(string imageFileName,FZZBytes * imageData,bool isPixel,float width,float height)
{
    string ContentypeName = FZZFileMagic::getContentTypeFromFileExtension(imageFileName);
    string ExtensionName = FZZFileMagic::getFileExtension(imageFileName);
    if ( ContentypeName.empty() ) {
        return false;
    }
    
    if ( m_DocXDir == NULL || imageData == NULL || imageData->getLen() <= 0 ) {
        return false;
    }
    
    FZZWordDir * tempWordDir = m_DocXDir->getWordDir();
    if ( tempWordDir == NULL ) {
        return false;
    }
    FZZMediaDir * tempMediaDir =  tempWordDir->getMediaDir();
    if ( tempMediaDir == NULL ) {
        return false;
    }
    
    int ResFileNameID = 0;
    string ResfileName = tempMediaDir->getResFileName("image", ExtensionName,ResFileNameID);
    string strResFileNameId = FZZConst::fmt(ResFileNameID);
    tempMediaDir->FlushResFile(ResfileName, imageData);
    //------------------------------
    FZZRelsDir * tempRelsDir = tempWordDir->getRelsDir();
    if ( tempRelsDir == NULL ) {
        return false;
    }
    
    FZZDocumentXMLRels* tempDocumentXMLRels = tempRelsDir->getDocumentXMLRels();
    if ( tempRelsDir == NULL ) {
        return false;
    }
    FZZRelationship * tempRelationship  = tempDocumentXMLRels->addRelationship();
    if ( tempRelationship == NULL ) {
        return false;
    }
    
    string relsRid = tempDocumentXMLRels->getNexId();
    tempRelationship->setId(relsRid);
    if ( ContentypeName == CONTENTTYPES_IMAGE_JPEG || ContentypeName == CONTENTTYPES_IMAGE_PNG  || ContentypeName == CONTENTTYPES_IMAGE_GIF || ContentypeName == CONTENTTYPES_IMAGE_TIFF || ContentypeName == CONTENTTYPES_IMAGE_PICT ) {
        tempRelationship->setType(DOCUMENTXMLRELS_TYPE_IMAGE);
    }
    tempRelationship->setTarget("media/"+ResfileName);
    //------------------------------
    FZZContentTypesXML* tempContentTypesXML = m_DocXDir->getContentTypesXML();
    if ( tempContentTypesXML == NULL ) {
        return false;
    }
    
    if ( !tempContentTypesXML->isHave_Default_ContentType(ContentypeName) ) {
        CTContentTypes_Default * tempContentTypes_Default = tempContentTypesXML->addDefault();
        tempContentTypes_Default->setExtension(ExtensionName);
        tempContentTypes_Default->setContentType(ContentypeName);
    }
    
    //--------------------------------------
    
    FZZWR * tempR = addR();
    if ( tempR == NULL ) {
        return false;
    }
    
    FZZWRPr * tempRpr = tempR->setRPr();
    if ( tempRpr == NULL ) {
        return false;
    }
    tempRpr->setNoProof();
    
    FZZWDrawing * tempDrawing = tempR->setDrawing();
    if ( tempDrawing == NULL ) {
        return false;
    }
    FZZWPInline * tempInline = tempDrawing->setInline();
    if ( tempDrawing == NULL ) {
        return false;
    }
    tempInline->setDistT("0");
    tempInline->setDistB("0");
    tempInline->setDistL("0");
    tempInline->setDistR("0");
    //tempInline->setAnchorId("0338C5C5");
    //tempInline->setEditId("28C52659");
    
    FZZWPExtent * tempExtent = tempInline->setExtent();
    if ( tempExtent == NULL ) {
        return false;
    }
    tempExtent->setCx(FZZConst::fmt(isPixel ? PixelToETU(width) : MillimetersToETU(width)));
    tempExtent->setCy(FZZConst::fmt(isPixel ? PixelToETU(height) : MillimetersToETU(height)));
    
    FZZWPEffectExtent * tempEffectExtent = tempInline->setEffectExtent();
    if ( tempEffectExtent == NULL ) {
        return false;
    }
    tempEffectExtent->setL("0");
    tempEffectExtent->setT("0");
    tempEffectExtent->setR("0");
    tempEffectExtent->setB("0");
    
    FZZWPDocPr * tempDocPr = tempInline->setDocPr();
    if ( tempDocPr == NULL ) {
        return false;
    }
    tempDocPr->setId(strResFileNameId);
    tempDocPr->setName("Image "+strResFileNameId);
    
    FZZWPCNvGraphicFramePr * tempCNvGraphicFramePr = tempInline->setCNvGraphicFramePr();
    if ( tempCNvGraphicFramePr == NULL ) {
        return false;
    }
    FZZAGraphicFrameLocks * tempGraphicFrameLocks = tempCNvGraphicFramePr->setGraphicFrameLocks();
    if ( tempGraphicFrameLocks == NULL ) {
        return false;
    }
    tempGraphicFrameLocks->setXmlnsA(OPENXMLFORMATS_DRAWINGML_2006_MAIN_VALUE);
    tempGraphicFrameLocks->setNoChangeAspect("1");
    
    FZZAGraphic * tempGraphic = tempInline->setGraphic();
    if ( tempGraphic == NULL ) {
        return false;
    }
    tempGraphic->setXmlnsA(OPENXMLFORMATS_DRAWINGML_2006_MAIN_VALUE);
    
    FZZAGraphicData * tempGraphicData = tempGraphic->setGraphicData();
    if ( tempGraphicData == NULL ) {
        return false;
    }
    tempGraphicData->setUri(OPENXMLFORMATS_DRAWINGML_2006_PICTURE_VALUE);
    
    FZZPICPic * tempPic = tempGraphicData->setPic();
    if ( tempPic == NULL ) {
        return false;
    }
    tempPic->setXmlnsPic(OPENXMLFORMATS_DRAWINGML_2006_PICTURE_VALUE);
    
    FZZPICNvPicPr * tempNvPicPr = tempPic->setNvPicPr();
    if ( tempNvPicPr == NULL ) {
        return false;
    }
    FZZPICCNvPr * tempCNvPr = tempNvPicPr->setCNvPr();
    if ( tempCNvPr == NULL ) {
        return false;
    }
    tempCNvPr->setId(strResFileNameId);
    tempCNvPr->setName("Image "+strResFileNameId);
    tempNvPicPr->setCNvPicPr();
    
    FZZPICBlipFill * tempBlipFill = tempPic->setBlipFill();
    if ( tempBlipFill == NULL ) {
        return false;
    }
    FZZABlip * tempBlip = tempBlipFill->setBlip();
    if ( tempBlip == NULL ) {
        return false;
    }
    tempBlip->setEmbed(relsRid);
    FZZAExtLst * tempExtLst = tempBlip->setExtLst();
    if ( tempExtLst == NULL ) {
        return false;
    }
    FZZAExt* tempExt = tempExtLst->addExt();
    if ( tempExt == NULL ) {
        return false;
    }
    tempExt->setUri("{28A0092B-C50C-407E-A947-70E740481C1C}");
    FZZA14UseLocalDpi * tmpUseLocalDpi = tempExt->setUseLocalDpi();
    if ( tmpUseLocalDpi == NULL ) {
        return false;
    }
    tmpUseLocalDpi->setXmlnsA14(OPENXMLFORMATS_OFFICE_DRAWING_2010_MAIN_VALUE);
    tmpUseLocalDpi->setVal("0");
    
    FZZAStretch * tempStretch = tempBlipFill->setStretch();
    if ( tempStretch == NULL ) {
        return false;
    }
    tempStretch->setFillRect();
    
    FZZPICSpPr * tempSpPr = tempPic->setSpPr();
    if ( tempSpPr == NULL ) {
        return false;
    }
    FZZAXfrm * tempXfrm = tempSpPr->setXfrm();
    if ( tempXfrm == NULL ) {
        return false;
    }
    FZZAOff * tempOff = tempXfrm->setOff();
    if ( tempOff == NULL ) {
        return false;
    }
    tempOff->setX("0");
    tempOff->setY("0");
    tempExt = tempXfrm->setExt();
    if ( tempExt == NULL ) {
        return false;
    }

    tempExt->setCx(FZZConst::fmt(isPixel ? PixelToETU(width) : MillimetersToETU(width)));
    tempExt->setCy(FZZConst::fmt(isPixel ? PixelToETU(height) : MillimetersToETU(height)));
    
    FZZAPrstGeom * tempPrstGeom = tempSpPr->setPrstGeom();
    if ( tempPrstGeom == NULL ) {
        return false;
    }
    tempPrstGeom->setPrst("rect");
    tempPrstGeom->setAvLst();
    
    
    //------------------------------
    
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWP::setDocXDir(FZZDocXDir * docXDir)
{
    m_DocXDir = docXDir;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZWP::addLine(int color_R,int color_G,int color_B,int alpha)
{
    if ( m_DocXDir == NULL  ) {
        return false;
    }
    FZZWordDir * workDir = m_DocXDir->getWordDir();
    if ( workDir == NULL ) {
        return false;
    }
    FZZDocumentXML * docXml = workDir->getDocumentXML();
    if ( docXml == NULL ) {
        return false;
    }
    FZZWR * tempR = addR();
    if ( tempR == NULL ) {
        return false;
    }
    FZZWRPr * tempRpr = tempR->setRPr();
    if ( tempRpr == NULL ) {
        return false;
    }
    tempRpr->setNoProof();
    FZZMCAlternateContent * ctmcAlternateContent = tempR->setAlternateContent();
    if ( ctmcAlternateContent == NULL ) {
        return false;
    }
    FZZMCChoice * ctmcChoice = ctmcAlternateContent->setChoice();
    if ( ctmcChoice == NULL ) {
        return false;
    }
    ctmcChoice->setRequires("wps");
    FZZWDrawing * ctwDrawing = ctmcChoice->setDrawing();
    if ( ctwDrawing == NULL ) {
        return false;
    }
    FZZWPAnchor * ctwpAnchor = ctwDrawing->setAnchor();
    if ( ctwpAnchor == NULL ) {
        return false;
    }
    ctwpAnchor->setDistT("0");
    ctwpAnchor->setDistB("0");
    ctwpAnchor->setDistL("0");
    ctwpAnchor->setDistR("0");
    ctwpAnchor->setSimplePos("0");
    ctwpAnchor->setRelativeHeight("251659264");
    ctwpAnchor->setBehindDoc("0");
    ctwpAnchor->setLocked("0");
    ctwpAnchor->setLayoutInCell("1");
    ctwpAnchor->setAllowOverlap("1");
    
    FZZWPSimplePos * ctwpSimplePos = ctwpAnchor->setSimplePos();
    if ( ctwpSimplePos == NULL ) {
        return false;
    }
    ctwpSimplePos->setX("0");
    ctwpSimplePos->setY("0");
    FZZWPPositionH * ctwpPositionH = ctwpAnchor->setPositionH();
    if ( ctwpPositionH == NULL ) {
        return false;
    }
    ctwpPositionH->setRelativeFrom("column");//margin
    FZZWPPosOffset * ctwpPosOffset = ctwpPositionH->setPosOffset();
    if ( ctwpPosOffset == NULL ) {
        return false;
    }
    ctwpPosOffset->setValue("10296");
    FZZWPPositionV * ctwpPositionV = ctwpAnchor->setPositionV();
    if ( ctwpPositionV == NULL ) {
        return false;
    }
    ctwpPositionV->setRelativeFrom("paragraph"); //page
    ctwpPosOffset = ctwpPositionV->setPosOffset();
    if ( ctwpPosOffset == NULL ) {
        return false;
    }
    ctwpPosOffset->setValue("156519");
    
    FZZWPExtent * ctwpExtent = ctwpAnchor->setExtent();
    if ( ctwpExtent == NULL ) {
        return false;
    }
    ctwpExtent->setCx("3599935");
    ctwpExtent->setCy("0");
    
    FZZWPEffectExtent * ctwpEffectExtent = ctwpAnchor->setEffectExtent();
    if ( ctwpEffectExtent == NULL ) {
        return false;
    }
    ctwpEffectExtent->setL("0");
    ctwpEffectExtent->setT("0");
    ctwpEffectExtent->setR("19685");
    ctwpEffectExtent->setB("12700");
    
    ctwpAnchor->setWrapNone();
    FZZWPDocPr * ctwpDocPr = ctwpAnchor->setDocPr();
    if ( ctwpDocPr == NULL ) {
        return false;
    }
    
    string docPrID = docXml->getNextStyleID_ToString();
    string docPrName = "line "+docPrID;
    ctwpDocPr->setId(docPrID);
    ctwpDocPr->setName(docPrName);
    
    ctwpAnchor->setCNvGraphicFramePr();
    
    FZZAGraphic * ctaGraphic = ctwpAnchor->setGraphic();
    if ( ctaGraphic == NULL ) {
        return false;
    }
    ctaGraphic->setXmlnsA(OPENXMLFORMATS_DRAWINGML_2006_MAIN_VALUE);
    FZZAGraphicData * ctaGraphicData = ctaGraphic->setGraphicData();
    if ( ctaGraphicData == NULL ) {
        return false;
    }
    ctaGraphicData->setUri(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_VALUE);
    FZZWPSWsp * ctwpsWsp = ctaGraphicData->setWsp();
    if ( ctwpsWsp == NULL ) {
        return false;
    }
    ctwpsWsp->setCNvCnPr();
    FZZWPSSpPr * ctwpsSpPr = ctwpsWsp->setSpPr();
    if ( ctwpsSpPr == NULL ) {
        return false;
    }
    FZZAXfrm * ctaXfrm = ctwpsSpPr->setXfrm();
    if ( ctaXfrm == NULL ) {
        return false;
    }
    FZZAOff * ctaOff = ctaXfrm->setOff();
    if ( ctaOff == NULL ) {
        return false;
    }
    ctaOff->setX("0");
    ctaOff->setY("0");
    FZZAExt * ctaExt = ctaXfrm->setExt();
    if ( ctaExt == NULL ) {
        return false;
    }
    ctaExt->setCx("3599935");
    ctaExt->setCy("0");
    FZZAPrstGeom *  ctaPrstGeom = ctwpsSpPr->setPrstGeom();
    if ( ctaPrstGeom == NULL ) {
        return false;
    }
    ctaPrstGeom->setPrst("line");
    ctaPrstGeom->setAvLst();
    FZZALn * ctaLn = ctwpsSpPr->setLn();
    if ( ctaLn == NULL ) {
        return false;
    }
    ctaLn->setW("12700");
    ctaLn->setCap("rnd");
    FZZAsolidFill * ctaSolidFill = ctaLn->setSolidFill();
    if ( ctaSolidFill == NULL ) {
        return false;
    }
    FZZASrgbClr * ctaSrgbClr = ctaSolidFill->setSrgbClr();
    if ( ctaSrgbClr == NULL ) {
        return false;
    }
    ctaSrgbClr->setVal(ColorToString(color_R, color_G, color_B));
    FZZAalpha * ctaAlpha = ctaSrgbClr->setAlpha();
    if ( ctaAlpha == NULL ) {
        return false;
    }
    ctaAlpha->setVal(Alpha_OFDToWord(alpha));
//
//    FZZWPSStyle * ctwpsStyle = ctwpsWsp->setStyle();
//    if ( ctwpsStyle == NULL ) {
//        return false;
//    }
//    FZZALnRef * ctaLnRef = ctwpsStyle->setLnRef();
//    if ( ctaLnRef == NULL ) {
//        return false;
//    }
//    ctaLnRef->setIdx("1");
//    FZZAschemeClr * ctaschemeClr = ctaLnRef->setSchemeClr();
//    if ( ctaschemeClr == NULL ) {
//        return false;
//    }
//    ctaschemeClr->setVal("accent2");
//
//    FZZAFillRef * ctaFillRef = ctwpsStyle->setFillRef();
//    if ( ctaFillRef == NULL ) {
//        return false;
//    }
//    ctaFillRef->setIdx("0");
//    ctaschemeClr = ctaFillRef->setSchemeClr();
//    if ( ctaschemeClr == NULL ) {
//        return false;
//    }
//    ctaschemeClr->setVal("accent2");
//
//    FZZAEffectRef * ctaEffectRef = ctwpsStyle->setEffectRef();
//    if ( ctaEffectRef == NULL ) {
//        return false;
//    }
//    ctaEffectRef->setIdx("0");
//    ctaschemeClr = ctaEffectRef->setSchemeClr();
//    if ( ctaschemeClr == NULL ) {
//        return false;
//    }
//    ctaschemeClr->setVal("accent2");
//
//    FZZAFontRef * ctaFontRef = ctwpsStyle->setFontRef();
//    if ( ctaFontRef == NULL ) {
//        return false;
//    }
//    ctaFontRef->setIdx("minor");
//    ctaschemeClr = ctaFontRef->setSchemeClr();
//    if ( ctaschemeClr == NULL ) {
//        return false;
//    }
//    ctaschemeClr->setVal("tx1");
    
    ctwpsWsp->setBodyPr();
    //-------------------------
    
    FZZMCFallback * ctmcFallback = ctmcAlternateContent->setFallback();
    if ( ctmcFallback == NULL ) {
        return false;
    }
    FZZWPict * ctwPict = ctmcFallback->addPict();
    if ( ctwPict == NULL ) {
        return false;
    }
    FZZVLine * ctvLine = ctwPict->addLine();
    if ( ctvLine == NULL ) {
        return false;
    }
    ctvLine->setId(docPrName);
    ctvLine->setSpId("_x0000_s1026");
    ctvLine->setStyle("position:absolute;left:0;text-align:left;z-index:251659264;visibility:visible;mso-wrap-style:square;mso-wrap-distance-left:9pt;mso-wrap-distance-top:0;mso-wrap-distance-right:9pt;mso-wrap-distance-bottom:0;mso-position-horizontal:absolute;mso-position-horizontal-relative:text;mso-position-vertical:absolute;mso-position-vertical-relative:text");
    ctvLine->setFrom(".8pt,12.3pt");
    ctvLine->setTo("284.25pt,12.3pt");
    ctvLine->setStrokecolor("red");
    ctvLine->setStrokeweight("1pt");
    FZZVStroke * ctvStroke = ctvLine->setStroke();
    if ( ctvStroke == NULL ) {
        return false;
    }
    ctvStroke->setJoinstyle("miter");
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
