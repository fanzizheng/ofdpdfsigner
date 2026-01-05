//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDTEXTCODE_H
#define FZZOFDTEXTCODE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDTEXTCODE_Name "ofd:TextCode"

class FZZOFDTextCode : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDTextCode(FZZOFDXMLFileObject * parent);
    FZZOFDTextCode(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTextCode(const FZZOFDTextCode& obj);
    virtual ~FZZOFDTextCode();
    
public:
    void setContent(string content);
    string getContent();
    void setCoordinate(double x, double y);
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
    //原 使用deltaFormatter 格式化后再给ST_Array
    void setDeltaX(string value);
    string getDeltaX();
    void setDeltaY(string value);
    string getDeltaY();
    
    void setDeltaX(const vector<string> & array);
    void getDeltaX(/*out*/vector<string> & array);
    void setDeltaY(const vector<string> & array);
    void getDeltaY(/*out*/vector<string> & array);
protected:
    FZZOFDTextCode();
private:
    void deltaFormatter(string delta,/*out*/vector<string> & array);
};

#endif //FZZOFDTEXTCODE_H
