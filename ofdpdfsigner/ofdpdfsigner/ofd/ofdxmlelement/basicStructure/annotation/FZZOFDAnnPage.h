//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDANNPAGE_H
#define FZZOFDANNPAGE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"

#define FZZOFDANNPAGE_Name "ofd:Page"


class FZZOFDAnnPage : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDAnnPage(FZZOFDXMLFileObject * parent);
    FZZOFDAnnPage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAnnPage(const FZZOFDAnnPage& obj);
    virtual ~FZZOFDAnnPage();
    
public:
    void setPageID(string value);
    string getPageID();
    void setPageID(long value);
    long getPageID_long();
    FZZOFDFileLoc * setFileLoc();
    FZZOFDFileLoc * getFileLoc();
    
protected:
    FZZOFDAnnPage();
private:
    FZZOFDFileLoc * m_FZZOFDFileLoc;
};

#endif //FZZOFDANNPAGE_H
