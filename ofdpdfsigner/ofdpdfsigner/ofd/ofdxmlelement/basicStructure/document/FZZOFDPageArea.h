//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDPAGEAREA_H
#define FZZOFDPAGEAREA_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPhysicalBox.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDApplicationBox.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDContentBox.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBleedBox.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDCropBox.h"

#define FZZOFDPAGEAREA_Name "ofd:PageArea"
#define FZZOFDPAGEAREA_EXT_Name "ofd:Area"

class FZZOFDPageArea : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPageArea(FZZOFDXMLFileObject * parent);
    FZZOFDPageArea(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPageArea(const FZZOFDPageArea& obj);
    virtual ~FZZOFDPageArea();
    
public:
    FZZOFDPhysicalBox * setPhysicalBox();
    FZZOFDPhysicalBox * getPhysicalBox();
    FZZOFDApplicationBox * setApplicationBox();
    FZZOFDApplicationBox * getApplicationBox();
    FZZOFDContentBox * setContentBox();
    FZZOFDContentBox * getContentBox();
    FZZOFDBleedBox * setBleedBox();
    FZZOFDBleedBox * getBleedBox();
    FZZOFDCropBox * setCropBox();
    FZZOFDCropBox * getCropBox();
    string getBox();
    void getBox(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
protected:
    FZZOFDPageArea();
private:
    FZZOFDPhysicalBox * m_FZZOFDPhysicalBox;
    FZZOFDApplicationBox * m_FZZOFDApplicationBox;
    FZZOFDContentBox * m_FZZOFDContentBox;
    FZZOFDBleedBox * m_FZZOFDBleedBox;
    FZZOFDCropBox * m_FZZOFDCropBox;
};

#endif //FZZOFDPAGEAREA_H
