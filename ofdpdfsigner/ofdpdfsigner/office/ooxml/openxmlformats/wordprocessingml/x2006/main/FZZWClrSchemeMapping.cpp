//
//  Created by zizheng fan on 2023/09/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWClrSchemeMapping.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWClrSchemeMapping**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping::FZZWClrSchemeMapping() : FZZXMLElementObject()
{
    //DLOG("FZZWClrSchemeMapping()");
    FZZConst::addClassCount("FZZWClrSchemeMapping");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping::FZZWClrSchemeMapping(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWClrSchemeMapping");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping::FZZWClrSchemeMapping(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWClrSchemeMapping");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping::FZZWClrSchemeMapping(const FZZWClrSchemeMapping& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWClrSchemeMapping");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWClrSchemeMapping::~FZZWClrSchemeMapping()
{
    //DLOG("~FZZWClrSchemeMapping()");
    FZZConst::delClassCount("FZZWClrSchemeMapping");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setBg1(string value)
{
    setAttribute_String("w:bg1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getBg1()
{
    return getAttribute_String("w:bg1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setBg2(string value)
{
    setAttribute_String("w:bg2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getBg2()
{
    return getAttribute_String("w:bg2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setT1(string value)
{
    setAttribute_String("w:t1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getT1()
{
    return getAttribute_String("w:t1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setT2(string value)
{
    setAttribute_String("w:t2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getT2()
{
    return getAttribute_String("w:t2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setAccent1(string value)
{
    setAttribute_String("w:accent1",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getAccent1()
{
    return getAttribute_String("w:accent1");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setAccent2(string value)
{
    setAttribute_String("w:accent2",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getAccent2()
{
    return getAttribute_String("w:accent2");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setAccent3(string value)
{
    setAttribute_String("w:accent3",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getAccent3()
{
    return getAttribute_String("w:accent3");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setAccent4(string value)
{
    setAttribute_String("w:accent4",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getAccent4()
{
    return getAttribute_String("w:accent4");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setAccent5(string value)
{
    setAttribute_String("w:accent5",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getAccent5()
{
    return getAttribute_String("w:accent5");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setAccent6(string value)
{
    setAttribute_String("w:accent6",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getAccent6()
{
    return getAttribute_String("w:accent6");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setHyperlink(string value)
{
    setAttribute_String("w:hyperlink",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getHyperlink()
{
    return getAttribute_String("w:hyperlink");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWClrSchemeMapping::setFollowedHyperlink(string value)
{
    setAttribute_String("w:followedHyperlink",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWClrSchemeMapping::getFollowedHyperlink()
{
    return getAttribute_String("w:followedHyperlink");
}
//-----------------------------------------------------------------------------------------------------------------
