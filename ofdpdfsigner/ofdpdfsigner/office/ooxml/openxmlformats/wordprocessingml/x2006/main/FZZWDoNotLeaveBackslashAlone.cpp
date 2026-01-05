//
//  Created by zizheng fan on 2023/09/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDoNotLeaveBackslashAlone.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDoNotLeaveBackslashAlone**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone::FZZWDoNotLeaveBackslashAlone() : FZZXMLElementObject()
{
    //DLOG("FZZWDoNotLeaveBackslashAlone()");
    FZZConst::addClassCount("FZZWDoNotLeaveBackslashAlone");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone::FZZWDoNotLeaveBackslashAlone(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDoNotLeaveBackslashAlone");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone::FZZWDoNotLeaveBackslashAlone(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDoNotLeaveBackslashAlone");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone::FZZWDoNotLeaveBackslashAlone(const FZZWDoNotLeaveBackslashAlone& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDoNotLeaveBackslashAlone");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone::~FZZWDoNotLeaveBackslashAlone()
{
    //DLOG("~FZZWCompat()");
    FZZConst::delClassCount("FZZWDoNotLeaveBackslashAlone");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
