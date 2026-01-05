//
//  Created by zizheng fan on 2023/06/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPWrapNone.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPWrapNone**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone::FZZWPWrapNone() : FZZXMLElementObject()
{
    //DLOG("FZZWPWrapNone()");
    FZZConst::addClassCount("FZZWPWrapNone");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone::FZZWPWrapNone(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPWrapNone");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone::FZZWPWrapNone(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPWrapNone");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone::FZZWPWrapNone(const FZZWPWrapNone& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPWrapNone");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone::~FZZWPWrapNone()
{
    //DLOG("~FZZWPWrapNone()");
    FZZConst::delClassCount("FZZWPWrapNone");
    
}
//-----------------------------------------------------------------------------------------------------------------


