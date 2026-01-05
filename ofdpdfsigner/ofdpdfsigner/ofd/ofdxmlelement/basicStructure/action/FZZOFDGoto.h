//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDGOTO_H
#define FZZOFDGOTO_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDDest.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmark.h"

#define FZZOFDGOTO_Name "ofd:Goto"

class FZZOFDGoto : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDGoto(FZZOFDXMLFileObject * parent);
    FZZOFDGoto(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDGoto(const FZZOFDGoto& obj);
    virtual ~FZZOFDGoto();
    
public:
    
    FZZOFDDest * setDest();
    FZZOFDDest * getDest();
    FZZOFDBookmark * setBookmark();
    FZZOFDBookmark * getBookmark();
    
protected:
    FZZOFDGoto();
private:
    void deleteObject();
private:
    FZZOFDDest * m_FZZOFDDest;
    FZZOFDBookmark * m_FZZOFDBookmark;
};

#endif //FZZOFDGOTO_H
