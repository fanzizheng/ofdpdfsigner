//
//  Created by zizheng fan on 2023/11/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcW.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTcW**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW::FZZWTcW() : FZZXMLElementObject()
{
    //DLOG("FZZWTcW()");
    FZZConst::addClassCount("FZZWTcW");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW::FZZWTcW(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTcW");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW::FZZWTcW(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTcW");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW::FZZWTcW(const FZZWTcW& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTcW");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW::~FZZWTcW()
{
    //DLOG("~FZZWTcW()");
    FZZConst::delClassCount("FZZWTcW");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTcW::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTcW::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTcW::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTcW::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
