//
//  Created by zizheng fan on 2023/09/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPanose1.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPanose1**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1::FZZWPanose1() : FZZXMLElementObject()
{
    //DLOG("FZZWPanose1()");
    FZZConst::addClassCount("FZZWPanose1");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1::FZZWPanose1(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPanose1");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1::FZZWPanose1(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPanose1");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1::FZZWPanose1(const FZZWPanose1& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPanose1");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPanose1::~FZZWPanose1()
{
    //DLOG("~FZZWPanose1()");
    FZZConst::delClassCount("FZZWPanose1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPanose1::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPanose1::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
