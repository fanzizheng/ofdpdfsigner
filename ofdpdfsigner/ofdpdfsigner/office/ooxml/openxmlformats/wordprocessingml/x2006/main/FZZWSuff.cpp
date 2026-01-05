//
//  Created by zizheng fan on 2023/11/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSuff.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSuff**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff::FZZWSuff() : FZZXMLElementObject()
{
    //DLOG("FZZWSuff()");
    FZZConst::addClassCount("FZZWSuff");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff::FZZWSuff(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSuff");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff::FZZWSuff(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSuff");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff::FZZWSuff(const FZZWSuff& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSuff");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff::~FZZWSuff()
{
    //DLOG("~FZZWSuff()");
    FZZConst::delClassCount("FZZWSuff");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSuff::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSuff::getVal()
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
