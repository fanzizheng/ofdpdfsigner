//
//  Created by zizheng fan on 2023/04/20.
//
#ifndef FZZVTEXTBOX_H
#define FZZVTEXTBOX_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTxbxContent.h"


#define FZZVTEXTBOX_Find_Key "schemas-microsoft-com:vml"
#define FZZVTEXTBOX_Name "textbox"

class FZZVTextbox : public FZZXMLElementObject
{
public:
    
    FZZVTextbox(FZZOfficeObject * parent);
    FZZVTextbox(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVTextbox(const FZZVTextbox& obj);
    virtual ~FZZVTextbox();
    
public:
    
    void setInset(string value);
    string getInset();
    void setStyle(string value);
    string getStyle();
    
    FZZWTxbxContent * setTxbxContent();
    FZZWTxbxContent * getTxbxContent();

protected:
    FZZVTextbox();
private:
    FZZWTxbxContent* m_FZZWTxbxContent;
    
};

#endif //FZZVTEXTBOX_H
