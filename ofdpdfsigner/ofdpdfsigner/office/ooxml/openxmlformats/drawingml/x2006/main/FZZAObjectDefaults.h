//
//  Created by zizheng fan on 2023/08/29
//
#ifndef FZZAOBJECTDEFAULTS_H
#define FZZAOBJECTDEFAULTS_H

#include "office/FZZXMLElementObject.h"

#define FZZAOBJECTDEFAULTS_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAOBJECTDEFAULTS_Name "objectDefaults"

class FZZAObjectDefaults : public FZZXMLElementObject
{
public:
    
    FZZAObjectDefaults(FZZOfficeObject * parent);
    FZZAObjectDefaults(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAObjectDefaults(const FZZAObjectDefaults& obj);
    virtual ~FZZAObjectDefaults();
    
public:
    
protected:
    FZZAObjectDefaults();
private:
    
    
};

#endif //FZZAOBJECTDEFAULTS_H
