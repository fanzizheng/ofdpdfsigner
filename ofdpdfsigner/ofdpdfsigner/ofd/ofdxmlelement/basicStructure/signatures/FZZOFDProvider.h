//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDPROVIDER_H
#define FZZOFDPROVIDER_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDExtendData.h"

#define FZZOFDPROVIDER_Name "ofd:Provider"

class FZZOFDProvider : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDProvider(FZZOFDXMLFileObject * parent);
    FZZOFDProvider(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDProvider(const FZZOFDProvider& obj);
    virtual ~FZZOFDProvider();
    
public:
    void setName(string value);
    string getName();
    void setProviderName(string value);
    string getProviderName();
    
    void setVersion(string value);
    string getVersion();
    void setCompany(string value);
    string getCompany();
    /*
      GM/T 0099-2020
     ofd 2.0 新增 （可选）
     创建签名时所用的签章组件的接口协议版本
     */
    void setProtocolVer(string value);
    string getProtocolVer();
    /*
      GM/T 0099-2020
     ofd 2.0 新增 （可选）
     创建签名时所用的签章组件的扩展信息
     */
    FZZOFDExtendData * setExtendData();
    FZZOFDExtendData * getExtendData();
    
protected:
    FZZOFDProvider();
private:
    FZZOFDExtendData * m_FZZOFDExtendData;
};

#endif //FZZOFDPROVIDER_H
