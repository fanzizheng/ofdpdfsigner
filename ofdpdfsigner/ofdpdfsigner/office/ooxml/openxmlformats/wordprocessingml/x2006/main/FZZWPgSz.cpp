//
//  Created by zizheng fan on 2023/10/25
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPgSz.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPgSz**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz::FZZWPgSz() : FZZXMLElementObject()
{
    //DLOG("FZZWPgSz()");
    FZZConst::addClassCount("FZZWPgSz");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz::FZZWPgSz(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPgSz");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz::FZZWPgSz(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPgSz");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz::FZZWPgSz(const FZZWPgSz& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPgSz");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz::~FZZWPgSz()
{
    //DLOG("~FZZWPgSz()");
    FZZConst::delClassCount("FZZWPgSz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgSz::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgSz::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPgSz::setH(string value)
{
    setAttribute_String("w:h",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPgSz::getH()
{
    return getAttribute_String("w:h");
}
//-----------------------------------------------------------------------------------------------------------------
