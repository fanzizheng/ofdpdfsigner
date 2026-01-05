//
//  Created by zizheng fan on 2023/10/27
//
#ifndef FZZWP_H
#define FZZWP_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWR.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWHyperlink.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSmartTag.h"

#define FZZWP_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWP_Name "p"

class FZZDocXDir;

class FZZWP : public FZZXMLElementObject
{
public:
    
    FZZWP(FZZOfficeObject * parent);
    FZZWP(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWP(const FZZWP& obj);
    virtual ~FZZWP();
    
public:
    void setParaId(string value);
    string getParaId();
    void setTextId(string value);
    string getTextId();
    void setRsidR(string value);
    string getRsidR();
    void setRsidRDefault(string value);
    string getRsidRDefault();
    void setRsidRPr(string value);
    string getRsidRPr();
    
    FZZWPPr * setPPr();
    FZZWPPr * getPPr();
    
    
//    FZZWR * setR();
//    FZZWR * getR();
//    FZZWPPr * addPPr();
//    vector<FZZWPPr*> * getPPrs();
    FZZWR * addR();
    vector<FZZWR*> * getRList();
    FZZWHyperlink * addHyperlinkList();
    vector<FZZWHyperlink*> * getHyperlinkList();
    FZZWSmartTag * addSmartTag();
    vector<FZZWSmartTag*> * getSmartTagList();
    
    vector<FZZWR*> * getRList_All();
    
public:
    void setDocXDir(FZZDocXDir * FZZDocXDir);
    bool addText(string text,string fontname = "eastAsia",int fontsize = 0,bool isBlob = false,int text_color_R = 0,int text_color_G = 0,int text_color_B = 0,int alpha = 255);
    // imageFileName => xxx.png
    // png,gif,jpg,tif, not bmp
    bool addImage(string imageFileName,FZZBytes * imageData,bool isPixel,float width,float height);
    bool addLine(int color_R = 0,int color_G = 0,int color_B = 0,int alpha = 255);
    
protected:
    FZZWP();
private:
    FZZWPPr * m_FZZWPPr;
 
    //FZZWR * m_FZZWR;
    
    //vector<FZZWPPr*> m_FZZWPPrs;
    vector<FZZWR*> m_FZZWRs;
    vector<FZZWHyperlink *> m_FZZWHyperlinkList;
    vector<FZZWSmartTag *> m_FZZWSmartTagList;
    
    FZZDocXDir * m_DocXDir;
    vector<FZZWR*> m_FZZWRList_All;
};

#endif //FZZWP_H
