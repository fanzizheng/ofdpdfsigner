//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDCGTRANSFORM_H
#define FZZOFDCGTRANSFORM_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDGlyphs.h"

#define FZZOFDCGTRANSFORM_Name "ofd:CGTransform"

class FZZOFDCGTransform : public FZZOFDXMLElementObject 
{

public:
    
    FZZOFDCGTransform(FZZOFDXMLFileObject * parent);
    FZZOFDCGTransform(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCGTransform(const FZZOFDCGTransform& obj);
    virtual ~FZZOFDCGTransform();
    
public:
    void setCodePosition(int value);
    int getCodePosition();
    void setCodeCount(int value);
    int getCodeCount();
    void setGlyphCount(int value);
    int getGlyphCount();
    FZZOFDGlyphs * setGlyphs();
    FZZOFDGlyphs * getGlyphs();
    
protected:
    FZZOFDCGTransform();
private:
    FZZOFDGlyphs * m_FZZOFDGlyphs;
};

#endif //FZZOFDCGTRANSFORM_H
