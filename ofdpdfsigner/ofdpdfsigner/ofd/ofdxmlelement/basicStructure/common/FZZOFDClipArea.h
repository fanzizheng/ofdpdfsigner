//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDCLIPAREA_H
#define FZZOFDCLIPAREA_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDText.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPath.h"

#define FZZOFDCLIPAREA_Name "ofd:Area"

class FZZOFDClipArea : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDClipArea(FZZOFDXMLFileObject * parent);
    FZZOFDClipArea(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDClipArea(const FZZOFDClipArea& obj);
    virtual ~FZZOFDClipArea();
    
public:
    void setDrawParam(string value);
    string getDrawParam();
    void setCTM(string value);
    string getCTM();
    
    void setDrawParam(long value);
    long getDrawParam_long();
    void setCTM(const vector<string> & array);
    void getCTM(/*out*/vector<double> & array);
    
    FZZOFDText * setText();
    FZZOFDText * getText();
    FZZOFDPath * setPath();
    FZZOFDPath * getPath();
    
    
protected:
    FZZOFDClipArea();
private:
    void deleteObject();
private:
    //FZZOFDClipAble * m_FZZOFDClipAble;
    FZZOFDText * m_FZZOFDText;
    FZZOFDPath * m_FZZOFDPath;
};

#endif //FZZOFDCLIPAREA_H
