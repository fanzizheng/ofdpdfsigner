//
//  Created by zizheng fan on 2023/06/21
//
#ifndef FZZWPEFFECTEXTENT_H
#define FZZWPEFFECTEXTENT_H

#include "office/FZZXMLElementObject.h"

#define FZZWPEFFECTEXTENT_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPEFFECTEXTENT_Name "effectExtent"

class FZZWPEffectExtent : public FZZXMLElementObject
{
public:
    
    FZZWPEffectExtent(FZZOfficeObject * parent);
    FZZWPEffectExtent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPEffectExtent(const FZZWPEffectExtent& obj);
    virtual ~FZZWPEffectExtent();
   
public:
    void setL(string value);
    string getL();
    void setT(string value);
    string getT();
    void setR(string value);
    string getR();
    void setB(string value);
    string getB();
protected:
    FZZWPEffectExtent();
private:
    
    
};

#endif //FZZWPEFFECTEXTENT_H
