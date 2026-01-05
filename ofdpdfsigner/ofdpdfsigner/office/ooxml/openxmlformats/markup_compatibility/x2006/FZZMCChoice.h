//
//  Created by zizheng fan on 2023/05/11.
//
#ifndef FZZMCCHOICE_H
#define FZZMCCHOICE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawing.h"


#define FZZMCCHOICE_Find_Key "schemas.openxmlformats.org/markup-compatibility/2006"
#define FZZMCCHOICE_Name "Choice"



class FZZMCChoice : public FZZXMLElementObject
{
public:
    
    FZZMCChoice(FZZOfficeObject * parent);
    FZZMCChoice(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMCChoice(const FZZMCChoice& obj);
    virtual ~FZZMCChoice();
    
public:
    void setRequires(string value);
    string getRequires();
    
    FZZWDrawing * setDrawing();
    FZZWDrawing * getDrawing();
public:

    
protected:
    FZZMCChoice();
private:
    FZZWDrawing * m_FZZWDrawing;
    

};

#endif //FZZMCCHOICE_H
