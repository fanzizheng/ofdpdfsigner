//
//  Created by zizheng fan on 2023/05/07.
//
#ifndef FZZWPSWSP_H
#define FZZWPSWSP_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSCNvCnPr.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSSpPr.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSStyle.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSBodyPr.h"

#define FZZWPSWSP_Find_Key "schemas.microsoft.com/office/word/2010/wordprocessingShape"
#define FZZWPSWSP_Name "wsp"

class FZZWPSWsp : public FZZXMLElementObject
{
public:
    
    FZZWPSWsp(FZZOfficeObject * parent);
    FZZWPSWsp(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPSWsp(const FZZWPSWsp& obj);
    virtual ~FZZWPSWsp();
    
public:
    FZZWPSCNvCnPr * setCNvCnPr();
    FZZWPSCNvCnPr * getCNvCnPr();
    FZZWPSSpPr * setSpPr();
    FZZWPSSpPr * getSpPr();
    FZZWPSStyle * setStyle();
    FZZWPSStyle * getStyle();
    FZZWPSBodyPr * setBodyPr();
    FZZWPSBodyPr * getBodyPr();
    
protected:
    FZZWPSWsp();
private:
    FZZWPSCNvCnPr * m_FZZWPSCNvCnPr;
    FZZWPSSpPr * m_FZZWPSSpPr;
    FZZWPSStyle * m_FZZWPSStyle;
    FZZWPSBodyPr * m_FZZWPSBodyPr;
};

#endif //FZZWPSWSP_H
