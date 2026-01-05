//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDVALIDPERIOD_H
#define FZZOFDVALIDPERIOD_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDVALIDPERIOD_Name "ofd:ValidPeriod"

class FZZOFDValidPeriod : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDValidPeriod(FZZOFDXMLFileObject * parent);
    FZZOFDValidPeriod(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDValidPeriod(const FZZOFDValidPeriod& obj);
    virtual ~FZZOFDValidPeriod();
    
public:
    void setStartDate(string startDate);
    string getStartDate();
    void setEndDate(string endDate);
    string getEndDate();
protected:
    FZZOFDValidPeriod();
private:
    
};

#endif //FZZOFDVALIDPERIOD_H
