//
//  Created by zizheng fan on 2023/09/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBalanceSingleByteDoubleByteWidth.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBalanceSingleByteDoubleByteWidth**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth::FZZWBalanceSingleByteDoubleByteWidth() : FZZXMLElementObject()
{
    //DLOG("FZZWBalanceSingleByteDoubleByteWidth()");
    FZZConst::addClassCount("FZZWBalanceSingleByteDoubleByteWidth");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth::FZZWBalanceSingleByteDoubleByteWidth(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBalanceSingleByteDoubleByteWidth");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth::FZZWBalanceSingleByteDoubleByteWidth(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBalanceSingleByteDoubleByteWidth");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth::FZZWBalanceSingleByteDoubleByteWidth(const FZZWBalanceSingleByteDoubleByteWidth& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBalanceSingleByteDoubleByteWidth");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth::~FZZWBalanceSingleByteDoubleByteWidth()
{
    //DLOG("~FZZWBalanceSingleByteDoubleByteWidth()");
    FZZConst::delClassCount("FZZWBalanceSingleByteDoubleByteWidth");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
