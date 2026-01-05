//
//  Created by zizheng fan on 2023/10/23
//
#ifndef FZZWSTYLE_H
#define FZZWSTYLE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWName.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUnhideWhenUsed.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSemiHidden.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUiPriority.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWQFormat.h"

#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsid.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBasedOn.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblStylePr.h"

#define FZZWSTYLE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSTYLE_Name "style"

class FZZWStyle : public FZZXMLElementObject
{
public:
    
    FZZWStyle(FZZOfficeObject * parent);
    FZZWStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWStyle(const FZZWStyle& obj);
    virtual ~FZZWStyle();
    
public:
    void setDefault(string value);
    string getDefault();
    void setType(string value);
    string getType();
    void setStyleId(string value);
    string getStyleId();
    
    //FZZWTblPr * addTblPr();
    //vector<FZZWTblPr*> * getTblPrs();
    FZZWTblPr * setTblPr();
    FZZWTblPr * getTblPr();

    FZZWName * setName();
    FZZWName * getName();
    FZZWUnhideWhenUsed * setUnhideWhenUsed();
    FZZWUnhideWhenUsed * getUnhideWhenUsed();
    FZZWSemiHidden * setSemiHidden();
    FZZWSemiHidden * getSemiHidden();
    FZZWUiPriority * setUiPriority();
    FZZWUiPriority * getUiPriority();
    FZZWQFormat * setQFormat();
    FZZWQFormat * getQFormat();
    FZZWRsid * setRsid();
    FZZWRsid * getRsid();
    FZZWPPr * setPpr();
    FZZWPPr * getPpr();
    FZZWBasedOn * setBasedOn();
    FZZWBasedOn * getBasedOn();
    FZZWRPr * setRpr();
    FZZWRPr * getRpr();
    FZZWTblStylePr * setTblStylePr();
    FZZWTblStylePr * getTblStylePr();
protected:
    FZZWStyle();
private:
    //vector<FZZWTblPr*> m_FZZWTblPrs;
    FZZWTblPr * m_FZZWTblPr;
    FZZWName * m_FZZWName;
    FZZWUnhideWhenUsed * m_FZZWUnhideWhenUsed;
    FZZWSemiHidden * m_FZZWSemiHidden;
    FZZWUiPriority * m_FZZWUiPriority;
    FZZWQFormat * m_FZZWQFormat;
    FZZWRsid * m_FZZWRsid;
    FZZWPPr * m_FZZWPPr;
    FZZWBasedOn * m_FZZWBasedOn;
    FZZWRPr * m_FZZWRPr;
    FZZWTblStylePr * m_FZZWTblStylePr;
};

#endif //FZZWSTYLE_H
