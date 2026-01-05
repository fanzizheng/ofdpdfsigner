//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDPAGES_H
#define FZZOFDPAGES_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageElem.h"

#define FZZOFDPAGES_Name "ofd:Pages"

class FZZOFDPages : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPages(FZZOFDXMLFileObject * parent);
    FZZOFDPages(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPages(const FZZOFDPages& obj);
    virtual ~FZZOFDPages();
    
public:
    FZZOFDPageElem * addPage();
    vector<FZZOFDPageElem*> * getPageList();
    
    
protected:
    FZZOFDPages();
private:
    vector<FZZOFDPageElem*> m_FZZOFDPageElems;
};

#endif //FZZOFDPAGES_H
