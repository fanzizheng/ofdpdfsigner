//
//  Created by zizheng fan on 2023/06/22
//
#ifndef FZZWPEXTENT_H
#define FZZWPEXTENT_H

#include "office/FZZXMLElementObject.h"


#define FZZWPEXTENT_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPEXTENT_Name "extent"

class FZZWPExtent : public FZZXMLElementObject
{
public:
    
    FZZWPExtent(FZZOfficeObject * parent);
    FZZWPExtent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPExtent(const FZZWPExtent& obj);
    virtual ~FZZWPExtent();
    
public:
    //-> mm : cx/914400*25.4 ; FZZDocXConst::ETUToMillimeters(cx);
    //-> pix: cx/914400*72 ; FZZDocXConst::ETUToPixel(cx);
    void setCx(string value);
    string getCx();
    void setCy(string value);
    string getCy();
    
protected:
    FZZWPExtent();
private:
    
    
};

#endif //FZZWPEXTENT_H
