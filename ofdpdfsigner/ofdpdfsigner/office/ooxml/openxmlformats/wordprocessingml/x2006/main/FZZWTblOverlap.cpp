//
//  Created by zizheng fan on 2023/11/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblOverlap.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblOverlap**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap::FZZWTblOverlap() : FZZXMLElementObject()
{
    //DLOG("FZZWTblOverlap()");
    FZZConst::addClassCount("FZZWTblOverlap");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap::FZZWTblOverlap(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblOverlap");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap::FZZWTblOverlap(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblOverlap");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap::FZZWTblOverlap(const FZZWTblOverlap& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblOverlap");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap::~FZZWTblOverlap()
{
    //DLOG("~FZZWTblOverlap()");
    FZZConst::delClassCount("FZZWTblOverlap");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblOverlap::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblOverlap::getVal()
{
    string retstr = getAttribute_String("w:val");
    return retstr;
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
