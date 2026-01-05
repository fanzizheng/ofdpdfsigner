//
//  Created by zizheng fan on 2023/04/26.
//
#ifndef FZZW15CHARTTRACKINGREFBASED_H
#define FZZW15CHARTTRACKINGREFBASED_H

#include "office/FZZXMLElementObject.h"

#define FZZW15CHARTTRACKINGREFBASED_Find_Key "schemas.microsoft.com/office/word/2012/wordml"
#define FZZW15CHARTTRACKINGREFBASED_Name "chartTrackingRefBased"

class FZZW15ChartTrackingRefBased : public FZZXMLElementObject
{
public:
    
    FZZW15ChartTrackingRefBased(FZZOfficeObject * parent);
    FZZW15ChartTrackingRefBased(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW15ChartTrackingRefBased(const FZZW15ChartTrackingRefBased& obj);
    virtual ~FZZW15ChartTrackingRefBased();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZW15ChartTrackingRefBased();
private:
    
    
};

#endif //FZZW15CHARTTRACKINGREFBASED_H
