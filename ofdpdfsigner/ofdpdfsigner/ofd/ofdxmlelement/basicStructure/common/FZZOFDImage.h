//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDIMAGE_H
#define FZZOFDIMAGE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBaseGraphic.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBorder.h"

#define FZZOFDIMAGE_Name "ofd:Image"

class FZZOFDImage : public FZZOFDBaseGraphic
{

public:
    
    FZZOFDImage(FZZOFDXMLFileObject * parent);
    FZZOFDImage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDImage(const FZZOFDImage& obj);
    virtual ~FZZOFDImage();
    
public:
    void setResourceID(string value);
    string getResourceID();
    void setSubstitution(string value);
    string getSubstitution();
    void setImageMask(string value);
    string getImageMask();
    FZZOFDBorder * setBorder();
    FZZOFDBorder * getBorder();
    
    void setResourceID(long value);
    long getResourceID_long();
    void setSubstitution(long value);
    long getSubstitution_long();
    void setImageMask(long value);
    long getImageMask_long();
protected:
    FZZOFDImage();
private:
    FZZOFDBorder * m_FZZOFDBorder;
};

#endif //FZZOFDIMAGE_H
