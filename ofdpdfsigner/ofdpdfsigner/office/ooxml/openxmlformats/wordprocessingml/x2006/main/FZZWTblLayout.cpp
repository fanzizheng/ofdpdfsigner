//
//  Created by zizheng fan on 2023/11/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblLayout.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblLayout**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout::FZZWTblLayout() : FZZXMLElementObject()
{
    //DLOG("FZZWTblLayout()");
    FZZConst::addClassCount("FZZWTblLayout");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout::FZZWTblLayout(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblLayout");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout::FZZWTblLayout(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblLayout");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout::FZZWTblLayout(const FZZWTblLayout& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblLayout");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout::~FZZWTblLayout()
{
    //DLOG("~FZZWTblLayout()");
    FZZConst::delClassCount("FZZWTblLayout");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLayout::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLayout::getType()
{
    string retstr = getAttribute_String("w:type");
    
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWW::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWW::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
