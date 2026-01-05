//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDGLYPHS_H
#define FZZOFDGLYPHS_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDGLYPHS_Name "ofd:Glyphs"

class FZZOFDGlyphs : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDGlyphs(FZZOFDXMLFileObject * parent);
    FZZOFDGlyphs(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDGlyphs(const FZZOFDGlyphs& obj);
    virtual ~FZZOFDGlyphs();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(const vector<string> & array);
    void getValue(/*out*/vector<string> & array);
    
protected:
    FZZOFDGlyphs();
private:
    
};

#endif //FZZOFDGLYPHS_H
