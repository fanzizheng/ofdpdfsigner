//
//  Created by zizheng fan on 2023/04/21.
//
#ifndef FZZVSHAPE_H
#define FZZVSHAPE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVStroke.h"
#include "office/ooxml/microsoft/office/word/FZZW10Wrap.h"
#include "office/ooxml/microsoft/vml/FZZVPath.h"
#include "office/ooxml/microsoft/vml/FZZVTextbox.h"
#include "office/ooxml/microsoft/vml/FZZVImageData.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"
#include "office/ooxml/microsoft/vml/FZZVTextpath.h"

#define FZZVSHAPE_Find_Key "schemas-microsoft-com:vml"
#define FZZVSHAPE_Name "shape"

class FZZVShape : public FZZXMLElementObject
{
public:
    
    FZZVShape(FZZOfficeObject * parent);
    FZZVShape(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVShape(const FZZVShape& obj);
    virtual ~FZZVShape();
    
public:
    FZZVStroke * setStroke();
    FZZVStroke * getStroke();
    FZZW10Wrap * setWrap();
    FZZW10Wrap * getWrap();
    FZZVPath * setPath();
    FZZVPath * getPath();
    FZZVTextbox * setTextbox();
    FZZVTextbox * getTextbox();
    FZZVImageData * setImageData();
    FZZVImageData * getImageData();
    FZZOLock * setLock();
    FZZOLock * getLock();
    FZZVTextpath * setTextpath();
    FZZVTextpath * getTextpath();

    void setAnchorId(string value);
    string getAnchorId();
    void setId(string value);
    string getId();
    void setSpId(string value);
    string getSpId();
    void setStyle(string value);
    string getStyle();
    void setOle(string value);
    string getOle();
    void setFillcolor(string value);
    string getFillcolor();
    void setGfxdata(string value);
    string getGfxdata();
    void setStrokecolor(string value);
    string getStrokecolor();
    void setStrokeweight(string value);
    string getStrokeweight();
    void setType(string value);
    string getType();
    void setFilled(string value);
    string getFilled();
    void setStroked(string value);
    string getStroked();
    void setPreferrelative(string value);
    string getPreferrelative();
    void setCoordorigin(string value);
    string getCoordorigin();
    void setCoordsize(string value);
    string getCoordsize();
    void setAdj(string value);
    string getAdj();
    
    
    
protected:
    FZZVShape();
private:
    FZZVStroke* m_FZZVStroke;
    FZZW10Wrap * m_FZZW10Wrap;
    FZZVPath * m_FZZVPath;
    FZZVTextbox * m_FZZVTextbox;
    FZZVImageData * m_FZZVImageData;
    FZZOLock * m_FZZOLock;
    FZZVTextpath * m_FZZVTextpath;
};

#endif //FZZVSHAPE_H
