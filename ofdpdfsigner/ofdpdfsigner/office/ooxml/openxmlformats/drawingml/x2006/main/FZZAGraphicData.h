//
//  Created by zizheng fan on 2023/07/14
//
#ifndef FZZAGRAPHICDATA_H
#define FZZAGRAPHICDATA_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICPic.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSWsp.h"

#define FZZAGRAPHICDATA_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAGRAPHICDATA_Name "graphicData"

class FZZAGraphicData : public FZZXMLElementObject
{
public:
    
    FZZAGraphicData(FZZOfficeObject * parent);
    FZZAGraphicData(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAGraphicData(const FZZAGraphicData& obj);
    virtual ~FZZAGraphicData();
    
public:
    void setUri(string value);
    string getUri();
    
    FZZPICPic * setPic();
    FZZPICPic * getPic();
    FZZWPSWsp * setWsp();
    FZZWPSWsp * getWsp();
protected:
    FZZAGraphicData();
private:
    FZZPICPic * m_FZZPICPic;
    FZZWPSWsp * m_FZZWPSWsp;
};

#endif //FZZAGRAPHICDATA_H
