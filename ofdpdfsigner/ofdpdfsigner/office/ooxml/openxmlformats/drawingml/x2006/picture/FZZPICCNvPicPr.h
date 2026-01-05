//
//  Created by zizheng fan on 2023/06/01
//
#ifndef FZZPICCNVPICPR_H
#define FZZPICCNVPICPR_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicData.h"

#define FZZPICCNVPICPR_Find_Key "schemas.openxmlformats.org/drawingml/2006/picture"

#define FZZPICCNVPICPR_Name "cNvPicPr"

class FZZPICCNvPicPr : public FZZXMLElementObject
{
public:
    
    FZZPICCNvPicPr(FZZOfficeObject * parent);
    FZZPICCNvPicPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZPICCNvPicPr(const FZZPICCNvPicPr& obj);
    virtual ~FZZPICCNvPicPr();
    
public:
//    void setXmlnsPic(string value);
//    string getXmlnsPic();
    
    //FZZAGraphicData * setGraphicData();
    //FZZAGraphicData * getGraphicData();
protected:
    FZZPICCNvPicPr();
private:
    //FZZAGraphicData * m_FZZAGraphicData;
    
};

#endif //FZZPICCNVPICPR_H
