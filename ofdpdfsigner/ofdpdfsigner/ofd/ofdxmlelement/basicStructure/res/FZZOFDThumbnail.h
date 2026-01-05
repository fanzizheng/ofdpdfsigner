//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDTHUMBNAIL_H
#define FZZOFDTHUMBNAIL_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDTHUMBNAIL_Name "ofd:Thumbnail"

class FZZOFDThumbnail : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDThumbnail(FZZOFDXMLFileObject * parent);
    FZZOFDThumbnail(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDThumbnail(const FZZOFDThumbnail& obj);
    virtual ~FZZOFDThumbnail();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(long value);
    long getLongValue();
    
protected:
    FZZOFDThumbnail();
private:
 
    
};

#endif //FZZOFDTHUMBNAIL_H
