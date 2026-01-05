//
//  Created by zizheng fan on 2023/04/24.
//
#ifndef FZZOLOCK_H
#define FZZOLOCK_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZOLOCK_Find_Key "schemas-microsoft-com:office:office"
#define FZZOLOCK_Name "lock"

class FZZOLock : public FZZXMLElementObject
{
public:
    
    FZZOLock(FZZOfficeObject * parent);
    FZZOLock(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOLock(const FZZOLock& obj);
    virtual ~FZZOLock();
    
public:
    void setExt(string value);
    string getExt();
    void setAspectratio(string value);
    string getAspectratio();
    void setPosition(string value);
    string getPosition();
    void setSelection(string value);
    string getSelection();
    void setGrouping(string value);
    string getGrouping();
    void setRotation(string value);
    string getRotation();
    void setCropping(string value);
    string getCropping();
    void setText(string value);
    string getText();
    
protected:
    FZZOLock();
private:
    
    
};

#endif //FZZOLOCK_H
