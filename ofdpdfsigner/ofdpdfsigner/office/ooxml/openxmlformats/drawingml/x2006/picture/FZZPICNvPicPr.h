//
//  Created by zizheng fan on 2023/06/05
//
#ifndef FZZPICNVPICPR_H
#define FZZPICNVPICPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICCNvPr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICCNvPicPr.h"

#define FZZPICNVPICPR_Find_Key "schemas.openxmlformats.org/drawingml/2006/picture"

#define FZZPICNVPICPR_Name "nvPicPr"

class FZZPICNvPicPr : public FZZXMLElementObject
{
public:
    
    FZZPICNvPicPr(FZZOfficeObject * parent);
    FZZPICNvPicPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZPICNvPicPr(const FZZPICNvPicPr& obj);
    virtual ~FZZPICNvPicPr();
    
public:
//    void setXmlnsPic(string value);
//    string getXmlnsPic();
//
    //FZZAGraphicData * setGraphicData();
    //FZZAGraphicData * getGraphicData();
    FZZPICCNvPr * setCNvPr();
    FZZPICCNvPr * getCNvPr();
    FZZPICCNvPicPr * setCNvPicPr();
    FZZPICCNvPicPr * getCNvPicPr();
protected:
    FZZPICNvPicPr();
private:
    FZZPICCNvPr * m_FZZPICCNvPr;
    FZZPICCNvPicPr * m_FZZPICCNvPicPr;
};

#endif //FZZPICNVPICPR_H
