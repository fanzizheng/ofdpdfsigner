//
//  Created by zizheng fan on 2023/11/08
//
#ifndef FZZWPICT_H
#define FZZWPICT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVLine.h"
#include "office/ooxml/microsoft/vml/FZZVShape.h"
#include "office/ooxml/microsoft/vml/FZZVRect.h"
#include "office/ooxml/microsoft/vml/FZZVShapeType.h"
#include "office/ooxml/microsoft/vml/FZZVGroup.h"


#define FZZWPICT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPICT_Name "pict"

class FZZDocXDir;

class FZZWPict : public FZZXMLElementObject
{
public:
    
    FZZWPict(FZZOfficeObject * parent);
    FZZWPict(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPict(const FZZWPict& obj);
    virtual ~FZZWPict();
    
public:
    FZZVLine * addLine();
    vector<FZZVLine*> * getLineList();
    FZZVShape * addShape();
    vector<FZZVShape*> * getShapeList();
    FZZVRect * addRect();
    vector<FZZVRect*> * getRectList();
    FZZVShapeType * addShapeType();
    vector<FZZVShapeType*> * getShapeTypeList();
    
    FZZVGroup * addGroup();
    vector<FZZVGroup*> * getGroupList();
    
public:
    void setDocXDir(FZZDocXDir * docXDir);
    
protected:
    FZZWPict();
private:
    vector<FZZVLine*> m_FZZVLines;
    vector<FZZVShapeType*> m_FZZVShapeTypes;
    vector<FZZVShape*> m_FZZVShapes;
    vector<FZZVRect*> m_FZZVRects;
    vector<FZZVGroup *> m_FZZVGroups;
    
    FZZDocXDir * m_DocXDir;
};

#endif //FZZWPICT_H
