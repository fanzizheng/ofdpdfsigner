//
//  Created by zizheng fan on 2023/11/27
//
#ifndef FZZWHYPERLINK_H
#define FZZWHYPERLINK_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWR.h"

#define FZZWHYPERLINK_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWHYPERLINK_Name "hyperlink"



class FZZWHyperlink : public FZZXMLElementObject
{
public:
    
    FZZWHyperlink(FZZOfficeObject * parent);
    FZZWHyperlink(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWHyperlink(const FZZWHyperlink& obj);
    virtual ~FZZWHyperlink();
    
public:
    void setID(string value);
    string getID();
    
    void setTgtFrame(string value);
    string getTgtFrame();
    
    void setHistory(string value);
    string getHistory();
    
    FZZWR * setR();
    FZZWR * getR();
    
protected:
    FZZWHyperlink();
private:
    FZZWR * m_FZZWR;
    
};

#endif //FZZWHYPERLINK_H
