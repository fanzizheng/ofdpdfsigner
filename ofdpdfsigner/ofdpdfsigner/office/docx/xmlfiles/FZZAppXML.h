//
//  Created by zizheng fan on 2023/04/13.
//
#ifndef FZZAPPXML_H
#define FZZAPPXML_H


#include "office/FZZOfficeObject.h"


#define APPXML_FILENAME "app.xml"

class FZZAppXML : public FZZOfficeObject
{
public:
    FZZAppXML();
    FZZAppXML(XMLDocument * doc);
    FZZAppXML(const FZZAppXML& obj);
    virtual ~FZZAppXML();
    
    
    
public:
    void setTemplate(string value);
    string getTemplate();
    
    void setApplication(string value);
    string getApplication();
    
protected:
    
private:
    

    
};

#endif //FZZAPPXML_H
