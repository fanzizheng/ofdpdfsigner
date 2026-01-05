//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDMOVIE_H
#define FZZOFDMOVIE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDMOVIE_Name "ofd:Movie"

class FZZOFDMovie : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDMovie(FZZOFDXMLFileObject * parent);
    FZZOFDMovie(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDMovie(const FZZOFDMovie& obj);
    virtual ~FZZOFDMovie();
    
public:
    void setResourceID(string value);
    string getResourceID();
    void setResourceID(long value);
    long getResourceID_long();
    void setOperator(PlayType type);
    PlayType getOperator();
    
protected:
    FZZOFDMovie();
private:
    
};

#endif //FZZOFDMOVIE_H
