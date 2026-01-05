//
//  Created by zizheng fan on 2023/06/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPosOffset.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPPosOffset**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset::FZZWPPosOffset() : FZZXMLElementObject()
{
    //DLOG("FZZWPPosOffset()");
    FZZConst::addClassCount("FZZWPPosOffset");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset::FZZWPPosOffset(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPPosOffset");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset::FZZWPPosOffset(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPPosOffset");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset::FZZWPPosOffset(const FZZWPPosOffset& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPPosOffset");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset::~FZZWPPosOffset()
{
    //DLOG("~FZZWPPosOffset()");
    FZZConst::delClassCount("FZZWPPosOffset");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPPosOffset::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPPosOffset::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------


