//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDCV_H
#define FZZOFDCV_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCV_Name "ofd:CV"

class FZZOFDCV : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCV(FZZOFDXMLFileObject * parent);
    FZZOFDCV(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCV(const FZZOFDCV& obj);
    virtual ~FZZOFDCV();
    
public:
    void setColor(string value);
    string getColor();
    void setColor(const vector<string> & array);
    void getColor(/*out*/vector<string> & array);
    
protected:
    FZZOFDCV();
private:
 
    
};

#endif //FZZOFDCV_H
