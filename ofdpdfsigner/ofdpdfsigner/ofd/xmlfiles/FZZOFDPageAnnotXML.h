//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDPAGEANNOTXML_H
#define FZZOFDPAGEANNOTXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnot_Annotation.h"

#define FZZOFDPAGEANNOTXML_FILENAME "Annotation.xml"




class FZZOFDPageAnnotXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDPageAnnotXML();
    FZZOFDPageAnnotXML(XMLDocument * doc);
    FZZOFDPageAnnotXML(const FZZOFDPageAnnotXML& obj);
    virtual ~FZZOFDPageAnnotXML();

public:
    FZZOFDAnnot_Annotation* addAnnot();
    vector<FZZOFDAnnot_Annotation*>* getAnnotList();
    
public:
  
protected:
    
private:
    vector<FZZOFDAnnot_Annotation*> m_FZZOFDAnnots;
    
};

#endif //FZZOFDPAGEANNOTXML_H
