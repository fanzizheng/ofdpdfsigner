//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDATTACHMENT_H
#define FZZOFDATTACHMENT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"

#define FZZOFDATTACHMENT_Name "ofd:Attachment"

class FZZOFDAttachment : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDAttachment(FZZOFDXMLFileObject * parent);
    FZZOFDAttachment(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAttachment(const FZZOFDAttachment& obj);
    virtual ~FZZOFDAttachment();
    
public:
    void setID(string value);
    void setID(long value);
    string getID();
    void setName(string value);
    string getName();
    void setFormat(string value);
    string getFormat();
    void setCreationDate(string value);
    string getCreationDate();
    void setModDate(string value);
    string getModDate();
    void setSize(double value);
    double getSize();
    void setVisible(bool value);
    bool getVisible();
    void setUsage(string value);
    string getUsage();
    FZZOFDFileLoc * setFileLoc();
    FZZOFDFileLoc * getFileLoc();
    
protected:
    FZZOFDAttachment();
private:
    FZZOFDFileLoc * m_FZZOFDFileLoc;
};

#endif //FZZOFDATTACHMENT_H
