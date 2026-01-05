//
//  Created by zizheng fan on 2023/09/12
//
#ifndef FZZWBORDERSDONOTSURROUNDFOOTER_H
#define FZZWBORDERSDONOTSURROUNDFOOTER_H

#include "office/FZZXMLElementObject.h"

#define FZZWBORDERSDONOTSURROUNDFOOTER_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBORDERSDONOTSURROUNDFOOTER_Name "bordersDoNotSurroundFooter"

class FZZWBordersDoNotSurroundFooter : public FZZXMLElementObject
{
public:
    
    FZZWBordersDoNotSurroundFooter(FZZOfficeObject * parent);
    FZZWBordersDoNotSurroundFooter(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBordersDoNotSurroundFooter(const FZZWBordersDoNotSurroundFooter& obj);
    virtual ~FZZWBordersDoNotSurroundFooter();
  
public:
   
    
protected:
    FZZWBordersDoNotSurroundFooter();
private:
    
    
};

#endif //FZZWBORDERSDONOTSURROUNDFOOTER_H
