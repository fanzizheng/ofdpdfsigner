//
//  Created by zizheng fan on 2023/04/15.
//
#ifndef FZZDOCUMENTXML_H
#define FZZDOCUMENTXML_H


#include "office/FZZOfficeObject.h"

#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBody.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBackGround.h"

#define DOCUMENTXML_FILENAME "document.xml"

class FZZDocumentXML : public FZZOfficeObject
{
public:
    FZZDocumentXML();
    FZZDocumentXML(XMLDocument * doc);
    FZZDocumentXML(const FZZDocumentXML& obj);
    virtual ~FZZDocumentXML();
    
 
public:
    
    FZZWBody * setBody();
    FZZWBody * getBody();
    FZZWBackGround * setBackGround();
    FZZWBackGround * getBackGround();
    
    void test();
public:
    string getNextStyleID_ToString();
    string getCurrStyleID_ToString();
protected:
    void defaultInit();
private:
    
    FZZWBody * m_Body;
    FZZWBackGround * m_BackGround;
    
    int m_GlobalID;
};

#endif //FZZDOCUMENTXML_H
