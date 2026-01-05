//
//  Created by zizheng fan on 2023/04/10.
//
#ifndef FZZENDNOTESXML_H
#define FZZENDNOTESXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWEndnote.h"


#define ENDNOTESXML_FILENAME "endnotes.xml"



class FZZEndnotesXML : public FZZOfficeObject
{
public:
    FZZEndnotesXML();
    FZZEndnotesXML(XMLDocument * doc);
    FZZEndnotesXML(const FZZEndnotesXML& obj);
    virtual ~FZZEndnotesXML();
    
 
public:
    vector<FZZWEndnote *> * getEndnoteList() ;
    FZZWEndnote * addEndnote();
    
public:

protected:
    
private:
    vector<FZZWEndnote *> m_FZZWEndnoteList;
};

#endif //FZZENDNOTESXML_H
