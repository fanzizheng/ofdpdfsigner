//
//  Created by zizheng fan on 2023/10/31
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBCs.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBCs**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs::FZZWBCs() : FZZXMLElementObject()
{
    //DLOG("FZZWBCs()");
    FZZConst::addClassCount("FZZWBCs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs::FZZWBCs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBCs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs::FZZWBCs(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBCs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs::FZZWBCs(const FZZWBCs& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBCs");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs::~FZZWBCs()
{
    //DLOG("~FZZWBCs()");
    FZZConst::delClassCount("FZZWBCs");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWBCs::setVal(string value)
//{
//    setAttribute_String("w:val",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWBCs::getVal()
//{
//    return getAttribute_String("w:val");
//}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWBCs::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWBCs::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
