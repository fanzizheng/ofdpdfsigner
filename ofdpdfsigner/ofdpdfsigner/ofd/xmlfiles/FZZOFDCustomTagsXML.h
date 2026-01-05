//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDCUSTOMTAGSXML_H
#define FZZOFDCUSTOMTAGSXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/customTags/FZZOFDCustomTag.h"

#define FZZOFDCUSTOMTAGSXML_FILENAME "CustomTags.xml"




class FZZOFDCustomTagsXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDCustomTagsXML();
    FZZOFDCustomTagsXML(XMLDocument * doc);
    FZZOFDCustomTagsXML(const FZZOFDCustomTagsXML& obj);
    virtual ~FZZOFDCustomTagsXML();

public:
    FZZOFDCustomTag * addCustomTag();
    vector<FZZOFDCustomTag*> * getCustomTagList();
    
public:
  
protected:
    
private:
    vector<FZZOFDCustomTag*> m_FZZOFDCustomTags;
    
};

#endif //FZZOFDCUSTOMTAGSXML_H
