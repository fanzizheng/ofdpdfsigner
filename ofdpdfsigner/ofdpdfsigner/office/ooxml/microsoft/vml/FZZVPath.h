//
//  Created by zizheng fan on 2023/04/19.
//
#ifndef FZZVPATH_H
#define FZZVPATH_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZVPATH_Find_Key "schemas-microsoft-com:vml"
#define FZZVPATH_Name "path"

class FZZVPath : public FZZXMLElementObject
{
public:
    
    FZZVPath(FZZOfficeObject * parent);
    FZZVPath(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVPath(const FZZVPath& obj);
    virtual ~FZZVPath();
    
public:
    void setArrowok(string value);
    string getArrowok();
    void setExtrusionok(string value);
    string getExtrusionok();
    void setGradientshapeok(string value);
    string getGradientshapeok();
    void setConnecttype(string value);
    string getConnecttype();
//    void setWeight(string value);
//    string getWeight();
//    void setEndarrow(string value);
//    string getEndarrow();
protected:
    FZZVPath();
private:
    //FZZWPPr* m_FZZWPPr;
    
};

#endif //FZZVPATH_H
