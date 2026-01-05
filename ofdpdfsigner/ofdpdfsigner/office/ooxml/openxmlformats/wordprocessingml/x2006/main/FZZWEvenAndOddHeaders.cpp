//
//  Created by zizheng fan on 2024/02/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWEvenAndOddHeaders.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWEvenAndOddHeaders**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders::FZZWEvenAndOddHeaders() : FZZXMLElementObject()
{
    //DLOG("FZZWEvenAndOddHeaders()");
    FZZConst::addClassCount("FZZWEvenAndOddHeaders");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders::FZZWEvenAndOddHeaders(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWEvenAndOddHeaders");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders::FZZWEvenAndOddHeaders(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWEvenAndOddHeaders");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders::FZZWEvenAndOddHeaders(const FZZWEvenAndOddHeaders& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWEvenAndOddHeaders");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEvenAndOddHeaders::~FZZWEvenAndOddHeaders()
{
    //DLOG("~FZZWEvenAndOddHeaders()");
    FZZConst::delClassCount("FZZWEvenAndOddHeaders");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWEvenAndOddHeaders::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWEvenAndOddHeaders::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
