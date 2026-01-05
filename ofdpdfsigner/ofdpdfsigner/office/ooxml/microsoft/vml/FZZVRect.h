//
//  Created by zizheng fan on 2023/04/20.
//
#ifndef FZZVRECT_H
#define FZZVRECT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVStroke.h"
#include "office/ooxml/microsoft/office/word/FZZW10Wrap.h"
#include "office/ooxml/microsoft/vml/FZZVTextbox.h"
#include "office/ooxml/microsoft/vml/FZZVFill.h"
#include "office/ooxml/microsoft/vml/FZZVImageData.h"
#include "office/ooxml/microsoft/office/office/FZZOLock.h"

#define FZZVRECT_Find_Key "schemas-microsoft-com:vml"
#define FZZVRECT_Name "rect"

class FZZVRect : public FZZXMLElementObject
{
public:
    
    FZZVRect(FZZOfficeObject * parent);
    FZZVRect(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVRect(const FZZVRect& obj);
    virtual ~FZZVRect();
    
public:
//    FZZVStroke * setStroke();
//    FZZVStroke * getStroke();
    FZZW10Wrap * setWrap();
    FZZW10Wrap * getWrap();
    FZZVTextbox * setTextbox();
    FZZVTextbox * getTextbox();
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
//    void setFrom(string value);
//    string getFrom();
//    void setTo(string value);
//    string getTo();
    void setGfxdata(string value);
    string getGfxdata();
    void setStrokecolor(string value);
    string getStrokecolor();
    void setStrokeweight(string value);
    string getStrokeweight();
    void setFillcolor(string value);
    string getFillcolor();
    void setType(string value);
    string getType();
    
    void setPreferrelative(string value);
    string getPreferrelative();
    void setOle(string value);
    string getOle();
    void setFilled(string value);
    string getFilled();
    void setStroked(string value);
    string getStroked();
    void setCoordorigin(string value);
    string getCoordorigin();
    void setCoordsize(string value);
    string getCoordsize();
    
protected:
    FZZVRect();
private:
    //FZZVStroke* m_FZZVStroke;
    FZZW10Wrap * m_FZZW10Wrap;
    FZZVTextbox * m_FZZVTextbox;
    FZZVImageData * m_FZZVImageData;
    FZZOLock * m_FZZOLock;
    FZZVFill * m_FZZVFill;
};

#endif //FZZVRECT_H
