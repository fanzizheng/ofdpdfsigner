//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDATTACHMENTSXML_H
#define FZZOFDATTACHMENTSXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/attachment/FZZOFDAttachment.h"

#define FZZOFDATTACHMENTSXML_FILENAME "Attachments.xml"




class FZZOFDAttachmentsXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDAttachmentsXML();
    FZZOFDAttachmentsXML(XMLDocument * doc);
    FZZOFDAttachmentsXML(const FZZOFDAttachmentsXML& obj);
    virtual ~FZZOFDAttachmentsXML();

public:
    FZZOFDAttachment* addAttachment();
    vector<FZZOFDAttachment*>* getAttachmentList();
    
public:
  
protected:
    
private:
    vector<FZZOFDAttachment*> m_FZZOFDAttachments;
    
};

#endif //FZZOFDATTACHMENTSXML_H
