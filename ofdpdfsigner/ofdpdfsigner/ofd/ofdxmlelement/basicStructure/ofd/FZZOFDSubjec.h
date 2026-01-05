//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDSUBJEC_H
#define FZZOFDSUBJEC_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDSUBJEC_Name "ofd:Subject"

class FZZOFDSubjec : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDSubjec(FZZOFDXMLFileObject * parent);
    FZZOFDSubjec(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSubjec(const FZZOFDSubjec& obj);
    virtual ~FZZOFDSubjec();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDSubjec();
private:
  
};

#endif //FZZOFDSUBJEC_H
