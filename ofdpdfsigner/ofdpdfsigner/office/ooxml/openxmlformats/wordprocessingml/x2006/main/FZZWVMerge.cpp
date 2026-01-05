//
//  Created by zizheng fan on 2023/11/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVMerge.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWVMerge**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge::FZZWVMerge() : FZZXMLElementObject()
{
    //DLOG("FZZWVMerge()");
    FZZConst::addClassCount("FZZWVMerge");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge::FZZWVMerge(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWVMerge");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge::FZZWVMerge(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWVMerge");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge::FZZWVMerge(const FZZWVMerge& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWVMerge");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge::~FZZWVMerge()
{
    //DLOG("~FZZWVMerge()");
    FZZConst::delClassCount("FZZWVMerge");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWVMerge::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWVMerge::getVal()
{
    string retstr = getAttribute_String("w:val");
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
