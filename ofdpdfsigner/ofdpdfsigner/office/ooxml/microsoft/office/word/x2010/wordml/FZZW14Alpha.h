//
//  Created by zizheng fan on 2023/05/07.
//
#ifndef FZZW14ALPHA_H
#define FZZW14ALPHA_H

#include "office/FZZXMLElementObject.h"

#define FZZW14ALPHA_Find_Key "schemas.microsoft.com/office/word/2010/wordml"

#define FZZW14ALPHA_Name "alpha"

class FZZW14Alpha : public FZZXMLElementObject
{
public:
    
    FZZW14Alpha(FZZOfficeObject * parent);
    FZZW14Alpha(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW14Alpha(const FZZW14Alpha& obj);
    virtual ~FZZW14Alpha();
    
public:
    void setVal(string value);
    string getVal();
    
//    static float WordAlphaToAlpha(int wordAlpha);
//    static int AlphaToWordAlpha(float Alpha);
protected:
    FZZW14Alpha();
private:
    
    
};

#endif //FZZW14ALPHA_H
