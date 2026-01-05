//
//  Created by zizheng fan on 2023/04/11.
//
#ifndef FZZFOOTNOTESXML_H
#define FZZFOOTNOTESXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFootnote.h"

#define FOOTNOTESXML_FILENAME "footnotes.xml"


class FZZFootnotesXML : public FZZOfficeObject
{
public:
    FZZFootnotesXML();
    FZZFootnotesXML(XMLDocument * doc);
    FZZFootnotesXML(const FZZFootnotesXML& obj);
    virtual ~FZZFootnotesXML();
    
 
public:
    vector<FZZWFootnote *> * getFootnoteList() ;
    FZZWFootnote * addFootnote();
    
public:

protected:
    
private:
    
    vector<FZZWFootnote *> m_FZZWFootnoteList;
};

#endif //FZZFOOTNOTESXML_H
