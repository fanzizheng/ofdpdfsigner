//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDPERMISSION_H
#define FZZOFDPERMISSION_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPrint.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDValidPeriod.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDEdit.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDAnnot.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDExport.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDWatermark.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDSignature_Permission.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPrintScreen.h"

#define FZZOFDPERMISSION_Name "ofd:Permission"

class FZZOFDPermission : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPermission(FZZOFDXMLFileObject * parent);
    FZZOFDPermission(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPermission(const FZZOFDPermission& obj);
    virtual ~FZZOFDPermission();
    
public:
    FZZOFDPrint * setPrint();
    FZZOFDPrint * getPrint();
    FZZOFDValidPeriod * setValidPeriod();
    FZZOFDValidPeriod * getValidPeriod();
    
    FZZOFDEdit * setEdit();
    FZZOFDEdit * getEdit();
    FZZOFDAnnot * setAnnot();
    FZZOFDAnnot * getAnnot();
    FZZOFDExport * setExport();
    FZZOFDExport * getExport();
    FZZOFDWatermark * setWatermark();
    FZZOFDWatermark * getWatermark();
    FZZOFDSignature_Permission * setSignature();
    FZZOFDSignature_Permission * getSignature();
    FZZOFDPrintScreen * setPrintScreen();
    FZZOFDPrintScreen * getPrintScreen();
    
protected:
    FZZOFDPermission();
private:
    FZZOFDPrint * m_FZZOFDPrint;
    FZZOFDValidPeriod * m_FZZOFDValidPeriod;
    FZZOFDEdit * m_FZZOFDEdit;
    FZZOFDAnnot * m_FZZOFDAnnot;
    FZZOFDExport * m_FZZOFDExport;
    FZZOFDWatermark * m_FZZOFDWatermark;
    FZZOFDSignature_Permission * m_FZZOFDSignature_Permission;
    FZZOFDPrintScreen * m_FZZOFDPrintScreen;
};

#endif //FZZOFDPERMISSION_H
