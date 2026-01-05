//
//  Created by zizheng fan on 2023/06/02
//
#ifndef FZZPICCNVPR_H
#define FZZPICCNVPR_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicData.h"

#define FZZPICCNVPR_Find_Key "schemas.openxmlformats.org/drawingml/2006/picture"

#define FZZPICCNVPR_Name "cNvPr"

class FZZPICCNvPr : public FZZXMLElementObject
{
public:
    
    FZZPICCNvPr(FZZOfficeObject * parent);
    FZZPICCNvPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZPICCNvPr(const FZZPICCNvPr& obj);
    virtual ~FZZPICCNvPr();
    
public:
    void setId(string value);
    string getId();
    void setName(string value);
    string getName();
    
    //FZZAGraphicData * setGraphicData();
    //FZZAGraphicData * getGraphicData();
protected:
    FZZPICCNvPr();
private:
    //FZZAGraphicData * m_FZZAGraphicData;
    
};

#endif //FZZPICCNVPR_H
