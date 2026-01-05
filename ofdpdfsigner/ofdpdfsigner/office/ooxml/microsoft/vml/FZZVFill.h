//
//  Created by zizheng fan on 2024/02/07.
//
#ifndef FZZVFILL_H
#define FZZVFILL_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZVFILL_Find_Key "schemas-microsoft-com:vml"
#define FZZVFILL_Name "fill"

class FZZVFill : public FZZXMLElementObject
{
public:
    
    FZZVFill(FZZOfficeObject * parent);
    FZZVFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVFill(const FZZVFill& obj);
    virtual ~FZZVFill();
    
public:
    void setOn(string value);
    string getOn();
    void setColor2(string value);
    string getColor2();
    void setFocus(string value);
    string getFocus();
    
protected:
    FZZVFill();
private:
    //FZZWPPr* m_FZZWPPr;
    
};

#endif //FZZVFILL_H
