//
//  Created by zizheng fan on 2024/02/02.
//
#ifndef FZZVTEXTPATH_H
#define FZZVTEXTPATH_H

#include "office/FZZXMLElementObject.h"

#define FZZVTEXTPATH_Find_Key "schemas-microsoft-com:vml"
#define FZZVTEXTPATH_Name "textpath"

class FZZVTextpath : public FZZXMLElementObject
{
public:
    
    FZZVTextpath(FZZOfficeObject * parent);
    FZZVTextpath(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVTextpath(const FZZVTextpath& obj);
    virtual ~FZZVTextpath();
    
public:
    
    void setStyle(string value);
    string getStyle();
    void setOn(string value);
    string getOn();
    void setFitshape(string value);
    string getFitshape();
    void setFitpath(string value);
    string getFitpath();
    void setTrim(string value);
    string getTrim();
    void setXscale(string value);
    string getXscale();
    void setString(string value);
    string getString();
    
protected:
    FZZVTextpath();
private:
    
};

#endif //FZZVTEXTPATH_H
