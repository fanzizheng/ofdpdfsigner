//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDBOOKMARK_H
#define FZZOFDBOOKMARK_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDDest.h"

#define FZZOFDBOOKMARK_Name "ofd:Bookmark"

class FZZOFDBookmark : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDBookmark(FZZOFDXMLFileObject * parent);
    FZZOFDBookmark(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDBookmark(const FZZOFDBookmark& obj);
    virtual ~FZZOFDBookmark();
    
public:
    void setName(string value);
    string getName();
    FZZOFDDest * setDest();
    FZZOFDDest * getDest();
    
protected:
    FZZOFDBookmark();
private:
    FZZOFDDest * m_FZZOFDDest;
};

#endif //FZZOFDBOOKMARK_H
