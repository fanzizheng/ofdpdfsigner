//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocUsage.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocUsage**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage::FZZOFDDocUsage() : FZZOFDXMLElementObject()
{
    FZZConst::addClassCount("FZZOFDDocUsage");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage::FZZOFDDocUsage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDDocUsage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage::FZZOFDDocUsage(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocUsage");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage::FZZOFDDocUsage(const FZZOFDDocUsage& obj) : FZZOFDXMLElementObject(obj)
{
    FZZConst::addClassCount("FZZOFDDocUsage");
    if ( this == &obj ) {
        return;
    }
   
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage::~FZZOFDDocUsage()
{
    FZZConst::delClassCount("FZZOFDDocUsage");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZOFDDocUsage::setType(FZZOFDDocUsage::TYPE value)
{
    string ret = "Normal";
    switch (value) {
        case FZZOFDDocUsage::TYPE::Normal:
            ret = "Normal";
            break;
        case FZZOFDDocUsage::TYPE::EBook:
            ret = "EBook";
            break;
        case FZZOFDDocUsage::TYPE::ENewsPaper:
            ret = "ENewsPaper";
            break;
        case FZZOFDDocUsage::TYPE::EMagzine:
            ret = "EMagzine";
            break;
        default:
            ret = "Normal";
            break;

    }
    setValue_String(ret);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocUsage::TYPE FZZOFDDocUsage::getType()
{
    string strtype = getValue_String();
    FZZOFDDocUsage::TYPE ret = FZZOFDDocUsage::TYPE::Normal;
    if ( !strtype.empty() ) {
        if (strtype == "Normal") {
            ret = FZZOFDDocUsage::TYPE::Normal;
        }
        else if (strtype == "EBook") {
            ret = FZZOFDDocUsage::TYPE::EBook;
        }
        else if (strtype == "ENewsPaper") {
            ret = FZZOFDDocUsage::TYPE::ENewsPaper;
        }
        else if (strtype == "EMagzine") {
            ret = FZZOFDDocUsage::TYPE::EMagzine;
        }
        
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
