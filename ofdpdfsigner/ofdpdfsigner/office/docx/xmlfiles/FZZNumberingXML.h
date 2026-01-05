//
//  Created by zizheng fan on 2023/04/09.
//
#ifndef FZZNUMBERINGXML_H
#define FZZNUMBERINGXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNum.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAbstractNum.h"

#define NUMBERINGXML_FILENAME "numbering.xml"


class FZZNumberingXML : public FZZOfficeObject
{
public:
    FZZNumberingXML();
    FZZNumberingXML(XMLDocument * doc);
    FZZNumberingXML(const FZZNumberingXML& obj);
    virtual ~FZZNumberingXML();
    
 
public:
    vector<FZZWNum *> * getNumList() ;
    FZZWNum * addNum();
    vector<FZZWAbstractNum *> * getAbstractNumList() ;
    FZZWAbstractNum * addAbstractNum();
    
    FZZWAbstractNum * getAbstractNum(string numid);
public:

protected:
    
private:
    vector<FZZWNum *> m_FZZWNumList;
    vector<FZZWAbstractNum *> m_FZZWAbstractNumList;
};

#endif //FZZNUMBERINGXML_H
