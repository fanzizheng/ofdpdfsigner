//
//  Created by zizheng fan on 2023/08/16
//
#ifndef FZZAFONT_EA_CS_H
#define FZZAFONT_EA_CS_H

#include "office/FZZXMLElementObject.h"


#define FZZAFONT_EA_CS_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

class FZZAfont_ea_cs : public FZZXMLElementObject
{
public:
    
    FZZAfont_ea_cs(FZZOfficeObject * parent);
    FZZAfont_ea_cs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAfont_ea_cs(const FZZAfont_ea_cs& obj);
    virtual ~FZZAfont_ea_cs();
    
public:
    void setScript(string value);
    string getScript();
    void setTypeface(string value);
    string getTypeface();
    void setPanose(string value);
    string getPanose();
protected:
    FZZAfont_ea_cs();
private:
    
    
};

#endif //FZZAFONT_EA_CS_H
