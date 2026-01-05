//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDDOCINFO_H
#define FZZOFDDOCINFO_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocUsage.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo_Keywords.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCustomDatas.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCover.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocID.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDTitle.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDAuthor.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDSubjec.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDAbstract.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreationDate.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDModDate.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreator.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreatorVersion.h"

#define FZZOFDDOCINFO_Name "ofd:DocInfo"

class FZZOFDDocInfo : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocInfo(FZZOFDXMLFileObject * parent);
    FZZOFDDocInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocInfo(const FZZOFDDocInfo& obj);
    virtual ~FZZOFDDocInfo();
    
public:
//    void setExt(string value);
//    string getExt();
    FZZOFDDocUsage * setDocUsage();
    FZZOFDDocUsage * getDocUsage();
    FZZOFDDocInfo_Keywords * setKeywords();
    FZZOFDDocInfo_Keywords * getKeywords();
    FZZOFDCustomDatas * setCustomDatas();
    FZZOFDCustomDatas * getCustomDatas();
    FZZOFDCover * setCover();
    FZZOFDCover * getCover();
    FZZOFDDocID * setDocID();
    FZZOFDDocID * getDocID();
    FZZOFDTitle * setTitle();
    FZZOFDTitle * getTitle();
    FZZOFDAuthor * setAuthor();
    FZZOFDAuthor * getAuthor();
    FZZOFDSubjec * setSubjec();
    FZZOFDSubjec * getSubjec();
    FZZOFDAbstract * setAbstract();
    FZZOFDAbstract * getAbstract();
    FZZOFDCreationDate * setCreationDate();
    FZZOFDCreationDate * getCreationDate();
    FZZOFDModDate * setModDate();
    FZZOFDModDate * getModDate();
    FZZOFDCreator * setCreator();
    FZZOFDCreator * getCreator();
    FZZOFDCreatorVersion * setCreatorVersion();
    FZZOFDCreatorVersion * getCreatorVersion();
    
protected:
    FZZOFDDocInfo();
private:
    FZZOFDDocUsage * m_FZZOFDDocUsage;
    FZZOFDDocInfo_Keywords * m_FZZOFDDocInfo_Keywords;
    FZZOFDCustomDatas * m_FZZOFDCustomDatas;
    FZZOFDCover * m_FZZOFDCover;
    FZZOFDDocID * m_FZZOFDDocID;
    FZZOFDTitle * m_FZZOFDTitle;
    FZZOFDAuthor * m_FZZOFDAuthor;
    FZZOFDSubjec * m_FZZOFDSubjec;
    FZZOFDAbstract * m_FZZOFDAbstract;
    FZZOFDCreationDate * m_FZZOFDCreationDate;
    FZZOFDModDate * m_FZZOFDModDate;
    FZZOFDCreator * m_FZZOFDCreator;
    FZZOFDCreatorVersion * m_FZZOFDCreatorVersion;
    
};

#endif //FZZOFDDOCINFO_H
