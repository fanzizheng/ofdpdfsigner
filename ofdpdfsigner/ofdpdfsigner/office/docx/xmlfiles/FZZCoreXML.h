//
//  Created by zizheng fan on 2023/04/14.
//
#ifndef FZZCOREXML_H
#define FZZCOREXML_H


#include "office/FZZOfficeObject.h"


#define COREXML_FILENAME "core.xml"

class FZZCoreXML : public FZZOfficeObject
{
public:
    FZZCoreXML();
    FZZCoreXML(XMLDocument * doc);
    FZZCoreXML(const FZZCoreXML& obj);
    virtual ~FZZCoreXML();
    
 
public:
    void setDcTitle(string value);
    string getDcTitle();
    
    void setDcSubject(string value);
    string getDcSubject();
    
    void setDcCreator(string value);
    string getDcCreator();
    
    void setCpKeywords(string value);
    string getCpKeywords();
    
    void setDcDescription(string value);
    string getDcDescription();
    
    void setCpLastModifiedBy(string value);
    string getCpLastModifiedBy();
    
    void setCpRevision(string value);
    string getCpRevision();
    
    void setDctermsCreated(string value);
    string getDctermsCreated();
    
    void setDctermsModified(string value);
    string getDctermsModified();
    
protected:
    
private:
    

    
};

#endif //FZZCOREXML_H
