//
//  Created by zizheng fan on 2024/03/04..
//
#ifndef FZZOFDCELLCONTENT_H
#define FZZOFDCELLCONTENT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.h"
#define FZZOFDCELLCONTENT_Name "ofd:CellContent"


class FZZOFDCellContent : public FZZOFDPageBlock
{

public:
    
    FZZOFDCellContent(FZZOFDXMLFileObject * parent);
    FZZOFDCellContent(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCellContent(const FZZOFDCellContent& obj);
    virtual ~FZZOFDCellContent();
    
public:
    void setThumbnail(string value);
    string getThumbnail();
    void setThumbnail(long value);
    long getThumbnail_long();
    
protected:
    FZZOFDCellContent();
private:
    
};

#endif //FZZOFDCELLCONTENT_H
