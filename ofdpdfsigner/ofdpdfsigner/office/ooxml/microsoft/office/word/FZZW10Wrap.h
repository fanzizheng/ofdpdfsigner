//
//  Created by zizheng fan on 2023/04/25.
//
#ifndef FZZW10WRAP_H
#define FZZW10WRAP_H

#include "office/FZZXMLElementObject.h"



#define FZZW10WRAP_Find_Key "schemas-microsoft-com:office:word"
#define FZZW10WRAP_Name "wrap"

class FZZW10Wrap : public FZZXMLElementObject
{
public:
    
    FZZW10Wrap(FZZOfficeObject * parent);
    FZZW10Wrap(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW10Wrap(const FZZW10Wrap& obj);
    virtual ~FZZW10Wrap();
    
public:
    void setAnchorX(string value);
    string getAnchorX();
    void setAnchorY(string value);
    string getAnchorY();

protected:
    FZZW10Wrap();
private:

    
};

#endif //FZZW10WRAP_H
