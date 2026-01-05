//
//  Created by zizheng fan on 2023/04/15.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZDocumentXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZDocumentXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXML::FZZDocumentXML() : FZZOfficeObject(),m_Body(NULL),m_GlobalID(0),m_BackGround(NULL)
{
    //DLOG("FZZDocumentXML()");
    FZZConst::addClassCount("FZZDocumentXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:document");
    
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGCANVAS_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGCANVAS_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_NAME, OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2014_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2014_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2015_9_8_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2015_9_8_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2015_10_21_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2015_10_21_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_9_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_9_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_10_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_10_CHARTEX_VALUE);
    
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_11_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_11_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_12_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_12_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_13_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_13_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_14_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_14_CHARTEX_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_NAME, OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_INK_NAME, MICROSOFT_OFFICE_DRAWING_2016_INK_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2017_MODEL3D_NAME, MICROSOFT_OFFICE_DRAWING_2017_MODEL3D_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_OFFICE_NAME, MICROSOFT_OFFICE_OFFICE_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_URN_VML_NAME, MICROSOFT_URN_VML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGDRAWING_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGDRAWING_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2006_WORDPROCESSINGDRAWING_NAME, MICROSOFT_OFFICE_WORD_2006_WORDPROCESSINGDRAWING_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_URN_OFFICE_WORD_NAME, MICROSOFT_URN_OFFICE_WORD_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDML_NAME, MICROSOFT_OFFICE_WORD_2010_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2012_WORDML_NAME, MICROSOFT_OFFICE_WORD_2012_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2016_WORDML_CID_NAME, MICROSOFT_OFFICE_WORD_2016_WORDML_CID_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_NAME, MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_NAME, MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGGROUP_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGGROUP_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGINK_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGINK_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2006_WORDML_NAME, MICROSOFT_OFFICE_WORD_2006_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_VALUE);
    ofd_Document->SetAttribute(MC_IGNORABLE_NAME, MC_IGNORABLE_VALUE);
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    m_FileName = DOCUMENTXML_FILENAME;
    
    InitXmlnsList();
    
    defaultInit();
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXML::FZZDocumentXML(XMLDocument * doc) : FZZOfficeObject(doc),m_Body(NULL),m_GlobalID(0),m_BackGround(NULL)
{
    FZZConst::addClassCount("FZZDocumentXML");
    m_FileName = DOCUMENTXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXML::FZZDocumentXML(const FZZDocumentXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZDocumentXML");
    if ( this == &obj ) {
        return;
    }
  
    m_GlobalID = obj.m_GlobalID;
    m_Body = obj.m_Body != NULL ? new FZZWBody(*obj.m_Body) : NULL;
    m_BackGround = obj.m_BackGround != NULL ? new FZZWBackGround(*obj.m_BackGround) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXML::~FZZDocumentXML()
{
    //DLOG("~FZZDocumentXML()");
    FZZConst::delClassCount("FZZDocumentXML");
    
    if ( m_Body != NULL ) {
        delete m_Body;
        m_Body = NULL;
    }
    if ( m_BackGround != NULL ) {
        delete m_BackGround;
        m_BackGround = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody * FZZDocumentXML::setBody()
{
    return m_Body = setElementObject(m_Body,FZZWBody_Find_Key,FZZWBody_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody * FZZDocumentXML::getBody()
{
    return m_Body = getElementObject(m_Body,FZZWBody_Find_Key,FZZWBody_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround * FZZDocumentXML::setBackGround()
{
    return m_BackGround = setElementObject(m_BackGround,FZZWBACKGROUND_Find_Key,FZZWBACKGROUND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround * FZZDocumentXML::getBackGround()
{
    return m_BackGround = getElementObject(m_BackGround,FZZWBACKGROUND_Find_Key,FZZWBACKGROUND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocumentXML::defaultInit()
{
//    FZZWP * tempP = NULL;
    FZZWSectPr* ctwSectPr = NULL;
    FZZWBody * body = setBody();
    if ( body != NULL ) {
//        tempP = body->addP();
//        if ( tempP != NULL ) {
//            tempP->setParaId("02307031");
//            tempP->setTextId("77777777");
//            tempP->setRsidR("00154C1A");
//            tempP->setRsidRDefault("00154C1A");
//        }

        FZZWDocGrid * ctwDocGrid = NULL;
        FZZWCols * ctwCols = NULL;
        FZZWPgMar * ctwPgMar = NULL;
        FZZWPgSz * ctwPgSz = NULL;
        ctwSectPr = body->setSectPr();
        if ( ctwSectPr != NULL ) {
            //ctwSectPr->setRsidR("00154C1A");
            ctwPgSz = ctwSectPr->setPgSz();
            if ( ctwPgSz != NULL ) {
                ctwPgSz->setW("11906");
                ctwPgSz->setH("16838");
            }
            ctwPgMar = ctwSectPr->setPgMar();
            if ( ctwPgMar != NULL ) {
                ctwPgMar->setTop("1440");
                ctwPgMar->setRight("1800");
                ctwPgMar->setBottom("1440");
                ctwPgMar->setLeft("1800");
                ctwPgMar->setHeader("851");
                ctwPgMar->setFooter("992");
                ctwPgMar->setGutter("0");
            }
            ctwCols = ctwSectPr->setCols();
            if ( ctwCols != NULL ) {
                ctwCols->setSpace("425");
            }
            ctwDocGrid = ctwSectPr->setDocGrid();
            if ( ctwDocGrid != NULL ) {
                ctwDocGrid->setType("lines");
                ctwDocGrid->setLinePitch("312");
            }
        }
    }//if ( body != NULL )
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocumentXML::test()
{
    //http://schemas.openxmlformats.org/wordprocessingml/2006/main
    XMLElement* xmlElement = m_ofd_Node->ToElement();
    DLOG("%s", xmlElement->Name());
    
    const XMLAttribute* attr = xmlElement->FirstAttribute();
  
    while( attr != NULL ) {
        DLOG("%s = %s",attr->Name(),attr->Value());
        attr = attr->Next();
    }
    
    //const char * value;
    //xmlElement->QueryStringAttribute(attr->Name(), &value);
    //DLOG("%s = %s",attr->Name(),attr->Value());
}
//-----------------------------------------------------------------------------------------------------------------
string FZZDocumentXML::getNextStyleID_ToString()
{
    m_GlobalID++;
    return FZZConst::fmt(m_GlobalID);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZDocumentXML::getCurrStyleID_ToString()
{
    return FZZConst::fmt(m_GlobalID);
}
//-----------------------------------------------------------------------------------------------------------------
