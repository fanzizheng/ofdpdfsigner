//
//  Created by zizheng fan on 2023/06/07
//
#ifndef FZZPICPIC_H
#define FZZPICPIC_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICSpPr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICBlipFill.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICNvPicPr.h"

#define FZZPICPIC_Find_Key "schemas.openxmlformats.org/drawingml/2006/picture"

#define FZZPICPIC_Name "pic"

class FZZPICPic : public FZZXMLElementObject
{
public:
    
    FZZPICPic(FZZOfficeObject * parent);
    FZZPICPic(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZPICPic(const FZZPICPic& obj);
    virtual ~FZZPICPic();
    
public:
    void setXmlnsPic(string value);
    string getXmlnsPic();
    
    FZZPICSpPr * setSpPr();
    FZZPICSpPr * getSpPr();
    FZZPICBlipFill * setBlipFill();
    FZZPICBlipFill * getBlipFill();
    FZZPICNvPicPr * setNvPicPr();
    FZZPICNvPicPr * getNvPicPr();
protected:
    FZZPICPic();
private:
    FZZPICSpPr * m_FZZPICSpPr;
    FZZPICBlipFill * m_FZZPICBlipFill;
    FZZPICNvPicPr * m_FZZPICNvPicPr;
};

#endif //FZZPICPIC_H
