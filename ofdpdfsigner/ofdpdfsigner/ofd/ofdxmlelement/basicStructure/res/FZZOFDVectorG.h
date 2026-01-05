//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDVECTORG_H
#define FZZOFDVECTORG_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDThumbnail.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDSubstitution.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.h"

#define FZZOFDVECTORG_Name "ofd:VectorG"
#define FZZOFDCOMPOSITEGRAPHICUNIT_Name "ofd:CompositeGraphicUnit"

class FZZOFDVectorG : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDVectorG(FZZOFDXMLFileObject * parent);
    FZZOFDVectorG(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDVectorG(const FZZOFDVectorG& obj);
    virtual ~FZZOFDVectorG();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setWidth(double value);
    double getWidth();
    void setHeight(double value);
    double getHeight();
    
    
    
    FZZOFDThumbnail* setThumbnail();
    FZZOFDThumbnail* getThumbnail();
    FZZOFDSubstitution* setSubstitution();
    FZZOFDSubstitution* getSubstitution();
    FZZOFDPageBlock * setContent();
    FZZOFDPageBlock * getContent();
    
protected:
    FZZOFDVectorG();
private:
    FZZOFDThumbnail * m_FZZOFDThumbnail;
    FZZOFDSubstitution * m_FZZOFDSubstitution;
    FZZOFDPageBlock * m_FZZOFDPageBlock;
};

#endif //FZZOFDVECTORG_H
