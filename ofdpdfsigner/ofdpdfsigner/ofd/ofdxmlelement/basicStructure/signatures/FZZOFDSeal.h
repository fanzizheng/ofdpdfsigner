//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDSEAL_H
#define FZZOFDSEAL_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"

#define FZZOFDSEAL_Name "ofd:Seal"

class FZZOFDSeal : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSeal(FZZOFDXMLFileObject * parent);
    FZZOFDSeal(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSeal(const FZZOFDSeal& obj);
    virtual ~FZZOFDSeal();
    
public:
    FZZOFDFileLoc * setBaseLoc();
    FZZOFDFileLoc * getBaseLoc();
    /*
     GM/T 0099-2020
    ofd 2.0 新增 （可选）
     印模图片存储位置
     */
    FZZOFDFileLoc * setImageLoc();
    FZZOFDFileLoc * getImageLoc();
    
protected:
    FZZOFDSeal();
private:
    FZZOFDFileLoc * m_BaseLoc;
    FZZOFDFileLoc * m_ImageLoc;
};

#endif //FZZOFDSEAL_H
