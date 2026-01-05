//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDPAGEBLOCK_H
#define FZZOFDPAGEBLOCK_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.h"

#define FZZOFDPAGEBLOCK_Name "ofd:PageBlock"
#define FZZOFDPAGEBLOCK_CONTENT_Name "ofd:Content"

class FZZOFDPageBlock : public FZZOFDXMLElementObject , public FZZOFDPageBlockType
{

public:
    
    FZZOFDPageBlock(FZZOFDXMLFileObject * parent);
    FZZOFDPageBlock(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPageBlock(const FZZOFDPageBlock& obj);
    virtual ~FZZOFDPageBlock();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setBoundary(string value);
    string getBoundary();
    void setBoundary(double x, double y,double width, double height);
    void getBoundary(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
    FZZOFDPageBlockType* addPageBlock(FZZOFDPageBlockType::TYPE type);
    vector<FZZOFDPageBlockType* >* getPageBlockList();
protected:
    FZZOFDPageBlock();
private:
    vector<FZZOFDPageBlockType* > m_PageBlockTypes;
};

#endif //FZZOFDPAGEBLOCK_H
