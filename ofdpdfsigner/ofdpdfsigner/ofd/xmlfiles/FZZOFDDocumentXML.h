//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDOCUMENTXML_H
#define FZZOFDDOCUMENTXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Extensions.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Attachments.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_CustomTags.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Annotations.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmarks.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDVPreferences.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPermission.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDOutlines.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPages.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDCommonData.h"

#define FZZOFDDOCUMENTXML_FILENAME "Document.xml"

#define PAGE_SIZE_A0 "0 0 841 1189"
#define PAGE_SIZE_A1 "0 0 594 841"
#define PAGE_SIZE_A2 "0 0 420 594"
#define PAGE_SIZE_A3 "0 0 297 420"
#define PAGE_SIZE_A4 "0 0 210 297"
#define PAGE_SIZE_A5 "0 0 148 210"
#define PAGE_SIZE_A6 "0 0 105 148"
#define PAGE_SIZE_A7 "0 0 74 105"
#define PAGE_SIZE_A8 "0 0 52 74"
#define PAGE_SIZE_A9 "0 0 37 52"
#define PAGE_SIZE_A10 "0 0 26 37"


class FZZOFDDocumentXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDDocumentXML();
    FZZOFDDocumentXML(XMLDocument * doc);
    FZZOFDDocumentXML(const FZZOFDDocumentXML& obj);
    virtual ~FZZOFDDocumentXML();

public:
    FZZOFDDocument_Extensions * setExtensions();
    FZZOFDDocument_Extensions * getExtensions();
    FZZOFDDocument_Attachments * setAttachments();
    FZZOFDDocument_Attachments * getAttachments();
    FZZOFDDocument_CustomTags * setCustomTags();
    FZZOFDDocument_CustomTags * getCustomTags();
    FZZOFDDocument_Annotations * setAnnotations();
    FZZOFDDocument_Annotations * getAnnotations();
    FZZOFDBookmarks * setBookmarks();
    FZZOFDBookmarks * getBookmarks();
    FZZOFDVPreferences * setVPreferences();
    FZZOFDVPreferences * getVPreferences();
    FZZOFDActions * setActions();
    FZZOFDActions * getActions();
    FZZOFDPermission * setPermission();
    FZZOFDPermission * getPermission();
    FZZOFDOutlines * setOutlines();
    FZZOFDOutlines * getOutlines();
    FZZOFDPages * setPages();
    FZZOFDPages * getPages();
    FZZOFDCommonData * setCommonData();
    FZZOFDCommonData * getCommonData();

public:
  
protected:
    
private:

    FZZOFDDocument_Extensions * m_FZZOFDDocument_Extensions;
    FZZOFDDocument_Attachments * m_FZZOFDDocument_Attachments;
    FZZOFDDocument_CustomTags * m_FZZOFDDocument_CustomTags;
    FZZOFDDocument_Annotations * m_FZZOFDDocument_Annotations;
    FZZOFDBookmarks * m_FZZOFDBookmarks;
    FZZOFDVPreferences * m_FZZOFDVPreferences;
    FZZOFDActions * m_FZZOFDActions;
    FZZOFDPermission * m_FZZOFDPermission;
    FZZOFDOutlines * m_FZZOFDOutlines;
    FZZOFDPages * m_FZZOFDPages;
    FZZOFDCommonData * m_FZZOFDCommonData;
//        .setAnnotations(ST_Loc.getInstance("./Res/Annotations.xml"))
//                        .setCustomTags(ST_Loc.getInstance("./Res/CustomTags.xml"))
//                        .setAttachments(ST_Loc.getInstance("./Attachments.xml"))
//                        .setExtensions(ST_Loc.getInstance("./Res/Extensions.xml"))
};

#endif //FZZOFDDOCUMENTXML_H
