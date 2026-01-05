//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDMULTIMEDIA_H
#define FZZOFDMULTIMEDIA_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDMediaType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"

#define FZZOFDMULTIMEDIA_Name "ofd:MultiMedia"

class FZZOFDMultiMedia : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDMultiMedia(FZZOFDXMLFileObject * parent);
    FZZOFDMultiMedia(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDMultiMedia(const FZZOFDMultiMedia& obj);
    virtual ~FZZOFDMultiMedia();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setType(FZZOFDMediaType::TYPE type);
    FZZOFDMediaType::TYPE getType();
    void setFormat(string value);
    string getFormat();
    
    FZZOFDFileLoc * setMediaFile();
    FZZOFDFileLoc * getMediaFile();
  
    
protected:
    FZZOFDMultiMedia();
private:
    FZZOFDFileLoc * m_FZZOFDFileLoc;
};

#endif //FZZOFDMULTIMEDIA_H
