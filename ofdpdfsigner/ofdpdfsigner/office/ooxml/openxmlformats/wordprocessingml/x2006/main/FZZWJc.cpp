//
//  Created by zizheng fan on 2023/10/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWJc.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWJc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWJc::FZZWJc() : FZZXMLElementObject()
{
    //DLOG("FZZWJc()");
    FZZConst::addClassCount("FZZWJc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc::FZZWJc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWJc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc::FZZWJc(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWJc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc::FZZWJc(const FZZWJc& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWJc");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc::~FZZWJc()
{
    //DLOG("~FZZWJc()");
    FZZConst::delClassCount("FZZWJc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWJc::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWJc::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
