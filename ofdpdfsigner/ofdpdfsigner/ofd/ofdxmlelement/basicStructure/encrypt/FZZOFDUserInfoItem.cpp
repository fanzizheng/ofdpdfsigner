//
//  Created by zizheng fan on 2024/10/17.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDUserInfoItem.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDUserInfoItem**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem::FZZOFDUserInfoItem() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDUserInfoItem()");
    FZZConst::addClassCount("FZZOFDUserInfoItem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem::FZZOFDUserInfoItem(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDUserInfoItem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem::FZZOFDUserInfoItem(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDUserInfoItem");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem::FZZOFDUserInfoItem(const FZZOFDUserInfoItem& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDUserInfoItem");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfoItem::~FZZOFDUserInfoItem()
{
    //DLOG("~FZZOFDUserInfoItem()");
    FZZConst::delClassCount("FZZOFDUserInfoItem");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDUserInfoItem::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserInfoItem::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
