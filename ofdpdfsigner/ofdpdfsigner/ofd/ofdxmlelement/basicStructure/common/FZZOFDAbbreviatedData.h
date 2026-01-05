//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDABBREVIATEDDATA_H
#define FZZOFDABBREVIATEDDATA_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"

#define FZZOFDABBREVIATEDDATA_Name "ofd:AbbreviatedData"

class FZZOFDAbbreviatedData : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDAbbreviatedData(FZZOFDXMLFileObject * parent);
    FZZOFDAbbreviatedData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAbbreviatedData(const FZZOFDAbbreviatedData& obj);
    virtual ~FZZOFDAbbreviatedData();
    
public:
    void copy(FZZOFDAbbreviatedData * obj);
    void setValue(string value);
    string getValue();
    
    void flush();
    string toString();
    
    void defineStart(double x, double y);

    void S(double x, double y) { return defineStart(x, y);}
    void moveTo(double x, double y);
    void  M(double x, double y) {return moveTo(x, y); }
   
    void lineTo(double x, double y);
    void L(double x, double y) { return lineTo(x, y);}

    void quadraticBezier(double x1, double y1, double x2, double y2);
    void Q(double x1, double y1,double x2, double y2) { return quadraticBezier(x1, y1, x2, y2);}

    void cubicBezier(double x1, double y1,double x2, double y2,double x3, double y3);
    void B(double x1, double y1,double x2, double y2,double x3, double y3) {
        return cubicBezier(x1, y1,x2, y2,x3, y3);
    }

    void arc(double rx, double ry,double angle, int large,int sweep, double x, double y);
    void A(double rx, double ry,double angle, int large,int sweep, double x, double y) {
        return arc(rx, ry,angle, large,sweep, x, y);
    }

    void close() {
        m_dataQueue.push_back("C");
    }
    void C() {
        return close();
    }
    void undo() {
        m_dataQueue.pop_back();
    }
protected:
    FZZOFDAbbreviatedData();
private:
    vector<string> m_dataQueue;
};

#endif //FZZOFDABBREVIATEDDATA_H
