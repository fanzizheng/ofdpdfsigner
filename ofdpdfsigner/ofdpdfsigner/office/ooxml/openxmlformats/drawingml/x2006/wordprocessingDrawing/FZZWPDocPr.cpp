//
//  Created by zizheng fan on 2023/06/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPDocPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPDocPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr::FZZWPDocPr() : FZZXMLElementObject()
{
    //DLOG("FZZWPDocPr()");
    FZZConst::addClassCount("FZZWPDocPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr::FZZWPDocPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPDocPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr::FZZWPDocPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPDocPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr::FZZWPDocPr(const FZZWPDocPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPDocPr");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr::~FZZWPDocPr()
{
    //DLOG("~FZZWPDocPr()");
    FZZConst::delClassCount("FZZWPDocPr");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPDocPr::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPDocPr::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPDocPr::setName(string value)
{
    setAttribute_String("name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPDocPr::getName()
{
    return getAttribute_String("name");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
