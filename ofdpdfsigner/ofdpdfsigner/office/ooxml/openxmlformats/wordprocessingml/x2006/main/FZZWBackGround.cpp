//
//  Created by zizheng fan on 2023/11/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBackGround.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBackGround**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround::FZZWBackGround() : FZZXMLElementObject()
{
    //DLOG("FZZWBackGround()");
    FZZConst::addClassCount("FZZWBackGround");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround::FZZWBackGround(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBackGround");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround::FZZWBackGround(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBackGround");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround::FZZWBackGround(const FZZWBackGround& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBackGround");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBackGround::~FZZWBackGround()
{
    //DLOG("~FZZWBackGround()");
    FZZConst::delClassCount("FZZWBackGround");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWBackGround::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWBackGround::getColor()
{
    string retstr = getAttribute_String("w:color");
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
