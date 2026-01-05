//
//  Created by zizheng fan on 2023/11/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblW.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblW**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW::FZZWTblW() : FZZXMLElementObject()
{
    //DLOG("FZZWTblW()");
    FZZConst::addClassCount("FZZWTblW");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW::FZZWTblW(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblW");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW::FZZWTblW(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblW");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW::FZZWTblW(const FZZWTblW& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblW");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW::~FZZWTblW()
{
    //DLOG("~FZZWTblW()");
    FZZConst::delClassCount("FZZWTblW");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblW::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblW::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblW::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblW::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
