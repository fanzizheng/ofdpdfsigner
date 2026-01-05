//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDSTAMPANNOT_H
#define FZZOFDSTAMPANNOT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDSTAMPANNOT_Name "ofd:StampAnnot"

class FZZOFDStampAnnot : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDStampAnnot(FZZOFDXMLFileObject * parent);
    FZZOFDStampAnnot(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDStampAnnot(const FZZOFDStampAnnot& obj);
    virtual ~FZZOFDStampAnnot();
    
public:
    void setID(string value);
    string getID();
    void setPageRef(string value);
    string getPageRef();
    void setBoundary(string value);
    string getBoundary();
    void setClip(string value);
    string getClip();
    
    void setPageRef(long value);
    long getPageRef_long();
    void setBoundary(double x, double y,double width, double height);
    void getBoundary(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    void setClip(double x, double y,double width, double height);
    void getClip(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
    
protected:
    FZZOFDStampAnnot();
private:
  
};

#endif //FZZOFDSTAMPANNOT_H
