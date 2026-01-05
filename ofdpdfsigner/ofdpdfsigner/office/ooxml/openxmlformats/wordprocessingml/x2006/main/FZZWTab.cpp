//
//  Created by zizheng fan on 2023/11/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTab.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTab**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTab::FZZWTab() : FZZXMLElementObject()
{
    //DLOG("FZZWTab()");
    FZZConst::addClassCount("FZZWTab");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab::FZZWTab(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTab");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab::FZZWTab(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTab");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab::FZZWTab(const FZZWTab& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTab");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab::~FZZWTab()
{
    //DLOG("~FZZWTab()");
    FZZConst::delClassCount("FZZWTab");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTab::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTab::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTab::setPos(string value)
{
    setAttribute_String("w:pos",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTab::getPos()
{
    return getAttribute_String("w:pos");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWTab::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWTab::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
