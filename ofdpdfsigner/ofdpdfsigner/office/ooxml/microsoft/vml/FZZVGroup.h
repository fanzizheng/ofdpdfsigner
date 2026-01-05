//
//  Created by zizheng fan on 2024/02/02.
//
#ifndef FZZVGROUP_H
#define FZZVGROUP_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVLine.h"
#include "office/ooxml/microsoft/vml/FZZVShape.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"
#include "office/ooxml/microsoft/vml/FZZVShapeType.h"

#define FZZVGROUP_Find_Key "schemas-microsoft-com:vml"
#define FZZVGROUP_Name "group"

class FZZVGroup : public FZZXMLElementObject
{
public:
    
    FZZVGroup(FZZOfficeObject * parent);
    FZZVGroup(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVGroup(const FZZVGroup& obj);
    virtual ~FZZVGroup();
    
public:
    FZZVLine * addLine();
    vector<FZZVLine*> * getLineList();
    FZZVShape * addShape();
    vector<FZZVShape*> * getShapeList();
    FZZVShapeType * addShapeType();
    vector<FZZVShapeType*> * getShapeTypeList();
    
    FZZOLock * setLock();
    FZZOLock * getLock();
    
    void setId(string value);
    string getId();
    void setSpId(string value);
    string getSpId();
    void setStyle(string value);
    string getStyle();
    void setCoordorigin(string value);
    string getCoordorigin();
    void setCoordsize(string value);
    string getCoordsize();
    
protected:
    FZZVGroup();
private:
    vector<FZZVLine*> m_FZZVLines;
    vector<FZZVShape*> m_FZZVShapes;
    vector<FZZVShapeType*> m_FZZVShapeTypes;
    FZZOLock * m_FZZOLock;
};

#endif //FZZVGROUP_H
