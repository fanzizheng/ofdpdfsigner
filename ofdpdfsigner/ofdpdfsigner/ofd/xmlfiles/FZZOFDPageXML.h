//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDPAGEXML_H
#define FZZOFDPAGEXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageArea.h"
#include "ofd/ofdxmlelement/basicStructure/page/FZZOFDContent.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"
#include "ofd/ofdxmlelement/basicStructure/page/FZZOFDTemplate.h"
#include "ofd/ofdxmlelement/basicStructure/page/FZZOFDPageRes.h"

#define FZZOFDPAGEXML_FILENAME "Content.xml"




class FZZOFDPageXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDPageXML();
    FZZOFDPageXML(XMLDocument * doc);
    FZZOFDPageXML(const FZZOFDPageXML& obj);
    virtual ~FZZOFDPageXML();

public:
    FZZOFDPageArea * setPageArea();
    FZZOFDPageArea * getPageArea();
    FZZOFDContent * setContent();
    FZZOFDContent * getContent();
    FZZOFDActions * setActions();
    FZZOFDActions * getActions();
    
    FZZOFDTemplate* addTemplate();
    vector<FZZOFDTemplate*>* getTemplateList();
    FZZOFDPageRes* addPageRes();
    vector<FZZOFDPageRes*>* getPageResList();
    
    void setPageIndex(int index) { m_index = index;}
    int getPageIndex() { return m_index; }
public:
  
protected:
    
private:
    FZZOFDPageArea * m_FZZOFDPageArea;
    FZZOFDContent * m_FZZOFDContent;
    FZZOFDActions * m_FZZOFDActions;
    vector<FZZOFDTemplate*> m_FZZOFDTemplates;
    vector<FZZOFDPageRes*> m_FZZOFDPageRess;
    int m_index;
};

#endif //FZZOFDPAGEXML_H
