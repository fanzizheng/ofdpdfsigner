//
//  Created by zizheng fan on 2023/06/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPAlign.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPPosOffset**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign::FZZWPAlign() : FZZXMLElementObject()
{
    //DLOG("FZZWPAlign()");
    FZZConst::addClassCount("FZZWPAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign::FZZWPAlign(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign::FZZWPAlign(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPAlign");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign::FZZWPAlign(const FZZWPAlign& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPAlign");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign::~FZZWPAlign()
{
    //DLOG("~FZZWPAlign()");
    FZZConst::delClassCount("FZZWPAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAlign::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAlign::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------


