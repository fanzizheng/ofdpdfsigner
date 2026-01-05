//
//  Created by zizheng fan on 2023/04/19.
//
#ifndef FZZVIMAGEDATA_H
#define FZZVIMAGEDATA_H

#include "office/FZZXMLElementObject.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
//#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"


#define FZZVIMAGEDATA_Find_Key "schemas-microsoft-com:vml"
#define FZZVIMAGEDATA_Name "imagedata"

class FZZVImageData : public FZZXMLElementObject
{
public:
    
    FZZVImageData(FZZOfficeObject * parent);
    FZZVImageData(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVImageData(const FZZVImageData& obj);
    virtual ~FZZVImageData();
    
public:
    void setRID(string value);
    string getRID();
    void setTitle(string value);
    string getTitle();
    void setGain(string value);
    string getGain();
    void setBlacklevel(string value);
    string getBlacklevel();
    void setGamma(string value);
    string getGamma();
protected:
    FZZVImageData();
private:
    //FZZWPPr* m_FZZWPPr;
    
};

#endif //FZZVIMAGEDATA_H
