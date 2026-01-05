//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDCOLOR_H
#define FZZOFDCOLOR_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPattern.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDRadialShd.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLaGouraudShd.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDGouraudShd.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDAxialShd.h"

#define FZZOFDCOLOR_Name "ofd:Color"
#define FZZOFDFILLCOLOR_Name "ofd:FillColor"
#define FZZOFDSTROKECOLOR_Name "ofd:StrokeColor"
#define FZZOFDBACKCOLOR_Name "ofd:BackColor"
#define FZZOFDBORDERCOLOR_Name "ofd:BorderColor"
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDColor : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDColor(FZZOFDXMLFileObject * parent);
    FZZOFDColor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDColor(const FZZOFDColor& obj);
    virtual ~FZZOFDColor();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(const vector<string> & array);
    void getValue(/*out*/vector<string> & array);
    void setIndex(string value);
    string getIndex();
    void setColorSpace(string value);
    string getColorSpace();
    void setColorSpace(long value);
    long getColorSpace_long();
    void setAlpha(int value);
    int getAlpha();
    
    FZZOFDPattern * setPattern();
    FZZOFDPattern * getPattern();
    
    FZZOFDRadialShd * setRadialShd();
    FZZOFDRadialShd * getRadialShd();
    FZZOFDLaGouraudShd * setLaGouraudShd();
    FZZOFDLaGouraudShd * getLaGouraudShd();
    FZZOFDGouraudShd * setGouraudShd();
    FZZOFDGouraudShd * getGouraudShd();
    FZZOFDAxialShd * setAxialShd();
    FZZOFDAxialShd * getAxialShd();
    
protected:
    FZZOFDColor();
private:
    void deleteObject();
private:
    FZZOFDPattern * m_FZZOFDPattern;
    FZZOFDRadialShd * m_FZZOFDRadialShd;
    FZZOFDLaGouraudShd * m_FZZOFDLaGouraudShd;
    FZZOFDGouraudShd * m_FZZOFDGouraudShd;
    FZZOFDAxialShd * m_FZZOFDAxialShd;
    
    
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDFillColor : public FZZOFDColor
{
public:
    
    FZZOFDFillColor(FZZOFDXMLFileObject * parent):FZZOFDColor(parent) {}
    FZZOFDFillColor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) :FZZOFDColor(parent,doc,node,key) {}
    FZZOFDFillColor(const FZZOFDFillColor& obj):FZZOFDColor(obj) {}
    virtual ~FZZOFDFillColor() {}
public:
protected:
    FZZOFDFillColor():FZZOFDColor() {}
private:
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDStrokeColor : public FZZOFDColor
{
public:
    
    FZZOFDStrokeColor(FZZOFDXMLFileObject * parent):FZZOFDColor(parent) {}
    FZZOFDStrokeColor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) :FZZOFDColor(parent,doc,node,key) {}
    FZZOFDStrokeColor(const FZZOFDStrokeColor& obj):FZZOFDColor(obj) {}
    virtual ~FZZOFDStrokeColor() {}
public:
protected:
    FZZOFDStrokeColor():FZZOFDColor() {}
private:
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDBackColor : public FZZOFDColor
{
public:
    
    FZZOFDBackColor(FZZOFDXMLFileObject * parent):FZZOFDColor(parent) {}
    FZZOFDBackColor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) :FZZOFDColor(parent,doc,node,key) {}
    FZZOFDBackColor(const FZZOFDBackColor& obj):FZZOFDColor(obj) {}
    virtual ~FZZOFDBackColor() {}
public:
protected:
    FZZOFDBackColor():FZZOFDColor() {}
private:
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDBorderColor : public FZZOFDColor
{
public:
    
    FZZOFDBorderColor(FZZOFDXMLFileObject * parent):FZZOFDColor(parent) {}
    FZZOFDBorderColor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) :FZZOFDColor(parent,doc,node,key) {}
    FZZOFDBorderColor(const FZZOFDBorderColor& obj):FZZOFDColor(obj) {}
    virtual ~FZZOFDBorderColor() {}
public:
protected:
    FZZOFDBorderColor():FZZOFDColor() {}
private:
};
//-----------------------------------------------------------------------------------------------------------------
#endif //FZZOFDCOLOR_H
