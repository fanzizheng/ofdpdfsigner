//
//  Created by zizheng fan on 2023/11/21
//
#ifndef FZZWABSTRACTNUM_H
#define FZZWABSTRACTNUM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNsid.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWMultiLevelType.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTmpl.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvl.h"

#define FZZWABSTRACTNUM_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWABSTRACTNUM_Name "abstractNum"



class FZZWAbstractNum : public FZZXMLElementObject
{
public:
    
    FZZWAbstractNum(FZZOfficeObject * parent);
    FZZWAbstractNum(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWAbstractNum(const FZZWAbstractNum& obj);
    virtual ~FZZWAbstractNum();
    
public:
    FZZWNsid * setNsid();
    FZZWNsid * getNsid();
    FZZWMultiLevelType * setMultiLevelType();
    FZZWMultiLevelType * getMultiLevelType();
    FZZWTmpl * setTmpl();
    FZZWTmpl * getTmpl();
    FZZWLvl * addLvl();
    vector<FZZWLvl*> * getLvlList();
    FZZWLvl * getLvl(string lvlid);
    
    void setRestartNumberingAfterBreak(string value);
    string getRestartNumberingAfterBreak();
    void setAbstractNumId(string value);
    string getAbstractNumId();

protected:
    FZZWAbstractNum();
private:
    FZZWNsid* m_FZZWNsid;
    FZZWMultiLevelType * m_FZZWMultiLevelType;
    FZZWTmpl* m_FZZWTmpl;
    //FZZWLvl* m_FZZWLvl;
    vector<FZZWLvl *> m_FZZWLvlList;
};

#endif //FZZWABSTRACTNUM_H
