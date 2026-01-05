
#ifndef FZZVF_H
#define FZZVF_H
//
//  Created by zizheng fan on 2023/04/17.
//
#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZVF_Find_Key "schemas-microsoft-com:vml"
#define FZZVF_Name "f"

class FZZVF : public FZZXMLElementObject
{
public:
    
    FZZVF(FZZOfficeObject * parent);
    FZZVF(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVF(const FZZVF& obj);
    virtual ~FZZVF();
    
public:
    void setEqn(string value);
    string getEqn();
    
protected:
    FZZVF();
private:
    
    
};

#endif //FZZVF_H
