//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNATURE_H
#define FZZOFDSIGNATURE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSigType.h"

#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"


#define FZZOFDSIGNATURE_Name "ofd:Signature"

class FZZOFDSignature : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSignature(FZZOFDXMLFileObject * parent);
    FZZOFDSignature(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignature(const FZZOFDSignature& obj);
    virtual ~FZZOFDSignature();
    
public:
    void setID(string value);
    string getID();
    
    void setType(FZZOFDSigType::TYPE value);
    FZZOFDSigType::TYPE getType();
    
    void setBaseLoc(string value);
    string getBaseLoc();
    /*
     GM/T 0099-2020
    ofd 2.0 新增 （可选）
    此签名基于的签名标识,一旦签名标注了该属性,则验证时应同时验证“基”签名
     
     功能我们没有实现，等遇到时在实现
     */
    void setRelative(string value);
    string getRelative();
    
    
protected:
    FZZOFDSignature();
private:
 
};

#endif //FZZOFDSIGNATURE_H
