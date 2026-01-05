//
//  Created by zizheng fan on 2024/02/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTitlePg.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTitlePg**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg::FZZWTitlePg() : FZZXMLElementObject()
{
    //DLOG("FZZWTitlePg()");
    FZZConst::addClassCount("FZZWTitlePg");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg::FZZWTitlePg(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTitlePg");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg::FZZWTitlePg(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTitlePg");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg::FZZWTitlePg(const FZZWTitlePg& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTitlePg");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg::~FZZWTitlePg()
{
    //DLOG("~FZZWPosition()");
    FZZConst::delClassCount("FZZWTitlePg");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTitlePg::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTitlePg::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
