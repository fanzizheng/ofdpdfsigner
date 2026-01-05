//
//  Created by zizheng fan on 2023/09/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDoNotExpandShiftReturn.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDoNotExpandShiftReturn**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn::FZZWDoNotExpandShiftReturn() : FZZXMLElementObject()
{
    //DLOG("FZZWDoNotExpandShiftReturn()");
    FZZConst::addClassCount("FZZWDoNotExpandShiftReturn");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn::FZZWDoNotExpandShiftReturn(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDoNotExpandShiftReturn");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn::FZZWDoNotExpandShiftReturn(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDoNotExpandShiftReturn");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn::FZZWDoNotExpandShiftReturn(const FZZWDoNotExpandShiftReturn& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDoNotExpandShiftReturn");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn::~FZZWDoNotExpandShiftReturn()
{
    //DLOG("~FZZWDoNotExpandShiftReturn()");
    FZZConst::delClassCount("FZZWDoNotExpandShiftReturn");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
