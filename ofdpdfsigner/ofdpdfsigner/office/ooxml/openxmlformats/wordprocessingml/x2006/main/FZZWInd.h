//
//  Created by zizheng fan on 2023/11/01
//
#ifndef FZZWIND_H
#define FZZWIND_H

#include "office/FZZXMLElementObject.h"

#define FZZWIND_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWIND_Name "ind"

//https://learn.microsoft.com/zh-cn/dotnet/api/documentformat.openxml.wordprocessing.indentation?view=openxml-2.8.1
class FZZWInd : public FZZXMLElementObject
{
public:
    
    FZZWInd(FZZOfficeObject * parent);
    FZZWInd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWInd(const FZZWInd& obj);
    virtual ~FZZWInd();
    
public:
    // value/20
    void setFirstLineChars(string value);
    string getFirstLineChars();
    // value/20
    void setFirstLine(string value);
    string getFirstLine();
    void setRight(string value);
    string getRight();
    void setLeft(string value);
    string getLeft();
    void setHanging(string value);
    string getHanging();
    void setHangingChars(string value);
    string getHangingChars();
    
    void setLeftChars(string value);
    string getLeftChars();
    
protected:
    FZZWInd();
private:
    
    
};

#endif //FZZWIND_H
