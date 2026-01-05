//
//  Created by zizheng fan on 2023/04/18.
//
#ifndef FZZVSHAPETYPE_H
#define FZZVSHAPETYPE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVStroke.h"
#include "office/ooxml/microsoft/vml/FZZVPath.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"
#include "office/ooxml/microsoft/vml/FZZVFormulas.h"

#define FZZVSHAPETYPE_Find_Key "schemas-microsoft-com:vml"
#define FZZVSHAPETYPE_Name "shapetype"

class FZZVShapeType : public FZZXMLElementObject
{
public:
    
    FZZVShapeType(FZZOfficeObject * parent);
    FZZVShapeType(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVShapeType(const FZZVShapeType& obj);
    virtual ~FZZVShapeType();
    
public:
    void setId(string value);
    string getId();
    void setCoordSize(string value);
    string getCoordSize();
    void setSpt(string value);
    string getSpt();
    void setPreferrelative(string value);
    string getPreferrelative();
    void setPath_Attribute(string value);
    string getPath_Attribute();
    void setFilled(string value);
    string getFilled();
    void setStroked(string value);
    string getStroked();
    
    FZZVStroke * setStroke();
    FZZVStroke * getStroke();
    FZZOLock * setLock();
    FZZOLock * getLock();
    FZZVPath * setPath();
    FZZVPath * getPath();
    FZZVFormulas * setFormulas();
    FZZVFormulas * getFormulas();

    
protected:
    FZZVShapeType();
private:
    FZZVStroke* m_FZZVStroke;
    FZZVPath * m_FZZVPath;
    FZZOLock * m_FZZOLock;
    FZZVFormulas * m_FZZVFormulas;
};

#endif //FZZVSHAPE_H
