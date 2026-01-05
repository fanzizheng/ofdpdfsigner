//
//  Created by zizheng fan on 2023/04/21.
//
#ifndef FZZVLINE_H
#define FZZVLINE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVStroke.h"
#include "office/ooxml/microsoft/office/word/FZZW10Wrap.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"
#include "office/ooxml/microsoft/vml/FZZVFill.h"
#include "office/ooxml/microsoft/vml/FZZVImageData.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"

#define FZZVLINE_Find_Key "schemas-microsoft-com:vml"
#define FZZVLINE_Name "line"

class FZZVLine : public FZZXMLElementObject
{
public:
    
    FZZVLine(FZZOfficeObject * parent);
    FZZVLine(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVLine(const FZZVLine& obj);
    virtual ~FZZVLine();
    
public:
    FZZVStroke * setStroke();
    FZZVStroke * getStroke();
    FZZW10Wrap * setWrap();
    FZZW10Wrap * getWrap();
    FZZVImageData * setImageData();
    FZZVImageData * getImageData();
    FZZOLock * setLock();
    FZZOLock * getLock();
    FZZVFill * setFill();
    FZZVFill * getFill();

    void setAnchorId(string value);
    string getAnchorId();
    void setId(string value);
    string getId();
    void setSpId(string value);
    string getSpId();
    void setStyle(string value);
    string getStyle();
    void setFrom(string value);
    string getFrom();
    void setTo(string value);
    string getTo();
    void setGfxdata(string value);
    string getGfxdata();
    void setStrokecolor(string value);
    string getStrokecolor();
    void setStrokeweight(string value);
    string getStrokeweight();
    void setType(string value);
    string getType();
    void setOle(string value);
    string getOle();
    void setFillcolor(string value);
    string getFillcolor();
    void setFilled(string value);
    string getFilled();
    void setPreferrelative(string value);
    string getPreferrelative();
    void setStroked(string value);
    string getStroked();
    void setCoordsize(string value);
    string getCoordsize();
protected:
    FZZVLine();
private:
    FZZVStroke* m_FZZVStroke;
    FZZW10Wrap * m_FZZW10Wrap;
    FZZVFill * m_FZZVFill;
    FZZVImageData * m_FZZVImageData;
    FZZOLock * m_FZZOLock;
    
};

#endif //FZZVLINE_H
