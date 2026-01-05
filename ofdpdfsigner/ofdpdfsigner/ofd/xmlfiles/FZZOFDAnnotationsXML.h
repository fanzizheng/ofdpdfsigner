//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDANNOTATIONSXML_H
#define FZZOFDANNOTATIONSXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnPage.h"

#define FZZOFDANNOTATIONSXML_FILENAME "Annotations.xml"




class FZZOFDAnnotationsXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDAnnotationsXML();
    FZZOFDAnnotationsXML(XMLDocument * doc);
    FZZOFDAnnotationsXML(const FZZOFDAnnotationsXML& obj);
    virtual ~FZZOFDAnnotationsXML();

public:
    FZZOFDAnnPage* addPage();
    vector<FZZOFDAnnPage*>* getPageList();
public:
  
protected:
    
private:
    vector<FZZOFDAnnPage*> m_FZZOFDAnnPages;
    
};

#endif //FZZOFDANNOTATIONSXML_H
