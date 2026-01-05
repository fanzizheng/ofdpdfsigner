//
//  Created by zizheng fan on 2023/11/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWGridCol.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWGridCol**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWGridCol::FZZWGridCol() : FZZXMLElementObject()
{
    //DLOG("FZZWGridCol()");
    FZZConst::addClassCount("FZZWGridCol");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridCol::FZZWGridCol(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWGridCol");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridCol::FZZWGridCol(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWGridCol");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridCol::FZZWGridCol(const FZZWGridCol& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWGridCol");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridCol::~FZZWGridCol()
{
    //DLOG("~FZZWGridCol()");
    FZZConst::delClassCount("FZZWGridCol");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWGridCol::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWGridCol::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWB::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWB::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
