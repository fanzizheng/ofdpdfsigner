//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDResXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDResXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResXML::FZZOFDResXML() : FZZOFDXMLFileObject(),m_Fonts(NULL)
{
    //DLOG("FZZOFDResXML()");
    FZZConst::addClassCount("FZZOFDResXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Res");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    //m_FileName = FZZOFDPAGEXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResXML::FZZOFDResXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_Fonts(NULL)
{
    FZZConst::addClassCount("FZZOFDResXML");
    //m_FileName = FZZOFDPAGEXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResXML::FZZOFDResXML(const FZZOFDResXML& obj) : FZZOFDXMLFileObject(obj),m_Fonts(NULL)
{
    FZZConst::addClassCount("FZZOFDResXML");
    if ( this == &obj ) {
        return;
    }
    //m_FZZOFDDocument_Extensions = obj.m_FZZOFDDocument_Extensions != NULL ? new FZZOFDDocument_Extensions(*obj.m_FZZOFDDocument_Extensions) : NULL;
    
    FZZOFDFonts * ofdFonts = NULL;
    FZZOFDColorSpaces * ofdColorSpacs = NULL;
    FZZOFDDrawParams * ofdDrawParams = NULL;
    FZZOFDMultiMedias * ofdMultiMeedias = NULL;
    FZZOFDCompositeGraphicUnits * ofdCompositeGraphicUnits = NULL;
    
    vector<FZZOFDBaseRes*>::const_iterator itr;
    for( itr = obj.m_FZZOFDBaseRess.begin(); itr != obj.m_FZZOFDBaseRess.end(); itr++ ) {
        FZZOFDBaseRes * temp = *itr;
        if ( temp != NULL ) {
            ofdFonts = NULL;
            ofdColorSpacs = NULL;
            ofdDrawParams = NULL;
            ofdMultiMeedias = NULL;
            ofdCompositeGraphicUnits = NULL;
            
            if ( ( ofdFonts = dynamic_cast<FZZOFDFonts*>(temp) ) != NULL ) {
                m_FZZOFDBaseRess.push_back(new FZZOFDFonts(*ofdFonts));
            } else if ( ( ofdColorSpacs = dynamic_cast<FZZOFDColorSpaces*>(temp) ) != NULL ) {
                m_FZZOFDBaseRess.push_back(new FZZOFDColorSpaces(*ofdColorSpacs));
            } else if ( ( ofdDrawParams = dynamic_cast<FZZOFDDrawParams*>(temp) ) != NULL ) {
                m_FZZOFDBaseRess.push_back(new FZZOFDDrawParams(*ofdDrawParams));
            } else if ( ( ofdMultiMeedias = dynamic_cast<FZZOFDMultiMedias*>(temp) ) != NULL ) {
                m_FZZOFDBaseRess.push_back(new FZZOFDMultiMedias(*ofdMultiMeedias));
            } else if ( ( ofdCompositeGraphicUnits = dynamic_cast<FZZOFDCompositeGraphicUnits*>(temp) ) != NULL ) {
                m_FZZOFDBaseRess.push_back(new FZZOFDCompositeGraphicUnits(*ofdCompositeGraphicUnits));
            }
            
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResXML::~FZZOFDResXML()
{
    //DLOG("~FZZOFDResXML()");
    FZZConst::delClassCount("FZZOFDResXML");
//    if ( m_FZZOFDDocument_Extensions != NULL ) {
//        delete m_FZZOFDDocument_Extensions;
//        m_FZZOFDDocument_Extensions = NULL;
//    }
    
    FZZOFDFonts * ofdFonts = NULL;
    FZZOFDColorSpaces * ofdColorSpacs = NULL;
    FZZOFDDrawParams * ofdDrawParams = NULL;
    FZZOFDMultiMedias * ofdMultiMeedias = NULL;
    FZZOFDCompositeGraphicUnits * ofdCompositeGraphicUnits = NULL;
    
    vector<FZZOFDBaseRes*>::const_iterator itr;
    for( itr = m_FZZOFDBaseRess.begin(); itr != m_FZZOFDBaseRess.end(); itr++ ) {
        FZZOFDBaseRes * temp = *itr;
        if ( temp != NULL ) {
            ofdFonts = NULL;
            ofdColorSpacs = NULL;
            ofdDrawParams = NULL;
            ofdMultiMeedias = NULL;
            ofdCompositeGraphicUnits = NULL;
            
            if ( ( ofdFonts = dynamic_cast<FZZOFDFonts*>(temp) ) != NULL ) {
                delete ofdFonts;
            } else if ( ( ofdColorSpacs = dynamic_cast<FZZOFDColorSpaces*>(temp) ) != NULL ) {
                delete ofdColorSpacs;
            } else if ( ( ofdDrawParams = dynamic_cast<FZZOFDDrawParams*>(temp) ) != NULL ) {
                delete ofdDrawParams;
            } else if ( ( ofdMultiMeedias = dynamic_cast<FZZOFDMultiMedias*>(temp) ) != NULL ) {
                delete ofdMultiMeedias;
            } else if ( ( ofdCompositeGraphicUnits = dynamic_cast<FZZOFDCompositeGraphicUnits*>(temp) ) != NULL ) {
                delete ofdCompositeGraphicUnits;
            }
            
            
        }
    }
    m_FZZOFDBaseRess.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDResXML::setBaseLoc(string value)
{
    setAttribute_String("BaseLoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDResXML::getBaseLoc()
{
    return getAttribute_String("BaseLoc");
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDBaseRes*> * FZZOFDResXML::getResourceList()
{
    if ( m_FZZOFDBaseRess.size() <= 0 ) {
        XMLElement* ele = m_ofd_Node->FirstChildElement();
        while (ele != NULL) {
            const char* elename = ele->Name();
            FZZOFDBaseRes * tempObject = NULL;
            
            if (strcmp(elename, FZZOFDFONTS_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,(FZZOFDFonts*)NULL);
            } else if (strcmp(elename, FZZOFDCOLORSPACES_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,(FZZOFDColorSpaces*)NULL);
            } else if (strcmp(elename, FZZOFDDRAWPARAMS_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,(FZZOFDDrawParams*)NULL);
            } else if (strcmp(elename, FZZOFDMULTIMEDIAS_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,(FZZOFDMultiMedias*)NULL);
            } else if (strcmp(elename, FZZOFDCOMPOSITEGRAPHICUNITS_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(this,m_doc, ele,(FZZOFDCompositeGraphicUnits*)NULL);
            }
                       
            if ( tempObject != NULL ) {
                m_FZZOFDBaseRess.push_back(tempObject);
            }

            ele = ele->NextSiblingElement();
        }//while
    }//if ( m_FZZOFDBaseRess.size() <= 0 )
    
    return &m_FZZOFDBaseRess;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFonts* FZZOFDResXML::setFonts()
{
    m_Fonts = setElementObject(m_Fonts,FZZOFDFONTS_Name);
    if ( m_Fonts != NULL ) {
        m_FZZOFDBaseRess.push_back(m_Fonts);
    }
    return m_Fonts;
    
}
//-----------------------------------------------------------------------------------------------------------------
//FZZOFDFonts* FZZOFDResXML::addFonts()
//{
//    FZZOFDFonts * ofdFonts = NULL;
//    ofdFonts = addElementObject_NoAddList(ofdFonts,FZZOFDFONTS_Name);
//    if ( ofdFonts != NULL ) {
//        m_FZZOFDBaseRess.push_back(ofdFonts);
//    }
//    return ofdFonts;
//}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpaces* FZZOFDResXML::addColorSpaces()
{
    FZZOFDColorSpaces * ofdColorSpaces = NULL;
    ofdColorSpaces = addElementObject_NoAddList(ofdColorSpaces,FZZOFDCOLORSPACES_Name);
    if ( ofdColorSpaces != NULL ) {
        m_FZZOFDBaseRess.push_back(ofdColorSpaces);
    }
    return ofdColorSpaces;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParams* FZZOFDResXML::addDrawParams()
{
    FZZOFDDrawParams * ofdDrawParams = NULL;
    ofdDrawParams = addElementObject_NoAddList(ofdDrawParams,FZZOFDDRAWPARAMS_Name);
    if ( ofdDrawParams != NULL ) {
        m_FZZOFDBaseRess.push_back(ofdDrawParams);
    }
    return ofdDrawParams;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedias* FZZOFDResXML::addMultiMedias()
{
    FZZOFDMultiMedias * ofdMultiMedias = NULL;
    ofdMultiMedias = addElementObject_NoAddList(ofdMultiMedias,FZZOFDMULTIMEDIAS_Name);
    if ( ofdMultiMedias != NULL ) {
        m_FZZOFDBaseRess.push_back(ofdMultiMedias);
    }
    return ofdMultiMedias;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeGraphicUnits* FZZOFDResXML::addCompositeGraphicUnits()
{
    FZZOFDCompositeGraphicUnits * ofdCompositeGraphicUnits = NULL;
    ofdCompositeGraphicUnits = addElementObject_NoAddList(ofdCompositeGraphicUnits,FZZOFDCOMPOSITEGRAPHICUNITS_Name);
    if ( ofdCompositeGraphicUnits != NULL ) {
        m_FZZOFDBaseRess.push_back(ofdCompositeGraphicUnits);
    }
    return ofdCompositeGraphicUnits;
    
}
//-----------------------------------------------------------------------------------------------------------------
