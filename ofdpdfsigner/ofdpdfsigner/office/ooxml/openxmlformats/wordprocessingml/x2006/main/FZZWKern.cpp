//
//  Created by zizheng fan on 2023/10/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWKern.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWKern**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWKern::FZZWKern() : FZZXMLElementObject()
{
    //DLOG("FZZWKern()");
    FZZConst::addClassCount("FZZWKern");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWKern::FZZWKern(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWKern");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWKern::FZZWKern(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWKern");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWKern::FZZWKern(const FZZWKern& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWKern");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWKern::~FZZWKern()
{
    //DLOG("~FZZWKern()");
    FZZConst::delClassCount("FZZWKern");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWKern::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWKern::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
