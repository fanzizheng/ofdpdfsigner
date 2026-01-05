//
//  Created by zizheng fan on 2023/11/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFldChar.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWFldChar**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar::FZZWFldChar() : FZZXMLElementObject()
{
    //DLOG("FZZWFldChar()");
    FZZConst::addClassCount("FZZWFldChar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar::FZZWFldChar(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWFldChar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar::FZZWFldChar(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWFldChar");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar::FZZWFldChar(const FZZWFldChar& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWFldChar");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar::~FZZWFldChar()
{
    //DLOG("~FZZWFldChar()");
    FZZConst::delClassCount("FZZWFldChar");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFldChar::setFldCharType(string value)
{
    setAttribute_String("w:fldCharType",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFldChar::getFldCharType()
{
    return getAttribute_String("w:fldCharType");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
