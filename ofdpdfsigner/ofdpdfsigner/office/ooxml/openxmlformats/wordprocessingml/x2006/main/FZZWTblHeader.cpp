//
//  Created by zizheng fan on 2023/11/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblHeader.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblHeader**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader::FZZWTblHeader() : FZZXMLElementObject()
{
    //DLOG("FZZWTblHeader()");
    FZZConst::addClassCount("FZZWTblHeader");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader::FZZWTblHeader(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblHeader");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader::FZZWTblHeader(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblHeader");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader::FZZWTblHeader(const FZZWTblHeader& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblHeader");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblHeader::~FZZWTblHeader()
{
    //DLOG("~FZZWTblHeader()");
    FZZConst::delClassCount("FZZWTblHeader");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblHeader::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblHeader::getVal()
{
    string retstr = getAttribute_String("w:val");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWB::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWB::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
