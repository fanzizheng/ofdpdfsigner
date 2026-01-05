//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDCOMMONDATA_H
#define FZZOFDCOMMONDATA_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDMaxUnitID.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPublicRes.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDocumentRes.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDDefaultCS.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageArea.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDTemplatePage.h"

#define FZZOFDCOMMONDATA_Name "ofd:CommonData"

class FZZOFDCommonData : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDCommonData(FZZOFDXMLFileObject * parent);
    FZZOFDCommonData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCommonData(const FZZOFDCommonData& obj);
    virtual ~FZZOFDCommonData();
    
public:
    FZZOFDMaxUnitID * setMaxUnitID();
    FZZOFDMaxUnitID * getMaxUnitID();
    FZZOFDPublicRes * setPublicRes();
    FZZOFDPublicRes * getPublicRes();
    FZZOFDDocumentRes * setDocumentRes();
    FZZOFDDocumentRes * getDocumentRes();
    FZZOFDDefaultCS * setDefaultCS();
    FZZOFDDefaultCS * getDefaultCS();
    FZZOFDPageArea * setPageArea();
    FZZOFDPageArea * getPageArea();
    
    FZZOFDTemplatePage * addTemplatePage();
    vector<FZZOFDTemplatePage*> * getTemplatePageList();
    
    
protected:
    FZZOFDCommonData();
private:
    FZZOFDMaxUnitID * m_FZZOFDMaxUnitID;
    FZZOFDPublicRes * m_FZZOFDPublicRes;
    FZZOFDDocumentRes * m_FZZOFDDocumentRes;
    FZZOFDDefaultCS * m_FZZOFDDefaultCS;
    FZZOFDPageArea * m_FZZOFDPageArea;
    vector<FZZOFDTemplatePage*> m_FZZOFDTemplatePages;
};

#endif //FZZOFDCOMMONDATA_H
