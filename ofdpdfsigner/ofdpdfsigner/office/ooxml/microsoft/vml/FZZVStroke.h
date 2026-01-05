//
//  Created by zizheng fan on 2023/04/21.
//
#ifndef FZZVSTROKE_H
#define FZZVSTROKE_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZVSTROKE_Find_Key "schemas-microsoft-com:vml"
#define FZZVSTROKE_Name "stroke"

class FZZVStroke : public FZZXMLElementObject
{
public:
    
    FZZVStroke(FZZOfficeObject * parent);
    FZZVStroke(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVStroke(const FZZVStroke& obj);
    virtual ~FZZVStroke();
    
public:
    void setOpacity(string value);
    string getOpacity();
    void setJoinstyle(string value);
    string getJoinstyle();
    void setRound(string value);
    string getRound();
    void setColor(string value);
    string getColor();
    void setWeight(string value);
    string getWeight();
    void setEndarrow(string value);
    string getEndarrow();
protected:
    FZZVStroke();
private:
    //FZZWPPr* m_FZZWPPr;
    
};

#endif //FZZVSTROKE_H
