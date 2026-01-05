//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDDOCINFOKEYWORDS_H
#define FZZOFDDOCINFOKEYWORDS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo_Keyword.h"

#define FZZOFDDOCINFOKEYWORDS_Name "ofd:Keywords"

class FZZOFDDocInfo_Keywords : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocInfo_Keywords(FZZOFDXMLFileObject * parent);
    FZZOFDDocInfo_Keywords(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocInfo_Keywords(const FZZOFDDocInfo_Keywords& obj);
    virtual ~FZZOFDDocInfo_Keywords();
    
public:
    FZZOFDDocInfo_Keyword * addKeyword();
    vector<FZZOFDDocInfo_Keyword*> * getKeywordList();
    
protected:
    FZZOFDDocInfo_Keywords();
private:
 
    vector<FZZOFDDocInfo_Keyword*> m_FZZOFDDocInfo_Keywords;
};

#endif //FZZOFDDOCINFOKEYWORDS_H
